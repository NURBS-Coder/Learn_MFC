
// MFC_DocViewView.h : CMFC_DocViewView ��Ľӿ�
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class CMFC_DocViewView : public CFormView
{
protected: // �������л�����
	CMFC_DocViewView();
	DECLARE_DYNCREATE(CMFC_DocViewView)

public:
	enum{ IDD = IDD_MFC_DOCVIEW_FORM };

// ����
public:
	CMFC_DocViewDoc* GetDocument() const;

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
	virtual ~CMFC_DocViewView();
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
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	int m_uiId;
	CString m_uiName;
	int m_uiAge;
	int m_uiScore;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CButton m_ButtonEdit;
};

#ifndef _DEBUG  // MFC_DocViewView.cpp �еĵ��԰汾
inline CMFC_DocViewDoc* CMFC_DocViewView::GetDocument() const
   { return reinterpret_cast<CMFC_DocViewDoc*>(m_pDocument); }
#endif

