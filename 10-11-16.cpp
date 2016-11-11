#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <list>
using namespace std;

class graph{
private:
	map<int,vector<int> > grafo;
public:
	graph(vector<int> &starts,vector<int> &ends){
		for(int i=0; i<starts.size(); i++){
			grafo[starts[i]].push_back(ends[i]);
		}
		vector<int> vacio;
		for(int i=0; i<ends.size(); i++){
			if (grafo.find(ends[i])->second.size()==grafo.size()){
				grafo[ends[i]];
			}
		}
	}
	vector<int> adjacent(int ID){
		return grafo.find(ID)->second;
	}
	int numOutgoing(int ID){
		if(adjacent(ID).size()==grafo.size())
		   return adjacent(ID).size();
		else{
			return 0;
		}
	}
	map<int,vector<int> > getGraph(){
		return grafo;
	}
};

template <class E>
class pila{
private:
	E val;
	pila *next;
	int size;
public:
	pila(){val=0;size=0;next=NULL;}
	pila(E valor){val=valor;size=1;}
	int getSize(){return size;}
	void push(E valor){
		pila *temp;
		temp=new pila;
		if(size==1){
		   temp->val=val;
		   val=valor;
		   next=temp;
		}
		else{
			temp->val=val;
			temp->next=next;
			val=valor;
			next=temp;
		}
		size++;
	}
	void pop(){
		if(size!=1){
			pila *p;
			p=next;
			val=next->val;
			next=next->next;
			delete p;
		}
		else{
			val=0;
		}
		size--;
	}
	void print(){
		if(size!=0){
			if(size==1)
			cout<<val;
			else{
				pila *cur;
				cur=this;
				cout<<val;
				while(cur->next!=NULL){
					cur=cur->next;
					cout<<cur->val;
				}
		}
		cout<<endl;
		}
	}
	E *top(){
		pila *p=this;
		return p;
	}
	bool empty(){return size==0 ? true:false;}
};

template <typename T>
T Min(T a, T b){
	return a > b ? b:a;
}

int main(int argc, char *argv[]) {
	//int c=4,b=3;
	//cout<<Min(c,b)<<endl;
	//pila<int> a(4);
	//a.push(5);
	//a.push(2);
	//a.push(3);
	//a.push(1);
	//a.print();
	//a.pop();
	//a.pop();
	//a.print();
	//cout<<a.empty()<<endl;;
	//a.pop();
	//a.pop();
	//a.pop();
	//cout<<a.empty()<<endl;;
	//a.print();
	//a.push(5);
	//a.push(2);
	//a.push(3);
	//a.push(1);
	//a.print();
	vector<int> a,b,c;
	a.push_back(1);
	a.push_back(1);
	a.push_back(1);
	a.push_back(5);
	a.push_back(5);
	a.push_back(4);
	b.push_back(2);
	b.push_back(3);
	b.push_back(4);
	b.push_back(4);
	b.push_back(2);
	b.push_back(2);
	graph mapa(a,b);
	cout<<mapa.numOutgoing(7)<<endl;
	return 0;
}

