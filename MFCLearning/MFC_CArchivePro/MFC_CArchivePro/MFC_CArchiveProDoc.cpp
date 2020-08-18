
// MFC_CArchiveProDoc.cpp : CMFC_CArchiveProDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_CArchivePro.h"
#endif

#include "MFC_CArchiveProDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFC_CArchiveProDoc

IMPLEMENT_DYNCREATE(CMFC_CArchiveProDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFC_CArchiveProDoc, CDocument)
END_MESSAGE_MAP()


// CMFC_CArchiveProDoc 构造/析构

CMFC_CArchiveProDoc::CMFC_CArchiveProDoc()
{
	// TODO: 在此添加一次性构造代码

}

CMFC_CArchiveProDoc::~CMFC_CArchiveProDoc()
{
}

BOOL CMFC_CArchiveProDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMFC_CArchiveProDoc 序列化

void CMFC_CArchiveProDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码

		//保存数据
		ar << m_Num;

		for (int i = 0; i < m_Num; i++)
		{
			ar << m_pt[i];
		}


	}
	else
	{
		// TODO: 在此添加加载代码

		//读取数据
		ar >> m_Num;

		for (int i = 0; i < m_Num; i++)
		{
			ar >> m_pt[i];
		}
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CMFC_CArchiveProDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CMFC_CArchiveProDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CMFC_CArchiveProDoc::SetSearchContent(const CString& value)
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

// CMFC_CArchiveProDoc 诊断

#ifdef _DEBUG
void CMFC_CArchiveProDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFC_CArchiveProDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFC_CArchiveProDoc 命令


void CMFC_CArchiveProDoc::DeleteContents()
{
	// TODO: 在此添加专用代码和/或调用基类

	memset(&m_pt, 0, sizeof(m_pt));

	m_Num = 0;



	CDocument::DeleteContents();
}
