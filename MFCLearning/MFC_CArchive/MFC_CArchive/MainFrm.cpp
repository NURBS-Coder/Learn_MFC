
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "MFC_CArchive.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_CARCHIVE_WRITE, &CMainFrame::OnCarchiveWrite)
	ON_COMMAND(ID_CARCHIVE_READ, &CMainFrame::OnCarchiveRead)
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

//文档序列化，二进制操作文件类 CArchive的使用
//序列化： 以二进制方式写文件
//反序列化： 以二进制方式读文件


void CMainFrame::OnCarchiveWrite()
{
	// TODO: 在此添加命令处理程序代码
	//用CArchive类写文件
	/*
		1. 创建文件对象 CFile
		2. 以写方式打开文件 CFile::Open()
		3. 创建序列化对象，并和文件关联在一起 CArchive
			CAchive::store 把数据保存到归档文件中。 允许CFile写操作
		4. 往数据流写数据（相当于往文件写数据）
			ar << a << b << c
		5. 断开数据流和文件的关联 CArchive::Close()
		6. 关闭文件 CFile::Close()
	*/

	//1. 创建文件对象 CFile
	CFile file;

	//2. 以写方式打开文件 CFile::Open()
	BOOL isOk = file.Open(_T("../demo.txt"),CFile::modeCreate |CFile::modeWrite);
	if (isOk == FALSE)
	{
		return ;
	}

	//3. 创建序列化对象，并和文件关联在一起 CArchive
	//CArchive对象是数据流，关联后操作CArchive就是操作文件
	CArchive ar(&file, CArchive::store);

	//4. 往数据流写数据（相当于往文件写数据）
	//和cout用法一样
	int a = 10;
	CString str = _T("ABC");
	TCHAR ch = 't';		
	//箭头代表流向
	//数据流向ar,ar指向文件,即写文件
	ar << a << str << ch;

	//5. 断开数据流和文件的关联 CArchive::Close()
	ar.Close();

	//6. 关闭文件 CFile::Close()
	file.Close();
}


void CMainFrame::OnCarchiveRead()
{
	// TODO: 在此添加命令处理程序代码
	//用CArchive类读文件
	/*
		1. 创建文件对象 CFile
		2. 以读方式打开文件 CFile::Open()
		3. 创建序列化对象，并和文件关联在一起 CArchive
			CAchive::load 从归档文件中装载数据。 CFile只读
		4. 通过数据流往变量写数据（相当于从文件读数据）
			ar >> a >> b >> c
		5. 断开数据流和文件的关联 CArchive::Close()
		6. 关闭文件 CFile::Close()
	*/

	//1. 创建文件对象 CFile
	CFile file;

	//2. 以读方式打开文件 CFile::Open()
	BOOL isOk = file.Open(_T("../demo.txt"),CFile::modeRead);
	if (isOk == FALSE)
	{
		return ;
	}

	//3. 创建序列化对象，并和文件关联在一起 CArchive
	//CArchive对象是数据流，关联后操作CArchive就是操作文件
	CArchive ar(&file, CArchive::load);

	//4. 通过数据流往变量写数据（相当于从文件读数据）
	//和cout用法一样
	int a;
	CString str;
	TCHAR ch;		
	//箭头代表流向
	//数据流向变量,ar指向文件,即读文件
	ar >> a >> str >> ch;

	CString buf;
	buf.Format(_T("%d, %s, %c"),a,str,ch);
	MessageBox(buf);

	//5. 断开数据流和文件的关联 CArchive::Close()
	ar.Close();

	//6. 关闭文件 CFile::Close()
	file.Close();
}
