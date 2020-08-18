
// MFC_ListBoxDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_ListBox.h"
#include "MFC_ListBoxDlg.h"
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


// CMFC_ListBoxDlg 对话框



CMFC_ListBoxDlg::CMFC_ListBoxDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_ListBoxDlg::IDD, pParent)
	, m_str(_T(""))
	, m_int(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_ListBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str);
	DDX_Control(pDX, IDC_LIST1, m_ListBox);
	DDX_Control(pDX, IDC_COMBO1, m_ComboBox);
	DDX_Text(pDX, IDC_EDIT2, m_int);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_SBar);
}

BEGIN_MESSAGE_MAP(CMFC_ListBoxDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_ListBoxDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC_ListBoxDlg::OnBnClickedButton3)
	ON_LBN_SELCHANGE(IDC_LIST1, &CMFC_ListBoxDlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC_ListBoxDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFC_ListBoxDlg::OnBnClickedButton4)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CMFC_ListBoxDlg 消息处理程序

BOOL CMFC_ListBoxDlg::OnInitDialog()
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
	m_ComboBox.AddString(_T("333"));
	m_ComboBox.SetCurSel(1);

	m_SBar.SetScrollRange(0,100);
	m_SBar.SetScrollPos(50);
	m_int = 50;
	UpdateData(FALSE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFC_ListBoxDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_ListBoxDlg::OnPaint()
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
HCURSOR CMFC_ListBoxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//列表框 CListBox的使用
/*
	1.添加字符串 CListBox::AddString()
	2.选中列表框的某一项，触发事件 LBN_SELCHANGE
		a)获取当前选中项 CListBox::GetCurSel()
		b)获取当前位置内容 CListBox::GetText()
	3.删除指定位置字符串 CListBox::DeleteString()
	4.在指定位置插入字符串 CListBox::InsertString()
*/



void CMFC_ListBoxDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);

	if(m_str.GetLength() == 0){
		MessageBox(_T("内容为空！"));
		return;
	}

	//添加内容
	m_ListBox.AddString(m_str);

	m_str.Empty();

	UpdateData(FALSE);
}


void CMFC_ListBoxDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

	//获取选中行
	int n = m_ListBox.GetCurSel();

	//删除
	m_ListBox.DeleteString(n);
}


void CMFC_ListBoxDlg::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码

	//获取选中行
	int n = m_ListBox.GetCurSel();

	//获取选中行内容
	m_ListBox.GetText(n,m_str);

	UpdateData(FALSE);

}


void CMFC_ListBoxDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);

	if(m_str.GetLength() == 0){
		MessageBox(_T("内容为空！"));
		return;
	}

	//获取选中行
	int n = m_ListBox.GetCurSel();

	//删除该行数据
	m_ListBox.DeleteString(n);


	//添加内容
	m_ListBox.InsertString(n,m_str);

	m_str.Empty();

	UpdateData(FALSE);

}


//组合框 CComboBox的使用
/*
	1.添加字符串 CComboBox::AddString()
	2.选中列表框的某一项 CComboBox::SetCurSel()
		a)获取当前选中项 CComboBox::GetCurSel()
		b)获取当前位置内容 CComboBox::GetLBText()
	3.删除指定位置字符串 CComboBox::DeleteString()
	4.在指定位置插入字符串 CComboBox::InsertString()
	5.属性设置：
		data：设置内容，分号分割
		type：普通、下拉框、下拉列表
*/

void CMFC_ListBoxDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码

	CString str;

	//获取选中行
	int n = m_ComboBox.GetCurSel();

	//获取选中行数据
	m_ComboBox.GetLBText(n,str);

	MessageBox(str);
}


//滚动条 CScrollBar的使用
/*
	1.设置给定滚动条的最大最小位置 CScrollBar::SetScrollRange()
	2.获取滚动条当前位置 CScrollBar::GetScrollPos()
	3.设置滚动条当前位置 CScrollBar::SetScrollPos()
	4.处理滚动条事件，不在滚动条本身处理，在其所属父窗口处理消息 WM_HSCROLL
			一个窗口不止一个滚动条，通过函数参数pScrollBar区分
			一个滚动条有五个不同的处理区域，通过函数参数nSBCode区分
			而滑块位置由函数参数nPos传递【只有点击滑块才有值】
		switch (nSBCode)
		{
		case SB_THUMBPOSITION:		//滑块
			break;
		case SB_LINELEFT:			//左箭头
			break;
		case SB_LINERIGHT:			//右箭头
			break;
		case SB_PAGELEFT:			//左箭头与滑块之间
			break;	
		case SB_PAGERIGHT:			//右箭头与滑块之间
			break;
		default:
			break;
		}
*/

void CMFC_ListBoxDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	if(pScrollBar = &m_SBar){
		switch (nSBCode)
		{
		case SB_THUMBPOSITION:		//滑块
			{
				m_SBar.SetScrollPos(nPos);
				m_int = nPos;
				UpdateData(FALSE);
				break;
			}
		case SB_LINELEFT:			//左箭头
			{
				int temp = m_SBar.GetScrollPos() - 5;
				if(temp < 0){temp = 0;}
				m_SBar.SetScrollPos(temp);
				m_int = temp;
				UpdateData(FALSE);
				break;
			}
		case SB_LINERIGHT:			//右箭头
			{
				int temp = m_SBar.GetScrollPos() + 5;
				if(temp > 100){temp = 100;}
				m_SBar.SetScrollPos(temp);
				m_int = temp;
				UpdateData(FALSE);
				break;
			}
		case SB_PAGELEFT:			//左箭头与滑块之间
			{
				int temp = m_SBar.GetScrollPos() - 10;
				if(temp < 0){temp = 0;}
				m_SBar.SetScrollPos(temp);
				m_int = temp;
				UpdateData(FALSE);
				break;
			}
		case SB_PAGERIGHT:			//右箭头与滑块之间
			{
				int temp = m_SBar.GetScrollPos() + 10;
				if(temp > 100){temp = 100;}
				m_SBar.SetScrollPos(temp);
				m_int = temp;
				UpdateData(FALSE);
				break;
			}
		default:
			break;
		}

	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

//微调按钮 SpinControl的使用
/*
	1.属性设置
		Auto Buddy -> True
		Set buddy integer -> True
	2.微调（旋转）按钮顺序比伙伴控件大1【Ctrl + D】

*/