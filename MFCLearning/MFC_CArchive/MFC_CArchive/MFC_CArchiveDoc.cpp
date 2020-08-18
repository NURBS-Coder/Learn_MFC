
// MFC_CArchiveDoc.cpp : CMFC_CArchiveDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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


// CMFC_CArchiveDoc ����/����

CMFC_CArchiveDoc::CMFC_CArchiveDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CMFC_CArchiveDoc::~CMFC_CArchiveDoc()
{
}

BOOL CMFC_CArchiveDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMFC_CArchiveDoc ���л�

void CMFC_CArchiveDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
		
		//�����棬���ô˴�

		//4. ��������д���ݣ��൱�����ļ�д���ݣ�
		//��cout�÷�һ��
		int a = 10;
		double b = 12.56;
		TCHAR ch = 't';		
		CString str = _T("ABC");
		//��ͷ��������
		//��������ar,arָ���ļ�,��д�ļ�
		ar << a << b << ch << str;

	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���

		//���򿪣����ô˴�

		//4. ͨ��������������д���ݣ��൱�ڴ��ļ������ݣ�
		//��cout�÷�һ��
		int a;
		double b;
		TCHAR ch;	
		CString str;
		//��ͷ��������
		//�����������,arָ���ļ�,�����ļ�
		ar >> a >> b >> ch >> str;

		CString buf;
		buf.Format(_T("%d, %f, %c, %s"),a,b,ch,str);
		AfxMessageBox(buf);

		//AfxMessageBox(_T("hhh"));

	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CMFC_CArchiveDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CMFC_CArchiveDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
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

// CMFC_CArchiveDoc ���

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


// CMFC_CArchiveDoc ����
