
// MFC_OnTimerView.cpp : CMFC_OnTimerView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_COMMAND(ID_32771, &CMFC_OnTimerView::On32771)
END_MESSAGE_MAP()

// CMFC_OnTimerView ����/����

CMFC_OnTimerView::CMFC_OnTimerView()
{
	// TODO: �ڴ˴���ӹ������

	//����ͼ��
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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC_OnTimerView ����

void CMFC_OnTimerView::OnDraw(CDC* pDC)
{
	CMFC_OnTimerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	pDC->DrawIcon(x1,y,icon[0]);
	pDC->DrawIcon(x2,y+30,icon[1]);
	pDC->DrawIcon(x3,y+60,icon[2]);
	pDC->DrawIcon(x4,y+90,icon[3]);

}


// CMFC_OnTimerView ��ӡ

BOOL CMFC_OnTimerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC_OnTimerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC_OnTimerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFC_OnTimerView ���

#ifdef _DEBUG
void CMFC_OnTimerView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_OnTimerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_OnTimerDoc* CMFC_OnTimerView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_OnTimerDoc)));
	return (CMFC_OnTimerDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_OnTimerView ��Ϣ�������


int CMFC_OnTimerView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	// TODO:  �ڴ������ר�õĴ�������


	SetTimer(1,500,NULL);

	
	return 0;
}


void CMFC_OnTimerView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch (nIDEvent)
	{
	case 1:
		{
			x1 += 30;
			x2 += 60;
			x3 += 90;
			x4 += 120;

			//��ȡ�ͻ�����Χ
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
	// TODO: �ڴ���������������


	x1=x2=x3=x4=30;
	Invalidate();		//��ӵ���OnDraw������


}
