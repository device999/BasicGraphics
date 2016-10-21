#include <iostream>
using namespace std;	
int main(){
double number = 10.0;
double& reference(number); // reference to variable number(second name for the a variable) *
double* pointer(&number); // pointer to variable number (a variable which stores the address of another variable) &
std::cout << &number << "; " << &reference << "; " << pointer << std::endl;
//0x22fe28; 0x22fe28; 0x22fe28;
//& in front of the variable assigns the address of the variable
//Value of the number - We can show reference by assigning & in front of the variable
//Value of the reference - Due to the condition that reference is a second name for the variable ,
//assigning & will show the address value of it.
//Value of the pointer - as it can be seen from initial declaration of the pointer ,it points to the address value of the reference
//in our case &number
std::cout << number << "; " << reference << "; " << *pointer << std::endl;
//10;10;10
//Value of the number - Simple printing value of the number which is - 10
//Value of the reference is the same as value of the number so it is also -10
//An interesting property of pointers is that they can be used to access the variable they point to directly with the * sign
//Value of the pointer - in this case shows the value of the memory layer.
*pointer = 15;
std::cout << number << "; " << reference << "; " << *pointer << std::endl;
// 15; 15; 15;
//All the values are equal to the 15 because the memory layer containing the 10 has been reassigned to 15 , and therefore name and reference are
//15
reference = 50;
std::cout << number << "; " << reference << "; " << *pointer << std::endl;
//50 ; 50 ; 50
//Due the condition that reference stores the variable and when it is changed the value of everything is changed.
number = 10;
std::cout << number << "; " << reference << "; " << *pointer << std::endl;
//10 ; 10; 10
//Same explanation like on 15 line
}
