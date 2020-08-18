
// MFC_DataBaseView.cpp : CMFC_DataBaseView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_DataBase.h"
#endif

#include "MFC_DataBaseDoc.h"
#include "MFC_DataBaseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_DataBaseView

IMPLEMENT_DYNCREATE(CMFC_DataBaseView, CFormView)

BEGIN_MESSAGE_MAP(CMFC_DataBaseView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_DataBaseView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC_DataBaseView::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC_DataBaseView::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFC_DataBaseView::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFC_DataBaseView::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFC_DataBaseView::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFC_DataBaseView::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFC_DataBaseView::OnBnClickedButton8)
END_MESSAGE_MAP()

// CMFC_DataBaseView 构造/析构

CMFC_DataBaseView::CMFC_DataBaseView()
	: CFormView(CMFC_DataBaseView::IDD)
	, m_uiId(0)
	, m_uiName(_T(""))
	, m_uiAge(0)
	, m_uiScore(0)
	, m_isEdit(false)
	, m_isFilter(false)
{
	// TODO: 在此处添加构造代码

}

CMFC_DataBaseView::~CMFC_DataBaseView()
{
}

void CMFC_DataBaseView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_uiId);
	DDX_Text(pDX, IDC_EDIT2, m_uiName);
	DDX_Text(pDX, IDC_EDIT3, m_uiAge);
	DDX_Text(pDX, IDC_EDIT4, m_uiScore);
	DDX_Control(pDX, IDC_BUTTON3, m_ButtonEdit);
	DDX_Control(pDX, IDC_BUTTON7, m_buttonFilter);
}

BOOL CMFC_DataBaseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CMFC_DataBaseView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	//数据库编程
	/*
		1.准备工作：安装MySQL服务器 ； 安装MySQL odbc驱动
		2.odbc（open database connectivity）层次图
			a）odbc是一套标准接口（内部通过SQL语句操作数据库，用户不会SQL语句也可以操作数据库）
			b）创建数据源
		3.创建数据源（MySQL只能是快照）
			a）快照（Snapshot）记录集：每次操作重新查询后才更新
			b）动态（Dynaset）记录集：每次操作自动更新（添加记录除外）
		4.应用程序框架
			a）CRecordset的子类，主要对数据库进行相应操作
				1）DoFieldExchange() 自动把数据库字段和变量相关联
				2）GetDefaultConnect() 获取数据库连接信息
				3）GetDefaultSQL() 获取数据库连接的表
			b）CFormView的子类，显示数据库内容的视图
				1）OnInitialUpdate() 主要做初始化的功能
		5.通过CRecordset 类对数据库进行相应操作
			a）文档类头文件创建CRecordset的子类对象
			b）视图类做增删改查操作
				1）打开数据库 CRecordset::Open()
				2）查询记录	CRecordset::Requery()
				3）移动上一个记录集 CRecordset::MovePrev()
				4）移动下一个记录集 CRecordset::MoveNext()
				5）是否为最后一个记录的下一个 CRecordset::IsEOF()
				6）是否为开始一个记录的上一个 CRecordset::IsBOF()
				7）移动到开始一个记录 CRecordset::MoveFirst()
				8）移动到最后一个记录 CRecordset::MoveLast()
				9）添加空记录 CRecordset::AddNew()
				10）如果记录集可更新 CRecordset::CanUpdate()
				11）更新记录集 CRecordset::UpDate()
				12）删除当前记录 CRecordset::Delete()
				13）编辑当前记录 CRecordset::Edit()
				14）过滤 CRecordset::m_strFilter()
				15）排序 CRecordset::m_strSort()（默认升序，降序加desc）
			c）注意点
				1）移动记录集，注意越界处理
				2）移动记录集后，不要重新查询，重新查询相当于游标（pSet）重新开始
				3）更新记录前，先通过 CRecordset::CanUpdate()判断记录集可更新后，才能更新
				4）删除数据后，最后移动到下一个记录集

	*/


	//获取文档指针
	pDoc = GetDocument();
	//获取数据库记录指针集
	pSet = pDoc->GetSet();
	//打开数据库
	if (FALSE == pSet->IsOpen())
	{
		pSet->Open();

		m_uiId = pSet->m_id;
		m_uiName = pSet->m_name;
		m_uiAge = pSet->m_age;
		m_uiScore = pSet->m_score;

		UpdateData(FALSE);
	}

}


// CMFC_DataBaseView 诊断

#ifdef _DEBUG
void CMFC_DataBaseView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMFC_DataBaseView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMFC_DataBaseDoc* CMFC_DataBaseView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_DataBaseDoc)));
	return (CMFC_DataBaseDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_DataBaseView 消息处理程序


void CMFC_DataBaseView::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	//获取上一个记录集
	pSet->MovePrev();

	//如果是开始的前一个
	if (pSet->IsBOF())
	{
		//把记录集设置为最后一个
		pSet->MoveLast();
	}

	m_uiId = pSet->m_id;
	m_uiName = pSet->m_name;
	m_uiAge = pSet->m_age;
	m_uiScore = pSet->m_score;

	UpdateData(FALSE);
}


void CMFC_DataBaseView::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	//获取下一个记录集
	pSet->MoveNext();

	//如果是最后的后一个
	if (pSet->IsEOF())
	{
		//把记录集设置为第一个
		pSet->MoveFirst();
	}

	m_uiId = pSet->m_id;
	m_uiName = pSet->m_name;
	m_uiAge = pSet->m_age;
	m_uiScore = pSet->m_score;

	UpdateData(FALSE);

}

//添加记录
void CMFC_DataBaseView::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

	m_isEdit =! m_isEdit;

	if(m_isEdit)
	{
		//数据库添加空记录
		pSet->AddNew();
		//清空
		m_uiId = 0;
		m_uiName = _T("XX");
		m_uiAge = 0;
		m_uiScore = 0;

		UpdateData(FALSE);
		//确认添加
		m_ButtonEdit.SetWindowTextW(_T("确认添加"));
	}else{
		UpdateData(TRUE);

		pSet->m_id = m_uiId ;
		pSet->m_name = m_uiName;
		pSet->m_age = m_uiAge;
		pSet->m_score = m_uiScore;

		//判断有没有数据可更新到数据库
		if (pSet->CanUpdate())
		{
			//更新到数据库
			pSet->Update();
		}

		//更新数据库，自动指向第一条记录
		pSet->Requery();

		m_uiId = pSet->m_id;
		m_uiName = pSet->m_name;
		m_uiAge = pSet->m_age;
		m_uiScore = pSet->m_score;

		UpdateData(FALSE);
		
		//确认添加
		m_ButtonEdit.SetWindowTextW(_T("添加记录"));
	}
}

//确定添加记录
void CMFC_DataBaseView::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);

	pSet->m_id = m_uiId ;
	pSet->m_name = m_uiName;
	pSet->m_age = m_uiAge;
	pSet->m_score = m_uiScore;

	//判断有没有数据可更新到数据库
	if (pSet->CanUpdate())
	{
		//更新到数据库
		pSet->Update();
	}

	//更新数据库，自动指向第一条记录
	pSet->Requery();

	m_uiId = pSet->m_id;
	m_uiName = pSet->m_name;
	m_uiAge = pSet->m_age;
	m_uiScore = pSet->m_score;

	UpdateData(FALSE);
}

//修改数据库
void CMFC_DataBaseView::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码

	//数据库修改
	pSet->Edit();

	UpdateData(TRUE);

	pSet->m_id = m_uiId ;
	pSet->m_name = m_uiName;
	pSet->m_age = m_uiAge;
	pSet->m_score = m_uiScore;

	//判断有没有数据可更新到数据库
	if (pSet->CanUpdate())
	{
		//更新到数据库
		pSet->Update();
	}

	//更新数据库，自动指向第一条记录
	pSet->Requery();

	m_uiId = pSet->m_id;
	m_uiName = pSet->m_name;
	m_uiAge = pSet->m_age;
	m_uiScore = pSet->m_score;

	UpdateData(FALSE);
}

//删除记录
void CMFC_DataBaseView::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码

	//删除记录
	pSet->Delete();

	//更新数据库,自动指向第一个记录
	pSet->Requery();

	m_uiId = pSet->m_id;
	m_uiName = pSet->m_name;
	m_uiAge = pSet->m_age;
	m_uiScore = pSet->m_score;

	UpdateData(FALSE);
}


void CMFC_DataBaseView::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码

	m_isFilter =! m_isFilter;
	if(m_isFilter){
		//设置过滤条件
		pSet->m_strFilter = (_T("age > 18"));

		m_buttonFilter.SetWindowTextW(_T("恢复全部数据"));
	}else{
		//不过滤
		pSet->m_strFilter = (_T(""));

		m_buttonFilter.SetWindowTextW(_T("年龄大于18"));
	}
	//重新查询
	pSet->Requery();

	m_uiId = pSet->m_id;
	m_uiName = pSet->m_name;
	m_uiAge = pSet->m_age;
	m_uiScore = pSet->m_score;

	UpdateData(FALSE);
}


void CMFC_DataBaseView::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码

	//设置排序(年龄排序，默认升序)
	//pSet->m_strSort = _T("age");
	
	//设置排序(年龄排序，降序)
	pSet->m_strSort = _T("score desc");

	//重新查询
	pSet->Requery();

	m_uiId = pSet->m_id;
	m_uiName = pSet->m_name;
	m_uiAge = pSet->m_age;
	m_uiScore = pSet->m_score;

	UpdateData(FALSE);
}
