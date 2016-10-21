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

int main()
{
    Vector3 a,b;
    double s = -2;
    a.x = 1;
    a.y = 2;
    a.z = 3;
    b.x = -1;
    b.y = 2;
    b.z = -2;
    cout<<"Sum of two vectors give the vector below "<<endl;
	print(add(a, b));
	cout<<"Subtraction of two vectors give the vector below "<<endl;
    print(substract(a, b));
    cout<<"Multiplication of two vectors give the vector below "<<endl;
    print(multiply(s, b));
    cout<<"Dot product of two vectors give the vector below "<<endl;
    cout<<dot_product(a, b)<<endl;
    cout<<"Length of vector give the value below "<<endl;
    cout<<length(a)<<endl;
    cout<<"Cross product of two vectors give the vector below "<<endl;
    print(cross_product(a, b));
}
