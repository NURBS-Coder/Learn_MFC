#include "mfc.h"

//������Ϣӳ���
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


void MyFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString str;

	//str = _T("Hello World!");
	str.Format(_T("%d,%d"),point.x,point.y);
	
	MessageBox(str,_T("����������"));

	CFrameWnd::OnLButtonDown(nFlags, point);
}


void MyFrame::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CFrameWnd::OnPaint()

	CString str;
	str = _T("");


	dc.TextOutW(100,100,_T("Hello"));


}


void MyFrame::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

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
	
	MessageBox(str,_T("���̰���"));

	CFrameWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}
