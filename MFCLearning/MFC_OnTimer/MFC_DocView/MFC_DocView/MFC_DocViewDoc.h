
// MFC_DocViewDoc.h : CMFC_DocViewDoc ��Ľӿ�
//


#pragma once
#include "Student.h"

class CMFC_DocViewDoc : public CDocument
{
protected: // �������л�����
	CMFC_DocViewDoc();
	DECLARE_DYNCREATE(CMFC_DocViewDoc)

// ����
public:

	//�Զ����б�
	CList <Student	*> m_list;
	POSITION m_pos;	//��ǰλ�ýڵ�




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
	virtual ~CMFC_DocViewDoc();
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
	virtual void DeleteContents();
};
