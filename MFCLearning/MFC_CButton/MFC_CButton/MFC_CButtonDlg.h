
// MFC_CButtonDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "mybutton.h"


// CMFC_CButtonDlg �Ի���
class CMFC_CButtonDlg : public CDialogEx
{
// ����
public:
	CMFC_CButtonDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC_CBUTTON_DIALOG };

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
	CButton m_CButton;
	afx_msg void OnBnClickedButton1();
	MyButton m_MyButton;
};
