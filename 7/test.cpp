#include<iostream>
#include <limits>
#include<vector>

using namespace std;

/*
	1)For any node in the tree, the node is larger than
	its children.
	2)Every level of the tree except for the leaves is full.
	3)The leaf level of the tree is full from the leftmost leaf
	to the last leaf. (In other words, the last level is filled
	left to right.)
*/


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

void swap_element_values(HeapElement* e1, HeapElement* e2) // swap element values
{
	HeapElement* aux = e1;
	e1 = e2;
	e2 = aux;
}
class Heap1
{
	HeapElement* head;

public:
	Heap1()
	{
		head = NULL; //init
	}

	~Heap1()
	{
		while (head != NULL)
			pop_top();
	}
	/*
		An element is inserted at the bottom of the tree
		The heap property is then repaired
	*/
	HeapElement* ins(HeapElement* r, double d)
	{
		if (r == NULL)
		{
			r = make_heap_element(d);
			return r;
		}
		else if (d < r->value) r->child1 = ins(r->child1, d);
			else if(d > r->value)  r->child2 = ins(r->child2, d);
	}

	void insert(double d) // inserts value d into the Heap1
	{
		HeapElement* nod = make_heap_element(d);

		if (head == NULL)
		{
			head = nod;
			return;
		}
		//What we do is take the last element in the heap the rightmost leaf and insert it as the root
		HeapElement* parent = head;

		while (head)
		{
			char position = 3% 2;
			HeapElement* child;

			if (position == 0)
				child = parent->child1;
			else
				child = parent->child2;

			if (child == NULL)
			{
				nod->parent = parent;
				if (position == 0)
					parent->child1 = nod;
				else
					parent->child2 = nod;
				break;
			}
			parent = child;
		}

		while (parent != NULL)
		{
			if (parent->value > nod->value)
			{
				swap_element_values(nod, parent);
				nod = parent;
			}
			else
			{
				parent = parent->parent;
			}
		}
	}

	HeapElement* make_heap_element(double d) //create a new heap element
	{
		HeapElement* x;

		x = new HeapElement;
		x->value = d;

		x->child1 = NULL;
		x->child2 = NULL;

		return x;
	}

	bool is_empty() const // returns whether the heap is empty
	{
		if (head == NULL)
			return true;
		return false;
	}

	double top() const // returns the smallest element
	{
		if (is_empty() == false)
			return head->value;

		cout << "The heap is empty! " << endl;
		return 0;
	}

	void pop_top() // removes the smallest element
	{
		if (is_empty() == false)
		{
			HeapElement* current = head;
			while (true)
			{
				char position = 3 % 2;
				HeapElement* child;

				if (position == 0 && current->child1 != NULL)
					child = current->child1;
				else
				{
					child = current->child2;

					if (child == NULL && current->child1 != NULL)
						child = current->child1;
				}

				if (child == NULL)
				{
					if (current == head)
					{
						delete current;
						head = NULL;
						break;
					}

					head->value = current->value;
					HeapElement* parent = current->parent;

					if (parent->child1 == current)
						parent->child1 = NULL;
					else
						parent->child2 = NULL;
					delete current;
					break;
				}
				current = child;
			}

			bool exists_right = true;
			current = head;

			while ( exists_right )
			{
				if (current->child1 == NULL && current->child2 == NULL)
					break;

				int position = 0;
				double value = current->value;

				if (current->child1 != NULL && current->child1->value < value)
				{
					position = 1;
					value = current->child1->value;
				}

				if (current->child2 != NULL && current->child2->value < value)
				{
					position = 2;
				}

				switch (position)
				{
					case 1:

						swap_element_values(current, current->child1);

					case 2:

						swap_element_values(current, current->child2);
				}

				exists_right = false;
			}
		}
	}



	void print() // prints the heap?
	{
		while (head != NULL)
		{
			if (head->child1 != NULL || head->child2 != NULL)
			{
				cout << head->child1->value;
				cout << head->child2->value;
				pop_top();//repeatedly remove the root
				//re-heapify the rest of the heap
			}
			break;
		}
	}

private:
	HeapElement* find_leaf()// find some leaf (element without children)
	{
		if (head == NULL)
			return head;
		HeapElement* current = head;

		if (current->child1 == NULL && current->child2 == NULL)
			return current;

	}

	HeapElement* insert_as_leaf(double d) // insert a value as leaf, return the element
	{
		HeapElement* x;

		x = new HeapElement;
		x->value = d;

		x->child1 = NULL;
		x->child2 = NULL;

		return x;
	}
};



/*
	Complexities:

	Tree:

	Remove element ->	The depth of the tree is lg(n), where n is the number of values in the tree.
						So we do at most lg(n) swaps so the cost of removing the largest element
						is O(lg n).


	Add element	  ->	It's basically the inverse of removing the root; its a swift up
						We insert the value into the position	after the last leaf.
						Then we compare the leaf to its parent. If it's
						larger than its parent, we swap the node with its parent. And we repeat going
						up the tree.
						So again, we're looking at a maximum of lg(n) swaps to
						do an insert. So we're using O(lg n) for insert.


	Array:


*/

//move these functions up, otherwise there will be identifier not found

void repair_upwards(HeapElement* child); // assure the heap property upwards
void repair_downwards(HeapElement* parent); // assure the heap property downwards


int main()
{
	Heap1 h1;

	//Heap1 h1(0);
	HeapElement* rad;
	rad = NULL;

	int values[20] = { 29, 49, 52, 26, 29, 89, 11, 91, 65, 68, 91, 44, 19, 74, 51, 77, 93, 90, 56, 28 };

	cout << "Heap1 tree:" << endl;

	for (int i = 0; i < 20; i++)
	{
		h1.insert(values[i]);
		h1.print();
		cout << h1.top() << " ";
		h1.pop_top();
	}

	cout << "Creating a heap based on array" << endl;
/*
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
*/
	//getchar();
}
