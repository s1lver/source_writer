//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <inifiles.hpp>

#include "splash.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//переменная значений языка
AnsiString lang;
//переменные значений сообщений
AnsiString ms10;
AnsiString ms11;
AnsiString ms12;
AnsiString ms13;
AnsiString ms14;
AnsiString ms15;
AnsiString ms16;
AnsiString ms17;
AnsiString ms18;
AnsiString ms19;
AnsiString ms20;
AnsiString ms21;
AnsiString ms22;
AnsiString ms23;
AnsiString ms24;
AnsiString ms25;
AnsiString ms26;
AnsiString ms27;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	Ini = new TIniFile(ExtractFilePath(Application->ExeName)+"\\Data\\config.ini");
	lang = Ini->ReadString("lngflag", "active", "");
	//языковая функция формы
	if (lang == "gb") {
		Langs = new TIniFile(ExtractFilePath(Application->ExeName)+"\\Data\\eng.lng");
	}
	if (lang == "ua") {
		Langs = new TIniFile(ExtractFilePath(Application->ExeName)+"\\Data\\ua.lng");
	}
	if (lang == "ru") {
		Langs = new TIniFile(ExtractFilePath(Application->ExeName)+"\\Data\\rus.lng");
	}
	ms10 = Langs->ReadString("msg", "ms10", "");
	ms11 = Langs->ReadString("msg", "ms11", "");
	ms12 = Langs->ReadString("msg", "ms12", "");
	ms13 = Langs->ReadString("msg", "ms13", "");
	ms14 = Langs->ReadString("msg", "ms14", "");
	ms15 = Langs->ReadString("msg", "ms15", "");
	ms16 = Langs->ReadString("msg", "ms16", "");
	ms17 = Langs->ReadString("msg", "ms17", "");
	ms18 = Langs->ReadString("msg", "ms18", "");
	ms19 = Langs->ReadString("msg", "ms19", "");
	ms20 = Langs->ReadString("msg", "ms20", "");
	ms21 = Langs->ReadString("msg", "ms21", "");
	ms22 = Langs->ReadString("msg", "ms22", "");
	ms23 = Langs->ReadString("msg", "ms23", "");
	ms24 = Langs->ReadString("msg", "ms24", "");
	ms25 = Langs->ReadString("msg", "ms25", "");
	ms26 = Langs->ReadString("msg", "ms26", "");
	ms27 = Langs->ReadString("msg", "ms27", "");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
	if(FileExists(ExtractFilePath(Application->ExeName)+"\\Data\\config.ini") == false) {  
		ShowMessage("Ошибка инициализации");
		Application->Terminate();
	} else
		Form2->Label1->Caption = "Инициализация...";

	if (FileExists(ExtractFilePath(Application->ExeName)+"\\Data\\new_correct.sw") == false) {  
		ShowMessage("Не найдена библиотека коррекции");
		Application->Terminate();
	} else
		Form2->Label1->Caption = "Инициализация коррекции...";

	if (FileExists(ExtractFilePath(Application->ExeName)+"\\Data\\old_correct.sw") == false) {  
		ShowMessage("Не найдена библиотека коррекции");
		Application->Terminate();
	} else
		Form2->Label1->Caption = "Инициализация коррекции...";


	if (FileExists(ExtractFilePath(Application->ExeName)+"\\Data\\events.sw") == false) {  
		ShowMessage("Не найдена библиотека событий");
		Application->Terminate();
	} else
		Form2->Label1->Caption = "Инициализация событий...";


	if (FileExists(ExtractFilePath(Application->ExeName)+"\\Data\\function.sw") == false) {  
		ShowMessage("Не найдена библиотека функции");
		Application->Terminate();
	} else
		Form2->Label1->Caption = "Инициализация функции...";


	if (FileExists(ExtractFilePath(Application->ExeName)+"\\Data\\conditions.sw") == false) {  
		ShowMessage("Не найдена библиотека");
		Application->Terminate();
	} else
		Form2->Label1->Caption = "Инициализация...";


	/* if(FileExists(ExtractFilePath(Application->ExeName)+"\\Data\\error.dll") == false)	{  
		ShowMessage("Не найдена библиотека ошибок");
		Application->Terminate();
		} else
			Form2->Label1->Caption="Инициализация ...";
	*/

	if (FileExists(ExtractFilePath(Application->ExeName)+"\\macros\\maclist.macsw") == false) {  
		ShowMessage("Ошибка запуска макросов");
		Application->Terminate();
	} else
		Form2->Label1->Caption = "Инициализация макросов...";


	if (FileExists(ExtractFilePath(Application->ExeName)+"\\plugin\\module.sw") == false) {  
		ShowMessage("Ошибка запуска модулей");
		Application->Terminate();
	} else
		Form2->Label1->Caption = "Инициализация модулей...";


	if (FileExists(ExtractFilePath(Application->ExeName)+"\\plugin\\object.sw") == false) {  
		ShowMessage("Ошибка запуска объектов");
		Application->Terminate();
	} else
		Form2->Label1->Caption = "Инициализация объектов...";


	if (FileExists(ExtractFilePath(Application->ExeName)+"\\Data\\eng.lng") == false) {  
		ShowMessage("Не найден языковой файл");
		Application->Terminate();
	} else
		Form2->Label1->Caption = "Загрузка языков";


	if (FileExists(ExtractFilePath(Application->ExeName)+"\\Data\\rus.lng") == false) {  
		ShowMessage("Не найден языковой файл");
		Application->Terminate();
	} else
		Form2->Label1->Caption = "Загрузка языков";


	if (FileExists(ExtractFilePath(Application->ExeName)+"\\Data\\ua.lng") == false) {  
		ShowMessage("Не найден языковой файл");
		Application->Terminate();
	} else
		Form2->Label1->Caption = "Загрузка языков";
	Form2->Close();
}
//---------------------------------------------------------------------------

