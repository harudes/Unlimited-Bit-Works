#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <list>
using namespace std;

class point{
public:
	int x;
	int y;
	point(){
		x = 0;
		y = 0;
	}
	point(double a, double b){
		x = a;
		y = b;
	}
};
double distpunt(point &p1, point &p2){
	return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
class PointArray{
private:
	int size;
	point *points;
	void resize2(int newsize){
		point *p;
		p = new point[newsize];
		for(int i=0; i<newsize; i++)
			p[i] = points[i];
			delete[] points;
			points = p;
			size = newsize;
	}
public:
	PointArray(const point *array,const int tam){
		size = tam;
		points = new point[tam];
		for(int i=0;i<tam;i++)
			points[i] = array[i];
	}
	PointArray(const PointArray& pv){
		this->resize2(pv.size);
		for(int i=0;i<pv.size;i++){
			points[i] = pv.points[i];
		}
	}
	void push_back(const point &p){
		this->resize2(size+1);
		points[size-1]=p;
	}
	void insert(const point &p, int position){
		if(position == size)
		   push_back(p);
		else if(position<size){
			for(int i=size-1;i>position;i--)
				points[i]=points[i-1];
				points[position]=p;
		}
	}
	void remove(const int position){
		for(int i=position+1;i>size-1;i++)
			points[i]=points[i+1];
			this->resize2(size-1);
	}
	void clear(){
		this->resize2(0);
	}
	int getSize(){
		return this->size;
	}
};
//////////////////////////////////////////////
//////////////////////////////////////////////
//////////////////////////////////////////////
class polygon{
protected:
	point *puntos;
	int instances;
public:
	polygon(){}
	polygon(point *points, int tam){
		puntos = points;
		instances++;
	}
	virtual double area(){}
	int getNumPolygons(){
		return instances;
	}
	virtual int getNumSides(){}
	point *getPoints(){
		point *array;
		array = puntos;
		return array;
	}
};

class triangle : public polygon{
public:
	triangle():polygon(){};
	triangle(point *points, int tam)
			 : polygon(points, tam){}
			 double area(){
				 double a,b,c,s;
				 a=distpunt(puntos[0],puntos[1]);
				 b=distpunt(puntos[0],puntos[2]);
				 c=distpunt(puntos[2],puntos[1]);
				 s = (a+b+c)/2;
				 return sqrt(s*(s-a)*(s-b)*(s-c));
			 }
			 int getNumSides(){
				 return 3;
			 }
};

class rectangle : public polygon{
public:
	rectangle(int x1, int x2, int y1, int y2): polygon(){
		point p1(x1,y1), p2(x2,y2);
		point *arreglo;
		arreglo = new point[2];
		arreglo[0]=p1;
		arreglo[1]=p2;
		puntos = arreglo;
	}
	rectangle():polygon(){};
	rectangle(point *points, int tam)
			  : polygon(points, tam){}
			  double area(){
				  double a;
				  a=(puntos[1].x-puntos[0].x)*(puntos[1].y-puntos[0].y);
				  if(a<0)
					 a = a*-1;
				  return a;
			  }
			  int getNumSides(){
				  return 4;
			  }
};

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
	rectangle *d;
	triangle *t = dynamic_cast<triangle *> (d);
	return 0;
}
