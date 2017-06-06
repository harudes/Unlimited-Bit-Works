#include <iostream>
#include <dos.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

char temp;
char base[8][8];
int c=2,f=2;

#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_DOWN 80
#define KEY_ESC 27



void key_press(char tecla){
	base[f][c]=temp;
	if(tecla==KEY_DOWN)
		if(f!=7)
			f++;
	if(tecla==KEY_UP)
		if(f!=0)
			f--;
	if(tecla==KEY_LEFT)
		if(c!=0)
			c--;
	if(tecla==KEY_RIGHT)
		if(c!=7)
			c++;
	temp=base[f][c];
}

void generar_tablero(char tablero[8][8],int filas, int columnas){
	for(int i=0; i<filas;i++){
		for(int j=0;j<columnas;j++){
			tablero[i][j]=' ';
		}
	}
}

void imprimir_tablero(char tablero[8][8],int filas, int columnas){
	cout<<endl;
	for(int i=0; i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<"["<<tablero[i][j]<<"]";
		}
		cout<<endl;
	}
	cout<<endl;
}

class jugador{
	
public:
	bool jugadas;
	jugador *next;
	char ficha;
	int puntaje;
	jugador(char simbolo){
		ficha=simbolo;
		puntaje=2;
		jugadas=true;
	}
};

int main(int argc, char *argv[]) {
	jugador player1('O'), player2('*');
	player1.next=&player2;
	player2.next=&player1;
	jugador *player=&player1;
	generar_tablero(base,8,8);
	//imprimir_tablero(base,8,8);
	char tecla;
	int espacios=60;
	base[3][3]=player1.ficha;
	base[4][4]=player1.ficha;
	base[4][3]=player2.ficha;
	base[3][4]=player2.ficha;
		while((espacios!=0)&&(player1.puntaje!=0)&&(player2.puntaje!=0)&&(tecla!=KEY_ESC)){
		if(kbhit())
			system("cls");
			system("cls");
			imprimir_tablero(base,8,8);
			tecla=getch();
			key_press(tecla);
			base[f][c]='x';
	}
	return 0;
}

