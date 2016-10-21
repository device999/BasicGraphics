#include <iostream>
#include <stdlib.h> 
using namespace std;

int min(int a , int b)
{
	if(a>b)
	{
		return b;
	}
	else
	{
		return a;	
	}
}
int max (int a , int b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;	
	}
}
int square (int a)
{
int answer; 
return answer = a*a;
}
int mean (int a , int b)
{
int answer;
answer = (a+b)/2;
return answer;
}
int abs1(int a)
{
	return abs(a);
}
int main()
{
int answer;
answer = mean(min(max(10,1), abs1(-9)),6);
cout << "The result is " << answer;
}
