#pragma once

#include <afxwin.h>

//2)框架类 CFrameWnd,派生类（子类）
class MyFrame: public CFrameWnd
{
public:
	MyFrame()
	{
		//继承于CFrameWnd
		Create(NULL, TEXT("MFC"));
	}

	//声明消息映射宏
	DECLARE_MESSAGE_MAP()
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

//1)应用程序类 CWinApp,派生类（子类）
class MyApp: public CWinApp
{
public:
	//基类的虚函数
	//派生类的重写

	//MFC程序的入口地址
	virtual BOOL InitInstance()
	{
		/*
		1、创建框架类对象
		2、显示窗口
		3、更新窗口
		4、保存框架类指针
		*/

		MyFrame *frame = new MyFrame;  //构造函数

		frame->ShowWindow(SW_SHOWNORMAL);

		frame->UpdateWindow();

		m_pMainWnd = frame;

		return TRUE;
	}
};

//有且只有一个全局的应用程序类
MyApp myApp;



/*
消息队列
消息：SendMessage、PostMessage
窗口过程消息处理函数

字符集
ASCII 多字节，单字节
char p[] = "abcde";  //一个字符一个字节
strlen(p);

unicode 宽字节，一个字符两个字节
TCHAR *p = L"abc"
wcslen(p):

MFC:
TCHAR: 自动适应字节（条件编译）
TEXT（）、_T()

拓展
afx_xxxxx: 全局函数，不属于某个类特有。
例如：MessageBox（）是CWnd的函数，只有在CWnd的子类（派生类）才能用。
在其他的类下有用，AfxMessageBox（）
xxxEX、 xxxW：拓展函数

类名和函数名： 单词首字母大写：MyApp
形参第一个字母全小写：nFlag、isTag
成员变量：m_xxxx

菜单消息路由（路径）
消息类型：
命令消息：WM_COMMAND：菜单处理函数中
标准消息：WM_XXXX, CWnd子类才能接收
通告消息：控件的处理函数消息

*/


//**************************************************************************************************
/*
1、文档视图结构
a）单文档
只有一个框架，一个文档
有一个应用程序单文档模板类：CSingleDocTemplate
在CWinApp::InitInstansce()中实例化时将菜单、文档类、主框架类、视图类结合在一起

CWinApp：	一个应用程序类，用来创建应用程序进程及进行入口初始操作
CFrameWnd：	一个框架类，作为应用程序的框架，类似装视图的容器
CDocument：	一个文档类，专门储存加载（读写）数据
CView：		一个视图类，专门显示和修改数据，视图是框架上的一块区域，类似壁纸

重要函数(对应上面四个类的派生子类)：
应用程序类	CxxxApp：		InitInstansce（）		程序的入口地址
框架类		CMainFrame：	PreCreateWindow（）		创建窗口之前调用
							OnCreate（）			创建窗口后，触发WM_CREATE，调用的消息处理函数
文档类		CxxxDoc:		OnNewDocument()			第一次新建窗口调用，后面每次按“新建”，自动调用此函数
							DeleteContents()		做一些释放资源的操作，每次 按“新建”，新建前调用此函数
视图类		CxxxView：		OnDraw（）				绘图，WM_PAINT消息处理函数OnPaint（）内部调用
							当OnPaint()和OnDraw()同时存在时，只有OnPaint（）有效

各类之间相互调用函数
1.CWinApp类中：包含一个文档模板类对象CSingleDocTemplate
	a) CFrameWnd:得到指向应用程序类的活动主窗口指针 -> AfxGetMainWnd()
2.CFrameWnd类中：
	a) CDocument:获得与当前活动视图相连的CDocument指针 -> CFrameWnd::GetActiveDocument()
	b) CView:获得指向与CFrameWnd框架窗口连接的活动视图的指针 -> CFrameWnd::GetActiveView()
3.CDocument类中：一个文档可以有多个视图
	a) CSingleDocTemplate:获得指向该文档模板的指针 -> CDocument::GetDocTemplate()
4.CView类中：一个视图只能有一个文档
	a) CDocument：获得当前活动视图相连的CDocument指针 -> CView::GetDocument()

b) 多文档
可以有多个框架（子框架），比单文档多一个子框架类
有一个应用程序多文档模板类：CMultiDocTemplate
在CWinApp::InitInstansce()中实例化时将菜单、文档类、子框架类、视图类结合在一起

除了单文档的四个派生类，还有一个子框架类：CChildFrame【和CMainFrame一样是CFrameWnd的派生类】

*/
//**************************************************************************************************