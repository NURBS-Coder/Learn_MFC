// Clogin.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_PicWatch.h"
#include "Clogin.h"
#include "afxdialogex.h"


// Clogin �Ի���

IMPLEMENT_DYNAMIC(Clogin, CDialogEx)

Clogin::Clogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(Clogin::IDD, pParent)
	, m_UserName(_T(""))
	, m_Password(_T(""))
{

}

Clogin::~Clogin()
{
}

void Clogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_UserName);
	DDX_Text(pDX, IDC_EDIT2, m_Password);
}


BEGIN_MESSAGE_MAP(Clogin, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Clogin::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &Clogin::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Clogin::OnBnClickedCancel)
	//ON_BN_CLICKED(IDC_BUTTON4, &Clogin::OnBnClickedButton4)
END_MESSAGE_MAP()


// Clogin ��Ϣ�������


void Clogin::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//�ж��û��������Ƿ���ȷ
	UpdateData(TRUE);
	if(m_UserName == _T("admin")&&m_Password == _T("123456"))
	{
		MessageBox(_T("��¼�ɹ���"),_T("��ʾ"),MB_ICONINFORMATION);
		CDialogEx::OnOK();
	}else{
		MessageBox(_T("�û������������"),_T("��ʾ"),MB_ICONWARNING);
	}
}


void Clogin::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
}


void Clogin::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(IDOK  == MessageBox(_T("ȷ��Ҫ�˳�����"),_T("��ʾ"),MB_OKCANCEL|MB_ICONQUESTION))
	{
		//�˳�����
		exit(1);
	}
	//CDialogEx::OnCancel();
}


//void Clogin::OnBnClickedButton4()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	OnBnClickedCancel();
//}
