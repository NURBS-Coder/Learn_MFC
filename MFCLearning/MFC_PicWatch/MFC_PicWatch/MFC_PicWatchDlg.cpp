
// MFC_PicWatchDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_PicWatch.h"
#include "MFC_PicWatchDlg.h"
#include "afxdialogex.h"

#include "Clogin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//����·������ť����λͼ
#define HBMP(filepath, width, height) (HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,0,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION )

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


// CMFC_PicWatchDlg �Ի���



CMFC_PicWatchDlg::CMFC_PicWatchDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_PicWatchDlg::IDD, pParent)
	, m_PicIndex(1)
	, m_isPlay(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_PicWatchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFC_PicWatchDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_PicWatchDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC_PicWatchDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC_PicWatchDlg::OnBnClickedButton2)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDOK, &CMFC_PicWatchDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMFC_PicWatchDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CMFC_PicWatchDlg ��Ϣ�������

BOOL CMFC_PicWatchDlg::OnInitDialog()
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

	//��ʾ��½����
	Clogin MyLogin;
	MyLogin.DoModal();


	//��ȡ�ؼ�
	m_bmp = (CStatic*)GetDlgItem(IDC_STATIC_BMP);

	//������ʾ���
	m_bmp->ModifyStyle(0xf, SS_BITMAP|SS_CENTERIMAGE);

	//��ȡ�ؼ���С
	CRect rect;
	m_bmp->GetWindowRect(&rect);
	
	//����·������ť����λͼ
	m_bmp->SetBitmap(HBMP(_T("..//Pic//1.bmp"),rect.Width(),rect.Height()));


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFC_PicWatchDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_PicWatchDlg::OnPaint()
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
HCURSOR CMFC_PicWatchDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_PicWatchDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//����·������ť����λͼ
	CString str;
	m_PicIndex-=1;
	if(m_PicIndex<1){m_PicIndex=6;}
	str.Format(_T("..//Pic//%d.bmp"),m_PicIndex);

	//��ȡ�ؼ���С
	CRect rect;
	m_bmp->GetWindowRect(&rect);

	m_bmp->SetBitmap(HBMP(str,rect.Width(),rect.Height()));
}


void CMFC_PicWatchDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	m_PicIndex+=1;
	if(m_PicIndex>6){m_PicIndex=1;}
	str.Format(_T("..//Pic//%d.bmp"),m_PicIndex);

	//��ȡ�ؼ���С
	CRect rect;
	m_bmp->GetWindowRect(&rect);

	m_bmp->SetBitmap(HBMP(str,rect.Width(),rect.Height()));
}


void CMFC_PicWatchDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_isPlay =! m_isPlay;
	if(m_isPlay)
	{
		GetDlgItem(IDC_BUTTON1)->EnableWindow(0);
		GetDlgItem(IDC_BUTTON3)->EnableWindow(0);

		GetDlgItem(IDC_BUTTON2)->SetWindowTextW(_T("��ͣ����"));

		SetTimer(1,1000,NULL);
	}else{
		GetDlgItem(IDC_BUTTON1)->EnableWindow(1);
		GetDlgItem(IDC_BUTTON3)->EnableWindow(1);

		GetDlgItem(IDC_BUTTON2)->SetWindowTextW(_T("�Զ�����"));

		KillTimer(1);
	}
}


void CMFC_PicWatchDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	CString str;
	m_PicIndex+=1;
	if(m_PicIndex>6){m_PicIndex=1;}
	str.Format(_T("..//Pic//%d.bmp"),m_PicIndex);
	
	//��ȡ�ؼ���С
	CRect rect;
	m_bmp->GetWindowRect(&rect);

	m_bmp->SetBitmap(HBMP(str,rect.Width(),rect.Height()));

	CDialogEx::OnTimer(nIDEvent);
}


void CMFC_PicWatchDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CMFC_PicWatchDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}
