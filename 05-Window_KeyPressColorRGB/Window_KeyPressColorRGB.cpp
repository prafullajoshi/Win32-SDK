#include"stdafx.h"
#include<windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	//local variables

	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	//char AppName[] = "Windows";
	TCHAR AppName[] = TEXT("Windows");

	//Code

	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszClassName = AppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//Registration

	RegisterClassEx(&wndclass);


	//Creation of Window

	hwnd = CreateWindow(AppName, TEXT("Prafulla's First Window"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	//Displaying of Window

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	// Message of loop

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);

	}
	return (msg.wParam);

	//End of WinMain
}

//Window Procedure (Window Function)

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static int iPaintFlag = -1;
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rc;
	HBRUSH hBrush;
	TCHAR str[255];
	switch (iMsg)
	{
	case WM_KEYDOWN:
		switch (LOWORD(wParam))
		{
		case 'R':
		case 'r':
			iPaintFlag = 1;
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case 'G':
		case 'g':
			iPaintFlag = 2;
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case 'B':
		case 'b':
			iPaintFlag = 3;
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case 'C':
		case 'c':
			iPaintFlag = 4;
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case 'M':
		case 'm':
			iPaintFlag = 5;
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case 'Y':
		case 'y':
			iPaintFlag = 6;
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case 'K':
		case 'k':
			iPaintFlag = 7;
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case 'W':
		case 'w':
			iPaintFlag = 8;
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		default:
			wsprintf(str, TEXT("You pressed wrong key..!!"));
			MessageBox(hwnd, str, TEXT("Error"), MB_OK);
			break;
		}
		break;
	case WM_PAINT:
			hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rc);
		if (iPaintFlag == 1)
			hBrush = CreateSolidBrush(RGB(255, 0, 0));
		else if (iPaintFlag == 2)
			hBrush = CreateSolidBrush(RGB(0, 255, 0));
		else if (iPaintFlag == 3)
			hBrush = CreateSolidBrush(RGB(0, 0, 255));
		else if (iPaintFlag == 4)
			hBrush = CreateSolidBrush(RGB(0, 255, 255));
		else if (iPaintFlag == 5)
			hBrush = CreateSolidBrush(RGB(255, 0, 255));
		else if (iPaintFlag == 6)
			hBrush = CreateSolidBrush(RGB(255, 255, 0));
		else if (iPaintFlag == 7)
			hBrush = CreateSolidBrush(RGB(0, 0, 0));
		else if (iPaintFlag == 8)
			hBrush = CreateSolidBrush(RGB(255, 255, 255));
		SelectObject(hdc, hBrush);
		FillRect(hdc, &rc, hBrush);
		DeleteObject(hdc);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}
//End of Complete Program