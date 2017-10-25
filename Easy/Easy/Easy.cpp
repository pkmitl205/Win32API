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

LRESULT CALLBACK WindowsProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	HDC hdc = GetDC(hwnd);
	HPEN pen1 = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	HBRUSH brush1 = CreateSolidBrush(RGB(0, 0, 255));
	
		RECT rect;
		rect.left = 10;
		rect.top = 10;
		rect.right = 40;
		rect.bottom = 50;




	switch (msg)
	{
	case WM_PAINT:
	{

		SelectObject(hdc, pen1);
		SelectObject(hdc, brush1);

		FillRect(hdc, &rect, (HBRUSH)(COLOR_WINDOW + 2));
		ReleaseDC(hwnd, hdc);

		DeleteObject(pen1);
		DeleteObject(brush1);
	}break;

	case WM_DESTROY:
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
