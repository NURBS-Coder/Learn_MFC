#pragma once


// Clogin 对话框

class Clogin : public CDialogEx
{
	DECLARE_DYNAMIC(Clogin)

public:
	Clogin(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Clogin();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_UserName;
	CString m_Password;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
//	afx_msg void OnBnClickedButton4();
};
