#pragma once
#ifndef CVPOPUPINFO_H
#define CVPOPUPINFO_H

//#include "CvEnums.h"

class CvSavegameReader;
class CvSavegameWriter;

struct CvPopupButtonPython
{
	CvWString szText;
	CvString szArt;

	void read(CvSavegameReader& reader);
	void write(CvSavegameWriter& writer) const;
};

class CvPopupInfo
{
public:
	__declspec(dllexport) CvPopupInfo(ButtonPopupTypes eButtonPopupType = BUTTONPOPUP_TEXT, int iData1 = -1, int iData2 = -1, int iData3 = -1, int iFlags = 0, bool bOption1 = false, bool bOption2 = false);
	__declspec(dllexport) virtual ~CvPopupInfo();

	__declspec(dllexport) void read(FDataStreamBase& stream);
	__declspec(dllexport) void write(FDataStreamBase& stream) const;

	void read(CvSavegameReader& reader);
	void write(CvSavegameWriter& writer) const;

	void resetSavedData();

	__declspec(dllexport) const CvPopupInfo& operator=(const CvPopupInfo& other);

	// Accessors
	__declspec(dllexport) int getData1() const;
	__declspec(dllexport) int getData2() const;
	__declspec(dllexport) int getData3() const;
	__declspec(dllexport) int getFlags() const;
	__declspec(dllexport) bool getOption1() const;
	__declspec(dllexport) bool getOption2() const;
	__declspec(dllexport) ButtonPopupTypes getButtonPopupType() const;
	__declspec(dllexport) const CvWString& getText() const;
	__declspec(dllexport) bool getPendingDelete() const;
	__declspec(dllexport) const CvString& getOnFocusPythonCallback() const;
	__declspec(dllexport) const CvString& getOnClickedPythonCallback() const;
	__declspec(dllexport) const CvString& getPythonModule() const;
	__declspec(dllexport) const CvWString& getPythonButtonText(int i) const;
	__declspec(dllexport) const CvString& getPythonButtonArt(int i) const;
	__declspec(dllexport) int getNumPythonButtons() const;

	__declspec(dllexport) void setData1(int iValue);
	__declspec(dllexport) void setData2(int iValue);
	__declspec(dllexport) void setData3(int iValue);
	__declspec(dllexport) void setFlags(int iValue);
	__declspec(dllexport) void setOption1(bool bValue);
	__declspec(dllexport) void setOption2(bool bValue);
	__declspec(dllexport) void setButtonPopupType(ButtonPopupTypes eValue);
	__declspec(dllexport) void setText(const wchar* pszText);
	__declspec(dllexport) void setPendingDelete(bool bDelete);
	__declspec(dllexport) void setOnFocusPythonCallback(const char* szOnFocus);
	__declspec(dllexport) void setOnClickedPythonCallback(const char* szOnClicked);
	__declspec(dllexport) void setPythonModule(const char* szModule);
	__declspec(dllexport) void addPythonButton(const wchar* szText, const char* szArt);

protected:
	int m_iData1;
	int m_iData2;
	int m_iData3;
	int m_iFlags;
	bool m_bOption1;
	bool m_bOption2;
	ButtonPopupTypes m_eButtonPopupType;
	CvWString m_szText;

	std::vector<CvPopupButtonPython> m_aPythonButtons;
	CvString m_szOnFocusPythonCallback;
	CvString m_szOnClickedPythonCallback;
	CvString m_szPythonModule;

	bool m_bPendingDelete;
};


#endif
