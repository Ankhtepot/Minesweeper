//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uEditor.h"
#include "uRekord.h"
#include "structs.h"
#include "uVlastni.h"
#include "uAbout.h"
#include "uHelp.h"
#include "MakraMinolovka.h"
#include "u1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFHlavni *FHlavni;
//---------------------------------------------------------------------------
  //externi promene
  extern Ematrix Matrix;
  extern TImage Plocha;
//---------------------------------------------------------------------------
  //grafika
Graphics::TBitmap * tile_0 = new Graphics::TBitmap;
Graphics::TBitmap * tile_n = new Graphics::TBitmap;
Graphics::TBitmap * tile_1 = new Graphics::TBitmap;
Graphics::TBitmap * tile_2 = new Graphics::TBitmap;
Graphics::TBitmap * tile_3 = new Graphics::TBitmap;
Graphics::TBitmap * tile_4 = new Graphics::TBitmap;
Graphics::TBitmap * tile_5 = new Graphics::TBitmap;
Graphics::TBitmap * tile_6 = new Graphics::TBitmap;
Graphics::TBitmap * tile_7 = new Graphics::TBitmap;
Graphics::TBitmap * tile_8 = new Graphics::TBitmap;
Graphics::TBitmap * tile_bomb = new Graphics::TBitmap;
Graphics::TBitmap * tile_boom = new Graphics::TBitmap;
Graphics::TBitmap * tile_wrong = new Graphics::TBitmap;
Graphics::TBitmap * tile_flag = new Graphics::TBitmap;
Graphics::TBitmap * tile_O = new Graphics::TBitmap;
Graphics::TBitmap * tile_one = new Graphics::TBitmap;
Graphics::TBitmap * tile_two = new Graphics::TBitmap;
Graphics::TBitmap * tile_bet = new Graphics::TBitmap;
Graphics::TBitmap * tile_net16x16 = new Graphics::TBitmap;

Graphics::TBitmap * num_0 = new Graphics::TBitmap;
Graphics::TBitmap * num_dd = new Graphics::TBitmap;
Graphics::TBitmap * num_1 = new Graphics::TBitmap;
Graphics::TBitmap * num_2 = new Graphics::TBitmap;
Graphics::TBitmap * num_3 = new Graphics::TBitmap;
Graphics::TBitmap * num_4 = new Graphics::TBitmap;
Graphics::TBitmap * num_5 = new Graphics::TBitmap;
Graphics::TBitmap * num_6 = new Graphics::TBitmap;
Graphics::TBitmap * num_7 = new Graphics::TBitmap;
Graphics::TBitmap * num_8 = new Graphics::TBitmap;
Graphics::TBitmap * num_9 = new Graphics::TBitmap;
Graphics::TBitmap * num_minus = new Graphics::TBitmap;
Graphics::TBitmap * num_e = new Graphics::TBitmap;
Graphics::TBitmap * num_black = new Graphics::TBitmap;

Graphics::TBitmap * bor_NW = new Graphics::TBitmap;
Graphics::TBitmap * bor_NE = new Graphics::TBitmap;
Graphics::TBitmap * bor_SW = new Graphics::TBitmap;
Graphics::TBitmap * bor_SE = new Graphics::TBitmap;
Graphics::TBitmap * bor_W_NS = new Graphics::TBitmap;
Graphics::TBitmap * bor_E_NS = new Graphics::TBitmap;
Graphics::TBitmap * bor_T_W = new Graphics::TBitmap;
Graphics::TBitmap * bor_T_E = new Graphics::TBitmap;
Graphics::TBitmap * bor_N_EW = new Graphics::TBitmap;
Graphics::TBitmap * bor_S_EW = new Graphics::TBitmap;
Graphics::TBitmap * bor_M_EW = new Graphics::TBitmap;

Graphics::TBitmap * tile_net = new Graphics::TBitmap;
//---------------------------------------------------------------------------
  //definice finkci struktur
  void JednaZeDvou::Reset()
    {
    oznaceno=2;
    one.x=-1;
    one.y=-1;
    two.x=-1;
    two.y=-1;
    };

  void Bet::Reset()
    {
    oznaceno=0;
    for(int x=0;x<10;x++)
      {
      pozice[x].x=-1;
      pozice[x].y=-1;
      }
    };

//---------------------------------------------------------------------------
  //globalni promenne
StartData SData;
tile matrix[MaxX][MaxY];
TImage * I[MaxY][MaxY];
int Itimer[CItimer];
int b_sum,sirka,vyska;
//---------------------------------------------------------------------------
__fastcall TFHlavni::TFHlavni(TComponent* Owner)
        : TForm(Owner)
{
  IL1->GetBitmap(0,tile_0);
  IL1->GetBitmap(1,tile_n);
  IL1->GetBitmap(2,tile_1);
  IL1->GetBitmap(3,tile_2);
  IL1->GetBitmap(4,tile_3);
  IL1->GetBitmap(5,tile_4);
  IL1->GetBitmap(6,tile_5);
  IL1->GetBitmap(7,tile_6);
  IL1->GetBitmap(8,tile_7);
  IL1->GetBitmap(9,tile_8);
  IL1->GetBitmap(10,tile_bomb);
  IL1->GetBitmap(11,tile_boom);
  IL1->GetBitmap(12,tile_wrong);
  IL1->GetBitmap(13,tile_flag);
  IL1->GetBitmap(14,tile_O);
  IL1->GetBitmap(15,tile_one);
  IL1->GetBitmap(16,tile_two);
  IL1->GetBitmap(17,tile_bet);
  IL1->GetBitmap(18,tile_net16x16);

  IL2->GetBitmap(0,num_0);
  IL2->GetBitmap(1,num_1);
  IL2->GetBitmap(2,num_2);
  IL2->GetBitmap(3,num_3);
  IL2->GetBitmap(4,num_4);
  IL2->GetBitmap(5,num_5);
  IL2->GetBitmap(6,num_6);
  IL2->GetBitmap(7,num_7);
  IL2->GetBitmap(8,num_8);
  IL2->GetBitmap(9,num_9);
  IL2->GetBitmap(10,num_minus);
  IL2->GetBitmap(11,num_e);
  IL2->GetBitmap(12,num_dd);
  IL2->GetBitmap(13,num_black);

  IL3->GetBitmap(0,bor_E_NS);
  IL3->GetBitmap(1,bor_SE);
  IL3->GetBitmap(2,bor_M_EW);
  IL3->GetBitmap(3,bor_N_EW);
  IL3->GetBitmap(4,bor_NE);
  IL3->GetBitmap(5,bor_NW);
  IL3->GetBitmap(6,bor_S_EW);
  IL3->GetBitmap(7,bor_SW);
  IL3->GetBitmap(8,bor_T_E);
  IL3->GetBitmap(9,bor_T_W);
  IL3->GetBitmap(10,bor_W_NS);

  IL4->GetBitmap(1,tile_net);

}
//---------------------------------------------------------------------------

void __fastcall TFHlavni::FormCreate(TObject *Sender)
{
  TMain->Enabled=false;
  BReveal = false;
  BGroupReveal = false;
  BKonec = false;
  RevealMoment.x = 0;
  RevealMoment.y = 0;
  IStopky=0;
  IJtag=-1;

  for(int i=0;i<MaxX;i++)
    for(int y=0;y<MaxY;y++)
      {
      matrix[i][y].reveal = true;
      matrix[i][y].revealed = false;
      matrix[i][y].status = 0;
      }

  NastavTimer("00:00");

  SBStart->Tag=0;

  for(int i=1;i<=3;i++)
    DrawCounter(num_0,i);

  rnd=(double(Time())*100);

  FILE *fr;
  if((fr=fopen("start.dat","rb"))==NULL) {
   ShowMessage("Chyba pøi naèítání souboru start.dat !");
   SData.IStartSize = 1;
   SData.ZacatecnikRekord.cas = 999;
   strcpy(SData.ZacatecnikRekord.jmeno,"god");
   SData.PokrocilyRekord.cas = 999;
   strcpy(SData.PokrocilyRekord.jmeno,"Satan");
   SData.ExpertRekord.cas = 999;
   strcpy(SData.ExpertRekord.jmeno,"Bill G");
   return;
   }
  fread(&SData,sizeof(StartData),1,fr);
  fclose(fr);

  SBStart->Tag = SData.IStartSize;
  if(SBStart->Tag==4 || SBStart->Tag==5)
    SBStart->Tag = 2;
  SBStart->Click();

  JZD.Reset();
  Bet.Reset();

  NastavCounter(BombSummary());

  IBorderNW->Canvas->Brush->Bitmap = bor_NW;
  FillTileFull(IBorderNW);
  IBorderW_NS_1->Canvas->Brush->Bitmap = bor_W_NS;
  FillTileFull(IBorderW_NS_1);
  IBorderT_W->Canvas->Brush->Bitmap = bor_T_W;
  FillTileFull(IBorderT_W);
  INet_1->Canvas->Brush->Bitmap = tile_net;
  INet_2->Canvas->Brush->Bitmap = tile_net;
  FillTileFull(INet_1);
  FillTileFull(INet_2);
  VytvorBorder();

}
//---------------------------------------------------------------------------
 
//---------------------------------------------------------------------------
void __fastcall TFHlavni::KonecClick(TObject *Sender)
{
  SData.IStartSize = SBStart->Tag;
  FILE *fw;
  if((fw = fopen("start.dat","wb"))==NULL)
    {
    ShowMessage("Chyba pøi ukládání do start.dat !!!");
    return;
    }
  fwrite(&SData,sizeof(StartData),1,fw);
  fclose(fw);
  Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TFHlavni::IPlochaMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  TImage * I= (TImage *)Sender;
  int matrixx = I->Left/16;
  int matrixy = I->Top/16;
  int Xdraw=matrixx;
  int Ydraw=matrixy;
  RevealMoment.x=matrixx;
  RevealMoment.y=matrixy;
  if(SBJednaZeDvou->Down)
    {
    if(!matrix[matrixx][matrixy].revealed && !matrix[matrixx][matrixy].flag && matrix[matrixx][matrixy].bmp!=tile_one)
     if(!(matrix[matrixx][matrixy].bmp==tile_bet))
      switch(JZD.oznaceno)
        {
        case 0:
          {
          JZD.Reset();
          SBJednaZeDvou->AllowAllUp=true;
          SBJednaZeDvou->Down = false;
          };break;
        case 1:
          {
          SBJednaZeDvou->AllowAllUp=true;
          SBJednaZeDvou->Down = false;
          DrawTile(tile_two,Xdraw,Ydraw);
          JZD.oznaceno=0;
          JZD.two.x = matrixx;
          JZD.two.y = matrixy;
          SOME("Chvíle napìtí.");
          if(matrix[JZD.one.x][JZD.one.y].bomb && matrix[JZD.two.x][JZD.two.y].bomb)
            {
            SOME("Tak to moc nebylo jedna mina na dvou polích -"
            " miny jsou pod obìma poli, takže bye,bye :)");
            matrix[JZD.one.x][JZD.one.y].flag = matrix[JZD.two.x][JZD.two.y].flag = true;
            matrix[JZD.one.x][JZD.one.y].bomb = matrix[JZD.two.x][JZD.two.y].bomb = false;
            KonecBoom();
            }
            else if(matrix[JZD.one.x][JZD.one.y].bomb || matrix[JZD.two.x][JZD.two.y].bomb)
                   {
                   IStopky+=10;
                   if(matrix[JZD.one.x][JZD.one.y].bomb)
                     {
                     OdhalPolicko(JZD.two.x,JZD.two.y);
                     DrawTile(tile_flag,JZD.one.x,JZD.one.y);
                     matrix[JZD.one.x][JZD.one.y].flag = true;
                     IBombSummary--;
                     NastavCounter(IBombSummary);
                     }
                     else
                       {
                       OdhalPolicko(JZD.one.x,JZD.one.y);
                       DrawTile(tile_flag,JZD.two.x,JZD.two.y);
                       matrix[JZD.two.x][JZD.two.y].flag = true;
                       IBombSummary--;
                       NastavCounter(IBombSummary);
                       }
                   }// if bomb || bomb
                     else if(!(matrix[JZD.one.x][JZD.one.y].bomb || matrix[JZD.two.x][JZD.two.y].bomb))
                             {
                             SOME("Tak to jsi teda netrefil/a - ani pod jedním z polí není mina, takže bye, bye :)");
                             matrix[JZD.one.x][JZD.one.y].flag = matrix[JZD.two.x][JZD.two.y].flag = true;
                             KonecBoom();
                             }

          matrix[JZD.one.x][JZD.one.y].bmp = tile_n;
          matrix[JZD.two.x][JZD.two.y].bmp = tile_n;
          SBJednaZeDvou->AllowAllUp=true;
          SBJednaZeDvou->Down = false;
          JZD.Reset();
          };break;
        case 2:
          {
          DrawTile(tile_one,Xdraw,Ydraw);
          JZD.oznaceno=1;
          JZD.one.x = matrixx;
          JZD.one.y = matrixy;
          };break;
        }//switch JZD.oznaceno
      }//JZD.aktiv
    //------> else pro praci s Bet
    else if(!matrix[matrixx][matrixy].revealed && SBBet->Down)
        {
        if(matrix[matrixx][matrixy].bmp==tile_bet)
          {
          if(!(OkoliNeodhaleno(matrixx,matrixy)))
            {
            SOME("Jak vidno, špatný tip = +10 sekund.");
            IStopky+=10;
            }
          DrawTile(tile_n,Xdraw,Ydraw);
          Bet.oznaceno--;
          matrix[matrixx][matrixy].flag=false;
          IBombSummary++;
          NastavCounter(IBombSummary);
          }
          else if(Bet.oznaceno<10)
                 if(OkoliNeodhaleno(matrixx,matrixy))
                   {
                   matrix[matrixx][matrixy].bmp=tile_bet;
                   matrix[matrixx][matrixy].flag=true;
                   IBombSummary--;
                   NastavCounter(IBombSummary);
                   DrawTile(tile_bet,Xdraw,Ydraw);
                   Bet.oznaceno++;
                   }
                   else
                     SOME("Lze vsadit jen na pole, ktere nemá okolo žádné odhalené pole");
        } // else if Bet


  else if(!matrix[matrixx][matrixy].revealed && !matrix[matrixx][matrixy].flag)
    if(Button==mbLeft)
      {
      BReveal = true;
      if(matrix[matrixx][matrixy].reveal)
        DrawTile(tile_0,Xdraw,Ydraw);
      }

  if(Shift.Contains(ssLeft) && matrix[matrixx][matrixy].revealed)
    if(Shift.Contains(ssRight) && CountFlags(matrixx,matrixy)==matrix[matrixx][matrixy].status)
      {
      BGroupReveal=true;
      OkoliDolu(matrixx,matrixy);
      }

}
//---------------------------------------------------------------------------
void __fastcall TFHlavni::IPlochaMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  int matrixx,matrixy;
  TImage * I=(TImage*)Sender;
  matrixx = I->Left / 16;
  matrixy = I->Top / 16;

  if(!TMain->Enabled && !BKonec)
    {
    TMain->Enabled=true;
    }

  if(BReveal == true)
    {
    BReveal = false;
    //DrawTile(tile_n,matrixx,matrixy);
    if(matrix[matrixx][matrixy].bomb)
      {
      DrawTile(tile_boom,matrixx,matrixy);
      matrix[matrixx][matrixy].reveal = false;
      matrix[matrixx][matrixy].revealed = true;
      KonecBoom();
      return;
      }
      else
        {
        OdhalPolicko(matrixx,matrixy);
        WinEndQuery();
        } // else obsahujici switch
      } //if Breveal-nasleduje else !!
      else if(matrix[matrixx][matrixy].flag && Button==mbRight)
               {
               DrawTile(tile_n,matrixx,matrixy);
               matrix[matrixx][matrixy].flag = false;
               IBombSummary++;
               NastavCounter(IBombSummary);
               }
               else if(!matrix[matrixx][matrixy].revealed && Button==mbRight)
                 {
                 if(MMZnacky->Checked==true && !(matrix[matrixx][matrixy].bmp==tile_O))
                   {
                   DrawTile(tile_O,matrixx,matrixy);
                   }
                   else
                     {
                     DrawTile(tile_flag,matrixx,matrixy);
                     matrix[matrixx][matrixy].flag = true;
                     matrix[matrixx][matrixy].bmp = tile_flag;
                     IBombSummary--;
                     NastavCounter(IBombSummary);
                     }
                 }
  if(BGroupReveal && CountFlags(matrixx,matrixy)==matrix[matrixx][matrixy].status)
    if(BGroupReveal && Shift.Contains(ssLeft) || Shift.Contains(ssRight))
      {
      BGroupReveal==false;
      OdhalOkoli(matrixx,matrixy);
      WinEndQuery();
      }
}

//---------------------------------------------------------------------------

void TFHlavni::DrawTile(Graphics::TBitmap * bmp, int X,int Y)
{
  matrix[X][Y].bmp = bmp;
  I[X][Y]->Canvas->CopyRect(Rect(0,0,16,16),bmp->Canvas,Rect(0,0,16,16));
}
//---------------------------------------------------------------------------

void __fastcall TFHlavni::SBResetClick(TObject *Sender)
{
  BKonec=false;
  NastavTimer("00:00");
  IStopky=0;
  TMain->Enabled=false;
  JZD.Reset();
  Bet.Reset();
  
  for(int i=0;i<MaxX;i++)
    for(int y=0;y<MaxY;y++)
      {
      matrix[i][y].flag = false;
      matrix[i][y].reveal = true;
      matrix[i][y].revealed = false;
      }

  for(int x = 0; x < sirka; x++)
    for(int y = 0; y < vyska; y++)
      DrawTile(tile_n,x,y);

  IBombSummary=BombSummary();
  NastavCounter(IBombSummary);
}
//---------------------------------------------------------------------------

void __fastcall TFHlavni::SBEditorClick(TObject *Sender)
{
  //ClearMatrix();
  BKonec = false;
  IStopky=0;
  TMain->Enabled = false;

  b_sum=IBombSummary;

  if(!(FEditor->ShowModal()))
    return;

  VytvorPlochu(Matrix.Xsize,Matrix.Ysize);

  for(int i=0;i<Matrix.Xsize;i++)
    for(int y=0;y<Matrix.Ysize;y++)
      {
      matrix[i][y].bomb = Matrix.matrix[i][y];
      }
  SpocitatMiny(Matrix.Xsize,Matrix.Ysize);
  IBombSummary=BombSummary();
  NastavCounter(IBombSummary);
  VytvorBorder();
  SBStart->Tag=5;
}
//---------------------------------------------------------------------------

void __fastcall TFHlavni::FormDestroy(TObject *Sender)
{
  delete IPlocha;
  delete tile_n;
  delete tile_1;
  delete tile_2;
  delete tile_3;
  delete tile_4;
  delete tile_5;
  delete tile_6;
  delete tile_7;
  delete tile_8;
  delete tile_bomb;
  delete tile_boom;
  delete tile_wrong;
  delete tile_flag;
  delete tile_O;
  delete tile_one;
  delete tile_two;
  delete tile_bet;

  delete IBorderE_NS_1;
  delete IBorderE_NS_2;
  delete IBorderM_EW;
  delete IBorderN_EW;
  delete IBorderNE;
  delete IBorderNW;
  delete IBorderS_EW;
  delete IBorderSE;
  delete IBorderSW;
  delete IBorderT_E;
  delete IBorderT_W;
  delete IBorderW_NS_1;
  delete IBorderW_NS_2;
}
//---------------------------------------------------------------------------

int TFHlavni::CountBombs(int startx, int starty, int maxX, int maxY)
{
  int MX=maxX;
  int MY=maxY;
  int counter = 0;
  if(starty>0 && matrix[startx][starty-1].bomb)
    counter++;
  if(startx<MX && starty>0 && matrix[startx+1][starty-1].bomb)
    counter++;
  if(startx<MX && matrix[startx+1][starty].bomb)
    counter++;
  if(startx<MX && starty<MY && matrix[startx+1][starty+1].bomb)
    counter++;
  if(starty<MY && matrix[startx][starty+1].bomb)
    counter++;
  if(starty<MY && startx>0 && matrix[startx-1][starty+1].bomb)
    counter++;
  if(startx>0 && matrix[startx-1][starty].bomb)
    counter++;
  if(startx>0 && starty>0 && matrix[startx-1][starty-1].bomb)
    counter++;
  //ShowMessage(counter);
  return counter;
}
//---------------------------------------------------------------------------

void __fastcall TFHlavni::BShowClick(TObject *Sender)
{
  AnsiString * Lines = new AnsiString[Ysize];
  AnsiString LinesFinal;
  for(int i=0;i<Ysize;i++)
    {
    Lines[i] = FillLine(i);
    LinesFinal += Lines[i];
    }
  ShowMessage(LinesFinal);
}
//---------------------------------------------------------------------------


AnsiString TFHlavni::FillLine(int linenumber)
{
  AnsiString result = "";
  for(int i=0;i<Xsize;i++)
    if(matrix[i][linenumber].bomb)
      result += "1";
      else result += "0";
  result += "\n";
  return result;
}
//---------------------------------------------------------------------------


void TFHlavni::VytvorPlochu(int matrixx, int matrixy)
{  
  ClearMatrix();


  delete IPlocha;
  Xsize = sirka = matrixx;
  Ysize = vyska = matrixy;
  PPlocha->Width = 16*Xsize;
  PPlocha->Height = 16*Ysize;
  IStopky=0;
  NastavTimer("00:00");
  TMain->Enabled = false;
  SBJednaZeDvou->Down=false;
  SBBet->Down=false;
  JZD.Reset();
  Bet.Reset();

  //vytvoreni PPlocha - panel na kterrem jsou imidze
  delete PPlocha;
  TPanel * PPlocha=new TPanel(this);
  PPlocha->Name = "PPlocha";
  PPlocha->Parent = FHlavni;
  PPlocha->Left= 16;
  PPlocha->Top = 52;
  PPlocha->Height = vyska*16;
  PPlocha->Width = sirka*16;
  PPlocha->Caption="";

  //Vytvoreni pole imidzi
  for(int x=0;x<sirka;x++)
    for(int y=0;y<vyska;y++)
      {
      IPlocha = new TImage(PPlocha);
      IPlocha->Parent = PPlocha;
      IPlocha->Visible = false;
      IPlocha->Top = y*16;
      IPlocha->Left = x*16;
      IPlocha->Width = 16;
      IPlocha->Height = 16;
      IPlocha->Canvas->CopyRect(Rect(0,0,16,16),tile_n->Canvas,Rect(0,0,16,16));
      IPlocha->OnMouseDown = &IPlochaMouseDown;
      IPlocha->OnMouseUp = &IPlochaMouseUp;
      IPlocha->OnMouseMove = &IPlochaMouseMove;
      IPlocha->Visible = true;
      I[x][y]=IPlocha;
      }

  VytvorBorder();

  //pro Janu
  if(IJtag==0)
    {
    Memo->Visible = false;
    Memo->Top = 0;
    Memo->Left = 0;
    Memo->Width = 1;
    Memo->Height = 1;
    }
    else
      Memo->Top = IBorderSW->Top+16;
}
//---------------------------------------------------------------------------

void TFHlavni::ClearMatrix(void)
{
  BKonec = false;
  for(int i=0;i<MaxX;i++)
    for(int y=0;y<MaxY;y++)
      {
      matrix[i][y].flag = false;
      matrix[i][y].bomb = false;
      matrix[i][y].reveal = true;
      matrix[i][y].revealed = false;
      matrix[i][y].BetPosition = -1;
      matrix[i][y].status = 0;
      }
}
//---------------------------------------------------------------------------

void __fastcall TFHlavni::MMZacatecnikClick(TObject *Sender)
{
  int x = 9;
  int y = 9;
  int bomb_sum = 10;
    VytvorPlochu(x,y);
  Zaminovat(x,y,bomb_sum);
  SpocitatMiny(x,y);
  SBStart->Tag=1;
  IBombSummary=BombSummary();
  NastavCounter(IBombSummary);
}
//---------------------------------------------------------------------------

void TFHlavni::Zaminovat(int matrixx, int matrixy, int bomb_sum)
{
  int PRnaradek = bomb_sum/matrixy;

  bool * skip = new bool[matrixx];
  for(int i=0;i<matrixx;i++)
    skip[i]=false;

  ClearMatrix();

  if(bomb_sum%matrixy > 0)
    {
    int zbytek = bomb_sum-(PRnaradek*matrixy);
    while(zbytek>0)
      for(int s=0;s<matrixy && zbytek>0;s++)
        if(random(rnd)==1 && !skip[s])
          {
          skip[s] = true;
          zbytek--;
          }

    }


    for(int i=0;i<matrixy;i++)
      {
      int PR = PRnaradek;
      if(skip[i])
        PR++;
      while(PR>0)
        for(int s=0;s<matrixx && PR>0;s++)
          if(random(rnd)==1 && !matrix[s][i].bomb)
            {
            matrix[s][i].bomb=true;
            PR--;
            }
      }
  delete[]skip;
}
//--------------------------------------------------------------------------

void TFHlavni::SpocitatMiny(int matrixx, int matrixy)
{
  for(int i=0;i<matrixx;i++)
    for(int y=0;y<matrixy;y++)
      {
      matrix[i][y].status = CountBombs(i,y,matrixx-1,matrixy-1);
      }

}
//--------------------------------------------------------------------------
void __fastcall TFHlavni::IPlochaMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
 /*TImage * I=(TImage*)Sender;
 int Ix=(I->Left/16);
 int Iy=(I->Top/16);*/
 //this->Caption = ("X="+ITS(Ix)+" ; Y="+ITS(Iy));

  if(!(Shift.Contains(ssLeft) || Shift.Contains(ssRight)))
    {
    BReveal = BGroupReveal = false;
    }

  int Xpos,Ypos,Xmouse,Ymouse;
  Xpos = RevealMoment.x;
  Ypos = RevealMoment.y;
  Xmouse = X/16;
  Ymouse = Y/16;

  FHlavni->Caption = ("Xpos(RM)="+IntToStr(Xpos)+" Ypos(RM)="+IntToStr(Ypos)+" Xmouse"+IntToStr(Xmouse)+" Ymouse="+IntToStr(Ymouse));

  if(Shift.Contains(ssLeft))
    {
    if(Xmouse > 0 || Xmouse < 0 || Ymouse > 0 || Ymouse < 0)
      if(!matrix[Xpos][Ypos].revealed && !matrix[Xpos][Ypos].flag)
        {
        DrawTile(tile_n,Xpos,Ypos);
        BReveal = false;
        }
    }
        /*
      {
      RevealMoment.x = Ix;
      RevealMoment.y = Iy;
      if(!matrix[Xpos][Ypos].revealed && !matrix[Xpos][Ypos].flag)
        {
        DrawTile(tile_n,Xpos,Ypos);
        BReveal = false;
        }
      if(!matrix[Xmouse][Ymouse].revealed && !matrix[Xmouse][Ymouse].flag)
        {
        DrawTile(tile_0,Xmouse,Ymouse);
        BReveal = true;
        matrix[Xmouse][Ymouse].reveal = true;
        }
      //if(!matrix[Xmouse][Ymouse].revealed && !matrix[Xmouse][Ymouse].flag)
        //SOME("TU");
      } //if se spostou ||
    } // contains.ssLeft
      */
  if((Xmouse > 0 || Xmouse < 0 || Ymouse > 0 || Ymouse < 0) && BGroupReveal)
    {
    OkoliNahoru(Xpos,Ypos);
    BGroupReveal=false;
    BReveal=false;
    }

}
//---------------------------------------------------------------------------

void __fastcall TFHlavni::MMPokrocilyClick(TObject *Sender)
{
  int x = 16;
  int y = 16;
  int bomb_sum = 40;
    VytvorPlochu(x,y);
  Zaminovat(x,y,bomb_sum);
  SpocitatMiny(x,y);
  IBombSummary=BombSummary();
  NastavCounter(IBombSummary);
  VytvorBorder();
  SBStart->Tag=2;
}
//---------------------------------------------------------------------------

void __fastcall TFHlavni::MMExpertClick(TObject *Sender)
{
  int x = 30;
  int y = 16;
  int bomb_sum = 99;
    VytvorPlochu(x,y);
  Zaminovat(x,y,bomb_sum);
  SpocitatMiny(x,y);
  IBombSummary=BombSummary();
  NastavCounter(IBombSummary);
  VytvorBorder();
  SBStart->Tag=3;
}
//---------------------------------------------------------------------------


void TFHlavni::OdhalOkoli(int startx, int starty)
{
  int MX = Xsize-1;
  int MY = Ysize-1;

  if(starty>0 && !matrix[startx][starty-1].revealed && !matrix[startx][starty-1].flag)
    {
    matrix[startx][starty-1].revealed = true;
    matrix[startx][starty-1].reveal = false;
    OdhalPolicko(startx,starty-1);
    }
  if(startx<MX && starty>0 && !matrix[startx+1][starty-1].revealed && !matrix[startx+1][starty-1].flag)
    {
    matrix[startx+1][starty-1].revealed = true;
    matrix[startx+1][starty-1].reveal = false;
    OdhalPolicko(startx+1,starty-1);
    }
  if(startx<MX && !matrix[startx+1][starty].revealed && !matrix[startx+1][starty].flag)
    {
    matrix[startx+1][starty].revealed = true;
    matrix[startx+1][starty].reveal = false;
    OdhalPolicko(startx+1,starty);
    }
  if(startx<MX && starty<MY && !matrix[startx+1][starty+1].revealed && !matrix[startx+1][starty+1].flag)
    {
    matrix[startx+1][starty+1].revealed = true;
    matrix[startx+1][starty+1].reveal = false;
    OdhalPolicko(startx+1,starty+1);
    }
  if(starty<MY && !matrix[startx][starty+1].revealed && !matrix[startx][starty+1].flag)
    {
    matrix[startx][starty+1].revealed = true;
    matrix[startx][starty+1].reveal = false;
    OdhalPolicko(startx,starty+1);
    }
  if(startx>0 && starty<MY && !matrix[startx-1][starty+1].revealed && !matrix[startx-1][starty+1].flag)
    {
    matrix[startx-1][starty+1].revealed = true;
    matrix[startx-1][starty+1].reveal = false;
    OdhalPolicko(startx-1,starty+1);
    }
  if(startx>0 && !matrix[startx-1][starty].revealed && !matrix[startx-1][starty].flag)
    {
    matrix[startx-1][starty].revealed = true;
    matrix[startx-1][starty].reveal = false;
    OdhalPolicko(startx-1,starty);
    }
  if(startx>0 && starty>0 && !matrix[startx-1][starty-1].revealed && !matrix[startx-1][starty-1].flag)
    {
    matrix[startx-1][starty-1].revealed = true;
    matrix[startx-1][starty-1].reveal = false;
    OdhalPolicko(startx-1,starty-1);
    }
}
//---------------------------------------------------------------------------

void TFHlavni::OdhalPolicko(int matrixx, int matrixy)
{
  int DX = matrixx;
  int DY = matrixy;
  if(matrix[matrixx][matrixy].bomb)
    {
    DrawTile(tile_boom,DX,DY);
    KonecBoom();
    return;
    }
    else
      {
      matrix[matrixx][matrixy].reveal = false;
      matrix[matrixx][matrixy].revealed = true;
      switch(matrix[matrixx][matrixy].status)
          {
          case 0:
            {
            OdhalOkoli(matrixx,matrixy);
            DrawTile(tile_0,DX,DY);
            } ; break ;
          case 1:DrawTile(tile_1,DX,DY); break ;
          case 2:DrawTile(tile_2,DX,DY); break;
          case 3:DrawTile(tile_3,DX,DY); break;
          case 4:DrawTile(tile_4,DX,DY); break;
          case 5:DrawTile(tile_5,DX,DY); break;
          case 6:DrawTile(tile_6,DX,DY); break;
          case 7:DrawTile(tile_7,DX,DY); break;
          case 8:DrawTile(tile_8,DX,DY); break;
          } //switch status
      } //else m[x][y].bomb
}
//---------------------------------------------------------------------------


void __fastcall TFHlavni::MMOdhalVseClick(TObject *Sender)
{
  OdhalVse();
}
//---------------------------------------------------------------------------

void TFHlavni::OkoliDolu(int startx, int starty)
{
  int MX=Xsize-1;
  int MY=Ysize-1;
  int Xdraw=startx;
  int Ydraw=starty;
   if(starty>0 && !matrix[startx][starty-1].revealed && !matrix[startx][starty-1].flag)
      {
      DrawTile(tile_0,Xdraw,Ydraw-1);
      }
    if(startx<MX && starty>0 && !matrix[startx+1][starty-1].revealed &&!matrix[startx+1][starty-1].flag)
      {
      DrawTile(tile_0,Xdraw+1,Ydraw-1);
      }
    if(startx<MX && !matrix[startx+1][starty].revealed &&!matrix[startx+1][starty].flag)
      {
      DrawTile(tile_0,Xdraw+1,Ydraw);
      }
    if(startx<MX && starty<MY && !matrix[startx+1][starty+1].revealed &&!matrix[startx+1][starty+1].flag)
      {
      DrawTile(tile_0,Xdraw+1,Ydraw+1);
      }
    if(starty<MY && !matrix[startx][starty+1].revealed &&!matrix[startx][starty+1].flag)
      {
      DrawTile(tile_0,Xdraw,Ydraw+1);
      }
    if(startx>0 && starty<MY && !matrix[startx-1][starty+1].revealed &&!matrix[startx-1][starty+1].flag)
      {
      DrawTile(tile_0,Xdraw-1,Ydraw+1);
      }
    if(startx>0 && !matrix[startx-1][starty].revealed &&!matrix[startx-1][starty].flag)
      {
      DrawTile(tile_0,Xdraw-1,Ydraw);
      }
    if(startx>0 && starty>0 && !matrix[startx-1][starty-1].revealed &&!matrix[startx-1][starty-1].flag)
      {
      DrawTile(tile_0,Xdraw-1,Ydraw-1);
      }
}

//---------------------------------------------------------------------------
int TFHlavni::CountFlags(int startx, int starty)
{
  int MX=Xsize-1;
  int MY=Ysize-1;
  int counter=0;

  if(starty>0 && matrix[startx][starty-1].flag)
    {
    counter++;
    }
  if(startx<MX && starty>0 && matrix[startx+1][starty-1].flag)
    {
    counter++;
    }
  if(startx<MX && matrix[startx+1][starty].flag)
    {
    counter++;
    }
  if(startx<MX && starty<MY && matrix[startx+1][starty+1].flag)
    {
    counter++;
    }
  if(starty<MY && matrix[startx][starty+1].flag)
    {
    counter++;
    }
  if(startx>0 && starty<MY && matrix[startx-1][starty+1].flag)
    {
    counter++;
    }
  if(startx>0 && matrix[startx-1][starty].flag)
    {
    counter++;
    }
  if(startx>0 && starty>0 && matrix[startx-1][starty-1].flag)
    {
    counter++;
    }
 // ShowMessage(IntToStr(counter));
  return counter;
}

//---------------------------------------------------------------------------

void TFHlavni::KonecBoom()
{
  BKonec = true;
  OdhalVse();
}
//---------------------------------------------------------------------------
void TFHlavni::OdhalVse()
{
  TMain->Enabled = false;
  DrawTimer(num_dd,3);
  BKonec=true;

  for(int X=0;X<Xsize;X++)
   for(int Y=0;Y<Ysize;Y++)
    {
    if(!matrix[X][Y].bomb && matrix[X][Y].flag)
      {
      DrawTile(tile_wrong,X,Y);
      matrix[X][Y].revealed = true;
      matrix[X][Y].reveal = false;
      }
    if(!matrix[X][Y].revealed)
      {
      matrix[X][Y].revealed = true;
      matrix[X][Y].reveal = false;
      switch(matrix[X][Y].status)
        {
        case 0:DrawTile(tile_0,X,Y); break ;
        case 1:DrawTile(tile_1,X,Y); break ;
        case 2:DrawTile(tile_2,X,Y); break;
        case 3:DrawTile(tile_3,X,Y); break;
        case 4:DrawTile(tile_4,X,Y); break;
        case 5:DrawTile(tile_5,X,Y); break;
        case 6:DrawTile(tile_6,X,Y); break;
        case 7:DrawTile(tile_7,X,Y); break;
        case 8:DrawTile(tile_8,X,Y); break;
        } //switch
      if(matrix[X][Y].bomb)
        DrawTile(tile_bomb,X,Y);
      }//if m[x][y].revealed
    } //for Y
}
//---------------------------------------------------------------------------

void TFHlavni::DrawTimer(Graphics::TBitmap * bmp, int position)
{
  switch(position)
    {
    case 1:
      {
      ITimer->Canvas->Brush->Bitmap = bmp;
      ITimer->Canvas->FillRect(Rect(0,0,10,20));
      };break;
    case 2:
      {
      ITimer->Canvas->Brush->Bitmap = bmp;
      ITimer->Canvas->FillRect(Rect(10,0,20,20));
      };break;
    case 3:
      {
      ITimer->Canvas->Brush->Bitmap = bmp;
      ITimer->Canvas->FillRect(Rect(20,0,30,20));
      };break;
    case 4:
      {
      ITimer->Canvas->Brush->Bitmap = bmp;
      ITimer->Canvas->FillRect(Rect(30,0,40,20));
      };break;
    case 5:
      {
      ITimer->Canvas->Brush->Bitmap = bmp;
      ITimer->Canvas->FillRect(Rect(40,0,50,20));
      };break;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFHlavni::TMainTimer(TObject *Sender)
{
  if(Itimer[2]==-2)
    {
    DrawTimer(num_black,3);
    Itimer[2]=-3;
    }
    else
      {
      IStopky++;
      DrawTimer(num_dd,3);
      Itimer[2]=-2;
      ITimerChange();
      }
}
//---------------------------------------------------------------------------

void TFHlavni::DrawCounter(Graphics::TBitmap * bmp, int position)
{
  switch(position)
    {
    case 1:
      {
      ICounter->Canvas->Brush->Bitmap = bmp;
      ICounter->Canvas->FillRect(Rect(0,0,10,20));
      };break;
    case 2:
      {
      ICounter->Canvas->Brush->Bitmap = bmp;
      ICounter->Canvas->FillRect(Rect(10,0,20,20));
      };break;
    case 3:
      {
      ICounter->Canvas->Brush->Bitmap = bmp;
      ICounter->Canvas->FillRect(Rect(20,0,30,20));
      };break;
    } // switch position
}

//---------------------------------------------------------------------------
void __fastcall TFHlavni::MMVlastniClick(TObject *Sender)
{
  b_sum=IBombSummary;
  if(FVlastni->ShowModal()==mrOk)
    {
    int x = sirka;
    int y = vyska;
    int bomb_sum = b_sum;
    ClearMatrix();
    VytvorPlochu(x,y);
    Zaminovat(x,y,bomb_sum);
    SpocitatMiny(x,y);
    IBombSummary=BombSummary();
    NastavCounter(IBombSummary);
    VytvorBorder();
    SBStart->Tag=4;
    }
}
//---------------------------------------------------------------------------

int TFHlavni::BombSummary()
{
  int counter=0;
  for(int x=0;x<Xsize;x++)
    for(int y=0;y<Ysize;y++)
      if(matrix[x][y].bomb)
        counter++;
  return counter;
}

//---------------------------------------------------------------------------

bool TFHlavni::NastavCounter(int num)
{
  bool result=false;
  try
    {
    char ch[3];
    AnsiString v="000";
    if(num<10 && num>0)
      v="00"+ITS(num);
      else if(num<100 && num>0)
        v="0"+ITS(num);
        else if(num<0 && num>-10)
          {
          num*=-1;
          v="-0"+ITS(num);
          }
          else if(num<0 && num>-100)
            {
            v=ITS(num);
            }
            else if(num<-99)
              v="eee";
              else
                v=ITS(num);
    strcpy(ch,v.c_str());
    for(int i=0;i<=2;i++)
      {
      int I=i+1;
      switch(ch[i])
        {
        case '0': DrawCounter(num_0,I); break;
        case '1': DrawCounter(num_1,I); break;
        case '2': DrawCounter(num_2,I); break;
        case '3': DrawCounter(num_3,I); break;
        case '4': DrawCounter(num_4,I); break;
        case '5': DrawCounter(num_5,I); break;
        case '6': DrawCounter(num_6,I); break;
        case '7': DrawCounter(num_7,I); break;
        case '8': DrawCounter(num_8,I); break;
        case '9': DrawCounter(num_9,I); break;
        case 'e': DrawCounter(num_e,I); break;
        case '-': DrawCounter(num_minus,I); break;
        }
      }
    result=true;
    } //try
    catch (Exception &e)
      {
      for(int i=1;i<=3;i++)
        DrawCounter(num_e,i);
      }
  return result;
}
//---------------------------------------------------------------------------

bool TFHlavni::NastavTimer(AnsiString v)
{
  bool result=false;
  try
    {
    char ch[6];
    //SOME("v pred kontrolou="+v);
    int delka=v.Length();
    if(delka<5)
      for(int i=0;i<5;i++)
        {
        DrawTimer(num_e,i);
        return result;
        }
    strcpy(ch,v.c_str());
    //SOME("v po kontrole="+v);
    for(int i=0;i<=4;i++)
      {
      int I=i+1;
      switch(ch[i])
        {
        case ':': DrawTimer(num_dd,I);break;
        case '0': DrawTimer(num_0,I); break;
        case '1': DrawTimer(num_1,I); break;
        case '2': DrawTimer(num_2,I); break;
        case '3': DrawTimer(num_3,I); break;
        case '4': DrawTimer(num_4,I); break;
        case '5': DrawTimer(num_5,I); break;
        case '6': DrawTimer(num_6,I); break;
        case '7': DrawTimer(num_7,I); break;
        case '8': DrawTimer(num_8,I); break;
        case '9': DrawTimer(num_9,I); break;
        }
      }
    result=true;
    } //try
    catch (Exception &e)
      {
      for(int i=1;i<=5;i++)
        DrawCounter(num_e,i);
      }
  return result;
}

//---------------------------------------------------------------------------

void TFHlavni::ITimerChange()
{
  AnsiString AS,ASpred,ASza;
  int pred = IStopky/60;
  int za = IStopky%60;
  if(pred<10)
    ASpred=("0"+ITS(pred));
    else
      ASpred=ITS(pred);
  if(za<10)
    ASza=("0"+ITS(za));
    else
      ASza=ITS(za);
  AS=ASpred+":"+ASza;
  if(IStopky<0)
    AS="00:00";
  NastavTimer(AS);
}
//---------------------------------------------------------------------------

void TFHlavni::OkoliNahoru(int startx, int starty)
{
  int MX=Xsize-1;
  int MY=Ysize-1;
  int Xdraw=startx;
  int Ydraw=starty;
   if(starty>0 && !matrix[startx][starty-1].revealed &&  matrix[startx][starty-1].reveal && !matrix[startx][starty-1].flag)
      {
      DrawTile(tile_n,Xdraw,Ydraw-1);
      }
    if(startx<MX && starty>0 && !matrix[startx+1][starty-1].revealed && matrix[startx+1][starty-1].reveal && !matrix[startx+1][starty-1].flag)
      {
      DrawTile(tile_n,Xdraw+1,Ydraw-1);
      }
    if(startx<MX && !matrix[startx+1][starty].revealed && matrix[startx+1][starty].reveal && !matrix[startx+1][starty].flag)
      {
      DrawTile(tile_n,Xdraw+1,Ydraw);
      }
    if(startx<MX && starty<MY && !matrix[startx+1][starty+1].revealed && matrix[startx+1][starty+1].reveal && !matrix[startx+1][starty+1].flag)
      {
      DrawTile(tile_n,Xdraw+1,Ydraw+1);
      }
    if(starty<MY && !matrix[startx][starty+1].revealed && matrix[startx][starty+1].reveal && !matrix[startx][starty+1].flag)
      {
      DrawTile(tile_n,Xdraw,Ydraw+1);
      }
    if(startx>0 && starty<MY && !matrix[startx-1][starty+1].revealed && matrix[startx-1][starty+1].reveal && !matrix[startx-1][starty+1].flag)
      {
      DrawTile(tile_n,Xdraw-1,Ydraw+1);
      }
    if(startx>0 && !matrix[startx-1][starty].revealed && matrix[startx-1][starty].reveal && !matrix[startx-1][starty].flag)
      {
      DrawTile(tile_n,Xdraw-1,Ydraw);
      }
    if(startx>0 && starty>0 && !matrix[startx-1][starty-1].revealed &&!matrix[startx-1][starty-1].flag && !matrix[startx-1][starty-1].flag)
      {
      DrawTile(tile_n,Xdraw-1,Ydraw-1);
      }
}
//---------------------------------------------------------------------------

void TFHlavni::VytvorBorder()
{
  int pulka = (((Xsize*16)/2)+6);
  // posunuti komponent pri Xsize>12
  if(Xsize>12)
    {
    SBStart->Left = pulka-40;
    SBJednaZeDvou->Left = pulka-20;
    SBBet->Left = pulka;
    SBKonec->Left = pulka+20;
    ITimer->Left = (16*Xsize)-34;
    }
    else
      {
      SBStart->Left = 62;
      SBJednaZeDvou->Left = 82;
      SBBet->Left = 102;
      SBKonec->Left = 122;
      ITimer->Left = 158;
      }

  //W_NS_2
  delete IBorderW_NS_2;
  IBorderW_NS_2 = new TImage(FHlavni);
  IBorderW_NS_2->Visible = false;
  IBorderW_NS_2->Parent = FHlavni;
  IBorderW_NS_2->Left = 0;
  IBorderW_NS_2->Top = 52;
  IBorderW_NS_2->Width = 16;
  IBorderW_NS_2->Height = 16*Ysize;
  IBorderW_NS_2->Canvas->Brush->Bitmap = bor_W_NS;
  FillTileFull(IBorderW_NS_2);
  IBorderW_NS_2->Visible = true;


  // SW roh
  delete IBorderSW;
  IBorderSW = new TImage(FHlavni);
  IBorderSW->Visible = false;
  IBorderSW->Parent = FHlavni;
  IBorderSW->Left = 0;
  IBorderSW->Top = 52+(16*Ysize);
  IBorderSW->Width = 16;
  IBorderSW->Height = 16;
  IBorderSW->Canvas->Brush->Bitmap = bor_SW;
  FillTileFull(IBorderSW);
  IBorderSW->Visible = true;

  int LeftDist = CDefaultLeft;
  if(Xsize>12)
    LeftDist=(Xsize*16)+16;

  // N_EW
  delete IBorderN_EW;
  IBorderN_EW = new TImage(FHlavni);
  IBorderN_EW->Visible = false;
  IBorderN_EW->Parent = FHlavni;
  IBorderN_EW->Left = 16;
  IBorderN_EW->Top = 0;
  IBorderN_EW->Width = LeftDist-16;
  IBorderN_EW->Height = 16;
  IBorderN_EW->Canvas->Brush->Bitmap = bor_N_EW;
  FillTileFull(IBorderN_EW);
  IBorderN_EW->Visible = true;

  // SW roh
  delete IBorderNE;
  IBorderNE = new TImage(FHlavni);
  IBorderNE->Visible = false;
  IBorderNE->Parent = FHlavni;
  IBorderNE->Left = LeftDist;
  IBorderNE->Top = 0;
  IBorderNE->Width = 16;
  IBorderNE->Height = 16;
  IBorderNE->Canvas->Brush->Bitmap = bor_NE;
  FillTileFull(IBorderNE);
  IBorderNE->Visible = true;

  // E_NS_1
  delete IBorderE_NS_1;
  IBorderE_NS_1 = new TImage(FHlavni);
  IBorderE_NS_1->Visible = false;
  IBorderE_NS_1->Parent = FHlavni;
  IBorderE_NS_1->Left = LeftDist;
  IBorderE_NS_1->Top = 16;
  IBorderE_NS_1->Width = 16;
  IBorderE_NS_1->Height = 20;
  IBorderE_NS_1->Canvas->Brush->Bitmap = bor_E_NS;
  FillTileFull(IBorderE_NS_1);
  IBorderE_NS_1->Visible = true;

  // T_E
  delete IBorderT_E;
  IBorderT_E = new TImage(FHlavni);
  IBorderT_E->Visible = false;
  IBorderT_E->Parent = FHlavni;
  IBorderT_E->Left = LeftDist;
  IBorderT_E->Top = 36;
  IBorderT_E->Width = 16;
  IBorderT_E->Height = 16;
  IBorderT_E->Canvas->Brush->Bitmap = bor_T_E;
  FillTileFull(IBorderT_E);
  IBorderT_E->Visible = true;

  //E_NS_2
  delete IBorderE_NS_2;
  IBorderE_NS_2 = new TImage(FHlavni);
  IBorderE_NS_2->Visible = false;
  IBorderE_NS_2->Parent = FHlavni;
  IBorderE_NS_2->Left = LeftDist;
  IBorderE_NS_2->Top = 52;
  IBorderE_NS_2->Width = 16;
  IBorderE_NS_2->Height = 16*Ysize;
  IBorderE_NS_2->Canvas->Brush->Bitmap = bor_E_NS;
  FillTileFull(IBorderE_NS_2);
  IBorderE_NS_2->Visible = true;

  // SE roh
  delete IBorderSE;
  IBorderSE = new TImage(FHlavni);
  IBorderSE->Visible = false;
  IBorderSE->Parent = FHlavni;
  IBorderSE->Left = LeftDist;
  IBorderSE->Top = 52+(16*Ysize);
  IBorderSE->Width = 16;
  IBorderSE->Height = 16;
  IBorderSE->Canvas->Brush->Bitmap = bor_SE;
  FillTileFull(IBorderSE);
  IBorderSE->Visible = true;

  // S_EW
  delete IBorderS_EW;
  IBorderS_EW = new TImage(FHlavni);
  IBorderS_EW->Visible = false;
  IBorderS_EW->Parent = FHlavni;
  IBorderS_EW->Left = 16;
  IBorderS_EW->Top = 52+(16*Ysize);
  IBorderS_EW->Width = LeftDist-16;
  IBorderS_EW->Height = 16;
  IBorderS_EW->Canvas->Brush->Bitmap = bor_S_EW;
  FillTileFull(IBorderS_EW);
  IBorderS_EW->Visible = true;

  // M_EW
  delete IBorderM_EW;
  IBorderM_EW = new TImage(FHlavni);
  IBorderM_EW->Visible = false;
  IBorderM_EW->Parent = FHlavni;
  IBorderM_EW->Left = 16;
  IBorderM_EW->Top = 36;
  IBorderM_EW->Width = LeftDist-16;
  IBorderM_EW->Height = 16;
  IBorderM_EW->Canvas->Brush->Bitmap = bor_M_EW;
  FillTileFull(IBorderM_EW);
  IBorderM_EW->Visible = true;

  // Net_1
  delete INet_1;
  INet_1 = new TImage(FHlavni);
  INet_1->Visible = false;
  INet_1->Parent = FHlavni;
  INet_1->Left = 46;
  INet_1->Top = 16;
  INet_1->Width = (SBStart->Left-INet_1->Left);
  INet_1->Height = 20;
  INet_1->Canvas->Brush->Bitmap = tile_net;
  FillTileFull(INet_1);
  INet_1->Visible = true;

  // Net_2
  delete INet_2;
  INet_2 = new TImage(FHlavni);
  INet_2->Visible = false;
  INet_2->Parent = FHlavni;
  INet_2->Left = SBKonec->Left+20;
  INet_2->Top = 16;
  INet_2->Width = (ITimer->Left - INet_2->Left);
  INet_2->Height = 20;
  INet_2->Canvas->Brush->Bitmap = tile_net;
  FillTileFull(INet_2);
  INet_2->Visible = true;

  // Net_3 pri mensi plose
  delete INet_3;
  INet_3 = new TImage(FHlavni);
  INet_3->Visible = false;
  INet_3->Parent = FHlavni;
  if(Xsize<13)
    {
    INet_3->Left = 16+(Xsize*16);
    INet_3->Top = 52;
    INet_3->Width = 16*(12-Xsize);
    INet_3->Height = 16*Ysize;
    INet_3->Canvas->Brush->Bitmap = tile_net16x16;
    FillTileFull(INet_3);
    INet_3->Visible = true;
    }
}

//---------------------------------------------------------------------------

void TFHlavni::FillTileFull(TImage * img)
{
  img->Canvas->FillRect(Rect(0,0,img->Width,img->Height));
}
//---------------------------------------------------------------------------

void TFHlavni::WinEndQuery()
{
  //spocitani neodhalenych policek, kdyz = BombSummary znamena to vyhru
  int IBombs = BombSummary();
  int IUnrevealed=0;
  for(int x=0;x<Xsize;x++)
    for(int y=0;y<Ysize;y++)
      if(!matrix[x][y].revealed)
        IUnrevealed++;


  if(IUnrevealed==IBombs)
    {
    TMain->Enabled = false;
    if(IJtag==0)
      SOME("Vyhrál/a jsi!");
    for(int x=0;x<Xsize;x++)
      for(int y=0;y<Ysize;y++)
        if(matrix[x][y].bomb && (matrix[x][y].bmp==tile_bet))
          {
          SOME("JO! Trefil/a jsi se! Získáváš bonus 10 sekund !!!");
          IStopky-=10;
          }
    ITimerChange();
    OdhalVse();
    DrawTimer(num_dd,3);

    if(IJtag>0)
      MMJana->Click();

    switch(SBStart->Tag)
      {
      case 1:
        {
        if(IStopky<SData.ZacatecnikRekord.cas)
          {
          AnsiString jmeno = SData.ZacatecnikRekord.jmeno;
          InputQuery("Jméno rekordmana","Vytvoøil/a jsi nový rekord v zaèáteènících !"
            "Vlož své jméno, pro budoucí pokolení:",jmeno);
          SData.ZacatecnikRekord.cas = IStopky;
          strcpy(SData.ZacatecnikRekord.jmeno,jmeno.c_str());
          SData.ZacatecnikRekord.jmeno[20]='\0';
          FILE *fw;
          if((fw = fopen("start.dat","wb"))==NULL)
            {
            ShowMessage("Chyba pøi ukládání do start.dat !!!");
            return;
            }
          fwrite(&SData,sizeof(StartData),1,fw);
          fclose(fw);
          } //if <
        };break; //case1
        case 2:
        {
        if(IStopky<SData.PokrocilyRekord.cas)
          {
          AnsiString jmeno = SData.PokrocilyRekord.jmeno;
          InputQuery("Jméno rekordmana","Vytvoøil/a jsi nový rekord v pokroèilých !"
            "Vlož své jméno, pro budoucí pokolení:",jmeno);
          strcpy(SData.PokrocilyRekord.jmeno,jmeno.c_str());
          SData.PokrocilyRekord.cas = IStopky;
          SData.PokrocilyRekord.jmeno[20]='\0';
          FILE *fw;
          if((fw = fopen("start.dat","wb"))==NULL)
            {
            ShowMessage("Chyba pøi ukládání do start.dat !!!");
            return;
            }
          fwrite(&SData,sizeof(StartData),1,fw);
          fclose(fw);
          }
        /*case2*/};break;
        case 3:
          {
          if(IStopky<SData.ExpertRekord.cas)
            {
            AnsiString jmeno = SData.ExpertRekord.jmeno;
            InputQuery("Jméno rekordmana","Vytvoøil/a jsi nový rekord v expertech !"
            "Vlož své jméno, pro budoucí pokolení:",jmeno);
            SData.ExpertRekord.cas = IStopky;
            strcpy(SData.ExpertRekord.jmeno,jmeno.c_str());
            SData.ExpertRekord.jmeno[20]='\0';
            FILE *fw;
            if((fw = fopen("start.dat","wb"))==NULL)
              {
              ShowMessage("Chyba pøi ukládání do start.dat !!!");
              return;
              }
            fwrite(&SData,sizeof(StartData),1,fw);
            fclose(fw);
            }
          /*case3*/};break;
      } //switch SBStart->Tag
    } // IUnrevealed==IBombs

}
//---------------------------------------------------------------------------
void __fastcall TFHlavni::SBStartClick(TObject *Sender)
{
  BKonec=false;
  switch(TAG)
    {
    case 0:
    case 1: MMZacatecnik->Click(); break;
    case 2: MMPokrocily->Click(); break;
    case 3: MMExpert->Click(); break;
    case 4: MMVlastni->Click(); break;
    case 5: MMRestart->Click(); break;
    }
}
//---------------------------------------------------------------------------



void __fastcall TFHlavni::MMRekordResetClick(TObject *Sender)
{
  if(MessageDlg(("Opravdu chceš nenávratnì vynulovat všechny rekordy ?"),mtConfirmation,
     TMsgDlgButtons() << mbOK << mbCancel, 0) == mrOk)
     {
     SData.ZacatecnikRekord.cas=999;
     strcpy(SData.ZacatecnikRekord.jmeno,"God");
     SData.PokrocilyRekord.cas=999;
     strcpy(SData.PokrocilyRekord.jmeno,"Satan");
     SData.ExpertRekord.cas=999;
     strcpy(SData.ExpertRekord.jmeno,"Bill G");
     FILE *fw;
     if((fw = fopen("start.dat","wb"))==NULL)
       {
       ShowMessage("Chyba pøi ukládání do start.dat !!!");
       return;
       }
     fwrite(&SData,sizeof(StartData),1,fw);
     fclose(fw);
     }
}
//---------------------------------------------------------------------------

void __fastcall TFHlavni::MMRekordClick(TObject *Sender)
{
  FRekord->ShowModal();        
}
//---------------------------------------------------------------------------

void __fastcall TFHlavni::MMJednaDvaClick(TObject *Sender)
{
  if(Sender->ClassNameIs("TMenuItem"))
    SBJednaZeDvou->Down=!SBJednaZeDvou->Down;
  if(SBJednaZeDvou->Down)
    SBBet->Down = false;

  JZD.Reset();
  for(int x=0;x<Xsize;x++)
    for(int y=0;y<Ysize;y++)
      if(matrix[x][y].bmp==tile_one || matrix[x][y].bmp==tile_two)
        DrawTile(tile_n,x,y);
}
//---------------------------------------------------------------------------

void __fastcall TFHlavni::MMZnackyClick(TObject *Sender)
{
  !MMZnacky->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TFHlavni::MMBetClick(TObject *Sender)
{
  if(Sender->ClassNameIs("TMenuItem"))
    SBBet->Down=!SBBet->Down;
  if(SBBet->Down)
    {
    SBJednaZeDvou->Down = false;
    JZD.Reset();
    for(int x=0;x<Xsize;x++)
      for(int y=0;y<Ysize;y++)
        if(matrix[x][y].bmp==tile_one || matrix[x][y].bmp==tile_two)
          DrawTile(tile_n,x,y);
    }

}
//---------------------------------------------------------------------------

bool TFHlavni::OkoliNeodhaleno(int startx, int starty)
{
  bool result=true;
  int MX=Xsize-1;
  int MY=Ysize-1;

  if(starty>0 && matrix[startx][starty-1].revealed)
    result=false;
  if(startx<MX && starty>0 && matrix[startx+1][starty-1].revealed)
    result=false;
  if(startx<MX && matrix[startx+1][starty].revealed)
    result=false;
  if(startx<MX && starty<MY && matrix[startx+1][starty+1].revealed)
    result=false;
  if(starty<MY && matrix[startx][starty+1].revealed)
    result=false;
  if(startx>0 && starty<MY && matrix[startx-1][starty+1].revealed)
    result=false;
  if(startx>0 && matrix[startx-1][starty].revealed)
    result=false;
  if(startx>0 && starty>0 && matrix[startx-1][starty-1].revealed)
    result=false;

  return result;
}
//---------------------------------------------------------------------------

int TFHlavni::CountBet()
{
  int counter=0;

  for(int x=0;x<Xsize;x++)
    for(int y=0;y<Ysize;y++)
      if(matrix[x][y].bmp==tile_bet)
        counter++;

  return counter;
}
//---------------------------------------------------------------------------

void __fastcall TFHlavni::MMNahratClick(TObject *Sender)
{
  for(int i=0;i<MaxX;i++)
    for(int y=0;y<MaxY;y++)
      Matrix.matrix[i][y]=false;
  Matrix.Xsize=1;
  Matrix.Ysize=1;

  FILE *fr;
  char File[100];
  if(LD->Execute())
    {
    LoadMap(LD->FileName);
    }
}
//---------------------------------------------------------------------------

void __fastcall TFHlavni::MMJanaClick(TObject *Sender)
{
  if(IJtag>0)
    {
    switch(IJtag)
      {
      case 1:
        {
        SOME("Ahoj Jani.");
        LoadMap("maps\\18.map");
        Memo->Font->Color = clBlue;
        Memo->Lines->Insert(1,"Ahoj Jani...");
        IL1->GetBitmap(14,tile_bomb);
        IJtag=2;
        }
        ;break;
      case 2:
        {
        SOME("Všechno nejlepší k narozeninám.");
        LoadMap("maps\\darecky.map");
        Memo->Font->Color = clGreen;
        Memo->Lines->Insert(2,"Všechno nejlepší k narozeninám.");
        IL1->GetBitmap(20,tile_bomb);
        IJtag=3;
        }
        ;break;
      case 3:
        {
        SOME(" Doufám, že dostaneš spoustu skvìlých dáreèkù...");
        LoadMap("maps\\oslava.map");
        Memo->Font->Color = clGray;
        Memo->Lines->Insert(3," Doufám, že dostaneš spoustu skvìlých dáreèkù...");
        IL1->GetBitmap(21,tile_bomb);
        IJtag=4;
        }
        ;break;
      case 4:
        {
        SOME(" ... bude Ti dobøe...");
        LoadMap("maps\\pratele.map");
        Memo->Font->Color = clGreen;
        Memo->Lines->Insert(4,"... bude Ti dobøe...");
        IJtag=5;
        }
        ;break;
      case 5:
        {
        SOME(" ... i s Tvýmy pøáteli...");
        LoadMap("maps\\palec.map");
        Memo->Font->Color = clBlue;
        Memo->Lines->Insert(5," ... i s Tvýmy pøáteli...");
        IL1->GetBitmap(11,tile_bomb);
        IJtag=6;
        }
        ;break;
      case 6:
        {
        SOME(" ... ale hlavnì vìz, že i když Ti bude hùr...");
        LoadMap("maps\\konec.map");
        Memo->Font->Color = clFuchsia;
        Memo->Lines->Insert(6," ... ale hlavnì vìz, že i když Ti bude hùr...");
        IL1->GetBitmap(19,tile_bomb);
        IJtag=7;
        }
        ;break;
      case 7:
        {
        SOME(" ... že tu vždy budou lidé, kteøí Tì milují.");
        MMRestart->Click();
        Memo->Font->Color = clRed;
        Memo->Lines->Insert(7," ... že tu vždy budou lidé, kteøí Tì milují.");
        IL1->GetBitmap(10,tile_bomb);
        IJtag=0;
        SOME("Všechno nejlepší Jani.");
        }
        ;break;
      }
    }
    else
      {
      LoadMap("maps\\AHOJ.map");
      Memo->Left=16;
      Memo->Height = 50;
      Memo->Width=30*16;
      Memo->Visible=true;
      Memo->Lines->Insert(0,"Toto je dárek pro Tebe. Bav se :o)");
      IL1->GetBitmap(20,tile_bomb);
      IJtag=1;
      }
}
//---------------------------------------------------------------------------

void TFHlavni::CHEATwin()
{
  for(int x=0;x<sirka;x++)
    for(int y=0;y<vyska;y++)
      if(!matrix[x][y].bomb)
        OdhalPolicko(x,y);      
}
//---------------------------------------------------------------------------

void __fastcall TFHlavni::MMCHEATVyhraClick(TObject *Sender)
{
  CHEATwin();
  WinEndQuery();
}
//---------------------------------------------------------------------------

void TFHlavni::LoadMap(AnsiString File)
{
  for(int x=0;x<MaxX;x++)
    for(int y=0;y<MaxY;y++)
      Matrix.matrix[x][y]=false;
  Matrix.Xsize=1;
  Matrix.Ysize=1;

  FILE *fr;
  char CHFile[100];
  strcpy(CHFile,File.c_str());
  if((fr = fopen(CHFile, "rb"))==NULL)
    {
    ShowMessage("Nìco je špatnì");
    fclose(fr);
    return;
    }
    else
      {
      fread(&Matrix,sizeof(Ematrix),1,fr);

      VytvorPlochu(Matrix.Xsize,Matrix.Ysize);
      for(int i=0;i<Matrix.Xsize;i++)
        for(int y=0;y<Matrix.Ysize;y++)
          {
          matrix[i][y].bomb = Matrix.matrix[i][y];
          }
      SpocitatMiny(Matrix.Xsize,Matrix.Ysize);
      IBombSummary=BombSummary();
      NastavCounter(IBombSummary);
      VytvorBorder();
      SBStart->Tag=5;
      fclose(fr);
      }
}
//---------------------------------------------------------------------------

void __fastcall TFHlavni::OProgramu2Click(TObject *Sender)
{
  FAbout->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFHlavni::Help1Click(TObject *Sender)
{
  FHelp->ShowModal();        
}
//---------------------------------------------------------------------------

void __fastcall TFHlavni::FormKeyPress(TObject *Sender, char &Key)
{
 if(Key=='j')
   {
   MMJana->Visible=true;
   MMShowBoolean->Visible=true;
   MMCHEATVyhra->Visible=true;
   }
   else
     {
     MMJana->Visible=false;
     MMShowBoolean->Visible=false;
     MMCHEATVyhra->Visible=false;
     }
}
//---------------------------------------------------------------------------

void __fastcall TFHlavni::MMFlagClick(TObject *Sender)
{
  IL1->GetBitmap(13,tile_flag);
}
//---------------------------------------------------------------------------

void __fastcall TFHlavni::Smajlk1Click(TObject *Sender)
{
  IL1->GetBitmap(21,tile_flag);
}
//---------------------------------------------------------------------------

void __fastcall TFHlavni::srdce1Click(TObject *Sender)
{
  IL1->GetBitmap(19,tile_flag);
}
//---------------------------------------------------------------------------

void __fastcall TFHlavni::Dreek1Click(TObject *Sender)
{
  IL1->GetBitmap(20,tile_flag);
}
//---------------------------------------------------------------------------


