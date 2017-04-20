#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <bitset>
#include <vector>
#include <math.h>

using namespace std;


int to_int(bitset<8> a){
	int n=0;
	for(int i=0;i<a.size()-1;i++)
		n+=pow(2,i)*a[i];
	n-=pow(2,a.size()-1)*a[7];
	return n;
}

int ga(int bits_seed,int bits_num, int particiones, int vueltas)
{
	srand(time(NULL));
	bitset <1024> a;
	vector< bitset<512> > num;
	bitset<512> aux;
	for(int i = 0; i < bits_seed; i++){
		a[i + bits_num - bits_seed] = rand()%2;
	}
	int hola = a.size()-1;
	for(int i = bits_num - bits_seed - 1; i >= 0; i--)
	{
		a[i] = a[hola] ^ a[hola - 1];
		hola--;
	}
	for(int i=0;i<particiones;i++){
		
	}
	cout << a << endl;
}

int main(){
	ga(5,8,2,5);
	return 0;
}

