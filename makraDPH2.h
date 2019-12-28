#ifndef H_MAKRA
#define H_MAKRA
//makra ruzne
#define MODT {Modifikovano = true; \
              StatusBar->Panels->Items[1]->Text = "Zmeneno";}
#define MODF {Modifikovano = false; \
              StatusBar->Panels->Items[1]->Text = "Nezmeneno";}

//makra sendru komponent
#define BUTTON_S ((TButton *)(Sender))
#define RADIOGRP_S ((TRadioGroup *)(Sender))
#define SPEEDBTN_S ((TSpeedButton *)(Sender))
#define UPDOWN_S ((TUpDown *)(Sender))
#define EDIT_S ((TEdit *)(Sender))
#define CHECKBOX_S ((TCheckBox *)(Sender))
#define SPINB_S ((TCSpinButton *)(Sender))

//makra pro zkratky
#define TAG (((TComponent*)(Sender))->Tag)
#define FHLAVNI FHlavni->Components[i]
#define SBVYP_EDIT ((TEdit*)SBVypocetDPH->Components[i])
#define SBVYP (frmHlavni->SBVypocetDPH->Components[i])
#define FHLAVNI_I ((TImage*)FHLAVNI)
#define FRMHLAVNI_EDIT ((TEdit*)FRMHLAVNI)
#define FRMHLAVNI_RG ((TRadioGroup*)FRMHLAVNI)
#define FRMHLAVNI_UD ((TUpDown*)FRMHLAVNI)
#define FRMHLAVNI_SPEEDB ((TSpeedButton*)FRMHLAVNI)
#define FRMHLAVNI_CB ((TCheckBox*)FRMHLAVNI)
#define FRMHLAVNI_SPINB ((TCSpinButton*)FRMHLAVNI)
//---------------------------------------------------------------------------
#endif
