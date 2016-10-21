#include<iostream>
using namespace std;
int findb(int n,int i)
{
    if(n==i || n==1 && i==1 ||i==0)
        return 1;
    else
        return findb(n-1,i-1)+findb(n-1,i);
}
int main()
{
    int rows;
    cout<<"Enter number of rows: ";
    cin>>rows;
    for(int i=0;i<rows;i++)
    {
    	cout<<"   ";
		for(int j=0;j<i+1;j++)
		{
		int t=findb(i,j);
    	//cout<<"Binomial coefficient of n= "<<i<<" and i="<<j<<" equals "<<t<<endl;
    	cout<<"   "<<t;
		}
		cout<<endl;
	}

 
}
