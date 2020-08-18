// MyDialog2.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_TabCtrl.h"
#include "MyDialog2.h"
#include "afxdialogex.h"


// MyDialog2 对话框

IMPLEMENT_DYNAMIC(MyDialog2, CDialogEx)

MyDialog2::MyDialog2(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyDialog2::IDD, pParent)
{

}

MyDialog2::~MyDialog2()
{
}

void MyDialog2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDialog2, CDialogEx)
END_MESSAGE_MAP()


// MyDialog2 消息处理程序
