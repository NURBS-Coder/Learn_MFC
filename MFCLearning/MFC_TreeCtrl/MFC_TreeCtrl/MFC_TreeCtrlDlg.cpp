
// MFC_TreeCtrlDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_TreeCtrl.h"
#include "MFC_TreeCtrlDlg.h"
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


// CMFC_TreeCtrlDlg �Ի���



CMFC_TreeCtrlDlg::CMFC_TreeCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_TreeCtrlDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_TreeCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_TreeCtrl);
}

BEGIN_MESSAGE_MAP(CMFC_TreeCtrlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CMFC_TreeCtrlDlg ��Ϣ�������

BOOL CMFC_TreeCtrlDlg::OnInitDialog()
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


	//���ؼ�CTreeCtrl��ʹ��
	/*
		1.������������
			has buttons -> true
			has lines -> true
			lines at root -> true
		2.ʹ������
			a) �����Զ���ͼ��
				1.��ȡӦ�ó������ָ�� AfxGetApp()
				2.�����Զ���ͼ�� CWinApp::LoadIcon()
			b) ����ͼ���б�
				1. .h�ļ����ж���ͼ���б�(CImageList)����,�����Ǿֲ����������ܱ��ͷ�
				2. ����ͼ���б�		CImageList::Create()
				3. ͼ���б�׷��ͼ��	CImageList::Add()
			c) ����ͼ��״̬�б�		CTreeCtrl::SetImageList()
			d) �����ؼ�����ڵ�		CTreeCtrl::InsertItem()
			e) ����Ĭ�ϵ�ѡ����		CTreeCtrl::SelectItem()
	*/

	//a) �����Զ���ͼ��
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
	m_TreeCtrl.SetImageList(&m_imagelist,TVSIL_NORMAL);

	//d) �����ؼ�����ڵ�
	//InsertItem(�ڵ���,�ڵ�ͼ��,�ڵ�ѡ��ʱͼ��,��һ�ڵ�)
	//���ڵ�
	HTREEITEM root = m_TreeCtrl.InsertItem(_T("���ڵ�"),0,1,NULL);
	//���ڵ�
	HTREEITEM father = m_TreeCtrl.InsertItem(_T("���ڵ�"),1,1,root);
	//�ӽڵ�
	HTREEITEM son1 = m_TreeCtrl.InsertItem(_T("�ӽڵ�1"),2,2,father);
	HTREEITEM son2 = m_TreeCtrl.InsertItem(_T("�ӽڵ�2"),3,3,father);

	//e) ����Ĭ�ϵ�ѡ����
	m_TreeCtrl.SelectItem(father);	//��ʾ��ѡ�е���һ��ڵ�

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFC_TreeCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_TreeCtrlDlg::OnPaint()
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
HCURSOR CMFC_TreeCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

