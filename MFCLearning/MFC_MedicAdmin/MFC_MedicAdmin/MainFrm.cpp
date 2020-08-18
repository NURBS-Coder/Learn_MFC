
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "MFC_MedicAdmin.h"

#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_UPDATE_COMMAND_UI(ID_ADD_USER, &CMainFrame::OnUpdateAddUser)
	ON_UPDATE_COMMAND_UI(ID_DELETE_USER, &CMainFrame::OnUpdateDeleteUser)
	ON_UPDATE_COMMAND_UI(ID_SEARCH_USER, &CMainFrame::OnUpdateSearchUser)
	ON_COMMAND(ID_CLOSE_WINDOW, &CMainFrame::OnCloseWindow)
	ON_WM_CLOSE()
	ON_COMMAND(ID_CHANGE_PWD, &CMainFrame::OnChangePwd)
	ON_COMMAND(ID_CHANGE_USER, &CMainFrame::OnChangeUser)
	ON_COMMAND(ID_DELETE_USER, &CMainFrame::OnDeleteUser)
	ON_UPDATE_COMMAND_UI(ID_MEDIC_STORE, &CMainFrame::OnUpdateMedicStore)
	ON_UPDATE_COMMAND_UI(ID_MEDIC_SALE, &CMainFrame::OnUpdateMedicSale)
	ON_UPDATE_COMMAND_UI(ID_MEDIC_CLEAR, &CMainFrame::OnUpdateMedicClear)
	ON_COMMAND(ID_BY_TYPE, &CMainFrame::OnByType)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类

	//创建一个一行两列的静态分隔器窗口
	m_SpWnd.CreateStatic(this,1,2);

	//创建视图
	m_SpWnd.CreateView(0,0,RUNTIME_CLASS(CUserTreeView),CSize(230,600),pContext);
	m_SpWnd.CreateView(0,1,RUNTIME_CLASS(CMedicListView),CSize(720,600),pContext);


	//重写创建用户客户区函数，屏蔽默认功能
	return TRUE;
	//return CFrameWnd::OnCreateClient(lpcs, pContext);
}

void CMainFrame::OnChangePwd()
{
	// TODO: 在此添加命令处理程序代码
	CChangePwdDlg pChangPwdLog;
	pChangPwdLog.DoModal();
}


void CMainFrame::OnChangeUser()
{
	// TODO: 在此添加命令处理程序代码
}

void CMainFrame::SetMyEnable(CCmdUI *pCmdUI,CString type)
{
	CMFC_MedicAdminDoc *pDoc = (CMFC_MedicAdminDoc *)GetActiveDocument();

	CUser *pUser = pDoc -> GetUser();

	if (pUser->GetType() == type)
	{
		pCmdUI->Enable(TRUE);
	}else{
		pCmdUI->Enable(FALSE);
	}
}

//菜单更新,管理员才有权限
void CMainFrame::OnUpdateAddUser(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	SetMyEnable(pCmdUI,_T("管理员"));

}


void CMainFrame::OnUpdateDeleteUser(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码

	SetMyEnable(pCmdUI,_T("管理员"));
}


void CMainFrame::OnUpdateSearchUser(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码

	SetMyEnable(pCmdUI,_T("管理员"));
}


void CMainFrame::OnCloseWindow()
{
	// TODO: 在此添加命令处理程序代码

	//exit(0);

	OnClose();
}


void CMainFrame::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CFrameWnd::OnClose();
}


void CMainFrame::OnDeleteUser()
{
	// TODO: 在此添加命令处理程序代码
	CDeleteUserDlg dlg;
	dlg.DoModal();
}


void CMainFrame::OnUpdateMedicStore(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	SetMyEnable(pCmdUI,_T("售药员"));
}


void CMainFrame::OnUpdateMedicSale(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	SetMyEnable(pCmdUI,_T("售药员"));
}


void CMainFrame::OnUpdateMedicClear(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	SetMyEnable(pCmdUI,_T("售药员"));
}


void CMainFrame::OnByType()
{
	// TODO: 在此添加命令处理程序代码
	CSeekMTypeDlg dlg;
	dlg.DoModal();

}
