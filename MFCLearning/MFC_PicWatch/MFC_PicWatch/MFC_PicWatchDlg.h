
// MFC_PicWatchDlg.h : ͷ�ļ�
//

#pragma once


// CMFC_PicWatchDlg �Ի���
class CMFC_PicWatchDlg : public CDialogEx
{
// ����
public:
	CMFC_PicWatchDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC_PICWATCH_DIALOG };

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

	CStatic *m_bmp;
public:
	afx_msg void OnBnClickedButton1();
	int m_PicIndex;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	bool m_isPlay;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
