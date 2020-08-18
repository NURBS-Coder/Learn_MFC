
// MFC_MedicAdminView.cpp : CMFC_MedicAdminView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_MedicAdmin.h"
#endif

#include "MFC_MedicAdminDoc.h"
#include "MFC_MedicAdminView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_MedicAdminView

IMPLEMENT_DYNCREATE(CMFC_MedicAdminView, CFormView)

BEGIN_MESSAGE_MAP(CMFC_MedicAdminView, CFormView)
	ON_WM_CLOSE()
END_MESSAGE_MAP()

// CMFC_MedicAdminView 构造/析构

CMFC_MedicAdminView::CMFC_MedicAdminView()
	: CFormView(CMFC_MedicAdminView::IDD)
{
	// TODO: 在此处添加构造代码

}

CMFC_MedicAdminView::~CMFC_MedicAdminView()
{
}

void CMFC_MedicAdminView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CMFC_MedicAdminView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CMFC_MedicAdminView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();


	//CView类初始化函数
	//药品管理程序案例实践过程
	/*
	一、静态拆分窗口
		1）自定义两个类
			a) CUserTreeView（继承于CTreeView, 显示用户信息）
			b) CMedicListView(继承于CListView, 显示药品信息)
		2）在框架类中做拆分操作
			a) 包含自定义类的头文件
			b) 使用CSplitterWnd类实现拆分功能
					i.重载父框架的 CFrameWnd::OnCreateClient成员函数
					ii.其中创建静态分隔器窗口	CSplitterWnd::CreateStatic()
					iii.其中创建各个分割窗格	CSplitterWnd::CreateView()
	
		3）初始化自定义类（都是CView类的派生类）-> 重载父框架的CView::OnInitialUpdate()成员函数,其中进行相应的初始化工作
			a）CMedicListView 初始化
				1）CListCtrl的使用
				2）关联数据库：添加类->MFC->MFC ODBC使用者->数据源->新建->.....-> 新类名CMedicSet【CRecordset的子类】
				3）在文档类中定义 CMedicSet对象，供后续使用
				4）打开记录集，查询后按行插入数据【一定要先打开再查询然后操作】
			b) CUserTreeView 初始化
				1）CTreeCtrl的使用
				2）关联数据库：添加类->MFC->MFC ODBC使用者->数据源->新建->.....-> 新类名CUserSet【CRecordset的子类】
				3）在文档类中定义 CUserSet对象，供后续使用
				4）打开记录集，查询后按行插入数据【一定要先打开再查询然后操作】
			
	*/

}


// CMFC_MedicAdminView 诊断

#ifdef _DEBUG
void CMFC_MedicAdminView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMFC_MedicAdminView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMFC_MedicAdminDoc* CMFC_MedicAdminView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_MedicAdminDoc)));
	return (CMFC_MedicAdminDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_MedicAdminView 消息处理程序


void CMFC_MedicAdminView::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CFormView::OnClose();
}
