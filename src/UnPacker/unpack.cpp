//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------

#pragma argsused
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fwdreason, LPVOID lpvReserved)
{
	return 1;
}
extern "C" void  __declspec(dllexport) CreateMyForm(TForm* Owner)
{
      static TForm1* form = new TForm1(Owner);
}
//---------------------------------------------------------------------------
