#pragma once

#include "User.h"
#include "MFC_MedicAdminDoc.h"
#include "MainFrm.h"

// CChangePwdDlg �Ի���

class CChangePwdDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChangePwdDlg)

public:
	CChangePwdDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChangePwdDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_CHANGE_Pwn };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_uiNewPwd;
	CString m_uiOldPwd;
	CString m_uiSurePwd;
	CString m_uiAccount;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton1();
};
