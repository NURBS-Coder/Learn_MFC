
// MFC_DocView.h : MFC_DocView Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFC_DocViewApp:
// �йش����ʵ�֣������ MFC_DocView.cpp
//

class CMFC_DocViewApp : public CWinApp
{
public:
	CMFC_DocViewApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_DocViewApp theApp;
