
// MFC_MedicAdmin.h : MFC_MedicAdmin Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFC_MedicAdminApp:
// �йش����ʵ�֣������ MFC_MedicAdmin.cpp
//

class CMFC_MedicAdminApp : public CWinApp
{
public:
	CMFC_MedicAdminApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_MedicAdminApp theApp;
