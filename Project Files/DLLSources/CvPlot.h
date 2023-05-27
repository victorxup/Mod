#pragma once

// CvPlot.h

#ifndef CIV4_PLOT_H
#define CIV4_PLOT_H

//#include "CvStructs.h"
#include "LinkedList.h"
#include <bitset>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_enum.hpp>

#include "CvPlotFunctions.h"

#pragma warning( disable: 4251 )		// needs to have dll-interface to be used by clients of class

class CvArea;
class CvMap;
class CvPlotBuilder;
class CvRoute;
class CvRiver;
class CvCity;
class CvFeature;
class CvUnit;
class CvSymbol;
class CvFlagEntity;

typedef bool (*ConstPlotUnitFunc)( const CvUnit* pUnit, int iData1, int iData2);
typedef bool (*PlotUnitFunc)(CvUnit* pUnit, int iData1, int iData2);

class CvPlot
{

public:
	CvPlot();
	virtual ~CvPlot();

	friend void postLoadGameFixes();

	void init(int iX, int iY);
	void uninit();
	void reset(int iX = 0, int iY = 0, bool bConstructorCall=false);
	void setupGraphical();
	void erase();

	__declspec(dllexport) float getPointX() const;
	__declspec(dllexport) float getPointY() const;
	__declspec(dllexport) NiPoint3 getPoint() const;

	__declspec(dllexport) TeamTypes getTeam() const;

	void doTurn();

	void doImprovement();

	void updateCulture(bool bBumpUnits);

	void updateFog();
	void updateVisibility();

	void updateSymbolDisplay();
	void updateSymbolVisibility();
	void updateSymbols();

	void updateMinimapColor();

	void updateCenterUnit();

	void verifyUnitValidPlot();

    bool isAdjacentToPlot(CvPlot* pPlot) const;
	bool isAdjacentToArea(int iAreaID) const;
	bool isAdjacentToArea(const CvArea* pArea) const;
	bool shareAdjacentArea( const CvPlot* pPlot) const;
	bool isAdjacentToLand() const;
	bool isCoastalLand(int iMinWaterSize = -1) const;
	bool hasDeepWaterCoast() const;
	bool hasOtherAdjacentOceanOrDeepWaterCoast() const; //WTP, ray, Safety Check for Deep Water Coast if there is Ocean or Deep Coast adjacent - START
	bool isAdjacentWaterPassable(CvPlot* pPlot) const;

	bool isVisibleWorked() const;
	bool isWithinTeamCityRadius(TeamTypes eTeam, PlayerTypes eIgnorePlayer = NO_PLAYER) const;

	__declspec(dllexport) bool isLake() const;

	bool isRiverMask() const;
	__declspec(dllexport) bool isRiverCrossingFlowClockwise(DirectionTypes eDirection) const;
	bool isRiverSide() const;
	bool isRiver() const;
	bool isFreshWater() const; // WTP, ray, Health Overhaul
	bool isRiverConnection(DirectionTypes eDirection) const;

	CvPlot* getNearestLandPlotInternal(int iDistance) const;
	int getNearestLandArea() const;
	CvPlot* getNearestLandPlot() const;

	int seeFromLevel() const;
	int seeThroughLevel() const;
	int getPlotVisibility() const;
	int getUnitVisibilityBonus() const;
	void changeAdjacentSight(TeamTypes eTeam, int iRange, bool bIncrement, CvUnit* pUnit);
	bool canSeePlot(const CvPlot *plot, TeamTypes eTeam, int iRange, DirectionTypes eFacingDirection) const;
	bool canSeeDisplacementPlot(TeamTypes eTeam, int dx, int dy, int originalDX, int originalDY, bool firstPlot, bool outerRing) const;
	bool shouldProcessDisplacementPlot(int dx, int dy, DirectionTypes eFacingDirection) const;
	void updateSight(bool bIncrement);
	void updateSeeFromSight(bool bIncrement);
	bool canHaveBonus(BonusTypes eBonus, bool bIgnoreLatitude = false) const;
	//bool canHaveImprovement(ImprovementTypes eImprovement, TeamTypes eTeam = NO_TEAM, bool bPotential = false) const;
	bool canHaveImprovement(ImprovementTypes eImprovement, TeamTypes eTeam = NO_TEAM, bool bPotential = false, bool bIgnoreFeature = false) const; // build feature removal detection - Nightinggale

	bool canBuild(BuildTypes eBuild, PlayerTypes ePlayer = NO_PLAYER, bool bTestVisible = false) const;
	int getBuildTime(BuildTypes eBuild) const;
	int getBuildTurnsLeft(BuildTypes eBuild, int iNowExtra, int iThenExtra) const;
	int getFeatureYield(BuildTypes eBuild, YieldTypes eYield, TeamTypes eTeam, CvCity** ppCity) const;

	CvUnit* getBestDefender(PlayerTypes eOwner, PlayerTypes eAttackingPlayer = NO_PLAYER, const CvUnit* pAttacker = nullptr, bool bTestAtWar = false, bool bTestPotentialEnemy = false, bool bTestCanMove = false) const;
	bool hasDefender(bool bCheckCanAttack, PlayerTypes eOwner, PlayerTypes eAttackingPlayer = NO_PLAYER, const CvUnit* pAttacker = nullptr, bool bTestAtWar = false, bool bTestPotentialEnemy = false, bool bTestCanMove = false) const;
	int AI_sumStrength(PlayerTypes eOwner, PlayerTypes eAttackingPlayer = NO_PLAYER, DomainTypes eDomainType = NO_DOMAIN, bool bDefensiveBonuses = true, bool bTestAtWar = false, bool bTestPotentialEnemy = false) const;
	CvUnit* getSelectedUnit() const;
	int getUnitPower(PlayerTypes eOwner = NO_PLAYER) const;

	// Super Forts begin *bombard*
	bool isBombardable(const CvUnit* pUnit) const;
	bool isBombarded() const;
	void setBombarded(bool bNewValue);
	int getDefenseDamage() const;
	void changeDefenseDamage(int iChange);
	// Super Forts end
	// Super Forts begin *culture*
	int getCultureRangeForts(PlayerTypes ePlayer) const;
	void setCultureRangeForts(PlayerTypes ePlayer, int iNewValue);
	void changeCultureRangeForts(PlayerTypes ePlayer, int iChange);
	bool isWithinFortCultureRange(PlayerTypes ePlayer) const;
	void changeCultureRangeFortsWithinRange(PlayerTypes ePlayer, int iChange, int iRange, bool bUpdate);
	void doImprovementCulture();
	// Super Forts end
	// Super Forts begin *canal* *choke*
	//int countRegionPlots(const CvPlot* pInvalidPlot = nullptr) const; //R&R mod, vetiarvind super forts merge, don't count region plots
	int countAdjacentPassableSections(bool bWater) const;
	int countImpassableCardinalDirections() const;
	int getCanalValue() const;
	void setCanalValue(int iNewValue);
	void calculateCanalValue();
	int getChokeValue() const;
	void setChokeValue(int iNewValue);
	void calculateChokeValue();
	// Super Forts end

	int defenseModifier(TeamTypes eDefender, bool bHelp = false) const;
	int movementCost(const CvUnit* pUnit, const CvPlot* pFromPlot,														// Exposed to Python
		bool bAssumeRevealed = false) const; // advc.001i, WTP: default is false rather than true

	bool isAdjacentOwned() const;
	bool isAdjacentPlayer(PlayerTypes ePlayer, bool bLandOnly = false) const;
	bool isAdjacentTeam(TeamTypes eTeam, bool bLandOnly = false) const;
	bool isWithinCultureRange(PlayerTypes ePlayer) const;
	int getNumCultureRangeCities(PlayerTypes ePlayer) const;

	PlayerTypes calculateCulturalOwner() const;
	void plotAction(PlotUnitFunc func, int iData1 = -1, int iData2 = -1, PlayerTypes eOwner = NO_PLAYER, TeamTypes eTeam = NO_TEAM);
	__declspec(dllexport) int plotCount(ConstPlotUnitFunc funcA, int iData1A = -1, int iData2A = -1, PlayerTypes eOwner = NO_PLAYER, TeamTypes eTeam = NO_TEAM, ConstPlotUnitFunc funcB = nullptr, int iData1B = -1, int iData2B = -1) const;
	CvUnit* plotCheck(ConstPlotUnitFunc funcA, int iData1A = -1, int iData2A = -1, PlayerTypes eOwner = NO_PLAYER, TeamTypes eTeam = NO_TEAM, ConstPlotUnitFunc funcB = nullptr, int iData1B = -1, int iData2B = -1) const;
	bool isOwned() const;

	bool isVisible(TeamTypes eTeam, bool bDebug) const;
	__declspec(dllexport) bool isActiveVisible(bool bDebug) const;
	bool isVisibleToCivTeam() const;
	bool isVisibleToWatchingHuman() const;
	bool isAdjacentVisible(TeamTypes eTeam, bool bDebug) const;
	bool isAdjacentNonvisible(TeamTypes eTeam) const;

	__declspec(dllexport) bool isGoody(TeamTypes eTeam = NO_TEAM) const;
	bool isGoodyForSpawningUnits(TeamTypes eTeam = NO_TEAM) const; //WTP, Unit only Goodies
	bool isGoodyForSpawningHostileAnimals(TeamTypes eTeam = NO_TEAM) const; //WTP, Protected Hostile Goodies
	bool isGoodyForSpawningHostileNatives(TeamTypes eTeam = NO_TEAM) const; //WTP, Protected Hostile Goodies
	bool isGoodyForSpawningHostileCriminals(TeamTypes eTeam = NO_TEAM) const; //WTP, Protected Hostile Goodies

	bool isRevealedGoody(TeamTypes eTeam = NO_TEAM) const;
	void removeGoody();

	__declspec(dllexport) bool isCity(bool bCheckImprovement = false, TeamTypes eForTeam = NO_TEAM) const;
	bool isFriendlyCity(const CvUnit& kUnit, bool bCheckImprovement) const;
	bool isEnemyCity(const CvUnit& kUnit) const;

	// R&R, ray, Monasteries and Forts - START
	bool isFort() const;
	bool isMonastery() const;
	bool isCanal() const;
	// R&R, ray, Monasteries and Forts - END

	//R&R mod, vetiarvind, super forts merge, refactor checks for activating monastery and forts - start
	CvUnit* getFortDefender();
	CvUnit* getMonasteryMissionary();
	//R&R mod, vetiarvind, super forts merge, refactor checks for activating monastery and forts - end

	bool isOccupation() const;
	bool isBeingWorked() const;

	bool isUnit() const;
	bool isVisibleEnemyDefender(const CvUnit* pUnit) const;
	CvUnit *getVisibleEnemyDefender(PlayerTypes ePlayer) const;
	int getNumDefenders(PlayerTypes ePlayer) const;
	int getNumVisibleEnemyDefenders(const CvUnit* pUnit) const;
	int getNumVisiblePotentialEnemyDefenders(const CvUnit* pUnit) const;
	__declspec(dllexport) bool isVisibleEnemyUnit(PlayerTypes ePlayer) const;
	bool isVisibleEnemyUnit(const CvUnit* pUnit) const;
	bool isVisibleOtherUnit(PlayerTypes ePlayer) const;
	__declspec(dllexport) bool isFighting() const;

	bool canHaveFeature(FeatureTypes eFeature) const;

	__declspec(dllexport) bool isRoute() const;
	bool isValidRoute(const CvUnit* pUnit) const;
	bool isValidDomainForLocation(const CvUnit& unit) const;
	bool isValidDomainForAction(const CvUnit& unit) const;
	bool isValidDomainForAction(UnitTypes eUnit) const;
	bool isImpassable() const;

	__declspec(dllexport) int getX() const;
	inline int getX_INLINE() const
	{
		// return m_iX;
		return m_coord.x();
	}

	__declspec(dllexport) int getY() const;
	inline int getY_INLINE() const
	{
		// return m_iY;
		return m_coord.y();
	}

	inline const Coordinates& coord() const
	{
		return m_coord;
	}
	bool at(int iX, int iY) const;
	bool at(Coordinates coord) const;
	int getIndex() const;
	int getLatitude() const;
	int getSignedLatitude() const; //ray, Norther and Southern Hemisphere, using hint of f1rpo
	bool isSouthernHemisphere() const; //ray, Norther and Southern Hemisphere, using hint of f1rpo
	bool isNorthernHemisphere() const; //ray, Norther and Southern Hemisphere, using hint of f1rpo
	int getFOWIndex() const;
	CvArea* area() const;
	CvArea* waterArea() const;
	CvArea* secondWaterArea() const;
	int getArea() const;
	// <advc>
	//inline CvArea& getArea() const { return *m_pArea; }
	// (This had called CvMap::getArea in BtS)
	//	inline CvArea* area() const { return m_pArea; }													// Exposed to Python
	inline bool isArea(CvArea const& kArea) const { return (area() == &kArea); }
	//inline bool sameArea(CvPlot const& kPlot) const { return isArea(kPlot.getArea()); }
	void setArea(int iNewValue);

	//WTP, ray, Large Rivers - Nightinggale addition - start
	CvArea* area(DomainTypes eDomain) const;
	int getArea(DomainTypes eDomain) const;
	const CvPlot* getAdjacentLandPlot(bool bReturnSelfFallback) const;
	CvPlot* getAdjacentLandPlot(bool bReturnSelfFallback);
	CvArea* CvPlot::getAdjacentSeaArea() const;
	//WTP, ray, Large Rivers - Nightinggale addition - end

	//WTP, Nightinggale - Terrain locator - start
	template <typename T>
	bool hasNearbyPlotWith(const InfoArray1<T>& kInfo, int iRange = 1, bool bEmptyReturnVal = true) const;

	// function to avoid using an InfoArray, though it only works when searching for a single value
	// use InfoArray if searching for multiple as it will be faster
	template <typename T>
	typename boost::enable_if<boost::is_enum<T>, bool>::type
	hasNearbyPlotWith(T eVal, int iRange = 1) const;
	//WTP, Nightinggale - Terrain locator - start

	__declspec(dllexport) int getFeatureVariety() const;

	int getOwnershipDuration() const;
	bool isOwnershipScore() const;
	void setOwnershipDuration(int iNewValue);
	void changeOwnershipDuration(int iChange);

	int getImprovementDuration() const;
	void setImprovementDuration(int iNewValue);
	void changeImprovementDuration(int iChange);

	int getUpgradeProgress() const;
	int getUpgradeTimeLeft(ImprovementTypes eImprovement, PlayerTypes ePlayer) const;
	void setUpgradeProgress(int iNewValue);
	void changeUpgradeProgress(int iChange);

	int getForceUnownedTimer() const;
	bool isForceUnowned() const;
	void setForceUnownedTimer(int iNewValue);
	void changeForceUnownedTimer(int iChange);

	int getCityRadiusCount() const;
	int isCityRadius() const;
	void changeCityRadiusCount(int iChange);
	bool isStartingPlot() const;
	void setStartingPlot(bool bNewValue);

	__declspec(dllexport) bool isNOfRiver() const;
	void setNOfRiver(bool bNewValue, CardinalDirectionTypes eRiverDir);

	__declspec(dllexport) bool isWOfRiver() const;
	void setWOfRiver(bool bNewValue, CardinalDirectionTypes eRiverDir);

	__declspec(dllexport) CardinalDirectionTypes getRiverNSDirection() const;
	__declspec(dllexport) CardinalDirectionTypes getRiverWEDirection() const;
	EuropeTypes getEurope() const;
	void setEurope(EuropeTypes eEurope);
	EuropeTypes getNearestEurope() const;
	bool isEuropeAccessable() const;

	CvPlot* getInlandCorner() const;
	bool hasCoastAtSECorner() const;
	bool isPotentialCityWork() const;
	bool isPotentialCityWorkForArea(CvArea* pArea) const;
	void updatePotentialCityWork();
	bool isShowCitySymbols() const;
	void updateShowCitySymbols();
	bool isFlagDirty() const;
	void setFlagDirty(bool bNewValue);

	__declspec(dllexport) PlayerTypes getOwner() const;
	inline PlayerTypes getOwnerINLINE() const
	{
		return m_eOwner;
	}
	void setOwner(PlayerTypes eNewValue, bool bCheckUnits);
	PlotTypes getPlotType() const;
	__declspec(dllexport) bool isWater() const;
	bool hasLargeRiver() const;
	bool isEurope() const;
	bool isFlatlands() const;
	__declspec(dllexport) bool isHills() const;
	__declspec(dllexport) bool isPeak() const;
	void setPlotType(PlotTypes eNewValue, bool bRecalculate = true, bool bRebuildGraphics = true);

	void setCoastline(bool bRecalculate = true, bool bRebuildGraphics = true); // autodetect lakes
	__declspec(dllexport) TerrainTypes getTerrainType() const;
	void setTerrainType(TerrainTypes eNewValue, bool bRecalculate = true, bool bRebuildGraphics = true);

	__declspec(dllexport) FeatureTypes getFeatureType() const;
	void setFeatureType(FeatureTypes eNewValue, int iVariety = -1);
	__declspec(dllexport) BonusTypes getBonusType() const;
	void setBonusType(BonusTypes eNewValue);

	__declspec(dllexport) ImprovementTypes getImprovementType() const;
	void setImprovementType(ImprovementTypes eNewValue);

	RouteTypes getRouteType() const;
	void setRouteType(RouteTypes eNewValue);
	void updateCityRoute();
	__declspec(dllexport) CvCity* getPlotCity() const;
	void setPlotCity(CvCity* pNewValue);
	__declspec(dllexport) CvCity* getWorkingCity() const;
	void updateWorkingCity();
	CvCity* getWorkingCityOverride() const;
	void setWorkingCityOverride( const CvCity* pNewValue);
	int getRiverID() const;
	void setRiverID(int iNewValue);

	int getMinOriginalStartDist() const;
	void setMinOriginalStartDist(int iNewValue);
	int getRiverCrossingCount() const;
	void changeRiverCrossingCount(int iChange);
	const EnumMap<YieldTypes, short> getYield() const;
	__declspec(dllexport) int getYield(YieldTypes eIndex) const;

	// TAC - AI Improved Naval AI - koma13 - START
	int getDangerMap(PlayerTypes eIndex) const;
	void setDangerMap(PlayerTypes eIndex, int iNewValue);
	// TAC - AI Improved Naval AI - koma13 - END

	BonusTypes getVariable(BonusTypes) const;
	FeatureTypes getVariable(FeatureTypes) const;
	ImprovementTypes getVariable(ImprovementTypes) const;
	PlotTypes getVariable(PlotTypes) const;
	RouteTypes getVariable(RouteTypes) const;
	TerrainTypes getVariable(TerrainTypes) const;

	int calculateNatureYield(YieldTypes eIndex, TeamTypes eTeam, bool bIgnoreFeature = false) const;
	int calculateBestNatureYield(YieldTypes eIndex, TeamTypes eTeam) const;
	int calculateTotalBestNatureYield(TeamTypes eTeam) const;
	int calculateImprovementYieldChange(ImprovementTypes eImprovement, YieldTypes eYield, PlayerTypes ePlayer, bool bOptimal = false) const;
	int calculateYield(YieldTypes eIndex, bool bDisplay) const;
	int calculatePotentialYield(YieldTypes eIndex, const CvUnit* pUnit, bool bDisplay) const;
	int calculatePotentialYield(YieldTypes eYield, PlayerTypes ePlayer, ImprovementTypes eImprovement, bool bIgnoreFeature, RouteTypes eRoute, UnitTypes eUnit, bool bDisplay) const;
	int calculatePotentialProfessionYieldAmount(ProfessionTypes eProfession, const CvUnit* pUnit, bool bDisplay) const;
	// R&R, ray , MYCP partially based on code of Aymerick - START
	int calculatePotentialProfessionYieldsAmount(YieldTypes eYield, ProfessionTypes eProfession, const CvUnit* pUnit, bool bDisplay) const;
	// R&R, ray , MYCP partially based on code of Aymerick - END
	int calculatePotentialCityYield(YieldTypes eYield, const CvCity *pCity) const;
	bool hasYield() const;
	void updateYield(bool bUpdateCity);
	int calculateMaxYield(YieldTypes eYield) const;
	int getYieldWithBuild(BuildTypes eBuild, YieldTypes eYield, bool bWithUpgrade) const;
	__declspec(dllexport) int getCulture(PlayerTypes eIndex) const;
	__declspec(dllexport) int countTotalCulture() const;
	int countFriendlyCulture(TeamTypes eTeam) const;
	TeamTypes findHighestCultureTeam() const;
	PlayerTypes findHighestCulturePlayer() const;
	int calculateCulturePercent(PlayerTypes eIndex) const;
	int calculateTeamCulturePercent(TeamTypes eIndex) const;
	void setCulture(PlayerTypes eIndex, int iNewValue, bool bUpdate);
	void changeCulture(PlayerTypes eIndex, int iChange, bool bUpdate);
	int getBuyCultureAmount(PlayerTypes ePlayer) const;
	int getBuyPrice(PlayerTypes ePlayer) const;
	int getFoundValue(PlayerTypes eIndex);
	bool isBestAdjacentFound(PlayerTypes eIndex);
	void setFoundValue(PlayerTypes eIndex, int iNewValue);
	int getPlayerCityRadiusCount(PlayerTypes eIndex) const;
	bool isPlayerCityRadius(PlayerTypes eIndex) const;
	void changePlayerCityRadiusCount(PlayerTypes eIndex, int iChange);

	int getVisibilityCount(TeamTypes eTeam) const;
	void changeVisibilityCount(TeamTypes eTeam, int iChange, InvisibleTypes eSeeInvisible);

	__declspec(dllexport) PlayerTypes getRevealedOwner(TeamTypes eTeam, bool bDebug) const;
	TeamTypes getRevealedTeam(TeamTypes eTeam, bool bDebug) const;
	void setRevealedOwner(TeamTypes eTeam, PlayerTypes eNewValue);
	void updateRevealedOwner(TeamTypes eTeam);
	__declspec(dllexport) bool isRiverCrossing(DirectionTypes eIndex) const;
	void updateRiverCrossing(DirectionTypes eIndex);
	void updateRiverCrossing();
	__declspec(dllexport) bool isRevealed(TeamTypes eTeam, bool bDebug) const;
	void setRevealed(TeamTypes eTeam, bool bNewValue, bool bTerrainOnly, TeamTypes eFromTeam);
	bool isAdjacentRevealed(TeamTypes eTeam) const;
	bool isAdjacentNonrevealed(TeamTypes eTeam) const;

	ImprovementTypes getRevealedImprovementType(TeamTypes eTeam, bool bDebug) const;
	void setRevealedImprovementType(TeamTypes eTeam, ImprovementTypes eNewValue);

	RouteTypes getRevealedRouteType(TeamTypes eTeam, bool bDebug) const;
	void setRevealedRouteType(TeamTypes eTeam, RouteTypes eNewValue);

	int getBuildProgress(BuildTypes eBuild) const;
	bool changeBuildProgress(BuildTypes eBuild, int iChange, TeamTypes eTeam = NO_TEAM);

	void updateFeatureSymbolVisibility();
	void updateFeatureSymbol(bool bForce = false, bool bBuildTileArt = true);

	__declspec(dllexport) bool isLayoutDirty() const;							// The plot layout contains bonuses and improvements --- it is, like the city layout, passively computed by LSystems
	__declspec(dllexport) void setLayoutDirty(bool bDirty);
	__declspec(dllexport) bool isLayoutStateDifferent() const;
	__declspec(dllexport) void setLayoutStateToCurrent();
	bool updatePlotBuilder();

	__declspec(dllexport) void getVisibleImprovementState(ImprovementTypes& eType, bool& bWorked);				// determines how the improvement state is shown in the engine
	__declspec(dllexport) void getVisibleBonusState(BonusTypes& eType, bool& bImproved, bool& bWorked);		// determines how the bonus state is shown in the engine
	bool shouldUsePlotBuilder();
	CvPlotBuilder* getPlotBuilder() { return m_pPlotBuilder; }

	__declspec(dllexport) CvRoute* getRouteSymbol() const;
	void updateRouteSymbol(bool bForce = false, bool bAdjacent = false);

	__declspec(dllexport) CvRiver* getRiverSymbol() const;
	void updateRiverSymbol(bool bForce = false, bool bAdjacent = false);

	CvFeature* getFeatureSymbol() const;

	__declspec(dllexport) CvFlagEntity* getFlagSymbol() const;
	CvFlagEntity* getFlagSymbolOffset() const;
	__declspec(dllexport) void updateFlagSymbol();

	__declspec(dllexport) CvUnit* getCenterUnit() const;
	__declspec(dllexport) CvUnit* getDebugCenterUnit() const;
	void setCenterUnit(CvUnit* pNewValue);
	int getCultureRangeCities(PlayerTypes eOwnerIndex, CultureLevelTypes eRangeIndex) const;
	bool isCultureRangeCity(PlayerTypes eOwnerIndex, CultureLevelTypes eRangeIndex) const;
	void changeCultureRangeCities(PlayerTypes eOwnerIndex, CultureLevelTypes eRangeIndex, int iChange);
	int getInvisibleVisibilityCount(TeamTypes eTeam, InvisibleTypes eInvisible) const;
	bool isInvisibleVisible(TeamTypes eTeam, InvisibleTypes eInvisible) const;
	void changeInvisibleVisibilityCount(TeamTypes eTeam, InvisibleTypes eInvisible, int iChange);

	int getNumUnits() const;
	CvUnit* getUnitByIndex(int iIndex) const;
	void addUnit(CvUnit* pUnit, bool bUpdate = true);
	void removeUnit(CvUnit* pUnit, bool bUpdate = true);
	__declspec(dllexport) CLLNode<IDInfo>* nextUnitNode(CLLNode<IDInfo>* pNode) const;
	CLLNode<IDInfo>* prevUnitNode(CLLNode<IDInfo>* pNode) const;
	__declspec(dllexport) CLLNode<IDInfo>* headUnitNode() const;
	CLLNode<IDInfo>* tailUnitNode() const;

	// Script data needs to be a narrow string for pickling in Python
	CvString getScriptData() const;
	void setScriptData(const char* szNewValue);

	bool canTrigger(EventTriggerTypes eTrigger, PlayerTypes ePlayer) const;
	bool canApplyEvent(EventTypes eEvent) const;
	void applyEvent(EventTypes eEvent);

	bool canTrain(UnitTypes eUnit, bool bContinue, bool bTestVisible) const;
	bool isValidYieldChanges(UnitTypes eUnit) const;

	void setDistanceToOcean(int iNewValue);
	int getDistanceToOcean() const;

	CvPlot* findNearbyOceanPlot(int iRandomization = 25);

	int getCrumbs() const;
	void addCrumbs(int iQuantity);

	__declspec(dllexport) const char* getResourceLayerIcon(ResourceLayerOptions eOption, CvWStringBuffer& szHelp, PlotIndicatorVisibilityFlags& eVisibilityFlag, ColorTypes& eColor) const;
	__declspec(dllexport) CvUnit* getUnitLayerUnit(UnitLayerOptionTypes eOption, CvWStringBuffer& szHelp, PlotIndicatorVisibilityFlags& eVisibilityFlag, ColorTypes& eColor, bool& bTestEnemyVisibility) const;

	void postLoadFixes();

	void read(CvSavegameReader& reader);
	void write(CvSavegameWriter& writer) const;

	void writeDesyncLog(FILE *f);

protected:

	void resetSavedData();

	void updateImpassable();

	Coordinates m_coord;
	int m_iArea;
	mutable CvArea *m_pPlotArea;
	short m_iFeatureVariety;
	short m_iOwnershipDuration;
	short m_iImprovementDuration;
	short m_iUpgradeProgress;
	short m_iForceUnownedTimer;
	short m_iCityRadiusCount;
	int m_iRiverID;
	short m_iMinOriginalStartDist;
	short m_iRiverCrossingCount;
	short m_iDistanceToOcean;
	short m_iCrumbs;
	// Super Forts begin *canal* *choke*
	int m_iCanalValue;
	int m_iChokeValue;
	// Super Forts end
	// Super Forts begin *bombard*
	int m_iDefenseDamage;
	bool m_bBombarded:1;
	// Super Forts end

	bool m_bStartingPlot:1;
	bool m_bHills:1;
	bool m_bNOfRiver:1;
	bool m_bWOfRiver:1;
	bool m_bPotentialCityWork:1;
	bool m_bShowCitySymbols:1;
	bool m_bFlagDirty:1;
	bool m_bPlotLayoutDirty:1;
	bool m_bLayoutStateWorked:1;
	bool m_bImpassable:1;

	PlotTypes m_ePlotType : 16;
	TerrainTypes m_eTerrainType : 16;
	FeatureTypes m_eFeatureType : 16;
	BonusTypes m_eBonusType : 16;
	ImprovementTypes m_eImprovementType : 16;
	RouteTypes m_eRouteType : 16;

	PlayerTypes m_eOwner : 8;
	CardinalDirectionTypes m_eRiverNSDirection : 8;
	CardinalDirectionTypes m_eRiverWEDirection : 8;
	EuropeTypes m_eEurope : 8;

	byte m_bmRiverCrossing;

	IDInfo m_plotCity;
	IDInfo m_workingCity;
	IDInfo m_workingCityOverride;

	EnumMap<YieldTypes , short> m_em_iYield;
	EnumMap<PlayerTypes, short> m_em_iDangerMap;	// TAC - AI Improved Naval AI - koma13
	EnumMap<PlayerTypes,   int> m_em_iCulture;
	EnumMap<PlayerTypes, short> m_em_iCultureRangeForts; // Super Forts *culture*
	EnumMap<PlayerTypes,   int> m_em_iFoundValue;
	EnumMap<PlayerTypes,  char> m_em_iPlayerCityRadiusCount;

	// keep all visibility variables together as they are usually accessed together
	// this maximizes CPU cache usage, hence reducing memory latency slowdowns
	signed char m_seeFromLevelCache;
	signed char m_seeThroughLevelCache;
	signed char m_iPlotVisibilityCache;
	signed char m_iUnitVisibilityBonusCache;
	EnumMap<TeamTypes, short      > m_em_iVisibilityCount;
	EnumMap<TeamTypes, PlayerTypes> m_em_eRevealedOwner;
	EnumMap<TeamTypes, bool       > m_em_bRevealed;
	RevealedPlotDataArray m_aeRevealedImprovementRouteTypes;

	char* m_szScriptData;

	EnumMap<BuildTypes, short> m_em_iBuildProgress;

	CvFeature* m_pFeatureSymbol;
	CvRoute* m_pRouteSymbol;
	CvRiver* m_pRiverSymbol;
	CvFlagEntity* m_pFlagSymbol;
	CvFlagEntity* m_pFlagSymbolOffset;
	CvUnit* m_pCenterUnit;

	CvPlotBuilder* m_pPlotBuilder;		// builds bonuses and improvements

	EnumMap<PlayerTypes, EnumMap<CultureLevelTypes, char > > m_em2_iCultureRangeCities;
	EnumMap<TeamTypes  , EnumMap<InvisibleTypes   , short> > m_em2_iInvisibleVisibilityCount;

	CLinkList<IDInfo> m_units;

	void doFeature();
	void doCulture(); // R&R mod, vetiarvind, super forts (outposts) merge

	void processArea(CvArea* pArea, int iChange);
	void doImprovementUpgrade();
	// R&R, ray, Monasteries and Forts - START
	void doFort();
	void doMonastery();
	// R&R, ray, Monasteries and Forts - END
	//R&R mod, vetiarvind, super forts merge, refactor checks for activating monastery and forts - start
	void doUpgradeNonWorkerImprovements();// R&R mod, vetiarvind, monasteries and forts upgrade bug fix
	//R&R mod, vetiarvind, super forts merge, refactor checks for activating monastery and forts - end
	ColorTypes plotMinimapColor();

	// added so under cheat mode we can access protected stuff
	friend class CvGameTextMgr;

	// CvPlot::hasYield cache - start - Nightinggale
public:
	void setYieldCache();
	// Cache the computation of the max visibility range

	// WTP, ray, helper methods for Python Event System - Spawning Units and Barbarians on Plots - START
	void spawnPlayerUnitOnPlot(int /*PlayerTypes*/ iPlayer, int /*UnitClassTypes*/ iIndex) const;
	void spawnBarbarianUnitOnPlot(int /*UnitClassTypes*/ iIndex) const; // careful with this, because will take over City for Barbarians
	void spawnPlayerUnitOnAdjacentPlot(int /*PlayerTypes*/ iPlayer, int /*UnitClassTypes*/ iIndex) const;
	void spawnBarbarianUnitOnAdjacentPlot(int /*UnitClassTypes*/ iIndex) const;

	bool isPlayerUnitOnAdjacentPlot(int /*PlayerTypes*/ iPlayer, int /*UnitClassTypes*/ iIndex) const;
	bool isBarbarianUnitOnAdjacentPlot(int /*UnitClassTypes*/ iIndex) const;
	// WTP, ray, helper methods for Python Event System - Spawning Units and Barbarians on Plots - END

protected:
	// plot visibility cache
	void setSeeFromLevelCache();
	void setSeeThroughLevelCache();
	void setPlotVisibilityCache();
	void setUnitVisibilityBonusCache();
	int getSeeFromLevelUncached() const;
	int getSeeThroughLevelUncached() const;
	int getPlotVisibilityUncached() const;
	int getUnitVisibilityBonusUncached() const;

	bool hasYieldUncached() const;
	bool m_bHasYield;
	// CvPlot::hasYield cache - end - Nightinggale
	void upgradeImprovement(ImprovementTypes eImprovementUpgrade, int iUpgradeRate);

private:
	void __template_declaration_func();
};

#endif
