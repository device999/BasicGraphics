#include<iostream>
#include <limits>
#include<vector>

using namespace,std;

struct HeapElement {
    double value;
    HeapElement* parent;
    HeapElement* child1;
	HeapElement* child2;
	HeapElement
	{
		parent=NULL;
		child1 = NULL;
		child2=NULL;
	}
};
class Heap {
	HeapElement* head;
	public:
		Heap()
		{
			head = NULL;
		}
		~Heap()
		{
			while(head!=NULL)
			{
				
			}
		}
		bool is_empty() const
		{
			if (head==NULL)
			{
				return true;
			}
			else
			{
				return false;
			}
		}		// returns whether the heap is empty
		double top() const
		{
			if(is_empty())
				return NULL;
			else:
				return head->value;
		}		// returns the smallest element
		void insert( double d )
		{
			HeapElement* neue = insert_as_leaf(d);
			if (head==NULL)
			{
				head = neue;
				return;
			}
		}		// inserts value d into the heap
		void pop_top()
		{
			if(is_empty()===false)
			{
				HeapElement* removed = head;
				while(true)
				{
					HeapElement* kid;
					int position = rand() % 2;
					if (position ==1 && removed->child1=!NULL)
					{
						kid = removed->child1;
						
					}
					else
					{
						kid = removed->child2;
						if(kid==NULL && removed->child1!=NULL)
						{
							kid = removed->child1;
						}
					}
					
				}
			}

				
		}		// removes the smallest element
		void print()
		{
			if(is_empty()===false)
		}
	private:
		HeapElement* find_leaf()
		{
			if (head==NULL)
			{
				return head;
			}
			HeapElement* leaf = head;
			while(true)
			{
				if (leaf->child1 == NULL && leaf->child2 == NULL)
				{
					return leaf;
				}
				else
				{
					leaf = leaf->child1;
				}
			}
		}		// find some leaf (element without children)
		HeapElement* insert_as_leaf(double d)
		{
			HeapElement* add;
			add = new HeapElement;
			add->value = d;
			add->child1 = NULL;
			add->child2=NULL;
			return add;
		}		// insert a value as leaf, return the element
};
void swap_element_values(HeapElement* e1, HeapElement* e2)
{
	Heap Element* middlevalue;
	middlevalue = e1;
	e1 = e2;
	e2 = middlevalue;
} // swap element values
void repair_upwards(HeapElement* child)
{
	
} // assure the heap property upwards
void repair_downwards(HeapElement* parent)
{
	
} // assure the heap property downwards
