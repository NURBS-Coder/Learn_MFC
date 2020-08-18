
// MFC_DialogView.h : CMFC_DialogView ��Ľӿ�
//

#pragma once


class CMFC_DialogView : public CView
{
protected: // �������л�����
	CMFC_DialogView();
	DECLARE_DYNCREATE(CMFC_DialogView)

// ����
public:
	CMFC_DialogDoc* GetDocument() const;

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
	virtual ~CMFC_DialogView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC_DialogView.cpp �еĵ��԰汾
inline CMFC_DialogDoc* CMFC_DialogView::GetDocument() const
   { return reinterpret_cast<CMFC_DialogDoc*>(m_pDocument); }
#endif

