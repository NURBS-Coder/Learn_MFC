// ChangePwdDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_MedicAdmin.h"
#include "ChangePwdDlg.h"
#include "afxdialogex.h"


// CChangePwdDlg �Ի���

IMPLEMENT_DYNAMIC(CChangePwdDlg, CDialogEx)

CChangePwdDlg::CChangePwdDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChangePwdDlg::IDD, pParent)
	, m_uiNewPwd(_T(""))
	, m_uiOldPwd(_T(""))
	, m_uiSurePwd(_T(""))
	, m_uiAccount(_T(""))
{

}

CChangePwdDlg::~CChangePwdDlg()
{
}

void CChangePwdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, m_uiNewPwd);
	DDX_Text(pDX, IDC_EDIT2, m_uiOldPwd);
	DDX_Text(pDX, IDC_EDIT4, m_uiSurePwd);
	DDX_Text(pDX, IDC_EDIT1, m_uiAccount);
}


BEGIN_MESSAGE_MAP(CChangePwdDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CChangePwdDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON2, &CChangePwdDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDCANCEL, &CChangePwdDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &CChangePwdDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CChangePwdDlg ��Ϣ�������


void CChangePwdDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
}


BOOL CChangePwdDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	CMFC_MedicAdminDoc *pDoc =(CMFC_MedicAdminDoc*)pFrame->GetActiveDocument();

	CUser *pUser = pDoc->GetUser();

	m_uiAccount = pUser->GetAccount();


	UpdateData(FALSE);



	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CChangePwdDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMFC_MedicAdminDoc *pDoc =(CMFC_MedicAdminDoc*)pFrame->GetActiveDocument();
	CUser *pUser = pDoc->GetUser();

	UpdateData(TRUE);

	int ret = pUser->ChangePwd(m_uiOldPwd,m_uiNewPwd,m_uiSurePwd);
	switch (ret)
	{
	case -2:
		MessageBox(_T("���ݲ���Ϊ�գ�"));
		break;
	case -3:
		MessageBox(_T("�¾����벻����ͬ��"));
		break;
	case -4:
		MessageBox(_T("�������������벻һ�£�"));
		break;
	case -5:
		MessageBox(_T("���ܸ��Ĵ��û���"));
		break;
	case -6:
		MessageBox(_T("����ʧ�ܣ�"));
		break;
	case -7:
		MessageBox(_T("�����벻��ȷ��"));
		break;
	default:
		MessageBox(_T("������ĳɹ���"));
		break;
	}


}

void CChangePwdDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CDialogEx::OnCancel();

}


void CChangePwdDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}



