#include "stdafx.h"
#include "MedicSearch.h"


CMedicSearch::CMedicSearch(void)
{
	pMedicSet = NULL;
	pListCtrl = NULL;
}


CMedicSearch::~CMedicSearch(void)
{
}


void CMedicSearch::SetMedicSet(CMedicSet *pSet)
{
	pMedicSet =  pSet;
}

void CMedicSearch::SetListCtrl(CListCtrl *pCtrl)
{
	pListCtrl =  pCtrl;
}

int CMedicSearch::SearchByType(CString type)
{
	if(pMedicSet == NULL || pListCtrl == NULL)
	{
		return -1;	
	}

	if (type == _T("所有类别"))
	{
		pMedicSet->m_strFilter = _T("");
	}else
	{
		CString SQL;
		SQL.Format(_T("classification = '%s'"),type);
		pMedicSet->m_strFilter = SQL;
	}

	//查询
	pMedicSet->Requery();

	//清空
	pListCtrl->DeleteAllItems();

	//更新
	//CRecordset::GetRecordCount()  获取记录集总行数（除了表头）
	for (int i = 0; i < pMedicSet->GetRecordCount(); i++)
	{
		CString str;
		str.Format(_T("%s"),pMedicSet->m_id);
		pListCtrl->InsertItem(i,str);

		int j = 1;

		str.Format(_T("%s"),pMedicSet->m_name);
		pListCtrl->SetItemText(i,j++,str);

		str.Format(_T("%s"),pMedicSet->m_classification);
		pListCtrl->SetItemText(i,j++,str);

		str.Format(_T("%d"),pMedicSet->m_number);
		pListCtrl->SetItemText(i,j++,str);

		str.Format(_T("%s"),pMedicSet->m_produceCompany);
		pListCtrl->SetItemText(i,j++,str);

		str.Format(_T("%s"),pMedicSet->m_producePlace);
		pListCtrl->SetItemText(i,j++,str);

		CTime time = pMedicSet->m_produceDate;
		str = time.Format(_T("%Y-%m-%d"));
		pListCtrl->SetItemText(i,j++,str);

		str.Format(_T("%d"),pMedicSet->m_quelityAssurance);
		pListCtrl->SetItemText(i,j++,str);

		str.Format(_T("%d"),pMedicSet->m_unitPrice);
		pListCtrl->SetItemText(i,j++,str);

		pMedicSet->MoveNext();
	}



	return 0;
}
