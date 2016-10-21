#include<iostream>
/*google	*/
#include<iomanip>
using namespace std;
class DynamicDoubleArray {
	public:
	DynamicDoubleArray(int length=0)
	{
		if (length!=0)
		{
			double* arr = new double[length];
		}
		else
		{
			arr=NULL;
		}
		this->length = length;
	}
	~DynamicDoubleArray()
	{
		if (length!=0)
		{
			delete[] arr;
		}
	}
	int get_size()
	{
		return length;
	} 
	// get the number of elements stored inside the array
	double& at(int idx)
	{
		if ((idx>-1) && (idx<length))
		{
			return arr[idx];	
		}
		
	}
	 // access the element positioned at idx
	void push_back(double d)
	{
		double* newArr = new double[length+1];
		
		for (int i=0;i<length;i++)
		{
			newArr[i]=arr[i];
		}
		newArr[length]=d;
		delete[] arr;
		arr=newArr;
		length = length+1;
	}
	 // adds a new element to the array
	void remove(int idx)
	{
		double* newArr = new double[length-1];

		for (int i = 0; i < idx; i++)
		{
			newArr[i] = arr[i];	
		}

		for (int i = idx + 1; i < length; i++)
		{
			newArr[i-1] = arr[i];
		}		
		delete[] arr;
		arr=newArr;
		length = length-1;
	}
	 // remove the element at idx from the array
	void clear()
	{
		if (length!=0)
		{
			delete[] arr;
			length = 0;
		}
	}
	private:
	double* arr;
	int length;
};
void bubbleSortIndicesA(double* data,int size)
{
	int time;
	bool end = false;
	while (!end)
	{
		end = true;
		for (int i=0;i<size-1;i++)
		{
			if (data[i] > data[i+1])
			{
				time = data[i+1];
				data[i+1] = data[i];
				data[i] = time;
				end=false;
			}
		}	
	}
	cout<<"Sorted array"<<endl;
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << "  ";
	}
	cout << endl;

}
void bubbleSortIndicesPointer(double* data,int size)
{
	int time;
	bool end = false;
	while (!end)
	{
		end = true;
		for (int i=0;i<size-1;i++)
		{
			if (*(data + i) > *(data + i+1))
			{
				time =*(data + i+1);
				*(data + i+1)= *(data + i);
				*(data + i) = time;
				end=false;
			}
		}	
	}
	cout<<"Sorted array"<<endl;
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << "  ";
	}
	cout << endl;
}
void joinSortedC(double* left,int sizeLeft, double* right, int sizeRight, double* output)
{
	int lCounter = 0;
	int rCounter = 0;
	int Counter = 0;
	while (lCounter<sizeLeft && rCounter<sizeRight)
	{
		if (left[lCounter]<right[rCounter])
		{
			output[Counter] = left[lCounter];
			lCounter = lCounter+1;
			Counter = Counter+1;
		}
		else
		{
			output[Counter] = right[rCounter];
			rCounter = rCounter+1;
			Counter = Counter+1;
		}
	}
	//case when one array is finished
	if (rCounter < sizeRight)
	{
		for (int i = rCounter; i < sizeRight; i++)
		{
			output[Counter] = right[i];
			Counter++;
		}
	}
	else
	{
		for (int i = lCounter; i < sizeLeft; i++)
		{
			output[Counter] = left[i];
			Counter++;
		}
	}
}
void mergeSortD(double* data,int size)
{
	int leftSize=0;
	int rightSize=0;
	if (size <= 1)
	{
		return;	
	}	
	else
	{
		leftSize = size/2;
		rightSize = size - leftSize;
		double* left = new double[leftSize];
		double* right = new double[rightSize];
		for (int i = 0; i < leftSize; i++)
		{
			left[i] = data[i];
		}
		mergeSortD(left, leftSize);
		for (int i = 0; i < rightSize; i++)
		{
			right[i] = data[leftSize + i];			
		}
		mergeSortD(right, rightSize);

		joinSortedC(left, leftSize, right, rightSize, data);
		//free memory
		delete[] left, right;
	}
	cout<<"Sorted array"<<endl;
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << "  ";
	}
	cout << endl;
}

int main() {

	DynamicDoubleArray arr;
	//add ten elements to the array
	arr.push_back(0.71);
	arr.push_back(2.43);
	arr.push_back(8.4);
	arr.push_back(7.2);
	cout << "Size of the array is =  " << arr.get_size() <<endl;
	
	for (int i = 0; i < arr.get_size(); i++)
	{
		cout << "Member  " << i<<" is = " <<  arr.at(i)<< endl;	
	}
	cout << endl;
	//remove the first element of the array
	cout << endl;
	int r= 1;
	cout << "Removing the  " << r << " element of the array ... "  <<endl;
	arr.remove(r);
	cout << "Size of the array after removing one element is =  " << arr.get_size() <<endl;
	for (int i = 0; i < arr.get_size(); i++)
	{
		cout << "Member  " << i<<" is = " <<  arr.at(i)<< endl;	
	}
	cout << endl;
		//use the clear function: remove all elements
	cout << "Clearing the members " << endl;
	arr.clear();
	cout << "Size after cleaning =  " << arr.get_size() << " ... " << endl;

	cout << "Adding new members  "<< endl;
	//add back other ten elements to the array
	arr.push_back(2.5);
	arr.push_back(-0.165);
	cout << "New size of the array is =  " << arr.get_size() << " ... " << endl;
	for (int i = 0; i < arr.get_size(); i++)
	{
		cout << "Member  " << i<<" is = " <<  arr.at(i)<< endl;	
	}
	cout << endl;
	//We are doing sheet 2;
	cout <<"------------------------------------------" <<endl;
	cout <<"Sheet 2" <<endl;
	cout <<"Buble sort" <<endl;	
	int size = 10;
	double data [size] = { 16.5, 2.3, 77.4, 40.6, 12.71,5.6,6.777,9.81,10,11.5 }; 
	bubbleSortIndicesA(data,size);
	cout <<"------------------------------------------" <<endl;
	cout <<"Buble sort with pointer" <<endl;
	bubbleSortIndicesPointer(data,size);
	cout <<"------------------------------------------" <<endl;
	cout <<"Merge Sort" <<endl;
	mergeSortD(data,size);
	
}
/*
Task1 c and d:
	push_back()=>O(length)
	get_size()= O(1)
	at() = O(1)
	remove() = O(length)
	clear()	= O(1)


	Algorithmic complexity:
	Bubble sort => O(N^2)
	Merge sort => O(N*log(N))
*/
