/*
Rahimbeyli Sattar
 Assignment 1 : Control Flow
*/
#include <iostream>
#include <typeinfo>
#include <ctime>
using namespace std;
//Assignment 1b
void assignment1b()
{
int day;
int month;
int year;
string name;
cout << "Please enter your name: ";
cin >> name;
cout << "Please enter your date of birth: ";
cin >> day;
cout << "Please enter your month of birth: ";
cin >> month;
cout << "Please enter your year of birth: ";
cin >> year;
time_t t = time(NULL);
tm* timePtr = localtime(&t);
int current = timePtr->tm_year + 1900;
cout << "Your name is = " << name<< endl;
cout << "Your age is = " << current - year<< endl;
}
//Assignment 2
//Assignment 2a
void assignment2a(){
int i = 10;
int j= 23;
float f = 3.141f;
double d = 2.718281828459045;
cout << "i stands for INTEGER" <<endl;
cout << "f stands for FLOAT" <<endl;
cout << "d stands for DOUBLE" <<endl;
cout << "i/j" << i/j <<endl;
cout << "Type of the result is  " <<typeid(i/j).name() <<endl;
cout << "j/i=" << j/i <<endl;
cout << "Type of the result is  " <<typeid(j/i).name() <<endl;
cout << "i/2=" << i/2 <<endl;
cout << "Type of the result is  " <<typeid(i/2).name() <<endl;
cout << "j/2=" << j/2 <<endl;
cout << "Type of the result is  " <<typeid(j/2).name() <<endl;
cout << "i%2=" << i%2 <<endl;
cout << "Type of the result is  " <<typeid(i%2).name() <<endl;
cout << "j%2=" << j%2 <<endl;
cout << "Type of the result is  " <<typeid(j%2).name() <<endl;
cout << "(j/3)*3+j%3=" << (j/3)*3+j%3 <<endl;
cout << "Type of the result is  " <<typeid((j/3)*3+j%3).name() <<endl;
cout << "f*f*5=" <<  f*f*5<<endl;
cout << "Type of the result is  " <<typeid(f*f*5).name() <<endl;
cout << "f/d=" << f/d <<endl;
cout << "Type of the result is  " <<typeid(f/d).name() <<endl;
cout << "d/f=" << d/f <<endl;
cout << "Type of the result is  " <<typeid(d/f).name() <<endl;
cout << "d*i=" << d*i <<endl;
cout << "Type of the result is  " <<typeid(d*i).name() <<endl;
cout << "d/i=" << d/i <<endl;
cout << "Type of the result is  " <<typeid(d/i).name() <<endl;
}
//end of 2a
//Assignment 2 b and c
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
int absl(int a)
{
    if (a >= 0)
    {
        return a;
    }
    else
    {
        return -a;
    }
}
void assignment2c()
{
    int answer;
    answer = mean(min(max(10,1), absl(-9)),6);
    cout << "The result is " << answer<<endl;
}
//end of Assignment b and c
//Assignment 3 Loops
//Assignment 3a
void loops()
{
    cout << "While loop" << endl;
    int a = 0;
    while( a < 10 ) {
        cout << "This is the " << a << " th time !" << endl;
        a ++;
    }
    cout << "For loop" << endl;
    for (int a=0; a<10; a++) {
        cout << "This is the " << a << " th time !" << endl;
    }
    cout << "Do while loop" << endl;
    do
    {
        cout << "This is the " << a << " th time !" << endl;
        a = a + 1;
    }while( a < 10 );

    cout << "Conditional set with while" << endl;
    a = 0;
    while (true)
    {
        cout << "This is the " << a << " th time !" << endl;
        a++;
        if (a == 10)
            break;
    }
}
//End of 3a
//Assignment 3b
int sumFirstN(int n)
{
    int answer = 0;
    for(int a =0;a<n+1;a++)
    {
        answer = answer + a;
    }
    return answer;
}
//End of 3b
//Assignment 3c
int fib_loop(int n)
{
    int oldsum = 0;
    int newsum =1;
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
//end of 3c
//Assignment 4
int fib_recursion(int n)
{
    if(n==0||n==1)
        return 1;
    else
        return fib_recursion(n-2)+fib_recursion(n-1);
}
//End of 4a
//Assignment 4 b and c
int findb(int n,int i)
{
    if(n==i || n==1 && i==1 ||i==0)
        return 1;
    else
        return findb(n-1,i-1)+findb(n-1,i);
}
int main(int argc, char** argv){
    int number;
    int fibrec;
    int fiblop;
    int sum;
    int rows;
    while(true)
    {
        cout << "Please choose the assignment" << endl;
        cout << "1  --- Assignment-1		" << endl;
        cout << "2  --- Assignment-2a	" << endl;
        cout << "3  --- Assignment-2b and c	" << endl;
        cout << "4  --- Assignment-3a	" << endl;
        cout << "5  --- Assignment-3b	" << endl;
        cout << "6  --- Assignment-3c	" << endl;
        cout << "7  --- Assignment-4a	" << endl;
        cout << "8  --- Assignment-4b and c	" << endl;
        cout << "0  --- Exit program  	    " << endl;
        cout << "------------------------------------" << endl;
        cin >>number;

        switch(number)
        {
            case 0: return(0);break;
            case 1: assignment1b();break;
            case 2: assignment2a();break;
            case 3: assignment2c();break;
            case 4: loops();break;
            case 5:
                cout << "Input the first n natural number,the sum of those you want to find =  ";
                cin >> sum;
                cout<<"The sum of first="<<sum<<" equals = "<<sumFirstN(sum)<<endl;				
                break;
            case 6:
                cout << "Input required n for Fibonacci sequence loop =  ";
                cin >> fiblop;
                fib_loop(fiblop);
                break;
            case 7:
                cout << "Input required n for Fibonacci sequence recursion=  ";
                cin >> fibrec;
                cout<<"Fibonacci of  "<<fibrec<<" equals "<< fib_loop(fibrec)<<endl;
                break;
            case 8:    
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
                break;
        }
    }

}
