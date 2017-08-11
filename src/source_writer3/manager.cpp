//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdio.h>
#pragma hdrstop
#include <inifiles.hpp>

#include "manager.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvPageControl"
#pragma link "PictureList"
#pragma link "rtflabel"
#pragma resource "*.dfm"
TForm4 *Form4;

//переменная значений языка
AnsiString lngmng;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
	Ini = new TIniFile(ExtractFilePath(Application->ExeName)+"\\Data\\config.ini");
	Form4->CheckBox1->Checked = Ini->ReadBool("Other", "mng", 0);
	Form4->CheckBox2->Checked = Ini->ReadBool("Other", "mng", 0);
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormClose(TObject *Sender, TCloseAction &Action)
{
	Ini->WriteBool("Other", "mng", CheckBox1->Checked);
	//плавно сворачиваем при закрытии
	TRect r1, r2;
	r1 = Rect(Left+Width/2, Top+Height/2, Left+Width/2, Top+Height/2);
	r2 = BoundsRect;
	DrawAnimatedRects(Handle, IDANI_CAPTION, &r2, &r1);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FormCreate(TObject *Sender)
{
	//плавно разворачиваем при открытии
	TRect r1, r2;
	r1 = Rect(Left+Width/2, Top+Height/2, Left+Width/2, Top+Height/2);
	r2 = BoundsRect;
	DrawAnimatedRects(Handle,IDANI_CAPTION, &r1, &r2);

	Ini = new TIniFile(ExtractFilePath(Application->ExeName)+"\\Data\\config.ini");
	lngmng = Ini->ReadString("lngflag", "active", "");
	//языковая функция формы
	if (lngmng == "gb") {
		Inilng = new TIniFile(ExtractFilePath(Application->ExeName)+"\\Data\\eng.lng");
	}
	if (lngmng == "ua") {
		Inilng = new TIniFile(ExtractFilePath(Application->ExeName)+"\\Data\\ua.lng");
	}
	if (lngmng == "ru") {
		Inilng = new TIniFile(ExtractFilePath(Application->ExeName)+"\\Data\\rus.lng");
	}
	Form4->Caption=Inilng->ReadString("manager", "mnr3", "");
	Form4->CheckBox1->Caption = Inilng->ReadString("form", "opt3", "");
	Form4->CheckBox2->Caption = Inilng->ReadString("form", "opt3", "");
	Form4->Button1->Caption = Inilng->ReadString("manager", "mnr1", "");
	Form4->Button2->Caption = Inilng->ReadString("manager", "mnr2", "");
	Form4->Button3->Caption = Inilng->ReadString("manager", "mnr2", "");
	Form4->Button4->Caption = Inilng->ReadString("manager", "mnr1", "");
	Form4->Label1->Caption = Inilng->ReadString("manager", "mnr4", "");
	Form4->Label2->Caption = Inilng->ReadString("manager", "mnr5", "");
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button4Click(TObject *Sender)
{
	//создаем выбранный файл
	if (Form4->CheckBox1->Checked) {
		switch (Form4->PictureList1->ItemIndex) {
			case 0:
				Form1->xml1->Click();
			break;
			case 1:
				Form1->txt1->Click();
			break;
			case 2:
				Form1->cfg1->Click();
			break;
			default:
			break;
		}
		Form4->Close();
	} else
		switch (Form4->PictureList1->ItemIndex) {
			case 0:
				Form1->xml1->Click();
			break;
			case 1:
				Form1->txt1->Click();
			break;
			case 2:
				Form1->cfg1->Click();
			break;
			default:
			break;
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button3Click(TObject *Sender)
{
	Form4->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button1Click(TObject *Sender)
{
	//создаем файл для луа
	if (Form4->CheckBox2->Checked) {
		switch (Form4->PictureList2->ItemIndex) {
			case 0:
				Form1->lua1->Click();
			break;
			default:
			break;
		}
		Form4->Close();
	} else
		switch (Form4->PictureList2->ItemIndex) {
			case 0:
				Form1->lua1->Click();
			break;
			default:
			break;
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button2Click(TObject *Sender)
{
	Form4->Close();
}
//---------------------------------------------------------------------------