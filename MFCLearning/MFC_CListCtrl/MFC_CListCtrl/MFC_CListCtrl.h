
// MFC_CListCtrl.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC_CListCtrlApp:
// �йش����ʵ�֣������ MFC_CListCtrl.cpp
//

class CMFC_CListCtrlApp : public CWinApp
{
public:
	CMFC_CListCtrlApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_CListCtrlApp theApp;