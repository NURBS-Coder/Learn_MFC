#include <Windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd,		//窗口句柄， 消息所属窗口
							UINT uMsg,		//消息标志
							WPARAM wParam,	//附加信息
							LPARAM lParam
							)
{
	switch(uMsg)
	{
	case WM_LBUTTONDOWN:
		{
			int xPos = LOWORD(lParam); 
			int yPos = HIWORD(lParam);
			//格式化字符串
			TCHAR buf[1024] = {0};
			wsprintf(buf, TEXT("%d,%d"),xPos, yPos);

			MessageBox(hwnd,buf,TEXT("鼠标左键按下"),MB_OK);
			break;
		}
	case WM_KEYDOWN:
		{
			switch(wParam)
			{
			case VK_LEFT:
				MessageBox(hwnd,TEXT("left"),TEXT("键盘"),MB_OK);
				break;
			case VK_RIGHT:
				MessageBox(hwnd,TEXT("right"),TEXT("键盘"),MB_OK);
				break;
			case VK_UP:
				MessageBox(hwnd,TEXT("up"),TEXT("键盘"),MB_OK);
				break;
			case VK_DOWN:
				MessageBox(hwnd,TEXT("down"),TEXT("键盘"),MB_OK);
				break;
			}
		break;
		}
	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC dc = BeginPaint(hwnd,&ps);
			TCHAR *p = L"jaskgjdsk";			//用宽字节，一个字符占两个字节
			TextOut(dc, 30, 30, p, wcslen(p));
			EndPaint(hwnd,&ps);
			break;
		}
	case WM_DESTROY:
		PostQuitMessage(0);		//发送WM_QUIT , Msg.wParam = 0
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}


int WINAPI WinMain(HINSTANCE hInstance,			//应用程序实例
				   HINSTANCE hPrevInstance,		//上一个应用程序实例
				   LPSTR lpCmdLine,				//LongPointString：指向字符串的指针，命令行参数
				   int nCmdShow					//窗口显示样式：最大化最小化
				   )
{
	/*
	1、定义入口函数WinMain（）
	2、创建一个窗口
		a）设计窗口类WNDCLASS（给成员变量赋值）
		b）注册窗口类
		c）创建一个窗口
		d）显示和更新窗口
	3、消息循环
	4、窗口过程函数
	*/

	HWND hWnd;
	MSG Msg;
	WNDCLASS wc;
	
	//a）设计窗口类WNDCLASS（给成员变量赋值）
	wc.cbClsExtra = 0; //类的附加信息
	wc.cbWndExtra = 0; //窗口附加信息
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//背景色

	//wc.hCursor = NULL;	//默认光标
	wc.hCursor = LoadCursor(NULL, IDC_HELP);	//加载系统默认光标

	//wc.hIcon =NULL;		//默认图标
	wc.hIcon = LoadIcon(NULL, IDI_WARNING);		//加载系统默认图标

	wc.hInstance = hInstance;			//应用程序实例
	wc.lpfnWndProc = WindowProc;		//窗口过程函数名，消息处理函数
	
	wc.lpszClassName = TEXT("test");	//类名
	wc.lpszMenuName = NULL;		//菜单名
	wc.style = nCmdShow;		//窗口显示样式

	//b）注册窗口类	,告诉系统窗口过程函数的地址
	RegisterClass(&wc);

	//c）创建一个窗口
	
	hWnd = CreateWindow(
		TEXT("test"), //窗口类名
		TEXT("Hello, Windows"),	//窗口实例的标题名		 
		WS_OVERLAPPEDWINDOW,	//窗口的风格
		CW_USEDEFAULT,
		CW_USEDEFAULT,			//以上2行表示窗口左上角坐标为默认值
		CW_USEDEFAULT,
		CW_USEDEFAULT,			//以上2行表示窗口的高度和宽度为默认值
		NULL,					//此窗口无父窗口
		NULL,					//此窗口无主菜单
		hInstance,				//创建此窗口的应用程序的当前句柄（即进程）
		NULL					//不使用该值
		);

	//d）显示和更新窗口
	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);
	
	
	//3、消息循环
	//如果接受到WM_QUIT， 返回0， 退出
	//如果出错， 返回-1， 不退出
	while (GetMessage(&Msg, NULL, 0, 0))
	{
		//翻译消息：键盘消息（虚拟按键）翻译后队列加入WM_CHAR消息
		TranslateMessage(&Msg);				

		//给系统分发消息
		DispatchMessage(&Msg);				

	}

	return Msg.wParam;
}