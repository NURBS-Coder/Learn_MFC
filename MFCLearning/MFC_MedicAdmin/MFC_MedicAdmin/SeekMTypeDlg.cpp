// SeekMTypeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_MedicAdmin.h"
#include "SeekMTypeDlg.h"
#include "afxdialogex.h"


// CSeekMTypeDlg �Ի���

IMPLEMENT_DYNAMIC(CSeekMTypeDlg, CDialogEx)

CSeekMTypeDlg::CSeekMTypeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSeekMTypeDlg::IDD, pParent)
{

}

CSeekMTypeDlg::~CSeekMTypeDlg()
{
}

void CSeekMTypeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_MedicType);
}


BEGIN_MESSAGE_MAP(CSeekMTypeDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSeekMTypeDlg::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CSeekMTypeDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CSeekMTypeDlg ��Ϣ�������


void CSeekMTypeDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
}


BOOL CSeekMTypeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	m_MedicType.SetCurSel(0);


	return TRUE;  // return TRUE unless you set the focus to a control

	// �쳣: OCX ����ҳӦ���� FALSE
}


void CSeekMTypeDlg::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	int index = m_MedicType.GetCurSel();
	CString Type;
	m_MedicType.GetLBText(index,Type);

	if (Type.IsEmpty())
	{
		MessageBox(_T("���ݲ���Ϊ�գ�"));
		return;
	}

	//��ȡ���ݿ��¼��ָ��
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	//��ȡ�ĵ���ָ��
	CMFC_MedicAdminDoc *pDoc =(CMFC_MedicAdminDoc*)pFrame->GetActiveDocument();

	//��ȡҩƷ��¼��
	CMedicSet *pMedicSet = pDoc->GetMedicSet();

	CMedicSearch *pMS = pDoc->GetMedicSearch();

	//�������ݼ�¼��ָ��
	pMS->SetMedicSet(pMedicSet);

	//��ȡ�б���ͼ
	//ͨ���ĵ��ҵ���Ҫ���б���ͼ��һ���ĵ���Ӧ�����ͼ��ͨ��������� ��
	CMedicListView *pMedicListView = NULL;

	//��ȡ�ĵ��е�һ����ͼ��λ��
	POSITION pos = pDoc->GetFirstViewPosition();

	//������ͼ����Ѱ������ͼ
	while (pos != NULL)
	{
		//���ݵ�ǰλ�û�ȡ��ͼָ�룬����λ������
		CView *pView = pDoc->GetNextView(pos);

		//�ж��ǲ���Ѱ�ҵ�����ͼ
		if (pView->IsKindOf(RUNTIME_CLASS(CMedicListView)))
		{
			//����ת����CView����������ת��
			pMedicListView = (CMedicListView *)pView;
			break;
		}
	}

	if(pMedicListView == NULL)
	{
		return ;
	}

	//������ͼָ��
	CListCtrl *p = &pMedicListView->GetListCtrl();
	pMS->SetListCtrl(p);

	pMS->SearchByType(Type);

}
