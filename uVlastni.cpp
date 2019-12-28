//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uVlastni.h"
#include "MakraMinolovka.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFVlastni *FVlastni;
//---------------------------------------------------------------------------
extern int b_sum;
extern int sirka;
extern int vyska;
//---------------------------------------------------------------------------
__fastcall TFVlastni::TFVlastni(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFVlastni::BBOKClick(TObject *Sender)
{
  try
    {
    b_sum=STI(EPocetMin->Text);
    }
  catch (Exception &e)
    {
    if(EPocetMin->Text == "") {b_sum=1;}
    EPocetMin->SelStart=((EPocetMin->Text.Length())-1);
    EPocetMin->SelLength=(1);
    EPocetMin->SelText = "";
    }

  try
    {
    sirka=STI(ESirka->Text);
    }
  catch (Exception &e)
    {
    if(ESirka->Text == "") {sirka=1;}
    ESirka->SelStart=((ESirka->Text.Length())-1);
    ESirka->SelLength=(1);
    ESirka->SelText = "";
    }

  try
    {
    vyska=STI(EVyska->Text);
    }
  catch (Exception &e)
    {
    if(EVyska->Text == "") {vyska=1;}
    EVyska->SelStart=((EVyska->Text.Length())-1);
    EVyska->SelLength=(1);
    EVyska->SelText = "";
    }
}
//---------------------------------------------------------------------------

void __fastcall TFVlastni::FormActivate(TObject *Sender)
{
  EPocetMin->Text = ITS(b_sum);
  ESirka->Text = ITS(sirka);
  EVyska->Text = ITS(vyska);
  EPocetMin->Focused();
  EPocetMin->SelectAll();
}
//---------------------------------------------------------------------------

