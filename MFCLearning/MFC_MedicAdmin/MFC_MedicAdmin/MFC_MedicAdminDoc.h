
// MFC_MedicAdminDoc.h : CMFC_MedicAdminDoc 类的接口
//


#pragma once
#include "MedicSet.h"
#include "UserSet.h"
#include "User.h"

#include "MedicSearch.h"

class CMFC_MedicAdminDoc : public CDocument
{
protected: // 仅从序列化创建
	CMFC_MedicAdminDoc();
	DECLARE_DYNCREATE(CMFC_MedicAdminDoc)

// 特性
public:

// 操作
public:
	//返回药品记录集对象指针
	CMedicSet *GetMedicSet()
	{
		return &m_medicSet;
	}

	//返回用户记录集对象指针
	CUserSet *GetUserSet()
	{
		return &m_userSet;
	}
	//返回用户管理类对象
	CUser *GetUser()
	{
		return &m_user;	
	}
	//返回药品查询类对象
	CMedicSearch *GetMedicSearch()
	{
		return &m_MedicSearch;	
	}

private:
	CMedicSet m_medicSet;
	CUserSet m_userSet;
	CUser m_user;
	CMedicSearch m_MedicSearch;

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CMFC_MedicAdminDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
