
// MFC_PicWatch.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC_PicWatchApp:
// �йش����ʵ�֣������ MFC_PicWatch.cpp
//

class CMFC_PicWatchApp : public CWinApp
{
public:
	CMFC_PicWatchApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_PicWatchApp theApp;