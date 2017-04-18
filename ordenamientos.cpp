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

void Bubblesort(int *p, int *q){
	int tam=q-p+1;
	int *temp=p;
	bool intercambio=1;
	int j=0;
	while(intercambio==1&&tam>1){
		intercambio==0;
		for(int i=0;i<tam-1;i++){
			if(*p>*(p+1)){
				swap(p,p+1);
				intercambio=1;
				j++;
			}
			p++;
		}
		p=temp;
		tam--;
	}
	cout<<j<<endl;
}

int main(int argc, char *argv[]) {
	int arreglo[20]={7,2,5,4,1,3,5,1,4,2,4,2,5,1,54,1,4,1,14,4};
	int *p=arreglo, *q=&arreglo[19];
	print(p,q);
	Bubblesort(p,q);
	print(p,q);
	return 0;
}

