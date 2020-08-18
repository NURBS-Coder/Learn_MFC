
// MFC_DocViewDoc.cpp : CMFC_DocViewDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_DocView.h"
#endif

#include "MFC_DocViewDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFC_DocViewDoc

IMPLEMENT_DYNCREATE(CMFC_DocViewDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFC_DocViewDoc, CDocument)
END_MESSAGE_MAP()


// CMFC_DocViewDoc 构造/析构

CMFC_DocViewDoc::CMFC_DocViewDoc()
{
	// TODO: 在此添加一次性构造代码

}

CMFC_DocViewDoc::~CMFC_DocViewDoc()
{
}

BOOL CMFC_DocViewDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMFC_DocViewDoc 序列化

void CMFC_DocViewDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CMFC_DocViewDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CMFC_DocViewDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CMFC_DocViewDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFC_DocViewDoc 诊断

#ifdef _DEBUG
void CMFC_DocViewDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFC_DocViewDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFC_DocViewDoc 命令


void CMFC_DocViewDoc::DeleteContents()
{
	// TODO: 在此添加专用代码和/或调用基类

	//删除数据，不销毁文档

	//每次新建，清空内容
	while (m_list.GetHeadPosition() != NULL)
	{
		//把头节点移除
		Student *p = m_list.RemoveHead();
		//释放空间
		delete p;
	}

	m_pos=NULL;


	CDocument::DeleteContents();
}
