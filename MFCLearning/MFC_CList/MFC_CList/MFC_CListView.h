
// MFC_CListView.h : CMFC_CListView 类的接口
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class CMFC_CListView : public CFormView
{
protected: // 仅从序列化创建
	CMFC_CListView();
	DECLARE_DYNCREATE(CMFC_CListView)

public:
	enum{ IDD = IDD_MFC_CLIST_FORM };

// 特性
public:
	CMFC_CListDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMFC_CListView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // MFC_CListView.cpp 中的调试版本
inline CMFC_CListDoc* CMFC_CListView::GetDocument() const
   { return reinterpret_cast<CMFC_CListDoc*>(m_pDocument); }
#endif

