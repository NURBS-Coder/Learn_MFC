
// MFC_CArchiveProView.h : CMFC_CArchiveProView ��Ľӿ�
//

#pragma once


class CMFC_CArchiveProView : public CView
{
protected: // �������л�����
	CMFC_CArchiveProView();
	DECLARE_DYNCREATE(CMFC_CArchiveProView)

// ����
public:
	CMFC_CArchiveProDoc* GetDocument() const;

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
	virtual ~CMFC_CArchiveProView();
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
};

#ifndef _DEBUG  // MFC_CArchiveProView.cpp �еĵ��԰汾
inline CMFC_CArchiveProDoc* CMFC_CArchiveProView::GetDocument() const
   { return reinterpret_cast<CMFC_CArchiveProDoc*>(m_pDocument); }
#endif
