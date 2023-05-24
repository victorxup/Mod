// CvDeal.cpp

#include "CvGameCoreDLL.h"
#include "CvGlobals.h"
#include "CvGameAI.h"
#include "CvTeamAI.h"
#include "CvPlayerAI.h"
#include "CvMap.h"
#include "CvPlot.h"
#include "CvGameCoreUtils.h"
#include "CvGameTextMgr.h"
#include "CvDLLInterfaceIFaceBase.h"
#include "CvDLLEventReporterIFaceBase.h"

#include "CvSavegame.h"

// Public Functions...

CvDeal::CvDeal()
{
	reset();
}


CvDeal::~CvDeal()
{
	uninit();
}


void CvDeal::init(int iID, PlayerTypes eFirstPlayer, PlayerTypes eSecondPlayer)
{
	//--------------------------------
	// Init saved data
	reset(iID, eFirstPlayer, eSecondPlayer);

	//--------------------------------
	// Init non-saved data

	//--------------------------------
	// Init other game data
	setInitialGameTurn(GC.getGameINLINE().getGameTurn());
}


void CvDeal::uninit()
{
	m_firstTrades.clear();
	m_secondTrades.clear();
}


// FUNCTION: reset()
// Initializes data members that are serialized.
void CvDeal::reset(int iID, PlayerTypes eFirstPlayer, PlayerTypes eSecondPlayer)
{
	//--------------------------------
	// Uninit class
	uninit();
	resetSavedData(iID, eFirstPlayer, eSecondPlayer);
}


void CvDeal::kill(bool bKillTeam, TeamTypes eKillingTeam)
{
	if ((getLengthFirstTrades() > 0) || (getLengthSecondTrades() > 0))
	{
		CvWString szString;
		CvWStringBuffer szDealString;
		CvWString szCancelString = gDLL->getText("TXT_KEY_POPUP_DEAL_CANCEL");

		if (CvTeamAI::getTeam(CvPlayerAI::getPlayer(getFirstPlayer()).getTeam()).isHasMet(CvPlayerAI::getPlayer(getSecondPlayer()).getTeam()))
		{
			szDealString.clear();
			GAMETEXT.getDealString(szDealString, *this, getFirstPlayer());
			szString.Format(L"%s: %s", szCancelString.GetCString(), szDealString.getCString());
			gDLL->UI().addPlayerMessage((PlayerTypes)getFirstPlayer(), true, GC.getEVENT_MESSAGE_TIME(), szString, "AS2D_DEAL_CANCELLED");
		}

		if (CvTeamAI::getTeam(CvPlayerAI::getPlayer(getSecondPlayer()).getTeam()).isHasMet(CvPlayerAI::getPlayer(getFirstPlayer()).getTeam()))
		{
			szDealString.clear();
			GAMETEXT.getDealString(szDealString, *this, getSecondPlayer());
			szString.Format(L"%s: %s", szCancelString.GetCString(), szDealString.getCString());
			gDLL->UI().addPlayerMessage((PlayerTypes)getSecondPlayer(), true, GC.getEVENT_MESSAGE_TIME(), szString, "AS2D_DEAL_CANCELLED");
		}
	}

	CLLNode<TradeData>* pNode;

	for (pNode = headFirstTradesNode(); (pNode != nullptr); pNode = nextFirstTradesNode(pNode))
	{
		endTrade(pNode->m_data, getFirstPlayer(), getSecondPlayer(), bKillTeam, eKillingTeam);
	}

	for (pNode = headSecondTradesNode(); (pNode != nullptr); pNode = nextSecondTradesNode(pNode))
	{
		endTrade(pNode->m_data, getSecondPlayer(), getFirstPlayer(), bKillTeam, eKillingTeam);
	}

	GC.getGameINLINE().deleteDeal(getID());
}


void CvDeal::addTrades(CLinkList<TradeData>* pFirstList, CLinkList<TradeData>* pSecondList, bool bCheckAllowed)
{
	CLLNode<TradeData>* pNode;
	bool bAlliance;
	bool bSave;
	int iValue;

	if (pFirstList != nullptr)
	{
		for (pNode = pFirstList->head(); pNode; pNode = pFirstList->next(pNode))
		{
			if (bCheckAllowed)
			{
				if (!(CvPlayerAI::getPlayer(getFirstPlayer()).canTradeItem(getSecondPlayer(), pNode->m_data)))
				{
					return;
				}
			}
		}
	}

	if (pSecondList != nullptr)
	{
		for (pNode = pSecondList->head(); pNode; pNode = pSecondList->next(pNode))
		{
			if (bCheckAllowed && !(CvPlayerAI::getPlayer(getSecondPlayer()).canTradeItem(getFirstPlayer(), pNode->m_data)))
			{
				return;
			}
		}
	}

	if (atWar(CvPlayerAI::getPlayer(getFirstPlayer()).getTeam(), CvPlayerAI::getPlayer(getSecondPlayer()).getTeam()))
	{
		CvTeamAI::getTeam(CvPlayerAI::getPlayer(getFirstPlayer()).getTeam()).makePeace(CvPlayerAI::getPlayer(getSecondPlayer()).getTeam(), true);
	}
	else
	{
		if (!isPeaceDealBetweenOthers(pFirstList, pSecondList))
		{
			if (pSecondList != nullptr && pSecondList->getLength() > 0)
			{
				iValue = CvPlayerAI::getPlayer(getFirstPlayer()).AI_dealVal(getSecondPlayer(), pSecondList, true);

				if (pFirstList != nullptr && pFirstList->getLength() > 0)
				{
					CvPlayerAI::getPlayer(getFirstPlayer()).AI_changePeacetimeTradeValue(getSecondPlayer(), iValue);
				}
				else
				{
					CvPlayerAI::getPlayer(getFirstPlayer()).AI_changePeacetimeGrantValue(getSecondPlayer(), iValue);
				}
			}
			if (pFirstList != nullptr && pFirstList->getLength() > 0)
			{
				iValue = CvPlayerAI::getPlayer(getSecondPlayer()).AI_dealVal(getFirstPlayer(), pFirstList, true);

				if (pSecondList != nullptr && pSecondList->getLength() > 0)
				{
					CvPlayerAI::getPlayer(getSecondPlayer()).AI_changePeacetimeTradeValue(getFirstPlayer(), iValue);
				}
				else
				{
					CvPlayerAI::getPlayer(getSecondPlayer()).AI_changePeacetimeGrantValue(getFirstPlayer(), iValue);
				}
			}
		}
	}

	if (pFirstList != nullptr)
	{
		for (pNode = pFirstList->head(); pNode; pNode = pFirstList->next(pNode))
		{
			bSave = startTrade(pNode->m_data, getFirstPlayer(), getSecondPlayer());

			if (bSave)
			{
				insertAtEndFirstTrades(pNode->m_data);
			}
		}
	}

	if (pSecondList != nullptr)
	{
		for (pNode = pSecondList->head(); pNode; pNode = pSecondList->next(pNode))
		{
			bSave = startTrade(pNode->m_data, getSecondPlayer(), getFirstPlayer());

			if (bSave)
			{
				insertAtEndSecondTrades(pNode->m_data);
			}
		}
	}

	bAlliance = false;

	if (pFirstList != nullptr)
	{
		for (pNode = pFirstList->head(); pNode; pNode = pFirstList->next(pNode))
		{
			if (pNode->m_data.m_eItemType == TRADE_PERMANENT_ALLIANCE)
			{
				bAlliance = true;
			}
		}
	}

	if (pSecondList != nullptr)
	{
		for (pNode = pSecondList->head(); pNode; pNode = pSecondList->next(pNode))
		{
			if (pNode->m_data.m_eItemType == TRADE_PERMANENT_ALLIANCE)
			{
				bAlliance = true;
			}
		}
	}

	if (bAlliance)
	{
		if (CvPlayerAI::getPlayer(getFirstPlayer()).getTeam() < CvPlayerAI::getPlayer(getSecondPlayer()).getTeam())
		{
			CvTeamAI::getTeam(CvPlayerAI::getPlayer(getFirstPlayer()).getTeam()).addTeam(CvPlayerAI::getPlayer(getSecondPlayer()).getTeam());
		}
		else if (CvPlayerAI::getPlayer(getSecondPlayer()).getTeam() < CvPlayerAI::getPlayer(getFirstPlayer()).getTeam())
		{
			CvTeamAI::getTeam(CvPlayerAI::getPlayer(getSecondPlayer()).getTeam()).addTeam(CvPlayerAI::getPlayer(getFirstPlayer()).getTeam());
		}
	}
}


void CvDeal::doTurn()
{
	int iValue;

	if (!isPeaceDeal())
	{
		if (getLengthSecondTrades() > 0)
		{
			iValue = (CvPlayerAI::getPlayer(getFirstPlayer()).AI_dealVal(getSecondPlayer(), getSecondTrades()) / GC.getDefineINT("PEACE_TREATY_LENGTH"));

			if (getLengthFirstTrades() > 0)
			{
				CvPlayerAI::getPlayer(getFirstPlayer()).AI_changePeacetimeTradeValue(getSecondPlayer(), iValue);
			}
			else
			{
				CvPlayerAI::getPlayer(getFirstPlayer()).AI_changePeacetimeGrantValue(getSecondPlayer(), iValue);
			}
		}

		if (getLengthFirstTrades() > 0)
		{
			iValue = (CvPlayerAI::getPlayer(getSecondPlayer()).AI_dealVal(getFirstPlayer(), getFirstTrades()) / GC.getDefineINT("PEACE_TREATY_LENGTH"));

			if (getLengthSecondTrades() > 0)
			{
				CvPlayerAI::getPlayer(getSecondPlayer()).AI_changePeacetimeTradeValue(getFirstPlayer(), iValue);
			}
			else
			{
				CvPlayerAI::getPlayer(getSecondPlayer()).AI_changePeacetimeGrantValue(getFirstPlayer(), iValue);
			}
		}
	}
}


// XXX probably should have some sort of message for the user or something...
void CvDeal::verify()
{
	if (isCancelable(NO_PLAYER) && isPeaceDeal())
	{
		kill(true, NO_TEAM);
	}
}


bool CvDeal::isPeaceDeal() const
{
	CLLNode<TradeData>* pNode;

	for (pNode = headFirstTradesNode(); (pNode != nullptr); pNode = nextFirstTradesNode(pNode))
	{
		if (pNode->m_data.m_eItemType == getPeaceItem())
		{
			return true;
		}
	}

	for (pNode = headSecondTradesNode(); (pNode != nullptr); pNode = nextSecondTradesNode(pNode))
	{
		if (pNode->m_data.m_eItemType == getPeaceItem())
		{
			return true;
		}
	}

	return false;
}

bool CvDeal::isPeaceDealBetweenOthers(CLinkList<TradeData>* pFirstList, CLinkList<TradeData>* pSecondList) const
{
	CLLNode<TradeData>* pNode;

	if (pFirstList != nullptr)
	{
		for (pNode = pFirstList->head(); pNode; pNode = pFirstList->next(pNode))
		{
			if (pNode->m_data.m_eItemType == TRADE_PEACE)
			{
				return true;
			}
		}
	}

	if (pSecondList != nullptr)
	{
		for (pNode = pSecondList->head(); pNode; pNode = pSecondList->next(pNode))
		{
			if (pNode->m_data.m_eItemType == TRADE_PEACE)
			{
				return true;
			}
		}
	}

	return false;
}


int CvDeal::getID() const
{
	return m_iID;
}


void CvDeal::setID(int iID)
{
	m_iID = iID;
}


int CvDeal::getInitialGameTurn() const
{
	return m_iInitialGameTurn;
}


void CvDeal::setInitialGameTurn(int iNewValue)
{
	m_iInitialGameTurn = iNewValue;
}


PlayerTypes CvDeal::getFirstPlayer() const
{
	return m_eFirstPlayer;
}


PlayerTypes CvDeal::getSecondPlayer() const
{
	return m_eSecondPlayer;
}

void CvDeal::clearFirstTrades()
{
	m_firstTrades.clear();
}


void CvDeal::insertAtEndFirstTrades(TradeData trade)
{
	m_firstTrades.insertAtEnd(trade);
}


CLLNode<TradeData>* CvDeal::nextFirstTradesNode(CLLNode<TradeData>* pNode) const
{
	return m_firstTrades.next(pNode);
}


int CvDeal::getLengthFirstTrades() const
{
	return m_firstTrades.getLength();
}


CLLNode<TradeData>* CvDeal::headFirstTradesNode() const
{
	return m_firstTrades.head();
}


const CLinkList<TradeData>* CvDeal::getFirstTrades() const
{
	return &(m_firstTrades);
}


void CvDeal::clearSecondTrades()
{
	m_secondTrades.clear();
}


void CvDeal::insertAtEndSecondTrades(TradeData trade)
{
	m_secondTrades.insertAtEnd(trade);
}


CLLNode<TradeData>* CvDeal::nextSecondTradesNode(CLLNode<TradeData>* pNode) const
{
	return m_secondTrades.next(pNode);
}


int CvDeal::getLengthSecondTrades() const
{
	return m_secondTrades.getLength();
}


CLLNode<TradeData>* CvDeal::headSecondTradesNode() const
{
	return m_secondTrades.head();
}


const CLinkList<TradeData>* CvDeal::getSecondTrades() const
{
	return &(m_secondTrades);
}


void CvDeal::write(FDataStreamBase* pStream) const
{
	CvSavegameWriterBase writerbase(pStream);
	CvSavegameWriter writer(writerbase);
	write(writer);
	writerbase.WriteFile();
}

void CvDeal::read(FDataStreamBase* pStream)
{
	CvSavegameReaderBase readerbase(pStream);
	CvSavegameReader reader(readerbase);

	read(reader);
}

// Protected Functions...

// Returns true if the trade should be saved...
bool CvDeal::startTrade(TradeData trade, PlayerTypes eFromPlayer, PlayerTypes eToPlayer)
{
	CvCity* pCity;
	CvPlot* pLoopPlot;
	bool bSave;
	int iI;

	bSave = false;

	switch (trade.m_eItemType)
	{
	case TRADE_CITIES:
		pCity = CvPlayerAI::getPlayer(eFromPlayer).getCity(trade.m_iData1);
		if (pCity != nullptr)
		{
			if (pCity->getLiberationPlayer(false) == eToPlayer)
			{
				pCity->doTask(TASK_LIBERATE, 0);
			}
			else
			{
				pCity->doTask(TASK_GIFT, eToPlayer);
			}
		}
		break;

	case TRADE_GOLD:
		{
			int iGold = trade.m_iData1;
			OOS_LOG("deal move gold", iGold);
			CvPlayerAI::getPlayer(eFromPlayer).changeGold(-iGold);
			CvPlayerAI::getPlayer(eToPlayer).changeGold(iGold * CvPlayerAI::getPlayer(eToPlayer).getExtraTradeMultiplier(eFromPlayer) / 100);
			CvPlayerAI::getPlayer(eFromPlayer).AI_changeGoldTradedTo(eToPlayer, iGold);

			for (int i = 0; i < GC.getNumFatherPointInfos(); ++i)
			{
				FatherPointTypes ePointType = (FatherPointTypes) i;

				if (CvPlayerAI::getPlayer(eFromPlayer).isNative())
				{
					CvPlayerAI::getPlayer(eToPlayer).changeFatherPoints(ePointType, iGold * GC.getFatherPointInfo(ePointType).getNativeTradeGoldPointPercent() / 100);
				}
				else if (CvPlayerAI::getPlayer(eToPlayer).getParent() == eFromPlayer)
				{
					CvPlayerAI::getPlayer(eToPlayer).changeFatherPoints(ePointType, iGold * GC.getFatherPointInfo(ePointType).getEuropeTradeGoldPointPercent() / 100);
				}
			}

			// Python Event
			gDLL->getEventReporterIFace()->playerGoldTrade(eFromPlayer, eToPlayer, trade.m_iData1);

		}
		break;

	case TRADE_YIELD:
		{
			YieldTypes eYield = (YieldTypes) trade.m_iData1;
			CvUnit* pTransport = ::getUnit(trade.m_kTransport);
			FAssert(pTransport != nullptr);
			if (pTransport != nullptr)
			{
				int iAmount = 0;

				CvPlot* pPlot = pTransport->plot();
				FAssert(pPlot != nullptr);
				CvCity *pCity = pPlot->getPlotCity();
				FAssert(pCity != nullptr);
				if (pCity != nullptr)
				{
					//load yields from city onto transport
					if(pCity->getOwnerINLINE() == eFromPlayer)
					{
						iAmount = pTransport->getMaxLoadYieldAmount(eYield);
						pTransport->loadYield(eYield, true);
					}
					else //unload yields from transport into city
					{
						std::vector<CvUnit*> aUnits;
						for (int i = 0; i < pPlot->getNumUnits(); ++i)
						{
							CvUnit* pLoopUnit = pPlot->getUnitByIndex(i);
							if (pLoopUnit != nullptr)
							{
								if (pLoopUnit->getTransportUnit() == pTransport && pLoopUnit->getYield() == eYield)
								{
									aUnits.push_back(pLoopUnit);
									iAmount += pLoopUnit->getYieldStored();
								}
							}
						}

						FAssert(aUnits.size() > 0);
						for (uint i = 0; i < aUnits.size(); ++i)
						{
							aUnits[i]->setTransportUnit(nullptr);  // unloads goods into city and kills the unit
						}
					}

					if (iAmount > 0)
					{
						CvPlayerAI::getPlayer(eFromPlayer).changeYieldTradedTotal(eYield, iAmount);
						CvPlayerAI::getPlayer(eToPlayer).changeYieldTradedTotal(eYield, iAmount);
						GC.getGameINLINE().changeYieldBoughtTotal(CvPlayerAI::getPlayer(eToPlayer).getID(), eYield, -iAmount);

						int iNativeHappy = GC.getYieldInfo(eYield).getNativeHappy();
						if (iNativeHappy != 0)
						{
							//Native Happy acts like gifting the AI gold, in terms of their interactions.
							CvPlayerAI& kFrom = CvPlayerAI::getPlayer(eFromPlayer);
							CvPlayerAI& kTo = CvPlayerAI::getPlayer(eToPlayer);
							if (kFrom.isNative())
							{
								if (iNativeHappy > 0)
								{
									kTo.AI_changeGoldTradedTo(eFromPlayer, iAmount * iNativeHappy);
								}
								else
								{
									kFrom.AI_changeGoldTradedTo(eToPlayer, -iAmount * iNativeHappy);
								}
							}

							if (CvPlayerAI::getPlayer(eToPlayer).isNative())
							{
								if (iNativeHappy > 0)
								{
									kFrom.AI_changeGoldTradedTo(eToPlayer, iAmount * iNativeHappy);
								}
								else
								{
									kTo.AI_changeGoldTradedTo(eFromPlayer, -iAmount * iNativeHappy);
								}
							}
						}
					}
				}
			}
		}

		break;

	case TRADE_MAPS:
		for (iI = 0; iI < GC.getMap().numPlotsINLINE(); iI++)
		{
			pLoopPlot = GC.getMap().plotByIndexINLINE(iI);

			if (pLoopPlot->isRevealed(CvPlayerAI::getPlayer(eFromPlayer).getTeam(), false))
			{
				pLoopPlot->setRevealed(CvPlayerAI::getPlayer(eToPlayer).getTeam(), true, false, CvPlayerAI::getPlayer(eFromPlayer).getTeam());
			}
		}
		break;

	case TRADE_PEACE:
		CvTeamAI::getTeam(CvPlayerAI::getPlayer(eFromPlayer).getTeam()).makePeace((TeamTypes)trade.m_iData1);
		break;

	case TRADE_WAR:
		CvTeamAI::getTeam(CvPlayerAI::getPlayer(eFromPlayer).getTeam()).declareWar(((TeamTypes)trade.m_iData1), true, NO_WARPLAN);

		for (iI = 0; iI < MAX_PLAYERS; iI++)
		{
			if (CvPlayerAI::getPlayer((PlayerTypes)iI).isAlive())
			{
				if (CvPlayerAI::getPlayer((PlayerTypes)iI).getTeam() == ((TeamTypes)trade.m_iData1))
				{
					CvPlayerAI::getPlayer((PlayerTypes)iI).AI_changeMemoryCount(eToPlayer, MEMORY_HIRED_WAR_ALLY, 1);
				}
			}
		}
		break;

	case TRADE_EMBARGO:
		CvPlayerAI::getPlayer(eFromPlayer).stopTradingWithTeam((TeamTypes)trade.m_iData1);

		for (iI = 0; iI < MAX_PLAYERS; iI++)
		{
			if (CvPlayerAI::getPlayer((PlayerTypes)iI).isAlive())
			{
				if (CvPlayerAI::getPlayer((PlayerTypes)iI).getTeam() == ((TeamTypes)trade.m_iData1))
				{
					CvPlayerAI::getPlayer((PlayerTypes)iI).AI_changeMemoryCount(eToPlayer, MEMORY_HIRED_TRADE_EMBARGO, 1);
				}
			}
		}
		break;

	case TRADE_OPEN_BORDERS:
		if (trade.m_iData1 == 0)
		{
			startTeamTrade(TRADE_OPEN_BORDERS, CvPlayerAI::getPlayer(eFromPlayer).getTeam(), CvPlayerAI::getPlayer(eToPlayer).getTeam(), true, trade.m_kTransport);
			CvTeamAI::getTeam(CvPlayerAI::getPlayer(eFromPlayer).getTeam()).setOpenBorders(((TeamTypes)(CvPlayerAI::getPlayer(eToPlayer).getTeam())), true);
		}
		else
		{
			bSave = true;
		}
		break;

	case TRADE_DEFENSIVE_PACT:
		if (trade.m_iData1 == 0)
		{
			startTeamTrade(TRADE_DEFENSIVE_PACT, CvPlayerAI::getPlayer(eFromPlayer).getTeam(), CvPlayerAI::getPlayer(eToPlayer).getTeam(), true, trade.m_kTransport);
			CvTeamAI::getTeam(CvPlayerAI::getPlayer(eFromPlayer).getTeam()).setDefensivePact(((TeamTypes)(CvPlayerAI::getPlayer(eToPlayer).getTeam())), true);
		}
		else
		{
			bSave = true;
		}
		break;

	case TRADE_PERMANENT_ALLIANCE:
		break;

	case TRADE_PEACE_TREATY:
		CvTeamAI::getTeam(CvPlayerAI::getPlayer(eFromPlayer).getTeam()).setForcePeace(((TeamTypes)(CvPlayerAI::getPlayer(eToPlayer).getTeam())), true);
		bSave = true;
		break;

	default:
		FAssert(false);
		break;
	}

	return bSave;
}


void CvDeal::endTrade(TradeData trade, PlayerTypes eFromPlayer, PlayerTypes eToPlayer, bool bTeam, TeamTypes eEndingTeam)
{
	int iI, iJ;

	switch (trade.m_eItemType)
	{
	case TRADE_CITIES:
	case TRADE_GOLD:
	case TRADE_YIELD:
		FAssert(false);
		break;

	case TRADE_MAPS:
	case TRADE_PEACE:
	case TRADE_WAR:
	case TRADE_EMBARGO:
		FAssert(false);
		break;

	case TRADE_OPEN_BORDERS:
		CvTeamAI::getTeam(CvPlayerAI::getPlayer(eFromPlayer).getTeam()).setOpenBorders(((TeamTypes)(CvPlayerAI::getPlayer(eToPlayer).getTeam())), false);
		if (bTeam)
		{
			endTeamTrade(TRADE_OPEN_BORDERS, CvPlayerAI::getPlayer(eFromPlayer).getTeam(), CvPlayerAI::getPlayer(eToPlayer).getTeam(), eEndingTeam);
		}

		if (eEndingTeam == CvPlayerAI::getPlayer(eFromPlayer).getTeam())
		{
			for (iI = 0; iI < MAX_PLAYERS; iI++)
			{
				if (CvPlayerAI::getPlayer((PlayerTypes)iI).isAlive())
				{
					if (CvPlayerAI::getPlayer((PlayerTypes)iI).getTeam() == CvPlayerAI::getPlayer(eToPlayer).getTeam())
					{
						for (iJ = 0; iJ < MAX_PLAYERS; iJ++)
						{
							if (CvPlayerAI::getPlayer((PlayerTypes)iJ).isAlive())
							{
								if (CvPlayerAI::getPlayer((PlayerTypes)iJ).getTeam() == CvPlayerAI::getPlayer(eFromPlayer).getTeam())
								{
									CvPlayerAI::getPlayer((PlayerTypes)iI).AI_changeMemoryCount(((PlayerTypes)iJ), MEMORY_CANCELLED_OPEN_BORDERS, 1);
								}
							}
						}
					}
				}
			}
		}
		break;

	case TRADE_DEFENSIVE_PACT:
		CvTeamAI::getTeam(CvPlayerAI::getPlayer(eFromPlayer).getTeam()).setDefensivePact(((TeamTypes)(CvPlayerAI::getPlayer(eToPlayer).getTeam())), false);
		if (bTeam)
		{
			endTeamTrade(TRADE_DEFENSIVE_PACT, CvPlayerAI::getPlayer(eFromPlayer).getTeam(), CvPlayerAI::getPlayer(eToPlayer).getTeam(), eEndingTeam);
		}
		break;

	case TRADE_PERMANENT_ALLIANCE:
		FAssert(false);
		break;

	case TRADE_PEACE_TREATY:
		CvTeamAI::getTeam(CvPlayerAI::getPlayer(eFromPlayer).getTeam()).setForcePeace(((TeamTypes)(CvPlayerAI::getPlayer(eToPlayer).getTeam())), false);
		break;

	default:
		FAssert(false);
		break;
	}
}

void CvDeal::startTeamTrade(TradeableItems eItem, TeamTypes eFromTeam, TeamTypes eToTeam, bool bDual, const IDInfo& kTransport)
{
	for (int iI = 0; iI < MAX_PLAYERS; iI++)
	{
		CvPlayer& kLoopFromPlayer = CvPlayerAI::getPlayer((PlayerTypes)iI);
		if (kLoopFromPlayer.isAlive() )
		{
			if (kLoopFromPlayer.getTeam() == eFromTeam)
			{
				for (int iJ = 0; iJ < MAX_PLAYERS; iJ++)
				{
					CvPlayer& kLoopToPlayer = CvPlayerAI::getPlayer((PlayerTypes)iJ);
					if (kLoopToPlayer.isAlive())
					{
						if (kLoopToPlayer.getTeam() == eToTeam)
						{
							TradeData item;
							setTradeItem(&item, eItem, 1, &kTransport);
							CLinkList<TradeData> ourList;
							ourList.insertAtEnd(item);
							CLinkList<TradeData> theirList;
							if (bDual)
							{
								theirList.insertAtEnd(item);
							}
							GC.getGame().implementDeal((PlayerTypes)iI, (PlayerTypes)iJ, &ourList, &theirList);
						}
					}
				}
			}
		}
	}
}

void CvDeal::endTeamTrade(TradeableItems eItem, TeamTypes eFromTeam, TeamTypes eToTeam, TeamTypes eEndingTeam)
{
	CvDeal* pLoopDeal;
	int iLoop;
	CLLNode<TradeData>* pNode;

	for (pLoopDeal = GC.getGameINLINE().firstDeal(&iLoop); pLoopDeal != nullptr; pLoopDeal = GC.getGameINLINE().nextDeal(&iLoop))
	{
		if (pLoopDeal != this)
		{
			bool bValid = true;

			if (CvPlayerAI::getPlayer(pLoopDeal->getFirstPlayer()).getTeam() == eFromTeam && CvPlayerAI::getPlayer(pLoopDeal->getSecondPlayer()).getTeam() == eToTeam)
			{
				if (pLoopDeal->getFirstTrades())
				{
					for (pNode = pLoopDeal->getFirstTrades()->head(); pNode; pNode = pLoopDeal->getFirstTrades()->next(pNode))
					{
						if (pNode->m_data.m_eItemType == eItem)
						{
							bValid = false;
						}
					}
				}
			}

			if (bValid && CvPlayerAI::getPlayer(pLoopDeal->getFirstPlayer()).getTeam() == eToTeam && CvPlayerAI::getPlayer(pLoopDeal->getSecondPlayer()).getTeam() == eFromTeam)
			{
				if (pLoopDeal->getSecondTrades() != nullptr)
				{
					for (pNode = pLoopDeal->getSecondTrades()->head(); pNode; pNode = pLoopDeal->getSecondTrades()->next(pNode))
					{
						if (pNode->m_data.m_eItemType == eItem)
						{
							bValid = false;
						}
					}
				}
			}

			if (!bValid)
			{
				pLoopDeal->kill(false, eEndingTeam);
			}
		}
	}
}

bool CvDeal::isCancelable(PlayerTypes eByPlayer, CvWString* pszReason)
{
	int iTurns = turnsToCancel(eByPlayer);
	if (pszReason)
	{
		if (iTurns > 0)
		{
			*pszReason = gDLL->getText("TXT_KEY_MISC_DEAL_NO_CANCEL", iTurns);
		}
	}

	return (iTurns <= 0);
}

int CvDeal::turnsToCancel(PlayerTypes eByPlayer)
{
	return (getInitialGameTurn() + GC.getDefineINT("PEACE_TREATY_LENGTH") - GC.getGameINLINE().getGameTurn());
}


// static
bool CvDeal::isAnnual(TradeableItems eItem)
{
	switch (eItem)
	{
	case TRADE_OPEN_BORDERS:
	case TRADE_DEFENSIVE_PACT:
	case TRADE_PERMANENT_ALLIANCE:
		return true;
		break;
	}

	return false;
}

// static
bool CvDeal::isDual(TradeableItems eItem, bool bExcludePeace)
{
	switch (eItem)
	{
	case TRADE_OPEN_BORDERS:
	case TRADE_DEFENSIVE_PACT:
	case TRADE_PERMANENT_ALLIANCE:
		return true;
	case TRADE_PEACE_TREATY:
		return (!bExcludePeace);
	}

	return false;
}

// static
bool CvDeal::hasData(TradeableItems eItem)
{
	return (eItem != TRADE_MAPS &&
		eItem != TRADE_OPEN_BORDERS &&
		eItem != TRADE_DEFENSIVE_PACT &&
		eItem != TRADE_PERMANENT_ALLIANCE &&
		eItem != TRADE_PEACE_TREATY);
}

bool CvDeal::isGold(TradeableItems eItem)
{
	return (eItem == getGoldItem());
}

bool CvDeal::isEndWar(TradeableItems eItem)
{
	if (eItem == getPeaceItem())
	{
		return true;
	}

	return false;
}

TradeableItems CvDeal::getPeaceItem()
{
	return TRADE_PEACE_TREATY;
}

TradeableItems CvDeal::getGoldItem()
{
	return TRADE_GOLD;
}
