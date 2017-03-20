//---------------------------------------------------------------------------

#ifndef objectH
#define objectH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <CheckLst.hpp>
#include <Tabs.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include "AdvTabSet.hpp"
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TObject_form : public TForm
{
__published:	// IDE-managed Components
	TPopupMenu *PopupMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TAdvTabSet *AdvTabSet1;
	TListBox *ListBox1;
	TListBox *ListBox2;
	TOpenDialog *OpenDialog1;
	TOpenDialog *OpenDialog2;
	TPopupMenu *PopupMenu2;
	TMenuItem *N3;
	TMenuItem *N4;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall ListBox2DblClick(TObject *Sender);
	void __fastcall N1Click(TObject *Sender);
	void __fastcall AdvTabSet1Change(TObject *Sender, int NewTab, bool &AllowChange);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);



private:	// User declarations
TIniFile *Ini;
TIniFile *Inilng;
public:		// User declarations
	__fastcall TObject_form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TObject_form *Object_form;
//---------------------------------------------------------------------------
#endif
