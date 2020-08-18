
// MFC_OnTimerView.h : CMFC_OnTimerView 类的接口
//

#pragma once


class CMFC_OnTimerView : public CView
{
protected: // 仅从序列化创建
	CMFC_OnTimerView();
	DECLARE_DYNCREATE(CMFC_OnTimerView)

// 特性
public:
	CMFC_OnTimerDoc* GetDocument() const;

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
	virtual ~CMFC_OnTimerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

private:
	HICON icon[4];
	int x1,x2,x3,x4;
	int y;

public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void On32771();
};

#ifndef _DEBUG  // MFC_OnTimerView.cpp 中的调试版本
inline CMFC_OnTimerDoc* CMFC_OnTimerView::GetDocument() const
   { return reinterpret_cast<CMFC_OnTimerDoc*>(m_pDocument); }
#endif

