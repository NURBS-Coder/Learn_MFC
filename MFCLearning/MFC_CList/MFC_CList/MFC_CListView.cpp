
// MFC_CListView.cpp : CMFC_CListView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC_CList.h"
#endif

#include "MFC_CListDoc.h"
#include "MFC_CListView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_CListView

IMPLEMENT_DYNCREATE(CMFC_CListView, CFormView)

BEGIN_MESSAGE_MAP(CMFC_CListView, CFormView)
	ON_BN_CLICKED(IDC_RADIO1, &CMFC_CListView::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMFC_CListView::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_CListView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC_CListView::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC_CListView::OnBnClickedButton3)
END_MESSAGE_MAP()

// CMFC_CListView ����/����

CMFC_CListView::CMFC_CListView()
	: CFormView(CMFC_CListView::IDD)
	, m_uiId(0)
	, m_uiName(_T(""))
	, m_uiAge(0)
	, m_uiScore(0)
{
	// TODO: �ڴ˴���ӹ������

}

CMFC_CListView::~CMFC_CListView()
{
}

void CMFC_CListView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON2, m_ButtonPre);
	DDX_Control(pDX, IDC_BUTTON3, m_ButtonNext);
	DDX_Control(pDX, IDC_BUTTON1, m_ButtonAdd);
	DDX_Text(pDX, IDC_EDIT1, m_uiId);
	DDX_Text(pDX, IDC_EDIT2, m_uiName);
	DDX_Text(pDX, IDC_EDIT3, m_uiAge);
	DDX_Text(pDX, IDC_EDIT4, m_uiScore);
}

BOOL CMFC_CListView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

void CMFC_CListView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	//��ʼ��
	CheckRadioButton(IDC_RADIO1,IDC_RADIO2,IDC_RADIO1);
	m_ButtonPre.EnableWindow(0);
	m_ButtonNext.EnableWindow(0);
	
}


// CMFC_CListView ���

#ifdef _DEBUG
void CMFC_CListView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMFC_CListView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMFC_CListDoc* CMFC_CListView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_CListDoc)));
	return (CMFC_CListDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_CListView ��Ϣ�������


void CMFC_CListView::OnBnClickedRadio1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	m_ButtonAdd.EnableWindow(1);
	m_ButtonPre.EnableWindow(0);
	m_ButtonNext.EnableWindow(0);
}


void CMFC_CListView::OnBnClickedRadio2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	m_ButtonAdd.EnableWindow(0);
	m_ButtonPre.EnableWindow(1);
	m_ButtonNext.EnableWindow(1);
}

/*
	ѧ������ϵͳ��CList �б�ģ���ʹ�ã�
	1.����һ��ѧ���࣬��ΪCList ��ģ�����
	2.�ĵ��ഢ�����ݣ���ͼ���޸ĺ���ʾ����
		a) ��β�����Ԫ�� CList::AddTail();
		b) ��ȡβԪ��λ�� CList::GetTailPostition();
		c) ��ȡ��Ԫ��λ�� CList::GetHeadPosition();
		d) ��ȡ��һ��Ԫ�� CList::GetPrev();
		e) ��ȡ��һ��Ԫ�� CList::GetNext();
		f) ��ȡָ��λ��Ԫ�� CList::GetAt();
		g) �Ƴ�ͷ�ڵ�Ԫ�أ����ͷſռ䣩CList::RemoveHead()
	3.��ͼ�Ļ��� CFormView ���½�����ʱѡ��
*/

void CMFC_CListView::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	UpdateData(TRUE);

	//ָ�붯̬����ռ�
	Student *stu = new Student(m_uiId,m_uiName,m_uiAge,m_uiScore);

	//��ȡ�ĵ�����ָ��
	CMFC_CListDoc *pDoc = GetDocument();

	//���б�β�����
	pDoc->m_Mylist.AddTail(stu);

	//���浱ǰλ��
	pDoc->m_Pos = pDoc->m_Mylist.GetTailPosition();

}


void CMFC_CListView::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//��ȡ�ĵ�����ָ��
	CMFC_CListDoc *pDoc = GetDocument();

	if (pDoc->m_Pos == NULL)
	{
		return;
	}

	Student *stu;
	//��ȡ��һԪ�أ�pDoc->m_Pos���Զ�����
	pDoc->m_Mylist.GetPrev(pDoc->m_Pos);

	//��ͷ�˾�����Ϊβ���λ��
	if (pDoc->m_Pos == NULL)
	{
		pDoc->m_Pos=pDoc->m_Mylist.GetTailPosition();
	}

	//��ȡ��ǰλ�õ�Ԫ��
	stu = pDoc->m_Mylist.GetAt(pDoc->m_Pos);

	//��ֵ
	m_uiId = stu->m_id;
	m_uiName = stu->m_name;
	m_uiAge = stu->m_age;
	m_uiScore = stu->m_score;

	UpdateData(FALSE);
}


void CMFC_CListView::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//��ȡ�ĵ�����ָ��
	CMFC_CListDoc *pDoc = GetDocument();

	if (pDoc->m_Pos == NULL)
	{
		return;
	}


	Student *stu;
	//��ȡ��һԪ�أ�pDoc->m_Pos���Զ�����
	pDoc->m_Mylist.GetNext(pDoc->m_Pos);

	//��ͷ�˾�����Ϊͷ���λ��
	if (pDoc->m_Pos == NULL)
	{
		pDoc->m_Pos=pDoc->m_Mylist.GetHeadPosition();
	}

	//��ȡ��ǰλ�õ�Ԫ��
	stu = pDoc->m_Mylist.GetAt(pDoc->m_Pos);

	//��ֵ
	m_uiId = stu->m_id;
	m_uiName = stu->m_name;
	m_uiAge = stu->m_age;
	m_uiScore = stu->m_score;

	UpdateData(FALSE);
}
