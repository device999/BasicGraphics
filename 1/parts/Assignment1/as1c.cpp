#include <iostream>
#include <ctime>
//the localtime() function does all the dirty work for you and you simply access the tm fields to read the results
// (time_t keeps the date in a compact form while tm splits the date in its components 
//(seconds, minutes, hours, day, month, year and other useful informations). 
using namespace std;
int main ()
{
  int day;
  int month;
  int year;
  string name;
  cout << "Please enter your name: ";
  cin >> name;
  cout << "Please enter your date of birth: ";
  cin >> day;
    cout << "Please enter your month of birth: ";
  cin >> month;
    cout << "Please enter your year of birth: ";
  cin >> year;
  	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	int current = timePtr->tm_year + 1900;
  cout << "Your name is = " << name<< endl;
  cout << "Your age is = " << current - year<< endl;
}
