#pragma once
#ifndef CVDIPLOPARAMETERS_H
#define CVDIPLOPARAMETERS_H

#include "LinkedList.h"
//#include "CvStructs.h"
#include "FVariableSystem.h"

class CvDiploParameters
{
public:
	__declspec(dllexport) CvDiploParameters(PlayerTypes ePlayer = NO_PLAYER);
	__declspec(dllexport) virtual ~CvDiploParameters();

	__declspec(dllexport) void setWhoTalkingTo(PlayerTypes eWhoTalkingTo);
	__declspec(dllexport) PlayerTypes getWhoTalkingTo() const;
	__declspec(dllexport) void setDiploComment(DiploCommentTypes eCommentType);
	__declspec(dllexport) void addDiploCommentVariable(const wchar *szArg);
	__declspec(dllexport) void addDiploCommentVariable(int iArg);
	__declspec(dllexport) void addDiploCommentVariable(const FVariable& var);

	__declspec(dllexport) DiploCommentTypes getDiploComment() const;
	__declspec(dllexport) void setOurOfferList(const CLinkList<TradeData>& ourOffer);
	__declspec(dllexport) const CLinkList<TradeData>& getOurOfferList() const;
	__declspec(dllexport) void setTheirOfferList(const CLinkList<TradeData>& theirOffer);
	__declspec(dllexport) const CLinkList<TradeData>& getTheirOfferList() const;
	__declspec(dllexport) void setRenegotiate(bool bValue);
	__declspec(dllexport) bool getRenegotiate() const;
	__declspec(dllexport) void setAIContact(bool bValue);
	__declspec(dllexport) bool getAIContact() const;
	__declspec(dllexport) void setPendingDelete(bool bPending);
	__declspec(dllexport) bool getPendingDelete() const;
	__declspec(dllexport) void setData(int iData);
	__declspec(dllexport) int getData() const;
	__declspec(dllexport) void setHumanDiplo(bool bValue);
	__declspec(dllexport) bool getHumanDiplo() const;
	__declspec(dllexport) void setOurOffering(bool bValue);
	__declspec(dllexport) bool getOurOffering() const;
	__declspec(dllexport) void setTheirOffering(bool bValue);
	__declspec(dllexport) bool getTheirOffering() const;
	__declspec(dllexport) void setChatText(const wchar* szText);
	__declspec(dllexport) const wchar* getChatText() const;
	__declspec(dllexport) const std::vector<FVariable>& getDiploCommentArgs() const { return m_DiploCommentArgs; }
	__declspec(dllexport) const IDInfo& getTransport() const;
	__declspec(dllexport) void setTransport(const IDInfo& kTransport);
	__declspec(dllexport) const IDInfo& getCity() const;
	__declspec(dllexport) void setCity(const IDInfo& kCity);

	__declspec(dllexport) void read(FDataStreamBase& stream);
	__declspec(dllexport) void write(FDataStreamBase& stream) const;

	void read(CvSavegameReader& reader);
	void write(CvSavegameWriter& writer) const;

	void resetSavedData();

private:
	PlayerTypes m_eWhoTalkingTo;
	DiploCommentTypes m_eCommentType;
	CLinkList<TradeData> m_OurOffer;
	CLinkList<TradeData> m_TheirOffer;
	bool m_bRenegotiate;
	bool m_bAIContact;
	bool m_bPendingDelete;
	int m_iData;
	bool m_bHumanDiplo;
	bool m_bOurOffering;
	bool m_bTheirOffering;
	CvWString m_szChatText;
	std::vector<FVariable> m_DiploCommentArgs;
	IDInfo m_kTransport;
	IDInfo m_kCity;
};

#endif
