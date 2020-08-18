
// MFC_DataBaseView.cpp : CMFC_DataBaseView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC_DataBase.h"
#endif

#include "MFC_DataBaseDoc.h"
#include "MFC_DataBaseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_DataBaseView

IMPLEMENT_DYNCREATE(CMFC_DataBaseView, CFormView)

BEGIN_MESSAGE_MAP(CMFC_DataBaseView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_DataBaseView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC_DataBaseView::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC_DataBaseView::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFC_DataBaseView::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFC_DataBaseView::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFC_DataBaseView::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFC_DataBaseView::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFC_DataBaseView::OnBnClickedButton8)
END_MESSAGE_MAP()

// CMFC_DataBaseView ����/����

CMFC_DataBaseView::CMFC_DataBaseView()
	: CFormView(CMFC_DataBaseView::IDD)
	, m_uiId(0)
	, m_uiName(_T(""))
	, m_uiAge(0)
	, m_uiScore(0)
	, m_isEdit(false)
	, m_isFilter(false)
{
	// TODO: �ڴ˴���ӹ������

}

CMFC_DataBaseView::~CMFC_DataBaseView()
{
}

void CMFC_DataBaseView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_uiId);
	DDX_Text(pDX, IDC_EDIT2, m_uiName);
	DDX_Text(pDX, IDC_EDIT3, m_uiAge);
	DDX_Text(pDX, IDC_EDIT4, m_uiScore);
	DDX_Control(pDX, IDC_BUTTON3, m_ButtonEdit);
	DDX_Control(pDX, IDC_BUTTON7, m_buttonFilter);
}

BOOL CMFC_DataBaseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

void CMFC_DataBaseView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	//���ݿ���
	/*
		1.׼����������װMySQL������ �� ��װMySQL odbc����
		2.odbc��open database connectivity�����ͼ
			a��odbc��һ�ױ�׼�ӿڣ��ڲ�ͨ��SQL���������ݿ⣬�û�����SQL���Ҳ���Բ������ݿ⣩
			b����������Դ
		3.��������Դ��MySQLֻ���ǿ��գ�
			a�����գ�Snapshot����¼����ÿ�β������²�ѯ��Ÿ���
			b����̬��Dynaset����¼����ÿ�β����Զ����£���Ӽ�¼���⣩
		4.Ӧ�ó�����
			a��CRecordset�����࣬��Ҫ�����ݿ������Ӧ����
				1��DoFieldExchange() �Զ������ݿ��ֶκͱ��������
				2��GetDefaultConnect() ��ȡ���ݿ�������Ϣ
				3��GetDefaultSQL() ��ȡ���ݿ����ӵı�
			b��CFormView�����࣬��ʾ���ݿ����ݵ���ͼ
				1��OnInitialUpdate() ��Ҫ����ʼ���Ĺ���
		5.ͨ��CRecordset ������ݿ������Ӧ����
			a���ĵ���ͷ�ļ�����CRecordset���������
			b����ͼ������ɾ�Ĳ����
				1�������ݿ� CRecordset::Open()
				2����ѯ��¼	CRecordset::Requery()
				3���ƶ���һ����¼�� CRecordset::MovePrev()
				4���ƶ���һ����¼�� CRecordset::MoveNext()
				5���Ƿ�Ϊ���һ����¼����һ�� CRecordset::IsEOF()
				6���Ƿ�Ϊ��ʼһ����¼����һ�� CRecordset::IsBOF()
				7���ƶ�����ʼһ����¼ CRecordset::MoveFirst()
				8���ƶ������һ����¼ CRecordset::MoveLast()
				9����ӿռ�¼ CRecordset::AddNew()
				10�������¼���ɸ��� CRecordset::CanUpdate()
				11�����¼�¼�� CRecordset::UpDate()
				12��ɾ����ǰ��¼ CRecordset::Delete()
				13���༭��ǰ��¼ CRecordset::Edit()
				14������ CRecordset::m_strFilter()
				15������ CRecordset::m_strSort()��Ĭ�����򣬽����desc��
			c��ע���
				1���ƶ���¼����ע��Խ�紦��
				2���ƶ���¼���󣬲�Ҫ���²�ѯ�����²�ѯ�൱���α꣨pSet�����¿�ʼ
				3�����¼�¼ǰ����ͨ�� CRecordset::CanUpdate()�жϼ�¼���ɸ��º󣬲��ܸ���
				4��ɾ�����ݺ�����ƶ�����һ����¼��

	*/


	//��ȡ�ĵ�ָ��
	pDoc = GetDocument();
	//��ȡ���ݿ��¼ָ�뼯
	pSet = pDoc->GetSet();
	//�����ݿ�
	if (FALSE == pSet->IsOpen())
	{
		pSet->Open();

		m_uiId = pSet->m_id;
		m_uiName = pSet->m_name;
		m_uiAge = pSet->m_age;
		m_uiScore = pSet->m_score;

		UpdateData(FALSE);
	}

}


// CMFC_DataBaseView ���

#ifdef _DEBUG
void CMFC_DataBaseView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMFC_DataBaseView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMFC_DataBaseDoc* CMFC_DataBaseView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_DataBaseDoc)));
	return (CMFC_DataBaseDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_DataBaseView ��Ϣ�������


void CMFC_DataBaseView::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//��ȡ��һ����¼��
	pSet->MovePrev();

	//����ǿ�ʼ��ǰһ��
	if (pSet->IsBOF())
	{
		//�Ѽ�¼������Ϊ���һ��
		pSet->MoveLast();
	}

	m_uiId = pSet->m_id;
	m_uiName = pSet->m_name;
	m_uiAge = pSet->m_age;
	m_uiScore = pSet->m_score;

	UpdateData(FALSE);
}


void CMFC_DataBaseView::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//��ȡ��һ����¼��
	pSet->MoveNext();

	//��������ĺ�һ��
	if (pSet->IsEOF())
	{
		//�Ѽ�¼������Ϊ��һ��
		pSet->MoveFirst();
	}

	m_uiId = pSet->m_id;
	m_uiName = pSet->m_name;
	m_uiAge = pSet->m_age;
	m_uiScore = pSet->m_score;

	UpdateData(FALSE);

}

//��Ӽ�¼
void CMFC_DataBaseView::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	m_isEdit =! m_isEdit;

	if(m_isEdit)
	{
		//���ݿ���ӿռ�¼
		pSet->AddNew();
		//���
		m_uiId = 0;
		m_uiName = _T("XX");
		m_uiAge = 0;
		m_uiScore = 0;

		UpdateData(FALSE);
		//ȷ�����
		m_ButtonEdit.SetWindowTextW(_T("ȷ�����"));
	}else{
		UpdateData(TRUE);

		pSet->m_id = m_uiId ;
		pSet->m_name = m_uiName;
		pSet->m_age = m_uiAge;
		pSet->m_score = m_uiScore;

		//�ж���û�����ݿɸ��µ����ݿ�
		if (pSet->CanUpdate())
		{
			//���µ����ݿ�
			pSet->Update();
		}

		//�������ݿ⣬�Զ�ָ���һ����¼
		pSet->Requery();

		m_uiId = pSet->m_id;
		m_uiName = pSet->m_name;
		m_uiAge = pSet->m_age;
		m_uiScore = pSet->m_score;

		UpdateData(FALSE);
		
		//ȷ�����
		m_ButtonEdit.SetWindowTextW(_T("��Ӽ�¼"));
	}
}

//ȷ����Ӽ�¼
void CMFC_DataBaseView::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	pSet->m_id = m_uiId ;
	pSet->m_name = m_uiName;
	pSet->m_age = m_uiAge;
	pSet->m_score = m_uiScore;

	//�ж���û�����ݿɸ��µ����ݿ�
	if (pSet->CanUpdate())
	{
		//���µ����ݿ�
		pSet->Update();
	}

	//�������ݿ⣬�Զ�ָ���һ����¼
	pSet->Requery();

	m_uiId = pSet->m_id;
	m_uiName = pSet->m_name;
	m_uiAge = pSet->m_age;
	m_uiScore = pSet->m_score;

	UpdateData(FALSE);
}

//�޸����ݿ�
void CMFC_DataBaseView::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//���ݿ��޸�
	pSet->Edit();

	UpdateData(TRUE);

	pSet->m_id = m_uiId ;
	pSet->m_name = m_uiName;
	pSet->m_age = m_uiAge;
	pSet->m_score = m_uiScore;

	//�ж���û�����ݿɸ��µ����ݿ�
	if (pSet->CanUpdate())
	{
		//���µ����ݿ�
		pSet->Update();
	}

	//�������ݿ⣬�Զ�ָ���һ����¼
	pSet->Requery();

	m_uiId = pSet->m_id;
	m_uiName = pSet->m_name;
	m_uiAge = pSet->m_age;
	m_uiScore = pSet->m_score;

	UpdateData(FALSE);
}

//ɾ����¼
void CMFC_DataBaseView::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//ɾ����¼
	pSet->Delete();

	//�������ݿ�,�Զ�ָ���һ����¼
	pSet->Requery();

	m_uiId = pSet->m_id;
	m_uiName = pSet->m_name;
	m_uiAge = pSet->m_age;
	m_uiScore = pSet->m_score;

	UpdateData(FALSE);
}


void CMFC_DataBaseView::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	m_isFilter =! m_isFilter;
	if(m_isFilter){
		//���ù�������
		pSet->m_strFilter = (_T("age > 18"));

		m_buttonFilter.SetWindowTextW(_T("�ָ�ȫ������"));
	}else{
		//������
		pSet->m_strFilter = (_T(""));

		m_buttonFilter.SetWindowTextW(_T("�������18"));
	}
	//���²�ѯ
	pSet->Requery();

	m_uiId = pSet->m_id;
	m_uiName = pSet->m_name;
	m_uiAge = pSet->m_age;
	m_uiScore = pSet->m_score;

	UpdateData(FALSE);
}


void CMFC_DataBaseView::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//��������(��������Ĭ������)
	//pSet->m_strSort = _T("age");
	
	//��������(�������򣬽���)
	pSet->m_strSort = _T("score desc");

	//���²�ѯ
	pSet->Requery();

	m_uiId = pSet->m_id;
	m_uiName = pSet->m_name;
	m_uiAge = pSet->m_age;
	m_uiScore = pSet->m_score;

	UpdateData(FALSE);
}
