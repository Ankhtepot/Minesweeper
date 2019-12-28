//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uHelp.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFHelp *FHelp;
//---------------------------------------------------------------------------
__fastcall TFHelp::TFHelp(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TFHelp::FormActivate(TObject *Sender)
{
  Memo->Lines->LoadFromFile("help.txt");
}
//---------------------------------------------------------------------------
