
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "MFCSingleDoc.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
	ON_COMMAND(ID_TEST, &CMainFrame::OnTest)
	ON_COMMAND(ID_TEST1_AAAAA, &CMainFrame::OnTest1Aaaaa)
	ON_COMMAND(ID_TEST1_BBBBB, &CMainFrame::OnTest1Bbbbb)
	ON_UPDATE_COMMAND_UI(ID_TEST1_AAAAA, &CMainFrame::OnUpdateTest1Aaaaa)
	ON_WM_TIMER()
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
	: m_isUpdate(false)
{
	// TODO: �ڴ���ӳ�Ա��ʼ������

	//�ڿ�����ȡӦ�ó�����ָ�룬����ico
	icon[0] = AfxGetApp()->LoadIconW(IDI_ICON1);
	icon[1] = AfxGetApp()->LoadIconW(IDI_ICON2);
	icon[2] = AfxGetApp()->LoadIconW(IDI_ICON3);
	icon[3] = AfxGetApp()->LoadIconW(IDI_ICON4);
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

	SetTimer(1,500,NULL);

	//�˵����
	//��ȡ���˵�
	CMenu *MainMenu = GetMenu();
	//��ȡ�Ӳ˵�
	CMenu *FileMenu = MainMenu->GetSubMenu(0);
	//ͨ��λ��MF_BYPOSITION��ȡѡ��
	FileMenu->CheckMenuItem(0,MF_BYPOSITION|MF_CHECKED);
	//ͨ��λ��MF_BYPOSITION��ȡѡ��
	FileMenu->CheckMenuItem(ID_FILE_PRINT,MF_BYCOMMAND|MF_CHECKED);

	//����Ĭ����Ӵ֣�һ���˵���ֻ��һ��Ĭ��
	FileMenu->SetDefaultItem(2,TRUE);

	//����
	m_bAutoMenuEnable= false;
	FileMenu->EnableMenuItem(ID_FILE_PRINT,1);

	//�Ƴ��˵���
	SetMenu(NULL);

	//���ز˵�
	CMenu menu;
	menu.LoadMenuW(IDR_MAINFRAME);
	SetMenu(&menu);

	//����
	menu.Detach();		//���Ʋ��ͷžֲ��˵���������Ȼ������

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



void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ



	CFrameWnd::OnLButtonDown(nFlags, point);
}


void CMainFrame::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CFrameWnd::OnPaint()
}


void CMainFrame::OnTest()
{
	// TODO: �ڴ���������������
	MessageBox(_T("HHHHHHH"));
}




void CMainFrame::OnTest1Aaaaa()
{
	// TODO: �ڴ���������������

}


//aaaa�˵��ĸ��£��˵��Զ�����ʱ����
void CMainFrame::OnUpdateTest1Aaaaa(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	if(m_isUpdate)
	{
		pCmdUI->Enable(TRUE);
	}else{
		pCmdUI->Enable(FALSE);
	}
}

//bbbbb�Ĵ�����
void CMainFrame::OnTest1Bbbbb()
{
	// TODO: �ڴ���������������
	m_isUpdate = !m_isUpdate;
}




void CMainFrame::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	static int i = 0;

	//�޸�ͼ��
	//���������WinAPI�����Ըĺܶණ��
	SetClassLong(m_hWnd, GCL_HICON,(LONG)icon[i]);
	i++;
	if(i==4){i=0;}


	CFrameWnd::OnTimer(nIDEvent);
}
