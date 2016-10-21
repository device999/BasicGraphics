#include <limits>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct HeapElement {
	double value;
	HeapElement* parent;
	HeapElement* child1;
	HeapElement* child2;
	HeapElement()
	{
		parent = child1 = child2 = NULL;
	};
};
void swap_element_values(HeapElement* e1, HeapElement* e2)
{
	HeapElement* middle = e1;
	e1 = e2;
	e2 = middle;
} // swap element values
void repair_upwards(HeapElement* child); // assure the heap property upwards
void repair_downwards(HeapElement* parent); // assure the heap property downwards
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
				pop_top();			
			}
		}
		bool is_empty() const
		{
			if(head==NULL)
			{
				return true;
			}
			return false;
		} // returns whether the heap is empty
		double top() const
		{
			if (is_empty() == false)
			{
			return head->value;	
		}
		cout << "The heap is empty! " << endl;
		return 0;
		} // returns the smallest element
		void insert( double d )
		{
			double changeValue;
			if(head==NULL)
			{
				head = new HeapElement;
				head->value = d;
				head->parent=NULL;
		        head->child1 = NULL;
		        head->child2 = NULL;
				
			}
			else
			{
				HeapElement* neueParent = head;
				HeapElement* neue = new HeapElement;
				while(neueParent->child1!=NULL && neueParent->child2!=NULL)
				{
					if(rand()%2==0)
					{
						neueParent = neueParent->child1;
					}
					else
					{
						neueParent=neueParent->child2;
					}
				}
				if(neueParent->child1==NULL)
				{
					neueParent->child1 = neue;
				}
				else
				{
					neueParent->child2 = neue;
				}
				neue->parent = neueParent;
				neue->value = d;
				neue->child1 = NULL;
				neue->child2 = NULL;
				while(neueParent!=NULL && neueParent->value > neue->value)
				{
					changeValue = neueParent->value;
					neueParent->value = neue->value;
					neue->value = changeValue;
					neue = neueParent;
					neueParent = neue->parent;
				}
			}
		} // inserts value d into the heap
		void pop_top()
		{
		 if (head == NULL){
        cout << "The heap is already empty." << endl;
    }
    else if (head->child1 == NULL && head->child2 ==NULL){
        delete head;
        head = NULL;
    }
    else{
        HeapElement* leaf =  head;
        //find a leaf node
        while (leaf->child1 != NULL || leaf->child2 != NULL){ //if it has child
            if (leaf->child1 != NULL && leaf->child2 != NULL){ //if has two children
                if (rand() % 2 == 0){
                    leaf = leaf->child1;
                }
                else{
                    leaf = leaf->child2;
                }
            }
            else if (leaf->child1 != NULL){
                leaf = leaf->child1;
            }
            else{ leaf = leaf->child2; }
        }

        //cut the leaf
        if (leaf == leaf->parent->child1){
            leaf->parent->child1 = NULL;
        }
        else{
            leaf->parent->child2 = NULL;
        }

        //change head to the leaf
        leaf->parent = NULL;
        leaf->child1 = head->child1;
        leaf->child2 = head->child2;

        // change the parents of childs of previous head
        if (head->child1 != NULL){
            head->child1->parent = leaf;
        }
        if (head->child2 != NULL){
            head->child2->parent = leaf;
        }

        delete head;
        head = leaf;
        //swap
        HeapElement* small_child = new HeapElement;
        double temp;
        while (leaf->child1 != NULL || leaf->child2 != NULL){
            if (leaf->child1 != NULL){
                small_child = leaf->child1;
                if (leaf->child2 != NULL && leaf->child2->value < leaf->child1->value){
                    small_child = leaf->child2;
                }
            }
            else{ small_child = leaf->child2; }
            if (leaf->value > small_child->value){
                temp = small_child->value;
                small_child->value = leaf->value;
                leaf->value = temp;
            }
            leaf = small_child;
        }

    }
	
		}
		// removes the smallest element
		void print()
		{
		while (head != NULL)
		{
			if (head->child1 != NULL || head->child2 != NULL)
			{
				cout << head->child1->value<<endl;
				cout << head->child2->value<<endl;
				pop_top();
			}
			break;
		}
		}
	private:
		HeapElement* find_leaf()
		{
			HeapElement* leaf =  head;
	        while (leaf->child1 != NULL || leaf->child2 != NULL)
			{ //if it has child
	            if (leaf->child1 != NULL && leaf->child2 != NULL){ //if has two children
	                if (rand() % 2 == 0){
	                    leaf = leaf->child1;
	                }
	                else{
	                    leaf = leaf->child2;
	                }
	            }
	            else if (leaf->child1 != NULL){
	                leaf = leaf->child1;
	            }
	            else{ leaf = leaf->child2; }
	        }
	        cout<<leaf->value<<endl;
		} // find some leaf (element without children)
		HeapElement* insert_as_leaf(double d)
		{
		HeapElement* x;

		x = new HeapElement;
		x->value = d;
		x->child1 = NULL;
		x->child2 = NULL;

		return x;
		} // insert a value as leaf, return the element
};



int main()
{
	Heap heap;
    // example input
    double input[20] = { 29, 49, 52, 26, 29, 89, 11, 91, 65, 68, 91, 44, 19, 74, 51, 77, 93, 90, 56, -5 };
    for (int i = 0; i < 20; i++){
        heap.insert(input[i]);//data is inserted into an heap
    }    
    for (int i = 0; i < 20; i++){
        cout<<heap.top()<<endl;
    	heap.pop_top();
    }
    //heap.print();
}

/*
task c:
	Remove	->	The depth of the tree is lg(n), where n is the number of values in the tree.
						So we do at most lg(n) swaps so the cost of removing the largest element
						is O(lg n).
						
	Add element	  ->	It's basically the inverse of removing the root; its a swift up
						We insert the value into the position	after the last leaf.
						Then we compare the leaf to its parent. If it's
						larger than its parent, we swap the node with its parent. And we repeat going
						up the tree.
						So again, we're looking at a maximum of lg(n) swaps to
						do an insert. So we're using O(lg n) for insert.


*/
