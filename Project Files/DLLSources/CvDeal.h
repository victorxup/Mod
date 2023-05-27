#pragma once

// CvDeal.h

#ifndef CIV4_DEAL_H
#define CIV4_DEAL_H

//#include "CvStructs.h"
#include "LinkedList.h"

class CvDeal
{

public:

	CvDeal();
	virtual ~CvDeal();

	void init(int iID, PlayerTypes eFirstPlayer, PlayerTypes eSecondPlayer);
	void uninit();

	__declspec(dllexport) void kill(bool bKillTeam, TeamTypes eKillingTeam);

	void addTrades(CLinkList<TradeData>* pFirstList, CLinkList<TradeData>* pSecondList, bool bCheckAllowed);

	void doTurn();

	void verify();

	bool isPeaceDeal() const;
	bool isPeaceDealBetweenOthers(CLinkList<TradeData>* pFirstList, CLinkList<TradeData>* pSecondList) const;

	__declspec(dllexport) int getID() const;
	void setID(int iID);

	int getInitialGameTurn() const;
	void setInitialGameTurn(int iNewValue);

	__declspec(dllexport) PlayerTypes getFirstPlayer() const;
	__declspec(dllexport) PlayerTypes getSecondPlayer() const;

	void clearFirstTrades();
	void insertAtEndFirstTrades(TradeData trade);
	__declspec(dllexport) CLLNode<TradeData>* nextFirstTradesNode(CLLNode<TradeData>* pNode) const;
	int getLengthFirstTrades() const;
	__declspec(dllexport) CLLNode<TradeData>* headFirstTradesNode() const;
	const CLinkList<TradeData>* getFirstTrades() const;

	void clearSecondTrades();
	void insertAtEndSecondTrades(TradeData trade);
	__declspec(dllexport) CLLNode<TradeData>* nextSecondTradesNode(CLLNode<TradeData>* pNode) const;
	int getLengthSecondTrades() const;
	__declspec(dllexport) CLLNode<TradeData>* headSecondTradesNode() const;
	const CLinkList<TradeData>* getSecondTrades() const;

	__declspec(dllexport) bool isCancelable(PlayerTypes eByPlayer = NO_PLAYER, CvWString* pszReason = nullptr);
	int turnsToCancel(PlayerTypes eByPlayer = NO_PLAYER);

	static bool isAnnual(TradeableItems eItem);
	__declspec(dllexport) static bool isDual(TradeableItems eItem, bool bExcludePeace = false);
	__declspec(dllexport) static bool hasData(TradeableItems eItem);
	__declspec(dllexport) static bool isGold(TradeableItems eItem);
	__declspec(dllexport) static bool isEndWar(TradeableItems eItem);
	__declspec(dllexport) static TradeableItems getPeaceItem();
	__declspec(dllexport) static TradeableItems getGoldItem();

	void read(FDataStreamBase* pStream);
	void write(FDataStreamBase* pStream) const;

	void read(CvSavegameReader& reader);
	void write(CvSavegameWriter& writer) const;

	void resetSavedData(int iID = 0, PlayerTypes eFirstPlayer = NO_PLAYER, PlayerTypes eSecondPlayer = NO_PLAYER);

protected:
	void reset(int iID = 0, PlayerTypes eFirstPlayer = NO_PLAYER, PlayerTypes eSecondPlayer = NO_PLAYER);

	bool startTrade(TradeData trade, PlayerTypes eFromPlayer, PlayerTypes eToPlayer);
	void endTrade(TradeData trade, PlayerTypes eFromPlayer, PlayerTypes eToPlayer, bool bTeam, TeamTypes eEndingTeam);

	void startTeamTrade(TradeableItems eItem, TeamTypes eFromTeam, TeamTypes eToTeam, bool bDual, const IDInfo& kTransport);
	void endTeamTrade(TradeableItems eItem, TeamTypes eFromTeam, TeamTypes eToTeam, TeamTypes eEndingTeam);

	int m_iID;
	int m_iInitialGameTurn;

	PlayerTypes m_eFirstPlayer;
	PlayerTypes m_eSecondPlayer;

	CLinkList<TradeData> m_firstTrades;
	CLinkList<TradeData> m_secondTrades;
};

#endif
