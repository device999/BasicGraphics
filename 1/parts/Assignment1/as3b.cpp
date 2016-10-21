#include <iostream>
#include <math.h>

using namespace std;
int sumFirstN(int n)
{
int answer = 0;
for(int a =0;a<n+1;a++)
{
answer = answer + a;	
}
return answer;
}

int main()
{
int number = 5;
int a;
a=sumFirstN(number);
cout<< "Sum of "<<number<< "="<<a<<endl;
}
