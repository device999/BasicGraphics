#include <iostream>
#include <math.h>

using namespace std;
int fib_loop(int n,int a,int b)
{
int oldsum = a;
int newsum =b;
int coefficient = 0;
for(int i=0;i<n;i++)
{
newsum = newsum + oldsum;
oldsum = oldsum + newsum;
cout<< "Fibbonaci coefficient "<<coefficient<< "="<<newsum<<endl;
coefficient ++;
i++;
cout<< "Fibbonaci coefficient "<<coefficient<< "="<<oldsum<<endl;
coefficient ++;
}
return oldsum;
}

int main()
{
int number = 10;
int a;
a=fib_loop(number,0,1);
//cout<< "Sum final "<<number<< "="<<a<<endl;
}
