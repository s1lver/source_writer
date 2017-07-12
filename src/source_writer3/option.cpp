//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "option.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvPageControl"
#pragma link "rtflabel"
#pragma link "Spin"
#pragma resource "*.dfm"
TOptions *Options;
//переменная значений языка
AnsiString lng2;
//переменная имя макроса
AnsiString FileName;
//переменная пользовательского языка
AnsiString usrlng;

//---------------------------------------------------------------------------
__fastcall TOptions::TOptions(TComponent* Owner)
	: TForm(Owner)
{
	//загружаем значения опции
	Ini = new TIniFile(ExtractFilePath(Application->ExeName)+"\\Data\\config.ini");
	Options->RadioButton1->Checked = Ini->ReadBool("Macros","Norm",0);
	Options->RadioButton2->Checked = Ini->ReadBool("Macros","Fast",0);
	Options->RadioButton3->Checked = Ini->ReadBool("Macros","Sys",0);
	Options->RadioButton4->Checked = Ini->ReadBool("Macros","App",0);
	Options->CheckBox4->Checked = Ini->ReadBool("Other","Close",0);
	Options->CheckBox1->Checked = Ini->ReadBool("Other","Default",0);
	Options->Edit1->Text = Ini->ReadString("Game","Lok1","");
	Options->RadioButton8->Checked = Ini->ReadBool("Game","game1",0);
	Options->RadioButton9->Checked = Ini->ReadBool("Game","game2",0);
	Options->RadioButton10->Checked = Ini->ReadBool("Game","mod1",0);
	Options->RadioButton11->Checked = Ini->ReadBool("Game","mod2",0);
	//значения языков
	Options->RadioButton5->Checked = Ini->ReadBool("Lang","ru",0);
	Options->RadioButton6->Checked = Ini->ReadBool("Lang","ua",0);
	Options->RadioButton7->Checked = Ini->ReadBool("Lang","gb",0);
	Options->CheckBox18->Checked = Ini->ReadBool("Lang","user",0);
	//общие значения
	Options->CheckBox5->Checked = Ini->ReadBool("general","save",0);
	Options->Edit2->Text = Ini->ReadString("general","time","");
	//значения автообновления
	Options->CheckBox14->Checked = Ini->ReadBool("update","log",0);
	Options->Edit3->Text = Ini->ReadString("update","port",0);
	Options->CheckBox15->Checked = Ini->ReadBool("update","start",0);
	Options->CheckBox16->Checked = Ini->ReadBool("update","run",0);
	Options->CheckBox17->Checked = Ini->ReadBool("update","auto",0);
	Options->CheckBox19->Checked = Ini->ReadBool("update","use",0);
	Options->Edit4->Text = Ini->ReadString("update","proxy","");
	Options->Edit5->Text = Ini->ReadString("update","proxyuser","");
	Options->Edit6->Text = Ini->ReadString("update","proxypass","");
	//delete Ini;
	//языковая функция формы
}
//---------------------------------------------------------------------------
void __fastcall TOptions::FormCreate(TObject *Sender)
{
	//плавно разворачиваем при открытии
	TRect r1,r2;
	r1 = Rect(Left+Width/2,Top+Height/2,Left+Width/2,Top+Height/2);
	r2 = BoundsRect;
	DrawAnimatedRects(Handle,IDANI_CAPTION,&r1,&r2);
	//загружаем в макрос лист значения из файлов
	Options->ListBox1->Items->LoadFromFile(ExtractFilePath(Application->ExeName)+"\\macros\\maclist.macsw");
	lng2=Ini->ReadString("lngflag","active","");
	if (lng2 == "gb") {
		Inilng = new TIniFile(ExtractFilePath(Application->ExeName)+"\\Data\\eng.lng");
	}
	if (lng2 == "ua") {
		Inilng = new TIniFile(ExtractFilePath(Application->ExeName)+"\\Data\\ua.lng");
	}
	if (lng2 == "ru") {
		Inilng = new TIniFile(ExtractFilePath(Application->ExeName)+"\\Data\\rus.lng");
	}
	Options->Caption = Inilng->ReadString("form","opt1","");
	Options->CheckBox1->Caption = Inilng->ReadString("form","opt2","");
	Options->CheckBox4->Caption = Inilng->ReadString("form","opt3","");
	Options->BitBtn1->Caption=Inilng->ReadString("form","opt4","");
	Options->BitBtn2->Caption = Inilng->ReadString("form","opt5","");
	//макросы
	Options->GroupBox1->Caption = Inilng->ReadString("form","opt6","");
	Options->GroupBox2->Caption = Inilng->ReadString("form","opt7","");
	Options->GroupBox3->Caption = Inilng->ReadString("form","opt8","");
	Options->GroupBox4->Caption = Inilng->ReadString("form","opt9","");
	Options->RadioButton3->Caption = Inilng->ReadString("form","opt10","");
	Options->RadioButton4->Caption = Inilng->ReadString("form","opt11","");
	Options->RadioButton1->Caption = Inilng->ReadString("form","opt12","");
	Options->RadioButton2->Caption = Inilng->ReadString("form","opt13","");
	Options->CheckBox2->Caption = Inilng->ReadString("form","opt14","");
	Options->CheckBox3->Caption = Inilng->ReadString("form","opt15","");
	Options->CheckBox13->Caption = Inilng->ReadString("form","opt38","");
	//игра
	Options->GroupBox5->Caption = Inilng->ReadString("form","opt16","");
	Options->GroupBox12->Caption = Inilng->ReadString("form","opt23","");
	//заголовки
	Options->AdvTabSheet1->Caption = Inilng->ReadString("form","opt17","");
	Options->AdvTabSheet2->Caption = Inilng->ReadString("form","opt18","");
	Options->AdvTabSheet3->Caption = Inilng->ReadString("form","opt19","");
	Options->AdvTabSheet4->Caption = Inilng->ReadString("form","opt20","");
	Options->Отладчик->Caption = Inilng->ReadString("form","opt21","");
	Options->AdvTabSheet5->Caption = Inilng->ReadString("form","opt22","");
	//языки
	Options->GroupBox6->Caption = Inilng->ReadString("form","opt24","");
	Options->RadioButton5->Caption = Inilng->ReadString("form","opt25","");
	Options->RadioButton6->Caption = Inilng->ReadString("form","opt26","");
	Options->RadioButton7->Caption = Inilng->ReadString("form","opt27","");
	Options->CheckBox18->Caption = Inilng->ReadString("form","opt28","");
	Options->Label1->Caption = Inilng->ReadString("form","opt29","");
	Options->GroupBox7->Caption = Inilng->ReadString("form","opt28","");
	//общие
	Options->GroupBox8->Caption = Inilng->ReadString("form","opt30","");
	Options->CheckBox5->Caption = Inilng->ReadString("form","opt31","");
	//отладчик
	Options->GroupBox11->Caption = Inilng->ReadString("form","opt20","");
	Options->GroupBox10->Caption = Inilng->ReadString("form","opt19","");
	Options->CheckBox10->Caption = Inilng->ReadString("form","opt39","");
	Options->CheckBox11->Caption = Inilng->ReadString("form","opt40","");
	Options->CheckBox12->Caption = Inilng->ReadString("form","opt41","");
	Options->CheckBox6->Caption = Inilng->ReadString("form","opt42","");
	Options->CheckBox7->Caption = Inilng->ReadString("form","opt43","");
	Options->CheckBox8->Caption = Inilng->ReadString("form","opt44","");
	Options->CheckBox9->Caption = Inilng->ReadString("form","opt45","");
	Options->GroupBox9->Caption = Inilng->ReadString("form","opt46","");
	//автоматическое обновление
	Options->CheckBox14->Caption = Inilng->ReadString("form","opt32","");
	Options->CheckBox17->Caption = Inilng->ReadString("form","opt33","");
	Options->CheckBox16->Caption = Inilng->ReadString("form","opt34","");
	Options->CheckBox15->Caption = Inilng->ReadString("form","opt35","");
	Options->Label3->Caption = Inilng->ReadString("form","opt36","");
	Options->GroupBox15->Caption = Inilng->ReadString("form","opt37","");
}
//---------------------------------------------------------------------------

void __fastcall TOptions::FormClose(TObject *Sender, TCloseAction &Action)
{
	//плавно сворачиваем при закрытии
	TRect r1,r2;
	r1 = Rect(Left+Width/2,Top+Height/2,Left+Width/2,Top+Height/2);
	r2 = BoundsRect;
	DrawAnimatedRects(Handle,IDANI_CAPTION,&r2,&r1);
}
//---------------------------------------------------------------------------

void __fastcall TOptions::BitBtn1Click(TObject *Sender)
{
	//Сохраняем настройки
	if (Options->CheckBox4->Checked) {
		Ini->WriteBool("Macros", "Norm", RadioButton1->Checked);
		Ini->WriteBool("Macros", "Fast", RadioButton2->Checked);
		Ini->WriteBool("Macros", "Sys", RadioButton3->Checked);
		Ini->WriteBool("Macros", "App", RadioButton4->Checked);
		Ini->WriteBool("Other", "Close", CheckBox4->Checked);
		Ini->WriteBool("Other", "Default", CheckBox1->Checked);
		Ini->WriteString("Game", "Lok1", Edit1->Text);
		Ini->WriteBool("lang", "ru", RadioButton5->Checked);
		Ini->WriteBool("lang", "ua", RadioButton6->Checked);
		Ini->WriteBool("lang", "gb", RadioButton7->Checked);
		Ini->WriteBool("general", "save", CheckBox5->Checked);
		Ini->WriteString("general", "time", Edit2->Text);
		Ini->WriteBool("debuger", "activetws", CheckBox6->Checked);
		Ini->WriteBool("debuger", "activexml", CheckBox7->Checked);
		Ini->WriteBool("debuger", "activelua", CheckBox8->Checked);
		Ini->WriteBool("debuger", "uselua", CheckBox9->Checked);
		Ini->WriteBool("debuger", "activedebug", CheckBox10->Checked);
		Ini->WriteBool("debuger", "activelang", CheckBox11->Checked);
		Ini->WriteBool("debuger", "activesyntax", CheckBox12->Checked);
		Ini->WriteBool("Game", "game1", RadioButton8->Checked);
		Ini->WriteBool("Game", "game2", RadioButton9->Checked);
		Ini->WriteBool("Game", "mod1", RadioButton10->Checked);
		Ini->WriteBool("Game", "mod2", RadioButton11->Checked);
		Ini->WriteBool("update", "log", CheckBox14->Checked);
		Ini->WriteBool("update", "start", CheckBox15->Checked);
		Ini->WriteBool("update", "run", CheckBox16->Checked);
		Ini->WriteBool("update", "auto", CheckBox17->Checked);
		Ini->WriteString("update", "port", Edit3->Text);
		Ini->WriteBool("Lang", "user", CheckBox18->Checked);
		Ini->WriteBool("update", "use", CheckBox19->Checked);
		Ini->WriteString("update", "proxy", Edit4->Text);
		Ini->WriteString("update", "proxyuser", Edit5->Text);
		Ini->WriteString("update", "proxypass", Edit6->Text);
		Ini->UpdateFile();
		Options->Close();
	} else
		Ini->WriteBool("Macros", "Norm", RadioButton1->Checked);
		Ini->WriteBool("Macros", "Fast", RadioButton2->Checked);
		Ini->WriteBool("Macros", "Sys", RadioButton3->Checked);
		Ini->WriteBool("Macros", "App", RadioButton4->Checked);
		Ini->WriteBool("Other", "Close", CheckBox4->Checked);
		Ini->WriteBool("Other", "Default", CheckBox1->Checked);
		Ini->WriteString("Game", "Lok1", Edit1->Text);
		Ini->WriteBool("lang", "ru", RadioButton5->Checked);
		Ini->WriteBool("lang", "ua", RadioButton6->Checked);
		Ini->WriteBool("lang", "gb", RadioButton7->Checked);
		Ini->WriteBool("general", "save", CheckBox5->Checked);
		Ini->WriteString("general", "time", Edit2->Text);
		Ini->WriteBool("debuger", "activetws", CheckBox6->Checked);
		Ini->WriteBool("debuger", "activexml", CheckBox7->Checked);
		Ini->WriteBool("debuger", "activelua", CheckBox8->Checked);
		Ini->WriteBool("debuger", "uselua", CheckBox9->Checked);
		Ini->WriteBool("debuger", "activedebug", CheckBox10->Checked);
		Ini->WriteBool("debuger", "activelang", CheckBox11->Checked);
		Ini->WriteBool("debuger", "activesyntax", CheckBox12->Checked);
		Ini->WriteBool("Game", "game1", RadioButton8->Checked);
		Ini->WriteBool("Game", "game2", RadioButton9->Checked);
		Ini->WriteBool("Game", "mod1", RadioButton10->Checked);
		Ini->WriteBool("Game", "mod2", RadioButton11->Checked);
		Ini->WriteBool("update", "log", CheckBox14->Checked);
		Ini->WriteBool("update", "start", CheckBox15->Checked);
		Ini->WriteBool("update", "run", CheckBox16->Checked);
		Ini->WriteBool("update", "auto", CheckBox17->Checked);
		Ini->WriteString("update", "port", Edit3->Text);
		Ini->WriteBool("Lang", "user", CheckBox18->Checked);
		Ini->WriteBool("update", "use", CheckBox19->Checked);
		Ini->WriteString("update", "proxy", Edit4->Text);
		Ini->WriteString("update", "proxyuser", Edit5->Text);
		Ini->WriteString("update", "proxypass", Edit6->Text);
		Ini->UpdateFile();
}
//---------------------------------------------------------------------------

void __fastcall TOptions::RadioButton1Click(TObject *Sender)
{
	//задаем скорость воспроизведения: нормальная
	Form1->MacroRecorder1->PlaybackSpeed = pbNormal;
}
//---------------------------------------------------------------------------

void __fastcall TOptions::RadioButton2Click(TObject *Sender)
{
	//задаем скорость воспроизведения: быстрая
	Form1->MacroRecorder1->PlaybackSpeed = pbFast;
}
//---------------------------------------------------------------------------

void __fastcall TOptions::RadioButton3Click(TObject *Sender)
{
	//задаем диапазон записи: приложение
	Form1->MacroRecorder1->RecordingRange = rrApplication;
}
//---------------------------------------------------------------------------

void __fastcall TOptions::RadioButton4Click(TObject *Sender)
{
	//задаем диапазон записи:     система
	Form1->MacroRecorder1->RecordingRange = rrSystem;
}
//---------------------------------------------------------------------------

void __fastcall TOptions::CheckBox2Click(TObject *Sender)
{
	//Form1->MacroRecorder1->Options[roMouseMove=true];
}
//---------------------------------------------------------------------------

void __fastcall TOptions::BitBtn2Click(TObject *Sender)
{
	//закрываем форму по отмена
	Options->Close();
}
//---------------------------------------------------------------------------

void __fastcall TOptions::RadioButton5Click(TObject *Sender)
{
	//говорим программе что язык русский
	Ini->WriteString("lngflag", "active", "ru");
}
//---------------------------------------------------------------------------

void __fastcall TOptions::RadioButton6Click(TObject *Sender)
{
	//говорим программе что язык украйинский
	Ini->WriteString("lngflag", "active", "ua");
}
//---------------------------------------------------------------------------

void __fastcall TOptions::RadioButton7Click(TObject *Sender)
{
	//говорим программе что язык английский
	Ini->WriteString("lngflag", "active", "gb");
}
//---------------------------------------------------------------------------

void __fastcall TOptions::CheckBox5Click(TObject *Sender)
{
	//активируем поле ввода времени сохранения
	if (Options->CheckBox5->Checked) {
		Options->Edit2->Enabled = true;
	} else
		Options->Edit2->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TOptions::CheckBox11Click(TObject *Sender)
{
	//активируем языки
	if (Options->CheckBox11->Checked) {
		Options->GroupBox10->Enabled = true;
	} else
		Options->GroupBox10->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TOptions::CheckBox12Click(TObject *Sender)
{
	//активируем синтаксис
	if (Options->CheckBox12->Checked) {
		Options->GroupBox9->Enabled = true;
	} else
		Options->GroupBox9->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TOptions::CheckBox9Click(TObject *Sender)
{
	//включаем lua
	if (FileExists(ExtractFilePath(Application->ExeName)+"\\Data\\lua.dll") == false) {
		Options->CheckBox9->Checked = false;
		ShowMessage("Не найдена библиотека Lua");
	} else
		Options->CheckBox9->Checked = true;
}
//---------------------------------------------------------------------------

void __fastcall TOptions::CheckBox7Click(TObject *Sender)
{
	//xml
	if (FileExists(ExtractFilePath(Application->ExeName)+"\\Data\\xml.dll") == false) {
		Options->CheckBox7->Checked = false;
		ShowMessage("Не найдена библиотека XML");
	} else
		Options->CheckBox7->Checked = true;
}
//---------------------------------------------------------------------------

void __fastcall TOptions::CheckBox8Click(TObject *Sender)
{
	//Lua
	if (FileExists(ExtractFilePath(Application->ExeName)+"\\Data\\lua.dll") == false) {
		Options->CheckBox8->Checked = false;
		ShowMessage("Не найдена библиотека Lua");
	} else
		Options->CheckBox8->Checked = true;
}
//---------------------------------------------------------------------------

void __fastcall TOptions::CheckBox6Click(TObject *Sender)
{
	//tws
	if (FileExists(ExtractFilePath(Application->ExeName)+"\\Data\\error.dll") == false) {
		Options->CheckBox6->Checked = false;
		ShowMessage("Не найдена библиотека Error");
	} else
		Options->CheckBox6->Checked = true;
}
//---------------------------------------------------------------------------

void __fastcall TOptions::SpeedButton1Click(TObject *Sender)
{
	//удаляем выбранный макрос
	if (CheckBox13->Checked) {
		for (int i = 0; i < ListBox1->Items->Count; i++)
			if (ListBox1->Selected[i] && !(ListBox1->ItemIndex == -1))
				FileName = ExtractFilePath(Application->ExeName)+"macros/"+Form1->ListBox1->Items->Strings[i];
				DeleteFile(FileName);
				ListBox1->Items->Delete(ListBox1->ItemIndex);
				Options->ListBox1->Refresh();
				Options->ListBox1->Items->SaveToFile(ExtractFilePath(Application->ExeName)+"\\macros\\maclist.macsw");
	} else
		if (!(ListBox1->ItemIndex == -1))
			ListBox1->Items->Delete(ListBox1->ItemIndex);
			Options->ListBox1->Refresh();
			Options->ListBox1->Items->SaveToFile(ExtractFilePath(Application->ExeName)+"\\macros\\maclist.macsw");
}
//---------------------------------------------------------------------------

void __fastcall TOptions::Label1Click(TObject *Sender)
{
	//добавляем пользовательский язык
	if (!Options->OpenDialog1->Execute())return; {
		Options->ListBox2->Items->Add(ExtractFileName(Options->OpenDialog1->FileName));
	}
}
//---------------------------------------------------------------------------

void __fastcall TOptions::CheckBox18Click(TObject *Sender)
{
	//устанавливаем пользовательский язык интерфейса
	RadioButton5->Checked = false;
	RadioButton6->Checked = false;
	RadioButton7->Checked = false;
	for (int i = 0; i < ListBox2->Items->Count; i++)
		if(ListBox2->Selected[i])
			usrlng = Form1->ListBox1->Items->Strings[i];
			Label4->Caption = usrlng;
			Ini->WriteString("Lang", "userlng", usrlng);
}
//---------------------------------------------------------------------------

void __fastcall TOptions::CheckBox1Click(TObject *Sender)
{
	//сброс настроек
	Options->CheckBox3->Checked = false;
	Options->CheckBox2->Checked = false;
	Options->CheckBox4->Checked = false;
	Options->CheckBox5->Checked = false;
	Options->CheckBox6->Checked = false;
	Options->CheckBox7->Checked = false;
	Options->CheckBox8->Checked = false;
	Options->CheckBox9->Checked = false;
	Options->CheckBox10->Checked = false;
	Options->CheckBox11->Checked = false;
	Options->CheckBox12->Checked = false;
	Options->CheckBox14->Checked = true;
	Options->CheckBox15->Checked = false;
	Options->CheckBox16->Checked = false;
	Options->CheckBox17->Checked = false;
	Options->CheckBox18->Checked = false;
	Options->RadioButton1->Checked = true;
	Options->RadioButton2->Checked = false;
	Options->RadioButton3->Checked = true;
	Options->RadioButton4->Checked = false;
	Options->RadioButton5->Checked = true;
	Options->RadioButton6->Checked = false;
	Options->RadioButton7->Checked = false;
	Options->RadioButton8->Checked = false;
	Options->RadioButton9->Checked = false;
	Options->RadioButton10->Checked = false;
	Options->RadioButton11->Checked = false;
}
//---------------------------------------------------------------------------
