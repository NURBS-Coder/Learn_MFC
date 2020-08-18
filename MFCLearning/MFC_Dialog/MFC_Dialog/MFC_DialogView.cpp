
// MFC_DialogView.cpp : CMFC_DialogView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC_DialogView ����/����

CMFC_DialogView::CMFC_DialogView()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC_DialogView::~CMFC_DialogView()
{
}

BOOL CMFC_DialogView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC_DialogView ����

void CMFC_DialogView::OnDraw(CDC* /*pDC*/)
{
	CMFC_DialogDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC_DialogView ��ӡ

BOOL CMFC_DialogView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC_DialogView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC_DialogView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFC_DialogView ���

#ifdef _DEBUG
void CMFC_DialogView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_DialogView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_DialogDoc* CMFC_DialogView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_DialogDoc)));
	return (CMFC_DialogDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_DialogView ��Ϣ�������
