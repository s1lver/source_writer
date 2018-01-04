//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		WinExec("tools//unpacker//unpacker.exe --source=..\\..\\packs\\data_0.pack --destination=..\\..\\ --verbosity=1", SW_HIDE);
	}
	if (RadioButton2->Checked) { 
		WinExec("tools//unpacker//unpacker.exe --source=..\\..\\packs\\data_1.pack --destination=..\\..\\ --verbosity=1", SW_HIDE);
	}
	if (RadioButton3->Checked) {
		WinExec("tools//unpacker//unpacker.exe --source=..\\..\\packs\\data_2.pack --destination=..\\..\\ --verbosity=1", SW_HIDE);
	}
	if (RadioButton4->Checked) {
		WinExec("tools//unpacker//unpacker.exe --source=..\\..\\packs\\data_3.pack --destination=..\\..\\ --verbosity=1", SW_HIDE);
	}
	if (RadioButton5->Checked) {
		WinExec("tools//unpacker//unpacker.exe --source=..\\..\\packs\\data_4.pack --destination=..\\..\\ --verbosity=1", SW_HIDE);
	}
	if (RadioButton6->Checked) {
		WinExec("tools//unpacker//unpacker.exe --source=..\\..\\packs\\localized.pack --destination=..\\..\\ --verbosity=1", SW_HIDE);
	}
	if (RadioButton7->Checked) {
		WinExec("tools//unpacker//unpacker.exe --source=..\\..\\packs\\*.pack --destination=..\\..\\ --verbosity=1", SW_HIDE);
	}
	if (RadioButton8->Checked) {
		WinExec("tools//unpacker//unpacker.exe --source=..\\packs\\*.pack --destination=c:\\packs\\ --filter=*.txt", SW_HIDE);
	}
	if (RadioButton9->Checked) {
		WinExec("tools//unpacker//unpacker.exe --source=..\\packs\\*.pack --destination=c:\\packs\\ --filter=*.xml", SW_HIDE);
	}
	if (RadioButton10->Checked) {
		WinExec("tools//unpacker//unpacker.exe --source=..\\packs\\*.pack --destination=c:\\packs\\ --filter=*.tga", SW_HIDE);
	}
	if (RadioButton11->Checked) {
		WinExec("tools//unpacker//unpacker.exe --source=..\\packs\\*.pack --destination=c:\\packs\\ --filter=*.wmv", SW_HIDE);
	}
	if (RadioButton12->Checked) {
		WinExec("tools//unpacker//unpacker.exe --source=..\\packs\\*.pack --destination=c:\\packs\\ --filter=*.bik", SW_HIDE);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
	if (CheckBox1->Checked) {
		Edit1->Enabled = true;
	} else {
		Edit1->Enabled = false;
	}
}
//---------------------------------------------------------------------------
