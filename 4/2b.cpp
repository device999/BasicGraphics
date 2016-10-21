#include<iostream>
#include <math.h>
using namespace std;
/*
construct A:4;
construct A:2;
3 times left
construct A:1
2 times left
destruct A:-1
1 times left
destruct A:2
destruct A:1
*/
class A {
	public:
		int counter;
		A(int a = 1) 
		{
			counter = a;
			cout<<counter<<endl;
			cout << "construct A: " << counter << endl;
		}
		~A() 
		{
			cout << "destruct A: " << counter << endl;
		}
		void use() 
		{
			cout<<counter<<endl;
			if( -- counter > 0 ) 
			{
				cout << counter << " times left" << endl;
			}
		}
};
int main(int argc,char** argv) 
{
	A a1(4), a2(2);
	a1.use();
	{
		A a3;
		a3.use();
		a1.use();
		a3.use();
	}
	a1.use();
}
//Just a hint first destructor is called for a3 object,
//then for a2,a1.Guess might be that the counter went less than 0?Guess.
