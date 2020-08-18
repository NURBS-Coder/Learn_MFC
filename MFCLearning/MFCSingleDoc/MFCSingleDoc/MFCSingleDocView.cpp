
// MFCSingleDocView.cpp : CMFCSingleDocView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCSingleDoc.h"
#endif

#include "MFCSingleDocDoc.h"
#include "MFCSingleDocView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCSingleDocView

IMPLEMENT_DYNCREATE(CMFCSingleDocView, CView)

BEGIN_MESSAGE_MAP(CMFCSingleDocView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
//	ON_WM_PAINT()
ON_WM_CHAR()
ON_WM_CREATE()
ON_WM_TIMER()
ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCSingleDocView 构造/析构

CMFCSingleDocView::CMFCSingleDocView()
	: m_Point(0)
	, str(_T(""))
	, str1(_T(""))
	, w(0)
{
	// TODO: 在此处添加构造代码

}

CMFCSingleDocView::~CMFCSingleDocView()
{
}

BOOL CMFCSingleDocView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCSingleDocView 绘制

void CMFCSingleDocView::OnDraw(CDC* /*pDC*/)
{
	CMFCSingleDocDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CClientDC dc(this);

	str1 = _T("原谅我这一生不羁放纵爱自由，哪会怕有一天会跌倒");
	dc.TextOutW(100,100,str1);
}


// CMFCSingleDocView 打印

BOOL CMFCSingleDocView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCSingleDocView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCSingleDocView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCSingleDocView 诊断

#ifdef _DEBUG
void CMFCSingleDocView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCSingleDocView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCSingleDocDoc* CMFCSingleDocView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCSingleDocDoc)));
	return (CMFCSingleDocDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCSingleDocView 消息处理程序


void CMFCSingleDocView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	//MessageBox(_T("Hello World"));

	SetCaretPos(point);

	m_Point = point;

	str.Empty();

	CView::OnLButtonDown(nFlags, point);
}


//void CMFCSingleDocView::OnPaint()
//{
//	CPaintDC dc(this); // device context for painting
//	// TODO: 在此处添加消息处理程序代码
//	// 不为绘图消息调用 CView::OnPaint()
//
//
//}


void CMFCSingleDocView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//TCHAR ch = (TCHAR)nChar;
	//CString Str;
	//Str.Format(TEXT("%c"), ch);
	//MessageBox(Str);

	

	CClientDC dc(this);
	


	//获取字体信息
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);

	if(nChar == VK_RETURN)  //换行
	{
		str.Empty();
		m_Point.y = m_Point.y+tm.tmHeight;
		SetCaretPos(CPoint(m_Point.x,m_Point.y));
	}else if(nChar == VK_BACK)	//退格
	{
		//获取背景色
		COLORREF color = GetBkColor(dc);
		//设置字体颜色
		COLORREF oldColor = dc.SetTextColor(color);
		//白色重新写一遍
		dc.TextOutW(m_Point.x,m_Point.y,str);
		//去掉最后一个字符
		str = str.Left(str.GetLength()-1);
		dc.SetTextColor(oldColor);

	}else{
		str += (TCHAR)nChar;
		
	}

	//获取字体长度信息
	CSize size = dc.GetTextExtent(str);
	CPoint MyPoint;
	MyPoint.x = m_Point.x + size.cx;
	MyPoint.y = m_Point.y;
	SetCaretPos(MyPoint);

	dc.TextOutW(m_Point.x,m_Point.y,str);

	CView::OnChar(nChar, nRepCnt, nFlags);
}


int CMFCSingleDocView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码

	//获取字体信息
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);

	//继承与CWnd
	CreateSolidCaret(tm.tmAveCharWidth/8,tm.tmHeight); //创建插入符
	ShowCaret();	//显示插入符

	SetTimer(1,100,NULL);

	return 0;
}


void CMFCSingleDocView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

#if 0
	static int i = 0;
	i++;

	CString sttt;
	sttt.Format(TEXT("%d"),i);
#endif

	//获取字体长度信息
	CClientDC dc(this);
	CSize size = dc.GetTextExtent(str1);
	w+=5;

	if(w >size.cx){
		w=0;
		Invalidate();
	}

	CRect rect(100,100,100+w,100+size.cy);

	dc.SetTextColor(RGB(255,0,0));
	dc.DrawText(str1,&rect,DT_LEFT);


	CView::OnTimer(nIDEvent);
}


void CMFCSingleDocView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//获取主菜单(菜单是在框架类下)
	//CMenu *MainMenu = GetMenu();
	CMenu MainMenu;
	MainMenu.LoadMenuW(IDR_MENU1);

	//获取子菜单
	CMenu *FileMenu = MainMenu.GetSubMenu(0);

	//子菜单为快捷菜单
	ClientToScreen(&point);
	FileMenu->TrackPopupMenu(TPM_RIGHTALIGN|TPM_RIGHTALIGN,point.x,point.y,this);

	CView::OnRButtonDown(nFlags, point);
}
