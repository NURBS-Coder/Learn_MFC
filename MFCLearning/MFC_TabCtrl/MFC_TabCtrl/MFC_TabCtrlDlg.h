
// MFC_TabCtrlDlg.h : 头文件
//

#pragma once
#include "tabsheet.h"

#include "MyDialog1.h"
#include "MyDialog2.h"

// CMFC_TabCtrlDlg 对话框
class CMFC_TabCtrlDlg : public CDialogEx
{
// 构造
public:
	CMFC_TabCtrlDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFC_TABCTRL_DIALOG };

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
	CTabSheet m_TabCtrl;

	MyDialog1 MyDialog1;
	MyDialog2 MyDialog2;
};
