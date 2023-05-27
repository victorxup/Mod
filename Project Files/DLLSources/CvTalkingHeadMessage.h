#pragma once

#ifndef TALKINGHEADMESSAGE_H
#define TALKINGHEADMESSAGE_H
class CvSavegameReader;
class CvSavegameWriter;

class CvTalkingHeadMessage
{
public:
	__declspec(dllexport) CvTalkingHeadMessage(int iMessageTurn = 0, int iLen = 0, LPCWSTR pszDesc = nullptr, LPCTSTR pszSound = nullptr, InterfaceMessageTypes eType = MESSAGE_TYPE_INFO, LPCTSTR icon = nullptr, ColorTypes eColor = NO_COLOR, int iX = -1, int iY = -1, bool bShowOffScreenArrows = false, bool bShowOnScreenArrows = false);
	__declspec(dllexport) virtual ~CvTalkingHeadMessage(void);

	void read(CvSavegameReader& reader);
	void write(CvSavegameWriter& writer) const;

	void resetSavedData();

	// Accessors
	__declspec(dllexport) const wchar* getDescription() const;
	void setDescription(CvWString pszDescription);
	__declspec(dllexport) const CvString& getSound() const;
	void setSound(LPCTSTR pszSound);
	__declspec(dllexport) const CvString& getIcon() const;
	void setIcon(LPCTSTR pszIcon);
	__declspec(dllexport) int getLength() const;
	__declspec(dllexport) void setLength(int iLength);
	__declspec(dllexport) ColorTypes getFlashColor() const;
	void setFlashColor(ColorTypes eColor);
	__declspec(dllexport) int getX() const;
	void setX(int i);
	__declspec(dllexport) int getY() const;
	void setY(int i);
	__declspec(dllexport) bool getOffScreenArrows() const;
	void setOffScreenArrows(bool bArrows);
	__declspec(dllexport) bool getOnScreenArrows() const;
	void setOnScreenArrows(bool bArrows);
	__declspec(dllexport) int getTurn() const;
	void setTurn(int iTurn);
	__declspec(dllexport) InterfaceMessageTypes getMessageType() const;
	void setMessageType(InterfaceMessageTypes eType);
	__declspec(dllexport) ChatTargetTypes getTarget() const;
	__declspec(dllexport) void setTarget(ChatTargetTypes eType);
	__declspec(dllexport) PlayerTypes getFromPlayer() const;
	__declspec(dllexport) void setFromPlayer(PlayerTypes eFromPlayer);
	__declspec(dllexport) bool getShown() const;
	__declspec(dllexport) void setShown(bool bShown);

	int getExpireTurn();


protected:
	CvWString m_szDescription;
	CvString m_szSound;
	CvString m_szIcon;
	int m_iLength;
	ColorTypes m_eFlashColor;
	int m_iFlashX;
	int m_iFlashY;
	bool m_bOffScreenArrows;
	bool m_bOnScreenArrows;
	int m_iTurn;
	InterfaceMessageTypes m_eMessageType;
	PlayerTypes m_eFromPlayer;
	ChatTargetTypes m_eTarget;
	bool m_bShown;

};

#endif
