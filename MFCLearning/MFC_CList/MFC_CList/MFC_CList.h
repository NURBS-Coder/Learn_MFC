
// MFC_CList.h : MFC_CList Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFC_CListApp:
// �йش����ʵ�֣������ MFC_CList.cpp
//

class CMFC_CListApp : public CWinApp
{
public:
	CMFC_CListApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_CListApp theApp;
