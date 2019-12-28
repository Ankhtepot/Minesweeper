//---------------------------------------------------------------------------

#ifndef uEditorH
#define uEditorH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include "CSPIN.h"
#include <Graphics.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
  const int MaxX = 30;
  const int MaxY = 30;

  struct field {
    int workX;
    int workY;
    };

   struct Ematrix {
    int Xsize;
    int Ysize;
    int sum_bomb;
    bool matrix[MaxX][MaxY];
    };

//---------------------------------------------------------------------------
class TFEditor : public TForm
{
__published:	// IDE-managed Components
        TImage *ImgPlocha;
        TBevel *Bevel1;
        TEdit *ESirka;
        TEdit *EVyska;
        TButton *BNavrat;
        TButton *BReset;
        TLabel *Label1;
        TLabel *Label2;
        TCSpinButton *CSpinButton1;
        TCSpinButton *CSpinButton2;
        TImage *Image1;
        TLabel *Label3;
        TEdit *ESum_bomb;
        TButton *BShow;
        TSpeedButton *SBBomb;
        TSpeedButton *SBNone;
        TButton *BLoad;
        TButton *BSave;
        TOpenDialog *LD;
        TSaveDialog *SD;
        void __fastcall ImgPlochaMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall BNavratClick(TObject *Sender);
        void __fastcall BResetClick(TObject *Sender);
        void __fastcall CSpinButton1UpClick(TObject *Sender);
        void __fastcall CSpinButton1DownClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall CSpinButton2DownClick(TObject *Sender);
        void __fastcall CSpinButton2UpClick(TObject *Sender);
        void __fastcall BShowClick(TObject *Sender);
        void __fastcall SBBombClick(TObject *Sender);
        void __fastcall ImgPlochaMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall BLoadClick(TObject *Sender);
        void __fastcall BSaveClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFEditor(TComponent* Owner);
        void DrawTile(Graphics::TBitmap * bmp, int X, int Y);
        void FillImg();
        int pokus;
        AnsiString FillLine(int linenumber);
        field work;
        int BSummary();
};
//---------------------------------------------------------------------------
extern PACKAGE TFEditor *FEditor;
//extern matrix Matrix;
//---------------------------------------------------------------------------
#endif
