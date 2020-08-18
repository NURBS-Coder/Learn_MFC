
// MFC_PicWatchDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_PicWatch.h"
#include "MFC_PicWatchDlg.h"
#include "afxdialogex.h"

#include "Clogin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//按照路径给按钮设置位图
#define HBMP(filepath, width, height) (HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,0,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION )

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


// CMFC_PicWatchDlg 对话框



CMFC_PicWatchDlg::CMFC_PicWatchDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_PicWatchDlg::IDD, pParent)
	, m_PicIndex(1)
	, m_isPlay(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_PicWatchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFC_PicWatchDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_PicWatchDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC_PicWatchDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC_PicWatchDlg::OnBnClickedButton2)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDOK, &CMFC_PicWatchDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMFC_PicWatchDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CMFC_PicWatchDlg 消息处理程序

BOOL CMFC_PicWatchDlg::OnInitDialog()
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

	//显示登陆界面
	Clogin MyLogin;
	MyLogin.DoModal();


	//获取控件
	m_bmp = (CStatic*)GetDlgItem(IDC_STATIC_BMP);

	//设置显示风格
	m_bmp->ModifyStyle(0xf, SS_BITMAP|SS_CENTERIMAGE);

	//获取控件大小
	CRect rect;
	m_bmp->GetWindowRect(&rect);
	
	//按照路径给按钮设置位图
	m_bmp->SetBitmap(HBMP(_T("..//Pic//1.bmp"),rect.Width(),rect.Height()));


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFC_PicWatchDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_PicWatchDlg::OnPaint()
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
HCURSOR CMFC_PicWatchDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_PicWatchDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	//按照路径给按钮设置位图
	CString str;
	m_PicIndex-=1;
	if(m_PicIndex<1){m_PicIndex=6;}
	str.Format(_T("..//Pic//%d.bmp"),m_PicIndex);

	//获取控件大小
	CRect rect;
	m_bmp->GetWindowRect(&rect);

	m_bmp->SetBitmap(HBMP(str,rect.Width(),rect.Height()));
}


void CMFC_PicWatchDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	m_PicIndex+=1;
	if(m_PicIndex>6){m_PicIndex=1;}
	str.Format(_T("..//Pic//%d.bmp"),m_PicIndex);

	//获取控件大小
	CRect rect;
	m_bmp->GetWindowRect(&rect);

	m_bmp->SetBitmap(HBMP(str,rect.Width(),rect.Height()));
}


void CMFC_PicWatchDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_isPlay =! m_isPlay;
	if(m_isPlay)
	{
		GetDlgItem(IDC_BUTTON1)->EnableWindow(0);
		GetDlgItem(IDC_BUTTON3)->EnableWindow(0);

		GetDlgItem(IDC_BUTTON2)->SetWindowTextW(_T("暂停播放"));

		SetTimer(1,1000,NULL);
	}else{
		GetDlgItem(IDC_BUTTON1)->EnableWindow(1);
		GetDlgItem(IDC_BUTTON3)->EnableWindow(1);

		GetDlgItem(IDC_BUTTON2)->SetWindowTextW(_T("自动播放"));

		KillTimer(1);
	}
}


void CMFC_PicWatchDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CString str;
	m_PicIndex+=1;
	if(m_PicIndex>6){m_PicIndex=1;}
	str.Format(_T("..//Pic//%d.bmp"),m_PicIndex);
	
	//获取控件大小
	CRect rect;
	m_bmp->GetWindowRect(&rect);

	m_bmp->SetBitmap(HBMP(str,rect.Width(),rect.Height()));

	CDialogEx::OnTimer(nIDEvent);
}


void CMFC_PicWatchDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CMFC_PicWatchDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
