
// MFC_CArchiveView.h : CMFC_CArchiveView ��Ľӿ�
//

#pragma once


class CMFC_CArchiveView : public CView
{
protected: // �������л�����
	CMFC_CArchiveView();
	DECLARE_DYNCREATE(CMFC_CArchiveView)

// ����
public:
	CMFC_CArchiveDoc* GetDocument() const;

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
	virtual ~CMFC_CArchiveView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC_CArchiveView.cpp �еĵ��԰汾
inline CMFC_CArchiveDoc* CMFC_CArchiveView::GetDocument() const
   { return reinterpret_cast<CMFC_CArchiveDoc*>(m_pDocument); }
#endif

