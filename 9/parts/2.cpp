#include<algorithm>
#include<iostream>
#include<math.h>
#include<list>
#include<map>
#include<string>
#include<vector>
using namespace std;
/*
std::min, std::max, std::min_element,
std::max_element, std::accumulate

*/
double mean(vector<double>& array)
{
	int size = array.size();
	double accumulator = 0;
	for( int i=0;i<array.size();i++ )
	{
		accumulator = accumulator + array[i];
	}
	return accumulator/size;
}
double deviation(vector<double>& array)
{
	double meanValue = mean(array);
	double sum = 0;
	for(int i=0;i<array.size();i++)
	{
		sum = (array[i]-meanValue)*(array[i]-meanValue);
	}
	return sqrt(sum/array.size());
}

double minValue(vector<double>& array)
{
	double value = 100;
	for( int i=0;i<array.size();i++ )
	{
		if(array[i]<value)
		{
			value = array[i];
		}
	}
	return value;
}

double maxValue(vector<double>& array)
{
	double value = -100;
	for( int i=0;i<array.size();i++ )
	{
		if(array[i]>value)
		{
			value = array[i];
		}
	}
	return value;
}

void printData(vector<double>& array)
{
	std::cout << "--------------------" << endl;
	for( int i=0;i<array.size();i++ )
	{
		std::cout << array[i] << endl;
	}
}
void smaller(vector<double>& array,double arr[])
{
	
	for(int j=0;j<3;j++)
	{
		for( int i=0;i<array.size();i++ )
		{
			if (array[i]<arr[j])
			{
				cout<<"The number = "<<array[i]<<"is smaller than = "<<arr[j]<<endl;
			}
		}
		cout<<"-------------------------------"<<endl;
	}
}
int main()
{
	vector<double> array;
	const double data[] = {
-1.37, 2.04, 4.98, 5.36, 8.88e-1, 2.47, -1.19e-1, -5.57e-1,
2.83, 5.38e-1, 4.69, 7.37, 3.78, 5.29, 6.30, 2.62, 2.60,
4.35, 5.31, 3.53, 7.64, 4.41e-1, 1.61, 4.71 };
const int dataCount = sizeof( data ) / sizeof( data[0] );
for (int i=0;i<dataCount;i++)
{
	array.push_back( data[i] );
}
printData(array);
double valueSecond = array[2];
array.erase(array.begin()+2);
printData(array);
array.insert(array.begin() + 7, valueSecond);
printData(array);
std::cout << "Minimum value" << endl;
cout<<minValue(array) <<endl;
std::cout << "Maximum value" << endl;
cout<<maxValue(array) <<endl;
std::cout << "Mean value" << endl;
cout<<mean(array) <<endl;
std::cout << "Standard deviation value" << endl;
cout<<deviation(array) <<endl;
double boundaries[]={2,4,6};
std::cout << "--------------------" << endl;
smaller(array,boundaries);



}
