#include <iostream>
#include <string>

using namespace std;

struct Element //used to store the list
{
	Element* _previous; //previous pointer (node)
	Element* _next; //next pointer(node)
	string value; //value of the initial node

	Element()
	{
		_previous = NULL;
		_next = NULL;
	}
};

//liniar list simple chained
class LinkedList
{
	private:
		Element* _head; // first element
		Element* _tail; //last element 
		unsigned int number_of_elements;
		public:
			LinkedList()
			{
				_head = NULL;
				_tail = NULL;
				number_of_elements = 0;
			}//constructor
			~LinkedList()
			{
				Element* cur = _head->_next;
				for (unsigned int i = 1; i < number_of_elements; i++)
				{
					if (cur->_previous != NULL)
					{
						delete cur->_previous;
					}
					cur = cur->_next;

				}

				delete _tail;
				_head = NULL;
				_tail = NULL;
				number_of_elements = 0;
			}//destructor

			Element* head() 
			{
				return _head;
			}//return first element
			Element* tail() 
			{
				return _tail;
			}//return last element
			int size() 
			{
				return number_of_elements;
			}// return number of elements

			Element* remove(Element* element) //remove element e, return the previous element
			{
				Element* ini = head();
				Element* elReturn = NULL;
				for (unsigned int i = 0; i < number_of_elements; i++)
				{
					if (ini->value == element->value)
					{
						if (ini->_previous != NULL)
						{
							ini->_previous->_next = ini->_next;
							if (ini == _tail)
							{
								_tail = ini->_previous;	
							}
						}
						if (ini->_next != NULL)
						{
							ini->_next->_previous = ini->_previous; //move links
							if (ini == head())
							{
								_head = ini->_next;	
							}
						}
						elReturn = ini->_previous;
						delete ini;
						number_of_elements--;
						break;
					}
					else
					{
						ini = ini->_next;
					}
						
				}
		
			return elReturn;
			}

			/* insert element at head, tail or inside the list */
			Element* insert(Element* previous, string value)
			{
				Element* insertion = new Element();
				insertion->value = value;
				if ( previous == NULL )
				{
					if ( head() != NULL )
					{
						insertion->_next = head();
						_head->_previous = insertion;
					}
					else
					{
						_tail = insertion;
					}
					_head = insertion;
					number_of_elements++;
					return insertion;
				}
				Element* current = previous;
						insertion->_previous = current;
						insertion->_next = current->_next;
						if (current != _tail)
							current->_next->_previous = insertion;
						else
							_tail = insertion;
						current->_next = insertion;
						number_of_elements++;
				return insertion;
			}

			void clear() // clear elements
			{
				Element* cur = _head->_next;

				for (unsigned int i = 1; i < number_of_elements; i++)
				{
					if (cur->_previous != NULL)

						delete cur->_previous;

					cur = cur->_next;

				}

				delete _tail;
				_head = NULL;
				_tail = NULL;
				number_of_elements = 0;
			}

						void print() // print contents
			{
				Element* current = head();

				if (number_of_elements > 0)
				{
					for (int i = 0; i < (int)number_of_elements ; i++)
					{
						cout << "The value of " << i << "-st element is = " << current->value << " "<< endl;
						current = current->_next;
					}
					cout << endl;
				}
				else
				{
					cout << ":(((( List is empty " << endl;
				}
			}
	int remove_value(string value)
			{
				Element* element = new Element();
				int countOfElements = 0;
				element->value = value;

				while (true)
				{
					int listLength = number_of_elements;

					remove(element);
					//exit if there are no further removals
					if (listLength == number_of_elements)
						break;

					countOfElements++;
				}
				return countOfElements;
			}
	void insert_sorted(string value)
			{
				Element* current = head();
				unsigned int i;

				if (number_of_elements == 0)
				{
					insert(NULL, value);
					return;
				}

				for (i = 0; i < number_of_elements; i++)
				{
					if ((current->value).compare(value) > 0) 
					{
						insert(current->_previous, value);
						break;
					}
					current = current->_next;
				}

				if (i == number_of_elements)
				{
					insert(_tail, value);	
				}
			}
};
void TaskC()
{
	LinkedList* zoo = new LinkedList();
	zoo->insert(zoo->tail(), "wolverine");
	zoo->print();
	zoo->insert(zoo->tail(), "chicken");
	zoo->print();
	zoo->insert(zoo->tail(), "turtle");
	zoo->print();
	zoo->insert(zoo->tail(), "dog");
	zoo->print();
	zoo->insert(zoo->tail(), "snail");
	zoo->print();
	zoo->insert(zoo->tail(), "cat");
	zoo->print();
	zoo->insert(zoo->tail(), "sardine");
	zoo->print();
	zoo->insert(zoo->tail(), "zebra");
	zoo->print();
	zoo->insert(zoo->tail(), "dog");
	zoo->print();
	zoo->insert(zoo->tail(), "snail");
	zoo->print();
	zoo->insert(zoo->tail(), "dog");
	zoo->print();
	zoo->clear();
	cout << "Zoo cleaned " << endl;
	zoo->print();
}

void TaskD()
{
	LinkedList* zoo = new LinkedList();
	zoo->insert(zoo->tail(), "wolverine");
	zoo->insert(zoo->tail(), "chicken");
	zoo->insert(zoo->tail(), "turtle");
	zoo->insert(zoo->tail(), "dog");
	zoo->insert(zoo->tail(), "snail");
	zoo->insert(zoo->tail(), "cat");
	zoo->insert(zoo->tail(), "sardine");
	zoo->insert(zoo->tail(), "zebra");
	zoo->insert(zoo->tail(), "dog");
	zoo->insert(zoo->tail(), "snail");
	zoo->insert(zoo->tail(), "dog");
	zoo->print();
	cout << "Dog is removed" << endl;
	zoo->remove_value("dog");
	zoo->print();
	cout << "Wolverine is removed " << endl;
	zoo->remove_value("wolverine");
	zoo->print();
	cout << endl;
}
void TaskE()
{
	LinkedList* zoo = new LinkedList();
	cout << "Zoo members: " << endl;
	zoo->insert_sorted("wolverine");
	zoo->print();
	zoo->insert_sorted("chicken");
	zoo->print();
	zoo->insert_sorted("turtle");
	zoo->print();
	zoo->insert_sorted("dog");
	zoo->print();
	zoo->insert_sorted("snail");
	zoo->print();
	zoo->insert_sorted("cat");
	zoo->print();
	zoo->insert_sorted("sardine");
	zoo->print();
	zoo->insert_sorted("zebra");
	zoo->print();
	zoo->insert_sorted("dog");
	zoo->print();
	zoo->insert_sorted("snail");
	zoo->print();
	zoo->insert_sorted("dog");
	cout << "Animals of the our zoo are : " << endl;
	zoo->print();
}
void TaskF()
{
	LinkedList* zoo = new LinkedList();
	string animalToBeAdded;

	zoo->insert_sorted("wolverine");
	zoo->insert_sorted("chicken");
	zoo->insert_sorted("turtle");
	zoo->insert_sorted("dog");
	zoo->insert_sorted("snail");
	zoo->insert_sorted("cat");
	zoo->insert_sorted("sardine");
	zoo->insert_sorted("zebra");
	zoo->insert_sorted("dog");
	zoo->insert_sorted("snail");
	zoo->insert_sorted("dog");
	cout << "The initial zoo is is: " << endl;
	zoo->print();

	while (true)
	{
		cout << endl << "Which animal to add? Enter name: ";
		cin >> animalToBeAdded;

		if (zoo->remove_value(animalToBeAdded) == 0)
		{
			zoo->insert_sorted(animalToBeAdded);
		} //is there more than one element in the zoo?
			

		cout << "The resulting zoo is after adding  " << animalToBeAdded << "  is: "  << endl;
		zoo->print();
	}
}

/*

TASK g

Algorithmic complexity:
 inserting front/back- O(1)
 removing front/back- O(1)
 inserting sorted - O(N) (you need to increment until you get to the position you want )
 remove by value- O(N)
 accessing by index- O(N)


TASK h

As a data structure, linked lists have advantages over arrays.

Insert:
linked list => O(1)
array => O(n)

Accessing elements
linked list => O(n)
array => O(1) (access directly element & secquential)

Storage
linked list =>  better for storing large data items


It's easier to store data of different sizes in a linked list. An array assumes every element is exactly the same size.

As you mentioned, it's easier for a linked list to grow organically. 
An array's size needs to be known ahead of time, or re-created when it needs to grow.

Shuffling a linked list is just a matter of changing what points to what. Shuffling an array is more complicated and/or takes more memory.

As long as your iterations all happen in a "foreach" context, you don't lose any performance in iteration.
*/


int main()
{
	int number;
    while(true)
    {
        cout << "Please choose the assignment" << endl;
        cout << "1  --- Assignment-c		" << endl;
        cout << "2  --- Assignment-d	" << endl;
        cout << "3  --- Assignment-e	" << endl;
        cout << "4  --- Assignment-f	" << endl;
        cout << "0  --- Exit program  	    " << endl;
        cout << "------------------------------------" << endl;
        cin >>number;
        switch(number)
        {

            case 0: return(0);break;
            case 1: TaskC();break;
            case 2: TaskD();break;
            case 3: TaskE();break;
            case 4: TaskF();break;
		}
	}
}

