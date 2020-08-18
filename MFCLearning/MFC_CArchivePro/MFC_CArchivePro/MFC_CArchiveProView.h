
// MFC_CArchiveProView.h : CMFC_CArchiveProView 类的接口
//

#pragma once


class CMFC_CArchiveProView : public CView
{
protected: // 仅从序列化创建
	CMFC_CArchiveProView();
	DECLARE_DYNCREATE(CMFC_CArchiveProView)

// 特性
public:
	CMFC_CArchiveProDoc* GetDocument() const;

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
	virtual ~CMFC_CArchiveProView();
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
};

#ifndef _DEBUG  // MFC_CArchiveProView.cpp 中的调试版本
inline CMFC_CArchiveProDoc* CMFC_CArchiveProView::GetDocument() const
   { return reinterpret_cast<CMFC_CArchiveProDoc*>(m_pDocument); }
#endif

