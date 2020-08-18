// Clogin.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_PicWatch.h"
#include "Clogin.h"
#include "afxdialogex.h"


// Clogin 对话框

IMPLEMENT_DYNAMIC(Clogin, CDialogEx)

Clogin::Clogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(Clogin::IDD, pParent)
	, m_UserName(_T(""))
	, m_Password(_T(""))
{

}

Clogin::~Clogin()
{
}

void Clogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_UserName);
	DDX_Text(pDX, IDC_EDIT2, m_Password);
}


BEGIN_MESSAGE_MAP(Clogin, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Clogin::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &Clogin::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Clogin::OnBnClickedCancel)
	//ON_BN_CLICKED(IDC_BUTTON4, &Clogin::OnBnClickedButton4)
END_MESSAGE_MAP()


// Clogin 消息处理程序


void Clogin::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	//判断用户名密码是否正确
	UpdateData(TRUE);
	if(m_UserName == _T("admin")&&m_Password == _T("123456"))
	{
		MessageBox(_T("登录成功！"),_T("提示"),MB_ICONINFORMATION);
		CDialogEx::OnOK();
	}else{
		MessageBox(_T("用户名或密码错误！"),_T("提示"),MB_ICONWARNING);
	}
}


void Clogin::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}


void Clogin::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	if(IDOK  == MessageBox(_T("确定要退出程序？"),_T("提示"),MB_OKCANCEL|MB_ICONQUESTION))
	{
		//退出进程
		exit(1);
	}
	//CDialogEx::OnCancel();
}


//void Clogin::OnBnClickedButton4()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	OnBnClickedCancel();
//}
