
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
	, m_Edit(_T(""))
	, m_Pos(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_ListBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Edit);
	DDX_Control(pDX, IDC_LIST1, m_ListBox);
	DDX_Control(pDX, IDC_COMBO1, m_CComboBox);
	DDX_Text(pDX, IDC_EDIT2, m_Pos);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_SBar);
}

BEGIN_MESSAGE_MAP(CMFC_ListBoxDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_ListBoxDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC_ListBoxDlg::OnBnClickedButton2)
	ON_LBN_SELCHANGE(IDC_LIST1, &CMFC_ListBoxDlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC_ListBoxDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFC_ListBoxDlg::OnBnClickedButton4)
	ON_WM_HSCROLL()
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CMFC_ListBoxDlg::OnDeltaposSpin1)
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
	//设置默认值
	m_CComboBox.SetCurSel(1);

	//初始化水平控制条的值
	m_Pos = 50;
	UpdateData(FALSE);
	//设置水平控制条的位置
	m_SBar.SetScrollRange(0,100);
	m_SBar.SetScrollPos(m_Pos);


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



void CMFC_ListBoxDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	//列表框CListBox 的使用
	/*
		1.给列表框添加字符串		CListBox::AddString()
		2.选中列表框某一项，自动触发事件：LBN_SELCHANGE
			a）获取当前选中项		CListBox::GetCurSel()
			b）获取指定位置的内容	CListBox::GetText()
		3.删除指定位置字符串		CListBox::DeleteString()
		4.在指定位置插入字符串		CListBox::InsertString()
	*/

	//获取编辑区内容
	UpdateData(TRUE);

	if(m_Edit.GetLength() > 0)
	{
		m_ListBox.AddString(m_Edit);
		m_Edit.Empty();
		UpdateData(FALSE);

	}else{
		MessageBox(_T("添加内容为空！"));
	}


}


void CMFC_ListBoxDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	//获取当前选中行
	int i = m_ListBox.GetCurSel();

	//删除当前选中行
	m_ListBox.DeleteString(i);
}


void CMFC_ListBoxDlg::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码

	//获取当前选中行
	int i = m_ListBox.GetCurSel();
	//获取当前选中内容
	m_ListBox.GetText(i,m_Edit);
	//更新到编辑区
	UpdateData(FALSE);
}


void CMFC_ListBoxDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

	//获取当前编辑区内容
	UpdateData(TRUE);
	if(m_Edit.GetLength() > 0)
	{	
		//获取当前选中行
		int i = m_ListBox.GetCurSel();
		//删除该位置内容
		m_ListBox.DeleteString(i);
		//在该位置插入内容
		m_ListBox.InsertString(i,m_Edit);
		//清空编辑区
		m_Edit = _T("");
		UpdateData(FALSE);
	}else{
		MessageBox(_T("修改内容为空！"));
	}
}


void CMFC_ListBoxDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码

	//组合框 CComboBox的使用
	/*
		1.获取内容 CComboBox::GetLBText
			其他接口与 CListBox 的用法类似
		2.属性设置
			a）data ：设置内容，不同内容用英文分号";"分隔
			b）type ：简单、下拉框、下拉列表
	*/

	//获取当前选中行
	int i = m_CComboBox.GetCurSel();
	//获取当前选中内容
	CString str;
	m_CComboBox.GetLBText(i,str);
	MessageBox(str);
}


void CMFC_ListBoxDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//水平滚动条 HorizontalScrollBar的使用
	/*
		1.设置给定滚动条的最小和最大位置	CScrollBar::SetScrollRange()
		2.获取一个滚动条的当前位置			CScrollBar::GetScrollPos()
		3.设置一个滚动条的当前位置			CScrollBar::SetScrollPos()
		4.消息处理：
			a)水平控制条处理函数再其父窗口(对话框类)的WM_HSCROLL消息的处理函数
			b)该处理函数类似OnTimer的处理函数,要处理该窗口下的所有水平控制条,用指针pScrollBar区别
			c)nPos指示滑块位置，只有点击滑块时才有值，否则是0.
		5.滚动条的位置关系
				switch (nSBCode)
				{
				case SB_THUMBPOSITION:	//滑块位置
					break;
				case SB_LINELEFT:		//左箭头位置
					break;
				case SB_LINERIGHT:		//右箭头位置
					break;
				case SB_PAGELEFT:		//左箭头与滑块中间位置
					break;
				case SB_PAGERIGHT:		//右箭头与滑块中间位置
					break;
				default:
					break;
				}
			
	*/

	if (pScrollBar = &m_SBar)
	{
		int tempPos ;
		switch (nSBCode)
		{
		case SB_THUMBPOSITION:	//滑块位置
			{
				m_SBar.SetScrollPos(nPos);
				m_Pos = nPos;
				UpdateData(FALSE);
				break;
			}
		case SB_LINELEFT:		//左箭头位置
			{
				//获取滑块当前位置
				tempPos = m_SBar.GetScrollPos() - 5;
				if(tempPos < 0){tempPos =  0;}
				m_SBar.SetScrollPos(tempPos);
				m_Pos = tempPos;
				UpdateData(FALSE);
				break;
			}
		case SB_LINERIGHT:		//右箭头位置
			{
				//获取滑块当前位置
				tempPos = m_SBar.GetScrollPos() + 5;
				if(tempPos > 100){tempPos =  100;}
				m_SBar.SetScrollPos(tempPos);
				m_Pos = tempPos;
				UpdateData(FALSE);
				break;
			}
		case SB_PAGELEFT:		//左箭头与滑块中间位置
			{
				//获取滑块当前位置
				tempPos = m_SBar.GetScrollPos() - 10;
				if(tempPos < 0){tempPos =  0;}
				m_SBar.SetScrollPos(tempPos);
				m_Pos = tempPos;
				UpdateData(FALSE);
				break;
			}
		case SB_PAGERIGHT:		//右箭头与滑块中间位置
			{
				//获取滑块当前位置
				tempPos = m_SBar.GetScrollPos() + 10;
				if(tempPos > 100){tempPos =  100;}
				m_SBar.SetScrollPos(tempPos);
				m_Pos = tempPos;
				UpdateData(FALSE);
				break;
			}
		default:
			break;
		}

	}




	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CMFC_ListBoxDlg::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	//微调（选转）按钮 SpinControl 的使用
	/*
		1.属性设置  Auto Buddy -> True
					Set Buddy Integer -> True
		2.微调（选转）按钮的顺序比Buddy空间大一【Ctrl + D】
	*/

	*pResult = 0;
}
