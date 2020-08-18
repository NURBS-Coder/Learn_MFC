// MyButton.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_CButton.h"
#include "MyButton.h"


// MyButton

IMPLEMENT_DYNAMIC(MyButton, CButton)

MyButton::MyButton()
: m_Width(0)
, m_Height(0)
{
	//SetIcon();

}

MyButton::~MyButton()
{
}


BEGIN_MESSAGE_MAP(MyButton, CButton)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()



// MyButton 消息处理程序




void MyButton::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	int x0 = rand() ;
	int y0 = rand() ;
	int x = x0 % 300;
	int y = y0 % 300;

	//按钮移动（资源加载）
	//this->MoveWindow(x, y, m_Width, m_Height);

	//按钮移动（路径加载）
	this->MoveWindow(x, y, 100, 100);


	CButton::OnMouseMove(nFlags, point);
}
