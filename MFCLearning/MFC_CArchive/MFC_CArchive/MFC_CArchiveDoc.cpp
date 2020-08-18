
// MFC_CArchiveDoc.cpp : CMFC_CArchiveDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_CArchive.h"
#endif

#include "MFC_CArchiveDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFC_CArchiveDoc

IMPLEMENT_DYNCREATE(CMFC_CArchiveDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFC_CArchiveDoc, CDocument)
END_MESSAGE_MAP()


// CMFC_CArchiveDoc 构造/析构

CMFC_CArchiveDoc::CMFC_CArchiveDoc()
{
	// TODO: 在此添加一次性构造代码

}

CMFC_CArchiveDoc::~CMFC_CArchiveDoc()
{
}

BOOL CMFC_CArchiveDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMFC_CArchiveDoc 序列化

void CMFC_CArchiveDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
		
		//按保存，调用此处

		//4. 往数据流写数据（相当于往文件写数据）
		//和cout用法一样
		int a = 10;
		double b = 12.56;
		TCHAR ch = 't';		
		CString str = _T("ABC");
		//箭头代表流向
		//数据流向ar,ar指向文件,即写文件
		ar << a << b << ch << str;

	}
	else
	{
		// TODO: 在此添加加载代码

		//按打开，调用此处

		//4. 通过数据流往变量写数据（相当于从文件读数据）
		//和cout用法一样
		int a;
		double b;
		TCHAR ch;	
		CString str;
		//箭头代表流向
		//数据流向变量,ar指向文件,即读文件
		ar >> a >> b >> ch >> str;

		CString buf;
		buf.Format(_T("%d, %f, %c, %s"),a,b,ch,str);
		AfxMessageBox(buf);

		//AfxMessageBox(_T("hhh"));

	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CMFC_CArchiveDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CMFC_CArchiveDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CMFC_CArchiveDoc::SetSearchContent(const CString& value)
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

// CMFC_CArchiveDoc 诊断

#ifdef _DEBUG
void CMFC_CArchiveDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFC_CArchiveDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFC_CArchiveDoc 命令
