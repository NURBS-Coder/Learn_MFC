
// MFC_OtherButtonDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_OtherButton.h"
#include "MFC_OtherButtonDlg.h"
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


// CMFC_OtherButtonDlg 对话框



CMFC_OtherButtonDlg::CMFC_OtherButtonDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_OtherButtonDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_OtherButtonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_CheckBox);
}

BEGIN_MESSAGE_MAP(CMFC_OtherButtonDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_OtherButtonDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC_OtherButtonDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMFC_OtherButtonDlg 消息处理程序

BOOL CMFC_OtherButtonDlg::OnInitDialog()
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
	CheckRadioButton(IDC_RADIO1,IDC_RADIO3,IDC_RADIO1);

	m_CheckBox.SetCheck(1);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFC_OtherButtonDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_OtherButtonDlg::OnPaint()
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
HCURSOR CMFC_OtherButtonDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_OtherButtonDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	//RadioButton 单选控件的使用
	/*
		1.同组第一个按钮设置Group属性为TRUE
		2.一组单选控件要排序【Ctrl + D】设置
		3.初始化单选框： CWnd::CheckRadioButton()
		4.判断按钮按下： CWnd::IsDlgButtonChecked()
	*/

	CString str;
	if(IsDlgButtonChecked(IDC_RADIO1))
	{
		 GetDlgItem(IDC_RADIO1)->GetWindowTextW(str);
	}
	if(IsDlgButtonChecked(IDC_RADIO2))
	{
		 GetDlgItem(IDC_RADIO2)->GetWindowTextW(str);
	}
		if(IsDlgButtonChecked(IDC_RADIO3))
	{
		 GetDlgItem(IDC_RADIO3)->GetWindowTextW(str);
	}

	MessageBox(str);
}


void CMFC_OtherButtonDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
		
	//CheckBox 复选控件的使用
	/*
		1.常关联变量 BOOL :UpdateData(TRUE),UpdateData(FALSE)
		2.初始化单选框： CButton::SetCheck();
		4.判断按钮状态： CButton::GetCheck();
	*/
		
	CString str,temp;
	if(IsDlgButtonChecked(IDC_CHECK1))
	{
		 GetDlgItem(IDC_CHECK1)->GetWindowTextW(temp);
		 str+=temp;
		 str+=_T("\r\n");
	}
	if(IsDlgButtonChecked(IDC_CHECK2))
	{
		 GetDlgItem(IDC_CHECK2)->GetWindowTextW(temp);
		 str+=temp;
		 str+=_T("\r\n");;
	}
		if(IsDlgButtonChecked(IDC_CHECK3))
	{
		 GetDlgItem(IDC_CHECK3)->GetWindowTextW(temp);
		 str+=temp;
		 str+=_T("\r\n");
	}

	MessageBox(str);
}
