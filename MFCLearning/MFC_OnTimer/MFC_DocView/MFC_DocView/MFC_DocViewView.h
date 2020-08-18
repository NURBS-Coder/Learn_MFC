
// MFC_DocViewView.h : CMFC_DocViewView 类的接口
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class CMFC_DocViewView : public CFormView
{
protected: // 仅从序列化创建
	CMFC_DocViewView();
	DECLARE_DYNCREATE(CMFC_DocViewView)

public:
	enum{ IDD = IDD_MFC_DOCVIEW_FORM };

// 特性
public:
	CMFC_DocViewDoc* GetDocument() const;

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
	virtual ~CMFC_DocViewView();
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

#ifndef _DEBUG  // MFC_DocViewView.cpp 中的调试版本
inline CMFC_DocViewDoc* CMFC_DocViewView::GetDocument() const
   { return reinterpret_cast<CMFC_DocViewDoc*>(m_pDocument); }
#endif

