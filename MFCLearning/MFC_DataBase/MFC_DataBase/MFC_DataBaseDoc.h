
// MFC_DataBaseDoc.h : CMFC_DataBaseDoc ��Ľӿ�
//


#pragma once

#include "MFC_DataBaseSet.h"


class CMFC_DataBaseDoc : public CDocument
{
protected: // �������л�����
	CMFC_DataBaseDoc();
	DECLARE_DYNCREATE(CMFC_DataBaseDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMFC_DataBaseDoc();
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


//�ĵ���������ݿ��¼������
public:
	CMFC_DataBaseSet *GetSet()
	{
		//����ָ���ȡ��������˽�ж���ָ��
		return &pSet;
	}

private:
	CMFC_DataBaseSet pSet;		//���ݿ��¼������


};
