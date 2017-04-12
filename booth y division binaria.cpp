#include <iostream>
#include <math.h>
#include <bitset>

using namespace std;

int to_int(bitset<8> a){
	int n=0;
	for(int i=0;i<a.size()-1;i++)
		n+=pow(2,i)*a[i];
	n-=pow(2,a.size()-1)*a[7];
	return n;
}

bitset<8> sumaBit(bitset<8> a, bitset<8> b){
	bool acarreo=0;
	bitset<8> c;
	for(int i=0; i<a.size();i++){
		c[i]=(a[i] ^ b[i]) ^ acarreo;
		acarreo=(a[i] & b[i]) | (a[i] & acarreo) | (acarreo & b[i]);
	}
	return c;
}

bitset<8> complementoBit(bitset<8> a){
	bitset<8> b, u(1);
	for(int i=0; i<a.size();i++)
		b[i]=~a[i];
	return sumaBit(b,u);
}

int booth(int a, int b){
	bitset<8> A(0), M(a), Q(b);
	int n=Q.size();
	bool Q1=0;
	bool temp=0;
	while(n>0){
		if((Q[0]==1)&&(Q1==0))
			A=sumaBit(A,complementoBit(M));
		else if((Q[0]==0)&&(Q1==1)){
			A=sumaBit(A,M);
		}
		Q1=Q[0];//arithmetic shift
		Q=Q>>1;//arithmetic shift
		Q[7]=A[0];//arithmetic shift
		temp=A[7];//arithmetic shift
		A=A>>1;//arithmetic shift
		A[7]=temp;//arithmetic shift
		n--;
	}
	cout<<"Binario: "<<Q<<endl;
	return to_int(Q);
}

int division(int a, int b){
	bitset<8> Q(a),M(b),A(0), temp(0);
	int n=Q.size();
	while(n>0){
		A=A<<1;
		A[0]=Q[7];
		Q=Q<<1;
		A=sumaBit(A,complementoBit(M));
		if(A[Q.size()-1]==1){
			Q[0]=0;
			A=sumaBit(A,M);
		}
		else
		   Q[0]=1;
		n--;
	}
	cout<<"Binario: "<<Q<<endl;
	cout<<"El resto es: "<<to_int(A)<<endl;
	return to_int(Q);
}
int main()
{
	cout<<division(115,3)<<endl;
	cout<<division(75,5)<<endl;
	cout<<booth(-11,5)<<endl;
	cout<<booth(10,-4)<<endl;
	cout<<booth(15,3)<<endl;
	return 0;
}

