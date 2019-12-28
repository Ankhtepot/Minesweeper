//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "u1.h"
#include "structs.h"
#include "uEditor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TFEditor *FEditor;
//---------------------------------------------------------------------------
  Ematrix Matrix;

  extern int sirka;
  extern int vyska;
  extern int b_sum;
  extern tile matrix[MaxX][MaxY];
  extern Graphics::TBitmap * tile_n;
  extern Graphics::TBitmap * tile_bomb;
//---------------------------------------------------------------------------
__fastcall TFEditor::TFEditor(TComponent* Owner)
        : TForm(Owner)
{
  work.workX = 80;
  work.workY = 80;
}
//---------------------------------------------------------------------------

void __fastcall TFEditor::ImgPlochaMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  int matrixX = X/16;
  int matrixY = Y/16;
  if(SBBomb->Down && Button==mbLeft)
    {
    int drawX = 16*(X/16);
    int drawY = 16*(Y/16);
    if(X <= sirka*16 && Y <= vyska*16 && !Matrix.matrix[matrixX][matrixY])
      {
      Matrix.matrix[matrixX][matrixY] = true;
      DrawTile(tile_bomb,drawX,drawY);
      Matrix.sum_bomb++;
      ESum_bomb->Text = IntToStr(Matrix.sum_bomb);
      }
    }
    else
      if(Matrix.matrix[matrixX][matrixY])
        {
        Matrix.matrix[matrixX][matrixY] = false;
        int drawX = 16*(X/16);
        int drawY = 16*(Y/16);
        if(X <= sirka*16 && Y <= vyska*16)
          DrawTile(tile_n,drawX,drawY);
        if(Matrix.sum_bomb>0)
          Matrix.sum_bomb--;
        ESum_bomb->Text = IntToStr(Matrix.sum_bomb);
        }  //if

}
//---------------------------------------------------------------------------


void TFEditor::DrawTile(Graphics::TBitmap * bmp, int X, int Y)
{
  ImgPlocha->Canvas->Brush->Bitmap = bmp;
  ImgPlocha->Canvas->FillRect(Rect(X,Y,X+16,Y+16));
}
//---------------------------------------------------------------------------

void __fastcall TFEditor::FormActivate(TObject *Sender)
{
  ImgPlocha->Canvas->Brush->Color = clBtnFace;
  ImgPlocha->Canvas->FillRect(Rect(0,0,ImgPlocha->Width,ImgPlocha->Height));
  ESirka->Text = IntToStr(sirka);
  EVyska->Text = IntToStr(vyska);
  ESum_bomb->Text = IntToStr(b_sum);
  Matrix.sum_bomb = b_sum;
  Matrix.Xsize = sirka;
  Matrix.Ysize = vyska;
  SBBomb->Down = true;
  FillImg();
  for(int x=0;x<MaxX;x++)
    for(int y=0;y<MaxY;y++)
      Matrix.matrix[x][y]=false;
  for(int x=0;x<sirka;x++)
    for(int y=0;y<vyska;y++)
      if(matrix[x][y].bomb)
        {
        DrawTile(tile_bomb,x*16,y*16);
        Matrix.matrix[x][y]=true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFEditor::BNavratClick(TObject *Sender)
{
  //ShowMessage(Matrix.Xsize);
  FEditor->Close();
  FHlavni->Show();        
}
//---------------------------------------------------------------------------

void __fastcall TFEditor::BResetClick(TObject *Sender)
{
  for(int i=0;i<MaxX;i++)
    for(int y=0;y<MaxY;y++)
      Matrix.matrix[i][y] = false;
  FillImg();
  Matrix.sum_bomb = 0;
  ESum_bomb->Text = "0";
}
//---------------------------------------------------------------------------

void TFEditor::FillImg(void)
{
 // ShowMessage("Sirka="+IntToStr(ImgPlocha->Width)+" Vyska="+IntToStr(ImgPlocha->Height));
  ImgPlocha->Canvas->Brush->Bitmap = tile_n;
  ImgPlocha->Canvas->FillRect(Rect(0,0,sirka*16,vyska*16));
}
//---------------------------------------------------------------------------



void __fastcall TFEditor::CSpinButton1UpClick(TObject *Sender)
{
  if(sirka < MaxX)
    {
    int TempX = sirka*16;
    sirka++;
    Matrix.Xsize++;
    ESirka->Text = IntToStr((StrToInt(ESirka->Text)+1));
    ImgPlocha->Canvas->Brush->Bitmap = tile_n;
    ImgPlocha->Canvas->FillRect(Rect(TempX,0,sirka*16,vyska*16));
    }
}
//---------------------------------------------------------------------------

void __fastcall TFEditor::CSpinButton1DownClick(TObject *Sender)
{
  if(sirka > 0)
    {
    int TempX = sirka*16;
    for(int i=0;i<MaxY;i++)
      Matrix.matrix[sirka-1][i]=false;
    sirka--;
    Matrix.Xsize--;
    ESirka->Text = IntToStr((StrToInt(ESirka->Text)-1));
    ImgPlocha->Canvas->Brush->Color = clBtnFace;
    ImgPlocha->Canvas->FillRect(Rect(TempX,0,sirka*16,vyska*16));
    ESum_bomb->Text = IntToStr(BSummary());
    Matrix.sum_bomb = BSummary();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFEditor::FormCreate(TObject *Sender)
{
  ImgPlocha->Canvas->Brush->Color = clBtnFace;
  ImgPlocha->Canvas->FillRect(Rect(0,0,ImgPlocha->Width,ImgPlocha->Height));
}
//---------------------------------------------------------------------------


void __fastcall TFEditor::CSpinButton2DownClick(TObject *Sender)
{
  if(vyska > 0)
    {
    int TempY = vyska*16;
    for(int i=0;i<MaxX;i++)
      Matrix.matrix[i][vyska-1]=false;
    vyska--;
    Matrix.Ysize--;
    EVyska->Text = IntToStr((StrToInt(EVyska->Text)-1));
    ImgPlocha->Canvas->Brush->Color = clBtnFace;
    ImgPlocha->Canvas->FillRect(Rect(0,TempY,sirka*16,vyska*16));
    ESum_bomb->Text = IntToStr(BSummary());
    Matrix.sum_bomb = BSummary();
    for(int i=0;i<MaxX;i++)
      Matrix.matrix[i][vyska]=false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFEditor::CSpinButton2UpClick(TObject *Sender)
{
  if(vyska < MaxY)
    {
    int TempY = vyska*16;
    vyska++;
    Matrix.Ysize++;
    EVyska->Text = IntToStr((StrToInt(EVyska->Text)+1));
    ImgPlocha->Canvas->Brush->Bitmap = tile_n;
    ImgPlocha->Canvas->FillRect(Rect(0,TempY,sirka*16,vyska*16));
    }
}
//---------------------------------------------------------------------------


void __fastcall TFEditor::BShowClick(TObject *Sender)
{
  AnsiString * Lines = new AnsiString[Matrix.Ysize];
  AnsiString LinesFinal;
  for(int i=0;i<vyska;i++)
    {
    Lines[i] = FillLine(i);
    LinesFinal += Lines[i];
    }
  ShowMessage(LinesFinal);

}
//---------------------------------------------------------------------------

AnsiString TFEditor::FillLine(int linenumber)
{
  AnsiString result = "";
  for(int i=0;i<sirka;i++)
    if(Matrix.matrix[i][linenumber])
      result += "1";
      else result += "0";
  result += "\n";
  return result;
}
//---------------------------------------------------------------------------

void __fastcall TFEditor::SBBombClick(TObject *Sender)
{
 /* SBBomb->Down = true;
  SBNone->Down = false;*/
}
//---------------------------------------------------------------------------


void __fastcall TFEditor::ImgPlochaMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  int matrixX = X/16;
  int matrixY = Y/16;

  if(Matrix.matrix[matrixX][matrixY] && Button==mbRight)
        {
        Matrix.matrix[matrixX][matrixY] = false;
        int drawX = 16*(X/16);
        int drawY = 16*(Y/16);
        if(X <= sirka*16 && Y <= vyska*16)
          DrawTile(tile_n,drawX,drawY);
        if(Matrix.sum_bomb>0)
          Matrix.sum_bomb--;
        ESum_bomb->Text = IntToStr(Matrix.sum_bomb);
        }
}
//---------------------------------------------------------------------------

int TFEditor::BSummary()
{
  int counter=0;
  for(int x=0;x<sirka;x++)
    for(int y=0;y<vyska;y++)
      if(Matrix.matrix[x][y])
        counter++;
  return counter;
}
//---------------------------------------------------------------------------

void __fastcall TFEditor::BLoadClick(TObject *Sender)
{
  FILE *fr;
  char File[100];
  if(LD->Execute())
    {
    strcpy(File,LD->FileName.c_str());
    if((fr = fopen(File, "rb"))==NULL)
      {
      ShowMessage("Nìco je špatnì");
      return;
      }
      else
        {
        fread(&Matrix,sizeof(Ematrix),1,fr);
        }
    fclose(fr);
    }
}
//---------------------------------------------------------------------------

void __fastcall TFEditor::BSaveClick(TObject *Sender)
{
  FILE *fw;
  char File[100];
  if(SD->Execute())
    {
    strcpy(File, SD->FileName.c_str());
    if((fw =fopen(File, "wb"))==NULL)
      {
      ShowMessage("Nìco je špatnì");
      return;
      }
      else
        {
        fwrite(&Matrix,sizeof(Ematrix),1,fw);
        }
    fclose(fw);
    }
}
//---------------------------------------------------------------------------


