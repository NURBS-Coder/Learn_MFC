// MedicListView.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_MedicAdmin.h"
#include "MedicListView.h"
#include "MFC_MedicAdminDoc.h"

// CMedicListView

IMPLEMENT_DYNCREATE(CMedicListView, CListView)

CMedicListView::CMedicListView()
{

}

CMedicListView::~CMedicListView()
{
}

BEGIN_MESSAGE_MAP(CMedicListView, CListView)
END_MESSAGE_MAP()


// CMedicListView 诊断

#ifdef _DEBUG
void CMedicListView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void CMedicListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMedicListView 消息处理程序


void CMedicListView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	//获取列表视图中的列表控件
	CListCtrl &listCtrl = this->GetListCtrl();

	//设置风格，表格，选中全行
	listCtrl.SetExtendedStyle(listCtrl.GetExtendedStyle()
		|LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	
	//设置报表模型
	listCtrl.ModifyStyle(0,LVS_REPORT);

	//设置表头
	CString head[] = 
	{
		_T("药品代号"),_T("药品名称"),_T("药品类别"),
		_T("库存数目"),_T("出厂公司"),_T("产地"),
		_T("出厂时间"),_T("保质期（月）"),_T("单价（元）")
	};

	int n = sizeof(head)/sizeof(head[0]);

	for (int i = 0; i < n; i++)
	{
		listCtrl.InsertColumn(i,head[i],LVCFMT_LEFT,100);
	}

	//设置数据库内容，先行后列
	//for (int i = 0; i < 7; i++)
	//{
	//	CString str;
	//	str.Format(_T("%d"),i);
	//	listCtrl.InsertItem(i,str);

	//	for (int j = 1; j < n; j++)
	//	{
	//		listCtrl.SetItemText(i,j,_T("123"));
	//	}
	//}

	//获取文档类指针
	CMFC_MedicAdminDoc *pDoc = (CMFC_MedicAdminDoc*)GetDocument();

	//获取数据库记录集指针
	CMedicSet *pMedicSet = pDoc->GetMedicSet();

	//打开数据库
	if (!pMedicSet->IsOpen())
	{
		pMedicSet->Open();
	}

	//查询
	pMedicSet->Requery();

	//CRecordset::GetRecordCount()  获取记录集总行数（除了表头）
	for (int i = 0; i < pMedicSet->GetRecordCount(); i++)
	{
		CString str;
		str.Format(_T("%s"),pMedicSet->m_id);
		listCtrl.InsertItem(i,str);

		int j = 1;

		str.Format(_T("%s"),pMedicSet->m_name);
		listCtrl.SetItemText(i,j++,str);

		str.Format(_T("%s"),pMedicSet->m_classification);
		listCtrl.SetItemText(i,j++,str);

		str.Format(_T("%d"),pMedicSet->m_number);
		listCtrl.SetItemText(i,j++,str);

		str.Format(_T("%s"),pMedicSet->m_produceCompany);
		listCtrl.SetItemText(i,j++,str);

		str.Format(_T("%s"),pMedicSet->m_producePlace);
		listCtrl.SetItemText(i,j++,str);

		CTime time = pMedicSet->m_produceDate;
		str = time.Format(_T("%Y-%m-%d"));
		listCtrl.SetItemText(i,j++,str);

		str.Format(_T("%d"),pMedicSet->m_quelityAssurance);
		listCtrl.SetItemText(i,j++,str);

		str.Format(_T("%d"),pMedicSet->m_unitPrice);
		listCtrl.SetItemText(i,j++,str);

		pMedicSet->MoveNext();
	}

}
