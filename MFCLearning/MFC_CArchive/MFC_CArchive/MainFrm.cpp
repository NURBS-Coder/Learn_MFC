
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "MFC_CArchive.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_CARCHIVE_WRITE, &CMainFrame::OnCarchiveWrite)
	ON_COMMAND(ID_CARCHIVE_READ, &CMainFrame::OnCarchiveRead)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: �������Ҫ��ͣ������������ɾ��������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}

// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������

//�ĵ����л��������Ʋ����ļ��� CArchive��ʹ��
//���л��� �Զ����Ʒ�ʽд�ļ�
//�����л��� �Զ����Ʒ�ʽ���ļ�


void CMainFrame::OnCarchiveWrite()
{
	// TODO: �ڴ���������������
	//��CArchive��д�ļ�
	/*
		1. �����ļ����� CFile
		2. ��д��ʽ���ļ� CFile::Open()
		3. �������л����󣬲����ļ�������һ�� CArchive
			CAchive::store �����ݱ��浽�鵵�ļ��С� ����CFileд����
		4. ��������д���ݣ��൱�����ļ�д���ݣ�
			ar << a << b << c
		5. �Ͽ����������ļ��Ĺ��� CArchive::Close()
		6. �ر��ļ� CFile::Close()
	*/

	//1. �����ļ����� CFile
	CFile file;

	//2. ��д��ʽ���ļ� CFile::Open()
	BOOL isOk = file.Open(_T("../demo.txt"),CFile::modeCreate |CFile::modeWrite);
	if (isOk == FALSE)
	{
		return ;
	}

	//3. �������л����󣬲����ļ�������һ�� CArchive
	//CArchive�����������������������CArchive���ǲ����ļ�
	CArchive ar(&file, CArchive::store);

	//4. ��������д���ݣ��൱�����ļ�д���ݣ�
	//��cout�÷�һ��
	int a = 10;
	CString str = _T("ABC");
	TCHAR ch = 't';		
	//��ͷ��������
	//��������ar,arָ���ļ�,��д�ļ�
	ar << a << str << ch;

	//5. �Ͽ����������ļ��Ĺ��� CArchive::Close()
	ar.Close();

	//6. �ر��ļ� CFile::Close()
	file.Close();
}


void CMainFrame::OnCarchiveRead()
{
	// TODO: �ڴ���������������
	//��CArchive����ļ�
	/*
		1. �����ļ����� CFile
		2. �Զ���ʽ���ļ� CFile::Open()
		3. �������л����󣬲����ļ�������һ�� CArchive
			CAchive::load �ӹ鵵�ļ���װ�����ݡ� CFileֻ��
		4. ͨ��������������д���ݣ��൱�ڴ��ļ������ݣ�
			ar >> a >> b >> c
		5. �Ͽ����������ļ��Ĺ��� CArchive::Close()
		6. �ر��ļ� CFile::Close()
	*/

	//1. �����ļ����� CFile
	CFile file;

	//2. �Զ���ʽ���ļ� CFile::Open()
	BOOL isOk = file.Open(_T("../demo.txt"),CFile::modeRead);
	if (isOk == FALSE)
	{
		return ;
	}

	//3. �������л����󣬲����ļ�������һ�� CArchive
	//CArchive�����������������������CArchive���ǲ����ļ�
	CArchive ar(&file, CArchive::load);

	//4. ͨ��������������д���ݣ��൱�ڴ��ļ������ݣ�
	//��cout�÷�һ��
	int a;
	CString str;
	TCHAR ch;		
	//��ͷ��������
	//�����������,arָ���ļ�,�����ļ�
	ar >> a >> str >> ch;

	CString buf;
	buf.Format(_T("%d, %s, %c"),a,str,ch);
	MessageBox(buf);

	//5. �Ͽ����������ļ��Ĺ��� CArchive::Close()
	ar.Close();

	//6. �ر��ļ� CFile::Close()
	file.Close();
}
