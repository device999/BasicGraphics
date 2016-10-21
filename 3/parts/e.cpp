#include <iostream>
using namespace std;	
int main(){
double array[5] = { 10.0, 20.0, 30.0, 40.0, 50.0 };
double* begin = array;
double* end = array + 5;
//4-6 Taken from previous assignment
double* ptr = begin;
while (ptr != end) {
std::cout << *(ptr ++) << " ";
}
std::cout << endl;
ptr = end;
//9-13 it is simple for loop :) but instead of variable we are using memory address and the variable contained in it
//with every cycle we are moving to the next address with the step +1
while (ptr != begin) {
std::cout << *(-- ptr) << " ";
} ;
std::cout << endl;
//16-19 backwards for loop :) due the line 13 the value of ptr is end so we are decreasing the address of the memory
}
