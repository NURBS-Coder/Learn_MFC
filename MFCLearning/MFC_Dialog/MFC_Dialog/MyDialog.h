#pragma once


// MyDialog 对话框

class MyDialog : public CDialogEx
{
	DECLARE_DYNAMIC(MyDialog)

public:
	MyDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG_Self };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
