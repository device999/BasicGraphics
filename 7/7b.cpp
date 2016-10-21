#include<iostream>
#include <limits>
#include<vector>

using namespace std;
struct HeapElement //node
{
	double value; //value of the node
	HeapElement* parent; //parent of node
	HeapElement* child1; //left child
	HeapElement* child2; //right child

	HeapElement()
	{
		parent = child1 = child2 = NULL;
	};

};
class Heap3
{
	static const int max_elements = 1000;


public:
	vector<double> heap;
	int poz[max_elements];
	int aux[max_elements];

	
	int N;
	int NR;
	Heap3()
	{
	for (int i=0;i<max_elements;i++)
		{
			aux[i] = -1;
			poz[i]=-1;
		}
	N = -1;
	NR = -1;
	}
	
	int parent(int node)
	{
		return  node-1 / 2;
	}

	int left_child(int node)
	{
		return node * 2+1;
	}

	int right_child(int node)
	{
		return node * 2 + 2;

	}
	//the node must travel downwards in the tree
	void repair_upwards(int key)
	{
		int son = key;

		if (left_child(key) <= N && heap[left_child(key)] < heap[son])

			son = left_child(key);

		if (right_child(key) <= N && heap[right_child(key)] < heap[son])

			son = right_child(key);

		if (son != key)
		{
			swap(heap[key], heap[son]);
			swap(aux[key], aux[son]);
			poz[aux[key]] = key;
			poz[aux[son]] = son;
			repair_upwards(son);
		}
	}

	//the node must travel upwards in the tree
	void repair_downwards(int key)
	{
		while (key > 1 && heap[key] < heap[parent(key)])
		{
			swap(heap[key], heap[parent(key)]);
			swap(aux[key], aux[parent(key)]);
			poz[aux[key]] = key;
			poz[aux[parent(key)]] = parent(key);

			key = parent(key);
		}
	}

	void insert(int key)
	{
		NR++;
		N++;
		heap[N] = key;
		aux[N] = NR;
		poz[NR] = N;
		repair_downwards(N);
	}

	void pop(int key)
	{
		key = poz[key];
		heap[key] = heap[N];
		N--;
		if (key > 1 && heap [key] < heap[parent(key)] )
			repair_downwards(key);
		else
			repair_upwards(key);
	}

	double top()
	{
		if (heap.size() == 0)
		{
			cout << "heap is empty!" << endl << endl;
			return 0;
		}
		return heap[0];
	};
};

int main()
{
	Heap3 h2;

	//Heap1 h1(0);
	int values[20] = { 29, 49, 52, 26, 29, 89, 11, 91, 65, 68, 91, 44, 19, 74, 51, 77, 93, 90, 56, 28 };


	cout << "Creating a heap based on array" << endl;

	for (int i = 0; i < 20; i++)
	{
		cout << "Creating" << endl;
		h2.insert(values[i]);
	}
	for (int i = 0; i < 20; i++)
	{
        cout<<"hello";
		cout << h2.heap[i] << " ";
	}

	//getchar();
}

