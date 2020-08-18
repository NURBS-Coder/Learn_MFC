
// MFCSingleDocView.cpp : CMFCSingleDocView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CMFCSingleDocView ����/����

CMFCSingleDocView::CMFCSingleDocView()
	: m_Point(0)
	, str(_T(""))
	, str1(_T(""))
	, w(0)
{
	// TODO: �ڴ˴���ӹ������

}

CMFCSingleDocView::~CMFCSingleDocView()
{
}

BOOL CMFCSingleDocView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCSingleDocView ����

void CMFCSingleDocView::OnDraw(CDC* /*pDC*/)
{
	CMFCSingleDocDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CClientDC dc(this);

	str1 = _T("ԭ������һ������ݰ����ɣ��Ļ�����һ������");
	dc.TextOutW(100,100,str1);
}


// CMFCSingleDocView ��ӡ

BOOL CMFCSingleDocView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCSingleDocView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCSingleDocView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFCSingleDocView ���

#ifdef _DEBUG
void CMFCSingleDocView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCSingleDocView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCSingleDocDoc* CMFCSingleDocView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCSingleDocDoc)));
	return (CMFCSingleDocDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCSingleDocView ��Ϣ�������


void CMFCSingleDocView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	//MessageBox(_T("Hello World"));

	SetCaretPos(point);

	m_Point = point;

	str.Empty();

	CView::OnLButtonDown(nFlags, point);
}


//void CMFCSingleDocView::OnPaint()
//{
//	CPaintDC dc(this); // device context for painting
//	// TODO: �ڴ˴������Ϣ����������
//	// ��Ϊ��ͼ��Ϣ���� CView::OnPaint()
//
//
//}


void CMFCSingleDocView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//TCHAR ch = (TCHAR)nChar;
	//CString Str;
	//Str.Format(TEXT("%c"), ch);
	//MessageBox(Str);

	

	CClientDC dc(this);
	


	//��ȡ������Ϣ
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);

	if(nChar == VK_RETURN)  //����
	{
		str.Empty();
		m_Point.y = m_Point.y+tm.tmHeight;
		SetCaretPos(CPoint(m_Point.x,m_Point.y));
	}else if(nChar == VK_BACK)	//�˸�
	{
		//��ȡ����ɫ
		COLORREF color = GetBkColor(dc);
		//����������ɫ
		COLORREF oldColor = dc.SetTextColor(color);
		//��ɫ����дһ��
		dc.TextOutW(m_Point.x,m_Point.y,str);
		//ȥ�����һ���ַ�
		str = str.Left(str.GetLength()-1);
		dc.SetTextColor(oldColor);

	}else{
		str += (TCHAR)nChar;
		
	}

	//��ȡ���峤����Ϣ
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

	// TODO:  �ڴ������ר�õĴ�������

	//��ȡ������Ϣ
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);

	//�̳���CWnd
	CreateSolidCaret(tm.tmAveCharWidth/8,tm.tmHeight); //���������
	ShowCaret();	//��ʾ�����

	SetTimer(1,100,NULL);

	return 0;
}


void CMFCSingleDocView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

#if 0
	static int i = 0;
	i++;

	CString sttt;
	sttt.Format(TEXT("%d"),i);
#endif

	//��ȡ���峤����Ϣ
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//��ȡ���˵�(�˵����ڿ������)
	//CMenu *MainMenu = GetMenu();
	CMenu MainMenu;
	MainMenu.LoadMenuW(IDR_MENU1);

	//��ȡ�Ӳ˵�
	CMenu *FileMenu = MainMenu.GetSubMenu(0);

	//�Ӳ˵�Ϊ��ݲ˵�
	ClientToScreen(&point);
	FileMenu->TrackPopupMenu(TPM_RIGHTALIGN|TPM_RIGHTALIGN,point.x,point.y,this);

	CView::OnRButtonDown(nFlags, point);
}
