#include<iostream>
using namespace std;
//calculate mean: add the numbers and divide by counter 
float mean(float* num, int counter)
{
	float sum=0;
	for(int i=0; i < counter; i++){
		sum+= num[i];
	}
	return sum/counter;
	
}

//calculate variance = The average of the squared differences from the Mean 
float variance(float* num, int counter)
{
	float meanOfNumbers = mean(num, counter);
	float sum=0;
	for(int i=0; i < counter; i++){
		sum+= (meanOfNumbers-num[i])*(meanOfNumbers-num[i]);
	}
	return sum/counter;
}

int main(int argc, char** argv)
{
	int counter;
	std::cout << "Numbers :  " << endl;
	std::cin >> counter;
	float* array = new float[counter];

	for(int i=0;i<counter;i++) {
		std::cout << "Number " << i+1 << "=" ;
		std::cin >> array[i];
	}
	std::cout << " Mean : " << mean(array,counter) << endl;
	std::cout << " Variance : "<<  variance(array,counter) << endl;
	cin.get();
	delete[] array;
	getchar();
	return 0;
	exit(0);
}
