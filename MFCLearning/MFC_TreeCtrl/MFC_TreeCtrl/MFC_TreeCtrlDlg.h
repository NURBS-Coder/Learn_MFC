
// MFC_TreeCtrlDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"


// CMFC_TreeCtrlDlg 对话框
class CMFC_TreeCtrlDlg : public CDialogEx
{
// 构造
public:
	CMFC_TreeCtrlDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFC_TREECTRL_DIALOG };

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


private:
	HICON icon[4];
	CImageList m_imagelist;		//图像列表
public:
	CTreeCtrl m_TreeCtrl;
};
