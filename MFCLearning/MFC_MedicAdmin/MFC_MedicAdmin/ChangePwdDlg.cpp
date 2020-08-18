// ChangePwdDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_MedicAdmin.h"
#include "ChangePwdDlg.h"
#include "afxdialogex.h"


// CChangePwdDlg 对话框

IMPLEMENT_DYNAMIC(CChangePwdDlg, CDialogEx)

CChangePwdDlg::CChangePwdDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChangePwdDlg::IDD, pParent)
	, m_uiNewPwd(_T(""))
	, m_uiOldPwd(_T(""))
	, m_uiSurePwd(_T(""))
	, m_uiAccount(_T(""))
{

}

CChangePwdDlg::~CChangePwdDlg()
{
}

void CChangePwdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, m_uiNewPwd);
	DDX_Text(pDX, IDC_EDIT2, m_uiOldPwd);
	DDX_Text(pDX, IDC_EDIT4, m_uiSurePwd);
	DDX_Text(pDX, IDC_EDIT1, m_uiAccount);
}


BEGIN_MESSAGE_MAP(CChangePwdDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CChangePwdDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON2, &CChangePwdDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDCANCEL, &CChangePwdDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &CChangePwdDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CChangePwdDlg 消息处理程序


void CChangePwdDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}


BOOL CChangePwdDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此添加额外的初始化

	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	CMFC_MedicAdminDoc *pDoc =(CMFC_MedicAdminDoc*)pFrame->GetActiveDocument();

	CUser *pUser = pDoc->GetUser();

	m_uiAccount = pUser->GetAccount();


	UpdateData(FALSE);



	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CChangePwdDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMFC_MedicAdminDoc *pDoc =(CMFC_MedicAdminDoc*)pFrame->GetActiveDocument();
	CUser *pUser = pDoc->GetUser();

	UpdateData(TRUE);

	int ret = pUser->ChangePwd(m_uiOldPwd,m_uiNewPwd,m_uiSurePwd);
	switch (ret)
	{
	case -2:
		MessageBox(_T("内容不能为空！"));
		break;
	case -3:
		MessageBox(_T("新旧密码不能相同！"));
		break;
	case -4:
		MessageBox(_T("两次输入新密码不一致！"));
		break;
	case -5:
		MessageBox(_T("不能更改此用户！"));
		break;
	case -6:
		MessageBox(_T("更新失败！"));
		break;
	case -7:
		MessageBox(_T("旧密码不正确！"));
		break;
	default:
		MessageBox(_T("密码更改成功！"));
		break;
	}


}

void CChangePwdDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	CDialogEx::OnCancel();

}


void CChangePwdDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}



