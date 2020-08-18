
// MFC_CListDoc.cpp : CMFC_CListDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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


// CMFC_CListDoc ����/����

CMFC_CListDoc::CMFC_CListDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CMFC_CListDoc::~CMFC_CListDoc()
{
}

BOOL CMFC_CListDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	m_Pos == NULL;


	return TRUE;
}




// CMFC_CListDoc ���л�

void CMFC_CListDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CMFC_CListDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
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

// ������������֧��
void CMFC_CListDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
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

// CMFC_CListDoc ���

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


// CMFC_CListDoc ����


void CMFC_CListDoc::DeleteContents()
{
	// TODO: �ڴ����ר�ô����/����û���

	//�½�ǰ������б�����
	while (m_Mylist.GetHeadPosition()!=NULL)
	{
		//�Ƴ�ͷ�ڵ�
		Student *stu = m_Mylist.RemoveHead();
		delete stu;
	}

	m_Pos = NULL;

	CDocument::DeleteContents();
}
