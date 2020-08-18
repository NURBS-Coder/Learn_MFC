
// MFC_CArchiveProDoc.h : CMFC_CArchiveProDoc ��Ľӿ�
//


#pragma once


class CMFC_CArchiveProDoc : public CDocument
{
protected: // �������л�����
	CMFC_CArchiveProDoc();
	DECLARE_DYNCREATE(CMFC_CArchiveProDoc)

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
	virtual ~CMFC_CArchiveProDoc();
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
	//��CDocument::DeleteContents()��ʼ��
	CPoint m_pt[200];
	int m_Num;



	virtual void DeleteContents();
};
