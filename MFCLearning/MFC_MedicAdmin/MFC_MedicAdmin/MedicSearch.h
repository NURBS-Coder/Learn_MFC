#pragma once

#include "MedicSet.h"

class CMedicSearch
{
public:
	CMedicSearch(void);
	~CMedicSearch(void);


private:
	CMedicSet *pMedicSet;
	CListCtrl *pListCtrl;

public:
	void SetMedicSet(CMedicSet *pSet);
	void SetListCtrl(CListCtrl *pCtrl);
	int SearchByType(CString type =_T("�������"));
};

