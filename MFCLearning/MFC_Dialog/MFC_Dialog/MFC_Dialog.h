
// MFC_Dialog.h : MFC_Dialog Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFC_DialogApp:
// �йش����ʵ�֣������ MFC_Dialog.cpp
//

class CMFC_DialogApp : public CWinAppEx
{
public:
	CMFC_DialogApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_DialogApp theApp;
