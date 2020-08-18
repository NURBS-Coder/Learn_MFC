// DeleteUserDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_MedicAdmin.h"
#include "DeleteUserDlg.h"
#include "afxdialogex.h"


// CDeleteUserDlg �Ի���

IMPLEMENT_DYNAMIC(CDeleteUserDlg, CDialogEx)

CDeleteUserDlg::CDeleteUserDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDeleteUserDlg::IDD, pParent)
	, m_uiAccount(_T(""))
{

}

CDeleteUserDlg::~CDeleteUserDlg()
{
}

void CDeleteUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_uiType);
	DDX_Text(pDX, IDC_EDIT1, m_uiAccount);
	DDX_Control(pDX, IDC_LIST1, m_uiListCtrl);
}


BEGIN_MESSAGE_MAP(CDeleteUserDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDeleteUserDlg::OnBnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDeleteUserDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDOK, &CDeleteUserDlg::OnBnClickedOk)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CDeleteUserDlg::OnNMClickList1)
END_MESSAGE_MAP()


// CDeleteUserDlg ��Ϣ�������
void CDeleteUserDlg::UpdataListCtrl(CString Type)
{
	//��ȡ���ݿ��¼��ָ��
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	//��ȡ�ĵ���ָ��
	CMFC_MedicAdminDoc *pDoc =(CMFC_MedicAdminDoc*)pFrame->GetActiveDocument();

	//��ȡ�û���¼��
	CUserSet *pUserSet = pDoc->GetUserSet();

	CString SQL;
	SQL.Format(_T("classification = '%s'"),Type);
	if(Type == _T("���г�Ա")){
		pUserSet->m_strFilter=_T("");
	}else{
		pUserSet->m_strFilter=SQL;
	}

	//��ѯ
	pUserSet->Requery();

	//������ڵ��б�
	m_uiListCtrl.DeleteAllItems();

	//CRecordset::GetRecordCount()  ��ȡ��¼�������������˱�ͷ��
	for (int i = 0; i < pUserSet->GetRecordCount(); i++)
	{
		CString str;
		str.Format(_T("%d"),i+1);
		m_uiListCtrl.InsertItem(i,str);

		int j = 1;
		str.Format(_T("%s"),pUserSet->m_classification);
		m_uiListCtrl.SetItemText(i,j++,str);

		str.Format(_T("%s"),pUserSet->m_account);
		m_uiListCtrl.SetItemText(i,j++,str);

		str.Format(_T("%s"),pUserSet->m_name);
		m_uiListCtrl.SetItemText(i,j++,str);

		str.Format(_T("%s"),pUserSet->m_password);
		m_uiListCtrl.SetItemText(i,j++,str);

		pUserSet->MoveNext();
	}

}


BOOL CDeleteUserDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	m_uiType.SetCurSel(3);

	//��ȡ���ݿ��¼��ָ��
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	//��ȡ�ĵ���ָ��
	CMFC_MedicAdminDoc *pDoc =(CMFC_MedicAdminDoc*)pFrame->GetActiveDocument();

	//��ȡ�û���¼��
	CUserSet *pUserSet = pDoc->GetUserSet();

	//�����ݿ�
	if (!pUserSet->IsOpen())
	{
		pUserSet->Open();
	}

	//���÷�񣬱��ѡ��ȫ��
	m_uiListCtrl.SetExtendedStyle(m_uiListCtrl.GetExtendedStyle()
		|LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	

	//���ñ�ͷ
	CString head[] = 
	{
		_T("����"),_T("�û����"),_T("�û��˺�"),_T("�û�����"),_T("�û�����")
	};

	int n = sizeof(head)/sizeof(head[0]);

	for (int i = 0; i < n; i++)
	{
		m_uiListCtrl.InsertColumn(i,head[i],LVCFMT_LEFT,100);
	}

	//��ȡѡ�е�ɸѡ����
	int index = m_uiType.GetCurSel();
	CString type ;
	m_uiType.GetLBText(index,type);

	if(type.IsEmpty()){
		MessageBox(_T("�����Ϊ��"));
		return TRUE;
	}

	UpdataListCtrl(type);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CDeleteUserDlg::UpdataTreeView(void)
{
	//��ȡ���ݿ��¼��ָ��
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	//��ȡ�ĵ���ָ��
	CMFC_MedicAdminDoc *pDoc =(CMFC_MedicAdminDoc*)pFrame->GetActiveDocument();

	//��ȡ�û���¼��
	CUserSet *pUserSet = pDoc->GetUserSet();

	//�����ݿ�
	if (!pUserSet->IsOpen())
	{
		pUserSet->Open();
	}

	//ͨ���ĵ��ҵ���Ҫ������ͼ��һ���ĵ���Ӧ�����ͼ��ͨ��������� ��
	CUserTreeView *pUserTreeView = NULL;

	//��ȡ�ĵ��е�һ����ͼ��λ��
	POSITION pos = pDoc->GetFirstViewPosition();

	//������ͼ����Ѱ������ͼ
	while (pos != NULL)
	{
		//���ݵ�ǰλ�û�ȡ��ͼָ�룬����λ������
		CView *pView = pDoc->GetNextView(pos);

		//�ж��ǲ���Ѱ�ҵ�����ͼ
		if (pView->IsKindOf(RUNTIME_CLASS(CUserTreeView)))
		{
			//����ת����CView����������ת��
			pUserTreeView = (CUserTreeView *)pView;
			break;
		}
	}

	if(pUserTreeView == NULL)
	{
		return ;
	}

	//�������ؼ�

	//��ȡ����ͼ�е����ؼ�
	CTreeCtrl &treeCtrl = pUserTreeView->GetTreeCtrl();

	treeCtrl.DeleteAllItems();
	pUserSet->m_strFilter=_T("");

	//��ѯ
	pUserSet->Requery();

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


void CDeleteUserDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	if(m_uiAccount.IsEmpty()){
		MessageBox(_T("����ѡ���û���"));
		return;
	}

	//��ȡѡ�е�ɸѡ����
	int index = m_uiType.GetCurSel();
	CString type ;
	m_uiType.GetLBText(index,type);

	if(type.IsEmpty()){
		MessageBox(_T("�����Ϊ��"));
		return;
	}

	//��ȡ���ݿ��¼��ָ��
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	//��ȡ�ĵ���ָ��
	CMFC_MedicAdminDoc *pDoc =(CMFC_MedicAdminDoc*)pFrame->GetActiveDocument();

	//��ȡ��ǰ��¼�û�����
	CUser* pUser = pDoc->GetUser();

	//ɾ���û�
	int ret = pUser->DelUser(m_uiAccount);
	switch (ret)
	{
	case -2:
		MessageBox(_T("���ݲ���Ϊ�գ�"));
		break;
	case -3:
		MessageBox(_T("����ɾ����¼�û���"));
		break;
	case -4:
		MessageBox(_T("û�д��û���"));
		break;
	case -5:
		MessageBox(_T("�������ݿ�ʧ�ܣ�"));
		break;
	default:
		{
			//�����б�ؼ�
			UpdataListCtrl(type);
			//�������ؼ�
			UpdataTreeView();
			MessageBox(_T("ɾ���û��ɹ���"));
		}
		break;
	}

}

void CDeleteUserDlg::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//��ȡѡ�е�ɸѡ����
	int index = m_uiType.GetCurSel();
	CString type ;
	m_uiType.GetLBText(index,type);

	if(type.IsEmpty()){
		MessageBox(_T("�����Ϊ��"));
	}

	UpdataListCtrl(type);

}


void CDeleteUserDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
}


void CDeleteUserDlg::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	//ת�����ͣ��б���ͼ(�ṹ�壬������������Ϣ)
	NM_LISTVIEW *pList = (NM_LISTVIEW *)pNMHDR;

	//�к�l��
	int i = pList->iItem;
	int j = 2;

	//��ȡ�ı�����
	CString str = m_uiListCtrl.GetItemText(i,j);

	m_uiAccount = str;

	UpdateData(FALSE);

}


