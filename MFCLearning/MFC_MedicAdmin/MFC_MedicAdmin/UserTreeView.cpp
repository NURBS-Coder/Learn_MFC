// UserTreeView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_MedicAdmin.h"
#include "UserTreeView.h"
#include "MFC_MedicAdminDoc.h"

#include "LOGIN.h"
#include "User.h"

// CUserTreeView

IMPLEMENT_DYNCREATE(CUserTreeView, CTreeView)

CUserTreeView::CUserTreeView()
{

}

CUserTreeView::~CUserTreeView()
{
}

BEGIN_MESSAGE_MAP(CUserTreeView, CTreeView)
END_MESSAGE_MAP()


// CUserTreeView ���

#ifdef _DEBUG
void CUserTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUserTreeView ��Ϣ�������


void CUserTreeView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���

	
	//��ȡ����ͼ�е����ؼ�
	CTreeCtrl &treeCtrl = this->GetTreeCtrl();

	//�������ؼ�����
	//treeCtrl.ModifyStyle();

	//a) �����Զ���ͼ��
	HICON icon[4];
	icon[0]=AfxGetApp()->LoadIconW(IDI_ICON1);
	icon[1]=AfxGetApp()->LoadIconW(IDI_ICON2);
	icon[2]=AfxGetApp()->LoadIconW(IDI_ICON3);
	icon[3]=AfxGetApp()->LoadIconW(IDI_ICON4);

	//b)2 ����ͼ���б�
	//30, 30:ͼ����
	//ILC_COLOR32:��ʽ
	//4, 4���ж���ͼ��д����
	
	m_imagelist.Create(30, 30, ILC_COLOR32, 4, 4);

	//b)3. ͼ���б�׷��ͼ��
	for (int i = 0; i < 4; i++)
	{
		m_imagelist.Add(icon[i]);
	}

	//c) ����ͼ��״̬�б�
	treeCtrl.SetImageList(&m_imagelist,TVSIL_NORMAL);

	//d) �����ؼ�����ڵ�
	//InsertItem(�ڵ���,�ڵ�ͼ��,�ڵ�ѡ��ʱͼ��,��һ�ڵ�)
	//���ڵ�
	//HTREEITEM root = treeCtrl.InsertItem(_T("����Ա"),0,0,NULL);
	//HTREEITEM root1 = treeCtrl.InsertItem(_T("��ҩԱ"),2,2,NULL);
	//HTREEITEM root2 = treeCtrl.InsertItem(_T("ҽ��"),3,3,NULL);
	//���ڵ�
	//HTREEITEM father = treeCtrl.InsertItem(_T("���ڵ�"),1,1,root);
	//HTREEITEM father1 = treeCtrl.InsertItem(_T("���ڵ�"),1,1,root1);
	//HTREEITEM father2 = treeCtrl.InsertItem(_T("���ڵ�"),1,1,root2);
	//�ӽڵ�

	//e) ����Ĭ�ϵ�ѡ����
	//treeCtrl.SelectItem(father);	//��ʾ��ѡ�е���һ��ڵ�

	//��ȡ�ĵ���ָ��
	CMFC_MedicAdminDoc *pDoc = (CMFC_MedicAdminDoc*)GetDocument();

	//��ȡ�û���¼��
	CUserSet *pUserSet = pDoc->GetUserSet();

	//�����ݿ�
	if (!pUserSet->IsOpen())
	{
		pUserSet->Open();
	}

	pUserSet->m_strFilter=_T("");

	//������¼�Ի���
	CLOGIN pLoginDlg;
	pLoginDlg.DoModal();


#if 0
	//������¼������ڲ�ͬ���ڵ���
	CString str;
	//ɸѡ����Ա
	pUserSet->m_strFilter=_T("classification = '����Ա'");
	//��ѯ
	pUserSet->Requery();
	for (int i = 0; i < pUserSet->GetRecordCount(); i++)
	{
		str.Format(_T("%s(%s)"),pUserSet->m_account,pUserSet->m_name);
		treeCtrl.InsertItem(str,1,1,root);
		pUserSet->MoveNext();
	}
	//ɸѡ��ҩԱ
	pUserSet->m_strFilter=_T("classification = '��ҩԱ'");
	//��ѯ
	pUserSet->Requery();
	for (int i = 0; i < pUserSet->GetRecordCount(); i++)
	{
		str.Format(_T("%s(%s)"),pUserSet->m_account,pUserSet->m_name);
		treeCtrl.InsertItem(str,1,1,root1);
		pUserSet->MoveNext();
	}
	//ɸѡҽ��
	pUserSet->m_strFilter=_T("classification = 'ҽ��'");
	//��ѯ
	pUserSet->Requery();
	for (int i = 0; i < pUserSet->GetRecordCount(); i++)
	{
		str.Format(_T("%s(%s)"),pUserSet->m_account,pUserSet->m_name);
		treeCtrl.InsertItem(str,1,1,root2);
		pUserSet->MoveNext();
	}

#endif

	//������¼������ڲ�ͬ���ڵ��� (�Ż�)
	CString str;
	CString type[] = {_T("����Ա"),_T("��ҩԱ"),_T("ҽ��")};

	//��ȡ��¼����Ϣ
	CUser *pUser = pDoc->GetUser();
	HTREEITEM curuser = NULL;
	for (int i = 0; i < 3; i++)
	{
		//����
		HTREEITEM root = treeCtrl.InsertItem(type[i],i,i,NULL);
		//ɸѡ
		str.Format(_T("classification = '%s'"),type[i]);
		pUserSet->m_strFilter=str;
		//��ѯ
		pUserSet->Requery();
		for (int i = 0; i < pUserSet->GetRecordCount(); i++)
		{
			if(pUser->GetAccount() == pUserSet->m_account)
			{
				str.Format(_T("[��¼�û�]%s(%s)"),pUserSet->m_account,pUserSet->m_name);
				curuser = treeCtrl.InsertItem(str,1,1,root);
			}else{
				str.Format(_T("%s(%s)"),pUserSet->m_account,pUserSet->m_name);
				treeCtrl.InsertItem(str,3,3,root);
			}
			pUserSet->MoveNext();
		}
	}
	//����Ĭ�ϵ�ѡ����
	if(curuser != NULL)
	{
		treeCtrl.SelectItem(curuser);	//��ʾ��ѡ�е���һ��ڵ�
	}
}
