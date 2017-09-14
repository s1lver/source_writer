//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdio.h>
#include <inifiles.hpp>
#include <conio.h>
#include <string.h>
#include <iostream.h>
#include <windows.h>
#include <winuser.h>
#pragma hdrstop

#include "Unit1.h"
#include "object.h"
#include "splash.h"
#include "About.h"
#include "goto.h"
#include "manager.h"
#include "option.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvToolBar"
#pragma link "AdvToolBarStylers"
#pragma link "AdvOfficeStatusBar"
#pragma link "AdvOfficeStatusBarStylers"
#pragma link "AdvMemo"
#pragma link "AdvmWS"
#pragma link "Advmxml"
#pragma link "AdvCodeList"
#pragma link "MacroRecorder"
#pragma link "AdvSplitter"
#pragma link "ToolPanels"
#pragma link "AdvTabSet"
#pragma link "AdvNavBar"
#pragma link "AdvPageControl"
#pragma link "WUpdate"
#pragma link "WUpdateWiz"
#pragma link "AdvReflectionLabel"
#pragma link "DirOutln"
#pragma link "paramlst"
#pragma link "AdvmPS"
#pragma link "AdvmINIs"
#pragma link "AdvmCSHS"
#pragma resource "*.dfm"
TForm1 *Form1;
AnsiString FName;
int TabCount = 0;
//переменная расширения файла
AnsiString extens;
//переменная значений языка
AnsiString lng;
//переменная автоматического сохранения
int sav;
//переменная активности отладчика
int debugs;
//переменная номера таба
int tab;
//игровые переменные
int game1;
int game2;
int mod1;
int mod2;
//переменные обновления
int run;
int start;
int autors;
int port;
int proxy;
AnsiString proxypass;
AnsiString proxyuser;
int usee;
//переменные сообщений
AnsiString ms1;
AnsiString ms2;
AnsiString ms3;
AnsiString ms4;
AnsiString ms5;
AnsiString ms6;
AnsiString ms7;
AnsiString ms8;
AnsiString ms9;
//переменная значения индекса
int findex;
//переменные макросов
int mac1;
int mac2;
int mac3;
int mac4;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Ini = new TIniFile(ExtractFilePath(Application->ExeName)+"\\Data\\config.ini");
	//запоминаем значение автоматического сохранения
	sav = Ini->ReadInteger("general", "save", 0);
	//запоминаем значение активности отладчика
	debugs = Ini->ReadInteger("debuger", "activedebug", 0);

	//запоминаем значения переменных макрорекордера
	mac1 = Ini->ReadInteger("Macros", "Norm", 0);
	mac2 = Ini->ReadInteger("Macros", "Fast", 0);
	mac3 = Ini->ReadInteger("Macros", "Sys", 0);
	mac4 = Ini->ReadInteger("Macros", "App", 0);

	//запоминаем значения игровых переменных
	game1 = Ini->ReadInteger("Game", "game1", 0);
	game2 = Ini->ReadInteger("Game", "game2", 0);
	mod1 = Ini->ReadInteger("Game", "mod1", 0);
	mod2 = Ini->ReadInteger("Game", "mod2", 0);
	//запоминаем значения обновления
	run = Ini->ReadInteger("update", "run", 0);
	start = Ini->ReadInteger("update", "start", 0);
	autors = Ini->ReadInteger("update", "auto", 0);
	//запоминаем значение языка
	lng = Ini->ReadString("lngflag", "active", "");

	//языковая функция формы
	if (lng == "gb") {
		Ini = new TIniFile(ExtractFilePath(Application->ExeName)+"\\Data\\eng.lng");
	}
	if (lng == "ua") {
		Ini = new TIniFile(ExtractFilePath(Application->ExeName)+"\\Data\\ua.lng");
	}
	if (lng == "ru") {
		Ini = new TIniFile(ExtractFilePath(Application->ExeName)+"\\Data\\rus.lng");
	}
	//главное меню
	Form1->N6->Caption = Ini->ReadString("menu", "btnmenu1", "");
	Form1->N7->Caption = Ini->ReadString("menu", "btnmenu2", "");
	Form1->N8->Caption = Ini->ReadString("menu", "btnmenu3", "");
	Form1->N9->Caption = Ini->ReadString("menu", "btnmenu4", "");
	Form1->N10->Caption = Ini->ReadString("menu", "btnmenu5", "");
	Form1->N12->Caption = Ini->ReadString("menu", "btnmenu6", "");
	Form1->N13->Caption = Ini->ReadString("menu", "btnmenu7", "");
	Form1->N14->Caption = Ini->ReadString("menu", "btnmenu8", "");
	Form1->N29->Caption = Ini->ReadString("menu", "btnmenu9", "");
	Form1->N31->Caption = Ini->ReadString("menu", "btnmenu10", "");
	Form1->N16->Caption = Ini->ReadString("menu", "btnmenu11", "");
	Form1->N60->Caption = Ini->ReadString("menu", "btnmenu12", "");
	Form1->N18->Caption = Ini->ReadString("menu", "btnmenu13", "");
	Form1->N19->Caption = Ini->ReadString("menu", "btnmenu14", "");
	Form1->N22->Caption = Ini->ReadString("menu", "btnmenu15", "");
	Form1->N23->Caption = Ini->ReadString("menu", "btnmenu16", "");
	Form1->N24->Caption = Ini->ReadString("menu", "btnmenu17", "");
	Form1->N25->Caption = Ini->ReadString("menu", "btnmenu18", "");
	Form1->N27->Caption = Ini->ReadString("menu", "btnmenu19", "");
	Form1->N28->Caption = Ini->ReadString("menu", "btnmenu20", "");
	Form1->N34->Caption = Ini->ReadString("menu", "btnmenu21", "");
	Form1->N35->Caption = Ini->ReadString("menu", "btnmenu22", "");
	Form1->N70->Caption = Ini->ReadString("menu", "btnmenu23", "");
	Form1->N21->Caption = Ini->ReadString("menu", "btnmenu24", "");
	Form1->N40->Caption = Ini->ReadString("menu", "btnmenu25", "");
	Form1->N62->Caption = Ini->ReadString("menu", "btnmenu26", "");
	Form1->N73->Caption = Ini->ReadString("menu", "btnmenu27", "");
	Form1->N45->Caption = Ini->ReadString("menu", "btnmenu28", "");
	Form1->N72->Caption = Ini->ReadString("menu", "btnmenu29", "");
	Form1->N46->Caption = Ini->ReadString("menu", "btnmenu30", "");
	Form1->N39->Caption = Ini->ReadString("menu", "btnmenu31", "");
	Form1->N54->Caption = Ini->ReadString("menu", "btnmenu32", "");
	Form1->N65->Caption = Ini->ReadString("menu", "btnmenu33", "");
	Form1->N66->Caption = Ini->ReadString("menu", "btnmenu34", "");
	Form1->N32->Caption = Ini->ReadString("menu", "btnmenu35", "");
	Form1->N55->Caption = Ini->ReadString("menu", "btnmenu36", "");
	Form1->N69->Caption = Ini->ReadString("menu", "btnmenu37", "");
	Form1->N67->Caption = Ini->ReadString("menu", "btnmenu38", "");
	Form1->N41->Caption = Ini->ReadString("menu", "btnmenu39", "");
	Form1->N17->Caption = Ini->ReadString("menu", "btnmenu40", "");
	Form1->N57->Caption = Ini->ReadString("menu", "btnmenu41", "");
	Form1->N43->Caption = Ini->ReadString("menu", "btnmenu42", "");
	Form1->N80->Caption = Ini->ReadString("menu", "btnmenu43", "");
	Form1->N83->Caption = Ini->ReadString("menu", "btnmenu44", "");
	Form1->N59->Caption = Ini->ReadString("menu", "btnmenu45", "");
	//панели инструментов
	Form1->CategoryPanel4->Caption = Ini->ReadString("tools", "tl1", "");
	Form1->CategoryPanel6->Caption = Ini->ReadString("tools", "tl2", "");
	Form1->CategoryPanel7->Caption = Ini->ReadString("tools", "tl3", "");
	Form1->CategoryPanel8->Caption = Ini->ReadString("tools", "tl4", "");
	Form1->AdvTabSheet2->Caption = Ini->ReadString("tools", "tl5", "");
	Form1->AdvTabSheet3->Caption = Ini->ReadString("tools", "tl6", "");
	Form1->AdvTabSheet4->Caption = Ini->ReadString("tools", "tl7", "");
	Form1->CategoryPanel5->Caption = Ini->ReadString("tools", "tl8", "");
	Form1->CategoryPanel9->Caption = Ini->ReadString("menu", "btnmenu26", "");
	Form1->SpeedButton6->Caption = Ini->ReadString("menu", "btnmenu51", "");
	//гобальные значения
	Form1->AdvTabSheet1->Caption = Ini->ReadString("global", "gl1", "");
	Form1->GroupBox1->Caption = Ini->ReadString("global", "gl2", "");
	Form1->RadioButton1->Caption = Ini->ReadString("global", "gl3", "");
	Form1->RadioButton2->Caption = Ini->ReadString("global", "gl4", "");
	Form1->RadioButton3->Caption = Ini->ReadString("global", "gl5", "");
	Form1->Label1->Caption = Ini->ReadString("global", "gl6", "");
	Form1->N36->Caption = Ini->ReadString("global", "gl8", "");
	Form1->N38->Caption = Ini->ReadString("menu", "btnmenu21", "");
	Form1->AdvTabSet1->AdvTabs->Items[0]->Caption = Ini->ReadString("global", "gl7", "");
	//систрей
	Form1->N48->Caption = Ini->ReadString("menu", "btnmenu11", "");
	Form1->N52->Caption = Ini->ReadString("menu", "btnmenu42", "");
	Form1->N53->Caption = Ini->ReadString("menu", "btnmenu41", "");
	Form1->N50->Caption = Ini->ReadString("menu", "btnmenu46", "");
	Form1->N47->Caption = Ini->ReadString("menu", "btnmenu47", "");
	//сообщения
	ms1 = Ini->ReadString("msg", "ms1", "");
	ms2 = Ini->ReadString("msg", "ms2", "");
	ms3 = Ini->ReadString("msg", "ms3", "");
	ms4 = Ini->ReadString("msg", "ms4", "");
	ms5 = Ini->ReadString("msg", "ms5", "");
	ms6 = Ini->ReadString("msg", "ms6", "");
	ms7 = Ini->ReadString("msg", "ms7", "");
	ms8 = Ini->ReadString("msg", "ms8", "");
	ms9 = Ini->ReadString("msg", "ms9", "");
	//контекстное меню
	Form1->N3->Caption = Ini->ReadString("menu", "btnmenu15", "");
	Form1->N2->Caption = Ini->ReadString("menu", "btnmenu16", "");
	Form1->N4->Caption = Ini->ReadString("menu", "btnmenu17", "");
	Form1->N5->Caption = Ini->ReadString("menu", "btnmenu18", "");
	Form1->N74->Caption = Ini->ReadString("menu", "btnmenu48", "");
	Form1->N75->Caption = Ini->ReadString("menu", "btnmenu49", "");
	Form1->N63->Caption = Ini->ReadString("menu", "btnmenu50", "");
	//хинты
	Form1->ToolButton1->Hint = Ini->ReadString("menu", "btnmenu6", "");
	Form1->ToolButton2->Hint = Ini->ReadString("menu", "btnmenu7", "");
	Form1->ToolButton3->Hint = Ini->ReadString("menu", "btnmenu8", "");
	Form1->ToolButton5->Hint = Ini->ReadString("menu", "btnmenu15", "");
	Form1->ToolButton6->Hint = Ini->ReadString("menu", "btnmenu16", "");
	Form1->ToolButton7->Hint = Ini->ReadString("menu", "btnmenu17", "");
	Form1->ToolButton8->Hint = Ini->ReadString("menu", "btnmenu18", "");
	Form1->ToolButton10->Hint = Ini->ReadString("menu", "btnmenu14", "");
	Form1->ToolButton11->Hint = Ini->ReadString("menu", "btnmenu13", "");
	Form1->ToolButton13->Hint = Ini->ReadString("menu", "btnmenu21", "");
	Form1->ToolButton14->Hint = Ini->ReadString("hint", "ht1", "");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N1Click(TObject *Sender)
{
	//Закрываем активную вкладку из попапменню
	if ( AdvPageControl1->ActivePage != NULL) {
		for (int i = 0; i < AdvPageControl1->ActivePage->ComponentCount; i++) {
			if (String(AdvPageControl1->ActivePage->Components[i]->ClassName()) == "TAdvMemo") {
				AdvPageControl1->ActivePage->Components[i]->Free();
				TabCount--;
				tab--;
			}
			if (tab == 0)
				noactbtn();
		}
	}
	delete AdvPageControl1->ActivePage;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolButton8Click(TObject *Sender)
{
	//удаляем с панели инструментов
	memo[AdvPageControl1->ActivePageIndex]->ClearSelection();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolButton3Click(TObject *Sender)
{
	//сохраняем с панели инструментов
	if ( AdvPageControl1->ActivePage != NULL) {
		for (int i = 0; i < AdvPageControl1->ActivePage->ComponentCount; i++) {
			if (String(AdvPageControl1->ActivePage->Components[i]->ClassName()) == "TAdvMemo") {
				if (SaveDialog1->Execute()) {
					TAdvMemo *memo = (TAdvMemo *)AdvPageControl1->ActivePage->Components[i];
					memo->Lines->SaveToFile(SaveDialog1->FileName);
					break;
				}  
			}  
		} 
	}   
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolButton2Click(TObject *Sender)
{
	//открываем файл с панели инструментов
	Form1->N13->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::txt1Click(TObject *Sender)
{
  //создаем новый файл формата *.txt
   pts[TabCount] = new TAdvTabSheet(this);
   pts[TabCount]->AdvPageControl = AdvPageControl1;
   pts[TabCount]->Caption = "TW Script"+IntToStr(TabCount);
   pts[TabCount]->ImageIndex=10;
   memo[TabCount] = new TAdvMemo(pts[TabCount]);
   memo[TabCount]->Parent = pts[TabCount];
   memo[TabCount]->Align = alClient;
   memo[TabCount]->SyntaxStyles = AdvJSMemoStyler1;
   memo[TabCount]->Gutter->ShowLeadingZeros = true;
   memo[TabCount]->Gutter->ShowLineNumbers = true;
   memo[TabCount]->Gutter->GutterWidth = 60;
   memo[TabCount]->Gutter->GutterMargin = 45;
   memo[TabCount]->Gutter->ShowModified = true;
   memo[TabCount]->Gutter->ModifiedColor = clYellow;
   memo[TabCount]->Gutter->ModifiedColorBkg = clLime;
   memo[TabCount]->AutoIndent = true;
   memo[TabCount]->AcceptFiles = true;
   memo[TabCount]->MarkerList->MarkerImageList = ImageList3;
   memo[TabCount]->UndoLimit = 250;
   memo[TabCount]->WordWrap = wwClientWidth;
   memo[TabCount]->ActiveLineSettings->ActiveLineAtCursor = true;
   memo[TabCount]->ActiveLineSettings->ShowActiveLine = true;
   memo[TabCount]->ActiveLineSettings->ShowActiveLineIndicator = true;
   memo[TabCount]->ActiveLineSettings->ActiveLineColor = clSkyBlue;
   memo[TabCount]->AutoCompletion->Active = true;
   memo[TabCount]->AutoCompletion->AutoDisplay = true;
   memo[TabCount]->AutoCompletion->Delay = 100;
   memo[TabCount]->SyntaxStyles->AutoCompletion->LoadFromFile(ExtractFilePath(Application->ExeName)+"\\Data\\function.sw");
   memo[TabCount]->AutoCodeFold();
   memo[TabCount]->CodeFolding->Enabled = true;
   memo[TabCount]->AutoCorrect->Active = true;
   memo[TabCount]->AutoCorrect->OldValue->LoadFromFile(ExtractFilePath(Application->ExeName)+"\\Data\\old_correct.sw");
   memo[TabCount]->AutoCorrect->NewValue->LoadFromFile(ExtractFilePath(Application->ExeName)+"\\Data\\new_correct.sw");;
   memo[TabCount]->PopupMenu = PopupMenu2;
   memo[TabCount]->OnClick = MemoClick;
   memo[TabCount]->OnKeyPress = MemoKeyPress;
   Form1->StatusBar1->Panels->Items[2]->Text = "TW Script Color";
   memo[TabCount]->Clear();
   TabCount++;
   //накапливаем кол-во вкладок txt
   tab++;
   actbtn();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N16Click(TObject *Sender)
{
	//закрываем форму из главного меню
	Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::txt2Click(TObject *Sender)
{
	//создаем новый файл формата *.txt
	Form1->txt1->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N17Click(TObject *Sender)
{
	//открываем текстовый файл с последними изменениями
	ShellExecute(Handle, "open", "new.txt", NULL, NULL, SW_RESTORE);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N13Click(TObject *Sender)
{
	//открываем файл из главного меню
	if (!Form1->OpenDialog1->Execute()) return;
	findex = Form1->OpenDialog1->FilterIndex;	
	if (findex == 1) {
		pts[TabCount] = new TAdvTabSheet(this);
		pts[TabCount]->AdvPageControl = AdvPageControl1;
		pts[TabCount]->Caption = ExtractFileName(OpenDialog1->FileName);
		pts[TabCount]->ImageIndex = 10;
		memo[TabCount] = new TAdvMemo(pts[TabCount]);
		memo[TabCount]->Parent = pts[TabCount];
		memo[TabCount]->Align = alClient;
		memo[TabCount]->Clear();
		memo[TabCount]->SyntaxStyles = AdvJSMemoStyler1;
		memo[TabCount]->Gutter->ShowLeadingZeros = true;
		memo[TabCount]->Gutter->ShowLineNumbers = true;
		memo[TabCount]->Gutter->GutterWidth = 60;
		memo[TabCount]->Gutter->GutterMargin = 45;
		memo[TabCount]->Gutter->ShowModified = true;
		memo[TabCount]->Gutter->ModifiedColor = clYellow;
		memo[TabCount]->Gutter->ModifiedColorBkg = clLime;
		memo[TabCount]->AutoIndent = true;
		memo[TabCount]->AcceptFiles = true;
		memo[TabCount]->MarkerList->MarkerImageList = ImageList3;
		memo[TabCount]->UndoLimit = 250;
		memo[TabCount]->WordWrap = wwClientWidth;
		memo[TabCount]->ActiveLineSettings->ActiveLineAtCursor = true;
		memo[TabCount]->ActiveLineSettings->ShowActiveLine = true;
		memo[TabCount]->ActiveLineSettings->ShowActiveLineIndicator = true;
		memo[TabCount]->ActiveLineSettings->ActiveLineColor = clSkyBlue;
		memo[TabCount]->AutoCompletion->Active = true;
		memo[TabCount]->AutoCompletion->AutoDisplay = true;
		memo[TabCount]->AutoCodeFold();
		memo[TabCount]->CodeFolding->Enabled = true;
		memo[TabCount]->AutoCorrect->Active = true;
		memo[TabCount]->AutoCorrect->OldValue->LoadFromFile(ExtractFilePath(Application->ExeName)+"\\Data\\old_correct.sw");
		memo[TabCount]->AutoCorrect->NewValue->LoadFromFile(ExtractFilePath(Application->ExeName)+"\\Data\\new_correct.sw");
		memo[TabCount]->PopupMenu = PopupMenu2;
		memo[TabCount]->OnClick = MemoClick;
		memo[TabCount]->OnKeyPress = MemoKeyPress;
		memo[TabCount]->Lines->LoadFromFile(OpenDialog1->FileName);
		memo[TabCount]->OnClick = MemoClick;
		memo[TabCount]->OnKeyPress = MemoKeyPress;
		StatusBar1->Panels->Items[0]->Text = OpenDialog1->FileName;
		TabCount++;
		actbtn();
	}
	if (findex == 2) {
		pts[TabCount] = new TAdvTabSheet(this);
		pts[TabCount]->AdvPageControl = AdvPageControl1;
		pts[TabCount]->Caption = ExtractFileName(OpenDialog1->FileName);
		pts[TabCount]->ImageIndex = 13;
		memo[TabCount] = new TAdvMemo(pts[TabCount]);
		memo[TabCount]->Parent = pts[TabCount];
		memo[TabCount]->Align = alClient;
		memo[TabCount]->Clear();
		memo[TabCount]->SyntaxStyles = AdvXMLMemoStyler1;
		memo[TabCount]->Gutter->ShowLeadingZeros = true;
		memo[TabCount]->Gutter->ShowLineNumbers = true;
		memo[TabCount]->Gutter->GutterWidth = 60;
		memo[TabCount]->Gutter->GutterMargin = 45;
		memo[TabCount]->Gutter->ShowModified = true;
		memo[TabCount]->Gutter->ModifiedColor = clYellow;
		memo[TabCount]->Gutter->ModifiedColorBkg = clLime;
		memo[TabCount]->AutoIndent = true;
		memo[TabCount]->AcceptFiles = true;
		memo[TabCount]->MarkerList->MarkerImageList = ImageList3;
		memo[TabCount]->UndoLimit = 250;
		memo[TabCount]->WordWrap = wwClientWidth;
		memo[TabCount]->ActiveLineSettings->ActiveLineAtCursor = true;
		memo[TabCount]->ActiveLineSettings->ShowActiveLine = true;
		memo[TabCount]->ActiveLineSettings->ShowActiveLineIndicator = true;
		memo[TabCount]->ActiveLineSettings->ActiveLineColor = clSkyBlue;
		memo[TabCount]->AutoCompletion->Active = true;
		memo[TabCount]->AutoCompletion->AutoDisplay = true;
		memo[TabCount]->AutoCodeFold();
		memo[TabCount]->CodeFolding->Enabled = true;
		memo[TabCount]->AutoCorrect->Active = true;
		memo[TabCount]->AutoCorrect->OldValue->LoadFromFile(ExtractFilePath(Application->ExeName)+"\\Data\\old_correct.sw");
		memo[TabCount]->AutoCorrect->NewValue->LoadFromFile(ExtractFilePath(Application->ExeName)+"\\Data\\new_correct.sw");;
		memo[TabCount]->PopupMenu = PopupMenu2;
		memo[TabCount]->OnClick = MemoClick;
		memo[TabCount]->OnKeyPress = MemoKeyPress;
		memo[TabCount]->Lines->LoadFromFile(OpenDialog1->FileName);
		memo[TabCount]->OnClick = MemoClick;
		memo[TabCount]->OnKeyPress = MemoKeyPress;
		StatusBar1->Panels->Items[0]->Text = OpenDialog1->FileName;
		TabCount++;
		actbtn();
	}
	if (findex == 3) {
		pts[TabCount] = new TAdvTabSheet(this);
		pts[TabCount]->AdvPageControl = AdvPageControl1;
		pts[TabCount]->Caption = ExtractFileName(OpenDialog1->FileName);
		pts[TabCount]->ImageIndex = 12;
		memo[TabCount] = new TAdvMemo(pts[TabCount]);
		memo[TabCount]->Parent = pts[TabCount];
		memo[TabCount]->Align = alClient;
		memo[TabCount]->Clear();
		memo[TabCount]->SyntaxStyles = AdvINIMemoStyler1;
		memo[TabCount]->Gutter->ShowLeadingZeros = true;
		memo[TabCount]->Gutter->ShowLineNumbers = true;
		memo[TabCount]->Gutter->GutterWidth = 60;
		memo[TabCount]->Gutter->GutterMargin = 45;
		memo[TabCount]->Gutter->ShowModified = true;
		memo[TabCount]->Gutter->ModifiedColor = clYellow;
		memo[TabCount]->Gutter->ModifiedColorBkg = clLime;
		memo[TabCount]->AutoIndent = true;
		memo[TabCount]->AcceptFiles = true;
		memo[TabCount]->MarkerList->MarkerImageList = ImageList3;
		memo[TabCount]->UndoLimit = 250;
		memo[TabCount]->WordWrap = wwClientWidth;
		memo[TabCount]->ActiveLineSettings->ActiveLineAtCursor = true;
		memo[TabCount]->ActiveLineSettings->ShowActiveLine = true;
		memo[TabCount]->ActiveLineSettings->ShowActiveLineIndicator = true;
		memo[TabCount]->ActiveLineSettings->ActiveLineColor = clSkyBlue;
		memo[TabCount]->AutoCompletion->Active = true;
		memo[TabCount]->AutoCompletion->AutoDisplay = true;
		memo[TabCount]->AutoCodeFold();
		memo[TabCount]->CodeFolding->Enabled = true;
		memo[TabCount]->AutoCorrect->Active = true;
		memo[TabCount]->AutoCorrect->OldValue->LoadFromFile(ExtractFilePath(Application->ExeName)+"\\Data\\old_correct.sw");
		memo[TabCount]->AutoCorrect->NewValue->LoadFromFile(ExtractFilePath(Application->ExeName)+"\\Data\\new_correct.sw");;
		memo[TabCount]->PopupMenu = PopupMenu2;
		memo[TabCount]->OnClick = MemoClick;
		memo[TabCount]->OnKeyPress = MemoKeyPress;
		memo[TabCount]->Lines->LoadFromFile(OpenDialog1->FileName);
		memo[TabCount]->OnClick = MemoClick;
		memo[TabCount]->OnKeyPress = MemoKeyPress;
		StatusBar1->Panels->Items[0]->Text = OpenDialog1->FileName;
		TabCount++;
		actbtn();
	}
	if (findex == 4) {
		pts[TabCount] = new TAdvTabSheet(this);
		pts[TabCount]->AdvPageControl = AdvPageControl1;
		pts[TabCount]->Caption = ExtractFileName(OpenDialog1->FileName);
		memo[TabCount] = new TAdvMemo(pts[TabCount]);
		memo[TabCount]->Parent = pts[TabCount];
		memo[TabCount]->Align = alClient;
		memo[TabCount]->Clear();
		memo[TabCount]->Gutter->ShowLeadingZeros = true;
		memo[TabCount]->Gutter->ShowLineNumbers = true;
		memo[TabCount]->Gutter->GutterWidth = 60;
		memo[TabCount]->Gutter->GutterMargin = 45;
		memo[TabCount]->Gutter->ShowModified = true;
		memo[TabCount]->Gutter->ModifiedColor = clYellow;
		memo[TabCount]->Gutter->ModifiedColorBkg = clLime;
		memo[TabCount]->AutoIndent = true;
		memo[TabCount]->AcceptFiles = true;
		memo[TabCount]->MarkerList->MarkerImageList = ImageList3;
		memo[TabCount]->UndoLimit = 250;
		memo[TabCount]->WordWrap = wwClientWidth;
		memo[TabCount]->ActiveLineSettings->ActiveLineAtCursor = true;
		memo[TabCount]->ActiveLineSettings->ShowActiveLine = true;
		memo[TabCount]->ActiveLineSettings->ShowActiveLineIndicator = true;
		memo[TabCount]->ActiveLineSettings->ActiveLineColor = clSkyBlue;
		memo[TabCount]->AutoCompletion->Active = true;
		memo[TabCount]->AutoCompletion->AutoDisplay = true;
		memo[TabCount]->AutoCodeFold();
		memo[TabCount]->CodeFolding->Enabled = true;
		memo[TabCount]->AutoCorrect->Active = true;
		memo[TabCount]->AutoCorrect->OldValue->LoadFromFile(ExtractFilePath(Application->ExeName)+"\\Data\\old_correct.sw");
		memo[TabCount]->AutoCorrect->NewValue->LoadFromFile(ExtractFilePath(Application->ExeName)+"\\Data\\new_correct.sw");;
		memo[TabCount]->PopupMenu = PopupMenu2;
		memo[TabCount]->OnClick = MemoClick;
		memo[TabCount]->OnKeyPress = MemoKeyPress;
		memo[TabCount]->Lines->LoadFromFile(OpenDialog1->FileName);
		memo[TabCount]->OnClick = MemoClick;
		memo[TabCount]->OnKeyPress = MemoKeyPress;
		StatusBar1->Panels->Items[0]->Text = OpenDialog1->FileName;
		TabCount++;
		actbtn();
	}
	if (findex == 5) {
		pts[TabCount] = new TAdvTabSheet(this);
		pts[TabCount]->AdvPageControl = AdvPageControl1;
		pts[TabCount]->Caption = ExtractFileName(OpenDialog1->FileName);
		pts[TabCount]->ImageIndex = 11;
		memo[TabCount] = new TAdvMemo(pts[TabCount]);
		memo[TabCount]->Parent = pts[TabCount];
		memo[TabCount]->Align = alClient;
		memo[TabCount]->Clear();
		memo[TabCount]->SyntaxStyles = AdvPascalMemoStyler1;
		memo[TabCount]->Gutter->ShowLeadingZeros = true;
		memo[TabCount]->Gutter->ShowLineNumbers = true;
		memo[TabCount]->Gutter->GutterWidth = 60;
		memo[TabCount]->Gutter->GutterMargin = 45;
		memo[TabCount]->Gutter->ShowModified = true;
		memo[TabCount]->Gutter->ModifiedColor = clYellow;
		memo[TabCount]->Gutter->ModifiedColorBkg = clLime;
		memo[TabCount]->AutoIndent = true;
		memo[TabCount]->AcceptFiles = true;
		memo[TabCount]->MarkerList->MarkerImageList = ImageList3;
		memo[TabCount]->UndoLimit = 250;
		memo[TabCount]->WordWrap = wwClientWidth;
		memo[TabCount]->ActiveLineSettings->ActiveLineAtCursor = true;
		memo[TabCount]->ActiveLineSettings->ShowActiveLine = true;
		memo[TabCount]->ActiveLineSettings->ShowActiveLineIndicator = true;
		memo[TabCount]->ActiveLineSettings->ActiveLineColor = clSkyBlue;
		memo[TabCount]->AutoCompletion->Active = true;
		memo[TabCount]->AutoCompletion->AutoDisplay = true;
		memo[TabCount]->AutoCodeFold();
		memo[TabCount]->CodeFolding->Enabled = true;
		memo[TabCount]->AutoCorrect->Active = true;
		memo[TabCount]->AutoCorrect->OldValue->LoadFromFile(ExtractFilePath(Application->ExeName)+"\\Data\\old_correct.sw");
		memo[TabCount]->AutoCorrect->NewValue->LoadFromFile(ExtractFilePath(Application->ExeName)+"\\Data\\new_correct.sw");;
		memo[TabCount]->PopupMenu = PopupMenu2;
		memo[TabCount]->OnClick = MemoClick;
		memo[TabCount]->OnKeyPress = MemoKeyPress;
		memo[TabCount]->Lines->LoadFromFile(OpenDialog1->FileName);
		memo[TabCount]->OnClick = MemoClick;
		memo[TabCount]->OnKeyPress = MemoKeyPress;
		StatusBar1->Panels->Items[0]->Text = OpenDialog1->FileName;
		TabCount++;
		actbtn();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N14Click(TObject *Sender)
{
	//сохраняем из главного меню
	//SaveDialog1->FileName=FName;
	if (AdvPageControl1->ActivePage != NULL) {
		for (int i = 0; i < AdvPageControl1->ActivePage->ComponentCount; i++) {
			if (String(AdvPageControl1->ActivePage->Components[i]->ClassName()) == "TAdvMemo") {
				if (SaveDialog1->Execute()) {
					TAdvMemo *memo = (TAdvMemo *)AdvPageControl1->ActivePage->Components[i];
					memo->Lines->SaveToFile(SaveDialog1->FileName);
					break;
				}  
			}  
		} 
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N21Click(TObject *Sender)
{
	//открываем второе окно
	N21->Checked =!N21->Checked;
	AdvPageControl2->Visible = N21->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N18Click(TObject *Sender)
{
	//отменяем из главного меню
	memo[AdvPageControl1->ActivePageIndex]->Undo();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolButton11Click(TObject *Sender)
{
	//отменяем с панели инструментов
	memo[AdvPageControl1->ActivePageIndex]->Undo();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolButton10Click(TObject *Sender)
{
	//повторяем с панели инструментов
	memo[AdvPageControl1->ActivePageIndex]->Redo();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N19Click(TObject *Sender)
{
	//повторяем из главного меню
	memo[AdvPageControl1->ActivePageIndex]->Redo();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolButton6Click(TObject *Sender)
{
	//копируем с панели инструментов
	memo[AdvPageControl1->ActivePageIndex]->CopyToClipBoard();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolButton7Click(TObject *Sender)
{
	//вставляем с панели инструментов
	memo[AdvPageControl1->ActivePageIndex]->PasteFromClipBoard();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolButton5Click(TObject *Sender)
{
	//вырезаем с панели инструментов
	memo[AdvPageControl1->ActivePageIndex]->CutToClipBoard();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N22Click(TObject *Sender)
{
	//вырезаем из главного меню
	memo[AdvPageControl1->ActivePageIndex]->CutToClipBoard();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N23Click(TObject *Sender)
{
	//копируем из главного меню
	memo[AdvPageControl1->ActivePageIndex]->CopyToClipBoard();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N24Click(TObject *Sender)
{
	//вставляем из главного меню
	memo[AdvPageControl1->ActivePageIndex]->PasteFromClipBoard();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N25Click(TObject *Sender)
{
	//удаляем из главного меню
	memo[AdvPageControl1->ActivePageIndex]->ClearSelection();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N28Click(TObject *Sender)
{
	//выделяем все из главного меню
	memo[AdvPageControl1->ActivePageIndex]->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N27Click(TObject *Sender)
{
	//удаляем все из главного меню
	memo[AdvPageControl1->ActivePageIndex]->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolButton14Click(TObject *Sender)
{
	//обновляем текстовое поле
	memo[AdvPageControl1->ActivePageIndex]->RefreshMemo();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N32Click(TObject *Sender)
{
	//запускаем репозитории объектов
	Application->CreateForm(__classid(TObject_form), &Object_form);
	Object_form->ShowModal();
	Object_form->Free();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolButton13Click(TObject *Sender)
{
	//производим поиск с панели инструментов
	AdvMemoFindDialog1->AdvMemo = memo[AdvPageControl1->ActivePageIndex];
	AdvMemoFindDialog1->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N34Click(TObject *Sender)
{
	//производим поиск из главного меню
	AdvMemoFindDialog1->AdvMemo = memo[AdvPageControl1->ActivePageIndex];
	AdvMemoFindDialog1->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N35Click(TObject *Sender)
{
	//производим поиск и замену из главного меню
	AdvMemoFindReplaceDialog1->AdvMemo = memo[AdvPageControl1->ActivePageIndex];
	AdvMemoFindReplaceDialog1->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N29Click(TObject *Sender)
{
	//печатаем из главного меню
	if (PrintDialog1->Execute()) {
		memo[AdvPageControl1->ActivePageIndex]->Print();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N31Click(TObject *Sender)
{
	//настройка принтера перед печатью
	if (PrinterSetupDialog1->Execute()) {
		memo[AdvPageControl1->ActivePageIndex]->Print();
	} 
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N36Click(TObject *Sender)
{
	//открываем файл для сравнения
	if (!OpenDialog1->Execute()) return;
	Form1->AdvMemo1->Lines->Clear();
	Form1->AdvMemo1->Lines->LoadFromFile(OpenDialog1->FileName);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N38Click(TObject *Sender)
{
	//поиск в сравнении скриптов
	Form1->AdvMemoFindDialog1->AdvMemo = Form1->AdvMemo1;
	Form1->AdvMemoFindDialog1->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N39Click(TObject *Sender)
{
	//открываем окно вставки ресурсов
	N39->Checked =!N39->Checked;
	CategoryPanelGroup1->Visible = N39->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N40Click(TObject *Sender)
{
	//открываем окно вставки ресурсов
	N40->Checked =!N40->Checked;
	CategoryPanelGroup2->Visible = N40->Checked;
	CategoryPanel4->Collapsed = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	tab = 0;
	//запускаем заставку
	Application->CreateForm(__classid(TForm2), &Form2);
	Form2->ShowModal();
	Form2->Free();
	//загружаем в макрос лист значения из файлов
	Form1->ListBox1->Items->LoadFromFile(ExtractFilePath(Application->ExeName)+"\\macros\\maclist.macsw");
	//загружаем в лист событий события из файла
	Form1->ListBox2->Items->LoadFromFile(ExtractFilePath(Application->ExeName)+"\\data\\conditions.sw");
	Form1->ListBox3->Items->LoadFromFile(ExtractFilePath(Application->ExeName)+"\\data\\events.sw");
	Form1->ListBox4->Items->LoadFromFile(ExtractFilePath(Application->ExeName)+"\\data\\function.sw");
	//Display leaks on shutdown if a debugger is present
	ReportMemoryLeaksOnShutdown = DebugHook > 0;
	//загружаем время для таймера автосохранения
	Timer1->Interval=Ini->ReadInteger("general","time",0);
	//проверяем значение атосохранения и делаем видим/не видимым опцию
	if (sav == 0) {
		N58->Visible = false;
	} else
		N58->Visible = true;
	//проверяем наличие флага активности отладчика
	if (debugs == 0) {
		N80->Visible = false;
	} else
		N80->Visible = true;
	//проверяем и запускаем автообновление
	if (autors == 1) {
		Form1->WebUpdateWizard1->AutoRun = true;
		Form1->WebUpdateWizard1->AutoStart = true;
		Form1->WebUpdateWizard1->Execute();
	}
	//задаем порт для автообновления
	port = Ini->ReadInteger("update", "port", 0);
	Form1->WebUpdate1->Port = port;
	//задаем параметры прокси
	usee = Ini->ReadInteger("update", "use", 0);
	if (usee == 1) {
		proxy = Ini->ReadInteger("update", "proxy", 0);
		Form1->WebUpdate1->Proxy = proxy;
		proxypass = Ini->ReadInteger("update", "proxypass", 0);
		Form1->WebUpdate1->ProxyPassword = proxypass;
		proxyuser = Ini->ReadInteger("update", "proxyuser", 0);
		Form1->WebUpdate1->ProxyUserID = proxyuser;
	}
	//загружаем значения макрорекордера
	if (mac1 == 1) {
		Form1->MacroRecorder1->RecordingRange = rrApplication;
	}
	if (mac2 == 1) {
		Form1->MacroRecorder1->PlaybackSpeed = pbFast;
	}
	if(mac3 == 1) {
		Form1->MacroRecorder1->RecordingRange = rrSystem;
	}
	if(mac4 == 1) {
		Form1->MacroRecorder1->PlaybackSpeed = pbFast;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N41Click(TObject *Sender)
{
	//открываем файл справки
	ShellExecute(Handle, "open", "help.chm", NULL, NULL, SW_RESTORE);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::goldencenturyorg1Click(TObject *Sender)
{
	//преходим на сайт
	ShellExecute(Handle, "open", "http://www.goldencentury.org", NULL, NULL, SW_RESTORE);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N43Click(TObject *Sender)
{
	//запускаем сведения о проге
	Application->CreateForm(__classid(TAboutBox), &AboutBox);
	AboutBox->ShowModal();
	AboutBox->Free();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::xml2Click(TObject *Sender)
{
	//creat file xml
	Form1->xml1->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::cfg2Click(TObject *Sender)
{
	//creat file cgf
	Form1->cfg1->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::xml1Click(TObject *Sender)
{
	//creat file xml to popup
	pts[TabCount] = new TAdvTabSheet(this);
	pts[TabCount]->AdvPageControl = AdvPageControl1;
	pts[TabCount]->Caption = "XML Script"+IntToStr(TabCount);
	pts[TabCount]->ImageIndex = 13;
	memo[TabCount] = new TAdvMemo(pts[TabCount]);
	memo[TabCount]->Parent = pts[TabCount];
	memo[TabCount]->Align = alClient;
	memo[TabCount]->SyntaxStyles = AdvXMLMemoStyler1;
	memo[TabCount]->Gutter->ShowLeadingZeros = true;
	memo[TabCount]->Gutter->ShowLineNumbers = true;
	memo[TabCount]->Gutter->GutterWidth = 60;
	memo[TabCount]->Gutter->GutterMargin = 45;
	memo[TabCount]->Gutter->ShowModified = true;
	memo[TabCount]->Gutter->ModifiedColor = clYellow;
	memo[TabCount]->Gutter->ModifiedColorBkg = clLime;
	memo[TabCount]->AutoIndent = true;
	memo[TabCount]->AcceptFiles = true;
	memo[TabCount]->MarkerList->MarkerImageList = ImageList3;
	memo[TabCount]->UndoLimit = 250;
	memo[TabCount]->WordWrap = wwClientWidth;
	memo[TabCount]->ActiveLineSettings->ActiveLineAtCursor = true;
	memo[TabCount]->ActiveLineSettings->ShowActiveLine = true;
	memo[TabCount]->ActiveLineSettings->ShowActiveLineIndicator = true;
	memo[TabCount]->ActiveLineSettings->ActiveLineColor = clSkyBlue;
	memo[TabCount]->AutoCompletion->Active = true;
	memo[TabCount]->AutoCompletion->AutoDisplay = true;
	memo[TabCount]->AutoCodeFold();
	memo[TabCount]->CodeFolding->Enabled = true;
	memo[TabCount]->AutoCorrect->Active = true;
	memo[TabCount]->AutoCorrect->OldValue->LoadFromFile(ExtractFilePath(Application->ExeName)+"\\Data\\old_correct.sw");
	memo[TabCount]->AutoCorrect->NewValue->LoadFromFile(ExtractFilePath(Application->ExeName)+"\\Data\\new_correct.sw");;
	memo[TabCount]->PopupMenu = PopupMenu2;
	memo[TabCount]->OnClick = MemoClick;
	memo[TabCount]->OnKeyPress = MemoKeyPress;
	Form1->StatusBar1->Panels->Items[2]->Text = "XML Script Color";
	memo[TabCount]->Clear();
	TabCount++;
	actbtn();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::cfg1Click(TObject *Sender)
{
	//creat file cgf  to popup
	pts[TabCount] = new TAdvTabSheet(this);
	pts[TabCount]->AdvPageControl = AdvPageControl1;
	pts[TabCount]->Caption = "CFG Script"+IntToStr(TabCount);
	pts[TabCount]->ImageIndex = 12;
	memo[TabCount] = new TAdvMemo(pts[TabCount]);
	memo[TabCount]->Parent = pts[TabCount];
	memo[TabCount]->Align = alClient;
	memo[TabCount]->SyntaxStyles = AdvINIMemoStyler1;
	memo[TabCount]->Gutter->ShowLeadingZeros = true;
	memo[TabCount]->Gutter->ShowLineNumbers = true;
	memo[TabCount]->Gutter->GutterWidth = 60;
	memo[TabCount]->Gutter->GutterMargin = 45;
	memo[TabCount]->Gutter->ShowModified = true;
	memo[TabCount]->Gutter->ModifiedColor = clYellow;
	memo[TabCount]->Gutter->ModifiedColorBkg = clLime;
	memo[TabCount]->AutoIndent = true;
	memo[TabCount]->AcceptFiles = true;
	memo[TabCount]->MarkerList->MarkerImageList = ImageList3;
	memo[TabCount]->UndoLimit = 250;
	memo[TabCount]->WordWrap = wwClientWidth;
	memo[TabCount]->ActiveLineSettings->ActiveLineAtCursor = true;
	memo[TabCount]->ActiveLineSettings->ShowActiveLine = true;
	memo[TabCount]->ActiveLineSettings->ShowActiveLineIndicator = true;
	memo[TabCount]->ActiveLineSettings->ActiveLineColor = clSkyBlue;
	memo[TabCount]->AutoCompletion->Active = true;
	memo[TabCount]->AutoCompletion->AutoDisplay = true;
	memo[TabCount]->AutoCodeFold();
	memo[TabCount]->CodeFolding->Enabled = true;
	memo[TabCount]->AutoCorrect->Active = true;
	memo[TabCount]->AutoCorrect->OldValue->LoadFromFile(ExtractFilePath(Application->ExeName)+"\\Data\\old_correct.sw");
	memo[TabCount]->AutoCorrect->NewValue->LoadFromFile(ExtractFilePath(Application->ExeName)+"\\Data\\new_correct.sw");;
	memo[TabCount]->PopupMenu = PopupMenu2;
	memo[TabCount]->OnClick = MemoClick;
	memo[TabCount]->OnKeyPress = MemoKeyPress;
	Form1->StatusBar1->Panels->Items[2]->Text = "CFG Script Color";
	memo[TabCount]->Clear();
	TabCount++;
	actbtn();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N3Click(TObject *Sender)
{
	//вырезаем из контекстного меню
	memo[AdvPageControl1->ActivePageIndex]->CutToClipBoard();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)
{
	//копируем из контекстного меню
	memo[AdvPageControl1->ActivePageIndex]->CopyToClipBoard();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N4Click(TObject *Sender)
{
	//вставляем из контекстного меню
	memo[AdvPageControl1->ActivePageIndex]->PasteFromClipBoard();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N5Click(TObject *Sender)
{
	//удаляем из контекстного меню
	memo[AdvPageControl1->ActivePageIndex]->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image40Click(TObject *Sender)
{
	//вставка Rome/BI
	if (RadioButton1->Checked) {
		Form1->memo[Form1->AdvPageControl1->ActivePageIndex]->InsertText("amber,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[Form1->AdvPageControl1->ActivePageIndex]->InsertText("resource       amber,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[Form1->AdvPageControl1->ActivePageIndex]->InsertText("amber");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image41Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("camels,");
	}
	if (RadioButton2->Checked) { 
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource       camels,");
	}
	if (RadioButton3->Checked) { 
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("camels");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image42Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("copper,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource       copper,");
	}
	if (RadioButton3->Checked) { 
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("copper");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image43Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("dogs,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource       dogs,");
	}
	if (RadioButton3->Checked) { 
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("dogs");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image44Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("elephants,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource       elephants,");
	}
	if (RadioButton3->Checked) { 
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("elephants");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image45Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("fur,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource       fur,");
	}
	if (RadioButton3->Checked) { 
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("fur");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image46Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("glass,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource       glass,");
	}
	if (RadioButton3->Checked) { 
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("glass");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image47Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("gold,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource       gold,");
	}
	if (RadioButton3->Checked) { 
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("gold");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image48Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("grain,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource       grain,");
	}
	if (RadioButton3->Checked) { 
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("grain");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image49Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("hides,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource       hides,");
	}
	if (RadioButton3->Checked) { 
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("hides");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image50Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("incense,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource       incense,");
	}
	if (RadioButton3->Checked) { 
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("incense");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image51Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("iron,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource       iron,");
	}
	if (RadioButton3->Checked) { 
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("iron");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image52Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("lead,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource       lead,");
	}
	if (RadioButton3->Checked) { 
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("lead");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image53Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("marble,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource       marble,");
	}
	if (RadioButton3->Checked) { 
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("marble");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image54Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("olive_oil,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource       olive_oil,");
	}
	if (RadioButton3->Checked) { 
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("olive_oil");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image55Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("pigs,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource       pigs,");
	}
	if (RadioButton3->Checked) { 
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("pigs");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image56Click(TObject *Sender)
{
	if(RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("pottery,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource       pottery,");
	}
	if (RadioButton3->Checked) { 
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("pottery");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image57Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("purple_dye,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource       purple_dye,");
	}
	if (RadioButton3->Checked) { 
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("purple_dye");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image58Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("silk,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource       silk,");
	}
	if (RadioButton3->Checked) { 
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("silk");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image59Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("silver,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource       silver,");
	}
	if (RadioButton3->Checked) { 
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("silver");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image60Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("slaves,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource       slaves,");
	}
	if (RadioButton3->Checked) { 
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("slaves");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image61Click(TObject *Sender)
{
	if(RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("textiles,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource       textiles,");
	}
	if (RadioButton3->Checked) { 
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("textiles");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image62Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("timber,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource       timber,");
	}
	if (RadioButton3->Checked) { 
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("timber");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image63Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("tin,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource       tin,");
	}
	if (RadioButton3->Checked) { 
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("tin");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image64Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("wild_animals,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource       wild_animals,");
	}
	if (RadioButton3->Checked) { 
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("wild_animals");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image65Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("wine,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource       wine,");
	}
	if (RadioButton3->Checked) { 
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("wine");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1Click(TObject *Sender)
{ 
	//вставка Medieval2
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("gold,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    gold,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("gold");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("silver,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    silver,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("silver");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image3Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("amber,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    amber,");
	}
	if (RadioButton3->Checked) { 
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("amber");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image4Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("cotton,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    cotton,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("cotton");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image5Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("furs,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    furs,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("furs");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image6Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("grain,"); 
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    grain,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("grain");
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::xml3Click(TObject *Sender)
{
	//меняем подсветку синтаксиса на XML Script Color
	Form1->memo[AdvPageControl1->ActivePageIndex]->SyntaxStyles = AdvXMLMemoStyler1;
	Form1->StatusBar1->Panels->Items[2]->Text = "XML Script Color";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::txt3Click(TObject *Sender)
{
	//меняем подсветку синтаксиса на  TW Script Color
	Form1->memo[AdvPageControl1->ActivePageIndex]->SyntaxStyles = AdvJSMemoStyler1;
	Form1->StatusBar1->Panels->Items[2]->Text = "TW Script Color";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N46Click(TObject *Sender)
{
	//отключаем подсветку
	Form1->memo[AdvPageControl1->ActivePageIndex]->SyntaxStyles->CleanupInstance();
	Form1->StatusBar1->Panels->Items[2]->Text = ms2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N52Click(TObject *Sender)
{  
	//о программе из трея
	Application->CreateForm(__classid(TAboutBox), &AboutBox);
	AboutBox->ShowModal();
	AboutBox->Free();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N48Click(TObject *Sender)
{
	//выходим из программы с трея
	Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N50Click(TObject *Sender)
{       
	//разворачиваем прогу из трея
	Form1->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N47Click(TObject *Sender)
{   
	//сворачиваем в трей
	Form1->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N53Click(TObject *Sender)
{
	//качаем обновление из трея
	ShellExecute(Handle, "open", "http://www.goldencentury.org/board/", NULL, NULL, SW_RESTORE);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image67Click(TObject *Sender)
{
	//вставка Medieval2 Kingdoms
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("hemp,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    hemp,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("hemp");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image66Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("honey,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    honey,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("honey");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image77Click(TObject *Sender)
{
	if(RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("amber,");
	}
	if(RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    amber,");
	}
	if(RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("amber");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image76Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("chocolate,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    chocolate,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("chocolate");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image75Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("coal,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    coal,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("coal");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image74Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("fur,");
	}
	if (RadioButton2->Checked) {
		orm1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    fur,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("fur");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image73Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("tar,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    tar,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("tar");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image71Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("wool,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    wool,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("wool");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image72Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("salt,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    salt,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("salt");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image68Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("grain,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    grain,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("grain");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image69Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("slaves,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    slaves,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("slaves");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image70Click(TObject *Sender)
{
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("tobacco,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    tobacco,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("tobacco");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N54Click(TObject *Sender)
{
	//открываем окно вставки комментариев
	N54->Checked =! N54->Checked;
	CategoryPanelGroup2->Visible = N54->Checked;
	CategoryPanel6->Collapsed = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
	//запускаем макрос
	for (int i = 0; i < ListBox1->Items->Count; i++)
		if (ListBox1->Selected[i])
			MacroRecorder1->FileName = ExtractFilePath(Application->ExeName)+"macros/"+Form1->ListBox1->Items->Strings[i];
			MacroRecorder1->PlayMacro();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{   
	//пишем макрос
	MacroRecorder1->FileName = ExtractFilePath(Application->ExeName)+"macros/"+Form1->Edit1->Text+".mac";
	MacroRecorder1->RecordMacro();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{  
	//останавливаем макрос
	MacroRecorder1->StopRecording();
	Form1->ListBox1->Items->Add(Form1->Edit1->Text+".mac");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N55Click(TObject *Sender)
{ 
	//запускаем макросы
	N55->Checked =!N55->Checked;
	CategoryPanelGroup2->Visible = N55->Checked;
	CategoryPanel7->Collapsed = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Change(TObject *Sender)
{
	Edit1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N57Click(TObject *Sender)
{
	WebUpdateWizard1->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SDTXT1Click(TObject *Sender)
{
	//запускаем форму конвертера из sd
   if (HINSTANCE DLLInstance = LoadLibrary("sd.dll")) {
	   typedef TForm* (__cdecl* TCreateMyForm)(TForm*);
		if ( TCreateMyForm CreateMyForm = (TCreateMyForm)GetProcAddress(DLLInstance,"_CreateMyForm")) {
			TForm* form = CreateMyForm(this); 
			form->Show();
		}
	} else 
		ShowMessage(ms3);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AdvTabSet1Change(TObject *Sender, int NewTab, bool &AllowChange)
{  
	//переключаемся между логом и ошибками
	switch (AdvTabSet1->TabIndex) {
		case 1:  
			RichEdit2->Lines->Clear();
		break;
		case 0:
			RichEdit2->Lines->Clear();
			RichEdit2->Lines->LoadFromFile(Options->Edit1->Text+"system.log.txt");
		break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N62Click(TObject *Sender)
{
	//открываем панель отладки
	N62->Checked =!N62->Checked;
	Panel1->Visible = N62->Checked;
	//RichEdit2->Lines->LoadFromFile(Options->Edit1->Text+"system.log.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton4Click(TObject *Sender)
{ 
	//вставляем комментарий для текстовых скриптов
	Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText(" ; ");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton5Click(TObject *Sender)
{
	//вставляем комментарий для xml скриптов
	Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("<!-- --> ");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AdvCodeList1DragOver(TObject *Sender, TObject *Source, int X,
          int Y, TDragState State, bool &Accept)
{ 
	//code list  Accept := (source is TAdvMemo);
	Accept = (memo[AdvPageControl1->ActivePageIndex]);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AdvCodeList1DragDrop(TObject *Sender, TObject *Source, int X, int Y)
{
	//code list
	AdvCodeList1->CodeBlocks->Add(memo[AdvPageControl1->ActivePageIndex]->Selection);
	/*AdvCodeList1->CodeBlocks[AdvCodeList1->CodeBlocks->Count - 1]->ImageIndex := 0;
	  AdvCodeList1.CodeBlocks[AdvCodeList1.CodeBlocks.Count - 1].ImageIndex := 0;
	*/
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AdvCodeList1BlockRightClick(TObject *Sender, TCodeBlock *ACodeBlock)
{ 
	//просмотр содержимого блока
	ShowMessage(ACodeBlock->Code->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AdvCodeList1BlockInsertFromClipboard(TObject *Sender, TCodeBlock *ACodeBlock)
{
	// set image as clipboard icon
	ACodeBlock->ImageIndex = 4;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ApplicationEvents1Exception(TObject *Sender, Exception *E)
{
	//перехват сообщений об ошибках
	ShowMessage(ms1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N65Click(TObject *Sender)
{
	//открываем окно вставки комментариев
	N65->Checked =!N65->Checked;
	CategoryPanelGroup2->Visible = N65->Checked;
	CategoryPanel8->Collapsed = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N66Click(TObject *Sender)
{ 
	//автоподстановка(проба)
	N66->Checked =!N66->Checked;
	ListBox5->Visible = N66->Checked;
	ListBox5->Items->LoadFromFile(ExtractFilePath(Application->ExeName)+"\\Data\\function.sw");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N67Click(TObject *Sender)
{
	//открываем файл из главного меню
	if (!OpenTextFileDialog1->Execute()) return;
	   pts[TabCount] = new TAdvTabSheet(this);
	   pts[TabCount]->AdvPageControl = AdvPageControl1;
	   pts[TabCount]->Caption = ExtractFileName(OpenTextFileDialog1->FileName);
	   pts[TabCount]->ImageIndex = 10;
	   memo[TabCount] = new TAdvMemo(pts[TabCount]);
	   memo[TabCount]->Parent = pts[TabCount];
	   memo[TabCount]->Align = alClient;
	   memo[TabCount]->Clear();
	   memo[TabCount]->Gutter->ShowLeadingZeros = true;
	   memo[TabCount]->WordWrap = wwRightMargin;
	   memo[TabCount]->ActiveLineSettings->ActiveLineAtCursor = true;
	   memo[TabCount]->ActiveLineSettings->ShowActiveLine = true;
	   memo[TabCount]->ActiveLineSettings->ShowActiveLineIndicator = true;
	   memo[TabCount]->ActiveLineSettings->ActiveLineColor = clSkyBlue;
	   memo[TabCount]->CodeFolding->Enabled = true;
	   memo[TabCount]->AutoCodeFold();
	   memo[TabCount]->Gutter->ShowModified = true;
	   memo[TabCount]->AutoCorrect->Active = true;
	   memo[TabCount]->AutoCorrect->OldValue->LoadFromFile(ExtractFilePath(Application->ExeName)+"\\Data\\old_correct.sw");
	   memo[TabCount]->AutoCorrect->NewValue->LoadFromFile(ExtractFilePath(Application->ExeName)+"\\Data\\new_correct.sw");
	   memo[TabCount]->AutoCompletion->Active = true;
	   memo[TabCount]->PopupMenu = PopupMenu2;
	   memo[TabCount]->Lines->LoadFromFile(OpenTextFileDialog1->FileName);
	   memo[TabCount]->OnClick = MemoClick;
	   memo[TabCount]->OnKeyPress = MemoKeyPress;
	   StatusBar1->Panels->Items[0]->Text = OpenDialog1->FileName;
	   TabCount++;
	   actbtn();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N69Click(TObject *Sender)
{
	//пытаемся сохранить неизвестный файл
	if ( AdvPageControl1->ActivePage != NULL) {
		for (int i = 0; i < AdvPageControl1->ActivePage->ComponentCount; i++) {
			if (String(AdvPageControl1->ActivePage->Components[i]->ClassName()) == "TAdvMemo") {
				if (SaveTextFileDialog1->Execute()) {
					TAdvMemo *memo = (TAdvMemo *)AdvPageControl1->ActivePage->Components[i];
					memo->Lines->SaveToFile(SaveTextFileDialog1->FileName);
					break;
				}  
			} 
		} 
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N70Click(TObject *Sender)
{
	//запускаем форму перехода к нужной строке
	Application->CreateForm(__classid(TForm3), &Form3);
	Form3->ShowModal();
	Form3->Free();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{	
	//при закрытии формы сохраняем значения листа макросов в файл
	Form1->ListBox1->Items->SaveToFile(ExtractFilePath(Application->ExeName)+"\\macros\\maclist.macsw");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListBox1DblClick(TObject *Sender)
{
	//запускаем выбранный макрос по двойному щелчку в списке
	for (int i = 0; i < ListBox1->Items->Count; i++)
		if (ListBox1->Selected[i])
			MacroRecorder1->FileName = "macros/"+Form1->ListBox1->Items->Strings[i];
			MacroRecorder1->PlayMacro();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N60Click(TObject *Sender)
{
	//запускаем менеджер создания проекта
	Application->CreateForm(__classid(TForm4), &Form4);
	Form4->ShowModal();
	Form4->Free();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N72Click(TObject *Sender)
{
	//запускаем настройки программы
	Options->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::lua1Click(TObject *Sender)
{
	//создаем новый файл формата *.lua
	pts[TabCount] = new TAdvTabSheet(this);
	pts[TabCount]->AdvPageControl = AdvPageControl1;
	pts[TabCount]->Caption = "Lua Script"+IntToStr(TabCount);
	pts[TabCount]->ImageIndex = 11;
	memo[TabCount] = new TAdvMemo(pts[TabCount]);
	memo[TabCount]->Parent = pts[TabCount];
	memo[TabCount]->Align = alClient;
	memo[TabCount]->SyntaxStyles = AdvPascalMemoStyler1;
	memo[TabCount]->Gutter->ShowLeadingZeros = true;
	memo[TabCount]->Gutter->ShowLineNumbers = true;
	memo[TabCount]->Gutter->GutterWidth = 60;
	memo[TabCount]->Gutter->GutterMargin = 45;
	memo[TabCount]->Gutter->ShowModified = true;
	memo[TabCount]->Gutter->ModifiedColor = clYellow;
	memo[TabCount]->Gutter->ModifiedColorBkg = clLime;
	memo[TabCount]->AutoIndent = true;
	memo[TabCount]->AcceptFiles = true;
	memo[TabCount]->MarkerList->MarkerImageList = ImageList3;
	memo[TabCount]->UndoLimit = 250;
	memo[TabCount]->WordWrap = wwClientWidth;
	memo[TabCount]->ActiveLineSettings->ActiveLineAtCursor = true;
	memo[TabCount]->ActiveLineSettings->ShowActiveLine = true;
	memo[TabCount]->ActiveLineSettings->ShowActiveLineIndicator = true;
	memo[TabCount]->ActiveLineSettings->ActiveLineColor = clSkyBlue;
	memo[TabCount]->AutoCompletion->Active = true;
	memo[TabCount]->AutoCompletion->AutoDisplay = true;
	memo[TabCount]->AutoCodeFold();
	memo[TabCount]->CodeFolding->Enabled = true;
	memo[TabCount]->AutoCorrect->Active = true;
	memo[TabCount]->AutoCorrect->OldValue->LoadFromFile(ExtractFilePath(Application->ExeName)+"\\Data\\old_correct.sw");
	memo[TabCount]->AutoCorrect->NewValue->LoadFromFile(ExtractFilePath(Application->ExeName)+"\\Data\\new_correct.sw");;
	memo[TabCount]->PopupMenu = PopupMenu2;
	memo[TabCount]->OnClick = MemoClick;
	memo[TabCount]->OnKeyPress = MemoKeyPress;
	Form1->StatusBar1->Panels->Items[2]->Text = "Lua Script Color";
	memo[TabCount]->Clear();
	TabCount++;
	actbtn();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::lua2Click(TObject *Sender)
{
	//создаем новый файл формата *.lua
	Form1->lua1->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::lua3Click(TObject *Sender)
{
	//меняем подсветку синтаксиса на  Lua Script Color
	Form1->memo[AdvPageControl1->ActivePageIndex]->SyntaxStyles = AdvPascalMemoStyler1;
	Form1->StatusBar1->Panels->Items[2]->Text = "Lua Script Color";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MemoClick(TObject *Sender)
{ 
	//отображаем номер строки и символа в строке состояния
	Form1->StatusBar1->Panels->Items[3]->Text = memo[AdvPageControl1->ActivePageIndex]->SelStart;
	Form1->StatusBar1->Panels->Items[3]->Text = memo[AdvPageControl1->ActivePageIndex]->CurX+1;
	Form1->StatusBar1->Panels->Items[4]->Text = memo[AdvPageControl1->ActivePageIndex]->SelStart;
	Form1->StatusBar1->Panels->Items[4]->Text = memo[AdvPageControl1->ActivePageIndex]->CurY+1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MemoKeyPress(TObject *Sender, wchar_t &Key)
{ 
	//отображаем номер строки и символа в строке состояния
	Form1->StatusBar1->Panels->Items[3]->Text = memo[AdvPageControl1->ActivePageIndex]->SelStart;
	Form1->StatusBar1->Panels->Items[3]->Text = memo[AdvPageControl1->ActivePageIndex]->CurX+1;
	Form1->StatusBar1->Panels->Items[4]->Text = memo[AdvPageControl1->ActivePageIndex]->SelStart;
	Form1->StatusBar1->Panels->Items[4]->Text = memo[AdvPageControl1->ActivePageIndex]->CurY+1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListBox4DblClick(TObject *Sender)
{
	//выполняем вставку выбранного значения в текст
	for (int i = 0; i < ListBox4->Items->Count; i++)
		if (ListBox4->Selected[i])
			Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText(Form1->ListBox4->Items->Strings[i]);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListBox5DblClick(TObject *Sender)
{
	//Вставляем выбранное значение в текстовую область
	for (int i = 0; i < ListBox5->Items->Count; i++)
		if (ListBox5->Selected[i])
			Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText(Form1->ListBox5->Items->Strings[i]);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListBox3DblClick(TObject *Sender)
{ 
	//Вставляем выбранное значение в текстовую область
	for (int i = 0; i < ListBox3->Items->Count; i++)
		if (ListBox3->Selected[i])
			Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText(Form1->ListBox3->Items->Strings[i]);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListBox2DblClick(TObject *Sender)
{
	//Вставляем выбранное значение в текстовую область
	for (int i = 0; i < ListBox2->Items->Count; i++)
		if (ListBox2->Selected[i])
			Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText(Form1->ListBox2->Items->Strings[i]);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{ 
	//проверяем перед сохранением вкладки
	CanClose = true;
	for (int i = 0; i < AdvPageControl1->PageCount; ++i) {
		if (memo[i]->Modified) {
			int code = MessageBox(Handle,(AnsiString(ms9) + AdvPageControl1->Pages[i]->Caption+String(" ?")).c_str(),"", MB_ICONQUESTION | MB_YESNOCANCEL);
			if (code == IDCANCEL) {
				CanClose = false;
				break;
			}
			if (code == IDYES) {
				N14Click(Sender);
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image14Click(TObject *Sender)
{   
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("sugar,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    sugar,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("sugar");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image15Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("slaves,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    slaves,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("slaves");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image16Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("silk,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    silk,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("silk");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image17Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("iron,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    iron,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("iron");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image18Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("dyes,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    dyes,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("dyes");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image27Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("dogs,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    dogs,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("dogs");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image28Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("elephants,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    elephants,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("elephants");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image29Click(TObject *Sender)
{	
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("glass,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    glass,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("glass");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image30Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("hides,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    hides,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("hides");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image31Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("lead,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    lead,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("lead");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image20Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("timber,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    timber,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("timber");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image34Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("pottery,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    pottery,");
	}
    if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("pottery");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image10Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("chocolate,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    chocolate,");
	}
    if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("chocolate");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image12Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("wine,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    wine,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("wine");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image13Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("sulfur,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    sulfur,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("sulfur");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image26Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("copper,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    copper,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("copper");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image37Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("water,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    water,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("water");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image23Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("fish,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    fish,");
	}
    if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("fish");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image33Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("pigs,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    pigs,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("pigs");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image19Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("textiles,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    textiles,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("textiles");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image39Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("incense,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    incense,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("incense");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image24Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("tin,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    tin,");
	}
    if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("tin");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image35Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("purple_dye,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    purple_dye,");
	}
    if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("purple_dye");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image32Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("olive_oil,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    olive_oil,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("olive_oil");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image7Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("marble,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    marble,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("marble");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image21Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("coal,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    coal,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("coal");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image22Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("spices,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    spices,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("spices");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image11Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("wool,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    wool,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("wool");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image38Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("wild_animals,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    wild_animals,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("wild_animals");}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image25Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("camels,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    camels,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("camels");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image36Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("goods,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    goods,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("goods");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image9Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("tobacco,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    tobacco,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("tobacco");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image8Click(TObject *Sender)
{
	//вставка ресурсов меди
	if (RadioButton1->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("ivory,");
	}
	if (RadioButton2->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("resource    ivory,");
	}
	if (RadioButton3->Checked) {
		Form1->memo[AdvPageControl1->ActivePageIndex]->InsertText("ivory");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label1Click(TObject *Sender)
{
	//паказываем спраку по параметрам встаки
	ShowMessage(ms4);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AdvPageControl1Change(TObject *Sender)
{
	//отображаем в статус баре текущей путь к файлу
	StatusBar1->Panels->Items[0]->Text = OpenDialog1->FileName;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N111Click(TObject *Sender)
{
	//устанавливаем маркер
	memo[AdvPageControl1->ActivePageIndex]->SelStart;
	memo[AdvPageControl1->ActivePageIndex]->AddMarker(memo[AdvPageControl1->ActivePageIndex]->CurY, 3, 1);
	N111->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N110Click(TObject *Sender)
{
	//переходим к 1 маркеру
	memo[AdvPageControl1->ActivePageIndex]->GoToMarkerName(1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N210Click(TObject *Sender)
{
	memo[AdvPageControl1->ActivePageIndex]->GoToMarkerName(2);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N310Click(TObject *Sender)
{
	memo[AdvPageControl1->ActivePageIndex]->GoToMarkerName(3);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N410Click(TObject *Sender)
{
	memo[AdvPageControl1->ActivePageIndex]->GoToMarkerName(4);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N510Click(TObject *Sender)
{
	memo[AdvPageControl1->ActivePageIndex]->GoToMarkerName(5);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N610Click(TObject *Sender)
{
	memo[AdvPageControl1->ActivePageIndex]->GoToMarkerName(6);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N77Click(TObject *Sender)
{
	memo[AdvPageControl1->ActivePageIndex]->GoToMarkerName(7);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N81Click(TObject *Sender)
{
	memo[AdvPageControl1->ActivePageIndex]->GoToMarkerName(8);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N91Click(TObject *Sender)
{
	memo[AdvPageControl1->ActivePageIndex]->GoToMarkerName(9);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N101Click(TObject *Sender)
{
	memo[AdvPageControl1->ActivePageIndex]->GoToMarkerName(10);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N211Click(TObject *Sender)
{
	//устанавливаем маркер
	memo[AdvPageControl1->ActivePageIndex]->SelStart;
	memo[AdvPageControl1->ActivePageIndex]->AddMarker(memo[AdvPageControl1->ActivePageIndex]->CurY, 3, 2);
	N211->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N311Click(TObject *Sender)
{
	//устанавливаем маркер
	memo[AdvPageControl1->ActivePageIndex]->SelStart;
	memo[AdvPageControl1->ActivePageIndex]->AddMarker(memo[AdvPageControl1->ActivePageIndex]->CurY, 3, 3);
	N311->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N411Click(TObject *Sender)
{
	//устанавливаем маркер
	memo[AdvPageControl1->ActivePageIndex]->SelStart;
	memo[AdvPageControl1->ActivePageIndex]->AddMarker(memo[AdvPageControl1->ActivePageIndex]->CurY, 3, 4);
	N411->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N511Click(TObject *Sender)
{
	//устанавливаем маркер
	memo[AdvPageControl1->ActivePageIndex]->SelStart;
	memo[AdvPageControl1->ActivePageIndex]->AddMarker(memo[AdvPageControl1->ActivePageIndex]->CurY, 3, 5);
	N511->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N611Click(TObject *Sender)
{
	//устанавливаем маркер
	memo[AdvPageControl1->ActivePageIndex]->SelStart;
	memo[AdvPageControl1->ActivePageIndex]->AddMarker(memo[AdvPageControl1->ActivePageIndex]->CurY, 3, 6);
	N611->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N78Click(TObject *Sender)
{
	//устанавливаем маркер
	memo[AdvPageControl1->ActivePageIndex]->SelStart;
	memo[AdvPageControl1->ActivePageIndex]->AddMarker(memo[AdvPageControl1->ActivePageIndex]->CurY, 3, 7);
	N78->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N82Click(TObject *Sender)
{
	//устанавливаем маркер
	memo[AdvPageControl1->ActivePageIndex]->SelStart;
	memo[AdvPageControl1->ActivePageIndex]->AddMarker(memo[AdvPageControl1->ActivePageIndex]->CurY, 3, 8);
	N82->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N92Click(TObject *Sender)
{
	//устанавливаем маркер
	memo[AdvPageControl1->ActivePageIndex]->SelStart;
	memo[AdvPageControl1->ActivePageIndex]->AddMarker(memo[AdvPageControl1->ActivePageIndex]->CurY, 3, 9);
	N92->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N102Click(TObject *Sender)
{
	//устанавливаем маркер
	memo[AdvPageControl1->ActivePageIndex]->SelStart;
	memo[AdvPageControl1->ActivePageIndex]->AddMarker(memo[AdvPageControl1->ActivePageIndex]->CurY, 3, 10);
	N102->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::cfg3Click(TObject *Sender)
{
	//меняем подсветку синтаксиса на XML Script Color
	Form1->memo[AdvPageControl1->ActivePageIndex]->SyntaxStyles = AdvINIMemoStyler1;
	Form1->StatusBar1->Panels->Items[2]->Text = "Config Script Color";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N58Click(TObject *Sender)
{
	//запускаем таймер автосохранения
	N58->Checked =!N58->Checked;
	Timer1->Enabled = N58->Checked;
	if (Timer1->Enabled) {
		ShowMessage(ms5);
	} else 
		ShowMessage(ms6);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	//автоматическое сохранение
	if (AdvPageControl1->ActivePage != NULL) {
		for (int i = 0; i < AdvPageControl1->ActivePage->ComponentCount; i++) {
			if (String(AdvPageControl1->ActivePage->Components[i]->ClassName()) == "TAdvMemo") {
				TAdvMemo *memo = (TAdvMemo *)AdvPageControl1->ActivePage->Components[i];
				memo->Lines->SaveToFile(SaveDialog1->FileName);
				ShowMessage(ms7);
				break;
			}  
		}  
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N80Click(TObject *Sender)
{
	//делаем видимой панель отладчика
	N80->Checked =!N80->Checked;
	CategoryPanelGroup2->Visible = N80->Checked;
	CategoryPanel9->Collapsed = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N83Click(TObject *Sender)
{
	//делаем видимой/убираем стандартную панель
	N83->Checked =!N83->Checked;
	Form1->ToolBar1->Visible = N83->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N73Click(TObject *Sender)
{
	//запускаем игру
	if (game1 == 1) {
		//WinExec( "tools//unpacker//unpacker.exe --source=..\\..\\packs\\data_0.pack --destination=..\\..\\ --verbosity=1", SW_HIDE );
		WinExec("Options->Edit1->Text+kingdoms.exe", SW_HIDE);
	}
	if (game2 == 1) {
		WinExec("Options->Edit1->Text+medieval2.exe", SW_HIDE);
	}
	if (mod1 == 1) {
		WinExec("Options->Edit1->Text+kingdoms.exe --features.mod=mods//", SW_HIDE);
	}
	if (mod2 == 1) {
		WinExec("Options->Edit1->Text+medieval2.exe --features.mod=mods//", SW_HIDE);
	} else
		ShowMessage(ms8);
}
//---------------------------------------------------------------------------

void TForm1::actbtn(void)
{
	//функция отображения кнопок
	Form1->N14->Enabled = true;
	Form1->N18->Enabled = true;
	Form1->N19->Enabled = true;
	Form1->N22->Enabled = true;
	Form1->N23->Enabled = true;
	Form1->N24->Enabled = true;
	Form1->N25->Enabled = true;
	Form1->N27->Enabled = true;
	Form1->N28->Enabled = true;
	Form1->N29->Enabled = true;
	Form1->N34->Enabled = true;
	Form1->N35->Enabled = true;
	Form1->N39->Enabled = true;
	Form1->N46->Enabled = true;
	Form1->N54->Enabled = true;
	Form1->N65->Enabled = true;
	Form1->N66->Enabled = true;
	Form1->N70->Enabled = true;
	Form1->xml3->Enabled = true;
	Form1->txt3->Enabled = true;
	Form1->cfg3->Enabled = true;
	Form1->ToolButton3->Enabled = true;
	Form1->ToolButton5->Enabled = true;
	Form1->ToolButton6->Enabled = true;
	Form1->ToolButton7->Enabled = true;
	Form1->ToolButton8->Enabled = true;
	Form1->ToolButton10->Enabled = true;
	Form1->ToolButton11->Enabled = true;
	Form1->ToolButton13->Enabled = true;
	Form1->ToolButton14->Enabled = true;
}

//функция скрытия кнопок
void TForm1::noactbtn(void)
{
	Form1->N14->Enabled = false;
	Form1->N18->Enabled = false;
	Form1->N19->Enabled = false;
	Form1->N22->Enabled = false;
	Form1->N23->Enabled = false;
	Form1->N24->Enabled = false;
	Form1->N25->Enabled = false;
	Form1->N27->Enabled = false;
	Form1->N28->Enabled = false;
	Form1->N29->Enabled = false;
	Form1->N34->Enabled = false;
	Form1->N35->Enabled = false;
	Form1->N39->Enabled = false;
	Form1->N46->Enabled = false;
	Form1->N54->Enabled = false;
	Form1->N65->Enabled = false;
	Form1->N66->Enabled = false;
	Form1->N70->Enabled = false;
	Form1->xml3->Enabled = false;
	Form1->txt3->Enabled = false;
	Form1->cfg3->Enabled = false;
	Form1->ToolButton3->Enabled = false;
	Form1->ToolButton5->Enabled = false;
	Form1->ToolButton6->Enabled = false;
	Form1->ToolButton7->Enabled = false;
	Form1->ToolButton8->Enabled = false;
	Form1->ToolButton10->Enabled = false;
	Form1->ToolButton11->Enabled = false;
	Form1->ToolButton13->Enabled = false;
	Form1->ToolButton14->Enabled = false;
}

void __fastcall TForm1::N63Click(TObject *Sender)
{
	//пытаемся удалить маркеры
	memo[AdvPageControl1->ActivePageIndex]->ClearAllMarkers();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Unpacker1Click(TObject *Sender)
{
	//запускаем форму конвертера из dll
	if (HINSTANCE DLLInstance = LoadLibrary("plugin\\VISUAL.dll")) {
		typedef TForm* (__cdecl* TCreateMyForm)(TForm*);
		if (TCreateMyForm CreateMyForm = (TCreateMyForm)GetProcAddress(DLLInstance,"_CreateMyForm")) {
			TForm* form = CreateMyForm(this); 
			form->Show();
		}
	} else 
		ShowMessage(ms3);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton6Click(TObject *Sender)
{
	if (CheckBox1->Checked) {
		error();
	} else
		//проверяем текст скрипта
		debug_string();
}
//---------------------------------------------------------------------------

//функция проверки скобок в скрипте
void TForm1::debug_string(void)
{
	int k; //кол-во открытых скобок
	int l; //кол-во закрытых скобок
	int i,n;
	AnsiString st = memo[AdvPageControl1->ActivePageIndex]->Lines->Text;

	for (k = 0, l = 0, i = 1, n = st.Length(); i <= n; i++) {
		if (st[i] == '{') k++;
		if (st[i] == '}') l++;
	}
	if (k == l)
		RichEdit2->Lines->Add("Проблем со скобками не выявленно! \n");
	else
		if (k > l)
			RichEdit2->Lines->Add("Возникла ошибка! Не хватает закрытых скобок. \n");
		else
			RichEdit2->Lines->Add("Возникла ошибка! Не хватает открытых скобок. \n");
}

void __fastcall TForm1::Edit2Change(TObject *Sender)
{
	//поиск в  листбоксе
	fidlistbox();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	//поиск в  листбоксе
	fidlistbox();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2Enter(TObject *Sender)
{
	//поиск в  листбоксе
	fidlistbox();
}
//---------------------------------------------------------------------------

//функция поиска в листбоксе
void TForm1::fidlistbox(void)
{
	for (int k = 0; k < ListBox2->Count; k++) {
		if (ListBox2->Items->Strings[k].Pos(Edit2->Text) > 0) {
			ListBox2->ItemIndex = k;
			break;
		}
	}
}

//функция проверки на наличие ошибок в скрипте
void TForm1::win1251(void)
{
	if (memo[AdvPageControl1->ActivePageIndex]->Lines->Text.Length() == 0)
		RichEdit2->Lines->Add("Внимание! Поле пустое. \n");
	else {
		int k = 0;
		for (int i = 1; i <= memo[AdvPageControl1->ActivePageIndex]->Lines->Text.Length(); i++)
			if (memo[AdvPageControl1->ActivePageIndex]->Lines->Text[i] == memo[AdvPageControl1->ActivePageIndex]->Lines->Text[1])
				k = k + 1;

		Form1->Label2->Visible= true;
		RichEdit2->Lines->Add("Количество символов =" + IntToStr(k)+"\n");
	}
}

//функция доступа к библиотеки error.dll
void TForm1::error(void)
{
	if (FileExists(ExtractFilePath(Application->ExeName)+"\\Data\\error.dll") == false) {
		ShowMessage("Не найдена библиотека ошибок");
	}
}