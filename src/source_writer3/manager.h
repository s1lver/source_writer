//---------------------------------------------------------------------------

#ifndef managerH
#define managerH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvPageControl.hpp"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include "PictureList.hpp"
#include "rtflabel.hpp"
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TAdvPageControl *AdvPageControl1;
	TAdvTabSheet *AdvTabSheet1;
	TAdvTabSheet *Empire;
	TPanel *Panel1;
	TPanel *Panel2;
	TPictureList *PictureList1;
	TPanel *Panel3;
	TPictureList *PictureList2;
	TPanel *Panel4;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TEdit *Edit1;
	TLabel *Label1;
	TEdit *Edit2;
	TLabel *Label2;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
TIniFile *Ini;
TIniFile *Inilng;

public:		// User declarations
	__fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
