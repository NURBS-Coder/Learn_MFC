#include "mfc.h"

//定义消息映射宏
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


void MyFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString str;

	//str = _T("Hello World!");
	str.Format(_T("%d,%d"),point.x,point.y);
	
	MessageBox(str,_T("鼠标左键按下"));

	CFrameWnd::OnLButtonDown(nFlags, point);
}


void MyFrame::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CFrameWnd::OnPaint()

	CString str;
	str = _T("");


	dc.TextOutW(100,100,_T("Hello"));


}


void MyFrame::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CString str;
	switch(nChar)
	{
	case 37:
		str=_T("left");
		break;
	case 38:
		str=_T("up");
		break;
	case 39:
		str=_T("right");
		break;
	case 40:
		str=_T("down");
		break;
	}
	
	MessageBox(str,_T("键盘按下"));

	CFrameWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}
