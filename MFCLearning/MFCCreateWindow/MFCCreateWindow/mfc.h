#pragma once

#include <afxwin.h>

//2)����� CFrameWnd,�����ࣨ���ࣩ
class MyFrame: public CFrameWnd
{
public:
	MyFrame()
	{
		//�̳���CFrameWnd
		Create(NULL, TEXT("MFC"));
	}

	//������Ϣӳ���
	DECLARE_MESSAGE_MAP()
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

//1)Ӧ�ó����� CWinApp,�����ࣨ���ࣩ
class MyApp: public CWinApp
{
public:
	//������麯��
	//���������д

	//MFC�������ڵ�ַ
	virtual BOOL InitInstance()
	{
		/*
		1��������������
		2����ʾ����
		3�����´���
		4����������ָ��
		*/

		MyFrame *frame = new MyFrame;  //���캯��

		frame->ShowWindow(SW_SHOWNORMAL);

		frame->UpdateWindow();

		m_pMainWnd = frame;

		return TRUE;
	}
};

//����ֻ��һ��ȫ�ֵ�Ӧ�ó�����
MyApp myApp;



/*
��Ϣ����
��Ϣ��SendMessage��PostMessage
���ڹ�����Ϣ������

�ַ���
ASCII ���ֽڣ����ֽ�
char p[] = "abcde";  //һ���ַ�һ���ֽ�
strlen(p);

unicode ���ֽڣ�һ���ַ������ֽ�
TCHAR *p = L"abc"
wcslen(p):

MFC:
TCHAR: �Զ���Ӧ�ֽڣ��������룩
TEXT������_T()

��չ
afx_xxxxx: ȫ�ֺ�����������ĳ�������С�
���磺MessageBox������CWnd�ĺ�����ֻ����CWnd�����ࣨ�����ࣩ�����á�
���������������ã�AfxMessageBox����
xxxEX�� xxxW����չ����

�����ͺ������� ��������ĸ��д��MyApp
�βε�һ����ĸȫСд��nFlag��isTag
��Ա������m_xxxx

�˵���Ϣ·�ɣ�·����
��Ϣ���ͣ�
������Ϣ��WM_COMMAND���˵���������
��׼��Ϣ��WM_XXXX, CWnd������ܽ���
ͨ����Ϣ���ؼ��Ĵ�������Ϣ

*/


//**************************************************************************************************
/*
1���ĵ���ͼ�ṹ
a�����ĵ�
ֻ��һ����ܣ�һ���ĵ�
��һ��Ӧ�ó����ĵ�ģ���ࣺCSingleDocTemplate
��CWinApp::InitInstansce()��ʵ����ʱ���˵����ĵ��ࡢ������ࡢ��ͼ������һ��

CWinApp��	һ��Ӧ�ó����࣬��������Ӧ�ó�����̼�������ڳ�ʼ����
CFrameWnd��	һ������࣬��ΪӦ�ó���Ŀ�ܣ�����װ��ͼ������
CDocument��	һ���ĵ��࣬ר�Ŵ�����أ���д������
CView��		һ����ͼ�࣬ר����ʾ���޸����ݣ���ͼ�ǿ���ϵ�һ���������Ʊ�ֽ

��Ҫ����(��Ӧ�����ĸ������������)��
Ӧ�ó�����	CxxxApp��		InitInstansce����		�������ڵ�ַ
�����		CMainFrame��	PreCreateWindow����		��������֮ǰ����
							OnCreate����			�������ں󣬴���WM_CREATE�����õ���Ϣ������
�ĵ���		CxxxDoc:		OnNewDocument()			��һ���½����ڵ��ã�����ÿ�ΰ����½������Զ����ô˺���
							DeleteContents()		��һЩ�ͷ���Դ�Ĳ�����ÿ�� �����½������½�ǰ���ô˺���
��ͼ��		CxxxView��		OnDraw����				��ͼ��WM_PAINT��Ϣ������OnPaint�����ڲ�����
							��OnPaint()��OnDraw()ͬʱ����ʱ��ֻ��OnPaint������Ч

����֮���໥���ú���
1.CWinApp���У�����һ���ĵ�ģ�������CSingleDocTemplate
	a) CFrameWnd:�õ�ָ��Ӧ�ó�����Ļ������ָ�� -> AfxGetMainWnd()
2.CFrameWnd���У�
	a) CDocument:����뵱ǰ���ͼ������CDocumentָ�� -> CFrameWnd::GetActiveDocument()
	b) CView:���ָ����CFrameWnd��ܴ������ӵĻ��ͼ��ָ�� -> CFrameWnd::GetActiveView()
3.CDocument���У�һ���ĵ������ж����ͼ
	a) CSingleDocTemplate:���ָ����ĵ�ģ���ָ�� -> CDocument::GetDocTemplate()
4.CView���У�һ����ͼֻ����һ���ĵ�
	a) CDocument����õ�ǰ���ͼ������CDocumentָ�� -> CView::GetDocument()

b) ���ĵ�
�����ж����ܣ��ӿ�ܣ����ȵ��ĵ���һ���ӿ����
��һ��Ӧ�ó�����ĵ�ģ���ࣺCMultiDocTemplate
��CWinApp::InitInstansce()��ʵ����ʱ���˵����ĵ��ࡢ�ӿ���ࡢ��ͼ������һ��

���˵��ĵ����ĸ������࣬����һ���ӿ���ࣺCChildFrame����CMainFrameһ����CFrameWnd�������ࡿ

*/
//**************************************************************************************************