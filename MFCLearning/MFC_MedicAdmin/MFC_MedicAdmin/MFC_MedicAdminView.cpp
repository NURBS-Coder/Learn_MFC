
// MFC_MedicAdminView.cpp : CMFC_MedicAdminView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC_MedicAdmin.h"
#endif

#include "MFC_MedicAdminDoc.h"
#include "MFC_MedicAdminView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_MedicAdminView

IMPLEMENT_DYNCREATE(CMFC_MedicAdminView, CFormView)

BEGIN_MESSAGE_MAP(CMFC_MedicAdminView, CFormView)
	ON_WM_CLOSE()
END_MESSAGE_MAP()

// CMFC_MedicAdminView ����/����

CMFC_MedicAdminView::CMFC_MedicAdminView()
	: CFormView(CMFC_MedicAdminView::IDD)
{
	// TODO: �ڴ˴���ӹ������

}

CMFC_MedicAdminView::~CMFC_MedicAdminView()
{
}

void CMFC_MedicAdminView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CMFC_MedicAdminView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

void CMFC_MedicAdminView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();


	//CView���ʼ������
	//ҩƷ���������ʵ������
	/*
	һ����̬��ִ���
		1���Զ���������
			a) CUserTreeView���̳���CTreeView, ��ʾ�û���Ϣ��
			b) CMedicListView(�̳���CListView, ��ʾҩƷ��Ϣ)
		2���ڿ����������ֲ���
			a) �����Զ������ͷ�ļ�
			b) ʹ��CSplitterWnd��ʵ�ֲ�ֹ���
					i.���ظ���ܵ� CFrameWnd::OnCreateClient��Ա����
					ii.���д�����̬�ָ�������	CSplitterWnd::CreateStatic()
					iii.���д��������ָ��	CSplitterWnd::CreateView()
	
		3����ʼ���Զ����ࣨ����CView��������ࣩ-> ���ظ���ܵ�CView::OnInitialUpdate()��Ա����,���н�����Ӧ�ĳ�ʼ������
			a��CMedicListView ��ʼ��
				1��CListCtrl��ʹ��
				2���������ݿ⣺�����->MFC->MFC ODBCʹ����->����Դ->�½�->.....-> ������CMedicSet��CRecordset�����ࡿ
				3�����ĵ����ж��� CMedicSet���󣬹�����ʹ��
				4���򿪼�¼������ѯ���в������ݡ�һ��Ҫ�ȴ��ٲ�ѯȻ�������
			b) CUserTreeView ��ʼ��
				1��CTreeCtrl��ʹ��
				2���������ݿ⣺�����->MFC->MFC ODBCʹ����->����Դ->�½�->.....-> ������CUserSet��CRecordset�����ࡿ
				3�����ĵ����ж��� CUserSet���󣬹�����ʹ��
				4���򿪼�¼������ѯ���в������ݡ�һ��Ҫ�ȴ��ٲ�ѯȻ�������
			
	*/

}


// CMFC_MedicAdminView ���

#ifdef _DEBUG
void CMFC_MedicAdminView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMFC_MedicAdminView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMFC_MedicAdminDoc* CMFC_MedicAdminView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_MedicAdminDoc)));
	return (CMFC_MedicAdminDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_MedicAdminView ��Ϣ�������


void CMFC_MedicAdminView::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CFormView::OnClose();
}
