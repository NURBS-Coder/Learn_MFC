
// MFC_CArchivePro.h : MFC_CArchivePro Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFC_CArchiveProApp:
// �йش����ʵ�֣������ MFC_CArchivePro.cpp
//

class CMFC_CArchiveProApp : public CWinAppEx
{
public:
	CMFC_CArchiveProApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_CArchiveProApp theApp;
