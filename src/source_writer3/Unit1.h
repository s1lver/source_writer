//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include "AdvToolBar.hpp"
#include <ActnCtrls.hpp>
#include <ActnList.hpp>
#include <ActnMan.hpp>
#include <ActnMenus.hpp>
#include <PlatformDefaultStyleActnCtrls.hpp>
#include <ToolWin.hpp>
#include "AdvToolBarStylers.hpp"
#include "AdvOfficeStatusBar.hpp"
#include "AdvOfficeStatusBarStylers.hpp"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include "AdvMemo.hpp"
#include <ImgList.hpp>
#include <Dialogs.hpp>
#include "AdvmWS.hpp"
#include "Advmxml.hpp"
#include <DockTabSet.hpp>
#include <Tabs.hpp>
#include "AdvCodeList.hpp"
#include <Buttons.hpp>
#include <Graphics.hpp>
#include "MacroRecorder.hpp"
#include "AdvSplitter.hpp"
#include "ToolPanels.hpp"
#include "AdvTabSet.hpp"
#include "AdvNavBar.hpp"
#include "AdvPageControl.hpp"
#include "WUpdate.hpp"
#include "WUpdateWiz.hpp"
#include "AdvReflectionLabel.hpp"
#include <AppEvnts.hpp>
#include "DirOutln.hpp"
#include "paramlst.hpp"
#include <Grids.hpp>
#include <Outline.hpp>
#include <FileCtrl.hpp>
#include <ExtDlgs.hpp>
#include "AdvmPS.hpp"
#include "AdvmINIs.hpp"
#include "AdvmCSHS.hpp"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TAdvToolBar *AdvToolBar1;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TAdvXMLMemoStyler *AdvXMLMemoStyler1;
	TAdvJSMemoStyler *AdvJSMemoStyler1;
	TPopupMenu *PopupMenu1;
	TMenuItem *N1;
	TCoolBar *CoolBar1;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TImageList *ImageList2;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *ToolButton4;
	TToolButton *ToolButton5;
	TToolButton *ToolButton6;
	TToolButton *ToolButton7;
	TToolButton *ToolButton8;
	TToolButton *ToolButton9;
	TToolButton *ToolButton10;
	TToolButton *ToolButton11;
	TToolButton *ToolButton12;
	TToolButton *ToolButton13;
	TToolButton *ToolButton14;
	TPopupMenu *PopupMenu2;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TPopupMenu *PopupMenu3;
	TMenuItem *txt1;
	TMainMenu *MainMenu1;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *N8;
	TMenuItem *N9;
	TMenuItem *N10;
	TMenuItem *N11;
	TMenuItem *N12;
	TMenuItem *txt2;
	TMenuItem *N13;
	TMenuItem *N14;
	TMenuItem *N15;
	TMenuItem *N16;
	TMenuItem *N17;
	TMenuItem *N21;
	TMenuItem *N18;
	TMenuItem *N19;
	TMenuItem *N20;
	TMenuItem *N22;
	TMenuItem *N23;
	TMenuItem *N24;
	TMenuItem *N25;
	TMenuItem *N26;
	TMenuItem *N27;
	TMenuItem *N28;
	TMenuItem *N29;
	TMenuItem *N30;
	TMenuItem *N31;
	TMenuItem *N32;
	TAdvMemoFindDialog *AdvMemoFindDialog1;
	TMenuItem *N33;
	TMenuItem *N34;
	TMenuItem *N35;
	TAdvMemoFindReplaceDialog *AdvMemoFindReplaceDialog1;
	TPrinterSetupDialog *PrinterSetupDialog1;
	TPrintDialog *PrintDialog1;
	TPopupMenu *PopupMenu4;
	TMenuItem *N36;
	TMenuItem *N37;
	TMenuItem *N38;
	TCategoryPanelGroup *CategoryPanelGroup1;
	TMenuItem *N39;
	TCategoryPanel *CategoryPanel1;
	TCategoryPanel *CategoryPanel2;
	TCategoryPanel *CategoryPanel3;
	TCategoryPanelGroup *CategoryPanelGroup2;
	TMenuItem *N40;
	TCategoryPanel *CategoryPanel4;
	TAdvCodeList *AdvCodeList1;
	TMenuItem *N41;
	TMenuItem *goldencenturyorg1;
	TMenuItem *N42;
	TMenuItem *N43;
	TMenuItem *xml1;
	TMenuItem *cfg1;
	TMenuItem *xml2;
	TMenuItem *cfg2;
	TCategoryPanel *CategoryPanel5;
	TGroupBox *GroupBox1;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TRadioButton *RadioButton3;
	TStatusBar *StatusBar1;
	TImage *Image40;
	TImage *Image41;
	TImage *Image42;
	TImage *Image43;
	TImage *Image44;
	TImage *Image45;
	TImage *Image46;
	TImage *Image47;
	TImage *Image48;
	TImage *Image49;
	TImage *Image50;
	TImage *Image51;
	TImage *Image52;
	TImage *Image65;
	TImage *Image64;
	TImage *Image63;
	TImage *Image62;
	TImage *Image61;
	TImage *Image60;
	TImage *Image59;
	TImage *Image58;
	TImage *Image57;
	TImage *Image56;
	TImage *Image55;
	TImage *Image54;
	TImage *Image53;
	TImage *Image13;
	TImage *Image12;
	TImage *Image11;
	TImage *Image10;
	TImage *Image9;
	TImage *Image8;
	TImage *Image7;
	TImage *Image6;
	TImage *Image5;
	TImage *Image4;
	TImage *Image3;
	TImage *Image2;
	TImage *Image1;
	TImage *Image24;
	TImage *Image25;
	TImage *Image26;
	TImage *Image23;
	TImage *Image22;
	TImage *Image21;
	TImage *Image20;
	TImage *Image19;
	TImage *Image18;
	TImage *Image17;
	TImage *Image16;
	TImage *Image15;
	TImage *Image14;
	TImage *Image39;
	TImage *Image38;
	TImage *Image37;
	TImage *Image36;
	TImage *Image35;
	TImage *Image34;
	TImage *Image33;
	TImage *Image32;
	TImage *Image31;
	TImage *Image30;
	TImage *Image29;
	TImage *Image28;
	TImage *Image27;
	TImageList *ImageList1;
	TMenuItem *N44;
	TMenuItem *N45;
	TMenuItem *xml3;
	TMenuItem *txt3;
	TMenuItem *N46;
	TTrayIcon *TrayIcon1;
	TPopupMenu *PopupMenu5;
	TMenuItem *N47;
	TMenuItem *N48;
	TMenuItem *N49;
	TMenuItem *N50;
	TMenuItem *N51;
	TMenuItem *N52;
	TMenuItem *N53;
	TImage *Image66;
	TImage *Image67;
	TImage *Image68;
	TImage *Image69;
	TImage *Image70;
	TImage *Image71;
	TImage *Image72;
	TImage *Image73;
	TImage *Image74;
	TImage *Image75;
	TImage *Image76;
	TImage *Image77;
	TMenuItem *N54;
	TCategoryPanel *CategoryPanel6;
	TMacroRecorder *MacroRecorder1;
	TCategoryPanel *CategoryPanel7;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TListBox *ListBox1;
	TMenuItem *N55;
	TEdit *Edit1;
	TAdvTabSet *AdvTabSet1;
	TAdvPageControl *AdvPageControl1;
	TWebUpdate *WebUpdate1;
	TWebUpdateWizard *WebUpdateWizard1;
	TMenuItem *N57;
	TMenuItem *N60;
	TMenuItem *N61;
	TPanel *Panel1;
	TRichEdit *RichEdit2;
	TMenuItem *N62;
	TSpeedButton *SpeedButton4;
	TSpeedButton *SpeedButton5;
	TSplitter *Splitter1;
	TAdvPageControl *AdvPageControl2;
	TAdvTabSheet *AdvTabSheet1;
	TApplicationEvents *ApplicationEvents1;
	TAdvMemoSource *AdvMemoSource1;
	TCategoryPanel *CategoryPanel8;
	TAdvPageControl *AdvPageControl3;
	TAdvTabSheet *AdvTabSheet2;
	TAdvTabSheet *AdvTabSheet3;
	TAdvTabSheet *AdvTabSheet4;
	TListBox *ListBox2;
	TListBox *ListBox3;
	TListBox *ListBox4;
	TMenuItem *N65;
	TMenuItem *N66;
	TOpenTextFileDialog *OpenTextFileDialog1;
	TMenuItem *N67;
	TMenuItem *N68;
	TMenuItem *N69;
	TSaveTextFileDialog *SaveTextFileDialog1;
	TListBox *ListBox5;
	TImageList *ImageList3;
	TMenuItem *N70;
	TMenuItem *N71;
	TMenuItem *N72;
	TAdvPascalMemoStyler *AdvPascalMemoStyler1;
	TMenuItem *lua1;
	TMenuItem *lua2;
	TMenuItem *lua3;
	TLabel *Label1;
	TTimer *Timer1;
	TMenuItem *N73;
	TMenuItem *N74;
	TMenuItem *N75;
	TMenuItem *N76;
	TMenuItem *N110;
	TMenuItem *N210;
	TMenuItem *N310;
	TMenuItem *N410;
	TMenuItem *N510;
	TMenuItem *N610;
	TMenuItem *N77;
	TMenuItem *N81;
	TMenuItem *N91;
	TMenuItem *N101;
	TMenuItem *N111;
	TMenuItem *N211;
	TMenuItem *N311;
	TMenuItem *N411;
	TMenuItem *N511;
	TMenuItem *N611;
	TMenuItem *N78;
	TMenuItem *N82;
	TMenuItem *N92;
	TMenuItem *N102;
	TAdvINIMemoStyler *AdvINIMemoStyler1;
	TMenuItem *cfg3;
	TMenuItem *N56;
	TMenuItem *N58;
	TMenuItem *N59;
	TMenuItem *N79;
	TMenuItem *N80;
	TMenuItem *N83;
	TMenuItem *N63;
	TMenuItem *Unpacker1;
	TMenuItem *N64;
	TLabel *Label2;
	TCategoryPanel *CategoryPanel9;
	TSpeedButton *SpeedButton6;
	TEdit *Edit2;
	TMenuItem *N84;
	TCheckBox *CheckBox1;
	TAdvMemo *AdvMemo1;
	void __fastcall N1Click(TObject *Sender);
	void __fastcall ToolButton8Click(TObject *Sender);
	void __fastcall ToolButton3Click(TObject *Sender);
	void __fastcall ToolButton2Click(TObject *Sender);
	void __fastcall txt1Click(TObject *Sender);
	void __fastcall N16Click(TObject *Sender);
	void __fastcall txt2Click(TObject *Sender);
	void __fastcall N17Click(TObject *Sender);
	void __fastcall N13Click(TObject *Sender);
	void __fastcall N14Click(TObject *Sender);
	void __fastcall N21Click(TObject *Sender);
	void __fastcall N18Click(TObject *Sender);
	void __fastcall ToolButton11Click(TObject *Sender);
	void __fastcall ToolButton10Click(TObject *Sender);
	void __fastcall N19Click(TObject *Sender);
	void __fastcall ToolButton6Click(TObject *Sender);
	void __fastcall ToolButton7Click(TObject *Sender);
	void __fastcall ToolButton5Click(TObject *Sender);
	void __fastcall N22Click(TObject *Sender);
	void __fastcall N23Click(TObject *Sender);
	void __fastcall N24Click(TObject *Sender);
	void __fastcall N25Click(TObject *Sender);
	void __fastcall N28Click(TObject *Sender);
	void __fastcall N27Click(TObject *Sender);
	void __fastcall ToolButton14Click(TObject *Sender);
	void __fastcall N32Click(TObject *Sender);
	void __fastcall ToolButton13Click(TObject *Sender);
	void __fastcall N34Click(TObject *Sender);
	void __fastcall N35Click(TObject *Sender);
	void __fastcall N29Click(TObject *Sender);
	void __fastcall N31Click(TObject *Sender);
	void __fastcall N36Click(TObject *Sender);
	void __fastcall N38Click(TObject *Sender);
	void __fastcall N39Click(TObject *Sender);
	void __fastcall N40Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall N41Click(TObject *Sender);
	void __fastcall goldencenturyorg1Click(TObject *Sender);
	void __fastcall N43Click(TObject *Sender);
	void __fastcall xml2Click(TObject *Sender);
	void __fastcall cfg2Click(TObject *Sender);
	void __fastcall xml1Click(TObject *Sender);
	void __fastcall cfg1Click(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall N5Click(TObject *Sender);
	void __fastcall Image40Click(TObject *Sender);
	void __fastcall Image41Click(TObject *Sender);
	void __fastcall Image42Click(TObject *Sender);
	void __fastcall Image43Click(TObject *Sender);
	void __fastcall Image44Click(TObject *Sender);
	void __fastcall Image45Click(TObject *Sender);
	void __fastcall Image46Click(TObject *Sender);
	void __fastcall Image47Click(TObject *Sender);
	void __fastcall Image48Click(TObject *Sender);
	void __fastcall Image49Click(TObject *Sender);
	void __fastcall Image50Click(TObject *Sender);
	void __fastcall Image51Click(TObject *Sender);
	void __fastcall Image52Click(TObject *Sender);
	void __fastcall Image53Click(TObject *Sender);
	void __fastcall Image54Click(TObject *Sender);
	void __fastcall Image55Click(TObject *Sender);
	void __fastcall Image56Click(TObject *Sender);
	void __fastcall Image57Click(TObject *Sender);
	void __fastcall Image58Click(TObject *Sender);
	void __fastcall Image59Click(TObject *Sender);
	void __fastcall Image60Click(TObject *Sender);
	void __fastcall Image61Click(TObject *Sender);
	void __fastcall Image62Click(TObject *Sender);
	void __fastcall Image63Click(TObject *Sender);
	void __fastcall Image64Click(TObject *Sender);
	void __fastcall Image65Click(TObject *Sender);
	void __fastcall Image1Click(TObject *Sender);
	void __fastcall Image2Click(TObject *Sender);
	void __fastcall Image3Click(TObject *Sender);
	void __fastcall Image4Click(TObject *Sender);
	void __fastcall Image5Click(TObject *Sender);
	void __fastcall Image6Click(TObject *Sender);
	void __fastcall xml3Click(TObject *Sender);
	void __fastcall txt3Click(TObject *Sender);
	void __fastcall N46Click(TObject *Sender);
	void __fastcall N52Click(TObject *Sender);
	void __fastcall N48Click(TObject *Sender);
	void __fastcall N50Click(TObject *Sender);
	void __fastcall N47Click(TObject *Sender);
	void __fastcall N53Click(TObject *Sender);
	void __fastcall Image67Click(TObject *Sender);
	void __fastcall Image66Click(TObject *Sender);
	void __fastcall Image77Click(TObject *Sender);
	void __fastcall Image76Click(TObject *Sender);
	void __fastcall Image75Click(TObject *Sender);
	void __fastcall Image74Click(TObject *Sender);
	void __fastcall Image73Click(TObject *Sender);
	void __fastcall Image71Click(TObject *Sender);
	void __fastcall Image72Click(TObject *Sender);
	void __fastcall Image68Click(TObject *Sender);
	void __fastcall Image69Click(TObject *Sender);
	void __fastcall Image70Click(TObject *Sender);
	void __fastcall N54Click(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall N55Click(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall N57Click(TObject *Sender);
	void __fastcall SDTXT1Click(TObject *Sender);
	void __fastcall AdvTabSet1Change(TObject *Sender, int NewTab, bool &AllowChange);
	void __fastcall N62Click(TObject *Sender);
	void __fastcall SpeedButton4Click(TObject *Sender);
	void __fastcall SpeedButton5Click(TObject *Sender);
	void __fastcall AdvCodeList1DragOver(TObject *Sender, TObject *Source, int X, int Y,
          TDragState State, bool &Accept);
	void __fastcall AdvCodeList1DragDrop(TObject *Sender, TObject *Source, int X, int Y);
	void __fastcall AdvCodeList1BlockRightClick(TObject *Sender, TCodeBlock *ACodeBlock);
	void __fastcall AdvCodeList1BlockInsertFromClipboard(TObject *Sender, TCodeBlock *ACodeBlock);
	void __fastcall ApplicationEvents1Exception(TObject *Sender, Exception *E);
	void __fastcall N65Click(TObject *Sender);
	void __fastcall N66Click(TObject *Sender);
	void __fastcall N67Click(TObject *Sender);
	void __fastcall N69Click(TObject *Sender);
	void __fastcall N70Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ListBox1DblClick(TObject *Sender);
	void __fastcall N60Click(TObject *Sender);
	void __fastcall N72Click(TObject *Sender);
	void __fastcall lua1Click(TObject *Sender);
	void __fastcall lua2Click(TObject *Sender);
	void __fastcall lua3Click(TObject *Sender);
	void __fastcall MemoClick(TObject *Sender);
	void __fastcall MemoKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall ListBox4DblClick(TObject *Sender);
	void __fastcall ListBox5DblClick(TObject *Sender);
	void __fastcall ListBox3DblClick(TObject *Sender);
	void __fastcall ListBox2DblClick(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall Image14Click(TObject *Sender);
	void __fastcall Image15Click(TObject *Sender);
	void __fastcall Image16Click(TObject *Sender);
	void __fastcall Image17Click(TObject *Sender);
	void __fastcall Image18Click(TObject *Sender);
	void __fastcall Image27Click(TObject *Sender);
	void __fastcall Image28Click(TObject *Sender);
	void __fastcall Image29Click(TObject *Sender);
	void __fastcall Image30Click(TObject *Sender);
	void __fastcall Image31Click(TObject *Sender);
	void __fastcall Image20Click(TObject *Sender);
	void __fastcall Image34Click(TObject *Sender);
	void __fastcall Image10Click(TObject *Sender);
	void __fastcall Image12Click(TObject *Sender);
	void __fastcall Image13Click(TObject *Sender);
	void __fastcall Image26Click(TObject *Sender);
	void __fastcall Image37Click(TObject *Sender);
	void __fastcall Image23Click(TObject *Sender);
	void __fastcall Image33Click(TObject *Sender);
	void __fastcall Image19Click(TObject *Sender);
	void __fastcall Image39Click(TObject *Sender);
	void __fastcall Image24Click(TObject *Sender);
	void __fastcall Image35Click(TObject *Sender);
	void __fastcall Image32Click(TObject *Sender);
	void __fastcall Image7Click(TObject *Sender);
	void __fastcall Image21Click(TObject *Sender);
	void __fastcall Image22Click(TObject *Sender);
	void __fastcall Image11Click(TObject *Sender);
	void __fastcall Image38Click(TObject *Sender);
	void __fastcall Image25Click(TObject *Sender);
	void __fastcall Image36Click(TObject *Sender);
	void __fastcall Image9Click(TObject *Sender);
	void __fastcall Image8Click(TObject *Sender);
	void __fastcall Label1Click(TObject *Sender);
	void __fastcall AdvPageControl1Change(TObject *Sender);
	void __fastcall N111Click(TObject *Sender);
	void __fastcall N110Click(TObject *Sender);
	void __fastcall N210Click(TObject *Sender);
	void __fastcall N310Click(TObject *Sender);
	void __fastcall N410Click(TObject *Sender);
	void __fastcall N510Click(TObject *Sender);
	void __fastcall N610Click(TObject *Sender);
	void __fastcall N77Click(TObject *Sender);
	void __fastcall N81Click(TObject *Sender);
	void __fastcall N91Click(TObject *Sender);
	void __fastcall N101Click(TObject *Sender);
	void __fastcall N211Click(TObject *Sender);
	void __fastcall N311Click(TObject *Sender);
	void __fastcall N411Click(TObject *Sender);
	void __fastcall N511Click(TObject *Sender);
	void __fastcall N611Click(TObject *Sender);
	void __fastcall N78Click(TObject *Sender);
	void __fastcall N82Click(TObject *Sender);
	void __fastcall N92Click(TObject *Sender);
	void __fastcall N102Click(TObject *Sender);
	void __fastcall cfg3Click(TObject *Sender);
	void __fastcall N58Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall N80Click(TObject *Sender);
	void __fastcall N83Click(TObject *Sender);
	void __fastcall N73Click(TObject *Sender);
	void __fastcall N63Click(TObject *Sender);
	void __fastcall Unpacker1Click(TObject *Sender);
	void __fastcall SpeedButton6Click(TObject *Sender);
	void __fastcall Edit2Change(TObject *Sender);
	void __fastcall Edit2KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Edit2Enter(TObject *Sender);

	private:	// User declarations
	TIniFile *Ini;

	public:		// User declarations
	TAdvMemo *memo[256];
	TAdvTabSheet  *pts[256];

	__fastcall TForm1(TComponent* Owner);
	void TForm1::actbtn(void);
	void TForm1::noactbtn(void);
	void TForm1::debug_string(void);
	void TForm1::fidlistbox(void);
	void TForm1::win1251(void);
	void TForm1::error(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
