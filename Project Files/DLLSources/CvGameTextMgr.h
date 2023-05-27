#pragma once

//  $Header:
//------------------------------------------------------------------------------------------------
//
//  FILE:    CvGameTextMgr.h
//
//  AUTHOR:  Jesse Smith  --  10/2004
//
//  PURPOSE: Group of functions to manage CIV Game Text
//
//------------------------------------------------------------------------------------------------
//  Copyright (c) 2004 Firaxis Games, Inc. All rights reserved.
//------------------------------------------------------------------------------------------------
#ifndef CIV4_GAME_TEXT_MGR_H
#define CIV4_GAME_TEXT_MGR_H

#include "CvInfos.h"
//#include "CvEnums.h"

#pragma warning( disable: 4251 )	// needs to have dll-interface to be used by clients of class

class CvCity;
class CvDeal;
class CvPopupInfo;
class CvPlayer;

//
// Class:		CvGameTextMgr
// Purpose:		Manages Game Text...
class CvGameTextMgr
{
	friend class CvGlobals;
public:
	// singleton accessor
	__declspec(dllexport) static CvGameTextMgr& GetInstance();

	__declspec(dllexport) CvGameTextMgr();
	__declspec(dllexport) virtual ~CvGameTextMgr();

	__declspec(dllexport) void Initialize();
	__declspec(dllexport) void DeInitialize();
	__declspec(dllexport) void Reset();

	__declspec(dllexport) int getCurrentLanguage();

	__declspec(dllexport) void setTimeStr(CvWString& szString, int iGameTurn, bool bSave);
	__declspec(dllexport) void setYearStr(CvWString& szString, int iGameTurn, bool bSave, CalendarTypes eCalendar, int iStartYear, GameSpeedTypes eSpeed);
	__declspec(dllexport) void setDateStr(CvWString& szString, int iGameTurn, bool bSave, CalendarTypes eCalendar, int iStartYear, GameSpeedTypes eSpeed);
	__declspec(dllexport) void setInterfaceTime(CvWString& szString, PlayerTypes ePlayer);
	__declspec(dllexport) void setGoldStr(CvWString& szString, PlayerTypes ePlayer);
	__declspec(dllexport) void setOOSSeeds(CvWString& szString, PlayerTypes ePlayer);
	__declspec(dllexport) void setNetStats(CvWString& szString, PlayerTypes ePlayer);
	__declspec(dllexport) void setMinimizePopupHelp(CvWString& szString, const CvPopupInfo & info);

	__declspec(dllexport) void setUnitHelp(CvWStringBuffer &szString, const CvUnit* pUnit, bool bOneLine = false, bool bShort = false);
	__declspec(dllexport) void setUnitPromotionHelp(CvWStringBuffer &szString, const CvUnit* pUnit);
	__declspec(dllexport) void setPlotListHelp(CvWStringBuffer &szString, const CvPlot* pPlot, bool bOneLine, bool bShort);
	__declspec(dllexport) bool setCombatPlotHelp(CvWStringBuffer &szString, CvPlot* pPlot);
	__declspec(dllexport) void setPlotHelp(CvWStringBuffer &szString, CvPlot* pPlot);
	void setCityPlotHelp(CvWStringBuffer &szString, CvPlot* pPlot); // city plot mouse over help - inaiwae
	__declspec(dllexport) void setCityBarHelp(CvWStringBuffer &szString, CvCity* pCity);
	__declspec(dllexport) void setScoreHelp(CvWStringBuffer &szString, PlayerTypes ePlayer);
	__declspec(dllexport) void setCitizenHelp(CvWStringBuffer &szString, const CvCity& kCity, const CvUnit& kUnit);
	__declspec(dllexport) void setEuropeYieldSoldHelp(CvWStringBuffer &szString, const CvPlayer& kPlayer, YieldTypes eYield, int iAmount, int iCommission);
	__declspec(dllexport) void setEuropeYieldBoughtHelp(CvWStringBuffer &szString, const CvPlayer& kPlayer, YieldTypes eYield, int iAmount);
	__declspec(dllexport) void parseTraits(CvWStringBuffer &szHelpString, TraitTypes eTrait, CivilizationTypes eCivilization = NO_CIVILIZATION, bool bDawnOfMan = false, bool bIndent = true);
	__declspec(dllexport) void parseLeaderTraits(CvWStringBuffer &szInfoText, LeaderHeadTypes eLeader = NO_LEADER, CivilizationTypes eCivilization = NO_CIVILIZATION, bool bDawnOfMan = false, bool bCivilopediaText = false);
	__declspec(dllexport) void parseLeaderShortTraits(CvWStringBuffer &szInfoText, LeaderHeadTypes eLeader);
	__declspec(dllexport) void parseCivShortTraits(CvWStringBuffer &szInfoText, CivilizationTypes eCiv);
	__declspec(dllexport) void parseCivInfos(CvWStringBuffer &szHelpString, CivilizationTypes eCivilization, bool bDawnOfMan = false, bool bLinks = true);
	__declspec(dllexport) void parsePromotionHelp(CvWStringBuffer &szBuffer, PromotionTypes ePromotion, const wchar* pcNewline = NEWLINE);
	__declspec(dllexport) void parseCivicInfo(CvWStringBuffer &szBuffer, CivicTypes eCivic, bool bCivilopediaText = false, bool bPlayerContext = false, bool bSkipName = false);
	__declspec(dllexport) void parsePlayerTraits(CvWStringBuffer &szBuffer, PlayerTypes ePlayer);
	__declspec(dllexport) void parseLeaderHeadHelp(CvWStringBuffer &szBuffer, PlayerTypes eThisPlayer, PlayerTypes eOtherPlayer);
	__declspec(dllexport) void parseLeaderLineHelp(CvWStringBuffer &szBuffer, PlayerTypes eThisPlayer, PlayerTypes eOtherPlayer);
	__declspec(dllexport) void parseGreatGeneralHelp(CvWStringBuffer &szBuffer, CvPlayer& kPlayer);
	// CivEffects - Nightinggale - start
	void parseCivEffects(CvWStringBuffer &szHelpString, CivEffectTypes eCivEffect, CivilizationTypes eCivilization = NO_CIVILIZATION, bool bDawnOfMan = false, bool bIndent = true);
	// CivEffects - Nightinggale - end
	__declspec(dllexport) void setBasicUnitHelp(CvWStringBuffer &szBuffer, UnitTypes eUnit, bool bCivilopediaText = false);
	__declspec(dllexport) void setUnitHelp(CvWStringBuffer &szBuffer, UnitTypes eUnit, bool bCivilopediaText = false, bool bStrategyText = false, CvCity* pCity = nullptr);
	__declspec(dllexport) void setProfessionHelp(CvWStringBuffer &szBuffer, ProfessionTypes eProfession, bool bCivilopediaText = false, bool bStrategyText = false);
	__declspec(dllexport) void setBuildingHelp(CvWStringBuffer &szBuffer, BuildingTypes eBuilding, bool bCivilopediaText = false, bool bStrategyText = false, CvCity* pCity = nullptr);
	__declspec(dllexport) void setFatherPointHelp(CvWStringBuffer &szBuffer, FatherPointTypes eFatherPointType);
	__declspec(dllexport) void setYieldChangeHelp(CvWStringBuffer &szBuffer, const CvWString& szStart, const CvWString& szSpace, const CvWString& szEnd, const int* piYieldChange, bool bPercent = false, bool bNewLine = true);
	__declspec(dllexport) void setBonusHelp(CvWStringBuffer &szBuffer, BonusTypes eBonus, bool bCivilopediaText = false);
	__declspec(dllexport) void setPromotionHelp(CvWStringBuffer &szBuffer, PromotionTypes ePromotion, bool bCivilopediaText = false);
	__declspec(dllexport) void setImprovementHelp(CvWStringBuffer &szBuffer, ImprovementTypes eImprovement, bool bCivilopediaText = false);
	__declspec(dllexport) void setTerrainHelp(CvWStringBuffer &szBuffer, TerrainTypes eTerrain, bool bCivilopediaText = false);
	__declspec(dllexport) void setYieldsHelp(CvWStringBuffer &szBuffer, YieldTypes eYield, bool bCivilopediaText = false);
	__declspec(dllexport) void setFeatureHelp(CvWStringBuffer &szBuffer, FeatureTypes eFeature, bool bCivilopediaText = false);
	__declspec(dllexport) void setProductionHelp(CvWStringBuffer &szBuffer, CvCity& city);
	__declspec(dllexport) void setYieldPriceHelp(CvWStringBuffer &szBuffer, PlayerTypes ePlayer, YieldTypes eYield);
	__declspec(dllexport) void setYieldHelp(CvWStringBuffer &szBuffer, CvCity& city, YieldTypes eYieldType);
	__declspec(dllexport) void setEventHelp(CvWStringBuffer& szBuffer, EventTypes eEvent, int iEventTriggeredId, PlayerTypes ePlayer);
	__declspec(dllexport) void setFatherHelp(CvWStringBuffer &szBuffer, FatherTypes eFather, bool bCivilopediaText);
	__declspec(dllexport) void buildHintsList(CvWStringBuffer& szBuffer);
	__declspec(dllexport) void buildBuildingRequiresString(CvWStringBuffer& szBuffer, BuildingTypes eBuilding, bool bCivilopediaText, const CvCity* pCity);
	__declspec(dllexport) void buildCityBillboardIconString( CvWStringBuffer& szBuffer, CvCity* pCity);
	__declspec(dllexport) void buildCityBillboardCityNameString( CvWStringBuffer& szBuffer, CvCity* pCity);
	__declspec(dllexport) void buildCityBillboardProductionString( CvWStringBuffer& szBuffer, CvCity* pCity);
	__declspec(dllexport) void buildCityBillboardCitySizeString( CvWStringBuffer& szBuffer, CvCity* pCity, const NiColorA& kColor);
	void getWarplanString(CvWStringBuffer& szString, WarPlanTypes eWarPlan);
	__declspec(dllexport) void getAttitudeString(CvWStringBuffer& szBuffer, PlayerTypes ePlayer, PlayerTypes eTargetPlayer);
	__declspec(dllexport) void getTradeString(CvWStringBuffer& szBuffer, const TradeData& tradeData, PlayerTypes ePlayer1, PlayerTypes ePlayer2);
	__declspec(dllexport) void getDealString(CvWStringBuffer& szString, CvDeal& deal, PlayerTypes ePlayerPerspective = NO_PLAYER);
	void getDealString(CvWStringBuffer& szBuffer, PlayerTypes ePlayer1, PlayerTypes ePlayer2, const CLinkList<TradeData>* pListPlayer1, const CLinkList<TradeData>* pListPlayer2, PlayerTypes ePlayerPerspective = NO_PLAYER);
	__declspec(dllexport) void getActiveDealsString(CvWStringBuffer& szString, PlayerTypes eThisPlayer, PlayerTypes eOtherPlayer);
	__declspec(dllexport) void getTradeScreenTitleIcon(CvString& szButton, CvWidgetDataStruct& widgetData, PlayerTypes ePlayer);
	__declspec(dllexport) void getTradeScreenIcons(std::vector< std::pair<CvString, CvWidgetDataStruct> >& aIconInfos, PlayerTypes ePlayer);
	__declspec(dllexport) void getTradeScreenHeader(CvWString& szHeader, PlayerTypes ePlayer, PlayerTypes eOtherPlayer, bool bAttitude, CvCity* pCity);

	__declspec(dllexport) void setResourceLayerInfo(ResourceLayerOptions eOption, CvWString& szName, CvString& szButton);
	__declspec(dllexport) void setUnitLayerInfo(UnitLayerOptionTypes eOption, CvWString& szName, CvString& szButton);

	// WTP, ray, fixing wrong Trade Log in Port Royal
	void setAfricaYieldSoldHelp(CvWStringBuffer &szString, const CvPlayer& kPlayer, YieldTypes eYield, int iAmount, int iCommission);
	void setPortRoyalYieldSoldHelp(CvWStringBuffer &szString, const CvPlayer& kPlayer, YieldTypes eYield, int iAmount, int iCommission);

private:
	void eventGoldHelp(CvWStringBuffer& szBuffer, EventTypes eEvent, PlayerTypes ePlayer, PlayerTypes eOtherPlayer);

	std::vector<int*> m_apbPromotion;

	void setCityPlotYieldValueString(CvWStringBuffer& szString, CvCity* pCity, int iIndex, bool bAvoidGrowth, bool bIgnoreGrowth, bool bIgnoreFood = false);
	void setYieldValueString(CvWStringBuffer& szString, int iValue, bool bActive = false, bool bMakeWhitespace = false);
	int setCityYieldModifierString(CvWStringBuffer& szBuffer, YieldTypes eYieldType, const CvCity& kCity);
};

// Singleton Accessor
#define GAMETEXT CvGameTextMgr::GetInstance()

#endif
