#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
	int i = 10;
	int j= 23;
	float f = 3.141f;
	double d = 2.718281828459045;
	cout << "i stands for INTEGER" <<endl;
	cout << "f stands for FLOAT" <<endl;
	cout << "d stands for DOUBLE" <<endl;
	cout << "i/j" << i/j <<endl;
	cout << "Type of the result is  " <<typeid(i/j).name() <<endl;
	cout << "j/i=" << j/i <<endl;
	cout << "Type of the result is  " <<typeid(j/i).name() <<endl;
	cout << "i/2=" << i/2 <<endl;
	cout << "Type of the result is  " <<typeid(i/2).name() <<endl;
	cout << "j/2=" << j/2 <<endl;
	cout << "Type of the result is  " <<typeid(j/2).name() <<endl;
	cout << "i%2=" << i%2 <<endl;
	cout << "Type of the result is  " <<typeid(i%2).name() <<endl;
	cout << "j%2=" << j%2 <<endl;
	cout << "Type of the result is  " <<typeid(j%2).name() <<endl;
	cout << "(j/3)*3+j%3=" << (j/3)*3+j%3 <<endl;
	cout << "Type of the result is  " <<typeid((j/3)*3+j%3).name() <<endl;
	cout << "f*f*5=" <<  f*f*5<<endl;
	cout << "Type of the result is  " <<typeid(f*f*5).name() <<endl;
	cout << "f/d=" << f/d <<endl;
	cout << "Type of the result is  " <<typeid(f/d).name() <<endl;
	cout << "d/f=" << d/f <<endl;
	cout << "Type of the result is  " <<typeid(d/f).name() <<endl;
	cout << "d*i=" << d*i <<endl;
	cout << "Type of the result is  " <<typeid(d*i).name() <<endl;
	cout << "d/i=" << d/i <<endl;
	cout << "Type of the result is  " <<typeid(d/i).name() <<endl;
}
