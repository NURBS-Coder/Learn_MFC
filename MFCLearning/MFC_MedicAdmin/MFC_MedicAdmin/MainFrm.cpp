
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "MFC_MedicAdmin.h"

#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_UPDATE_COMMAND_UI(ID_ADD_USER, &CMainFrame::OnUpdateAddUser)
	ON_UPDATE_COMMAND_UI(ID_DELETE_USER, &CMainFrame::OnUpdateDeleteUser)
	ON_UPDATE_COMMAND_UI(ID_SEARCH_USER, &CMainFrame::OnUpdateSearchUser)
	ON_COMMAND(ID_CLOSE_WINDOW, &CMainFrame::OnCloseWindow)
	ON_WM_CLOSE()
	ON_COMMAND(ID_CHANGE_PWD, &CMainFrame::OnChangePwd)
	ON_COMMAND(ID_CHANGE_USER, &CMainFrame::OnChangeUser)
	ON_COMMAND(ID_DELETE_USER, &CMainFrame::OnDeleteUser)
	ON_UPDATE_COMMAND_UI(ID_MEDIC_STORE, &CMainFrame::OnUpdateMedicStore)
	ON_UPDATE_COMMAND_UI(ID_MEDIC_SALE, &CMainFrame::OnUpdateMedicSale)
	ON_UPDATE_COMMAND_UI(ID_MEDIC_CLEAR, &CMainFrame::OnUpdateMedicClear)
	ON_COMMAND(ID_BY_TYPE, &CMainFrame::OnByType)
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

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

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



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: �ڴ����ר�ô����/����û���

	//����һ��һ�����еľ�̬�ָ�������
	m_SpWnd.CreateStatic(this,1,2);

	//������ͼ
	m_SpWnd.CreateView(0,0,RUNTIME_CLASS(CUserTreeView),CSize(230,600),pContext);
	m_SpWnd.CreateView(0,1,RUNTIME_CLASS(CMedicListView),CSize(720,600),pContext);


	//��д�����û��ͻ�������������Ĭ�Ϲ���
	return TRUE;
	//return CFrameWnd::OnCreateClient(lpcs, pContext);
}

void CMainFrame::OnChangePwd()
{
	// TODO: �ڴ���������������
	CChangePwdDlg pChangPwdLog;
	pChangPwdLog.DoModal();
}


void CMainFrame::OnChangeUser()
{
	// TODO: �ڴ���������������
}

void CMainFrame::SetMyEnable(CCmdUI *pCmdUI,CString type)
{
	CMFC_MedicAdminDoc *pDoc = (CMFC_MedicAdminDoc *)GetActiveDocument();

	CUser *pUser = pDoc -> GetUser();

	if (pUser->GetType() == type)
	{
		pCmdUI->Enable(TRUE);
	}else{
		pCmdUI->Enable(FALSE);
	}
}

//�˵�����,����Ա����Ȩ��
void CMainFrame::OnUpdateAddUser(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	SetMyEnable(pCmdUI,_T("����Ա"));

}


void CMainFrame::OnUpdateDeleteUser(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������

	SetMyEnable(pCmdUI,_T("����Ա"));
}


void CMainFrame::OnUpdateSearchUser(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������

	SetMyEnable(pCmdUI,_T("����Ա"));
}


void CMainFrame::OnCloseWindow()
{
	// TODO: �ڴ���������������

	//exit(0);

	OnClose();
}


void CMainFrame::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CFrameWnd::OnClose();
}


void CMainFrame::OnDeleteUser()
{
	// TODO: �ڴ���������������
	CDeleteUserDlg dlg;
	dlg.DoModal();
}


void CMainFrame::OnUpdateMedicStore(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	SetMyEnable(pCmdUI,_T("��ҩԱ"));
}


void CMainFrame::OnUpdateMedicSale(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	SetMyEnable(pCmdUI,_T("��ҩԱ"));
}


void CMainFrame::OnUpdateMedicClear(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	SetMyEnable(pCmdUI,_T("��ҩԱ"));
}


void CMainFrame::OnByType()
{
	// TODO: �ڴ���������������
	CSeekMTypeDlg dlg;
	dlg.DoModal();

}
