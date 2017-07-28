//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdio.h>
#include <inifiles.hpp>
#pragma hdrstop

#include "Unit1.h"
#include "goto.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//переменна¤ значений ¤зыка
AnsiString lng3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action)
{
	//плавно сворачиваем при закрытии
	TRect r1,r2;
	r1 = Rect(Left+Width/2, Top+Height/2, Left+Width/2, Top+Height/2);
	r2 = BoundsRect;
	DrawAnimatedRects(Handle, IDANI_CAPTION, &r2, &r1);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormCreate(TObject *Sender)
{
	//плавно разворачиваем при открытии
	TRect r1,r2;
	r1 = Rect(Left+Width/2, Top+Height/2, Left+Width/2, Top+Height/2);
	r2 = BoundsRect;
	DrawAnimatedRects(Handle, IDANI_CAPTION, &r1, &r2);
	Ini = new TIniFile(ExtractFilePath(Application->ExeName)+"\\Data\\config.ini");
	//запоминаем значение ¤зыка
	lng3 = Ini->ReadString("lngflag", "active", "");
	//Языковая функция формы
	if (lng3 == "gb") {
		Ini = new TIniFile(ExtractFilePath(Application->ExeName)+"\\Data\\eng.lng");
	}
	if (lng3 == "ua") {
		Ini = new TIniFile(ExtractFilePath(Application->ExeName)+"\\Data\\ua.lng");
	}
	if (lng3 == "ru") {
		Ini = new TIniFile(ExtractFilePath(Application->ExeName)+"\\Data\\rus.lng");
	}
	Form3->Caption = Ini->ReadString("goto", "cap", "ѕерейти...");
	Form3->BitBtn1->Caption = Ini->ReadString("goto", "btn1", "ѕерейти");
}
//---------------------------------------------------------------------------

void __fastcall TForm3::BitBtn1Click(TObject *Sender)
{
	//ѕереходим в нужную строку
	Form1->memo[Form1->AdvPageControl1->ActivePageIndex]->SelStart;
	Form1->memo[Form1->AdvPageControl1->ActivePageIndex]->SetCursor(StrToInt(Edit1->Text)-1, StrToInt(Edit1->Text)-1);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender)
{
	Form3->Close();
}
//---------------------------------------------------------------------------
