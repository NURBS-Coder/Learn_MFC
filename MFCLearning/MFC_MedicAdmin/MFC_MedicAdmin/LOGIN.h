#pragma once
#include "afxwin.h"


// CLOGIN �Ի���

class CLOGIN : public CDialogEx
{
	DECLARE_DYNAMIC(CLOGIN)

public:
	CLOGIN(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLOGIN();

// �Ի�������
	enum { IDD = IDD_DIALOG_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk2();
	CComboBox m_Classification;
	CString m_uiAccount;
	CString m_uiPwd;
	virtual BOOL OnInitDialog();
};
