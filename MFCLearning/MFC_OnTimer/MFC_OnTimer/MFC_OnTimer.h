
// MFC_OnTimer.h : MFC_OnTimer Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFC_OnTimerApp:
// �йش����ʵ�֣������ MFC_OnTimer.cpp
//

class CMFC_OnTimerApp : public CWinAppEx
{
public:
	CMFC_OnTimerApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_OnTimerApp theApp;
