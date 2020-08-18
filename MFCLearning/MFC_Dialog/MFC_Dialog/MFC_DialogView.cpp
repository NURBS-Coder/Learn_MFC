
// MFC_DialogView.cpp : CMFC_DialogView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_Dialog.h"
#endif

#include "MFC_DialogDoc.h"
#include "MFC_DialogView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_DialogView

IMPLEMENT_DYNCREATE(CMFC_DialogView, CView)

BEGIN_MESSAGE_MAP(CMFC_DialogView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC_DialogView 构造/析构

CMFC_DialogView::CMFC_DialogView()
{
	// TODO: 在此处添加构造代码

}

CMFC_DialogView::~CMFC_DialogView()
{
}

BOOL CMFC_DialogView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC_DialogView 绘制

void CMFC_DialogView::OnDraw(CDC* /*pDC*/)
{
	CMFC_DialogDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC_DialogView 打印

BOOL CMFC_DialogView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC_DialogView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC_DialogView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFC_DialogView 诊断

#ifdef _DEBUG
void CMFC_DialogView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_DialogView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_DialogDoc* CMFC_DialogView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_DialogDoc)));
	return (CMFC_DialogDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_DialogView 消息处理程序
