
// MFC_CArchiveProView.cpp : CMFC_CArchiveProView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC_CArchiveProView ����/����

CMFC_CArchiveProView::CMFC_CArchiveProView()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC_CArchiveProView::~CMFC_CArchiveProView()
{
}

BOOL CMFC_CArchiveProView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC_CArchiveProView ����

void CMFC_CArchiveProView::OnDraw(CDC* pDC)
{
	CMFC_CArchiveProDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	for (int i = 0; i < pDoc->m_Num; i++)
	{
		pDC->Ellipse(pDoc->m_pt[i].x - 5,pDoc->m_pt[i].y - 5,
			pDoc->m_pt[i].x + 5,pDoc->m_pt[i].y + 5);
	}
}


// CMFC_CArchiveProView ��ӡ

BOOL CMFC_CArchiveProView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC_CArchiveProView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC_CArchiveProView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFC_CArchiveProView ���

#ifdef _DEBUG
void CMFC_CArchiveProView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_CArchiveProView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_CArchiveProDoc* CMFC_CArchiveProView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_CArchiveProDoc)));
	return (CMFC_CArchiveProDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_CArchiveProView ��Ϣ�������


void CMFC_CArchiveProView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//��ȡ�ĵ���ָ��

	CMFC_CArchiveProDoc *pDoc = GetDocument();

	if(pDoc->m_Num > 200)
	{
		pDoc->m_Num = 200;
		return;
	}

	pDoc->m_pt[pDoc->m_Num] = point;

	pDoc->m_Num++;

	//��ͼ
	Invalidate(); //->OnDraw();





	CView::OnLButtonDown(nFlags, point);
}
