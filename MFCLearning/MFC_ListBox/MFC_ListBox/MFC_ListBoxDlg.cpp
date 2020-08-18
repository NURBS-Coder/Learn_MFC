
// MFC_ListBoxDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_ListBox.h"
#include "MFC_ListBoxDlg.h"
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


// CMFC_ListBoxDlg �Ի���



CMFC_ListBoxDlg::CMFC_ListBoxDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_ListBoxDlg::IDD, pParent)
	, m_str(_T(""))
	, m_int(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_ListBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str);
	DDX_Control(pDX, IDC_LIST1, m_ListBox);
	DDX_Control(pDX, IDC_COMBO1, m_ComboBox);
	DDX_Text(pDX, IDC_EDIT2, m_int);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_SBar);
}

BEGIN_MESSAGE_MAP(CMFC_ListBoxDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_ListBoxDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC_ListBoxDlg::OnBnClickedButton3)
	ON_LBN_SELCHANGE(IDC_LIST1, &CMFC_ListBoxDlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC_ListBoxDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFC_ListBoxDlg::OnBnClickedButton4)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CMFC_ListBoxDlg ��Ϣ�������

BOOL CMFC_ListBoxDlg::OnInitDialog()
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
	m_ComboBox.AddString(_T("333"));
	m_ComboBox.SetCurSel(1);

	m_SBar.SetScrollRange(0,100);
	m_SBar.SetScrollPos(50);
	m_int = 50;
	UpdateData(FALSE);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFC_ListBoxDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_ListBoxDlg::OnPaint()
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
HCURSOR CMFC_ListBoxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//�б�� CListBox��ʹ��
/*
	1.����ַ��� CListBox::AddString()
	2.ѡ���б���ĳһ������¼� LBN_SELCHANGE
		a)��ȡ��ǰѡ���� CListBox::GetCurSel()
		b)��ȡ��ǰλ������ CListBox::GetText()
	3.ɾ��ָ��λ���ַ��� CListBox::DeleteString()
	4.��ָ��λ�ò����ַ��� CListBox::InsertString()
*/



void CMFC_ListBoxDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	UpdateData(TRUE);

	if(m_str.GetLength() == 0){
		MessageBox(_T("����Ϊ�գ�"));
		return;
	}

	//�������
	m_ListBox.AddString(m_str);

	m_str.Empty();

	UpdateData(FALSE);
}


void CMFC_ListBoxDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//��ȡѡ����
	int n = m_ListBox.GetCurSel();

	//ɾ��
	m_ListBox.DeleteString(n);
}


void CMFC_ListBoxDlg::OnLbnSelchangeList1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//��ȡѡ����
	int n = m_ListBox.GetCurSel();

	//��ȡѡ��������
	m_ListBox.GetText(n,m_str);

	UpdateData(FALSE);

}


void CMFC_ListBoxDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	if(m_str.GetLength() == 0){
		MessageBox(_T("����Ϊ�գ�"));
		return;
	}

	//��ȡѡ����
	int n = m_ListBox.GetCurSel();

	//ɾ����������
	m_ListBox.DeleteString(n);


	//�������
	m_ListBox.InsertString(n,m_str);

	m_str.Empty();

	UpdateData(FALSE);

}


//��Ͽ� CComboBox��ʹ��
/*
	1.����ַ��� CComboBox::AddString()
	2.ѡ���б���ĳһ�� CComboBox::SetCurSel()
		a)��ȡ��ǰѡ���� CComboBox::GetCurSel()
		b)��ȡ��ǰλ������ CComboBox::GetLBText()
	3.ɾ��ָ��λ���ַ��� CComboBox::DeleteString()
	4.��ָ��λ�ò����ַ��� CComboBox::InsertString()
	5.�������ã�
		data���������ݣ��ֺŷָ�
		type����ͨ�������������б�
*/

void CMFC_ListBoxDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CString str;

	//��ȡѡ����
	int n = m_ComboBox.GetCurSel();

	//��ȡѡ��������
	m_ComboBox.GetLBText(n,str);

	MessageBox(str);
}


//������ CScrollBar��ʹ��
/*
	1.���ø����������������Сλ�� CScrollBar::SetScrollRange()
	2.��ȡ��������ǰλ�� CScrollBar::GetScrollPos()
	3.���ù�������ǰλ�� CScrollBar::SetScrollPos()
	4.����������¼������ڹ������������������������ڴ�����Ϣ WM_HSCROLL
			һ�����ڲ�ֹһ����������ͨ����������pScrollBar����
			һ���������������ͬ�Ĵ�������ͨ����������nSBCode����
			������λ���ɺ�������nPos���ݡ�ֻ�е���������ֵ��
		switch (nSBCode)
		{
		case SB_THUMBPOSITION:		//����
			break;
		case SB_LINELEFT:			//���ͷ
			break;
		case SB_LINERIGHT:			//�Ҽ�ͷ
			break;
		case SB_PAGELEFT:			//���ͷ�뻬��֮��
			break;	
		case SB_PAGERIGHT:			//�Ҽ�ͷ�뻬��֮��
			break;
		default:
			break;
		}
*/

void CMFC_ListBoxDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	if(pScrollBar = &m_SBar){
		switch (nSBCode)
		{
		case SB_THUMBPOSITION:		//����
			{
				m_SBar.SetScrollPos(nPos);
				m_int = nPos;
				UpdateData(FALSE);
				break;
			}
		case SB_LINELEFT:			//���ͷ
			{
				int temp = m_SBar.GetScrollPos() - 5;
				if(temp < 0){temp = 0;}
				m_SBar.SetScrollPos(temp);
				m_int = temp;
				UpdateData(FALSE);
				break;
			}
		case SB_LINERIGHT:			//�Ҽ�ͷ
			{
				int temp = m_SBar.GetScrollPos() + 5;
				if(temp > 100){temp = 100;}
				m_SBar.SetScrollPos(temp);
				m_int = temp;
				UpdateData(FALSE);
				break;
			}
		case SB_PAGELEFT:			//���ͷ�뻬��֮��
			{
				int temp = m_SBar.GetScrollPos() - 10;
				if(temp < 0){temp = 0;}
				m_SBar.SetScrollPos(temp);
				m_int = temp;
				UpdateData(FALSE);
				break;
			}
		case SB_PAGERIGHT:			//�Ҽ�ͷ�뻬��֮��
			{
				int temp = m_SBar.GetScrollPos() + 10;
				if(temp > 100){temp = 100;}
				m_SBar.SetScrollPos(temp);
				m_int = temp;
				UpdateData(FALSE);
				break;
			}
		default:
			break;
		}

	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

//΢����ť SpinControl��ʹ��
/*
	1.��������
		Auto Buddy -> True
		Set buddy integer -> True
	2.΢������ת����ť˳��Ȼ��ؼ���1��Ctrl + D��

*/