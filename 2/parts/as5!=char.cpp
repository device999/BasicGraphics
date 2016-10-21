# include <iostream>
 
using namespace std;
 
bool a[100];
 
int main()
{  

	a[0]=true;
    a[1]=true;
    for(long long i=2; i<=100; ++i)
    {
            if(a[i]==false)
            {
                           if(i*i<=100)
                           {
                                          for(long long j=i*i; j<=100; j+=i)
                                          {
                                                   a[j]=true;
                                          }
                           }
            }
    }
 
    for(long long i=1; i<=100; ++i)
    {
            if(a[i]==false)
            	cout<<i<<" ";
    }
}
