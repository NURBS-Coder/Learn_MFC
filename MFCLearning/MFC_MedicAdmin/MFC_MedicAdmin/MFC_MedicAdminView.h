
// MFC_MedicAdminView.h : CMFC_MedicAdminView ��Ľӿ�
//

#pragma once

#include "resource.h"


class CMFC_MedicAdminView : public CFormView
{
protected: // �������л�����
	CMFC_MedicAdminView();
	DECLARE_DYNCREATE(CMFC_MedicAdminView)

public:
	enum{ IDD = IDD_MFC_MEDICADMIN_FORM };

// ����
public:
	CMFC_MedicAdminDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMFC_MedicAdminView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
};

#ifndef _DEBUG  // MFC_MedicAdminView.cpp �еĵ��԰汾
inline CMFC_MedicAdminDoc* CMFC_MedicAdminView::GetDocument() const
   { return reinterpret_cast<CMFC_MedicAdminDoc*>(m_pDocument); }
#endif

