
// MFC_ListBox.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC_ListBoxApp:
// �йش����ʵ�֣������ MFC_ListBox.cpp
//

class CMFC_ListBoxApp : public CWinApp
{
public:
	CMFC_ListBoxApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_ListBoxApp theApp;