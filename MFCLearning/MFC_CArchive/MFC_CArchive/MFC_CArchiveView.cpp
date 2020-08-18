
// MFC_CArchiveView.cpp : CMFC_CArchiveView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC_CArchiveView ����/����

CMFC_CArchiveView::CMFC_CArchiveView()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC_CArchiveView::~CMFC_CArchiveView()
{
}

BOOL CMFC_CArchiveView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC_CArchiveView ����

void CMFC_CArchiveView::OnDraw(CDC* /*pDC*/)
{
	CMFC_CArchiveDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC_CArchiveView ��ӡ

BOOL CMFC_CArchiveView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC_CArchiveView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC_CArchiveView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFC_CArchiveView ���

#ifdef _DEBUG
void CMFC_CArchiveView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_CArchiveView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_CArchiveDoc* CMFC_CArchiveView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_CArchiveDoc)));
	return (CMFC_CArchiveDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_CArchiveView ��Ϣ�������
