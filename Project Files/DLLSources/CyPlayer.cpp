//
// Python wrapper class for CvPlayer
//
#include "CvGameCoreDLL.h"
#include "CyPlayer.h"
#include "CyUnit.h"
#include "CyCity.h"
#include "CyArea.h"
#include "CyPlot.h"
#include "CvPlayerAI.h"
//#include "CvEnums.h"
#include "CvCity.h"
#include "CvMap.h"
#include "CvPlot.h"
#include "CySelectionGroup.h"
#include "CvDLLPythonIFaceBase.h"
#include "CvGlobals.h"
#include "CyTradeRoute.h"
#include "CyTradeRouteGroup.h" // R&R mod, vetiarvind, trade groups
#include "CyData.h"


CyPlayer::CyPlayer() : m_pPlayer(nullptr)
{
}
CyPlayer::CyPlayer(CvPlayer* pPlayer) : m_pPlayer(pPlayer)
{
}
int CyPlayer::startingPlotRange()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->startingPlotRange();
}
CyPlot* CyPlayer::findStartingPlot(bool bRandomize)
{
	if (m_pPlayer == nullptr)
		return nullptr;
	return new CyPlot(m_pPlayer->findStartingPlot(bRandomize));
}
CyCity* CyPlayer::initCity(int x, int y)
{
	if (m_pPlayer == nullptr)
		return nullptr;
	return new CyCity(m_pPlayer->initCity(Coordinates(x, y), true));
}
void CyPlayer::acquireCity(CyCity* pCity, bool bConquest, bool bTrade)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->acquireCity(pCity->getCity(), bConquest, bTrade);
}
void CyPlayer::killCities()
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->killCities();
}
std::wstring CyPlayer::getNewCityName()
{
	if (m_pPlayer == nullptr)
		return std::wstring();
	return m_pPlayer->getNewCityName();
}
CyUnit* CyPlayer::initUnit(int /*UnitTypes*/ iIndex, int iProfession, int iX, int iY, UnitAITypes eUnitAI, DirectionTypes eFacingDirection, int iYieldStored)
{
	if (m_pPlayer == nullptr)
		return nullptr;
	return new CyUnit(m_pPlayer->initUnit(static_cast<UnitTypes>(iIndex), static_cast<ProfessionTypes>(iProfession), iX, iY, eUnitAI, eFacingDirection, iYieldStored));
}
CyUnit* CyPlayer::initEuropeUnit(int /*UnitTypes*/ eUnit, UnitAITypes eUnitAI, DirectionTypes eFacingDirection)
{
	if (m_pPlayer == nullptr)
		return nullptr;
	return new CyUnit(m_pPlayer->initEuropeUnit(static_cast<UnitTypes>(eUnit), eUnitAI, eFacingDirection));
}
void CyPlayer::killUnits()
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->killUnits();
}
bool CyPlayer::hasTrait(int /*TraitTypes*/ iIndex)
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->hasTrait(static_cast<TraitTypes>(iIndex));
}
bool CyPlayer::isHuman()
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->isHuman();
}
bool CyPlayer::isNative()
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->isNative();
}
std::wstring CyPlayer::getName()
{
	if (m_pPlayer == nullptr)
		return std::wstring();
	return m_pPlayer->getName();
}
std::wstring CyPlayer::getNameForm(int iForm)
{
	if (m_pPlayer == nullptr)
		return std::wstring();
	return m_pPlayer->getName(static_cast<uint>(iForm));
}
std::wstring CyPlayer::getNameKey()
{
	if (m_pPlayer == nullptr)\
		return std::wstring();
	return m_pPlayer->getNameKey();
}
std::wstring CyPlayer::getCivilizationDescription(int iForm)
{
	if (m_pPlayer == nullptr)
		return std::wstring();
	return m_pPlayer->getCivilizationDescription(static_cast<uint>(iForm));
}
std::wstring CyPlayer::getCivilizationDescriptionKey()
{
	if (m_pPlayer == nullptr)
		return std::wstring();
	return m_pPlayer->getCivilizationDescriptionKey();
}
std::wstring CyPlayer::getCivilizationShortDescription(int iForm)
{
	if (m_pPlayer == nullptr)
		return std::wstring();
	return m_pPlayer->getCivilizationShortDescription(static_cast<uint>(iForm));
}
std::wstring CyPlayer::getCivilizationShortDescriptionKey()
{
	if (m_pPlayer == nullptr)
		return std::wstring();
	return m_pPlayer->getCivilizationShortDescriptionKey();
}
std::wstring CyPlayer::getCivilizationAdjective(int iForm)
{
	if (m_pPlayer == nullptr)
		return std::wstring();
	return m_pPlayer->getCivilizationAdjective(static_cast<uint>(iForm));
}
std::wstring CyPlayer::getCivilizationAdjectiveKey( )
{
	if (m_pPlayer == nullptr)
		return std::wstring();
	return m_pPlayer->getCivilizationAdjectiveKey();
}
std::wstring CyPlayer::getWorstEnemyName()
{
	if (m_pPlayer == nullptr)
		return std::wstring();
	return m_pPlayer->getWorstEnemyName();
}
int /*ArtStyleTypes*/ CyPlayer::getArtStyleType()
{
	if (m_pPlayer == nullptr)
		return NO_ARTSTYLE;
	return static_cast<int>(m_pPlayer->getArtStyleType());
}
std::string CyPlayer::getUnitButton(int eUnit)
{
	if (m_pPlayer == nullptr)
		return std::string();
	return m_pPlayer->getUnitButton(static_cast<UnitTypes>(eUnit));
}
int CyPlayer::findBestFoundValue( )
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->findBestFoundValue();
}
int CyPlayer::countNumCoastalCities()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->countNumCoastalCities();
}
int CyPlayer::countNumCoastalCitiesByArea(CyArea* pArea)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->countNumCoastalCitiesByArea(pArea->getArea());
}
int CyPlayer::countTotalCulture()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->countTotalCulture();
}
int CyPlayer::countTotalYieldStored(int /*YieldTypes*/ eYield)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->countTotalYieldStored(static_cast<YieldTypes>(eYield));
}
int CyPlayer::countCityFeatures(int /*FeatureTypes*/ eFeature)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->countCityFeatures(static_cast<FeatureTypes>(eFeature));
}
int CyPlayer::countNumBuildings(int /*BuildingTypes*/ eBuilding)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->countNumBuildings(static_cast<BuildingTypes>(eBuilding));
}
bool CyPlayer::canContact(int /*PlayerTypes*/ ePlayer)
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->canContact(static_cast<PlayerTypes>(ePlayer));
}
void CyPlayer::contact(int /*PlayerTypes*/ ePlayer)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->contact(static_cast<PlayerTypes>(ePlayer));
}
bool CyPlayer::canTradeWith(int /*PlayerTypes*/ eWhoTo)
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->canTradeWith(static_cast<PlayerTypes>(eWhoTo));
}
bool CyPlayer::canTradeItem(int /*PlayerTypes*/ eWhoTo, TradeData item, bool bTestDenial)
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->canTradeItem(static_cast<PlayerTypes>(eWhoTo), item, bTestDenial);
}
DenialTypes CyPlayer::getTradeDenial(int /*PlayerTypes*/ eWhoTo, TradeData item)
{
	if (m_pPlayer == nullptr)
		return NO_DENIAL;
	return m_pPlayer->getTradeDenial(static_cast<PlayerTypes>(eWhoTo), item);
}
bool CyPlayer::canStopTradingWithTeam(int /*TeamTypes*/ eTeam)
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->canStopTradingWithTeam(static_cast<TeamTypes>(eTeam));
}
void CyPlayer::stopTradingWithTeam(int /*TeamTypes*/ eTeam)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->stopTradingWithTeam(static_cast<TeamTypes>(eTeam));
}
void CyPlayer::killAllDeals()
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->killAllDeals();
}
bool CyPlayer::isTurnActive()
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->isTurnActive();
}
void CyPlayer::findNewCapital()
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->findNewCapital();
}
bool CyPlayer::canRaze(CyCity* pCity)
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->canRaze(pCity->getCity());
}
void CyPlayer::raze(CyCity* pCity)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->raze(pCity->getCity());
}
void CyPlayer::disband(CyCity* pCity)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->disband(pCity->getCity());
}
bool CyPlayer::canReceiveGoody(CyPlot* pPlot, int /*GoodyTypes*/ iIndex, CyUnit* pUnit)
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->canReceiveGoody(pPlot->getPlot(), static_cast<GoodyTypes>(iIndex), pUnit->getUnit());
}
void CyPlayer::receiveGoody(CyPlot* pPlot, int /*GoodyTypes*/ iIndex, CyUnit* pUnit)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->receiveGoody(pPlot->getPlot(), static_cast<GoodyTypes>(iIndex), pUnit->getUnit());
}
void CyPlayer::doGoody(CyPlot* pPlot, CyUnit* pUnit)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->doGoody(pPlot->getPlot(), pUnit->getUnit());
}
bool CyPlayer::canFound(int iX, int iY)
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->canFound(Coordinates(iX, iY));
}
void CyPlayer::found(int x, int y)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->found(Coordinates(x,y));
}
bool CyPlayer::canTrain(int /*UnitTypes*/ eUnit, bool bContinue, bool bTestVisible)
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->canTrain(static_cast<UnitTypes>(eUnit), bContinue, bTestVisible);
}
bool CyPlayer::canConstruct(int /*BuildingTypes*/eBuilding, bool bContinue, bool bTestVisible, bool bIgnoreCost)
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->canConstruct(static_cast<BuildingTypes>(eBuilding), bContinue, bTestVisible, bIgnoreCost);
}
int CyPlayer::getUnitYieldProductionNeeded(int /*UnitTypes*/ eUnit, int /*YieldTypes*/ eYield) const
{
	if (m_pPlayer == nullptr)
		return 0;
	return m_pPlayer->getYieldProductionNeeded(static_cast<UnitTypes>(eUnit), static_cast<YieldTypes>(eYield));
}
int CyPlayer::getBuildingYieldProductionNeeded(int /*BuildingTypes*/ eBuilding, int /*YieldTypes*/ eYield) const
{
	if (m_pPlayer == nullptr)
		return 0;
	return m_pPlayer->getYieldProductionNeeded(static_cast<BuildingTypes>(eBuilding), static_cast<YieldTypes>(eYield));
}
int CyPlayer::getBuildingClassPrereqBuilding(int /*BuildingTypes*/ eBuilding, int /*BuildingClassTypes*/ ePrereqBuildingClass, int iExtra)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getBuildingClassPrereqBuilding(static_cast<BuildingTypes>(eBuilding), static_cast<BuildingClassTypes>(ePrereqBuildingClass), iExtra);
}
void CyPlayer::removeBuildingClass(int /*BuildingClassTypes*/ eBuildingClass)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->removeBuildingClass(static_cast<BuildingClassTypes>(eBuildingClass));
}
bool CyPlayer::canBuild(CyPlot* pPlot, int /*BuildTypes*/ eBuild, bool bTestEra, bool bTestVisible)
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->canBuild(pPlot->getPlot(), static_cast<BuildTypes>(eBuild), bTestEra, bTestVisible);
}
int /*RouteTypes*/ CyPlayer::getBestRoute(CyPlot* pPlot) const
{
	if (m_pPlayer == nullptr || pPlot == nullptr)
		return NO_ROUTE;
	return static_cast<int>(m_pPlayer->getBestRoute(pPlot->getPlot()));
}
int CyPlayer::getImprovementUpgradeRate() const
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getImprovementUpgradeRate();
}
int CyPlayer::calculateTotalYield(int /*YieldTypes*/ eYield)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->calculateTotalYield(static_cast<YieldTypes>(eYield));
}
bool CyPlayer::isCivic(int /*CivicTypes*/ eCivic)
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->isCivic(static_cast<CivicTypes>(eCivic));
}
bool CyPlayer::canDoCivics(int /*CivicTypes*/ eCivic)
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->canDoCivics(static_cast<CivicTypes>(eCivic));
}
int CyPlayer::greatGeneralThreshold()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->greatGeneralThreshold();
}
// R&R, ray, Great Admirals - START
int CyPlayer::greatAdmiralThreshold()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->greatAdmiralThreshold();
}
// R&R, ray, Great Admirals - END
int CyPlayer::immigrationThreshold()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->immigrationThreshold();
}
int CyPlayer::revolutionEuropeUnitThreshold()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->revolutionEuropeUnitThreshold();
}
CyPlot* CyPlayer::getStartingPlot()
{
	if (m_pPlayer == nullptr)
		return nullptr;
	return new CyPlot(m_pPlayer->getStartingPlot());
}
void CyPlayer::setStartingPlot(CyPlot* pPlot, bool bUpdateStartDist)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->setStartingPlot(pPlot != nullptr ? pPlot->getPlot() : nullptr, bUpdateStartDist);
}
int CyPlayer::getTotalPopulation()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getTotalPopulation();
}
int CyPlayer::getAveragePopulation()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getAveragePopulation();
}
long CyPlayer::getRealPopulation()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getRealPopulation();
}
int CyPlayer::getTotalLand()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getTotalLand();
}
int CyPlayer::getTotalLandScored()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getTotalLandScored();
}
int CyPlayer::getGold()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getGold();
}
void CyPlayer::setGold(int iNewValue)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->setGold(iNewValue);
}
void CyPlayer::changeGold(int iChange)
{
	if (m_pPlayer == nullptr)
		return;
	OOS_LOG_3("Python change gold", m_pPlayer->getID(), iChange);
	m_pPlayer->changeGold(iChange);
}
int CyPlayer::getAdvancedStartPoints()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getAdvancedStartPoints();
}
void CyPlayer::setAdvancedStartPoints(int iNewValue)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->setAdvancedStartPoints(iNewValue);
}
void CyPlayer::changeAdvancedStartPoints(int iChange)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->changeAdvancedStartPoints(iChange);
}
int CyPlayer::getAdvancedStartUnitCost(int /*UnitTypes*/ eUnit, bool bAdd, CyPlot* pPlot)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getAdvancedStartUnitCost(static_cast<UnitTypes>(eUnit), bAdd, pPlot != nullptr ? pPlot->getPlot() : nullptr);
}
int CyPlayer::getAdvancedStartCityCost(bool bAdd, CyPlot* pPlot)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getAdvancedStartCityCost(bAdd, pPlot != nullptr ? pPlot->getPlot() : nullptr);
}
int CyPlayer::getAdvancedStartPopCost(bool bAdd, CyCity* pCity)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getAdvancedStartPopCost(bAdd, pCity->getCity());
}
int CyPlayer::getAdvancedStartCultureCost(bool bAdd, CyCity* pCity)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getAdvancedStartCultureCost(bAdd, pCity->getCity());
}
int CyPlayer::getAdvancedStartBuildingCost(int /*BuildingTypes*/ eBuilding, bool bAdd, CyCity* pCity)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getAdvancedStartBuildingCost(static_cast<BuildingTypes>(eBuilding), bAdd, pCity->getCity());
}
int CyPlayer::getAdvancedStartImprovementCost(int /*ImprovementTypes*/ eImprovement, bool bAdd, CyPlot* pPlot)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getAdvancedStartImprovementCost(static_cast<ImprovementTypes>(eImprovement), bAdd, pPlot != nullptr ? pPlot->getPlot() : nullptr);
}
int CyPlayer::getAdvancedStartRouteCost(int /*RouteTypes*/ eRoute, bool bAdd, CyPlot* pPlot)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getAdvancedStartRouteCost(static_cast<RouteTypes>(eRoute), bAdd, pPlot != nullptr ? pPlot->getPlot() : nullptr);
}
int CyPlayer::getAdvancedStartVisibilityCost(bool bAdd, CyPlot* pPlot)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getAdvancedStartVisibilityCost(bAdd, pPlot != nullptr ? pPlot->getPlot() : nullptr);
}
void CyPlayer::createGreatGeneral(int eGreatGeneralUnit, bool bIncrementExperience, int iX, int iY)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->createGreatGeneral(static_cast<UnitTypes>(eGreatGeneralUnit), bIncrementExperience, Coordinates(iX, iY));
}
int CyPlayer::getGreatGeneralsCreated()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getGreatGeneralsCreated();
}
int CyPlayer::getGreatGeneralsThresholdModifier()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getGreatGeneralsThresholdModifier();
}

// R&R, ray, Great Admirals - START
void CyPlayer::createGreatAdmiral(int eGreatAdmiralUnit, bool bIncrementExperience, int iX, int iY)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->createGreatAdmiral(static_cast<UnitTypes>(eGreatAdmiralUnit), bIncrementExperience, Coordinates(iX, iY));
}
int CyPlayer::getGreatAdmiralsCreated()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getGreatAdmiralsCreated();
}
int CyPlayer::getGreatAdmiralsThresholdModifier()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getGreatAdmiralsThresholdModifier();
}
// R&R, ray, Great Admirals -END

// WTP, ray, Lieutenants and Captains - START
void CyPlayer::createBraveLieutenant(int eBraveLieutenantUnit, int iX, int iY)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->createBraveLieutenant(static_cast<UnitTypes>(eBraveLieutenantUnit), Coordinates(iX, iY));
}
void CyPlayer::createCapableCaptain(int eCapableCaptainUnit, int iX, int iY)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->createCapableCaptain(static_cast<UnitTypes>(eCapableCaptainUnit), Coordinates(iX, iY));
}
// WTP, ray, Lieutenants and Captains - END

int CyPlayer::getGreatGeneralRateModifier()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getGreatGeneralRateModifier();
}
int CyPlayer::getDomesticGreatGeneralRateModifier()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getDomesticGreatGeneralRateModifier();
}
int CyPlayer::getFreeExperience()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getFreeExperience();
}
int CyPlayer::getWorkerSpeedModifier()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getWorkerSpeedModifier();
}
int CyPlayer::getImprovementUpgradeRateModifier()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getImprovementUpgradeRateModifier();
}
int CyPlayer::getMilitaryProductionModifier()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getMilitaryProductionModifier();
}
int CyPlayer::getCityDefenseModifier()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getCityDefenseModifier();
}
int CyPlayer::getHighestUnitLevel()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getHighestUnitLevel();
}
bool CyPlayer::getExpInBorderModifier()
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->getExpInBorderModifier();
}
int CyPlayer::getLevelExperienceModifier() const
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getLevelExperienceModifier();
}
CyCity* CyPlayer::getCapitalCity()
{
	if (m_pPlayer == nullptr)
		return nullptr;
	return new CyCity(m_pPlayer->getCapitalCity());
}
int CyPlayer::getCitiesLost()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getCitiesLost();
}
int CyPlayer::getAssets()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getAssets();
}
void CyPlayer::changeAssets(int iChange)
{
	if (m_pPlayer == nullptr)
		return;
	OOS_LOG("python change assets", iChange);
	m_pPlayer->changeAssets(iChange);
}
int CyPlayer::getPower()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getPower();
}
int CyPlayer::getPopScore()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getPopScore();
}
int CyPlayer::getLandScore()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getLandScore();
}
int CyPlayer::getFatherScore()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getFatherScore();
}
int CyPlayer::getTotalTimePlayed()
{
	if (m_pPlayer == nullptr)
		return -1;
	return static_cast<int>(m_pPlayer->getTotalTimePlayed());
}
bool CyPlayer::isAlive()
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->isAlive();
}
bool CyPlayer::isEverAlive()
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->isEverAlive();
}
bool CyPlayer::isExtendedGame()
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->isExtendedGame();
}
bool CyPlayer::isFoundedFirstCity()
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->isFoundedFirstCity();
}
int /*PlayerTypes*/ CyPlayer::getID() const
{
	if (m_pPlayer == nullptr)
		return NO_PLAYER;
	return static_cast<int>(m_pPlayer->getID());
}
WidgetTypes CyPlayer::getWikiWidget() const
{
	return WIDGET_MISSION_CHAR;
}
int CyPlayer::getChar() const
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getCivilizationInfo().getMissionaryChar();
}
int /*HandicapTypes*/ CyPlayer::getHandicapType()
{
	if (m_pPlayer == nullptr)
		return static_cast<int>(NO_HANDICAP);
	return static_cast<int>(m_pPlayer->getHandicapType());
}
int /*CivilizationTypes*/  CyPlayer::getCivilizationType()
{
	if (m_pPlayer == nullptr)
		return static_cast<int>(NO_CIVILIZATION);
	return static_cast<int>(m_pPlayer->getCivilizationType());
}
int /*LeaderHeadTypes*/ CyPlayer::getLeaderType()
{
	if (m_pPlayer == nullptr)
		return static_cast<int>(NO_LEADER);
	return static_cast<int>(m_pPlayer->getLeaderType());
}
int /*LeaderHeadTypes*/ CyPlayer::getPersonalityType()
{
	if (m_pPlayer == nullptr)
		return static_cast<int>(NO_LEADER);
	return static_cast<int>(m_pPlayer->getPersonalityType());
}
void CyPlayer::setPersonalityType(int /*LeaderHeadTypes*/ eNewValue)
{
	if (m_pPlayer)
		m_pPlayer->setPersonalityType(static_cast<LeaderHeadTypes>(eNewValue));
}
int /*ErasTypes*/ CyPlayer::getCurrentEra()
{
	if (m_pPlayer == nullptr)
		return static_cast<int>(NO_ERA);
	return static_cast<int>(m_pPlayer->getCurrentEra());
}
void CyPlayer::setCurrentEra(int /*EraTypes*/ iNewValue)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->setCurrentEra(static_cast<EraTypes>(iNewValue));
}
int /*PlayerTypes*/ CyPlayer::getParent()
{
	if (m_pPlayer == nullptr)
		return static_cast<int>(NO_PLAYER);
	return static_cast<int>(m_pPlayer->getParent());
}

int /*TeamTypes*/ CyPlayer::getTeam()
{
	if (m_pPlayer == nullptr)
		return static_cast<int>(NO_TEAM);
	return static_cast<int>(m_pPlayer->getTeam());
}
int /*PlayerColorTypes*/ CyPlayer::getPlayerColor()
{
	if (m_pPlayer == nullptr)
		return static_cast<int>(NO_COLOR);
	return static_cast<int>(m_pPlayer->getPlayerColor());
}
int CyPlayer::getPlayerTextColorR()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getPlayerTextColorR();
}
int CyPlayer::getPlayerTextColorG()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getPlayerTextColorG();
}
int CyPlayer::getPlayerTextColorB()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getPlayerTextColorB();
}
int CyPlayer::getPlayerTextColorA()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getPlayerTextColorA();
}
int CyPlayer::getSeaPlotYield(YieldTypes eIndex)
{
	if (m_pPlayer == nullptr)
		return 0;
	return m_pPlayer->getSeaPlotYield(eIndex);
}
// R&R, Robert Surcouf, No More Variables Hidden game option START
int CyPlayer::getYieldTradedTotal(YieldTypes eIndex)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getYieldTradedTotal(eIndex);
}
int CyPlayer::getYieldTradedTotalINT(int /*YieldTypes*/ eIndex)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getYieldTradedTotal(static_cast<YieldTypes>(eIndex));
}
// R&R, Robert Surcouf, No More Variables Hidden game option END

// WTP, ray, Yields Traded Total for Africa and Port Royal - START
int CyPlayer::getYieldTradedTotalAfrica(YieldTypes eIndex)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getYieldTradedTotalAfrica(eIndex);
}
int CyPlayer::getYieldTradedTotalINTAfrica(int /*YieldTypes*/ eIndex)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getYieldTradedTotalAfrica(static_cast<YieldTypes>(eIndex));
}

int CyPlayer::getYieldTradedTotalPortRoyal(YieldTypes eIndex)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getYieldTradedTotalPortRoyal(eIndex);
}
int CyPlayer::getYieldTradedTotalINTPortRoyal(int /*YieldTypes*/ eIndex)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getYieldTradedTotalPortRoyal(static_cast<YieldTypes>(eIndex));
}
// WTP, ray, Yields Traded Total for Africa and Port Royal - END

// R&R, vetiarvind, Price dependent tax rate change - START
int CyPlayer::getYieldScoreTotalINT(int /*YieldTypes*/ eIndex)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getYieldScoreTotal(static_cast<YieldTypes>(eIndex));
}
// R&R, vetiarvind, Price dependent tax rate change - END

int CyPlayer::getYieldRate(YieldTypes eIndex)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getYieldRate(eIndex);
}
// WTP, ray, Happiness - START
int CyPlayer::getHappinessRate()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getHappinessRate();
}
int CyPlayer::getUnHappinessRate()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getUnHappinessRate();
}
// WTP, ray, Happiness - END

// WTP, ray, Crime and Law - START
int CyPlayer::getLawRate()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getLawRate();
}
int CyPlayer::getCrimeRate()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getCrimeRate();
}
// WTP, ray, Crime and Law - END

int CyPlayer::getYieldRateModifier(YieldTypes eIndex)
{
	if (m_pPlayer == nullptr)
		return 0;
	return m_pPlayer->getYieldRateModifier(eIndex);
}
int CyPlayer::getCapitalYieldRateModifier(YieldTypes eIndex)
{
	if (m_pPlayer == nullptr)
		return 0;
	return m_pPlayer->getCapitalYieldRateModifier(eIndex);
}
int CyPlayer::getExtraYieldThreshold(YieldTypes eIndex)
{
	if (m_pPlayer == nullptr)
		return 0;
	return m_pPlayer->getExtraYieldThreshold(eIndex);
}
bool CyPlayer::isYieldEuropeTradable(int /*YieldTypes*/ eIndex)
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->isYieldEuropeTradable(static_cast<YieldTypes>(eIndex));
}
void CyPlayer::setYieldEuropeTradable(int /*YieldTypes*/ eIndex, bool bTradeable)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->setYieldEuropeTradable(static_cast<YieldTypes>(eIndex), bTradeable);
}
bool CyPlayer::isFeatAccomplished(int /*FeatTypes*/ eIndex)
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->isFeatAccomplished(static_cast<FeatTypes>(eIndex));
}
void CyPlayer::setFeatAccomplished(int /*FeatTypes*/ eIndex, bool bNewValue)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->setFeatAccomplished(static_cast<FeatTypes>(eIndex), bNewValue);
}
bool CyPlayer::shouldDisplayFeatPopup(int /*FeatTypes*/ eIndex)
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->shouldDisplayFeatPopup(static_cast<FeatTypes>(eIndex));
}
bool CyPlayer::isOption(int /*PlayerOptionTypes*/ eIndex)
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->isOption(static_cast<PlayerOptionTypes>(eIndex));
}
void CyPlayer::setOption(int /*PlayerOptionTypes*/ eIndex, bool bNewValue)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->setOption(static_cast<PlayerOptionTypes>(eIndex), bNewValue);
}
bool CyPlayer::isPlayable()
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->isPlayable();
}
void CyPlayer::setPlayable(bool bNewValue)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->setPlayable(bNewValue);
}
int CyPlayer::getImprovementCount(int /*ImprovementTypes*/ iIndex)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getImprovementCount(static_cast<ImprovementTypes>(iIndex));
}
bool CyPlayer::isBuildingFree(int /*BuildingTypes*/ iIndex)
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->isBuildingFree(static_cast<BuildingTypes>(iIndex));
}
int CyPlayer::getUnitClassCount(int /*UnitClassTypes*/ eIndex)
{
	if (m_pPlayer == nullptr)
		return NO_UNITCLASS;
	return m_pPlayer->getUnitClassCount(static_cast<UnitClassTypes>(eIndex));
}
int CyPlayer::getUnitClassMaking(int /*UnitClassTypes*/ eIndex)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getUnitClassMaking(static_cast<UnitClassTypes>(eIndex));
}
int CyPlayer::getUnitClassCountPlusMaking(int /*UnitClassTypes*/ eIndex)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getUnitClassCountPlusMaking(static_cast<UnitClassTypes>(eIndex));
}
int CyPlayer::getBuildingClassCount(int /*BuildingClassTypes*/ iIndex)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getBuildingClassCount(static_cast<BuildingClassTypes>(iIndex));
}
int CyPlayer::getBuildingClassMaking(int /*BuildingClassTypes*/ iIndex)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getBuildingClassMaking(static_cast<BuildingClassTypes>(iIndex));
}
int CyPlayer::getBuildingClassCountPlusMaking(int /*BuildingClassTypes*/ iIndex)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getBuildingClassCountPlusMaking(static_cast<BuildingClassTypes>(iIndex));
}
int CyPlayer::getHurryCount(int /*HurryTypes*/ eIndex)
{
	if (m_pPlayer == nullptr)
		return NO_HURRY;
	return m_pPlayer->getHurryCount(static_cast<HurryTypes>(eIndex));
}
bool CyPlayer::canHurry(int /*HurryTypes*/ eIndex)
{
	if (m_pPlayer == nullptr)
		return NO_HURRY;
	return m_pPlayer->canHurry(static_cast<HurryTypes>(eIndex), -1);
}
int CyPlayer::getSpecialBuildingNotRequiredCount(int /*SpecialBuildingTypes*/ eIndex)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getSpecialBuildingNotRequiredCount(static_cast<SpecialBuildingTypes>(eIndex));
}
bool CyPlayer::isSpecialBuildingNotRequired(int /*SpecialBuildingTypes*/ eIndex)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->isSpecialBuildingNotRequired(static_cast<SpecialBuildingTypes>(eIndex));
}
int CyPlayer::getBuildingYieldChange(int /*BuildingClassTypes*/ eBuildingClass, int /*YieldTypes*/ eYield)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getBuildingYieldChange(static_cast<BuildingClassTypes>(eBuildingClass), static_cast<YieldTypes>(eYield));
}
int /* CivicTypes */ CyPlayer::getCivic(int /*CivicOptionTypes*/ iIndex)
{
	if (m_pPlayer == nullptr)
		return NO_CIVIC;
	return static_cast<int>(m_pPlayer->getCivic(static_cast<CivicOptionTypes>(iIndex)));
}
void CyPlayer::setCivic(int /*CivicOptionTypes*/ eIndex, int /*CivicTypes*/ eNewValue)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->setCivic(static_cast<CivicOptionTypes>(eIndex), static_cast<CivicTypes>(eNewValue));
}
int CyPlayer::getCombatExperience() const
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getCombatExperience();
}
void CyPlayer::changeCombatExperience(int iChange)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->changeCombatExperience(iChange);
}
void CyPlayer::setCombatExperience(int iExperience)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->setCombatExperience(iExperience);
}

// R&R, ray, Great Admirals - START
int CyPlayer::getSeaCombatExperience() const
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getSeaCombatExperience();
}
void CyPlayer::changeSeaCombatExperience(int iChange)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->changeSeaCombatExperience(iChange);
}
void CyPlayer::setSeaCombatExperience(int iExperience)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->setSeaCombatExperience(iExperience);
}
// R&R, ray, Great Admirals - END

void CyPlayer::addCityName(std::wstring szName)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->addCityName(szName);
}
int CyPlayer::getNumCityNames()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getNumCityNames();
}
std::wstring CyPlayer::getCityName(int iIndex)
{
	if (m_pPlayer == nullptr)
		return std::wstring();
	return m_pPlayer->getCityName(iIndex);
}
// returns tuple of (CyCity, iterOut)
python::tuple CyPlayer::firstCity(bool bRev)
{
	int iterIn = 0;
	CvCity* pvObj = m_pPlayer ? m_pPlayer->firstCity(&iterIn, bRev) : nullptr;
	CyCity* pyObj = pvObj ? new CyCity(pvObj) : nullptr;
	python::tuple tup=python::make_tuple(pyObj, iterIn);
	delete pyObj;
	return tup;
}
// returns tuple of (CyCity, iterOut)
python::tuple CyPlayer::nextCity(int iterIn, bool bRev)
{
	CvCity* pvObj = m_pPlayer ? m_pPlayer->nextCity(&iterIn, bRev) : nullptr;
	CyCity* pyObj = pvObj ? new CyCity(pvObj) : nullptr;
	python::tuple tup=python::make_tuple(pyObj, iterIn);
	delete pyObj;
	return tup;
}
int CyPlayer::getNumCities()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getNumCities();
}
CyCity* CyPlayer::getCity(int iID)
{
	if (m_pPlayer == nullptr)
		return nullptr;
	return new CyCity(m_pPlayer->getCity(iID));
}
// returns tuple of (CyUnit, iterOut)
python::tuple CyPlayer::firstUnit()
{
	int iterIn = 0;
	CvUnit* pvUnit = m_pPlayer ? m_pPlayer->firstUnit(&iterIn) : nullptr;
	CyUnit* pyUnit = pvUnit ? new CyUnit(pvUnit) : nullptr;
	python::tuple tup=python::make_tuple(pyUnit, iterIn);
	delete pyUnit;
	return tup;
}
// returns tuple of (CyUnit, iterOut)
python::tuple CyPlayer::nextUnit(int iterIn)
{
	CvUnit* pvObj = m_pPlayer ? m_pPlayer->nextUnit(&iterIn) : nullptr;
	CyUnit* pyObj = pvObj ? new CyUnit(pvObj) : nullptr;
	python::tuple tup=python::make_tuple(pyObj, iterIn);
	delete pyObj;
	return tup;
}
int CyPlayer::getNumUnits()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getNumUnits();
}

// WTP, ray, easily counting Ships - START
int CyPlayer::getNumShips()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getNumShips();
}
// WTP, ray, easily counting Ships - END

CyUnit* CyPlayer::getUnit(int iID)
{
	if (m_pPlayer == nullptr)
		return nullptr;
	return new CyUnit(m_pPlayer->getUnit(iID));
}
int CyPlayer::getNumEuropeUnits()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getNumEuropeUnits();
}
CyUnit* CyPlayer::getEuropeUnit(int iIndex)
{
	if (m_pPlayer == nullptr)
		return nullptr;
	return new CyUnit(m_pPlayer->getEuropeUnit(iIndex));
}
CyUnit* CyPlayer::getEuropeUnitById(int iId)
{
	if (m_pPlayer == nullptr)
		return nullptr;
	return new CyUnit(m_pPlayer->getEuropeUnitById(iId));
}
void CyPlayer::loadUnitFromEurope(CyUnit* pUnit, CyUnit* pTransport)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->loadUnitFromEurope(pUnit->getUnit(), pTransport->getUnit());
}
void CyPlayer::unloadUnitToEurope(CyUnit* pUnit)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->unloadUnitToEurope(pUnit->getUnit());
}

// returns tuple of (CySelectionGroup, iterOut)
python::tuple CyPlayer::firstSelectionGroup(bool bRev)
{
	int iterIn = 0;
	CvSelectionGroup* pvObj = m_pPlayer ? m_pPlayer->firstSelectionGroup(&iterIn, bRev) : nullptr;
	CySelectionGroup* pyObj = pvObj ? new CySelectionGroup(pvObj) : nullptr;
	python::tuple tup=python::make_tuple(pyObj, iterIn);
	delete pyObj;
	return tup;
}
// returns tuple of (CySelectionGroup, iterOut)
python::tuple CyPlayer::nextSelectionGroup(int iterIn, bool bRev)
{
	CvSelectionGroup* pvObj = m_pPlayer ? m_pPlayer->nextSelectionGroup(&iterIn, bRev) : nullptr;
	CySelectionGroup* pyObj = pvObj ? new CySelectionGroup(pvObj) : nullptr;
	python::tuple tup=python::make_tuple(pyObj, iterIn);
	delete pyObj;
	return tup;
}
int CyPlayer::getNumSelectionGroups()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getNumSelectionGroups();
}
CySelectionGroup* CyPlayer::getSelectionGroup(int iID)
{
	if (m_pPlayer == nullptr)
		return nullptr;
	return new CySelectionGroup(m_pPlayer->getSelectionGroup(iID));
}
int CyPlayer::countNumTravelUnits(int /*UnitTravelStates*/ eState, int /*DomainTypes*/ eDomain)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->countNumTravelUnits(static_cast<UnitTravelStates>(eState), static_cast<DomainTypes>(eDomain));
}

void CyPlayer::trigger(/*EventTriggerTypes*/int eEventTrigger)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->trigger(static_cast<EventTriggerTypes>(eEventTrigger));
}
const EventTriggeredData* CyPlayer::getEventOccured(int /*EventTypes*/ eEvent) const
{
	if (m_pPlayer == nullptr)
		return nullptr;
	return m_pPlayer->getEventOccured(static_cast<EventTypes>(eEvent));
}
void CyPlayer::resetEventOccured(int /*EventTypes*/ eEvent)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->resetEventOccured(static_cast<EventTypes>(eEvent));
}
EventTriggeredData* CyPlayer::getEventTriggered(int iID) const
{
	if (m_pPlayer == nullptr)
		return nullptr;
	return m_pPlayer->getEventTriggered(iID);
}
EventTriggeredData* CyPlayer::initTriggeredData(int /*EventTriggerTypes*/ eEventTrigger, bool bFire, int iCityId, int iPlotX, int iPlotY, int /*PlayerTypes*/ eOtherPlayer, int iOtherPlayerCityId, int iUnitId, int /*BuildingTypes*/ eBuilding)
{
	if (m_pPlayer == nullptr)
		return nullptr;
	return m_pPlayer->initTriggeredData(static_cast<EventTriggerTypes>(eEventTrigger), bFire, iCityId, iPlotX, iPlotY, static_cast<PlayerTypes>(eOtherPlayer), iOtherPlayerCityId, iUnitId, static_cast<BuildingTypes>(eBuilding));
}
int CyPlayer::getEventTriggerWeight(int /*EventTriggerTypes*/ eTrigger)
{
	if (m_pPlayer == nullptr)
		return 0;
	return m_pPlayer->getEventTriggerWeight(static_cast<EventTriggerTypes>(eTrigger));
}
void CyPlayer::AI_updateFoundValues(bool bStartingLoc)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->AI_updateFoundValues(bStartingLoc);
}
int CyPlayer::AI_foundValue(int iX, int iY, int iMinUnitRange/* = -1*/, bool bStartingLoc/* = false*/)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->AI_foundValue(iX, iY, iMinUnitRange, bStartingLoc);
}
bool CyPlayer::AI_demandRebukedWar(int /*PlayerTypes*/ ePlayer)
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->AI_demandRebukedWar(static_cast<PlayerTypes>(ePlayer));
}
AttitudeTypes CyPlayer::AI_getAttitude(int /*PlayerTypes*/ ePlayer)
{
	if (m_pPlayer == nullptr)
		return NO_ATTITUDE;
	return m_pPlayer->AI_getAttitude(static_cast<PlayerTypes>(ePlayer));
}
// R&R, Robert Surcouf, No More Variables Hidden game option START
int CyPlayer::AI_getAttitudeVal(int /*PlayerTypes*/ ePlayer)
{
	if (m_pPlayer == nullptr)
		return 0;
	return m_pPlayer->AI_getAttitudeValue(static_cast<PlayerTypes>(ePlayer));
}
// R&R, Robert Surcouf, No More Variables Hidden game option END
int CyPlayer::AI_unitValue(int /*UnitTypes*/ eUnit, int /*UnitAITypes*/ eUnitAI, CyArea* pArea)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->AI_unitValue(static_cast<UnitTypes>(eUnit), static_cast<UnitAITypes>(eUnitAI), pArea->getArea());
}
int CyPlayer::AI_civicValue(int /*CivicTypes*/ eCivic)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->AI_civicValue(static_cast<CivicTypes>(eCivic));
}
int CyPlayer::AI_totalUnitAIs(int /*UnitAITypes*/ eUnitAI)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->AI_totalUnitAIs(static_cast<UnitAITypes>(eUnitAI));
}
int CyPlayer::AI_totalAreaUnitAIs(CyArea* pArea, int /*UnitAITypes*/ eUnitAI)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->AI_totalAreaUnitAIs(pArea->getArea(), static_cast<UnitAITypes>(eUnitAI));
}
int CyPlayer::AI_totalWaterAreaUnitAIs(CyArea* pArea, int /*UnitAITypes*/ eUnitAI)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->AI_totalWaterAreaUnitAIs(pArea->getArea(), static_cast<UnitAITypes>(eUnitAI));
}
int CyPlayer::AI_getNumAIUnits(int /*UnitAITypes*/ eIndex)
{
	if (m_pPlayer == nullptr)
		return NO_UNITAI;
	return m_pPlayer->AI_getNumAIUnits(static_cast<UnitAITypes>(eIndex));
}
int CyPlayer::AI_getAttitudeExtra(int /*PlayerTypes*/ eIndex)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->AI_getAttitudeExtra(static_cast<PlayerTypes>(eIndex));
}
void CyPlayer::AI_setAttitudeExtra(int /*PlayerTypes*/ eIndex, int iNewValue)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->AI_setAttitudeExtra(static_cast<PlayerTypes>(eIndex), iNewValue);
}
void CyPlayer::AI_changeAttitudeExtra(int /*PlayerTypes*/ eIndex, int iChange)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->AI_changeAttitudeExtra(static_cast<PlayerTypes>(eIndex), iChange);
}
int CyPlayer::AI_getMemoryCount(int /*PlayerTypes*/ eIndex1, int /*MemoryTypes*/ eIndex2)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->AI_getMemoryCount(static_cast<PlayerTypes>(eIndex1), static_cast<MemoryTypes>(eIndex2));
}
void CyPlayer::AI_changeMemoryCount(int /*PlayerTypes*/ eIndex1, int /*MemoryTypes*/ eIndex2, int iChange)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->AI_changeMemoryCount(static_cast<PlayerTypes>(eIndex1), static_cast<MemoryTypes>(eIndex2), iChange);
}
int CyPlayer::AI_getExtraGoldTarget() const
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->AI_getExtraGoldTarget();
}
void CyPlayer::AI_setExtraGoldTarget(int iNewValue)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->AI_setExtraGoldTarget(iNewValue);
}

int CyPlayer::getScoreHistory(int iTurn) const
{
	if (m_pPlayer == nullptr)
		return 0;
	return m_pPlayer->getScoreHistory(iTurn);
}
int CyPlayer::getEconomyHistory(int iTurn) const
{
	if (m_pPlayer == nullptr)
		return 0;
	return m_pPlayer->getEconomyHistory(iTurn);
}
int CyPlayer::getIndustryHistory(int iTurn) const
{
	if (m_pPlayer == nullptr)
		return 0;
	return m_pPlayer->getIndustryHistory(iTurn);
}
int CyPlayer::getAgricultureHistory(int iTurn) const
{
	if (m_pPlayer == nullptr)
		return 0;
	return m_pPlayer->getAgricultureHistory(iTurn);
}
int CyPlayer::getPowerHistory(int iTurn) const
{
	if (m_pPlayer == nullptr)
		return 0;
	return m_pPlayer->getPowerHistory(iTurn);
}
int CyPlayer::getCultureHistory(int iTurn) const
{
	if (m_pPlayer == nullptr)
		return 0;
	return m_pPlayer->getCultureHistory(iTurn);
}

int CyPlayer::addTradeRoute(int iSourceCityOwner, int iSourceCityId, int iDestinationCityOwner, int iDestinationCityId, int /*YieldTypes*/ eYield)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->addTradeRoute(IDInfo(static_cast<PlayerTypes>(iSourceCityOwner), iSourceCityId), IDInfo(static_cast<PlayerTypes>(iDestinationCityOwner), iDestinationCityId), static_cast<YieldTypes>(eYield));
}

bool CyPlayer::removeTradeRoute(int iId)
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->removeTradeRoute(iId);
}

CyTradeRoute* CyPlayer::getTradeRoute(int iId) const
{
	if (m_pPlayer == nullptr)
		return new CyTradeRoute(nullptr);
	return new CyTradeRoute(m_pPlayer->getTradeRoute(iId));
}

int CyPlayer::getNumTradeRoutes() const
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getNumTradeRoutes();
}

CyTradeRoute* CyPlayer::getTradeRouteByIndex(int iIndex) const
{
	if (m_pPlayer == nullptr)
		return new CyTradeRoute(nullptr);
	return new CyTradeRoute(m_pPlayer->getTradeRouteByIndex(iIndex));
}

bool CyPlayer::editTradeRoute(int iId, int iSourceCityOwner, int iSourceCityId, int iDestinationCityOwner, int iDestinationCityId, int /*YieldTypes*/ eYield)
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->editTradeRoute(iId, IDInfo(static_cast<PlayerTypes>(iSourceCityOwner), iSourceCityId), IDInfo(static_cast<PlayerTypes>(iDestinationCityOwner), iDestinationCityId), static_cast<YieldTypes>(eYield));
}

bool CyPlayer::canLoadYield(int /*PlayerTypes*/ eCityPlayer) const
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->canLoadYield(static_cast<PlayerTypes>(eCityPlayer));
}

bool CyPlayer::canUnloadYield(int /*PlayerTypes*/ eCityPlayer) const
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->canUnloadYield(static_cast<PlayerTypes>(eCityPlayer));
}

int CyPlayer::getYieldEquipmentAmount(int /*ProfessionTypes*/ eProfession, int /*YieldTypes*/ eYield)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getYieldEquipmentAmount(static_cast<ProfessionTypes>(eProfession), static_cast<YieldTypes>(eYield));
}

std::string CyPlayer::getScriptData() const
{
	if (m_pPlayer == nullptr)
		return std::string();
	return m_pPlayer->getScriptData();
}
void CyPlayer::setScriptData(std::string szNewValue)
{
	if (m_pPlayer)
		m_pPlayer->setScriptData(szNewValue);
}
int CyPlayer::AI_maxGoldTrade(int iPlayer)
{
	if (m_pPlayer == nullptr)
		return 0;
	CvPlayerAI* pPlayer = dynamic_cast<CvPlayerAI*>(m_pPlayer);
	return pPlayer->AI_maxGoldTrade(static_cast<PlayerTypes>(iPlayer));
}
void CyPlayer::forcePeace(int iPlayer)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->forcePeace(static_cast<PlayerTypes>(iPlayer));
}
int CyPlayer::getHighestTradedYield()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getHighestTradedYield();
}
int CyPlayer::getHighestStoredYieldCityId(int /*YieldTypes*/ eYield)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getHighestStoredYieldCityId(static_cast<YieldTypes>(eYield));
}
int CyPlayer::getCrossesStored()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getCrossesStored();
}
int CyPlayer::getBellsStored()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getBellsStored();
}
// R&R, Robert Surcouf, No More Variables Hidden game option START
int CyPlayer::getMissionaryPoints(int /*PlayerTypes*/ ePlayer) const
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getMissionaryPoints(static_cast<PlayerTypes>(ePlayer));
}
int CyPlayer::missionaryThreshold(int /*PlayerTypes*/ ePlayer) const
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->missionaryThreshold(static_cast<PlayerTypes>(ePlayer));
}
int CyPlayer::getMissionaryRateModifier() const
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getMissionaryRateModifier();
}
// R&R, Robert Surcouf, No More Variables Hidden game option END

//WTP, ray Kings Used Ship - START
int CyPlayer::getRandomUsedShipClassTypeID() const
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getRandomUsedShipClassTypeID();
}

int CyPlayer::getUsedShipPrice(int /*UnitClassTypes*/ iUsedShipClassType) const
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getUsedShipPrice(static_cast<UnitClassTypes>(iUsedShipClassType));
}

bool CyPlayer::isKingWillingToTradeUsedShips() const
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->isKingWillingToTradeUsedShips();
}

void CyPlayer::resetCounterForUsedShipDeals()
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->resetCounterForUsedShipDeals();
}
//WTP, ray Kings Used Ship - END


// WTP, ray, Foreign Kings, buy Immigrants - START
int /*UnitClassTypes*/ CyPlayer::getRandomForeignImmigrantClassTypeID(int iKingID) const
{
	if (m_pPlayer == nullptr)
		return static_cast<int>(NO_UNITCLASS);
	return static_cast<int>(m_pPlayer->getRandomForeignImmigrantClassTypeID(iKingID));
}

int CyPlayer::getForeignImmigrantPrice(int /*UnitClassTypes*/ iForeignImmigrantClassType, int iEuropeKingID) const
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getForeignImmigrantPrice(static_cast<UnitClassTypes>(iForeignImmigrantClassType), iEuropeKingID);
}

bool CyPlayer::isForeignKingWillingToTradeImmigrants(int iEuropeKingID) const
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->isForeignKingWillingToTradeImmigrants(iEuropeKingID);
}

void CyPlayer::resetCounterForForeignImmigrantsDeals()
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->resetCounterForForeignImmigrantsDeals();
}
// WTP, ray, Foreign Kings, buy Immigrants - END

// R&R, ray, Church Favours - START
int CyPlayer::getChurchFavourPrice() const
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getChurchFavourPrice();
}
// R&R, ray, Church Favours - END

/** NBMOD TAX **/
int CyPlayer::NBMOD_GetMaxTaxRate() const
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->NBMOD_GetMaxTaxRate();
}
/** NBMOD TAX **/

// R&R, ray, Bargaining - Start
bool CyPlayer::tryGetNewBargainPriceSell()
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->tryGetNewBargainPriceSell();
}

bool CyPlayer::tryGetNewBargainPriceBuy()
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->tryGetNewBargainPriceBuy();
}
// R&R, ray, Bargaining - End

// TAC - Python Export - Ray - START
void CyPlayer::NBMOD_IncreaseMaxTaxRate()
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->NBMOD_IncreaseMaxTaxRate();
}

void CyPlayer::NBMOD_DecreaseMaxTaxRate()
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->NBMOD_DecreaseMaxTaxRate();
}
// TAC - Python Export - Ray - END


int CyPlayer::getTaxRate()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getTaxRate();
}
void CyPlayer::changeTaxRate(int iChange)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->changeTaxRate(iChange);
}
bool CyPlayer::canTradeWithEurope()
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->canTradeWithEurope();
}
int CyPlayer::getSellToEuropeProfit(int /*YieldTypes*/ eYield, int iAmount)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getSellToEuropeProfit(static_cast<YieldTypes>(eYield), iAmount);
}
int CyPlayer::getYieldSellPrice(int /*YieldTypes*/ eYield)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getYieldSellPrice(static_cast<YieldTypes>(eYield));
}
int CyPlayer::getYieldBuyPrice(int /*YieldTypes*/ eYield)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getYieldBuyPrice(static_cast<YieldTypes>(eYield));
}
void CyPlayer::setYieldBuyPrice(int /*YieldTypes*/ eYield, int iPrice, bool bMessage)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->setYieldBuyPrice(static_cast<YieldTypes>(eYield), iPrice, bMessage);
}
// R&R, ray, Africa
int CyPlayer::getYieldAfricaSellPrice(int /*YieldTypes*/ eYield)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getYieldAfricaSellPrice(static_cast<YieldTypes>(eYield));
}
int CyPlayer::getYieldAfricaBuyPrice(int /*YieldTypes*/ eYield)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getYieldAfricaBuyPrice(static_cast<YieldTypes>(eYield));
}
int CyPlayer::getYieldAfricaBuyPriceNoModifier(int /*YieldTypes*/ eYield)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getYieldAfricaBuyPriceNoModifier(static_cast<YieldTypes>(eYield));
}

void CyPlayer::setYieldAfricaBuyPrice(int /*YieldTypes*/ eYield, int iPrice, bool bMessage)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->setYieldAfricaBuyPrice(static_cast<YieldTypes>(eYield), iPrice, bMessage);
}
CyUnit* CyPlayer::buyYieldUnitFromAfrica(int /*YieldTypes*/ eYield, int iAmount, CyUnit* pTransport)
{
	if (m_pPlayer == nullptr)
		return nullptr;
	return (new CyUnit(m_pPlayer->buyYieldUnitFromAfrica(static_cast<YieldTypes>(eYield), iAmount, pTransport->getUnit())));
}
// R&R, ray, Africa - END
// R&R, ray, Port Royal
int CyPlayer::getYieldPortRoyalSellPrice(int /*YieldTypes*/ eYield)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getYieldPortRoyalSellPrice(static_cast<YieldTypes>(eYield));
}
int CyPlayer::getYieldPortRoyalBuyPrice(int /*YieldTypes*/ eYield)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getYieldPortRoyalBuyPrice(static_cast<YieldTypes>(eYield));
}
int CyPlayer::getYieldPortRoyalBuyPriceNoModifier(int /*YieldTypes*/ eYield)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getYieldPortRoyalBuyPriceNoModifier(static_cast<YieldTypes>(eYield));
}
void CyPlayer::setYieldPortRoyalBuyPrice(int /*YieldTypes*/ eYield, int iPrice, bool bMessage)
{
	if (m_pPlayer)
		m_pPlayer->setYieldPortRoyalBuyPrice(static_cast<YieldTypes>(eYield), iPrice, bMessage);
}
CyUnit* CyPlayer::buyYieldUnitFromPortRoyal(int /*YieldTypes*/ eYield, int iAmount, CyUnit* pTransport)
{
	if (m_pPlayer == nullptr)
		return nullptr;
	return (new CyUnit(m_pPlayer->buyYieldUnitFromPortRoyal(static_cast<YieldTypes>(eYield), iAmount, pTransport->getUnit())));
}
// R&R, ray, Port Royal - END
void CyPlayer::sellYieldUnitToEurope(CyUnit* pUnit, int iAmount, int iCommission)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->sellYieldUnitToEurope(pUnit->getUnit(), iAmount, iCommission);
}
CyUnit* CyPlayer::buyYieldUnitFromEurope(int /*YieldTypes*/ eYield, int iAmount, CyUnit* pTransport)
{
	if (m_pPlayer == nullptr)
		return nullptr;
	return (new CyUnit(m_pPlayer->buyYieldUnitFromEurope(static_cast<YieldTypes>(eYield), iAmount, pTransport->getUnit())));
}
int CyPlayer::getEuropeUnitBuyPrice(int /*UnitTypes*/ eUnit)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getEuropeUnitBuyPrice(static_cast<UnitTypes>(eUnit));
}
CyUnit* CyPlayer::buyEuropeUnit(int /*UnitTypes*/ eUnit)
{
	if (m_pPlayer == nullptr)
		return nullptr;
	return (new CyUnit(m_pPlayer->buyEuropeUnit(static_cast<UnitTypes>(eUnit), 100)));
}
int CyPlayer::getYieldBoughtTotal(int /*YieldTypes*/ eYield) const
{
	if (m_pPlayer == nullptr)
		return 0;
	return m_pPlayer->getYieldBoughtTotal(static_cast<YieldTypes>(eYield));
}

// WTP, ray, Yields Traded Total for Africa and Port Royal - START
int CyPlayer::getYieldBoughtTotalAfrica(int /*YieldTypes*/ eYield) const
{
	if (m_pPlayer == nullptr)
		return 0;
	return m_pPlayer->getYieldBoughtTotalAfrica(static_cast<YieldTypes>(eYield));
}
int CyPlayer::getYieldBoughtTotalPortRoyal(int /*YieldTypes*/ eYield) const
{
	if (m_pPlayer == nullptr)
		return 0;
	return m_pPlayer->getYieldBoughtTotalPortRoyal(static_cast<YieldTypes>(eYield));
}
// WTP, ray, Yields Traded Total for Africa and Port Royal - END

int CyPlayer::getNumRevolutionEuropeUnits() const
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getNumRevolutionEuropeUnits();
}
int /*UnitTypes*/ CyPlayer::getRevolutionEuropeUnit(int iIndex) const
{
	if (m_pPlayer == nullptr)
		return static_cast<int>(NO_UNIT);
	return static_cast<int>(m_pPlayer->getRevolutionEuropeUnit(iIndex));
}
int /*ProfessionTypes*/ CyPlayer::getRevolutionEuropeProfession(int iIndex) const
{
	if (m_pPlayer == nullptr)
		return static_cast<int>(NO_PROFESSION);
	return static_cast<int>(m_pPlayer->getRevolutionEuropeProfession(iIndex));
}
bool CyPlayer::isEurope() const
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->isEurope();
}
bool CyPlayer::isInRevolution() const
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->isInRevolution();
}
int /*UnitTypes*/ CyPlayer::getDocksNextUnit(int iIndex) const
{
	if (m_pPlayer == nullptr)
		return static_cast<int>(NO_UNIT);
	if (iIndex < 0 || iIndex >= static_cast<int>(m_pPlayer->CivEffect().getNumUnitsOnDock()))
		return static_cast<int>(NO_UNIT);
	return static_cast<int>(m_pPlayer->getDocksNextUnit(iIndex));
}
void CyPlayer::addRevolutionEuropeUnit(int /*UnitTypes*/ eUnit, int /*ProfessionTypes*/ eProfession)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->addRevolutionEuropeUnit(static_cast<UnitTypes>(eUnit), static_cast<ProfessionTypes>(eProfession));
}
int CyPlayer::getNumTradeMessages() const
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getNumTradeMessages();
}
std::wstring CyPlayer::getTradeMessage(int i) const
{
	if (m_pPlayer == nullptr)
		return std::wstring();
	return m_pPlayer->getTradeMessage(i);
}

// TAC - Trade Messages - koma13 - START
int /*TradeMessageTypes*/ CyPlayer::getTradeMessageType(int i) const
{
	if (m_pPlayer == nullptr)
		return static_cast<int>(NO_TRADE_MESSAGE);
	return static_cast<int>(m_pPlayer->getTradeMessageType(i));
}
int /*YieldTypes*/ CyPlayer::getTradeMessageYield(int i) const
{
	if (m_pPlayer == nullptr)
		return static_cast<int>(NO_YIELD);
	return static_cast<int>(m_pPlayer->getTradeMessageYield(i));
}
int CyPlayer::getTradeMessageAmount(int i) const
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getTradeMessageAmount(i);
}
int CyPlayer::getTradeMessageCommission(int i) const
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getTradeMessageCommission(i);
}
// TAC - Trade Messages - koma13 - END

// PatchMod: Achievements START
bool CyPlayer::isAchieveGained(int /*AchieveTypes*/ eAchieve)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->isAchieveGained(static_cast<AchieveTypes>(eAchieve));
}

int CyPlayer::getAchieveYear(int /*AchieveTypes*/ eAchieve)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getAchieveYear(static_cast<AchieveTypes>(eAchieve));
}
// PatchMod: Achievements END
// TAC - TAC Interface - koma13 - START
void CyPlayer::toggleMultiRowPlotList()
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->toggleMultiRowPlotList();
}
// TAC - TAC Interface - koma13 - END

/*** TRIANGLETRADE 10/15/08 by DPII ***/
int CyPlayer::getNumAfricaUnits()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getNumAfricaUnits();
}
CyUnit* CyPlayer::getAfricaUnit(int iIndex)
{
	if (m_pPlayer == nullptr)
		return nullptr;
	return new CyUnit(m_pPlayer->getAfricaUnit(iIndex));
}
CyUnit* CyPlayer::getAfricaUnitById(int iId)
{
	if (m_pPlayer == nullptr)
		return nullptr;
	return new CyUnit(m_pPlayer->getAfricaUnitById(iId));
}
void CyPlayer::loadUnitFromAfrica(CyUnit* pUnit, CyUnit* pTransport)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->loadUnitFromAfrica(pUnit->getUnit(), pTransport->getUnit());
}
void CyPlayer::unloadUnitToAfrica(CyUnit* pUnit)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->unloadUnitToAfrica(pUnit->getUnit());
}
int CyPlayer::getAfricaUnitBuyPrice(int /*UnitTypes*/ eUnit)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getAfricaUnitBuyPrice(static_cast<UnitTypes>(eUnit));
}
CyUnit* CyPlayer::buyAfricaUnit(int /*UnitTypes*/ eUnit)
{
	if (m_pPlayer == nullptr)
		return nullptr;
	return (new CyUnit(m_pPlayer->buyAfricaUnit(static_cast<UnitTypes>(eUnit), 100)));
}
bool CyPlayer::canTradeWithAfrica()
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->canTradeWithAfrica();
}
int CyPlayer::getSellToAfricaProfit(int /*YieldTypes*/ eYield, int iAmount)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getSellToAfricaProfit(static_cast<YieldTypes>(eYield), iAmount);
}
bool CyPlayer::isYieldAfricaTradable(int /*YieldTypes*/ eIndex)
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->isYieldAfricaTradable(static_cast<YieldTypes>(eIndex));
}

//WTP, ray, Colonial Intervention In Native War - START
int CyPlayer::getIDSecondPlayerFrenchNativeWar()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getIDSecondPlayerFrenchNativeWar();
}
//WTP, ray, Colonial Intervention In Native War - END

/**************************************/

// R&R, ray, Port Royal
int CyPlayer::getNumPortRoyalUnits()
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getNumPortRoyalUnits();
}
CyUnit* CyPlayer::getPortRoyalUnit(int iIndex)
{
	if (m_pPlayer == nullptr)
		return nullptr;
	return new CyUnit(m_pPlayer->getPortRoyalUnit(iIndex));
}
CyUnit* CyPlayer::getPortRoyalUnitById(int iId)
{
	if (m_pPlayer == nullptr)
		return nullptr;
	return new CyUnit(m_pPlayer->getPortRoyalUnitById(iId));
}
void CyPlayer::loadUnitFromPortRoyal(CyUnit* pUnit, CyUnit* pTransport)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->loadUnitFromPortRoyal(pUnit->getUnit(), pTransport->getUnit());
}
void CyPlayer::unloadUnitToPortRoyal(CyUnit* pUnit)
{
	if (m_pPlayer == nullptr)
		return;
	m_pPlayer->unloadUnitToPortRoyal(pUnit->getUnit());
}
int CyPlayer::getPortRoyalUnitBuyPrice(int /*UnitTypes*/ eUnit)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getPortRoyalUnitBuyPrice(static_cast<UnitTypes>(eUnit));
}
CyUnit* CyPlayer::buyPortRoyalUnit(int /*UnitTypes*/ eUnit)
{
	if (m_pPlayer == nullptr)
		return nullptr;
	return (new CyUnit(m_pPlayer->buyPortRoyalUnit(static_cast<UnitTypes>(eUnit), 100)));
}
bool CyPlayer::canTradeWithPortRoyal()
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->canTradeWithPortRoyal();
}
int CyPlayer::getSellToPortRoyalProfit(int /*YieldTypes*/ eYield, int iAmount)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_pPlayer->getSellToPortRoyalProfit(static_cast<YieldTypes>(eYield), iAmount);
}
bool CyPlayer::isYieldPortRoyalTradable(int /*YieldTypes*/ eIndex)
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->isYieldPortRoyalTradable(static_cast<YieldTypes>(eIndex));
}
/**************************************/
// R&R mod, vetiarvind, trade groups - start
int CyPlayer::getLoadedTradeGroup()
{
	return m_loadedTradeGroup;
}

void CyPlayer::setLoadedTradeGroup(int iId)
{
	m_loadedTradeGroup = iId;
}

int CyPlayer::getLastUpdatedTradeGroup()
{
	return m_lastUpdatedTradegroup;
}

int CyPlayer::addTradeRouteGroup(const std::wstring groupName)
{
	if (m_pPlayer == nullptr)
		return -1;
	return m_lastUpdatedTradegroup = m_pPlayer->addTradeRouteGroup(groupName);
}
bool CyPlayer::editTradeRouteGroup(int iId, const std::wstring groupName)
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->editTradeRouteGroup(iId, groupName);
}
bool CyPlayer::removeTradeRouteGroup(int iId)
{
	if (m_pPlayer == nullptr)
		return false;
	return m_pPlayer->removeTradeRouteGroup(iId);
}

int CyPlayer::getNumTradeGroups() const
{
	if (m_pPlayer == nullptr)
		return 0;
	return m_pPlayer->getNumTradeGroups();
}
CyTradeRouteGroup* CyPlayer::getTradeGroup(int iIndex)
{
	if (m_pPlayer == nullptr)
		return nullptr;
	return new CyTradeRouteGroup(m_pPlayer->getTradeRouteGroup(iIndex));
}

// R&R mod, vetiarvind, trade groups - end

CyInfoArray* CyPlayer::getSpecialBuildingTypes() const
{
	// Currently a bit pointless, but here there is a single location to alter all of the python code using this should we need to update.

	EnumMap<SpecialBuildingTypes, bool, true> em;

	return new CyInfoArray(em);
}

CyInfoArray* CyPlayer::getStoredYieldTypes() const
{
	// Currently a bit pointless, but here there is a single location to alter all of the python code using this should we need to update.

	EnumMap<YieldTypes, bool, true> em;

	for (YieldTypes eYield = em.FIRST; eYield <= em.LAST; ++eYield)
	{
		if (eYield >= NUM_CARGO_YIELD_TYPES // only show cargo yields
			|| (m_pPlayer && !m_pPlayer->CivEffect().canUseYield(eYield))) // remove yields not used by the player
		{
			em.set(eYield, false);
		}
	}

	return new CyInfoArray(em);
}

CyInfoArray* CyPlayer::getDomesticDemandYieldTypes() const
{
	EnumMap<YieldTypes, bool> em;

	const InfoArray<YieldTypes>& array = GC.getDomesticDemandYieldTypes();

	for (int i = 0; i < array.getLength(); ++i)
	{
		const YieldTypes eYield = array.get(i);
		if (!m_pPlayer || m_pPlayer->CivEffect().canUseYield(eYield))
		{
			em.set(eYield, true);
		}
	}

	return new CyInfoArray(em);
}

CyInfoArray* CyPlayer::getTeachUnitTypes(int iTeachLevel) const
{
	EnumMap<UnitTypes, bool> em;

	if (m_pPlayer != nullptr)
	{
		const CvPlayerCivEffect& kPlayer = m_pPlayer->CivEffect();
		for (UnitTypes eUnit = em.FIRST; eUnit <= em.LAST; ++eUnit)
		{
			if (kPlayer.canUseUnit(eUnit) && GC.getUnitInfo(eUnit).NBMOD_GetTeachLevel() == iTeachLevel)
			{
				em.set(eUnit, true);
			}

		}
	}
	return new CyInfoArray(em);
}

int CyPlayer::getMaxTeachLevel() const
{
	int iLevel = 0;
	if (m_pPlayer != nullptr)
	{
		const CvPlayerCivEffect& kPlayer = m_pPlayer->CivEffect();
		for (UnitTypes eUnit = FIRST_UNIT; eUnit < NUM_UNIT_TYPES; ++eUnit)
		{
			if (kPlayer.canUseUnit(eUnit))
			{
				const int iUnitLevel = GC.getUnitInfo(eUnit).NBMOD_GetTeachLevel();
				if (iUnitLevel > iLevel && iUnitLevel < 100)
				{
					iLevel = iUnitLevel;
				}
			}
		}
	}
	return iLevel;
}

// CivEffect
int CyPlayer::getCivEffectCount(CivEffectTypes eCivEffect) const
{
	if (m_pPlayer == nullptr)
		return 0;
	return m_pPlayer->CivEffect().getCivEffectCount(eCivEffect);
}


unsigned int CyPlayer::getNumUnitsOnDock() const
{
	if (m_pPlayer == nullptr)
		return 0;
	return m_pPlayer->CivEffect().getNumUnitsOnDock();
}
