#include <iostream>
using namespace std;

float cuadrado(float *val){
	return *val * *val;
}

float rectangulo(float *val){
	return *val * *(val+1);
}

float triangulo(float *val){
	return (*val * *(val+1))/2;
}

float circunferencia(float *val){
	return *val * *val * 3.1416;
}

float area(float *val, float (*f)(float *nums)){
	return f(val);
}

int main(int argc, char *argv[]) {
	float lados[2]={9.4,4.7};
	cout<<area(lados,cuadrado)<<endl;
	return 0;
}

