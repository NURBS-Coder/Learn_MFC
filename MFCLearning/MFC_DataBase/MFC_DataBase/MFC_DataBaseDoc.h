
// MFC_DataBaseDoc.h : CMFC_DataBaseDoc 类的接口
//


#pragma once

#include "MFC_DataBaseSet.h"


class CMFC_DataBaseDoc : public CDocument
{
protected: // 仅从序列化创建
	CMFC_DataBaseDoc();
	DECLARE_DYNCREATE(CMFC_DataBaseDoc)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CMFC_DataBaseDoc();
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


//文档类添加数据库记录集对象
public:
	CMFC_DataBaseSet *GetSet()
	{
		//共有指针获取函数返回私有对象指针
		return &pSet;
	}

private:
	CMFC_DataBaseSet pSet;		//数据库记录集对象


};
