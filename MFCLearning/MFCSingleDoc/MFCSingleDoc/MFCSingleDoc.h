
// MFCSingleDoc.h : MFCSingleDoc Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCSingleDocApp:
// �йش����ʵ�֣������ MFCSingleDoc.cpp
//

class CMFCSingleDocApp : public CWinApp
{
public:
	CMFCSingleDocApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCSingleDocApp theApp;
