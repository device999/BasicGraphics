#include <iostream>
using namespace std;

int main()
{
	int size = 40;
	int a[size];
	int b[size];
	int sum = 0;
	int c[8];
	int product=1;
	int d[size];
	for (int i=0;i<size;i++)
	{
		a[i]=2*(i+1);
		cout <<a[i]<<endl;
	}
	cout <<" "<<endl;
	for(int i=0;i<size;i++)
	{
		sum=0;
		for(int j=0;j<i+1;j++)
		{
			sum	=sum+a[j];
		}
		b[i]=sum;
		cout <<b[i]<<endl;
	}
	cout <<" "<<endl;
	for (int i=0;i<size;i++)
	{
		d[i]=a[39-i];
		cout <<d[i]<<endl;
	}
	cout <<" "<<endl;
	for(int i=0;i<8;i++)
	{
		product=1;
		for(int j=0;j<i+1;j++)
		{
			product	=product*a[j];
		}
		c[i]=product;
		cout <<c[i]<<endl;
	}
	cout <<" "<<endl;
	cout <<a[6]<<endl;
	//this element is not defined (we only have up until a[40];) compiles; random value for a[100]
	cout <<a[100]<<endl;
	//int16 2 bytes short, short int, signed short int [-32 768 , 32 767]
	//compiles; generates runtime exception = Access violation reading location (memory addresses is too deep; another program that is using windows might use it)
	//cout << "a[10000] = " << a[10000] << endl;
}
