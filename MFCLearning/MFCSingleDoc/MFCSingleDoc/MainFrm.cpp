
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "MFCSingleDoc.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
	ON_COMMAND(ID_TEST, &CMainFrame::OnTest)
	ON_COMMAND(ID_TEST1_AAAAA, &CMainFrame::OnTest1Aaaaa)
	ON_COMMAND(ID_TEST1_BBBBB, &CMainFrame::OnTest1Bbbbb)
	ON_UPDATE_COMMAND_UI(ID_TEST1_AAAAA, &CMainFrame::OnUpdateTest1Aaaaa)
	ON_WM_TIMER()
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
	: m_isUpdate(false)
{
	// TODO: 在此添加成员初始化代码

	//在框架类获取应用程序类指针，加载ico
	icon[0] = AfxGetApp()->LoadIconW(IDI_ICON1);
	icon[1] = AfxGetApp()->LoadIconW(IDI_ICON2);
	icon[2] = AfxGetApp()->LoadIconW(IDI_ICON3);
	icon[3] = AfxGetApp()->LoadIconW(IDI_ICON4);
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: 如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	SetTimer(1,500,NULL);

	//菜单标记
	//获取主菜单
	CMenu *MainMenu = GetMenu();
	//获取子菜单
	CMenu *FileMenu = MainMenu->GetSubMenu(0);
	//通过位置MF_BYPOSITION获取选项
	FileMenu->CheckMenuItem(0,MF_BYPOSITION|MF_CHECKED);
	//通过位置MF_BYPOSITION获取选项
	FileMenu->CheckMenuItem(ID_FILE_PRINT,MF_BYCOMMAND|MF_CHECKED);

	//设置默认项，加粗，一个菜单项只有一个默认
	FileMenu->SetDefaultItem(2,TRUE);

	//禁用
	m_bAutoMenuEnable= false;
	FileMenu->EnableMenuItem(ID_FILE_PRINT,1);

	//移除菜单项
	SetMenu(NULL);

	//加载菜单
	CMenu menu;
	menu.LoadMenuW(IDR_MAINFRAME);
	SetMenu(&menu);

	//分离
	menu.Detach();		//类似不释放局部菜单变量，不然有问题

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



void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值



	CFrameWnd::OnLButtonDown(nFlags, point);
}


void CMainFrame::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CFrameWnd::OnPaint()
}


void CMainFrame::OnTest()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox(_T("HHHHHHH"));
}




void CMainFrame::OnTest1Aaaaa()
{
	// TODO: 在此添加命令处理程序代码

}


//aaaa菜单的更新，菜单自动更新时调用
void CMainFrame::OnUpdateTest1Aaaaa(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	if(m_isUpdate)
	{
		pCmdUI->Enable(TRUE);
	}else{
		pCmdUI->Enable(FALSE);
	}
}

//bbbbb的处理函数
void CMainFrame::OnTest1Bbbbb()
{
	// TODO: 在此添加命令处理程序代码
	m_isUpdate = !m_isUpdate;
}




void CMainFrame::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	static int i = 0;

	//修改图标
	//这个函数是WinAPI，可以改很多东西
	SetClassLong(m_hWnd, GCL_HICON,(LONG)icon[i]);
	i++;
	if(i==4){i=0;}


	CFrameWnd::OnTimer(nIDEvent);
}
