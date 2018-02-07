#define UNICODE
#include<windows.h>
#include"ImplicitServer.h"

//DllMain

BOOL WINAPI DllMain(HANDLE hModule, DWORD dwReson, LPVOID lpReserved)
{
	//Actual Code
	switch (dwReson)
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
	return(TRUE);
}


__declspec (dllexport) int SumOfTwoIntegers(int iNum1, int iNum2)
{
	//variable declaration

	int iNum3;
	iNum3 = iNum1 + iNum2;
	//actual code
	return iNum3;
}

__declspec(dllexport) int SubtractionOfTwoIntegers(int iNum1, int iNum2)
{
	//variable declaration

	int iNum3;
	//actual code
	iNum3 = iNum1 - iNum2;
	return iNum3;
}
