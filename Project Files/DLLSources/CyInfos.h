#ifndef CY_INFOS_H
#define CY_INFOS_H
#include "CvInfos.h"


class CyAchieveInfo : public CvAchieveInfo
{
public:
};
static_assert(sizeof(CyAchieveInfo) == sizeof(CvAchieveInfo));

class CyEffectInfo : public CvEffectInfo
{
public:
};
static_assert(sizeof(CyEffectInfo) == sizeof(CvEffectInfo));

class CyTerrainInfo : public CvTerrainInfo
{
public:
};
static_assert(sizeof(CyTerrainInfo) == sizeof(CvTerrainInfo));

class CyBonusInfo : public CvBonusInfo
{
public:
};
static_assert(sizeof(CyBonusInfo) == sizeof(CvBonusInfo));

class CyFeatureInfo : public CvFeatureInfo
{
public:
};
static_assert(sizeof(CyFeatureInfo) == sizeof(CvFeatureInfo));

class CyCivilizationInfo : public CvCivilizationInfo
{
public:
};
static_assert(sizeof(CyCivilizationInfo) == sizeof(CvCivilizationInfo));

class CyLeaderHeadInfo : public CvLeaderHeadInfo
{
public:
};
static_assert(sizeof(CyLeaderHeadInfo) == sizeof(CvLeaderHeadInfo));

class CyTraitInfo : public CvTraitInfo
{
public:
};
static_assert(sizeof(CyTraitInfo) == sizeof(CvTraitInfo));

class CyUnitInfo : public CvUnitInfo
{
public:
	int getDefaultProfession() const;
	int getUnitClassType() const;
};
static_assert(sizeof(CyUnitInfo) == sizeof(CvUnitInfo));

class CySpecialUnitInfo : public CvSpecialUnitInfo
{
public:
};
static_assert(sizeof(CySpecialUnitInfo) == sizeof(CvSpecialUnitInfo));

class CyYieldInfo : public CvYieldInfo
{
public:
};
static_assert(sizeof(CyYieldInfo) == sizeof(CvYieldInfo));

class CyRouteInfo : public CvRouteInfo
{
public:
};
static_assert(sizeof(CyRouteInfo) == sizeof(CvRouteInfo));

class CyImprovementInfo : public CvImprovementInfo
{
public:
};
static_assert(sizeof(CyImprovementInfo) == sizeof(CvImprovementInfo));

class CyGoodyInfo : public CvGoodyInfo
{
public:
};
static_assert(sizeof(CyGoodyInfo) == sizeof(CvGoodyInfo));

class CyBuildInfo : public CvBuildInfo
{
public:
};
static_assert(sizeof(CyBuildInfo) == sizeof(CvBuildInfo));

class CyHandicapInfo : public CvHandicapInfo
{
public:
};
static_assert(sizeof(CyHandicapInfo) == sizeof(CvHandicapInfo));

class CyGameSpeedInfo : public CvGameSpeedInfo
{
public:
};
static_assert(sizeof(CyGameSpeedInfo) == sizeof(CvGameSpeedInfo));

class CyTurnTimerInfo : public CvTurnTimerInfo
{
public:
};
static_assert(sizeof(CyTurnTimerInfo) == sizeof(CvTurnTimerInfo));

class CyBuildingClassInfo : public CvBuildingClassInfo
{
public:
};
static_assert(sizeof(CyBuildingClassInfo) == sizeof(CvBuildingClassInfo));

class CyMissionInfo : public CvMissionInfo
{
public:
};
static_assert(sizeof(CyMissionInfo) == sizeof(CvMissionInfo));

class CyCommandInfo : public CvCommandInfo
{
public:
};
static_assert(sizeof(CyCommandInfo) == sizeof(CvCommandInfo));

class CyAutomateInfo : public CvAutomateInfo
{
public:
};
static_assert(sizeof(CyAutomateInfo) == sizeof(CvAutomateInfo));

class CyActionInfo : public CvActionInfo
{
public:
};
static_assert(sizeof(CyActionInfo) == sizeof(CvActionInfo));

class CyUnitClassInfo : public CvUnitClassInfo
{
public:
};
static_assert(sizeof(CyUnitClassInfo) == sizeof(CvUnitClassInfo));

class CyBuildingInfo : public CvBuildingInfo
{
public:
};
static_assert(sizeof(CyBuildingInfo) == sizeof(CvBuildingInfo));

class CyCivicInfo : public CvCivicInfo
{
public:
};
static_assert(sizeof(CyCivicInfo) == sizeof(CvCivicInfo));

class CyDiplomacyInfo : public CvDiplomacyInfo
{
public:
};
static_assert(sizeof(CyDiplomacyInfo) == sizeof(CvDiplomacyInfo));

class CyControlInfo : public CvControlInfo
{
public:
};
static_assert(sizeof(CyControlInfo) == sizeof(CvControlInfo));

class CySpecialBuildingInfo : public CvSpecialBuildingInfo
{
public:
};
static_assert(sizeof(CySpecialBuildingInfo) == sizeof(CvSpecialBuildingInfo));

class CyPromotionInfo : public CvPromotionInfo
{
public:
};
static_assert(sizeof(CyPromotionInfo) == sizeof(CvPromotionInfo));

class CyProfessionInfo : public CvProfessionInfo
{
public:
};
static_assert(sizeof(CyProfessionInfo) == sizeof(CvProfessionInfo));

class CyEmphasizeInfo : public CvEmphasizeInfo
{
public:
};
static_assert(sizeof(CyEmphasizeInfo) == sizeof(CvEmphasizeInfo));

class CyCultureLevelInfo : public CvCultureLevelInfo
{
public:
};
static_assert(sizeof(CyCultureLevelInfo) == sizeof(CvCultureLevelInfo));

class CyEraInfo : public CvEraInfo
{
public:
};
static_assert(sizeof(CyEraInfo) == sizeof(CvEraInfo));

class CyVictoryInfo : public CvVictoryInfo
{
public:
};
static_assert(sizeof(CyVictoryInfo) == sizeof(CvVictoryInfo));

class CyWorldInfo : public CvWorldInfo
{
public:
};
static_assert(sizeof(CyWorldInfo) == sizeof(CvWorldInfo));

class CyClimateInfo : public CvClimateInfo
{
public:
};
static_assert(sizeof(CyClimateInfo) == sizeof(CvClimateInfo));

class CySeaLevelInfo : public CvSeaLevelInfo
{
public:
};
static_assert(sizeof(CySeaLevelInfo) == sizeof(CvSeaLevelInfo));

class CyEuropeInfo : public CvEuropeInfo
{
public:
};
static_assert(sizeof(CyEuropeInfo) == sizeof(CvEuropeInfo));

class CyMainMenuInfo : public CvMainMenuInfo
{
public:
};
static_assert(sizeof(CyMainMenuInfo) == sizeof(CvMainMenuInfo));

class CyFatherInfo : public CvFatherInfo
{
public:
};
static_assert(sizeof(CyFatherInfo) == sizeof(CvFatherInfo));

class CyFatherPointInfo : public CvFatherPointInfo
{
public:
};
static_assert(sizeof(CyFatherPointInfo) == sizeof(CvFatherPointInfo));

class CyEventTriggerInfo : public CvEventTriggerInfo
{
public:
};
static_assert(sizeof(CyEventTriggerInfo) == sizeof(CvEventTriggerInfo));

class CyEventInfo : public CvEventInfo
{
public:
};
static_assert(sizeof(CyEventInfo) == sizeof(CvEventInfo));

class CyHurryInfo : public CvHurryInfo
{
public:
};
static_assert(sizeof(CyHurryInfo) == sizeof(CvHurryInfo));

class CyPlayerOptionInfo : public CvPlayerOptionInfo
{
public:
};
static_assert(sizeof(CyPlayerOptionInfo) == sizeof(CvPlayerOptionInfo));

class CyGraphicOptionInfo : public CvGraphicOptionInfo
{
public:
};
static_assert(sizeof(CyGraphicOptionInfo) == sizeof(CvGraphicOptionInfo));

#endif
