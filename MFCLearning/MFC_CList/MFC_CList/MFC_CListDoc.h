
// MFC_CListDoc.h : CMFC_CListDoc ��Ľӿ�
//


#pragma once

#include "Student.h"


class CMFC_CListDoc : public CDocument
{
protected: // �������л�����
	CMFC_CListDoc();
	DECLARE_DYNCREATE(CMFC_CListDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMFC_CListDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS


public:
	CList <Student *> m_Mylist;
	POSITION m_Pos;
	virtual void DeleteContents();
};
