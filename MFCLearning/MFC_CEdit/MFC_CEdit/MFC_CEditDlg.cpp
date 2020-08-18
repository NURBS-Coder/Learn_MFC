
// MFC_CEditDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_CEdit.h"
#include "MFC_CEditDlg.h"
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


// CMFC_CEditDlg 对话框



CMFC_CEditDlg::CMFC_CEditDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_CEditDlg::IDD, pParent)
	, m_Edit1_string(_T(""))
	, m_Edit2_string(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_CEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
	DDX_Control(pDX, IDC_EDIT2, m_Edit2);
	DDX_Text(pDX, IDC_EDIT1, m_Edit1_string);
	DDX_Text(pDX, IDC_EDIT2, m_Edit2_string);
}

BEGIN_MESSAGE_MAP(CMFC_CEditDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_CEditDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC_CEditDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC_CEditDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFC_CEditDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CMFC_CEditDlg 消息处理程序

BOOL CMFC_CEditDlg::OnInitDialog()
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFC_CEditDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_CEditDlg::OnPaint()
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
HCURSOR CMFC_CEditDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_CEditDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	//用CEdit变量读写数据

	//获取第一个编辑框内容
	CString str;
	m_Edit1.GetWindowTextW(str);

	//给第二个编辑框写入内容
	if (str.GetLength() > 0)
	{
		m_Edit2.SetWindowTextW(str);
	}

}


void CMFC_CEditDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	//用控件关联的一般变量读写数据
	UpdateData(TRUE);	//TRUE,将控件数据更新到变量

	//获取第一个编辑框内容
	CString str;
	str=m_Edit1_string;

	//给第二个编辑框写入内容
	if (str.GetLength() > 0)
	{
		m_Edit2_string=str;
	}
	UpdateData(FALSE);	//FALSE,将变量数据更新到控件
}


void CMFC_CEditDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

	m_Edit1.SetWindowTextW(_T(""));
	m_Edit2.SetWindowTextW(_T(""));

}


void CMFC_CEditDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Edit1_string="";
	m_Edit2_string="";
	UpdateData(FALSE);
}
