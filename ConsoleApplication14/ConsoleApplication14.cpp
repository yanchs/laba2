


#include "pch.h"
#include <iostream>
class Point {
//protected:
public:
	   int x,y;
public:
	Point() {
		printf("Point()\n");
		x = 0;
		y = 0;
	}

	Point(int x, int y) {
		printf("Point(int x, int y)\n");
		this->x = x;
		this->y = y;
	}

	Point(Point& point) {
		printf("Point(Point &point)\n");
		this->x = point.x;
		this->y = point.y;
	}
	~Point() {
		printf("(%d,%d)\n", x, y);
		printf("~Point()\n");
	}
	void draw()
	{
		printf("Point::draw() drawing at (%d,%d)\n",x,y);
	}
	void MoveY_line(int dy);
};

void Point::MoveY_line(int dy) {
	printf("MoveY_line(int dy)\n");
	y = y + dy;
}

class Point3D : public Point {
protected:
	int z;

public:
	Point3D() : Point() {
		z = 0;
		printf("(%d,%d,%d)\n", x, y, z);
	}

	Point3D(int x, int y, int z) : Point(x, y) {
		printf("Point3D(int x, int y, int z)\n");
		this->z = z;
		printf("(%d,%d,%d)\n", x, y, z);
	}

	Point3D(Point3D& point) : Point(point) {
		printf("Point3D(Point3D &point)\n");
		this->z = point.z;
		printf("(%d,%d,%d)\n", x, y, z);
	}

	~Point3D() {
		printf("(%d,%d)\n", x, y,z);
		printf("~3DPoint()\n");
	}

	void move(int dz) {
		z = z + dz;
		printf("(%d,%d,%d)\n", x, y, z);
	}

};

class square {
protected:
	Point* p1;
	Point* p2;
	Point* p3;
	Point* p4;
public:
	square() {
		printf("square()\n");
		p1 = new Point;
		p2 = new Point;
		p3 = new Point;
		p4 = new Point;
	}

	square(Point &p1, Point& p2, Point& p3, Point& p4) {
		printf("square(points)\n");
		this->p1 = new Point(p1);
		this->p2 = new Point(p2);
		this->p3 = new Point(p3);
		this->p4 = new Point(p4);
	}

	square(square& sq) {
		printf("square(square& sq)\n");
		p1 = new Point(sq.p1->x, sq.p1->y);
		p2 = new Point(*(sq.p2));
		p3 = new Point(*(sq.p3));
		p4 = new Point(*(sq.p4));
	}

	~square() {
		delete p1;
		delete p2;
		delete p3;
		delete p4;
		printf("~square()\n");
	}
};


int main() {
	{
		//статическое с.
		//Point a1;
		//Point a2(2, 3);
	    // Point a3(a1);

		//динамическое с.
		//Point* a1 = new Point;
        //Point* a2 = new Point(3, 2);
        //Point* b = new Point(*a1);
        //delete a1;
        //delete a2;
        //delete b;

		//методы
		//Point a(11, 4);
		//a.draw();
		//printf(" draw (%d,%d)\n", a.x, a.y);
		//a.MoveY_line(33);
        // printf("Yline (%d,%d)\n", a.x, a.y);

		//Point3D* a = new Point3D(1, 4, 8);
		//a->move(1, 1, 1);
		//delete a;

		//square* e = new square(a,b,c,d);
		//delete e;
		 
		//square* e = new square;
		//square* sq = new square(*e);
        //delete e;
        // delete sq;

	}

}