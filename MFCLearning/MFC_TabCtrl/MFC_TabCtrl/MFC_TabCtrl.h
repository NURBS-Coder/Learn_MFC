
// MFC_TabCtrl.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC_TabCtrlApp:
// �йش����ʵ�֣������ MFC_TabCtrl.cpp
//

class CMFC_TabCtrlApp : public CWinApp
{
public:
	CMFC_TabCtrlApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_TabCtrlApp theApp;