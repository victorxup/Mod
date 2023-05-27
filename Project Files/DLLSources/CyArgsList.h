#pragma once

#ifndef CyArgsList_h
#define CyArgsList_h

//
// type for input args to python functions
//
class CyArgsList
{
public:
	enum
	{
		MAX_CY_ARGS=20
	};
	__declspec(dllexport) CyArgsList() : m_iCnt(0) {}
	__declspec(dllexport) void add(int i);
	__declspec(dllexport) void add(uint ui) { add((int)ui);	}
	__declspec(dllexport) void add(float f);
	__declspec(dllexport) void add(const char* s);					// null-terminated string
	__declspec(dllexport) void add(const wchar* s);					// null-terminated widestring
	__declspec(dllexport) void add(const char* s, int iLength);		// makes a data string
	__declspec(dllexport) void add(const byte* s, int iLength);		// makes a list
	__declspec(dllexport) void add(const int* s, int iLength);		// makes a list
	__declspec(dllexport) void add(const float* s, int iLength);		// makes a list
	__declspec(dllexport) void add(void* p);
	__declspec(dllexport) void* makeFunctionArgs();
	__declspec(dllexport) int size() const { return m_iCnt;	}
	__declspec(dllexport) void push_back(void* p) { FAssertMsg(m_iCnt<MAX_CY_ARGS, "increase cyArgsList::MAX_CY_ARGS"); m_aList[m_iCnt++] = p; }
	__declspec(dllexport) void clear() { m_iCnt=0;	}
protected:
	void* m_aList[MAX_CY_ARGS];
	int m_iCnt;
};

#endif	// CyArgsList_h
