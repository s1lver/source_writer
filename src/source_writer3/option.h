//---------------------------------------------------------------------------

#ifndef optionH
#define optionH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvPageControl.hpp"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include "rtflabel.hpp"
#include <IniFiles.hpp>
#include <pngimage.hpp>
#include <jpeg.hpp>
#include <Dialogs.hpp>
#include "Spin.hpp"
//---------------------------------------------------------------------------
class TOptions : public TForm
{
__published:	// IDE-managed Components
	TAdvPageControl *AdvPageControl1;
	TAdvTabSheet *AdvTabSheet1;
	TPanel *Panel1;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TCheckBox *CheckBox1;
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TListBox *ListBox1;
	TSpeedButton *SpeedButton1;
	TGroupBox *GroupBox3;
	TRadioButton *RadioButton3;
	TRadioButton *RadioButton4;
	TGroupBox *GroupBox4;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TCheckBox *CheckBox4;
	TAdvTabSheet *AdvTabSheet2;
	TGroupBox *GroupBox5;
	TEdit *Edit1;
	TAdvTabSheet *AdvTabSheet3;
	TGroupBox *GroupBox6;
	TImage *Image1;
	TImage *Image2;
	TImage *Image3;
	TRadioButton *RadioButton5;
	TRadioButton *RadioButton6;
	TRadioButton *RadioButton7;
	TGroupBox *GroupBox7;
	TListBox *ListBox2;
	TLabel *Label1;
	TAdvTabSheet *AdvTabSheet4;
	TGroupBox *GroupBox8;
	TCheckBox *CheckBox5;
	TEdit *Edit2;
	TAdvTabSheet *Отладчик;
	TGroupBox *GroupBox9;
	TCheckBox *CheckBox6;
	TCheckBox *CheckBox7;
	TCheckBox *CheckBox8;
	TGroupBox *GroupBox10;
	TGroupBox *GroupBox11;
	TCheckBox *CheckBox9;
	TCheckBox *CheckBox10;
	TCheckBox *CheckBox11;
	TCheckBox *CheckBox12;
	TGroupBox *GroupBox12;
	TRadioButton *RadioButton8;
	TRadioButton *RadioButton9;
	TRadioButton *RadioButton10;
	TRadioButton *RadioButton11;
	TGroupBox *GroupBox13;
	TGroupBox *GroupBox14;
	TCheckBox *CheckBox13;
	TAdvTabSheet *AdvTabSheet5;
	TCheckBox *CheckBox14;
	TLabel *Label3;
	TEdit *Edit3;
	TImage *Image4;
	TGroupBox *GroupBox15;
	TCheckBox *CheckBox15;
	TCheckBox *CheckBox16;
	TCheckBox *CheckBox17;
	TOpenDialog *OpenDialog1;
	TCheckBox *CheckBox18;
	TLabel *Label4;
	TGroupBox *GroupBox16;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TCheckBox *CheckBox19;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall RadioButton1Click(TObject *Sender);
	void __fastcall RadioButton2Click(TObject *Sender);
	void __fastcall RadioButton3Click(TObject *Sender);
	void __fastcall RadioButton4Click(TObject *Sender);
	void __fastcall CheckBox2Click(TObject *Sender);
	void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall RadioButton5Click(TObject *Sender);
	void __fastcall RadioButton6Click(TObject *Sender);
	void __fastcall RadioButton7Click(TObject *Sender);
	void __fastcall CheckBox5Click(TObject *Sender);
	void __fastcall CheckBox11Click(TObject *Sender);
	void __fastcall CheckBox12Click(TObject *Sender);
	void __fastcall CheckBox9Click(TObject *Sender);
	void __fastcall CheckBox7Click(TObject *Sender);
	void __fastcall CheckBox8Click(TObject *Sender);
	void __fastcall CheckBox6Click(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall Label1Click(TObject *Sender);
	void __fastcall CheckBox18Click(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	private:	// User declarations
	TIniFile *Ini;
	TIniFile *Inilng;
	public:		// User declarations
	__fastcall TOptions(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TOptions *Options;
//---------------------------------------------------------------------------
#endif
