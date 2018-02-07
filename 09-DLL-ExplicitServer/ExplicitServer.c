#include<windows.h>
//DllMain
BOOL WINAPI DllMain(HANDLE hModule, DWORD dwReason, LPVOID lpReserved)
{
	//	code
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	}
	return (TRUE);
}

//	Exported function

int SumOfTwoIntegers(int num1, int num2)
{
	//	variable declaration
	int num3;
	//	code
	num3 = num1 + num2;
	return (num3);
}

int SubtractionOfTwoIntegers(int num1, int num2)
{
	//	variable declaration
	int num3;
	//	code
	num3 = num1 - num2;
	return (num3);
}
