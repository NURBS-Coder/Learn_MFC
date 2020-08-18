
// MFC_CArchiveView.cpp : CMFC_CArchiveView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_CArchive.h"
#endif

#include "MFC_CArchiveDoc.h"
#include "MFC_CArchiveView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_CArchiveView

IMPLEMENT_DYNCREATE(CMFC_CArchiveView, CView)

BEGIN_MESSAGE_MAP(CMFC_CArchiveView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC_CArchiveView 构造/析构

CMFC_CArchiveView::CMFC_CArchiveView()
{
	// TODO: 在此处添加构造代码

}

CMFC_CArchiveView::~CMFC_CArchiveView()
{
}

BOOL CMFC_CArchiveView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC_CArchiveView 绘制

void CMFC_CArchiveView::OnDraw(CDC* /*pDC*/)
{
	CMFC_CArchiveDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC_CArchiveView 打印

BOOL CMFC_CArchiveView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC_CArchiveView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC_CArchiveView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFC_CArchiveView 诊断

#ifdef _DEBUG
void CMFC_CArchiveView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_CArchiveView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_CArchiveDoc* CMFC_CArchiveView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_CArchiveDoc)));
	return (CMFC_CArchiveDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_CArchiveView 消息处理程序
