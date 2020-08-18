#pragma once

#include "afxwin.h"
#include "afxcmn.h"

#include "User.h"
#include "MFC_MedicAdminDoc.h"
#include "MainFrm.h"
#include "UserTreeView.h"



// CDeleteUserDlg �Ի���

class CDeleteUserDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDeleteUserDlg)

public:
	CDeleteUserDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDeleteUserDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_DELETE_USER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox m_uiType;
	CString m_uiAccount;
	afx_msg void OnBnClickedButton1();
	CListCtrl m_uiListCtrl;
	void UpdataListCtrl(CString Type = _T("���г�Ա"));
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	void UpdataTreeView(void);
};
