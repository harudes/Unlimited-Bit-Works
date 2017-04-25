#include <iostream>
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

void sort(int *p,int *q,int *pivote){
	int *start=p, *end=q;
	int temp;
	for(int *i=p; i<pivote;){
		if(*i>*pivote){
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
	print(start,end);
	cout<<endl;
	for(int *i=q; i>pivote;){
		if(*i<*pivote){
			int *aux=i;
			temp=*aux;
			for(;aux>pivote;aux--)
				swap(aux,aux-1);
			*(aux)=temp;
			pivote++;
		}
		else
		   i--;
		print(start,end);
		cout<<endl;
	}
}

void QuickSort(*p,*q){
	
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

int main(int argc, char *argv[]) {
	int arreglo[20]={20,7,18,7,5,15,10,13,12,11,10,9,8,7,6,5,4,3,2,1};
	int *p=arreglo, *q=&arreglo[19];
	print(p,q);
	sort(p,q,&arreglo[8]);
	print(p,q);
	return 0;
}


