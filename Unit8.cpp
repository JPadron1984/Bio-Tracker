// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit8.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;

// ---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner) : TForm(Owner) {


Memo1->Lines->Clear();
Memo2->Lines->Clear();
Memo3->Lines->Clear();
Edit1->Text="";
Edit2->Text="";

}
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

void __fastcall TForm8::Button1Click(TObject *Sender) {

	fstream fin;

	if (OpenDialog1->Execute()) {

		AnsiString Fila = OpenDialog1->FileName;
		char * filename = Fila.c_str();
		fin.open(filename);
		fin >> n;

		datosx = new float[n];
		datosy = new float[n];

		for (int i = 0; i < n; i++) {

			fin >> datosx[i];
			fin >> datosy[i];

			Memo1->Lines->Add(datosx[i]);
			Memo2->Lines->Add(datosy[i]);
			}
		fin.close();
	}

	R = Bevel1->BoundsRect;

    distancia (datosx,datosy,n);


	Graficar(datosx, datosy, n);

	Edit1->Text= distanciat (datosx,datosy,n);
	Edit2->Text= velocidad (datosx,datosy,n);



}

// ---------------------------------------------------------------------------
float TForm8::fminimo(float *lista, int k) { // Funcion que ubica el valor minimo de una lista

	float min = lista[0];

	for (int i = 0; i < k; i++) {
		if (lista[i] < min) {
			min = lista[i];
		}

	}
	return min;
}

// ---------------------------------------------------------------------------
float TForm8::fmaximo(float *lista, int k) { // Funcion que ubica el valor maximo de una lista

	float max = lista[0];

	for (int i = 0; i < k; i++) {
		if (lista[i] > max) {
			max = lista[i];
		}

	}
	return max;
}

// ---------------------------------------------------------------------------
float TForm8::velocidad (float *dato1,float *dato2,int k){

float vel=0;
float *hipo;
hipo=new float [100];
float dist=0;


	for (int i = 0; i < k-1; i++) {
		hipo[i]=sqrt(pow(dato1[i+1]-dato1[i],2)+pow(dato2[i+1]-dato2[i],2));

	}

vel=(fmaximo(hipo,k))/((86400)/k);

return vel;

}


// ---------------------------------------------------------------------------
void TForm8::distancia(float *dato1,float *dato2,int k){

float dis=0;
float hip=0;

distot=0;

		for (int i= 0; i <k-1; i++) {

			dis=0;
			hip=(pow(dato1[i+1]-dato1[i],2)+pow(dato2[i+1]-dato2[i],2));
			distot=distot+hip;
			dis=dis+hip;

			Memo3->Lines->Add(dis);

		}
}
// ---------------------------------------------------------------------------
float TForm8::distanciat(float *dato1,float *dato2,int k){

float hip=0;

distot=0;

		for (int i= 0; i <k-1; i++) {


			hip=(pow(dato1[i+1]-dato1[i],2)+pow(dato2[i+1]-dato2[i],2));
			distot=distot+hip;


		}
return distot;
}
// ---------------------------------------------------------------------------
void TForm8::Graficar(float * dato1, float * dato2, int k) {

	int y1, y2, x1, x2, escY, escX, xoffset, yoffset;
	int top, left, bottom, right;
	int top1, left1, bottom1, right1;


	Canvas->Brush->Color = clGreen; // color de pluma
	Canvas->FillRect(R); // rellenar en tamaño y posicion en relacion en R



	W = R.Width() / 2; // ancho del bevel1
	H = R.Height(); // alto bevel1

	escX = k * 1.5; // escala en x en funcion de la cantidad de valores de la lista
	escY = fmaximo(dato2, k) * 1.2; // escala en y en funcion del valor mas alto en la lista

	xoffset = R.Left; // alineamiento en eje x
	yoffset = R.Top + H; // elineamiento en eje y

	for (int i = 0; i < k - 1; i++) {

		y1 = (dato2[i] * H) / escY; // datos[i]"valor de lista"*H"alto medio del bevel"
		y2 = (dato2[i + 1] * H) / escY; // datos[i+1]"valor siguiente de lista"
		x1 = (dato1[i] * W) / escX; // i"posicion en x"*(W/2)"punto medio del bevel"
		x2 = (dato1[i + 1] * W) / escX; // valor en y de la linea

		y1 = yoffset - y1;
		y2 = yoffset - y2;
		x1 = x1 + xoffset;
		x2 = x2 + xoffset;

		left1 = x1 - 3;
		top1 = y1 - 3;
		right1 = x1 + 3;
		bottom1 = y1 + 3;

		left = x2 - 3;
		top = y2 - 3;
		right = x2 + 3;
		bottom = y2 + 3;



        Canvas->Pen->Style = psSolid;
		Canvas->Pen->Width = 4;
		Canvas->Pen->Color = clRed;

		Canvas->Ellipse(left1, top1, right1, bottom1);
		Canvas->Ellipse(left, top, right, bottom);

		Canvas->Pen->Style = psDot;
		Canvas->Pen->Width = 1;
		Canvas->Pen->Color = clWhite;

		Canvas->MoveTo(x1, y1);
		Canvas->LineTo(x2, y2);

	}
}

// ---------------------------------------------------------------------------
