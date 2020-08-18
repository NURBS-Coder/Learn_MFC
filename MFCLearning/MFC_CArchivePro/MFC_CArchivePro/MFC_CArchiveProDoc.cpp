
// MFC_CArchiveProDoc.cpp : CMFC_CArchiveProDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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


// CMFC_CArchiveProDoc ����/����

CMFC_CArchiveProDoc::CMFC_CArchiveProDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CMFC_CArchiveProDoc::~CMFC_CArchiveProDoc()
{
}

BOOL CMFC_CArchiveProDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMFC_CArchiveProDoc ���л�

void CMFC_CArchiveProDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����

		//��������
		ar << m_Num;

		for (int i = 0; i < m_Num; i++)
		{
			ar << m_pt[i];
		}


	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���

		//��ȡ����
		ar >> m_Num;

		for (int i = 0; i < m_Num; i++)
		{
			ar >> m_pt[i];
		}
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CMFC_CArchiveProDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CMFC_CArchiveProDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
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

// CMFC_CArchiveProDoc ���

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


// CMFC_CArchiveProDoc ����


void CMFC_CArchiveProDoc::DeleteContents()
{
	// TODO: �ڴ����ר�ô����/����û���

	memset(&m_pt, 0, sizeof(m_pt));

	m_Num = 0;



	CDocument::DeleteContents();
}
