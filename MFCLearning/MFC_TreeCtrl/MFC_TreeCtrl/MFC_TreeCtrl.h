
// MFC_TreeCtrl.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC_TreeCtrlApp:
// �йش����ʵ�֣������ MFC_TreeCtrl.cpp
//

class CMFC_TreeCtrlApp : public CWinApp
{
public:
	CMFC_TreeCtrlApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_TreeCtrlApp theApp;