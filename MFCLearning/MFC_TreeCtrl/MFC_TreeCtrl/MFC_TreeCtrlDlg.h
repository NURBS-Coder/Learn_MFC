
// MFC_TreeCtrlDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// CMFC_TreeCtrlDlg �Ի���
class CMFC_TreeCtrlDlg : public CDialogEx
{
// ����
public:
	CMFC_TreeCtrlDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC_TREECTRL_DIALOG };

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


private:
	HICON icon[4];
	CImageList m_imagelist;		//ͼ���б�
public:
	CTreeCtrl m_TreeCtrl;
};
