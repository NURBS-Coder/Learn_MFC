
// MFC_CListView.cpp : CMFC_CListView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_CList.h"
#endif

#include "MFC_CListDoc.h"
#include "MFC_CListView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_CListView

IMPLEMENT_DYNCREATE(CMFC_CListView, CFormView)

BEGIN_MESSAGE_MAP(CMFC_CListView, CFormView)
	ON_BN_CLICKED(IDC_RADIO1, &CMFC_CListView::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMFC_CListView::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_CListView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC_CListView::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC_CListView::OnBnClickedButton3)
END_MESSAGE_MAP()

// CMFC_CListView 构造/析构

CMFC_CListView::CMFC_CListView()
	: CFormView(CMFC_CListView::IDD)
	, m_uiId(0)
	, m_uiName(_T(""))
	, m_uiAge(0)
	, m_uiScore(0)
{
	// TODO: 在此处添加构造代码

}

CMFC_CListView::~CMFC_CListView()
{
}

void CMFC_CListView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON2, m_ButtonPre);
	DDX_Control(pDX, IDC_BUTTON3, m_ButtonNext);
	DDX_Control(pDX, IDC_BUTTON1, m_ButtonAdd);
	DDX_Text(pDX, IDC_EDIT1, m_uiId);
	DDX_Text(pDX, IDC_EDIT2, m_uiName);
	DDX_Text(pDX, IDC_EDIT3, m_uiAge);
	DDX_Text(pDX, IDC_EDIT4, m_uiScore);
}

BOOL CMFC_CListView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CMFC_CListView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	//初始化
	CheckRadioButton(IDC_RADIO1,IDC_RADIO2,IDC_RADIO1);
	m_ButtonPre.EnableWindow(0);
	m_ButtonNext.EnableWindow(0);
	
}


// CMFC_CListView 诊断

#ifdef _DEBUG
void CMFC_CListView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMFC_CListView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMFC_CListDoc* CMFC_CListView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_CListDoc)));
	return (CMFC_CListDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_CListView 消息处理程序


void CMFC_CListView::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码

	m_ButtonAdd.EnableWindow(1);
	m_ButtonPre.EnableWindow(0);
	m_ButtonNext.EnableWindow(0);
}


void CMFC_CListView::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码

	m_ButtonAdd.EnableWindow(0);
	m_ButtonPre.EnableWindow(1);
	m_ButtonNext.EnableWindow(1);
}

/*
	学生管理系统（CList 列表模板的使用）
	1.创建一个学生类，作为CList 的模板对象
	2.文档类储存数据，视图类修改和显示数据
		a) 从尾部添加元素 CList::AddTail();
		b) 获取尾元素位置 CList::GetTailPostition();
		c) 获取首元素位置 CList::GetHeadPosition();
		d) 获取上一个元素 CList::GetPrev();
		e) 获取下一个元素 CList::GetNext();
		f) 获取指定位置元素 CList::GetAt();
		g) 移除头节点元素（不释放空间）CList::RemoveHead()
	3.视图的基类 CFormView 【新建工程时选择】
*/

void CMFC_CListView::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);

	//指针动态分配空间
	Student *stu = new Student(m_uiId,m_uiName,m_uiAge,m_uiScore);

	//获取文档对象指针
	CMFC_CListDoc *pDoc = GetDocument();

	//从列表尾部添加
	pDoc->m_Mylist.AddTail(stu);

	//储存当前位置
	pDoc->m_Pos = pDoc->m_Mylist.GetTailPosition();

}


void CMFC_CListView::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	//获取文档对象指针
	CMFC_CListDoc *pDoc = GetDocument();

	if (pDoc->m_Pos == NULL)
	{
		return;
	}

	Student *stu;
	//获取上一元素，pDoc->m_Pos会自动上移
	pDoc->m_Mylist.GetPrev(pDoc->m_Pos);

	//到头了就设置为尾结点位置
	if (pDoc->m_Pos == NULL)
	{
		pDoc->m_Pos=pDoc->m_Mylist.GetTailPosition();
	}

	//获取当前位置的元素
	stu = pDoc->m_Mylist.GetAt(pDoc->m_Pos);

	//赋值
	m_uiId = stu->m_id;
	m_uiName = stu->m_name;
	m_uiAge = stu->m_age;
	m_uiScore = stu->m_score;

	UpdateData(FALSE);
}


void CMFC_CListView::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

	//获取文档对象指针
	CMFC_CListDoc *pDoc = GetDocument();

	if (pDoc->m_Pos == NULL)
	{
		return;
	}


	Student *stu;
	//获取上一元素，pDoc->m_Pos会自动下移
	pDoc->m_Mylist.GetNext(pDoc->m_Pos);

	//到头了就设置为头结点位置
	if (pDoc->m_Pos == NULL)
	{
		pDoc->m_Pos=pDoc->m_Mylist.GetHeadPosition();
	}

	//获取当前位置的元素
	stu = pDoc->m_Mylist.GetAt(pDoc->m_Pos);

	//赋值
	m_uiId = stu->m_id;
	m_uiName = stu->m_name;
	m_uiAge = stu->m_age;
	m_uiScore = stu->m_score;

	UpdateData(FALSE);
}
