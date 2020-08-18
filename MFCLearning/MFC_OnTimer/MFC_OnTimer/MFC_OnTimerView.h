
// MFC_OnTimerView.h : CMFC_OnTimerView ��Ľӿ�
//

#pragma once


class CMFC_OnTimerView : public CView
{
protected: // �������л�����
	CMFC_OnTimerView();
	DECLARE_DYNCREATE(CMFC_OnTimerView)

// ����
public:
	CMFC_OnTimerDoc* GetDocument() const;

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
	virtual ~CMFC_OnTimerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // MFC_OnTimerView.cpp �еĵ��԰汾
inline CMFC_OnTimerDoc* CMFC_OnTimerView::GetDocument() const
   { return reinterpret_cast<CMFC_OnTimerDoc*>(m_pDocument); }
#endif

