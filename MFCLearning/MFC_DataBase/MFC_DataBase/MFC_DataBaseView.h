
// MFC_DataBaseView.h : CMFC_DataBaseView ��Ľӿ�
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class CMFC_DataBaseView : public CFormView
{
protected: // �������л�����
	CMFC_DataBaseView();
	DECLARE_DYNCREATE(CMFC_DataBaseView)

public:
	enum{ IDD = IDD_MFC_DATABASE_FORM };

// ����
public:
	CMFC_DataBaseDoc* GetDocument() const;

// ����
public:
	//�ĵ�ָ��
	CMFC_DataBaseDoc *pDoc;
	//���ݿ��¼ָ�뼯
	CMFC_DataBaseSet *pSet;




// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMFC_DataBaseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	int m_uiId;
	CString m_uiName;
	int m_uiAge;
	double m_uiScore;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton6();
	bool m_isEdit;
	CButton m_ButtonEdit;
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	bool m_isFilter;
	CButton m_buttonFilter;
};

#ifndef _DEBUG  // MFC_DataBaseView.cpp �еĵ��԰汾
inline CMFC_DataBaseDoc* CMFC_DataBaseView::GetDocument() const
   { return reinterpret_cast<CMFC_DataBaseDoc*>(m_pDocument); }
#endif

