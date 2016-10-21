#include<algorithm>
#include<iostream>
#include<list>
#include<map>
#include<string>
#include<vector>
using namespace std;
void c1()
{
	list<double> linkedList;
	
	
	linkedList.push_back( 29 );
	linkedList.push_back( 49 );
	linkedList.push_back( 52 );
	linkedList.push_back( 26 );
	linkedList.push_back( 89 );
	for (list<double>::iterator it1 = linkedList.begin(); it1 != linkedList.end(); ++it1)
	{
		cout << *it1 << " ";
	}
	std::cout << endl;
	//Iteration with pointers;
	for (double* it1 = &(linkedList.front()); it1 != &(linkedList.front()) +linkedList.size(); ++it1)
	{
		cout << *it1 << " ";
	}
	cout << endl;
	//end
	linkedList.pop_front();
	linkedList.pop_front();
	linkedList.push_front(29);
	linkedList.push_front(49);
	list<double>::iterator it = linkedList.begin();
	++it;
	swap(*(++it), *(++it));
	
	for (list<double>::iterator it1 = linkedList.begin(); it1 != linkedList.end(); ++it1)
	{
		cout << *it1 << " ";
	}
	cout << endl;
}

void as2()
{
	  vector<string> arr;
	  string str ("manchmal hat man eine sehr lange strasse vor sich"
		"man denkt die ist so schrecklich lang"
		"das kann man niemals schaffen denkt man"
		"und dann faengt man an sich zu eilen"
		"und man eilt sich immer mehr"
		"jedes mal wenn man aufblickt"
		"sieht man dass es gar nicht weniger wird"
		"was noch vor einem liegt"
		"und man strengt sich noch mehr an"
		"man kriegt es mit der angst"
		"und zum schluss ist man ganz auBer puste"
		"und kann nicht mehr"
		"und die strasse liegt immer noch vor einem"
		"so darf man es nicht machen"
		"man darf nie an die ganze strasse auf einmal denken verstehst du"
		"man muss nur an den naechsten schritt denken"
		"an den naechsten atemzug an den naechsten besenstrich"
		"und immer wieder nur an den naechsten"
		"dann macht es freude das ist wichtig"
		"dann macht man seine sache gut"
		"und so soll es sein");
	  string delim(" ");
	  size_t prev = 0;
	  size_t next;
	  size_t delta = delim.length();
	
	  while( ( next = str.find( delim, prev ) ) != string::npos ){
	    
	    string tmp = str.substr( prev, next-prev );
	    cout << tmp << endl;
	    
	    arr.push_back( str.substr( prev, next-prev ) );
	    prev = next + delta;
	  }
	  
	  string tmp = str.substr( prev );
	  cout << tmp << endl;
	  
	  arr.push_back( str.substr( prev ) );
	  cout << "Printing..." << endl;
	  for (int i=0;i<arr.size();i++)
	  {
	  	cout <<arr[i]<< " ";
	  }
	  cout << endl;
	  sort(arr.begin(),arr.end());
	  cout << "Sorting..." << endl;
		for (int i=0;i<arr.size();i++)
	  {
	  	cout <<arr[i]<< " ";
	  }
	cout <<endl << "Done sorting words!" << endl;
	//Unique words:
	vector<string> uniqueW =arr ;
	vector<string>::iterator it1;
	it1 = unique(uniqueW.begin(), uniqueW.end());
	cout << "Processing unique words... " << endl;
	uniqueW.resize(distance(uniqueW.begin(), it1));
	for (int i=0;i<uniqueW.size();i++)
	  {
	  	cout <<uniqueW[i]<< " ";
	  } 
	  cout<<endl;
	  //end of unique words;
	  	//d) Iterating over both arrays at once, count the number of occurrences of each word in a vector<int>
	//	counts.
	vector<int> counts; //using vector<int> counts as requested in exercise

	cout << "Processing word count... " <<endl;
	//it1 has a ptr (size+capacity+each letter of word+count)
	for (it1 = uniqueW.begin(); it1 != uniqueW.end(); ++it1)
	{
		//count: count elements that match _Val
		int word_count = count(arr.begin(), arr.end(), (*it1).c_str());

		counts.push_back(word_count); //insert element at the end
		//e) For words appearing more than once, output a sorted list of unique strings with their usage count
		if (word_count > 1)
			cout << "Word = " << (*it1).c_str() << " appears " << counts.at(counts.size() - 1) << " time(s) " << endl << endl;
	}

	cout << endl << "Done processing word count!" << endl;
}
void process(const string& long_string, const string& separator, string::size_type& start, string::size_type& end)
{
	//Find absence of character in string
	//Searches the string for the first character that does not match any of the characters specified in its arguments.

	start = long_string.find_first_not_of(separator, 0);

	// Find character in string
	//Searches the string for the first character that matches any of the characters specified in its arguments.
	//When end is specified, the search only includes characters at or after position end,
	//ignoring any possible occurrences before end.
	end = long_string.find_first_of(separator, start);
}
void a3(const string& long_string, map<string, int>& words, const string& separator = " ")
{
	string::size_type start;
	string::size_type end;
	map<string, int>::iterator iterator;

	process(long_string, separator, start, end);

	do
	{
		// find an element in mutable sequence that matches _Keyval
		//iterator - (denkt,1) (for example)
		iterator = words.find(long_string.substr(start, end - start));
		if (iterator != words.end())
			(*iterator).second++; //increment word count
		else
			words[long_string.substr(start, end - start)] = 1;	//fill vector with iterator

		start = long_string.find_first_not_of(separator, end);
		end = long_string.find_first_of(separator, start);

	} while (end != string::npos || start != string::npos);
}

void as3(string long_string)
{
		map<string, int>::iterator it1;
		map<string, int> words;
		a3(long_string, words);
		cout << "Sorting the words... " << endl << endl;

	for (it1 = words.begin(); it1 != words.end(); ++it1)

		for (size_t i = 0; i < (*it1).second; i++)
			cout << (*it1).first << " ";

	cout << endl << endl << "Done sorting words!" << endl;
	cout << "Processing unique words... " << endl << endl;

	for (it1 = words.begin(); it1 != words.end(); ++it1)
		cout << (*it1).first << " ";
	cout << endl << endl << "Done extracting unique words!" << endl << endl;


	//d) Iterating over both arrays at once, count the number of occurrences of each word in a vector<int>
	//	counts
	cout << "Processing word count... " << endl << endl;

	for (it1 = words.begin(); it1 != words.end(); ++it1)

		if ((*it1).second > 1)
			//e) For words appearing more than once, output a sorted list of unique strings with their usage count
			//first stored value = word
			//second stored value = count
			cout << "Word = " << (*it1).first << " appears " << (*it1).second << " time(s) " << endl << endl;

	cout << endl << endl << "Done processing word count!" << endl;
}

int main(){

std::vector<double> array;
// fill this array with values

//My explanations about the code:
//push_back adding elements to the vector in its end.
array.push_back( 29 );
array.push_back( 49 );
array.push_back( 52 );
array.push_back( 26 );
array.push_back( 89 );

//This as i understood is connection to the array with the help of pointers;
for( double* it1 = &array[0]; it1 != (&array[0]) + array.size(); ++ it1 ) {
std::cout << *it1 << " ";
}
std::cout << endl;
// change the data
//We can also reassign values of the vector using simple array operations
array[0] = 49;
array[1] = 29;
//Swap functions replace the value of the vector,in other words
// here value of the 2 position is changed with the value of the 3
std::swap( array[2], array[3]) ;
// iterate using iterators. See that they share the same semantics.
//array.begin return iterator to the beginning , in other words this is simple for loop.
// which shows the element located at the address. pointer.
for( std::vector<double>::iterator it1 = array.begin(); it1 != array.end(); ++ it1 )
{
std::cout << *it1 << " ";
}
std::cout << endl;
cout << "Lists" << endl;
c1();
as2();
string long_string =
		"manchmal hat man eine sehr lange strasse vor sich"
		"man denkt die ist so schrecklich lang"
		"das kann man niemals schaffen denkt man"
		"und dann faengt man an sich zu eilen"
		"und man eilt sich immer mehr"
		"jedes mal wenn man aufblickt"
		"sieht man dass es gar nicht weniger wird"
		"was noch vor einem liegt"
		"und man strengt sich noch mehr an"
		"man kriegt es mit der angst"
		"und zum schluss ist man ganz auBer puste"
		"und kann nicht mehr"
		"und die strasse liegt immer noch vor einem"
		"so darf man es nicht machen"
		"man darf nie an die ganze strasse auf einmal denken verstehst du"
		"man muss nur an den naechsten schritt denken"
		"an den naechsten atemzug an den naechsten besenstrich"
		"und immer wieder nur an den naechsten"
		"dann macht es freude das ist wichtig"
		"dann macht man seine sache gut"
		"und so soll es sein";

as3(long_string);
}
