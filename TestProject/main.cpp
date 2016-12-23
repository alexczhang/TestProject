﻿#include <iostream>
#include "switch.h"

#if 0		//project->setting->Link, Set Project options to be /subsystem:console
int main() 
{

#ifdef STACK
	Istack stack;
	
	for (int i = 1; i < MaxStack + 1 ; ++i)
		stack.Push(i);
	for (int i = 1; i < MaxStack + 1; ++i)
		std::cout << "Popped " << stack.Pop() << std::endl;
#endif //STACK

#ifdef FRAME
	Frame aFrame(5,3);
	Frame bFrame(3, 2);
#endif //FRAME

#ifdef GETNUM
	InputNum num;
	std::cout << "The Value is: " << num.GetValue() << ".\n";
	num.AddInput();
	std::cout << "Now the Value is: " << num.GetValue() << ".\n";

#endif //GETNUM

#ifdef WORLD
	World smallWorld(2);
	/*for (int i = 3; i < 6; ++i)
	World aWorld(i);

	World oneMoreWorld(6);*/
#endif // WORLD

#ifdef STAER
	std::cout << " Entering Main.\n";
	Star aStar(123.5, 0.1);
	std::cout << " Exiting Main.\n";

#endif //STAR

}
#else		//project->setting->Link, 在Project options中将 /subsystem:console改为/subsystem:windows.

#include <sstream>
#include <Windows.h>

//独一无二的类名，一般用GUID字串，以免与其他程序的类名重复 
static const char* CLASS_NAME = "{198CEAB2-AD78-4ed3-B099-247639080CB0}";

/** ********************************************************************** 
    回调函数，当主窗口收到任何Windows消息时被调用 
	*********************************************************************** */

LRESULT CALLBACK onMainWndMessage ( HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);	//如果是“窗口销毁”事件，则应该在消息队列中投递
		break;					//一个WM_QUIT消息，使GetMessage()返回FALSE 
	default:
		return DefWindowProc(wnd, msg, wParam, lParam);
	}
	return 0;
}

/************************************************************************ 
    登记自己的窗口类 
	************************************************************************/
bool registerMyClass () {
	WNDCLASSEX wce = {0};
	wce.cbSize			= sizeof(wce);
	wce.style			= CS_VREDRAW | CS_HREDRAW;
	wce.lpfnWndProc		= &onMainWndMessage;	//指明回调函数
	wce.hInstance		= GetModuleHandle(0);
	wce.hIcon			= LoadIcon(0, MAKEINTRESOURCE(IDI_WINLOGO));
	wce.hCursor			= LoadCursor(0, MAKEINTRESOURCE(IDC_ARROW));
	wce.hbrBackground	= reinterpret_cast <HBRUSH >(COLOR_BTNFACE + 1);
	wce.lpszClassName	= CLASS_NAME;			//独一无二的类名  
	wce.hIconSm	= wce.hIcon;
	return 0 != RegisterClassEx(&wce);
}

/************************************************************************ 
   创建并显示主窗口 
   ************************************************************************/
bool createMyWindow(int cmdShow) {
	HWND mainWnd = CreateWindowEx(0, CLASS_NAME, "Demo窗口", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		0, 0, GetModuleHandle(0), 0);
	if (0 != mainWnd) {
		ShowWindow(mainWnd, cmdShow);
		UpdateWindow(mainWnd);
		return true;
	} else {
		return false;
	}
}

/************************************************************************ 
    消息循环 
	************************************************************************/
int messageLoop() {
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return static_cast<int>(msg.wParam);
}

/************************************************************************ 
    WinMain，程序入口 
	************************************************************************/

int WINAPI WinMain(HINSTANCE, HINSTANCE, char *, int cmdShow) {
	if ( registerMyClass() && createMyWindow (cmdShow)) {
		return messageLoop();
	} else {
		std::ostringstream msg;
			msg << "创建主窗口失败，错误代码： " << GetLastError();
	MessageBoxA(0, msg.str().c_str(), 0, MB_OK | MB_ICONSTOP);
	return 0;
	}
}
#endif
