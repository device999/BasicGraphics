/*
Rahimbeyli Sattar
 Assignment 2 : Basic Data Types
*/
#include <iostream>

using namespace std;
void assignment2()
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
int string_length(const char* sms)
{
    int size=0;
    while (true)
    {
        if(sms[size]!='\0')
        {
            size++;
        }
        else
        {
            break;
        }
    }
    return size;
}
char map(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return ch + ('A' - 'a');
    else if (ch >= 'A' && ch <= 'Z')
        return ch + ('a' - 'A');
    else
        return ch;
}
void assignment3()
{
    //task a
    int var;
    char var1;
    cout <<var<<endl;
    cout <<var1<<endl;
    //task b
    cout << "a: " << int(char('a')) << endl;
    cout << "b: " << int(char('b')) << endl;
    cout << "c: " << int(char('c')) << endl;
    cout << "z: " << int(char('z')) << endl;
    cout << "A: " << int(char('A')) << endl;
    cout << "B: " << int(char('B')) << endl;
    cout << "C: " << int(char('C')) << endl;
    cout << "Z: " << int(char('Z')) << endl;
    cout << "0: " << int(char('0')) << endl;
    cout << "1: " << int(char('1')) << endl;
    cout << "2: " << int(char('2')) << endl;
    cout << "9: " << int(char('9')) << endl;
    cout <<" "<< endl;
    //task c
    for (char c = '0'; c <= 'z'; c++)
    {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        {
            cout << c<<"= " <<int(c) << endl;
        }

    }
    //task d
    cout <<" "<< endl;
    const char* message = "Hello world";
    cout << message;
    //task e
    cout <<" "<< endl;
    cout<< string_length(message)<<endl;
    //task f
    cout<<"Testing letter s in upper case = " <<map('s')<<endl;
    cout<<"Testing letter S in lower case = " <<map('S')<<endl;
    //task g
    char buffer[100];
    for (int i=0;i<string_length(message);i++)
    {
        buffer[i] = map(message[i]);
        cout << buffer[i];
    }
    cout<<endl;
}
void assignment4()
{
    char chvar;
    int invar;
    double dovar;
    cout<<chvar<<endl;
    cout<<invar<<endl;
    cout<<dovar<<endl;
    cout<<" "<<endl;
    int intarr[100];
    for (int i=0;i<100;i++)
    {
        cout<<intarr[i]<<endl;
    }
    //A declared variable can be Zero Initialized, Value Initialized or Default Initialized
}
void primenumbers()
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
int main(int argc, char** argv){
    int number;
    while(true)
    {
        cout << "Please choose the assignment" << endl;
        cout << "1  --- Assignment-2		" << endl;
        cout << "2  --- Assignment-3	" << endl;
        cout << "3  --- Assignment-4	" << endl;
        cout << "4  --- Assignment-5	" << endl;
        cout << "0  --- Exit program  	    " << endl;
        cout << "------------------------------------" << endl;
        cin >>number;

        switch(number)
        {
            case 0: return(0) ; break;
            case 1: assignment2();break;
            case 2: assignment3();break;
            case 3: assignment4();break;
            case 4: primenumbers();break;
        }
    }

}
