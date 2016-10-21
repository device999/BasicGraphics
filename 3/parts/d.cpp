#include <iostream>
using namespace std;	
int main(){
double array[5] = { 10.0, 20.0, 30.0, 40.0, 50.0 };
double x[5] ={ 10.0, 20.0, 30.0, 40.0, 50.0 };
double* begin =x;
//As i understood this part shows the certain part of the memory containing our array
//To be precise it shows the element which is located in the following addresses 8-11
std::cout << array << std::endl;
std::cout << *(begin + 0) << std::endl;
std::cout << *(begin + 1) << std::endl;
std::cout << *(begin + 2) << std::endl;
//Therefore it is printing 10,20,30 respectively
double* end = array + 5;
//Contains the value stored in the memory at position of array+5
int diff = end - begin;
//the value of the diff is 5 :) because the value of begin defined on line 5 and value of end defined on line 14
diff /= 2;
//value is 2 (type is int)
double value = *(begin + 1) + *(end - (diff));
//The value of the *(begin + 1) is 20 because the memory address defined by it contains 20
//*(end - (diff)) => array + 5 -2 equals to array +3 which contains 40 
//the sum will give the value of 60
std::cout << value << std::endl;
std::cout << *end << std::endl;
//Value of the *end is not assigned, so therefore it give random value.

}
