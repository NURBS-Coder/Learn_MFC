
// MFC_OtherButtonDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_OtherButton.h"
#include "MFC_OtherButtonDlg.h"
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


// CMFC_OtherButtonDlg �Ի���



CMFC_OtherButtonDlg::CMFC_OtherButtonDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_OtherButtonDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_OtherButtonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_CheckBox);
}

BEGIN_MESSAGE_MAP(CMFC_OtherButtonDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_OtherButtonDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC_OtherButtonDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMFC_OtherButtonDlg ��Ϣ��������

BOOL CMFC_OtherButtonDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵������ӵ�ϵͳ�˵��С�

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

	// TODO: �ڴ����Ӷ���ĳ�ʼ������
	CheckRadioButton(IDC_RADIO1,IDC_RADIO3,IDC_RADIO1);

	m_CheckBox.SetCheck(1);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFC_OtherButtonDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի���������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFC_OtherButtonDlg::OnPaint()
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
HCURSOR CMFC_OtherButtonDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_OtherButtonDlg::OnBnClickedButton1()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������

	//RadioButton ��ѡ�ؼ���ʹ��
	/*
		1.ͬ���һ����ť����Group����ΪTRUE
		2.һ�鵥ѡ�ؼ�Ҫ����Ctrl + D������
		3.��ʼ����ѡ�� CWnd::CheckRadioButton()
		4.�жϰ�ť���£� CWnd::IsDlgButtonChecked()
	*/

	CString str;
	if(IsDlgButtonChecked(IDC_RADIO1))
	{
		 GetDlgItem(IDC_RADIO1)->GetWindowTextW(str);
	}
	if(IsDlgButtonChecked(IDC_RADIO2))
	{
		 GetDlgItem(IDC_RADIO2)->GetWindowTextW(str);
	}
		if(IsDlgButtonChecked(IDC_RADIO3))
	{
		 GetDlgItem(IDC_RADIO3)->GetWindowTextW(str);
	}

	MessageBox(str);
}


void CMFC_OtherButtonDlg::OnBnClickedButton2()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
		
	//CheckBox ��ѡ�ؼ���ʹ��
	/*
		1.���������� BOOL :UpdateData(TRUE),UpdateData(FALSE)
		2.��ʼ����ѡ�� CButton::SetCheck();
		4.�жϰ�ť״̬�� CButton::GetCheck();
	*/
		
	CString str,temp;
	if(IsDlgButtonChecked(IDC_CHECK1))
	{
		 GetDlgItem(IDC_CHECK1)->GetWindowTextW(temp);
		 str+=temp;
		 str+=_T("\r\n");
	}
	if(IsDlgButtonChecked(IDC_CHECK2))
	{
		 GetDlgItem(IDC_CHECK2)->GetWindowTextW(temp);
		 str+=temp;
		 str+=_T("\r\n");;
	}
		if(IsDlgButtonChecked(IDC_CHECK3))
	{
		 GetDlgItem(IDC_CHECK3)->GetWindowTextW(temp);
		 str+=temp;
		 str+=_T("\r\n");
	}

	MessageBox(str);
}