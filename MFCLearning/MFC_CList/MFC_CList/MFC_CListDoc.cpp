
// MFC_CListDoc.cpp : CMFC_CListDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_CList.h"
#endif

#include "MFC_CListDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFC_CListDoc

IMPLEMENT_DYNCREATE(CMFC_CListDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFC_CListDoc, CDocument)
END_MESSAGE_MAP()


// CMFC_CListDoc 构造/析构

CMFC_CListDoc::CMFC_CListDoc()
{
	// TODO: 在此添加一次性构造代码

}

CMFC_CListDoc::~CMFC_CListDoc()
{
}

BOOL CMFC_CListDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	m_Pos == NULL;


	return TRUE;
}




// CMFC_CListDoc 序列化

void CMFC_CListDoc::Serialize(CArchive& ar)
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
void CMFC_CListDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CMFC_CListDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CMFC_CListDoc::SetSearchContent(const CString& value)
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

// CMFC_CListDoc 诊断

#ifdef _DEBUG
void CMFC_CListDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFC_CListDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFC_CListDoc 命令


void CMFC_CListDoc::DeleteContents()
{
	// TODO: 在此添加专用代码和/或调用基类

	//新建前，清空列表内容
	while (m_Mylist.GetHeadPosition()!=NULL)
	{
		//移除头节点
		Student *stu = m_Mylist.RemoveHead();
		delete stu;
	}

	m_Pos = NULL;

	CDocument::DeleteContents();
}
