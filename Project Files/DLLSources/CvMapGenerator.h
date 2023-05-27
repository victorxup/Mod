#pragma once

#ifndef CIV4_MAPGENERATOR_H
#define CIV4_MAPGENERATOR_H

//#include "CvEnums.h"

#pragma warning( disable: 4251 )		// needs to have dll-interface to be used by clients of class

class CvFractal;
class CvPlot;
class CvArea;

class CvMapGenerator
{
public:
	__declspec(dllexport) static CvMapGenerator& GetInstance();
	__declspec(dllexport) static void FreeInstance() { SAFE_DELETE(m_pInst); }
	CvMapGenerator();
	virtual ~CvMapGenerator();

	bool canPlaceBonusAt(BonusTypes eBonus, int iX, int iY, bool bIgnoreLatitude);
	bool canPlaceGoodyAt(ImprovementTypes eImprovement, int iX, int iY);

	// does all of the below "add..." functions:
	__declspec(dllexport) void addGameElements();

	void addLakes();
	__declspec(dllexport) void addRivers();
	void doRiver(CvPlot* pStartPlot, CardinalDirectionTypes eLastCardinalDirection=NO_CARDINALDIRECTION, CardinalDirectionTypes eOriginalCardinalDirection=NO_CARDINALDIRECTION, int iThisRiverID=-1);
	bool addRiver(CvPlot *pFreshWaterPlot);
	__declspec(dllexport) void addFeatures();
	void addFeaturesOnLand(); //WTP, ray, Randomize Features Map Option
	void addFeaturesOnWater();
	__declspec(dllexport) void addBonuses();
	void addUniqueBonusType(BonusTypes eBonusType);
	void addNonUniqueBonusType(BonusTypes eBonusType);
	__declspec(dllexport) void addGoodies();
	void addEurope();

	__declspec(dllexport) void eraseRivers();
	__declspec(dllexport) void eraseFeatures();
	void eraseFeaturesOnLand(); //WTP, ray, Randomize Features Map Option
	__declspec(dllexport) void eraseBonuses();
	__declspec(dllexport) void eraseGoodies();
	__declspec(dllexport) void eraseEurope();

	__declspec(dllexport) void generateRandomMap();

	void generatePlotTypes();
	void generateTerrain();

	void afterGeneration();

	void setPlotTypes(const int* paiPlotTypes);

protected:

	// Utility functions for roughenHeights()
	int getRiverValueAtPlot(CvPlot* pPlot);
	int calculateNumBonusesToAdd(BonusTypes eBonusType);

private:
	static CvMapGenerator* m_pInst;

};
#endif
