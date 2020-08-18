
// MainFrm.h : CMainFrame ��Ľӿ�
//

#pragma once



#include "User.h"
#include "MFC_MedicAdminDoc.h"
#include "MFC_MedicAdminView.h"
#include "UserTreeView.h"
#include "MedicListView.h"
#include "ChangePwdDlg.h"
#include "DeleteUserDlg.h"
#include "SeekMTypeDlg.h"


class CMainFrame : public CFrameWnd
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CStatusBar        m_wndStatusBar;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

public:
	//��ִ��ڶ���
	CSplitterWnd m_SpWnd;

	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	afx_msg void OnUpdateAddUser(CCmdUI *pCmdUI);
	afx_msg void OnUpdateDeleteUser(CCmdUI *pCmdUI);
	afx_msg void OnUpdateSearchUser(CCmdUI *pCmdUI);
	afx_msg void OnCloseWindow();
	afx_msg void OnClose();
	afx_msg void OnChangePwd();
	afx_msg void OnChangeUser();
	void SetMyEnable(CCmdUI *pCmdUI,CString type);
	afx_msg void OnDeleteUser();
	afx_msg void OnUpdateMedicStore(CCmdUI *pCmdUI);
	afx_msg void OnUpdateMedicSale(CCmdUI *pCmdUI);
	afx_msg void OnUpdateMedicClear(CCmdUI *pCmdUI);
	afx_msg void OnByType();
};


