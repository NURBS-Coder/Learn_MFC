// LOGIN.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_MedicAdmin.h"
#include "LOGIN.h"
#include "afxdialogex.h"
#include "MFC_MedicAdminDoc.h"
#include "MainFrm.h"
#include "User.h"

// CLOGIN 对话框

IMPLEMENT_DYNAMIC(CLOGIN, CDialogEx)

CLOGIN::CLOGIN(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLOGIN::IDD, pParent)
	, m_uiAccount(_T(""))
	, m_uiPwd(_T(""))
{

}

CLOGIN::~CLOGIN()
{
}

void CLOGIN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_Classification);
	DDX_Text(pDX, IDC_EDIT1, m_uiAccount);
	DDX_Text(pDX, IDC_EDIT2, m_uiPwd);
}


BEGIN_MESSAGE_MAP(CLOGIN, CDialogEx)
	ON_BN_CLICKED(IDOK, &CLOGIN::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CLOGIN::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK2, &CLOGIN::OnBnClickedOk2)
END_MESSAGE_MAP()


// CLOGIN 消息处理程序


void CLOGIN::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码



	//CDialogEx::OnOK();
}


void CLOGIN::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码

	exit(0);

	//CDialogEx::OnCancel();
}


void CLOGIN::OnBnClickedOk2()
{
	// TODO: 在此添加控件通知处理程序代码

	//不是视图类，不能直接GetDocument()

	//获取框架类指针
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();

	//获取文档类指针
	CMFC_MedicAdminDoc *pDoc = (CMFC_MedicAdminDoc*)pFrame->GetActiveDocument();

	//获取用户记录集
	CUserSet *pUserSet = pDoc->GetUserSet();

	//打开数据库
	if (!pUserSet->IsOpen())
	{
		pUserSet->Open();
	}

	//获取编辑区内容
	UpdateData(TRUE);

	//获取用户类别
	int index = m_Classification.GetCurSel();

	CString type;
	m_Classification.GetLBText(index,type);

	if (type.IsEmpty() || m_uiAccount.IsEmpty() ||m_uiPwd.IsEmpty())
	{
		MessageBox(_T("请输入登录信息"));
		return;
	}

#if 0

	//设置过滤条件
	CString SQL;
	SQL.Format(_T("account = '%s' and password = '%s' and classification = '%s'"),m_uiAccount,m_uiPwd,type);

	//过滤
	pUserSet->m_strFilter = SQL;

	//查询
	pUserSet->Requery();

	//判断有没有数据
	if (pUserSet->GetRecordCount() == 0)
	{
		MessageBox(_T("登录失败！"));
	}else{


		CDialogEx::OnCancel();
	}
#endif

	//CUser user;
	CUser *pUser = pDoc->GetUser();
	pUser->SetAllMember(m_uiAccount,m_uiPwd,type);
	pUser->SetUserSet(pUserSet);

	int ret = pUser->Login();
	if (ret == 0)
	{
		CDialogEx::OnCancel();
	}else if (ret == -2)
	{
		MessageBox(_T("登录失败！"));
	}
}


BOOL CLOGIN::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_Classification.SetCurSel(0);
	m_uiAccount=_T("abc");
	m_uiPwd=_T("250250");

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
}
