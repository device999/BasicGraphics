# include <iostream>
 
using namespace std;
 
int main()
{  
 char prime[101];
 for (int i=2;i<=10;i++)
 {
 	for (int j=i*2;j<=100;j=j+i)
 	{
		prime[j]='-';
	}
 }
 cout<<""<<endl;
 for (int i=0;i<101;i++)
 {
 	if (prime[i]!='-')
 	{
	cout<<i<<endl;
	}
 }
}
