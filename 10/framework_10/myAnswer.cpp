#include<algorithm>
#include "tools.h"
#include<iostream>

using namespace std;

double sum(double x1,double x2)
{
	return reducePrecision(x1)+reducePrecision(x2);
}
int main()
{
	cout<<sum(0.5,0.22) <<endl;
}
