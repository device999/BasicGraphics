#include<iostream>
#include <math.h>
using namespace std;

struct Vector3
{
    double x;
    double y;
    double z;
};

void print (const Vector3& a)
{
    cout << "x= "<<a.x<<" y= "<<a.y<<" z= "<<a.z<< endl;
}
Vector3 add(const Vector3& a, const Vector3& b)
{
    Vector3 c;
    c.x= a.x+b.x;
    c.y = a.y+b.y;
    c.z = a.z+b.z;
    return c;
}
Vector3 substract(const Vector3& a, const Vector3& b)
{
    Vector3 c;
    c.x= a.x-b.x;
    c.y = a.y-b.y;
    c.z = a.z-b.z;
    return c;
}
Vector3 multiply(double s, const Vector3& b)
{
    Vector3 c;
    c.x= s*b.x;
    c.y = s*b.y;
    c.z = s*b.z;
    return c;
}
double length(const Vector3& a)
{
    return 	sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
}
Vector3 normalize(const Vector3& a)
{
    Vector3 c;
    c.x = a.x / length(a);
    c.y = a.y / length(a);
    c.z = a.z / length(a);
    return c;
}

//Calculation are taken from this link:
//https://www.mathsisfun.com/algebra/vectors-cross-product.html
Vector3 cross_product(const Vector3& a, const Vector3& b)
{
    Vector3 c;
    c.x = a.y*b.z - a.z*b.y;
    c.y = a.z*b.x - a.x*b.z;
    c.z = a.x*b.y - a.y*b.x;
    return c;
}

//https://www.mathsisfun.com/algebra/vectors-dot-product.html
double dot_product(const Vector3& a, const Vector3& b)
{
    return a.x*b.x+a.y*b.y+a.z*b.z;
}

class Line {
	Vector3 point1, point2;
	public:
		Line(const Vector3& p1,const Vector3& p2)
		{
			point1 = p1;
			point2 = p2;
		}
		const Vector3& get_point1() const
		{
			return point1;
		}
		const Vector3& get_point2() const
		{
			return point2;
		}
		Vector3 closest_point(const Vector3& p)
		{
			return substract(point1, multiply(dot_product(substract(point1, p), substract(point2, point1)) /
			dot_product(substract(point2, point1), substract(point2, point1)), substract(point2, point1)));
		}
		double distance_to(const Vector3& p)
		{
			return length(substract(closest_point(p), p));
		}
};
class Plane {
	public:
	Vector3 point, normal;
	public:
		Plane(Vector3 p1,Vector3 p2, Vector3 p3)
		{
			point = p1;
			normal = multiply(1 / length(cross_product(substract(p1, p3), substract(p2, p3))), cross_product(substract(p1, p3), substract(p2, p3)));	
		}
		const Vector3& get_point() const
		{
			return point;
		}
		const Vector3& get_normal() const
		{
			return normal;
		}
		double get_hnf_d() const
		{
			return -dot_product(point, normal);
		}
		Vector3 closest_point(const Vector3& p)
		{
			return substract(p, multiply(get_hnf_d() + dot_product(p, normal), normal));
		}
		double distance_to(const Vector3& p)
		{
			return dot_product(normal, p)+get_hnf_d();
		}
		Vector3 intersect_line(const Line &l)
		{
		Vector3 a = l.get_point1();
		Vector3 b = l.get_point2();

		return substract(a, multiply((get_hnf_d() + dot_product(a, normal)) / dot_product(substract(b, a), normal), substract(b, a)));	
		}
};
void a(Plane a,Vector3 p1,Vector3 p2,Vector3 p3)
{
	cout << "p1 = " << a.distance_to(p1) << endl;
	cout << "p2 = " << a.distance_to(p2) << endl;
	cout << "p3 = " << a.distance_to(p3) << endl;
	cout << "p1 + p2 + p3  = " << a.distance_to(add(p1, add(p2, p3))) << endl;
	cout << "(p1 + p2 + p3) / 3  = " << a.distance_to(multiply(1 / 3, add(p1, add(p2, p3)))) << endl;
}
void b(Plane a)
{
	cout << "d  =  " << a.get_hnf_d() << endl;
}
void c(Plane a,Vector3 o)
{
	cout << "distance from the origin to the plane  =  " << a.distance_to(o) << endl;
}
void d(Plane a,Vector3 o)
{
	Vector3 closest = a.closest_point(o);
	print(closest);
}
void e(Plane a,Vector3 o)
{
	Vector3 solution = a.closest_point(o);
	cout << "the distance from closest points to origin is: " << length(solution) << endl;	
}
void f(Line lin,Vector3 p1,Vector3 p2,Vector3 p3)
{
	cout << "point's distance to p1 =  " << lin.distance_to(p1) << endl;
	cout << "point's distance to p2 =  " << lin.distance_to(p2) << endl;
	cout << "point's distance to p3 = " << lin.distance_to(p3) << endl;
}
void g(Line lin,Plane a)
{
	Vector3 solution = a.intersect_line(lin);
	cout << "The distance of the point to the plane =  " << a.distance_to(solution) << endl;
	cout << "The distance of the point to the line = " << lin.distance_to(solution) << endl;
}
int main()
{
	Vector3 p1,p2,p3,q1,q2,o;
	o.x=0;
	o.y=0;
	o.z=0;
	p1.x = sqrt(1 / 8.0);
	p1.y = sqrt(1 / 8.0);
	p1.z = sqrt(3 / 4.0);
	p2.x = 0;
	p2.y = 2 * sqrt(1 / 8.0);
	p2.z = 0;
	p3.x = sqrt(1 / 8.0) + sqrt(3 / 8.0);
	p3.y = sqrt(1 / 8.0) + sqrt(3 / 8.0);
	p3.z = sqrt(3 / 4.0) - sqrt(1 / 4.0);
	q1.x = 1;
	q1.y = 1;
	q1.z = 1;
	q2.x = -1;
	q2.y = -1;
	q2.z = 1;
	Plane pl(p1, p2, p3);
	Line lin(q1, q2);
	cout << "Assignment a" << endl;
	a(pl, p1, p2, p3);
	cout << "Assignment b" << endl;
	b(pl);
	cout << "Assignment c" << endl;
	c(pl,o);
	cout << "Assignment d" << endl;
	d(pl,o);
	cout << "Assignment e" << endl;
	f(lin,p1,p2,p3);
	cout << "Assignment f" << endl;
	e(pl,o);
	cout << "Assignment g" << endl;
	g(lin,pl);
}
