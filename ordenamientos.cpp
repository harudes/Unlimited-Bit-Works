#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void swap(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
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




void BubbleSort(int *p, int *q){
	int *temp=p;
	bool intercambio=1;
	while(intercambio==1&&q!=p+1){
		intercambio=0;
		for(;p<q;p++){
			if(*p>*(p+1)){
				swap(p,p+1);
				intercambio=1;
			}
		}
		p=temp;
		q--;
	}
}

void CoctailSort(int *p, int *q){
	int *temp=p;
	bool intercambio=1;
	while(intercambio==1&&q>p){
		intercambio=0;
		for(;p<q;p++){
			if(*p>*(p+1)){
				swap(p,p+1);
				intercambio=1;
			}
		}
		for(;q>temp;q--){
			if(*q<*(q-1)){
				swap(q,q-1);
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

int* sort(int *p,int *q,int *pivote){
	int temp;
	for(int *i=p; i<pivote;){
		if(*i>=*pivote){
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
		if(*i<=*pivote){
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

void QuickSort(int *p,int *q){
	int *pivote=p;
	pivote+=(q-p)/2;
	pivote=sort(p,q,pivote);
	if(p<pivote)
		QuickSort(p,pivote-1);
	if(q>pivote)
		QuickSort(pivote+1,q);
}

void generarArreglo(int *p, int tam){
	for(int i=0;i<tam;i++)
		p[i]=rand()%20;
}

int main(int argc, char *argv[]) {
	int arreglo[20];
	int *p=arreglo, *q=&arreglo[19];
	generarArreglo(arreglo,20);
	print(p,q);
	QuickSort(p,q);
	print(p,q);
	return 0;
}
