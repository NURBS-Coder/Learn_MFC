// MedicListView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_MedicAdmin.h"
#include "MedicListView.h"
#include "MFC_MedicAdminDoc.h"

// CMedicListView

IMPLEMENT_DYNCREATE(CMedicListView, CListView)

CMedicListView::CMedicListView()
{

}

CMedicListView::~CMedicListView()
{
}

BEGIN_MESSAGE_MAP(CMedicListView, CListView)
END_MESSAGE_MAP()


// CMedicListView ���

#ifdef _DEBUG
void CMedicListView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void CMedicListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMedicListView ��Ϣ�������


void CMedicListView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���

	//��ȡ�б���ͼ�е��б�ؼ�
	CListCtrl &listCtrl = this->GetListCtrl();

	//���÷�񣬱��ѡ��ȫ��
	listCtrl.SetExtendedStyle(listCtrl.GetExtendedStyle()
		|LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	
	//���ñ���ģ��
	listCtrl.ModifyStyle(0,LVS_REPORT);

	//���ñ�ͷ
	CString head[] = 
	{
		_T("ҩƷ����"),_T("ҩƷ����"),_T("ҩƷ���"),
		_T("�����Ŀ"),_T("������˾"),_T("����"),
		_T("����ʱ��"),_T("�����ڣ��£�"),_T("���ۣ�Ԫ��")
	};

	int n = sizeof(head)/sizeof(head[0]);

	for (int i = 0; i < n; i++)
	{
		listCtrl.InsertColumn(i,head[i],LVCFMT_LEFT,100);
	}

	//�������ݿ����ݣ����к���
	//for (int i = 0; i < 7; i++)
	//{
	//	CString str;
	//	str.Format(_T("%d"),i);
	//	listCtrl.InsertItem(i,str);

	//	for (int j = 1; j < n; j++)
	//	{
	//		listCtrl.SetItemText(i,j,_T("123"));
	//	}
	//}

	//��ȡ�ĵ���ָ��
	CMFC_MedicAdminDoc *pDoc = (CMFC_MedicAdminDoc*)GetDocument();

	//��ȡ���ݿ��¼��ָ��
	CMedicSet *pMedicSet = pDoc->GetMedicSet();

	//�����ݿ�
	if (!pMedicSet->IsOpen())
	{
		pMedicSet->Open();
	}

	//��ѯ
	pMedicSet->Requery();

	//CRecordset::GetRecordCount()  ��ȡ��¼�������������˱�ͷ��
	for (int i = 0; i < pMedicSet->GetRecordCount(); i++)
	{
		CString str;
		str.Format(_T("%s"),pMedicSet->m_id);
		listCtrl.InsertItem(i,str);

		int j = 1;

		str.Format(_T("%s"),pMedicSet->m_name);
		listCtrl.SetItemText(i,j++,str);

		str.Format(_T("%s"),pMedicSet->m_classification);
		listCtrl.SetItemText(i,j++,str);

		str.Format(_T("%d"),pMedicSet->m_number);
		listCtrl.SetItemText(i,j++,str);

		str.Format(_T("%s"),pMedicSet->m_produceCompany);
		listCtrl.SetItemText(i,j++,str);

		str.Format(_T("%s"),pMedicSet->m_producePlace);
		listCtrl.SetItemText(i,j++,str);

		CTime time = pMedicSet->m_produceDate;
		str = time.Format(_T("%Y-%m-%d"));
		listCtrl.SetItemText(i,j++,str);

		str.Format(_T("%d"),pMedicSet->m_quelityAssurance);
		listCtrl.SetItemText(i,j++,str);

		str.Format(_T("%d"),pMedicSet->m_unitPrice);
		listCtrl.SetItemText(i,j++,str);

		pMedicSet->MoveNext();
	}

}
