#include <iostream>
using namespace std;

class Point{
private:
	int x, y;
public:
	Point(){
		x=0;
		y=0;
	}
	Point(int a, int b){
		x=a;
		y=b;
	}
};

class PointArray{
private:
	int size;
	Point *points;
	void resize2(int newsize){
		Point *p;
		p = new Point[newsize];
		for(int i=0; i<newsize; i++)
			p[i] = points[i];
			delete[] points;
			points = p;
			size = newsize;
	}
public:
	PointArray(const Point *array,const int tam){
		size = tam;
		points = new Point[tam];
		for(int i=0;i<tam;i++)
			points[i] = array[i];
	}
	PointArray(const PointArray& pv){
		this->resize2(pv.size);
		for(int i=0;i<pv.size;i++){
			points[i] = pv.points[i];
		}
	}
	void push_back(const Point &p){
		this->resize2(size+1);
		points[size-1]=p;
	}
	void insert(const Point &p, int position){
		if(position = size)
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

int main(int argc, char *argv[]) {
	
	return 0;
}

