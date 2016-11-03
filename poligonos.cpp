#include <iostream>
#include <math.h>
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

int main(int argc, char *argv[]) {
	point triangulo[2]={point(2,1),point(3,4)},tri1[3]={point(0,0),point(4,0),point(0,3)},*p;
	PointArray rectangulo(triangulo,2);
	rectangle rect1(triangulo,4), rect2(2,7,4,9);
	triangle triangulo1(tri1,3);
	double a;
	p=rect2.getPoints();
	cout<<triangulo1.area()<<endl;
	cout<<triangulo1.getNumSides()<<endl;
	cout<<p[0].x<<endl;
	a=rect1.area();
	cout<<a<<endl;
	cout<<rect2.area()<<endl;
	cout<<rect1.getNumSides();
	return 0;
}

