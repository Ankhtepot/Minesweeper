//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uRekord.h"
#include "u1.h"
#include "MakraMinolovka.h"
#include <stdio>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFRekord *FRekord;
//---------------------------------------------------------------------------
extern StartData SData;
//---------------------------------------------------------------------------
__fastcall TFRekord::TFRekord(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFRekord::FormActivate(TObject *Sender)
{
  //SOME(ITS(SData.PokrocilyRekord.cas));
  LZ->Caption = (IntToTimeAS(SData.ZacatecnikRekord.cas)+" - "+SData.ZacatecnikRekord.jmeno);
  LP->Caption = (IntToTimeAS(SData.PokrocilyRekord.cas)+" - "+SData.PokrocilyRekord.jmeno);
  LE->Caption = (IntToTimeAS(SData.ExpertRekord.cas)+" - "+SData.ExpertRekord.jmeno);
}
//---------------------------------------------------------------------------

AnsiString TFRekord::IntToTimeAS(int time)
{
  AnsiString AS,ASpred,ASza;
  int pred = time/60;
  int za = time%60;
  if(za>60)
    {
    pred++;
    za=60-za;
    }
  if(pred<10)
    ASpred=("0"+ITS(pred));
    else
      ASpred=ITS(pred);
  if(za<10)
    ASza=("0"+ITS(za));
    else
      ASza=ITS(za);
  AS=ASpred+":"+ASza;
  return AS;
}
