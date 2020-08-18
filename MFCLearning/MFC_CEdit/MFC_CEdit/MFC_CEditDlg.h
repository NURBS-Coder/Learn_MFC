
// MFC_CEditDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CMFC_CEditDlg 对话框
class CMFC_CEditDlg : public CDialogEx
{
// 构造
public:
	CMFC_CEditDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFC_CEDIT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_Edit1;
	CEdit m_Edit2;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CString m_Edit1_string;
	CString m_Edit2_string;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
