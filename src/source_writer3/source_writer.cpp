//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("object.cpp", Object_form);
USEFORM("option.cpp", Options);
USEFORM("goto.cpp", Form3);
USEFORM("Unit1.cpp", Form1);
USEFORM("splash.cpp", Form2);
USEFORM("ABOUT.cpp", AboutBox);
USEFORM("manager.cpp", Form4);
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try {
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->Title = "Source Writer 3";
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TOptions), &Options);
		Application->CreateForm(__classid(TForm2), &Form2);
		Application->Run();
	}
	catch (Exception &exception) {
		Application->ShowException(&exception);
	}
	catch (...) {
		try {
			throw Exception("");
		}
		catch (Exception &exception) {
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------