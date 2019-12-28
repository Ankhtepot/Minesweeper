//---------------------------------------------------------------------------

#ifndef uVlastniH
#define uVlastniH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFVlastni : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TEdit *EPocetMin;
        TEdit *ESirka;
        TEdit *EVyska;
        TBitBtn *BBCancel;
        TBitBtn *BBOK;
        TUpDown *UDPocetMin;
        TUpDown *UDSirka;
        TUpDown *UDVyska;
        void __fastcall BBOKClick(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFVlastni(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFVlastni *FVlastni;
//---------------------------------------------------------------------------
#endif
