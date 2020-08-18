
// MFC_DocViewDoc.h : CMFC_DocViewDoc 类的接口
//


#pragma once
#include "Student.h"

class CMFC_DocViewDoc : public CDocument
{
protected: // 仅从序列化创建
	CMFC_DocViewDoc();
	DECLARE_DYNCREATE(CMFC_DocViewDoc)

// 特性
public:

	//自定义列表
	CList <Student	*> m_list;
	POSITION m_pos;	//当前位置节点




// 操作
public:

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
	virtual ~CMFC_DocViewDoc();
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
public:
	virtual void DeleteContents();
};
