
// MFC_MedicAdminDoc.h : CMFC_MedicAdminDoc ��Ľӿ�
//


#pragma once
#include "MedicSet.h"
#include "UserSet.h"
#include "User.h"

#include "MedicSearch.h"

class CMFC_MedicAdminDoc : public CDocument
{
protected: // �������л�����
	CMFC_MedicAdminDoc();
	DECLARE_DYNCREATE(CMFC_MedicAdminDoc)

// ����
public:

// ����
public:
	//����ҩƷ��¼������ָ��
	CMedicSet *GetMedicSet()
	{
		return &m_medicSet;
	}

	//�����û���¼������ָ��
	CUserSet *GetUserSet()
	{
		return &m_userSet;
	}
	//�����û����������
	CUser *GetUser()
	{
		return &m_user;	
	}
	//����ҩƷ��ѯ�����
	CMedicSearch *GetMedicSearch()
	{
		return &m_MedicSearch;	
	}

private:
	CMedicSet m_medicSet;
	CUserSet m_userSet;
	CUser m_user;
	CMedicSearch m_MedicSearch;

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
	virtual ~CMFC_MedicAdminDoc();
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
};
