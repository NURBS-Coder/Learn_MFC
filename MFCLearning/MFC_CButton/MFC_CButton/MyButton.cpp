// MyButton.cpp : ʵ���ļ�
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



// MyButton ��Ϣ�������




void MyButton::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	int x0 = rand() ;
	int y0 = rand() ;
	int x = x0 % 300;
	int y = y0 % 300;

	//��ť�ƶ�����Դ���أ�
	//this->MoveWindow(x, y, m_Width, m_Height);

	//��ť�ƶ���·�����أ�
	this->MoveWindow(x, y, 100, 100);


	CButton::OnMouseMove(nFlags, point);
}
