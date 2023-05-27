#pragma once

// game.h

#ifndef CIV4_INITCORE_H
#define CIV4_INITCORE_H

//#include "CvEnums.h"

#define FASSERT_BOUNDS(lower,upper,index,fnString)\
	if (index < lower)\
	{\
		char acOut[256];\
		sprintf(acOut, "Index in %s expected to be >= %d", fnString, lower);\
		FAssertMsg(index >= lower, acOut);\
	}\
	else if (index >= upper)\
	{\
		char acOut[256];\
		sprintf(acOut, "Index in %s expected to be < %d", fnString, upper);\
		FAssertMsg(index < upper, acOut);\
	}

class CvInitCore
{

public:
	CvInitCore();
	virtual ~CvInitCore();

	__declspec(dllexport) void init(GameMode eMode);

protected:

	void uninit();
	void reset(GameMode eMode);

	void setDefaults();

	bool checkBounds( int iValue, int iLower, int iUpper ) const;

public:

	// **************************
	// Applications of data
	// **************************
	__declspec(dllexport) bool getHuman(PlayerTypes eID) const;
	int getNumHumans() const;

	__declspec(dllexport) int getNumDefinedPlayers() const;

	__declspec(dllexport) bool getMultiplayer() const;
	__declspec(dllexport) bool getNewGame() const;
	__declspec(dllexport) bool getSavedGame() const;
	__declspec(dllexport) bool getScenario() const;
	__declspec(dllexport) bool getGameMultiplayer() const { return (getMultiplayer() || getPitboss() || getPbem() || getHotseat()); }

	__declspec(dllexport) bool getPitboss() const;
	__declspec(dllexport) bool getHotseat() const;
	__declspec(dllexport) bool getPbem() const;

	__declspec(dllexport) bool getSlotVacant(PlayerTypes eID) const;
	__declspec(dllexport) PlayerTypes getAvailableSlot();
	__declspec(dllexport) void reassignPlayer(PlayerTypes eOldID, PlayerTypes eNewID);

	__declspec(dllexport) void closeInactiveSlots();
	__declspec(dllexport) void reopenInactiveSlots();

	void resetGame();
	__declspec(dllexport) void resetGame(CvInitCore * pSource, bool bClear = true, bool bSaveGameType = false);
	__declspec(dllexport) void resetPlayers();
	__declspec(dllexport) void resetPlayers(CvInitCore * pSource, bool bClear = true, bool bSaveSlotInfo = false);
	void resetPlayer(PlayerTypes eID);
	__declspec(dllexport) void resetPlayer(PlayerTypes eID, CvInitCore * pSource, bool bClear = true, bool bSaveSlotInfo = false);

	// **************************
	// Member access
	// **************************
	const CvWString & getGameName() const	{ return m_szGameName; }
	__declspec(dllexport) void setGameName(const CvWString & szGameName)	{ m_szGameName = szGameName; }

	const CvWString & getGamePassword() const	{ return m_szGamePassword; }
	__declspec(dllexport) void setGamePassword(const CvWString & szGamePassword)	{ m_szGamePassword = szGamePassword; }

	const CvWString & getAdminPassword() const	{ return m_szAdminPassword; }
	__declspec(dllexport) void setAdminPassword(const CvWString & szAdminPassword, bool bEncrypt = true);

	__declspec(dllexport) CvWString getMapScriptName() const;
	__declspec(dllexport) void setMapScriptName(const CvWString & szMapScriptName);
	__declspec(dllexport) bool getWBMapScript() const;

	bool getWBMapNoPlayers() const { return m_bWBMapNoPlayers; }
	void setWBMapNoPlayers(bool bValue)	{ m_bWBMapNoPlayers = bValue; }

	WorldSizeTypes getWorldSize() const	{ return m_eWorldSize; }
	void setWorldSize(WorldSizeTypes eWorldSize)	{ m_eWorldSize = eWorldSize; }
	__declspec(dllexport) void setWorldSize(const CvWString & szWorldSize);
	__declspec(dllexport) const CvWString & getWorldSizeKey(CvWString & szBuffer) const;

	ClimateTypes getClimate() const	{ return m_eClimate; }
	void setClimate(ClimateTypes eClimate)	{ m_eClimate = eClimate; }
	__declspec(dllexport) void setClimate(const CvWString & szClimate);
	__declspec(dllexport) const CvWString & getClimateKey(CvWString & szBuffer) const;

	SeaLevelTypes getSeaLevel() const	{ return m_eSeaLevel; }
	void setSeaLevel(SeaLevelTypes eSeaLevel)	{ m_eSeaLevel = eSeaLevel; }
	__declspec(dllexport) void setSeaLevel(const CvWString & szSeaLevel);
	__declspec(dllexport) const CvWString & getSeaLevelKey(CvWString & szBuffer) const;

	EraTypes getEra() const	{ return m_eEra; }
	void setEra(EraTypes eEra)	{ m_eEra = eEra; }
	__declspec(dllexport) void setEra(const CvWString & szEra);
	__declspec(dllexport) const CvWString & getEraKey(CvWString & szBuffer) const;

	GameSpeedTypes getGameSpeed() const	{ return m_eGameSpeed; }
	void setGameSpeed(GameSpeedTypes eGameSpeed)	{ m_eGameSpeed = eGameSpeed; }
	__declspec(dllexport) void setGameSpeed(const CvWString & szGameSpeed);
	__declspec(dllexport) const CvWString & getGameSpeedKey(CvWString & szBuffer) const;

	TurnTimerTypes getTurnTimer() const	{ return m_eTurnTimer; }
	void setTurnTimer(TurnTimerTypes eTurnTimer)	{ m_eTurnTimer = eTurnTimer; }
	void setTurnTimer(const CvWString & szTurnTimer);
	const CvWString & getTurnTimerKey(CvWString & szBuffer) const;

	CalendarTypes getCalendar() const	{ return m_eCalendar; }
	void setCalendar(CalendarTypes eCalendar)	{ m_eCalendar = eCalendar; }
	void setCalendar(const CvWString & szCalendar);
	const CvWString & getCalendarKey(CvWString & szBuffer) const;


	int getNumCustomMapOptions() const	{ return m_iNumCustomMapOptions; }
	int getNumHiddenCustomMapOptions() const	{ return m_iNumHiddenCustomMapOptions; }

	__declspec(dllexport) const CustomMapOptionTypes * getCustomMapOptions() const	{ return m_aeCustomMapOptions; }
	__declspec(dllexport) void setCustomMapOptions(int iNumCustomMapOptions, const CustomMapOptionTypes * aeCustomMapOptions);

	__declspec(dllexport) CustomMapOptionTypes getCustomMapOption(int iOptionID) const;
	__declspec(dllexport) void setCustomMapOption(int iOptionID, CustomMapOptionTypes eCustomMapOption);


	__declspec(dllexport) int getNumVictories() const	{ return m_iNumVictories; }

	__declspec(dllexport) const bool * getVictories() const	{ return m_abVictories; }
	__declspec(dllexport) void setVictories(int iNumVictories, const bool * abVictories);

	__declspec(dllexport) bool getVictory(VictoryTypes eVictoryID) const;
	__declspec(dllexport) void setVictory(VictoryTypes eVictoryID, bool bVictory);


	const bool * getOptions() const	{ return m_abOptions; }
	__declspec(dllexport) bool getOption(GameOptionTypes eIndex) const;
	__declspec(dllexport) void setOption(GameOptionTypes eIndex, bool bOption);

	const bool * getMPOptions() const	{ return m_abMPOptions; }
	__declspec(dllexport) bool getMPOption(MultiplayerOptionTypes eIndex) const;
	__declspec(dllexport) void setMPOption(MultiplayerOptionTypes eIndex, bool bMPOption);

	bool getStatReporting() const	{ return m_bStatReporting; }
	void setStatReporting(bool bStatReporting)	{ m_bStatReporting = bStatReporting; }

	const bool * getForceControls() const	{ return m_abForceControls; }
	__declspec(dllexport) bool getForceControl(ForceControlTypes eIndex) const;
	__declspec(dllexport) void setForceControl(ForceControlTypes eIndex, bool bForceControl);


	int getGameTurn() const	{ return m_iGameTurn; }
	void setGameTurn(int iGameTurn)	{ m_iGameTurn = iGameTurn; }

	int getMaxTurns() const	{ return m_iMaxTurns; }
	void setMaxTurns(int iMaxTurns)	{ m_iMaxTurns = iMaxTurns; }

	__declspec(dllexport) int getPitbossTurnTime() const	{ return m_iPitbossTurnTime; }
	__declspec(dllexport) void setPitbossTurnTime(int iPitbossTurnTime)	{ m_iPitbossTurnTime = iPitbossTurnTime; }

	int getTargetScore() const	{ return m_iTargetScore; }
	void setTargetScore(int iTargetScore)	{ m_iTargetScore = iTargetScore; }


	int getMaxCityElimination() const	{ return m_iMaxCityElimination; }
	void setMaxCityElimination(int iMaxCityElimination)	{ m_iMaxCityElimination = iMaxCityElimination; }

	int getNumAdvancedStartPoints() const	{ return m_iNumAdvancedStartPoints; }
	void setNumAdvancedStartPoints(int iNumPoints)	{ m_iNumAdvancedStartPoints = iNumPoints; }

	__declspec(dllexport) unsigned int getSyncRandSeed() const	{ return m_uiSyncRandSeed; }
	__declspec(dllexport) void setSyncRandSeed(unsigned int uiSyncRandSeed)	{ m_uiSyncRandSeed = uiSyncRandSeed; }

	__declspec(dllexport) unsigned int getMapRandSeed() const	{ return m_uiMapRandSeed; }
	__declspec(dllexport) void setMapRandSeed(unsigned int uiMapRandSeed)	{ m_uiMapRandSeed = uiMapRandSeed; }

	PlayerTypes getActivePlayer() const	{ return m_eActivePlayer; }
	__declspec(dllexport) void setActivePlayer(PlayerTypes eActivePlayer);

	__declspec(dllexport) GameType getType() const	{ return m_eType; }
	__declspec(dllexport) void setType(GameType eType);
	__declspec(dllexport) void setType(const CvWString & szType);

	GameMode getMode() const	{ return m_eMode; }
	__declspec(dllexport) void setMode(GameMode eMode);


	__declspec(dllexport) const CvWString & getLeaderName(PlayerTypes eID, uint uiForm = 0) const;
	__declspec(dllexport) void setLeaderName(PlayerTypes eID, const CvWString & szLeaderName);
	__declspec(dllexport) const CvWString & getLeaderNameKey(PlayerTypes eID) const;

	__declspec(dllexport) const CvWString & getCivDescription(PlayerTypes eID, uint uiForm = 0) const;
	__declspec(dllexport) void setCivDescription(PlayerTypes eID, const CvWString & szCivDescription);
	__declspec(dllexport) const CvWString & getCivDescriptionKey(PlayerTypes eID) const;

	__declspec(dllexport) const CvWString & getCivShortDesc(PlayerTypes eID, uint uiForm = 0) const;
	__declspec(dllexport) void setCivShortDesc(PlayerTypes eID, const CvWString & szCivShortDesc);
	__declspec(dllexport) const CvWString & getCivShortDescKey(PlayerTypes eID) const;

	__declspec(dllexport) const CvWString & getCivAdjective(PlayerTypes eID, uint uiForm = 0) const;
	__declspec(dllexport) void setCivAdjective(PlayerTypes eID, const CvWString & szCivAdjective);
	__declspec(dllexport) const CvWString & getCivAdjectiveKey(PlayerTypes eID) const;

	__declspec(dllexport) const CvWString & getCivPassword(PlayerTypes eID) const;
	__declspec(dllexport) void setCivPassword(PlayerTypes eID, const CvWString & szCivPassword, bool bEncrypt = true);

	__declspec(dllexport) const CvString & getEmail(PlayerTypes eID) const;
	__declspec(dllexport) void setEmail(PlayerTypes eID, const CvString & szEmail);

	__declspec(dllexport) const CvString & getSmtpHost(PlayerTypes eID) const;
	__declspec(dllexport) void setSmtpHost(PlayerTypes eID, const CvString & szHost);

	__declspec(dllexport) CivilizationTypes getCiv(PlayerTypes eID) const;
	__declspec(dllexport) void setCiv(PlayerTypes eID, CivilizationTypes eCiv);

	__declspec(dllexport) LeaderHeadTypes getLeader(PlayerTypes eID) const;
	__declspec(dllexport) void setLeader(PlayerTypes eID, LeaderHeadTypes eLeader);

	__declspec(dllexport) TeamTypes getTeam(PlayerTypes eID) const;
	__declspec(dllexport) void setTeam(PlayerTypes eID, TeamTypes eTeam);

	__declspec(dllexport) HandicapTypes getHandicap(PlayerTypes eID) const;
	__declspec(dllexport) void setHandicap(PlayerTypes eID, HandicapTypes eHandicap);

	__declspec(dllexport) PlayerColorTypes getColor(PlayerTypes eID) const;
	__declspec(dllexport) void setColor(PlayerTypes eID, PlayerColorTypes eColor);

	__declspec(dllexport) ArtStyleTypes getArtStyle(PlayerTypes eID) const;
	__declspec(dllexport) void setArtStyle(PlayerTypes eID, ArtStyleTypes eArtStyle);


	__declspec(dllexport) SlotStatus getSlotStatus(PlayerTypes eID) const;
	__declspec(dllexport) void setSlotStatus(PlayerTypes eID, SlotStatus eSlotStatus);

	__declspec(dllexport) SlotClaim getSlotClaim(PlayerTypes eID) const;
	__declspec(dllexport) void setSlotClaim(PlayerTypes eID, SlotClaim eSlotClaim);


	__declspec(dllexport) bool getPlayableCiv(PlayerTypes eID) const;
	__declspec(dllexport) void setPlayableCiv(PlayerTypes eID, bool bPlayableCiv);

	__declspec(dllexport) bool getMinorNationCiv(PlayerTypes eID) const;
	__declspec(dllexport) void setMinorNationCiv(PlayerTypes eID, bool bMinorNationCiv);


	__declspec(dllexport) int getNetID(PlayerTypes eID) const;
	__declspec(dllexport) void setNetID(PlayerTypes eID, int iNetID);

	__declspec(dllexport) bool getReady(PlayerTypes eID) const;
	__declspec(dllexport) void setReady(PlayerTypes eID, bool bReady);

	__declspec(dllexport) const CvString & getPythonCheck(PlayerTypes eID) const;
	__declspec(dllexport) void setPythonCheck(PlayerTypes eID, const CvString & iPythonCheck);

	__declspec(dllexport) const CvString & getXMLCheck(PlayerTypes eID) const;
	__declspec(dllexport) void setXMLCheck(PlayerTypes eID, const CvString & iXMLCheck);

	__declspec(dllexport) void resetAdvancedStartPoints();

	__declspec(dllexport) int getMaxEuropePlayers() const;

	virtual void read(FDataStreamBase* pStream);
	virtual void write(FDataStreamBase* pStream);

protected:

	template<typename T>
	int read(CvSavegameReader& reader, bool*& pArray, bool bAllocate, T eLength);
	template<typename T>
	void write(CvSavegameWriter& writer, bool* pArray, T eLength);

	void clearCustomMapOptions();
	void refreshCustomMapOptions();

	void clearVictories();
	void refreshVictories();

	// ***
	// CORE GAME INIT DATA
	// ***

	// Game type
	GameType m_eType;

	// Descriptive strings about game and map
	CvWString m_szGameName;
	CvWString m_szGamePassword;
	CvWString m_szAdminPassword;
	CvWString m_szMapScriptName;

	bool m_bWBMapNoPlayers;

	// Standard game parameters
	WorldSizeTypes m_eWorldSize;
	ClimateTypes m_eClimate;
	SeaLevelTypes m_eSeaLevel;
	EraTypes m_eEra;
	GameSpeedTypes m_eGameSpeed;
	TurnTimerTypes m_eTurnTimer;
	CalendarTypes m_eCalendar;

	// Map-specific custom parameters
	int m_iNumCustomMapOptions;
	int m_iNumHiddenCustomMapOptions;
	CustomMapOptionTypes * m_aeCustomMapOptions;

	// Standard game options
	bool* m_abOptions;
	bool* m_abMPOptions;
	bool m_bStatReporting;

	bool* m_abForceControls;

	// Dynamic victory condition setting
	int m_iNumVictories;
	bool * m_abVictories;

	// Game turn mgmt
	int m_iGameTurn;
	int m_iMaxTurns;
	int m_iPitbossTurnTime;
	int m_iTargetScore;

	// Number of city eliminations permitted
	int m_iMaxCityElimination;

	int m_iNumAdvancedStartPoints;

	// Unsaved data
	unsigned int m_uiSyncRandSeed;
	unsigned int m_uiMapRandSeed;
	PlayerTypes m_eActivePlayer;
	GameMode m_eMode;

	// Temp var so we don't return locally scoped var
	mutable CvWString m_szTemp;
	mutable CvString m_szTempA;


	// ***
	// CORE PLAYER INIT DATA
	// ***

	// Civ details
	CvWString* m_aszLeaderName;
	CvWString* m_aszCivDescription;
	CvWString* m_aszCivShortDesc;
	CvWString* m_aszCivAdjective;
	CvWString* m_aszCivPassword;
	CvString* m_aszEmail;
	CvString* m_aszSmtpHost;

	CivilizationTypes* m_aeCiv;
	LeaderHeadTypes* m_aeLeader;
	TeamTypes* m_aeTeam;
	HandicapTypes* m_aeHandicap;
	PlayerColorTypes* m_aeColor;
	ArtStyleTypes* m_aeArtStyle;

	// Slot data
	SlotStatus* m_aeSlotStatus;
	SlotClaim* m_aeSlotClaim;

	// Civ flags
	bool* m_abPlayableCiv;
	bool* m_abMinorNationCiv;

	// Unsaved player data
	int* m_aiNetID;
	bool* m_abReady;

	CvString* m_aszPythonCheck;
	CvString* m_aszXMLCheck;
	mutable CvString m_szTempCheck;

protected:
	void showReadFailureMessage(char *szHeader, char* szMessage);
};

#endif
