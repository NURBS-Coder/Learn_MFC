
// MFC_CListView.h : CMFC_CListView ��Ľӿ�
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class CMFC_CListView : public CFormView
{
protected: // �������л�����
	CMFC_CListView();
	DECLARE_DYNCREATE(CMFC_CListView)

public:
	enum{ IDD = IDD_MFC_CLIST_FORM };

// ����
public:
	CMFC_CListDoc* GetDocument() const;

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
	virtual ~CMFC_CListView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CButton m_ButtonPre;
	CButton m_ButtonNext;
	CButton m_ButtonAdd;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	int m_uiId;
	CString m_uiName;
	int m_uiAge;
	double m_uiScore;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};

#ifndef _DEBUG  // MFC_CListView.cpp �еĵ��԰汾
inline CMFC_CListDoc* CMFC_CListView::GetDocument() const
   { return reinterpret_cast<CMFC_CListDoc*>(m_pDocument); }
#endif

