// LOGIN.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_MedicAdmin.h"
#include "LOGIN.h"
#include "afxdialogex.h"
#include "MFC_MedicAdminDoc.h"
#include "MainFrm.h"
#include "User.h"

// CLOGIN �Ի���

IMPLEMENT_DYNAMIC(CLOGIN, CDialogEx)

CLOGIN::CLOGIN(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLOGIN::IDD, pParent)
	, m_uiAccount(_T(""))
	, m_uiPwd(_T(""))
{

}

CLOGIN::~CLOGIN()
{
}

void CLOGIN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_Classification);
	DDX_Text(pDX, IDC_EDIT1, m_uiAccount);
	DDX_Text(pDX, IDC_EDIT2, m_uiPwd);
}


BEGIN_MESSAGE_MAP(CLOGIN, CDialogEx)
	ON_BN_CLICKED(IDOK, &CLOGIN::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CLOGIN::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK2, &CLOGIN::OnBnClickedOk2)
END_MESSAGE_MAP()


// CLOGIN ��Ϣ�������


void CLOGIN::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������



	//CDialogEx::OnOK();
}


void CLOGIN::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	exit(0);

	//CDialogEx::OnCancel();
}


void CLOGIN::OnBnClickedOk2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//������ͼ�࣬����ֱ��GetDocument()

	//��ȡ�����ָ��
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();

	//��ȡ�ĵ���ָ��
	CMFC_MedicAdminDoc *pDoc = (CMFC_MedicAdminDoc*)pFrame->GetActiveDocument();

	//��ȡ�û���¼��
	CUserSet *pUserSet = pDoc->GetUserSet();

	//�����ݿ�
	if (!pUserSet->IsOpen())
	{
		pUserSet->Open();
	}

	//��ȡ�༭������
	UpdateData(TRUE);

	//��ȡ�û����
	int index = m_Classification.GetCurSel();

	CString type;
	m_Classification.GetLBText(index,type);

	if (type.IsEmpty() || m_uiAccount.IsEmpty() ||m_uiPwd.IsEmpty())
	{
		MessageBox(_T("�������¼��Ϣ"));
		return;
	}

#if 0

	//���ù�������
	CString SQL;
	SQL.Format(_T("account = '%s' and password = '%s' and classification = '%s'"),m_uiAccount,m_uiPwd,type);

	//����
	pUserSet->m_strFilter = SQL;

	//��ѯ
	pUserSet->Requery();

	//�ж���û������
	if (pUserSet->GetRecordCount() == 0)
	{
		MessageBox(_T("��¼ʧ�ܣ�"));
	}else{


		CDialogEx::OnCancel();
	}
#endif

	//CUser user;
	CUser *pUser = pDoc->GetUser();
	pUser->SetAllMember(m_uiAccount,m_uiPwd,type);
	pUser->SetUserSet(pUserSet);

	int ret = pUser->Login();
	if (ret == 0)
	{
		CDialogEx::OnCancel();
	}else if (ret == -2)
	{
		MessageBox(_T("��¼ʧ�ܣ�"));
	}
}


BOOL CLOGIN::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_Classification.SetCurSel(0);
	m_uiAccount=_T("abc");
	m_uiPwd=_T("250250");

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
}
