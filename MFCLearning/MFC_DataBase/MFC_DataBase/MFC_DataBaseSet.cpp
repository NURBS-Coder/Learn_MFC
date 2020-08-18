
// MFC_DataBaseSet.cpp : CMFC_DataBaseSet ���ʵ��
//

#include "stdafx.h"
#include "MFC_DataBase.h"
#include "MFC_DataBaseSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_DataBaseSet ʵ��

// ���������� 2019��7��31��, 10:44

IMPLEMENT_DYNAMIC(CMFC_DataBaseSet, CRecordset)

CMFC_DataBaseSet::CMFC_DataBaseSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_id = 0;
	m_name = L"";
	m_age = 0;
	m_score = 0.0;
	m_nFields = 4;
	m_nDefaultType = snapshot;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFC_DataBaseSet::GetDefaultConnect()
{
	return _T("Driver=MySQL ODBC 5.2 Unicode Driver;SERVER=127.0.0.1;UID=root;PWD=root;DATABASE=info;PORT=3306");
}

CString CMFC_DataBaseSet::GetDefaultSQL()
{
	return _T("[student]");
}

void CMFC_DataBaseSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[id]"), m_id);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Long(pFX, _T("[age]"), m_age);
	RFX_Double(pFX, _T("[score]"), m_score);

}
/////////////////////////////////////////////////////////////////////////////
// CMFC_DataBaseSet ���

#ifdef _DEBUG
void CMFC_DataBaseSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFC_DataBaseSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

