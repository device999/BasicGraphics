#include<algorithm>
#include<iostream>
#include<map>
#include <numeric>
#include<string>
#include<vector>
/*
std::swap -	  2 parameters and exchanges their values.
std::min -	  returns minimum between a and b
std::max -	  returns maximum between a and b
std::min_element - return the minimum element from the vector(array)
std::max_element - return the maximum element from the vector(array)
std::accumulate - returns the sum of the elements of the vector(array)
std::find - finds an element in the vector due it is value
std::copy - copies values of the vector into another vector
std::reverse - reverses the vector;
std::rotate - rotates the vector,to be precise changes the elements
source code as a hint
  std::rotate(v.begin(), v.begin() + 1, v.end());
  before :  0 1 2 2 3 4 5 7 7 10 
  after the loop : 1 2 2 3 4 5 7 7 10 0
std::unique - removes all not unique elements
std::sort - sort vector by some algorithm
std::lower_bound - gives a lower bound , based on it we can make our case;


*/
//Run in other compiler hint!!!
using namespace std;
void printData(vector<double>& array)
{
    cout<<endl;
    std::cout << "--------------------" << endl;
    for( int i=0;i<array.size();i++ )
    {
        std::cout << array[i] << endl;
    }
}
int main()
{
    vector<double> array;
    const double data[]={ -1.37, 2.04, 4.98, 5.36, 8.88e-1, 2.47, -1.19e-1, -5.57e-1,
                          2.83, 5.38e-1, 4.69, 7.37, 3.78, 5.29, 6.30, 2.62, 2.60,
                          4.35, 5.31, 3.53, 7.64, 4.41e-1, 1.61, 4.71 };
    const int dataCount = sizeof( data ) / sizeof( data[0] );
    for (int i=0;i<dataCount;i++)
    {
        array.push_back( data[i] );
    }
    cout<<"The minimum value of the array is  = "<<*max_element(array.begin(), array.end())<<endl;
    cout<<"The maximum value of the array is  = "<<*min_element(array.begin(), array.end())<<endl;
    cout << "Mean =  " << accumulate(array.begin(), array.end(), 0.0) / (double)array.size()<<endl;
    cout << endl << "Number of elements smaller than 2 = " << count_if(array.begin(), array.end(), [](int i) {return i < 2; })<<endl;
    cout << endl << "Number of elements smaller than 4 = " <<count_if(array.begin(), array.end(), [](int i) {return i < 4; })<<endl;
    cout << endl << "Number of elements smaller than 6 =  " <<count_if(array.begin(), array.end(), [](int i) {return i < 6; })<<endl;
    sort(array.begin(),array.end());
    printData(array);
    cout<<"Lower than 2 = "<<lower_bound(array.begin(),array.end(),2)-array.begin();
    cout<<"Lower than 4 = "<<lower_bound(array.begin(),array.end(),4)-array.begin();
    cout<<"Lower than 6 = "<<lower_bound(array.begin(),array.end(),6)-array.begin();
    vector<double>copiedData(array);
    printData(copiedData);
    copiedData.resize(4*array.size());
    for(int i =0;i<4;i++)
    {
        copy(array.begin(),array.end(),copiedData.begin()+(array.size()*i+1));
    }

    printData(copiedData);
    sort(copiedData.begin(),copiedData.end());
    vector<double>::iterator it = unique(copiedData.begin(),copiedData.end());
    copiedData.resize(distance(copiedData.begin(), it));
    printData(copiedData);


}

