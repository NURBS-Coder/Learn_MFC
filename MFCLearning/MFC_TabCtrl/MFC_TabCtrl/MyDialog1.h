#pragma once


// MyDialog1 �Ի���

class MyDialog1 : public CDialogEx
{
	DECLARE_DYNAMIC(MyDialog1)

public:
	MyDialog1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDialog1();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
