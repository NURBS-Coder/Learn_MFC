
// MFC_CEdit.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC_CEditApp:
// �йش����ʵ�֣������ MFC_CEdit.cpp
//

class CMFC_CEditApp : public CWinApp
{
public:
	CMFC_CEditApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_CEditApp theApp;