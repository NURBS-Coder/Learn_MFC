// UserTreeView.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_MedicAdmin.h"
#include "UserTreeView.h"
#include "MFC_MedicAdminDoc.h"

#include "LOGIN.h"
#include "User.h"

// CUserTreeView

IMPLEMENT_DYNCREATE(CUserTreeView, CTreeView)

CUserTreeView::CUserTreeView()
{

}

CUserTreeView::~CUserTreeView()
{
}

BEGIN_MESSAGE_MAP(CUserTreeView, CTreeView)
END_MESSAGE_MAP()


// CUserTreeView 诊断

#ifdef _DEBUG
void CUserTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUserTreeView 消息处理程序


void CUserTreeView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	
	//获取树视图中的树控件
	CTreeCtrl &treeCtrl = this->GetTreeCtrl();

	//设置树控件属性
	//treeCtrl.ModifyStyle();

	//a) 加载自定义图标
	HICON icon[4];
	icon[0]=AfxGetApp()->LoadIconW(IDI_ICON1);
	icon[1]=AfxGetApp()->LoadIconW(IDI_ICON2);
	icon[2]=AfxGetApp()->LoadIconW(IDI_ICON3);
	icon[3]=AfxGetApp()->LoadIconW(IDI_ICON4);

	//b)2 创建图像列表
	//30, 30:图标宽高
	//ILC_COLOR32:样式
	//4, 4：有多少图标写多少
	
	m_imagelist.Create(30, 30, ILC_COLOR32, 4, 4);

	//b)3. 图像列表追加图标
	for (int i = 0; i < 4; i++)
	{
		m_imagelist.Add(icon[i]);
	}

	//c) 设置图形状态列表
	treeCtrl.SetImageList(&m_imagelist,TVSIL_NORMAL);

	//d) 给树控件插入节点
	//InsertItem(节点名,节点图形,节点选中时图形,上一节点)
	//根节点
	//HTREEITEM root = treeCtrl.InsertItem(_T("管理员"),0,0,NULL);
	//HTREEITEM root1 = treeCtrl.InsertItem(_T("售药员"),2,2,NULL);
	//HTREEITEM root2 = treeCtrl.InsertItem(_T("医生"),3,3,NULL);
	//父节点
	//HTREEITEM father = treeCtrl.InsertItem(_T("父节点"),1,1,root);
	//HTREEITEM father1 = treeCtrl.InsertItem(_T("父节点"),1,1,root1);
	//HTREEITEM father2 = treeCtrl.InsertItem(_T("父节点"),1,1,root2);
	//子节点

	//e) 设置默认的选中项
	//treeCtrl.SelectItem(father);	//显示到选中的这一层节点

	//获取文档类指针
	CMFC_MedicAdminDoc *pDoc = (CMFC_MedicAdminDoc*)GetDocument();

	//获取用户记录集
	CUserSet *pUserSet = pDoc->GetUserSet();

	//打开数据库
	if (!pUserSet->IsOpen())
	{
		pUserSet->Open();
	}

	pUserSet->m_strFilter=_T("");

	//弹出登录对话框
	CLOGIN pLoginDlg;
	pLoginDlg.DoModal();


#if 0
	//遍历记录，添加在不同根节点下
	CString str;
	//筛选管理员
	pUserSet->m_strFilter=_T("classification = '管理员'");
	//查询
	pUserSet->Requery();
	for (int i = 0; i < pUserSet->GetRecordCount(); i++)
	{
		str.Format(_T("%s(%s)"),pUserSet->m_account,pUserSet->m_name);
		treeCtrl.InsertItem(str,1,1,root);
		pUserSet->MoveNext();
	}
	//筛选售药员
	pUserSet->m_strFilter=_T("classification = '售药员'");
	//查询
	pUserSet->Requery();
	for (int i = 0; i < pUserSet->GetRecordCount(); i++)
	{
		str.Format(_T("%s(%s)"),pUserSet->m_account,pUserSet->m_name);
		treeCtrl.InsertItem(str,1,1,root1);
		pUserSet->MoveNext();
	}
	//筛选医生
	pUserSet->m_strFilter=_T("classification = '医生'");
	//查询
	pUserSet->Requery();
	for (int i = 0; i < pUserSet->GetRecordCount(); i++)
	{
		str.Format(_T("%s(%s)"),pUserSet->m_account,pUserSet->m_name);
		treeCtrl.InsertItem(str,1,1,root2);
		pUserSet->MoveNext();
	}

#endif

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
