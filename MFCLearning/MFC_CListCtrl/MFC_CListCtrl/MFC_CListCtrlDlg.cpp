
// MFC_CListCtrlDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_CListCtrl.h"
#include "MFC_CListCtrlDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC_CListCtrlDlg �Ի���



CMFC_CListCtrlDlg::CMFC_CListCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_CListCtrlDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_CListCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
}

BEGIN_MESSAGE_MAP(CMFC_CListCtrlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CMFC_CListCtrlDlg ��Ϣ�������

BOOL CMFC_CListCtrlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	//ListCtrl�ؼ���ʹ��
	/*
		1.�������� view -> Report (����) ����
		2.���ýӿ�
			a�������б���	CListCtrl::SetExtendedStyle()
				���磺	LVS_EX_FULLROWSELECT	ѡ������
						LVS_EX_GRIDLINES		����ʽ
			b����ȡ�б��� CListCtrl::GetExtendedStyle()
			c������ĳ��		CListCtrl::InsertColumn()
			d) ����ĳ��		CListCtrl::InsertItem()
			e����������		CListCtrl::SetItemText()
	*/

	//��ʼ��ListCtrl�ؼ�
	//���÷����ʽ
	//m_ListCtrl.SetExtendedStyle(LVS_EX_GRIDLINES);
	m_ListCtrl.SetExtendedStyle(m_ListCtrl.GetExtendedStyle()|
		LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);

	//�������
	CString Head[] = {_T("����"), _T("����"), _T("�Ա�")}; 
	//������
	m_ListCtrl.InsertColumn(0,Head[0],LVCFMT_LEFT,50);
	m_ListCtrl.InsertColumn(1,Head[1],LVCFMT_LEFT,50);
	m_ListCtrl.InsertColumn(2,Head[2],LVCFMT_LEFT,50);
	//�����������ݣ���ȷ���У��ٲ�����
	for (int i = 0; i < 10; i++)
	{
		CString str;
		str.Format(_T("ѧ��%d"),i);
		//ȷ����
		m_ListCtrl.InsertItem(i,str);

		//������
		int j;j=1;
		m_ListCtrl.SetItemText(i,j++,_T("18"));
		m_ListCtrl.SetItemText(i,j++,_T("��"));
	}


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFC_CListCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFC_CListCtrlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFC_CListCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

