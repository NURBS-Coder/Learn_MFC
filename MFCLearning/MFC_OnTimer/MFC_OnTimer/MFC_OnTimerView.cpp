
// MFC_OnTimerView.cpp : CMFC_OnTimerView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_OnTimer.h"
#endif

#include "MFC_OnTimerDoc.h"
#include "MFC_OnTimerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_OnTimerView

IMPLEMENT_DYNCREATE(CMFC_OnTimerView, CView)

BEGIN_MESSAGE_MAP(CMFC_OnTimerView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_COMMAND(ID_32771, &CMFC_OnTimerView::On32771)
END_MESSAGE_MAP()

// CMFC_OnTimerView 构造/析构

CMFC_OnTimerView::CMFC_OnTimerView()
{
	// TODO: 在此处添加构造代码

	//加载图标
	icon[0] = AfxGetApp()->LoadIconW(IDI_ICON1);
	icon[1] = AfxGetApp()->LoadIconW(IDI_ICON2);
	icon[2] = AfxGetApp()->LoadIconW(IDI_ICON3);
	icon[3] = AfxGetApp()->LoadIconW(IDI_ICON4);

	x1=x2=x3=x4=30;
	y=30;

}

CMFC_OnTimerView::~CMFC_OnTimerView()
{
}

BOOL CMFC_OnTimerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC_OnTimerView 绘制

void CMFC_OnTimerView::OnDraw(CDC* pDC)
{
	CMFC_OnTimerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	pDC->DrawIcon(x1,y,icon[0]);
	pDC->DrawIcon(x2,y+30,icon[1]);
	pDC->DrawIcon(x3,y+60,icon[2]);
	pDC->DrawIcon(x4,y+90,icon[3]);

}


// CMFC_OnTimerView 打印

BOOL CMFC_OnTimerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC_OnTimerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC_OnTimerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFC_OnTimerView 诊断

#ifdef _DEBUG
void CMFC_OnTimerView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_OnTimerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_OnTimerDoc* CMFC_OnTimerView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_OnTimerDoc)));
	return (CMFC_OnTimerDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_OnTimerView 消息处理程序


int CMFC_OnTimerView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	// TODO:  在此添加您专用的创建代码


	SetTimer(1,500,NULL);

	
	return 0;
}


void CMFC_OnTimerView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nIDEvent)
	{
	case 1:
		{
			x1 += 30;
			x2 += 60;
			x3 += 90;
			x4 += 120;

			//获取客户区范围
			CRect rect;
			GetClientRect(&rect);
			if(x1>rect.Width()){x1=30;}
			if(x2>rect.Width()){x2=30;}
			if(x3>rect.Width()){x3=30;}
			if(x4>rect.Width()){x4=30;}
			Invalidate();
			break;
		}
	default:
		break;
	}




	CView::OnTimer(nIDEvent);
}


void CMFC_OnTimerView::On32771()
{
	// TODO: 在此添加命令处理程序代码


	x1=x2=x3=x4=30;
	Invalidate();		//间接调用OnDraw（）；


}
