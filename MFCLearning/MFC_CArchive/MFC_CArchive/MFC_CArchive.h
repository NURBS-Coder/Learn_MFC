
// MFC_CArchive.h : MFC_CArchive Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFC_CArchiveApp:
// �йش����ʵ�֣������ MFC_CArchive.cpp
//

class CMFC_CArchiveApp : public CWinAppEx
{
public:
	CMFC_CArchiveApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_CArchiveApp theApp;
