
// MFC_DataBase.h : MFC_DataBase Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFC_DataBaseApp:
// �йش����ʵ�֣������ MFC_DataBase.cpp
//

class CMFC_DataBaseApp : public CWinApp
{
public:
	CMFC_DataBaseApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_DataBaseApp theApp;
