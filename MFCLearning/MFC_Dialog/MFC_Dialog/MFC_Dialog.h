
// MFC_Dialog.h : MFC_Dialog 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CMFC_DialogApp:
// 有关此类的实现，请参阅 MFC_Dialog.cpp
//

class CMFC_DialogApp : public CWinAppEx
{
public:
	CMFC_DialogApp();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_DialogApp theApp;
