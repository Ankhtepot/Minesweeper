//---------------------------------------------------------------------------

#ifndef uHelpH
#define uHelpH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFHelp : public TForm
{
__published:	// IDE-managed Components
        TMemo *Memo;
        TBitBtn *BitBtn1;
        void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFHelp(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFHelp *FHelp;
//---------------------------------------------------------------------------
#endif
