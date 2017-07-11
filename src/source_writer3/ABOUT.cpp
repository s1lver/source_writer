//---------------------------------------------------------------------
#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "About.h"
//--------------------------------------------------------------------- 
#pragma link "rtflabel"
#pragma resource "*.dfm"
TAboutBox *AboutBox;
//--------------------------------------------------------------------- 
__fastcall TAboutBox::TAboutBox(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------

void __fastcall TAboutBox::FormClose(TObject *Sender, TCloseAction &Action)
{
	//плавно сворачиваем при закрытии
	TRect r1,r2;
	r1 = Rect(Left+Width/2,Top+Height/2,Left+Width/2,Top+Height/2);
	r2 = BoundsRect;
	DrawAnimatedRects(Handle, IDANI_CAPTION, &r2, &r1);
}
//---------------------------------------------------------------------------

void __fastcall TAboutBox::FormCreate(TObject *Sender)
{
	//плавно разворачиваем при открытии
	TRect r1,r2;
	r1 = Rect(Left+Width/2,Top+Height/2,Left+Width/2,Top+Height/2);
	r2 = BoundsRect;
	DrawAnimatedRects(Handle, IDANI_CAPTION, &r1, &r2);
}
//---------------------------------------------------------------------------

void __fastcall TAboutBox::FormShow(TObject *Sender)
{
	//показываем размер/доступную память ПК
	TMemoryStatus MS;
    MS.dwLength = sizeof(MS);
    GlobalMemoryStatus(&MS);
	Label3->Caption = FormatFloat("#,###' KB'", MS.dwTotalPhys / 1024);
    CHAR lpMemLoad[5];
    sprintf(lpMemLoad, "%d %%", MS.dwMemoryLoad);
	Label4->Caption = lpMemLoad;
}
//---------------------------------------------------------------------------

void __fastcall TAboutBox::Label5Click(TObject *Sender)
{
	//преходим на сайт
	ShellExecute(Handle, "open", "http://www.goldencentury.org", NULL, NULL, SW_RESTORE);
}
//---------------------------------------------------------------------------

void __fastcall TAboutBox::Image1Click(TObject *Sender)
{
	AboutBox->Close();
}
//---------------------------------------------------------------------------
