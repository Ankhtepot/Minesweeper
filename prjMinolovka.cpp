//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("u1.cpp", FHlavni);
USEFORM("uEditor.cpp", FEditor);
USEFORM("uVlastni.cpp", FVlastni);
USEFORM("uRekord.cpp", FRekord);
USEFORM("uAbout.cpp", FAbout);
USEFORM("uHelp.cpp", FHelp);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "Minolovka";
                 Application->CreateForm(__classid(TFHlavni), &FHlavni);
                 Application->CreateForm(__classid(TFEditor), &FEditor);
                 Application->CreateForm(__classid(TFVlastni), &FVlastni);
                 Application->CreateForm(__classid(TFRekord), &FRekord);
                 Application->CreateForm(__classid(TFAbout), &FAbout);
                 Application->CreateForm(__classid(TFHelp), &FHelp);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
