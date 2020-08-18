
// MFCSingleDocView.h : CMFCSingleDocView ��Ľӿ�
//

#pragma once
#include "atltypes.h"


class CMFCSingleDocView : public CView
{
protected: // �������л�����
	CMFCSingleDocView();
	DECLARE_DYNCREATE(CMFCSingleDocView)

// ����
public:
	CMFCSingleDocDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMFCSingleDocView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // MFCSingleDocView.cpp �еĵ��԰汾
inline CMFCSingleDocDoc* CMFCSingleDocView::GetDocument() const
   { return reinterpret_cast<CMFCSingleDocDoc*>(m_pDocument); }
#endif

