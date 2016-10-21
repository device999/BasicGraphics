#include <iostream>
using namespace std;
int main()
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
a=0;
cout << "Do while loop" << endl;
   do
   {
       cout << "value of a: " << a << endl;
       a = a + 1;
   }while( a < 10 );
cout << "3 condition" << endl;
}
