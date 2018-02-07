#define UNICODE
#include<windows.h>
#include"ImplicitServer.h"
//	global functions declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//	WinMain()

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	//	variable decalrations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyApp");
	//	code
	//	initialization of WNDCLASSEX
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//	register above class
	RegisterClassEx(&wndclass);
	//	Create window
	hwnd = CreateWindow(szAppName, TEXT("User of Implicit Server's Dll"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	//	Message loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return ((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//	variable decalration
	int n1, n2, n3;
	TCHAR str[255];
	//	code
	switch (iMsg)
	{
	case WM_CREATE:
		n1 = 120;
		n2 = 60;
		n3 = SumOfTwoIntegers(n1, n2);
		wsprintf(str, TEXT("Sum of %d and %d =%d"), n1, n2, n3);
		MessageBox(hwnd, str, TEXT("Sum"), MB_OK);
		n3 = SubtractionOfTwoIntegers(n1, n2);
		wsprintf(str, TEXT("Subtraction of %d and %d =%d"), n1, n2, n3);
		MessageBox(hwnd, str, TEXT("Subtraction"), MB_OK);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
