
// MFC_CEditDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMFC_CEditDlg �Ի���
class CMFC_CEditDlg : public CDialogEx
{
// ����
public:
	CMFC_CEditDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC_CEDIT_DIALOG };

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
	CEdit m_Edit1;
	CEdit m_Edit2;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CString m_Edit1_string;
	CString m_Edit2_string;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
