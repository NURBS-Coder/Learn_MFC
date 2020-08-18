
// MFCSingleDocView.h : CMFCSingleDocView 类的接口
//

#pragma once
#include "atltypes.h"


class CMFCSingleDocView : public CView
{
protected: // 仅从序列化创建
	CMFCSingleDocView();
	DECLARE_DYNCREATE(CMFCSingleDocView)

// 特性
public:
	CMFCSingleDocDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFCSingleDocView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnPaint();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CPoint m_Point;
	CString str;
	CString str1;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int w;
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCSingleDocView.cpp 中的调试版本
inline CMFCSingleDocDoc* CMFCSingleDocView::GetDocument() const
   { return reinterpret_cast<CMFCSingleDocDoc*>(m_pDocument); }
#endif

