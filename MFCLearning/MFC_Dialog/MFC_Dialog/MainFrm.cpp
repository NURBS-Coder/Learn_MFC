
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "MFC_Dialog.h"

#include "MainFrm.h"

#include "MyDialog.h"

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
	ON_COMMAND(ID_DIALOG_EXEC, &CMainFrame::OnDialogExec)
	ON_COMMAND(ID_DIALOG_SHOW, &CMainFrame::OnDialogShow)
	ON_COMMAND(ID_DIALOG_Self, &CMainFrame::OnDialogSelf)
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

	//������ģ̬�Ի���
	Dialog_Show.Create(IDD_DIALOG_Show);

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



void CMainFrame::OnDialogExec()
{
	// TODO: �ڴ���������������
	//����ģ̬�Ի������
	CDialog Dialog_Exec(IDD_DIALOG_Exec);
	
	//���жԻ���
	Dialog_Exec.DoModal();	//��������������һֱͣ������

}


void CMainFrame::OnDialogShow()
{
	// TODO: �ڴ���������������
	//������ģ̬�Ի������
	//CDialog Dialog_Show;		//��Ӧ���þֲ�����������ģ̬�Ի���

	//Dialog_Show.Create(IDD_DIALOG_Show);	//����һ�Σ���ֵһ�ξ���

	//��ģ̬��������������ֱ�ӹ�ȥ��Dialog_Show����Ǿֲ������ͱ��ͷ���
	Dialog_Show.ShowWindow(SW_SHOWNORMAL);	
}


void CMainFrame::OnDialogSelf()
{
	// TODO: �ڴ���������������
	//�����Զ���ģ̬�Ի���
	//1������ͷ�ļ�
	//2����������
	MyDialog Dialog_Self;
	//3����ʾ����
	Dialog_Self.DoModal();	
}
