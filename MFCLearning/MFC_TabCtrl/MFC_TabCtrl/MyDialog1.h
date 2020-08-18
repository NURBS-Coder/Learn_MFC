#pragma once


// MyDialog1 对话框

class MyDialog1 : public CDialogEx
{
	DECLARE_DYNAMIC(MyDialog1)

public:
	MyDialog1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDialog1();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
