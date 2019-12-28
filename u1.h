//---------------------------------------------------------------------------

#ifndef u1H
#define u1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ImgList.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <Graphics.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
//const int rnd = 50;
const int CItimer = 5;
const int N_EWwidth = 192;
const int CDefaultLeft = 208;

  struct PressMoment {
    int x;
    int y;
    };

  //struct pro policko
  struct tile {
    bool bomb;
    bool reveal;
    bool flag;
    bool revealed;
    short status;
    short BetPosition;
    Graphics::TBitmap * bmp;
    };

  struct rekord {
    char jmeno[21];
    int cas;
    };

  struct StartData {
    int IStartSize;
    rekord ZacatecnikRekord;
    rekord PokrocilyRekord;
    rekord ExpertRekord;
    };

  struct JednaZeDvou {
    void Reset();
    short oznaceno;
    PressMoment one;
    PressMoment two;
    };

  struct Bet {
    void Reset();
    short oznaceno;
    PressMoment pozice[10];
    };

//---------------------------------------------------------------------------
class TFHlavni : public TForm
{
__published:	// IDE-managed Components
        TImageList *IL1;
        TMainMenu *MM;
        TMenuItem *MMOptions;
        TMenuItem *MMZacatecnik;
        TMenuItem *MMPokrocily;
        TMenuItem *MMExpert;
        TMenuItem *MMEditor;
        TMenuItem *N1;
        TMenuItem *servis1;
        TMenuItem *MMShowBoolean;
        TMenuItem *MMRestart;
        TMenuItem *MMOdhalVse;
        TImage *ITimer;
        TImageList *IL2;
        TTimer *TMain;
        TImage *ICounter;
        TMenuItem *MMVlastni;
        TImageList *IL3;
        TPanel *PPlocha;
        TImage *IBorderNW;
        TImage *IBorderW_NS_1;
        TImage *IBorderT_W;
        TImage *IBorderW_NS_2;
        TImage *IBorderSW;
        TSpeedButton *SBStart;
        TSpeedButton *SBJednaZeDvou;
        TSpeedButton *SBBet;
        TSpeedButton *SBKonec;
        TImage *IBorderN_EW;
        TImage *IBorderNE;
        TImage *IBorderE_NS_1;
        TImage *IBorderT_E;
        TImage *IBorderE_NS_2;
        TImage *IBorderSE;
        TImage *IBorderS_EW;
        TImage *IBorderM_EW;
        TImage *INet_1;
        TImageList *IL4;
        TImage *INet_2;
        TImage *INet_3;  //net na plose, kdyz Xsize<12
        TMenuItem *N2;
        TMenuItem *MMKonec;
        TMenuItem *MMRekord;
        TMenuItem *MMRekordReset;
        TMenuItem *Extra1;
        TMenuItem *MMJednaDva;
        TMenuItem *MMBet;
        TMenuItem *MMZnacky;
        TOpenDialog *LD;
        TMenuItem *MMNahrat;
        TMenuItem *N3;
        TMenuItem *MMJana;
        TMenuItem *N4;
        TMenuItem *MMCHEATVyhra;
        TMemo *Memo;
        TMenuItem *OProgramu1;
        TMenuItem *OProgramu2;
        TMenuItem *Help1;
        TMenuItem *N5;
        TMenuItem *MMSymbolVlajky;
        TMenuItem *MMFlag;
        TMenuItem *Smajlk1;
        TMenuItem *srdce1;
        TMenuItem *Dreek1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall KonecClick(TObject *Sender);
        void __fastcall IPlochaMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall IPlochaMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall IPlochaMouseMove(TObject * Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall SBResetClick(TObject *Sender);
        void __fastcall SBEditorClick(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall BShowClick(TObject *Sender);
        void __fastcall MMZacatecnikClick(TObject *Sender);
        void __fastcall MMPokrocilyClick(TObject *Sender);
        void __fastcall MMExpertClick(TObject *Sender);
        void __fastcall MMOdhalVseClick(TObject *Sender);
        void __fastcall TMainTimer(TObject *Sender);
        void __fastcall MMVlastniClick(TObject *Sender);
        void __fastcall SBStartClick(TObject *Sender);
        void __fastcall MMRekordResetClick(TObject *Sender);
        void __fastcall MMRekordClick(TObject *Sender);
        void __fastcall MMJednaDvaClick(TObject *Sender);
        void __fastcall MMZnackyClick(TObject *Sender);
        void __fastcall MMBetClick(TObject *Sender);
        void __fastcall MMNahratClick(TObject *Sender);
        void __fastcall MMJanaClick(TObject *Sender);
        void __fastcall MMCHEATVyhraClick(TObject *Sender);
        void __fastcall OProgramu2Click(TObject *Sender);
        void __fastcall Help1Click(TObject *Sender);
        void __fastcall FormKeyPress(TObject *Sender, char &Key);
        void __fastcall MMFlagClick(TObject *Sender);
        void __fastcall Smajlk1Click(TObject *Sender);
        void __fastcall srdce1Click(TObject *Sender);
        void __fastcall Dreek1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        TImage * IPlocha;
        __fastcall TFHlavni(TComponent* Owner);
        void DrawTile(Graphics::TBitmap * bmp,int X,int Y);
        int CountBombs(int startX, int startY, int maxX, int maxY);
        AnsiString FillLine(int linenumber);
        void VytvorPlochu(int matrixx, int matrixy);
        void ClearMatrix(void);
        void Zaminovat(int matrixx, int matrixy, int bomb_sum);
        void SpocitatMiny(int matrixx, int matrixy);
        bool BReveal;
        bool BGroupReveal;
        bool BKonec;
        bool BJednaZeDvou;
        PressMoment RevealMoment;
        JednaZeDvou JZD;
        Bet Bet;
        void OdhalOkoli(int startx, int starty);
        void OdhalPolicko(int matrixx, int matrixy);
        int Xsize;
        int Ysize;
        int rnd;
        int IJtag;
        int IBombSummary;//int pro nastaveni ICounter
        int IStopky;// int pro nastaveni IStopky
        void OkoliDolu(int startx, int starty);
        int CountFlags(int startx, int starty);
        void KonecBoom();
        void OdhalVse();
        void DrawTimer(Graphics::TBitmap * bmp, int position);
        void DrawCounter(Graphics::TBitmap * bmp, int position);
        int BombSummary();
        bool NastavCounter(int num);
        bool NastavTimer(AnsiString v);
        void ITimerChange();
        void OkoliNahoru(int startx, int starty);
        void VytvorBorder();
        void FillTileFull(TImage * img);
        void WinEndQuery();
        bool OkoliNeodhaleno(int startx, int starty);
        int CountBet();
        void CHEATwin();
        void LoadMap(AnsiString File);
         

};
//---------------------------------------------------------------------------
extern PACKAGE TFHlavni *FHlavni;
//---------------------------------------------------------------------------
#endif
