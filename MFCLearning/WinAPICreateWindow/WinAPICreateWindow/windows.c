#include <Windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd,		//���ھ���� ��Ϣ��������
							UINT uMsg,		//��Ϣ��־
							WPARAM wParam,	//������Ϣ
							LPARAM lParam
							)
{
	switch(uMsg)
	{
	case WM_LBUTTONDOWN:
		{
			int xPos = LOWORD(lParam); 
			int yPos = HIWORD(lParam);
			//��ʽ���ַ���
			TCHAR buf[1024] = {0};
			wsprintf(buf, TEXT("%d,%d"),xPos, yPos);

			MessageBox(hwnd,buf,TEXT("����������"),MB_OK);
			break;
		}
	case WM_KEYDOWN:
		{
			switch(wParam)
			{
			case VK_LEFT:
				MessageBox(hwnd,TEXT("left"),TEXT("����"),MB_OK);
				break;
			case VK_RIGHT:
				MessageBox(hwnd,TEXT("right"),TEXT("����"),MB_OK);
				break;
			case VK_UP:
				MessageBox(hwnd,TEXT("up"),TEXT("����"),MB_OK);
				break;
			case VK_DOWN:
				MessageBox(hwnd,TEXT("down"),TEXT("����"),MB_OK);
				break;
			}
		break;
		}
	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC dc = BeginPaint(hwnd,&ps);
			TCHAR *p = L"jaskgjdsk";			//�ÿ��ֽڣ�һ���ַ�ռ�����ֽ�
			TextOut(dc, 30, 30, p, wcslen(p));
			EndPaint(hwnd,&ps);
			break;
		}
	case WM_DESTROY:
		PostQuitMessage(0);		//����WM_QUIT , Msg.wParam = 0
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}


int WINAPI WinMain(HINSTANCE hInstance,			//Ӧ�ó���ʵ��
				   HINSTANCE hPrevInstance,		//��һ��Ӧ�ó���ʵ��
				   LPSTR lpCmdLine,				//LongPointString��ָ���ַ�����ָ�룬�����в���
				   int nCmdShow					//������ʾ��ʽ�������С��
				   )
{
	/*
	1��������ں���WinMain����
	2������һ������
		a����ƴ�����WNDCLASS������Ա������ֵ��
		b��ע�ᴰ����
		c������һ������
		d����ʾ�͸��´���
	3����Ϣѭ��
	4�����ڹ��̺���
	*/

	HWND hWnd;
	MSG Msg;
	WNDCLASS wc;
	
	//a����ƴ�����WNDCLASS������Ա������ֵ��
	wc.cbClsExtra = 0; //��ĸ�����Ϣ
	wc.cbWndExtra = 0; //���ڸ�����Ϣ
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//����ɫ

	//wc.hCursor = NULL;	//Ĭ�Ϲ��
	wc.hCursor = LoadCursor(NULL, IDC_HELP);	//����ϵͳĬ�Ϲ��

	//wc.hIcon =NULL;		//Ĭ��ͼ��
	wc.hIcon = LoadIcon(NULL, IDI_WARNING);		//����ϵͳĬ��ͼ��

	wc.hInstance = hInstance;			//Ӧ�ó���ʵ��
	wc.lpfnWndProc = WindowProc;		//���ڹ��̺���������Ϣ������
	
	wc.lpszClassName = TEXT("test");	//����
	wc.lpszMenuName = NULL;		//�˵���
	wc.style = nCmdShow;		//������ʾ��ʽ

	//b��ע�ᴰ����	,����ϵͳ���ڹ��̺����ĵ�ַ
	RegisterClass(&wc);

	//c������һ������
	
	hWnd = CreateWindow(
		TEXT("test"), //��������
		TEXT("Hello, Windows"),	//����ʵ���ı�����		 
		WS_OVERLAPPEDWINDOW,	//���ڵķ��
		CW_USEDEFAULT,
		CW_USEDEFAULT,			//����2�б�ʾ�������Ͻ�����ΪĬ��ֵ
		CW_USEDEFAULT,
		CW_USEDEFAULT,			//����2�б�ʾ���ڵĸ߶ȺͿ��ΪĬ��ֵ
		NULL,					//�˴����޸�����
		NULL,					//�˴��������˵�
		hInstance,				//�����˴��ڵ�Ӧ�ó���ĵ�ǰ����������̣�
		NULL					//��ʹ�ø�ֵ
		);

	//d����ʾ�͸��´���
	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);
	
	
	//3����Ϣѭ��
	//������ܵ�WM_QUIT�� ����0�� �˳�
	//������� ����-1�� ���˳�
	while (GetMessage(&Msg, NULL, 0, 0))
	{
		//������Ϣ��������Ϣ�����ⰴ�����������м���WM_CHAR��Ϣ
		TranslateMessage(&Msg);				

		//��ϵͳ�ַ���Ϣ
		DispatchMessage(&Msg);				

	}

	return Msg.wParam;
}