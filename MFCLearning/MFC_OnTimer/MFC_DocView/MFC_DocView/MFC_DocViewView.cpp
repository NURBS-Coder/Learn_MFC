
// MFC_DocViewView.cpp : CMFC_DocViewView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_DocView.h"
#endif

#include "MFC_DocViewDoc.h"
#include "MFC_DocViewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_DocViewView

IMPLEMENT_DYNCREATE(CMFC_DocViewView, CFormView)

BEGIN_MESSAGE_MAP(CMFC_DocViewView, CFormView)
	ON_BN_CLICKED(IDC_RADIO1, &CMFC_DocViewView::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMFC_DocViewView::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC_DocViewView::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_DocViewView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC_DocViewView::OnBnClickedButton2)
END_MESSAGE_MAP()

// CMFC_DocViewView 构造/析构

CMFC_DocViewView::CMFC_DocViewView()
	: CFormView(CMFC_DocViewView::IDD)
	, m_uiId(0)
	, m_uiName(_T(""))
	, m_uiAge(0)
	, m_uiScore(0)
{
	// TODO: 在此处添加构造代码

}

CMFC_DocViewView::~CMFC_DocViewView()
{
}

void CMFC_DocViewView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_ButtonPre);
	DDX_Control(pDX, IDC_BUTTON2, m_ButtonNext);
	DDX_Text(pDX, IDC_EDIT1, m_uiId);
	DDX_Text(pDX, IDC_EDIT2, m_uiName);
	DDX_Text(pDX, IDC_EDIT3, m_uiAge);
	DDX_Text(pDX, IDC_EDIT4, m_uiScore);
	DDX_Control(pDX, IDC_BUTTON3, m_ButtonEdit);
}

BOOL CMFC_DocViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CMFC_DocViewView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	//学生管理系统
	/*
		1.定义学生类Student
		2.在文档类添加数据，视图类修改和显示数据
			a)从尾部添加元素 CList::AddTail()
			b)获取列表尾部元素的位置 CList::GetTailPosition() 
			c)获取上一元素 CList::GetPrev()
			d)获取下一元素 CList::GetNext()
			e)获取首元素位置 CList::GetHeadPosition()
			f)获取指定位置的元素 CList::GetAt()
			g)移除头节点元素（没有释放空间）CList::RemobeHead()
		3.视图的基类 CFromView() [在创建MFC工程时选择]
	*/

	//设置单选框
	CheckRadioButton(IDC_RADIO1,IDC_RADIO2,IDC_RADIO1);
	m_ButtonPre.EnableWindow(0);
	m_ButtonNext.EnableWindow(0);

}


// CMFC_DocViewView 诊断

#ifdef _DEBUG
void CMFC_DocViewView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMFC_DocViewView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMFC_DocViewDoc* CMFC_DocViewView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_DocViewDoc)));
	return (CMFC_DocViewDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_DocViewView 消息处理程序


void CMFC_DocViewView::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_ButtonPre.EnableWindow(0);
	m_ButtonNext.EnableWindow(0);
	m_ButtonEdit.EnableWindow(1);
}


void CMFC_DocViewView::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_ButtonPre.EnableWindow(1);
	m_ButtonNext.EnableWindow(1);
	m_ButtonEdit.EnableWindow(0);
}


void CMFC_DocViewView::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);

	Student *stu = new Student(m_uiId,m_uiName,m_uiAge,m_uiScore);

	CMFC_DocViewDoc *pDoc = GetDocument();

	//从尾部添加节点
	pDoc->m_list.AddTail(stu);

	//保存当前节点位置
	pDoc->m_pos = pDoc->m_list.GetTailPosition();
}


void CMFC_DocViewView::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	CMFC_DocViewDoc *pDoc = GetDocument();

	if(pDoc->m_pos == NULL){
		return;
	}

	Student *stu;

	//获取上一个元素位置，pDoc->m_pos会自动往上移一个
	pDoc->m_list.GetPrev(pDoc->m_pos);
	if(pDoc->m_pos == NULL){
		//保存当前节点位置为尾结点
		pDoc->m_pos = pDoc->m_list.GetTailPosition();
	}

	//获取当前位置元素
	stu = pDoc->m_list.GetAt(pDoc->m_pos);

	m_uiId=stu->m_id;
	m_uiName=stu->m_name;
	m_uiAge=stu->m_age;
	m_uiScore=stu->m_score;

	UpdateData(FALSE);
}


void CMFC_DocViewView::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	CMFC_DocViewDoc *pDoc = GetDocument();

	if(pDoc->m_pos == NULL){
		return;
	}

	Student *stu;

	//获取上一个元素位置，pDoc->m_pos会自动往下移一个
	pDoc->m_list.GetNext(pDoc->m_pos);
	if(pDoc->m_pos == NULL){
		//保存当前节点位置为尾结点
		pDoc->m_pos = pDoc->m_list.GetHeadPosition();
	}

	//获取当前位置元素
	stu = pDoc->m_list.GetAt(pDoc->m_pos);

	m_uiId=stu->m_id;
	m_uiName=stu->m_name;
	m_uiAge=stu->m_age;
	m_uiScore=stu->m_score;

	UpdateData(FALSE);
}
