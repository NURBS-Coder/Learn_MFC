
// MFC_ListBoxDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CMFC_ListBoxDlg 对话框
class CMFC_ListBoxDlg : public CDialogEx
{
// 构造
public:
	CMFC_ListBoxDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFC_LISTBOX_DIALOG };

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
	CString m_str;
	CListBox m_ListBox;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton2();
	CComboBox m_ComboBox;
	afx_msg void OnBnClickedButton4();
	int m_int;
	CScrollBar m_SBar;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
