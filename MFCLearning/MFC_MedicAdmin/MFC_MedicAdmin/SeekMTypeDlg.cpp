// SeekMTypeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_MedicAdmin.h"
#include "SeekMTypeDlg.h"
#include "afxdialogex.h"


// CSeekMTypeDlg 对话框

IMPLEMENT_DYNAMIC(CSeekMTypeDlg, CDialogEx)

CSeekMTypeDlg::CSeekMTypeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSeekMTypeDlg::IDD, pParent)
{

}

CSeekMTypeDlg::~CSeekMTypeDlg()
{
}

void CSeekMTypeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_MedicType);
}


BEGIN_MESSAGE_MAP(CSeekMTypeDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSeekMTypeDlg::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CSeekMTypeDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CSeekMTypeDlg 消息处理程序


void CSeekMTypeDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}


BOOL CSeekMTypeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此添加额外的初始化

	m_MedicType.SetCurSel(0);


	return TRUE;  // return TRUE unless you set the focus to a control

	// 异常: OCX 属性页应返回 FALSE
}


void CSeekMTypeDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码

	int index = m_MedicType.GetCurSel();
	CString Type;
	m_MedicType.GetLBText(index,Type);

	if (Type.IsEmpty())
	{
		MessageBox(_T("内容不能为空！"));
		return;
	}

	//获取数据库记录集指针
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	//获取文档类指针
	CMFC_MedicAdminDoc *pDoc =(CMFC_MedicAdminDoc*)pFrame->GetActiveDocument();

	//获取药品记录集
	CMedicSet *pMedicSet = pDoc->GetMedicSet();

	CMedicSearch *pMS = pDoc->GetMedicSearch();

	//设置数据记录集指针
	pMS->SetMedicSet(pMedicSet);

	//获取列表视图
	//通过文档找到需要的列表视图（一个文档对应多个视图，通过链表管理 ）
	CMedicListView *pMedicListView = NULL;

	//获取文档中第一个视图的位置
	POSITION pos = pDoc->GetFirstViewPosition();

	//遍历视图链表，寻找树视图
	while (pos != NULL)
	{
		//根据当前位置获取视图指针，并将位置下移
		CView *pView = pDoc->GetNextView(pos);

		//判断是不是寻找的树视图
		if (pView->IsKindOf(RUNTIME_CLASS(CMedicListView)))
		{
			//类型转换：CView向其派生类转换
			pMedicListView = (CMedicListView *)pView;
			break;
		}
	}

	if(pMedicListView == NULL)
	{
		return ;
	}

	//设置视图指针
	CListCtrl *p = &pMedicListView->GetListCtrl();
	pMS->SetListCtrl(p);

	pMS->SearchByType(Type);

}
