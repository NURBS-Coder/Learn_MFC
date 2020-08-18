
// MFC_CListCtrlDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_CListCtrl.h"
#include "MFC_CListCtrlDlg.h"
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


// CMFC_CListCtrlDlg 对话框



CMFC_CListCtrlDlg::CMFC_CListCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_CListCtrlDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_CListCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
}

BEGIN_MESSAGE_MAP(CMFC_CListCtrlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CMFC_CListCtrlDlg 消息处理程序

BOOL CMFC_CListCtrlDlg::OnInitDialog()
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

	//ListCtrl控件的使用
	/*
		1.属性设置 view -> Report (报表) 常用
		2.常用接口
			a）设置列表风格	CListCtrl::SetExtendedStyle()
				例如：	LVS_EX_FULLROWSELECT	选择整行
						LVS_EX_GRIDLINES		网格方式
			b）获取列表风格 CListCtrl::GetExtendedStyle()
			c）插入某列		CListCtrl::InsertColumn()
			d) 插入某行		CListCtrl::InsertItem()
			e）插入内容		CListCtrl::SetItemText()
	*/

	//初始化ListCtrl控件
	//设置风格样式
	//m_ListCtrl.SetExtendedStyle(LVS_EX_GRIDLINES);
	m_ListCtrl.SetExtendedStyle(m_ListCtrl.GetExtendedStyle()|
		LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);

	//插入标题
	CString Head[] = {_T("姓名"), _T("年龄"), _T("性别")}; 
	//插入列
	m_ListCtrl.InsertColumn(0,Head[0],LVCFMT_LEFT,50);
	m_ListCtrl.InsertColumn(1,Head[1],LVCFMT_LEFT,50);
	m_ListCtrl.InsertColumn(2,Head[2],LVCFMT_LEFT,50);
	//插入正文内容，先确定行，再插入列
	for (int i = 0; i < 10; i++)
	{
		CString str;
		str.Format(_T("学生%d"),i);
		//确定行
		m_ListCtrl.InsertItem(i,str);

		//设置列
		int j;j=1;
		m_ListCtrl.SetItemText(i,j++,_T("18"));
		m_ListCtrl.SetItemText(i,j++,_T("男"));
	}


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFC_CListCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_CListCtrlDlg::OnPaint()
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
HCURSOR CMFC_CListCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

