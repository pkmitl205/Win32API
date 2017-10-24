/*
============================================================================
Name        : Easy
Author      : Pakon Ruchirekserikun
Version     : 
Copyright   : Your copyright notice
Description : Easy.cpp
============================================================================
*/

#include <windows.h>
#include <windowsx.h>
#include <stdio.h> 

/*
============================================================================
	NOTE : Error Code C4996

	1. Properties(Alt+Enter) 
	2. C/C++ 
	3. Preprocessor
	4. <Edit...>
	4. Add "_CRT_SECURE_NO_WARNINGS" to PreprocessorDefinitions
============================================================================
*/


LRESULT CALLBACK WindowsProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	HDC hdc;
	hdc = GetDC(hwnd);
	switch (msg)
	{
		case WM_MOUSEMOVE:
			{
				int x = LOWORD(lparam);
				int y = HIWORD(lparam);
				
				if(wparam & MK_LBUTTON)
					{
						char i[20];
						sprintf_s(i, "x = %d, y = %d		", x, y);
						TextOut(hdc, 10, 10, i, strlen(i));
					}
			}break;
		case WM_PAINT :
		{

		}break;

		case WM_DESTROY :
		{
			PostQuitMessage(0);
		}break;
	}
	return(DefWindowProc(hwnd, msg, wparam, lparam));
}

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hprevinstance, LPSTR lpcmdline, int ncmdshow)
{
	WNDCLASSEX winclass;
	winclass.cbSize = sizeof(WNDCLASSEX);
	winclass.style = CS_VREDRAW | CS_HREDRAW | CS_OWNDC | CS_DBLCLKS;
	winclass.lpfnWndProc = WindowsProc;
	winclass.cbClsExtra = 0;
	winclass.cbWndExtra = 0;
	winclass.hInstance = hinstance;

	winclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	winclass.lpszClassName = "MyWin";
	winclass.lpszMenuName = NULL;
	winclass.hIcon = LoadIcon(hinstance, IDI_APPLICATION);
	winclass.hCursor = LoadCursor(hinstance, IDC_ARROW);
	winclass.hIconSm = LoadIcon(hinstance, IDI_APPLICATION);

	RegisterClassEx(&winclass);

	HWND hwnd;
	MSG msg;

	hwnd = CreateWindowEx(NULL, "MyWin", "Win32 Window", WS_OVERLAPPEDWINDOW, 100, 100,
		400, 400, NULL, NULL, hinstance, NULL);

	ShowWindow(hwnd, ncmdshow);
	UpdateWindow(hwnd);

	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (!GetMessage(&msg, NULL, 0, 0))
				return msg.wParam;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return(msg.wParam);
}
