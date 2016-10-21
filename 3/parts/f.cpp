#include <iostream>
using namespace std;	
int main(){
double array[5] = { 10.0, 20.0, 30.0, 40.0, 50.0 };
double* begin = array;
double* end = array + 5;
//40 30 20 10
//Backward loops value 50 is contained in end-1, but in print we decrease it therefore 50 is not included
for(const double* ptr=end-1; ptr != begin; ) {
std::cout << *(-- ptr) << " ";
}
cout << endl;
//50 40 30 20
//10 is not included because memory address of 10 located in begin , but our loop mustnot be equal to begin,
//that is the reason
for(const double* ptr=end-1; ptr != begin; --ptr) {
std::cout << *ptr << " ";
}
cout << endl;
//50 40 30 20 10
//everything is included :) alles gut!
for(const double* ptr=end-1; ptr >= begin; --ptr) {
std::cout << *ptr << " ";
}

}
