
// MFC_PicWatchDlg.h : 头文件
//

#pragma once


// CMFC_PicWatchDlg 对话框
class CMFC_PicWatchDlg : public CDialogEx
{
// 构造
public:
	CMFC_PicWatchDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFC_PICWATCH_DIALOG };

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
