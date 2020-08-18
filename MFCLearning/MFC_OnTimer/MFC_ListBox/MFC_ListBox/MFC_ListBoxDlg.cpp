
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
	, m_Edit(_T(""))
	, m_Pos(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_ListBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Edit);
	DDX_Control(pDX, IDC_LIST1, m_ListBox);
	DDX_Control(pDX, IDC_COMBO1, m_CComboBox);
	DDX_Text(pDX, IDC_EDIT2, m_Pos);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_SBar);
}

BEGIN_MESSAGE_MAP(CMFC_ListBoxDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_ListBoxDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC_ListBoxDlg::OnBnClickedButton2)
	ON_LBN_SELCHANGE(IDC_LIST1, &CMFC_ListBoxDlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC_ListBoxDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFC_ListBoxDlg::OnBnClickedButton4)
	ON_WM_HSCROLL()
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CMFC_ListBoxDlg::OnDeltaposSpin1)
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
	//����Ĭ��ֵ
	m_CComboBox.SetCurSel(1);

	//��ʼ��ˮƽ��������ֵ
	m_Pos = 50;
	UpdateData(FALSE);
	//����ˮƽ��������λ��
	m_SBar.SetScrollRange(0,100);
	m_SBar.SetScrollPos(m_Pos);


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



void CMFC_ListBoxDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//�б��CListBox ��ʹ��
	/*
		1.���б������ַ���		CListBox::AddString()
		2.ѡ���б��ĳһ��Զ������¼���LBN_SELCHANGE
			a����ȡ��ǰѡ����		CListBox::GetCurSel()
			b����ȡָ��λ�õ�����	CListBox::GetText()
		3.ɾ��ָ��λ���ַ���		CListBox::DeleteString()
		4.��ָ��λ�ò����ַ���		CListBox::InsertString()
	*/

	//��ȡ�༭������
	UpdateData(TRUE);

	if(m_Edit.GetLength() > 0)
	{
		m_ListBox.AddString(m_Edit);
		m_Edit.Empty();
		UpdateData(FALSE);

	}else{
		MessageBox(_T("�������Ϊ�գ�"));
	}


}


void CMFC_ListBoxDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//��ȡ��ǰѡ����
	int i = m_ListBox.GetCurSel();

	//ɾ����ǰѡ����
	m_ListBox.DeleteString(i);
}


void CMFC_ListBoxDlg::OnLbnSelchangeList1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//��ȡ��ǰѡ����
	int i = m_ListBox.GetCurSel();
	//��ȡ��ǰѡ������
	m_ListBox.GetText(i,m_Edit);
	//���µ��༭��
	UpdateData(FALSE);
}


void CMFC_ListBoxDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//��ȡ��ǰ�༭������
	UpdateData(TRUE);
	if(m_Edit.GetLength() > 0)
	{	
		//��ȡ��ǰѡ����
		int i = m_ListBox.GetCurSel();
		//ɾ����λ������
		m_ListBox.DeleteString(i);
		//�ڸ�λ�ò�������
		m_ListBox.InsertString(i,m_Edit);
		//��ձ༭��
		m_Edit = _T("");
		UpdateData(FALSE);
	}else{
		MessageBox(_T("�޸�����Ϊ�գ�"));
	}
}


void CMFC_ListBoxDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//��Ͽ� CComboBox��ʹ��
	/*
		1.��ȡ���� CComboBox::GetLBText
			�����ӿ��� CListBox ���÷�����
		2.��������
			a��data ���������ݣ���ͬ������Ӣ�ķֺ�";"�ָ�
			b��type ���򵥡������������б�
	*/

	//��ȡ��ǰѡ����
	int i = m_CComboBox.GetCurSel();
	//��ȡ��ǰѡ������
	CString str;
	m_CComboBox.GetLBText(i,str);
	MessageBox(str);
}


void CMFC_ListBoxDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//ˮƽ������ HorizontalScrollBar��ʹ��
	/*
		1.���ø�������������С�����λ��	CScrollBar::SetScrollRange()
		2.��ȡһ���������ĵ�ǰλ��			CScrollBar::GetScrollPos()
		3.����һ���������ĵ�ǰλ��			CScrollBar::SetScrollPos()
		4.��Ϣ����
			a)ˮƽ���������������丸����(�Ի�����)��WM_HSCROLL��Ϣ�Ĵ�����
			b)�ô���������OnTimer�Ĵ�����,Ҫ����ô����µ�����ˮƽ������,��ָ��pScrollBar����
			c)nPosָʾ����λ�ã�ֻ�е������ʱ����ֵ��������0.
		5.��������λ�ù�ϵ
				switch (nSBCode)
				{
				case SB_THUMBPOSITION:	//����λ��
					break;
				case SB_LINELEFT:		//���ͷλ��
					break;
				case SB_LINERIGHT:		//�Ҽ�ͷλ��
					break;
				case SB_PAGELEFT:		//���ͷ�뻬���м�λ��
					break;
				case SB_PAGERIGHT:		//�Ҽ�ͷ�뻬���м�λ��
					break;
				default:
					break;
				}
			
	*/

	if (pScrollBar = &m_SBar)
	{
		int tempPos ;
		switch (nSBCode)
		{
		case SB_THUMBPOSITION:	//����λ��
			{
				m_SBar.SetScrollPos(nPos);
				m_Pos = nPos;
				UpdateData(FALSE);
				break;
			}
		case SB_LINELEFT:		//���ͷλ��
			{
				//��ȡ���鵱ǰλ��
				tempPos = m_SBar.GetScrollPos() - 5;
				if(tempPos < 0){tempPos =  0;}
				m_SBar.SetScrollPos(tempPos);
				m_Pos = tempPos;
				UpdateData(FALSE);
				break;
			}
		case SB_LINERIGHT:		//�Ҽ�ͷλ��
			{
				//��ȡ���鵱ǰλ��
				tempPos = m_SBar.GetScrollPos() + 5;
				if(tempPos > 100){tempPos =  100;}
				m_SBar.SetScrollPos(tempPos);
				m_Pos = tempPos;
				UpdateData(FALSE);
				break;
			}
		case SB_PAGELEFT:		//���ͷ�뻬���м�λ��
			{
				//��ȡ���鵱ǰλ��
				tempPos = m_SBar.GetScrollPos() - 10;
				if(tempPos < 0){tempPos =  0;}
				m_SBar.SetScrollPos(tempPos);
				m_Pos = tempPos;
				UpdateData(FALSE);
				break;
			}
		case SB_PAGERIGHT:		//�Ҽ�ͷ�뻬���м�λ��
			{
				//��ȡ���鵱ǰλ��
				tempPos = m_SBar.GetScrollPos() + 10;
				if(tempPos > 100){tempPos =  100;}
				m_SBar.SetScrollPos(tempPos);
				m_Pos = tempPos;
				UpdateData(FALSE);
				break;
			}
		default:
			break;
		}

	}




	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CMFC_ListBoxDlg::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//΢����ѡת����ť SpinControl ��ʹ��
	/*
		1.��������  Auto Buddy -> True
					Set Buddy Integer -> True
		2.΢����ѡת����ť��˳���Buddy�ռ��һ��Ctrl + D��
	*/

	*pResult = 0;
}
