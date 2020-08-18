
// MFC_DocViewDoc.cpp : CMFC_DocViewDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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


// CMFC_DocViewDoc ����/����

CMFC_DocViewDoc::CMFC_DocViewDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CMFC_DocViewDoc::~CMFC_DocViewDoc()
{
}

BOOL CMFC_DocViewDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMFC_DocViewDoc ���л�

void CMFC_DocViewDoc::Serialize(CArchive& ar)
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
void CMFC_DocViewDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CMFC_DocViewDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
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

// CMFC_DocViewDoc ���

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


// CMFC_DocViewDoc ����


void CMFC_DocViewDoc::DeleteContents()
{
	// TODO: �ڴ����ר�ô����/����û���

	//ɾ�����ݣ��������ĵ�

	//ÿ���½����������
	while (m_list.GetHeadPosition() != NULL)
	{
		//��ͷ�ڵ��Ƴ�
		Student *p = m_list.RemoveHead();
		//�ͷſռ�
		delete p;
	}

	m_pos=NULL;


	CDocument::DeleteContents();
}
