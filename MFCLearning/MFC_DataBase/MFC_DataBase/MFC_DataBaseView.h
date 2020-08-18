
// MFC_DataBaseView.h : CMFC_DataBaseView 类的接口
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class CMFC_DataBaseView : public CFormView
{
protected: // 仅从序列化创建
	CMFC_DataBaseView();
	DECLARE_DYNCREATE(CMFC_DataBaseView)

public:
	enum{ IDD = IDD_MFC_DATABASE_FORM };

// 特性
public:
	CMFC_DataBaseDoc* GetDocument() const;

// 操作
public:
	//文档指针
	CMFC_DataBaseDoc *pDoc;
	//数据库记录指针集
	CMFC_DataBaseSet *pSet;




// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMFC_DataBaseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // MFC_DataBaseView.cpp 中的调试版本
inline CMFC_DataBaseDoc* CMFC_DataBaseView::GetDocument() const
   { return reinterpret_cast<CMFC_DataBaseDoc*>(m_pDocument); }
#endif

