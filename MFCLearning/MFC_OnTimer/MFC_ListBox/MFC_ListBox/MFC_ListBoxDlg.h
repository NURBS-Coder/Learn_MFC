
// MFC_ListBoxDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMFC_ListBoxDlg �Ի���
class CMFC_ListBoxDlg : public CDialogEx
{
// ����
public:
	CMFC_ListBoxDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC_LISTBOX_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_Edit;
	CListBox m_ListBox;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	CComboBox m_CComboBox;
	int m_Pos;
	CScrollBar m_SBar;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult);
};
