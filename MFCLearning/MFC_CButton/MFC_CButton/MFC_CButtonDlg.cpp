
// MFC_CButtonDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_CButton.h"
#include "MFC_CButtonDlg.h"
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


// CMFC_CButtonDlg �Ի���



CMFC_CButtonDlg::CMFC_CButtonDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_CButtonDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_CButtonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_CButton);
	DDX_Control(pDX, IDC_BUTTON2, m_MyButton);
}

BEGIN_MESSAGE_MAP(CMFC_CButtonDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_CButtonDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMFC_CButtonDlg ��Ϣ�������

BOOL CMFC_CButtonDlg::OnInitDialog()
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
	//���ð�ťͼƬ1
	m_CButton.SetIcon(AfxGetApp()->LoadIconW(IDI_ICON1));

	//���ð�ťͼƬ2
	m_MyButton.SetWindowTextW(_T("���ܵİ�ť"));
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_BITMAP1);
	//��ȡλͼ��С
	BITMAP bmp;
	bitmap.GetBitmap(&bmp);
	//����ť����λͼ
	//m_MyButton.SetBitmap(bitmap);
	//����ͼƬ��С���ð�ť��С
	//m_MyButton.MoveWindow(20, 20, bmp.bmWidth,bmp.bmHeight);
	//m_MyButton.m_Width=bmp.bmWidth;
	//m_MyButton.m_Height=bmp.bmHeight;

	//����·������ť����λͼ
#define HBMP(filepath, width, height) (HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,0,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION )
	m_MyButton.SetBitmap(HBMP(_T("../MFC_CButton/res/q10.bmp"),100,100));
	m_MyButton.MoveWindow(200, 200, 100,100);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFC_CButtonDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_CButtonDlg::OnPaint()
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
HCURSOR CMFC_CButtonDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_CButtonDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	int x = rand() % 300;
	int y = rand() % 300;

	//��ť�ƶ�
	m_CButton.MoveWindow(x, y, 100, 100);

}
