
// MFC_DocViewView.cpp : CMFC_DocViewView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC_DocView.h"
#endif

#include "MFC_DocViewDoc.h"
#include "MFC_DocViewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_DocViewView

IMPLEMENT_DYNCREATE(CMFC_DocViewView, CFormView)

BEGIN_MESSAGE_MAP(CMFC_DocViewView, CFormView)
	ON_BN_CLICKED(IDC_RADIO1, &CMFC_DocViewView::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMFC_DocViewView::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC_DocViewView::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_DocViewView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC_DocViewView::OnBnClickedButton2)
END_MESSAGE_MAP()

// CMFC_DocViewView ����/����

CMFC_DocViewView::CMFC_DocViewView()
	: CFormView(CMFC_DocViewView::IDD)
	, m_uiId(0)
	, m_uiName(_T(""))
	, m_uiAge(0)
	, m_uiScore(0)
{
	// TODO: �ڴ˴���ӹ������

}

CMFC_DocViewView::~CMFC_DocViewView()
{
}

void CMFC_DocViewView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_ButtonPre);
	DDX_Control(pDX, IDC_BUTTON2, m_ButtonNext);
	DDX_Text(pDX, IDC_EDIT1, m_uiId);
	DDX_Text(pDX, IDC_EDIT2, m_uiName);
	DDX_Text(pDX, IDC_EDIT3, m_uiAge);
	DDX_Text(pDX, IDC_EDIT4, m_uiScore);
	DDX_Control(pDX, IDC_BUTTON3, m_ButtonEdit);
}

BOOL CMFC_DocViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

void CMFC_DocViewView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	//ѧ������ϵͳ
	/*
		1.����ѧ����Student
		2.���ĵ���������ݣ���ͼ���޸ĺ���ʾ����
			a)��β�����Ԫ�� CList::AddTail()
			b)��ȡ�б�β��Ԫ�ص�λ�� CList::GetTailPosition() 
			c)��ȡ��һԪ�� CList::GetPrev()
			d)��ȡ��һԪ�� CList::GetNext()
			e)��ȡ��Ԫ��λ�� CList::GetHeadPosition()
			f)��ȡָ��λ�õ�Ԫ�� CList::GetAt()
			g)�Ƴ�ͷ�ڵ�Ԫ�أ�û���ͷſռ䣩CList::RemobeHead()
		3.��ͼ�Ļ��� CFromView() [�ڴ���MFC����ʱѡ��]
	*/

	//���õ�ѡ��
	CheckRadioButton(IDC_RADIO1,IDC_RADIO2,IDC_RADIO1);
	m_ButtonPre.EnableWindow(0);
	m_ButtonNext.EnableWindow(0);

}


// CMFC_DocViewView ���

#ifdef _DEBUG
void CMFC_DocViewView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMFC_DocViewView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMFC_DocViewDoc* CMFC_DocViewView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_DocViewDoc)));
	return (CMFC_DocViewDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_DocViewView ��Ϣ�������


void CMFC_DocViewView::OnBnClickedRadio1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_ButtonPre.EnableWindow(0);
	m_ButtonNext.EnableWindow(0);
	m_ButtonEdit.EnableWindow(1);
}


void CMFC_DocViewView::OnBnClickedRadio2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_ButtonPre.EnableWindow(1);
	m_ButtonNext.EnableWindow(1);
	m_ButtonEdit.EnableWindow(0);
}


void CMFC_DocViewView::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	Student *stu = new Student(m_uiId,m_uiName,m_uiAge,m_uiScore);

	CMFC_DocViewDoc *pDoc = GetDocument();

	//��β����ӽڵ�
	pDoc->m_list.AddTail(stu);

	//���浱ǰ�ڵ�λ��
	pDoc->m_pos = pDoc->m_list.GetTailPosition();
}


void CMFC_DocViewView::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CMFC_DocViewDoc *pDoc = GetDocument();

	if(pDoc->m_pos == NULL){
		return;
	}

	Student *stu;

	//��ȡ��һ��Ԫ��λ�ã�pDoc->m_pos���Զ�������һ��
	pDoc->m_list.GetPrev(pDoc->m_pos);
	if(pDoc->m_pos == NULL){
		//���浱ǰ�ڵ�λ��Ϊβ���
		pDoc->m_pos = pDoc->m_list.GetTailPosition();
	}

	//��ȡ��ǰλ��Ԫ��
	stu = pDoc->m_list.GetAt(pDoc->m_pos);

	m_uiId=stu->m_id;
	m_uiName=stu->m_name;
	m_uiAge=stu->m_age;
	m_uiScore=stu->m_score;

	UpdateData(FALSE);
}


void CMFC_DocViewView::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CMFC_DocViewDoc *pDoc = GetDocument();

	if(pDoc->m_pos == NULL){
		return;
	}

	Student *stu;

	//��ȡ��һ��Ԫ��λ�ã�pDoc->m_pos���Զ�������һ��
	pDoc->m_list.GetNext(pDoc->m_pos);
	if(pDoc->m_pos == NULL){
		//���浱ǰ�ڵ�λ��Ϊβ���
		pDoc->m_pos = pDoc->m_list.GetHeadPosition();
	}

	//��ȡ��ǰλ��Ԫ��
	stu = pDoc->m_list.GetAt(pDoc->m_pos);

	m_uiId=stu->m_id;
	m_uiName=stu->m_name;
	m_uiAge=stu->m_age;
	m_uiScore=stu->m_score;

	UpdateData(FALSE);
}
