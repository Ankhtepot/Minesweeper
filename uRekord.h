//---------------------------------------------------------------------------

#ifndef uRekordH
#define uRekordH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
class TFRekord : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *BBNavrat;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *LZ;
        TLabel *LP;
        TLabel *LE;
        void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFRekord(TComponent* Owner);
        AnsiString IntToTimeAS(int time);
};
//---------------------------------------------------------------------------
extern PACKAGE TFRekord *FRekord;
//---------------------------------------------------------------------------
#endif
