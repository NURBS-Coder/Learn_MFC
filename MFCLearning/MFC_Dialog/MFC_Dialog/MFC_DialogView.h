
// MFC_DialogView.h : CMFC_DialogView 类的接口
//

#pragma once


class CMFC_DialogView : public CView
{
protected: // 仅从序列化创建
	CMFC_DialogView();
	DECLARE_DYNCREATE(CMFC_DialogView)

// 特性
public:
	CMFC_DialogDoc* GetDocument() const;

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
	virtual ~CMFC_DialogView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC_DialogView.cpp 中的调试版本
inline CMFC_DialogDoc* CMFC_DialogView::GetDocument() const
   { return reinterpret_cast<CMFC_DialogDoc*>(m_pDocument); }
#endif

