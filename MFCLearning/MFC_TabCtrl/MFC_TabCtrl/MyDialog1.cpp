// MyDialog1.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_TabCtrl.h"
#include "MyDialog1.h"
#include "afxdialogex.h"


// MyDialog1 对话框

IMPLEMENT_DYNAMIC(MyDialog1, CDialogEx)

MyDialog1::MyDialog1(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyDialog1::IDD, pParent)
{

}

MyDialog1::~MyDialog1()
{
}

void MyDialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDialog1, CDialogEx)
END_MESSAGE_MAP()


// MyDialog1 消息处理程序
