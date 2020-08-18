
// MFC_CArchiveProView.cpp : CMFC_CArchiveProView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_CArchivePro.h"
#endif

#include "MFC_CArchiveProDoc.h"
#include "MFC_CArchiveProView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_CArchiveProView

IMPLEMENT_DYNCREATE(CMFC_CArchiveProView, CView)

BEGIN_MESSAGE_MAP(CMFC_CArchiveProView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC_CArchiveProView 构造/析构

CMFC_CArchiveProView::CMFC_CArchiveProView()
{
	// TODO: 在此处添加构造代码

}

CMFC_CArchiveProView::~CMFC_CArchiveProView()
{
}

BOOL CMFC_CArchiveProView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC_CArchiveProView 绘制

void CMFC_CArchiveProView::OnDraw(CDC* pDC)
{
	CMFC_CArchiveProDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	for (int i = 0; i < pDoc->m_Num; i++)
	{
		pDC->Ellipse(pDoc->m_pt[i].x - 5,pDoc->m_pt[i].y - 5,
			pDoc->m_pt[i].x + 5,pDoc->m_pt[i].y + 5);
	}
}


// CMFC_CArchiveProView 打印

BOOL CMFC_CArchiveProView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC_CArchiveProView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC_CArchiveProView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFC_CArchiveProView 诊断

#ifdef _DEBUG
void CMFC_CArchiveProView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_CArchiveProView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_CArchiveProDoc* CMFC_CArchiveProView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_CArchiveProDoc)));
	return (CMFC_CArchiveProDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_CArchiveProView 消息处理程序


void CMFC_CArchiveProView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//获取文档类指针

	CMFC_CArchiveProDoc *pDoc = GetDocument();

	if(pDoc->m_Num > 200)
	{
		pDoc->m_Num = 200;
		return;
	}

	pDoc->m_pt[pDoc->m_Num] = point;

	pDoc->m_Num++;

	//绘图
	Invalidate(); //->OnDraw();





	CView::OnLButtonDown(nFlags, point);
}
