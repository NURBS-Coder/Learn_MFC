
// MFC_OtherButtonDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMFC_OtherButtonDlg �Ի���
class CMFC_OtherButtonDlg : public CDialogEx
{
// ����
public:
	CMFC_OtherButtonDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC_OTHERBUTTON_DIALOG };

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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CButton m_CheckBox;
};