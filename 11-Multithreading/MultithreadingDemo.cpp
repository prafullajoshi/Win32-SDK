#include<windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

DWORD WINAPI ThreadProcOne(LPVOID);
DWORD WINAPI ThreadProcTwo(LPVOID);
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
	static HANDLE hThreadOne = NULL;
	static HANDLE hThreadTwo = NULL;
	TCHAR str[255];
	switch (iMsg)
	{
	case WM_CREATE:
		hThreadOne = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProcOne, (LPVOID)hwnd, 0, NULL);
		hThreadTwo = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProcTwo, (LPVOID)hwnd, 0, NULL);
		break;
	case WM_LBUTTONDOWN:
		wsprintf(str, TEXT("HELLO User..!!!"));
		MessageBox(hwnd, str, TEXT("Event handled..!!"), MB_OK);
		break;
	case WM_DESTROY:
		if (hThreadOne)
		{
			CloseHandle(hThreadOne);
			hThreadOne = NULL;
		}
		if (hThreadTwo)
		{
			CloseHandle(hThreadTwo);
			hThreadTwo = NULL;
		}
		PostQuitMessage(0);
		break;
	}
	return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}

//	Increamenting numbers
DWORD WINAPI ThreadProcOne(LPVOID param)
{
	HWND hwnd = (HWND)param;
	HDC hdc = GetDC(hwnd);
	TCHAR str[255];
	for (int i = 0; i < 32768; i++)
	{
		wsprintf(str, TEXT("Increamenting :%d"), i);
		TextOut(hdc, 5, 5, str, (int)wcslen(str));
		Sleep(1);
	}
	ReleaseDC(hwnd, hdc);
	return 0;
}

//	Decreamenting numbers
DWORD WINAPI ThreadProcTwo(LPVOID param)
{
	HWND hwnd = (HWND)param;
	HDC hdc = GetDC(hwnd);
	TCHAR str[255];
	for (int i = 32767; i >= 0; i--)
	{
		wsprintf(str, TEXT("Decreamenting :%d"), i);
		TextOut(hdc, 5, 25, str, (int)wcslen(str));
		Sleep(1);
	}
	ReleaseDC(hwnd, hdc);
	return 0;
}
//End of Complete Program