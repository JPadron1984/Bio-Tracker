//---------------------------------------------------------------------------

#ifndef Unit8H
#define Unit8H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <fstream.h>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <math.h>

//---------------------------------------------------------------------------
class TForm8 : public TForm
{
__published:	// IDE-managed Components
	TBevel *Bevel1;
	TButton *Button1;
	TOpenDialog *OpenDialog1;
	TMemo *Memo1;
	TMemo *Memo2;
	TMemo *Memo3;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *Edit1;
	TEdit *Edit2;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations

int W,H,n;

float distot;

float *datosy;
float *datosx;

void Areagrafica();
void Graficar (float * dato1,float *dato2,int k);

TRect R;

float fmaximo (float *lista,int k);
float fminimo (float *lista,int k);
float distanciat(float *dato1,float *dato2,int k);

float velocidad (float *dato1,float *dato2,int k);

void distancia (float *dato1,float *dato2,int k);



	__fastcall TForm8(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm8 *Form8;
//---------------------------------------------------------------------------
#endif
