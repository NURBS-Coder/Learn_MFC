#pragma once
#include "afxwin.h"

#include "MFC_MedicAdminDoc.h"
#include "MainFrm.h"
#include "MedicSet.h"
#include "MedicSearch.h"
#include "MedicListView.h"

// CSeekMTypeDlg 对话框

class CSeekMTypeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSeekMTypeDlg)

public:
	CSeekMTypeDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSeekMTypeDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_SEARCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CComboBox m_MedicType;
	afx_msg void OnCbnSelchangeCombo1();
};
