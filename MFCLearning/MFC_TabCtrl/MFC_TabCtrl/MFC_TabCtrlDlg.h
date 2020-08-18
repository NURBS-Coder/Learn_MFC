
// MFC_TabCtrlDlg.h : ͷ�ļ�
//

#pragma once
#include "tabsheet.h"

#include "MyDialog1.h"
#include "MyDialog2.h"

// CMFC_TabCtrlDlg �Ի���
class CMFC_TabCtrlDlg : public CDialogEx
{
// ����
public:
	CMFC_TabCtrlDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC_TABCTRL_DIALOG };

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
	CTabSheet m_TabCtrl;

	MyDialog1 MyDialog1;
	MyDialog2 MyDialog2;
};
