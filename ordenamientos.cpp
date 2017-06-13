#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void swap(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

bool menor(int *a, int *b){
	return *a>*b;
}

bool abs_menor(int *a, int *b){
	int a_temp=*a, b_temp=*b;
	if(a_temp<0)
		a_temp=-a_temp;
	if(b_temp<0)
		b_temp=-b_temp;
	return a_temp>b_temp;
}

bool mayor(int *a, int *b){
	return *a<*b;
}

bool abs_mayor(int *a, int *b){
	int a_temp=*a, b_temp=*b;
	if(a_temp<0)
		a_temp=-a_temp;
	if(b_temp<0)
		b_temp=-b_temp;
	return a_temp<b_temp;
}

void print(int *p,int *q){
	int tam=q-p+1;
	cout<<"[";
	for(int i=0;i<tam;i++){
		if(i!=tam-1)
			cout<<p[i]<<",";
		else
			cout<<p[i];
	}
	cout<<"]"<<endl;
}




void BubbleSort(int *p, int *q,bool (*comparar)(int *a, int *b)){
	int *temp=p;
	bool intercambio=1;
	while(intercambio==1&&q!=p+1){
		intercambio=0;
		for(;p<q;p++){
			if(comparar(p,p+1)){
				swap(p,p+1);
				intercambio=1;
			}
		}
		p=temp;
		q--;
	}
}

void CoctailSort(int *p, int *q, bool (*comparar)(int *a, int *b)){
	int *temp=p;
	bool intercambio=1;
	while(intercambio==1&&q>p){
		intercambio=0;
		for(;p<q;p++){
			if(comparar(p,p+1)){
				swap(p,p+1);
				intercambio=1;
			}
		}
		for(;q>temp;q--){
			if(comparar(q-1,q)){
				swap(q-1,q);
				intercambio=1;
			}
		}
		temp=q;
		q=p;
		temp++;
		p=temp;
		q--;
	}
}

int* sort(int *p,int *q,int *pivote, bool (*comparar)(int *a, int *b)){
	int temp;
	for(int *i=p; i<pivote;){
		if(comparar(i,pivote)){
			int *aux=i;
			temp=*aux;
			for(;aux<pivote;aux++)
				swap(aux,aux+1);
			*(aux)=temp;
			pivote--;
		}
		else
		   i++;
	}
	for(int *i=q; i>pivote;){
		if(comparar(pivote,i)){
			int *aux=i;
			temp=*aux;
			for(;aux>pivote;aux--)
				swap(aux,aux-1);
			*(aux)=temp;
			pivote++;
		}
		else
		   i--;
	}
	return pivote;
}

void QuickSort(int *p,int *q, bool (*comparar)(int *a, int *b)){
	int *pivote=p;
	pivote+=(q-p)/2;
	pivote=sort(p,q,pivote,comparar);
	if(p<pivote)
		QuickSort(p,pivote-1,comparar);
	if(q>pivote)
		QuickSort(pivote+1,q,comparar);
}

void generarArreglo(int *p, int tam){
	for(int i=0;i<tam;i++)
		p[i]=rand()%40-20;
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int arreglo[20];
	int *p=arreglo, *q=&arreglo[19];
	generarArreglo(arreglo,20);
	print(p,q);
	QuickSort(p,q,menor);
	print(p,q);
	return 0;
}
