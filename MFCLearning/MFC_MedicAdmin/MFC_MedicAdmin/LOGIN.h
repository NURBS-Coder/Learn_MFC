#pragma once
#include "afxwin.h"


// CLOGIN 对话框

class CLOGIN : public CDialogEx
{
	DECLARE_DYNAMIC(CLOGIN)

public:
	CLOGIN(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLOGIN();

// 对话框数据
	enum { IDD = IDD_DIALOG_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
