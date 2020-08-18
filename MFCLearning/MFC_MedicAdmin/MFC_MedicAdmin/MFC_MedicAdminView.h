
// MFC_MedicAdminView.h : CMFC_MedicAdminView 类的接口
//

#pragma once

#include "resource.h"


class CMFC_MedicAdminView : public CFormView
{
protected: // 仅从序列化创建
	CMFC_MedicAdminView();
	DECLARE_DYNCREATE(CMFC_MedicAdminView)

public:
	enum{ IDD = IDD_MFC_MEDICADMIN_FORM };

// 特性
public:
	CMFC_MedicAdminDoc* GetDocument() const;

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
	virtual ~CMFC_MedicAdminView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
};

#ifndef _DEBUG  // MFC_MedicAdminView.cpp 中的调试版本
inline CMFC_MedicAdminDoc* CMFC_MedicAdminView::GetDocument() const
   { return reinterpret_cast<CMFC_MedicAdminDoc*>(m_pDocument); }
#endif

