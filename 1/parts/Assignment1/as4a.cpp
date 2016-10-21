#include<iostream>
using namespace std;
int fib_recursion(int n)
{
    if(n==0||n==1)
        return 1;
    else
        return fib_recursion(n-2)+fib_recursion(n-1);
}
int main()
{
    int n=5;
    int t=fib_recursion(n);
    cout<<"Fibonacci of  "<<n<<" equals "<<t<<endl;
 
}
