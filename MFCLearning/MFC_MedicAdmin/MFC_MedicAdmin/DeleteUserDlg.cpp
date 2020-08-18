// DeleteUserDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_MedicAdmin.h"
#include "DeleteUserDlg.h"
#include "afxdialogex.h"


// CDeleteUserDlg 对话框

IMPLEMENT_DYNAMIC(CDeleteUserDlg, CDialogEx)

CDeleteUserDlg::CDeleteUserDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDeleteUserDlg::IDD, pParent)
	, m_uiAccount(_T(""))
{

}

CDeleteUserDlg::~CDeleteUserDlg()
{
}

void CDeleteUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_uiType);
	DDX_Text(pDX, IDC_EDIT1, m_uiAccount);
	DDX_Control(pDX, IDC_LIST1, m_uiListCtrl);
}


BEGIN_MESSAGE_MAP(CDeleteUserDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDeleteUserDlg::OnBnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDeleteUserDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDOK, &CDeleteUserDlg::OnBnClickedOk)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CDeleteUserDlg::OnNMClickList1)
END_MESSAGE_MAP()


// CDeleteUserDlg 消息处理程序
void CDeleteUserDlg::UpdataListCtrl(CString Type)
{
	//获取数据库记录集指针
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	//获取文档类指针
	CMFC_MedicAdminDoc *pDoc =(CMFC_MedicAdminDoc*)pFrame->GetActiveDocument();

	//获取用户记录集
	CUserSet *pUserSet = pDoc->GetUserSet();

	CString SQL;
	SQL.Format(_T("classification = '%s'"),Type);
	if(Type == _T("所有成员")){
		pUserSet->m_strFilter=_T("");
	}else{
		pUserSet->m_strFilter=SQL;
	}

	//查询
	pUserSet->Requery();

	//清空现在的列表
	m_uiListCtrl.DeleteAllItems();

	//CRecordset::GetRecordCount()  获取记录集总行数（除了表头）
	for (int i = 0; i < pUserSet->GetRecordCount(); i++)
	{
		CString str;
		str.Format(_T("%d"),i+1);
		m_uiListCtrl.InsertItem(i,str);

		int j = 1;
		str.Format(_T("%s"),pUserSet->m_classification);
		m_uiListCtrl.SetItemText(i,j++,str);

		str.Format(_T("%s"),pUserSet->m_account);
		m_uiListCtrl.SetItemText(i,j++,str);

		str.Format(_T("%s"),pUserSet->m_name);
		m_uiListCtrl.SetItemText(i,j++,str);

		str.Format(_T("%s"),pUserSet->m_password);
		m_uiListCtrl.SetItemText(i,j++,str);

		pUserSet->MoveNext();
	}

}


BOOL CDeleteUserDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此添加额外的初始化

	m_uiType.SetCurSel(3);

	//获取数据库记录集指针
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	//获取文档类指针
	CMFC_MedicAdminDoc *pDoc =(CMFC_MedicAdminDoc*)pFrame->GetActiveDocument();

	//获取用户记录集
	CUserSet *pUserSet = pDoc->GetUserSet();

	//打开数据库
	if (!pUserSet->IsOpen())
	{
		pUserSet->Open();
	}

	//设置风格，表格，选中全行
	m_uiListCtrl.SetExtendedStyle(m_uiListCtrl.GetExtendedStyle()
		|LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	

	//设置表头
	CString head[] = 
	{
		_T("排序"),_T("用户类别"),_T("用户账号"),_T("用户姓名"),_T("用户密码")
	};

	int n = sizeof(head)/sizeof(head[0]);

	for (int i = 0; i < n; i++)
	{
		m_uiListCtrl.InsertColumn(i,head[i],LVCFMT_LEFT,100);
	}

	//获取选中的筛选类型
	int index = m_uiType.GetCurSel();
	CString type ;
	m_uiType.GetLBText(index,type);

	if(type.IsEmpty()){
		MessageBox(_T("类别不能为空"));
		return TRUE;
	}

	UpdataListCtrl(type);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CDeleteUserDlg::UpdataTreeView(void)
{
	//获取数据库记录集指针
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	//获取文档类指针
	CMFC_MedicAdminDoc *pDoc =(CMFC_MedicAdminDoc*)pFrame->GetActiveDocument();

	//获取用户记录集
	CUserSet *pUserSet = pDoc->GetUserSet();

	//打开数据库
	if (!pUserSet->IsOpen())
	{
		pUserSet->Open();
	}

	//通过文档找到需要的树视图（一个文档对应多个视图，通过链表管理 ）
	CUserTreeView *pUserTreeView = NULL;

	//获取文档中第一个视图的位置
	POSITION pos = pDoc->GetFirstViewPosition();

	//遍历视图链表，寻找树视图
	while (pos != NULL)
	{
		//根据当前位置获取视图指针，并将位置下移
		CView *pView = pDoc->GetNextView(pos);

		//判断是不是寻找的树视图
		if (pView->IsKindOf(RUNTIME_CLASS(CUserTreeView)))
		{
			//类型转换：CView向其派生类转换
			pUserTreeView = (CUserTreeView *)pView;
			break;
		}
	}

	if(pUserTreeView == NULL)
	{
		return ;
	}

	//更新树控件

	//获取树视图中的树控件
	CTreeCtrl &treeCtrl = pUserTreeView->GetTreeCtrl();

	treeCtrl.DeleteAllItems();
	pUserSet->m_strFilter=_T("");

	//查询
	pUserSet->Requery();

	//遍历记录，添加在不同根节点下 (优化)
	CString str;
	CString type[] = {_T("管理员"),_T("售药员"),_T("医生")};

	//获取登录人信息
	CUser *pUser = pDoc->GetUser();
	HTREEITEM curuser = NULL;
	for (int i = 0; i < 3; i++)
	{
		//创建
		HTREEITEM root = treeCtrl.InsertItem(type[i],i,i,NULL);
		//筛选
		str.Format(_T("classification = '%s'"),type[i]);
		pUserSet->m_strFilter=str;
		//查询
		pUserSet->Requery();
		for (int i = 0; i < pUserSet->GetRecordCount(); i++)
		{
			if(pUser->GetAccount() == pUserSet->m_account)
			{
				str.Format(_T("[登录用户]%s(%s)"),pUserSet->m_account,pUserSet->m_name);
				curuser = treeCtrl.InsertItem(str,1,1,root);
			}else{
				str.Format(_T("%s(%s)"),pUserSet->m_account,pUserSet->m_name);
				treeCtrl.InsertItem(str,3,3,root);
			}
			pUserSet->MoveNext();
		}
	}
	//设置默认的选中项
	if(curuser != NULL)
	{
		treeCtrl.SelectItem(curuser);	//显示到选中的这一层节点
	}

}


void CDeleteUserDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);

	if(m_uiAccount.IsEmpty()){
		MessageBox(_T("请先选择用户！"));
		return;
	}

	//获取选中的筛选类型
	int index = m_uiType.GetCurSel();
	CString type ;
	m_uiType.GetLBText(index,type);

	if(type.IsEmpty()){
		MessageBox(_T("类别不能为空"));
		return;
	}

	//获取数据库记录集指针
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	//获取文档类指针
	CMFC_MedicAdminDoc *pDoc =(CMFC_MedicAdminDoc*)pFrame->GetActiveDocument();

	//获取当前登录用户数据
	CUser* pUser = pDoc->GetUser();

	//删除用户
	int ret = pUser->DelUser(m_uiAccount);
	switch (ret)
	{
	case -2:
		MessageBox(_T("内容不能为空！"));
		break;
	case -3:
		MessageBox(_T("不能删除登录用户！"));
		break;
	case -4:
		MessageBox(_T("没有此用户！"));
		break;
	case -5:
		MessageBox(_T("更新数据库失败！"));
		break;
	default:
		{
			//更新列表控件
			UpdataListCtrl(type);
			//更新树控件
			UpdataTreeView();
			MessageBox(_T("删除用户成功！"));
		}
		break;
	}

}

void CDeleteUserDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码

	//获取选中的筛选类型
	int index = m_uiType.GetCurSel();
	CString type ;
	m_uiType.GetLBText(index,type);

	if(type.IsEmpty()){
		MessageBox(_T("类别不能为空"));
	}

	UpdataListCtrl(type);

}


void CDeleteUserDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}


void CDeleteUserDlg::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	//转化类型，列表视图(结构体，里面有属性信息)
	NM_LISTVIEW *pList = (NM_LISTVIEW *)pNMHDR;

	//行和l列
	int i = pList->iItem;
	int j = 2;

	//获取文本数据
	CString str = m_uiListCtrl.GetItemText(i,j);

	m_uiAccount = str;

	UpdateData(FALSE);

}


