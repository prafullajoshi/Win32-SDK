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
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
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
	HDC hdc;
	TCHAR str[255];
	int n1 = 10, n2 = 20;
	int n3 = n1 + n2;
	switch (iMsg)
	{
	case WM_CREATE:
		//int n1=10;
		//int n2=20;
		//int n3 = n1 + n2;
		wsprintf(str,TEXT("Sum of %d and %d is %d"), n1, n2, n3);
		MessageBox(hwnd, str, TEXT("SUM"), MB_OK);
		break;
	case WM_KEYDOWN:
		wsprintf(str, TEXT("Key is pressed..!!"));
		MessageBox(hwnd, str, TEXT("Event_KEYDOWN"), MB_OK);
		break;
	case WM_LBUTTONDOWN:
		wsprintf(str, TEXT("Left mouse button pressed..!!"));
		MessageBox(hwnd, str, TEXT("Event_LBUTTONDOWN"), MB_OK|MB_ICONINFORMATION|MB_SYSTEMMODAL);
		break;
	case WM_RBUTTONDOWN:
		wsprintf(str, TEXT("Right mouse button pressed..!!"));
		MessageBox(hwnd, str, TEXT("Event_RBUTTONDOWN"), MB_OK|MB_ICONINFORMATION|MB_APPLMODAL);
		break;
	case WM_SIZE:
		wsprintf(str, TEXT("Window Resized..!!"));
		MessageBox(hwnd, str, TEXT("Event_SIZE"), MB_OK);
		break;
	case WM_MOVE:
		wsprintf(str, TEXT("Window Moved..!!"));
		MessageBox(hwnd, str, TEXT("Event_MOVE"), MB_OK);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}
//End of Complete Program