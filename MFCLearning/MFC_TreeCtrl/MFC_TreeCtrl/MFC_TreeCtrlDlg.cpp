
// MFC_TreeCtrlDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_TreeCtrl.h"
#include "MFC_TreeCtrlDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC_TreeCtrlDlg 对话框



CMFC_TreeCtrlDlg::CMFC_TreeCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_TreeCtrlDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_TreeCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_TreeCtrl);
}

BEGIN_MESSAGE_MAP(CMFC_TreeCtrlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CMFC_TreeCtrlDlg 消息处理程序

BOOL CMFC_TreeCtrlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码


	//树控件CTreeCtrl的使用
	/*
		1.常用属性设置
			has buttons -> true
			has lines -> true
			lines at root -> true
		2.使用流程
			a) 加载自定义图标
				1.获取应用程序对象指针 AfxGetApp()
				2.加载自定义图标 CWinApp::LoadIcon()
			b) 创建图像列表
				1. .h文件类中定义图形列表(CImageList)对象,不能是局部变量，不能被释放
				2. 创建图形列表		CImageList::Create()
				3. 图像列表追加图标	CImageList::Add()
			c) 设置图形状态列表		CTreeCtrl::SetImageList()
			d) 给树控件插入节点		CTreeCtrl::InsertItem()
			e) 设置默认的选中项		CTreeCtrl::SelectItem()
	*/

	//a) 加载自定义图标
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
	m_TreeCtrl.SetImageList(&m_imagelist,TVSIL_NORMAL);

	//d) 给树控件插入节点
	//InsertItem(节点名,节点图形,节点选中时图形,上一节点)
	//根节点
	HTREEITEM root = m_TreeCtrl.InsertItem(_T("根节点"),0,1,NULL);
	//父节点
	HTREEITEM father = m_TreeCtrl.InsertItem(_T("父节点"),1,1,root);
	//子节点
	HTREEITEM son1 = m_TreeCtrl.InsertItem(_T("子节点1"),2,2,father);
	HTREEITEM son2 = m_TreeCtrl.InsertItem(_T("子节点2"),3,3,father);

	//e) 设置默认的选中项
	m_TreeCtrl.SelectItem(father);	//显示到选中的这一层节点

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFC_TreeCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFC_TreeCtrlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFC_TreeCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

