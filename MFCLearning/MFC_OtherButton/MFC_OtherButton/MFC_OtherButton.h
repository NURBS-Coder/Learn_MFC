
// MFC_OtherButton.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC_OtherButtonApp:
// �йش����ʵ�֣������ MFC_OtherButton.cpp
//

class CMFC_OtherButtonApp : public CWinApp
{
public:
	CMFC_OtherButtonApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_OtherButtonApp theApp;