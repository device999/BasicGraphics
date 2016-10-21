#include <iostream>
using namespace std;
int string_length(const char* sms)
{
	int size=0;
	while (true)
	{
		if(sms[size]!='\0')
		{
			size++;
		}
		else
		{
			break;
		}
	}
	return size;
}
int main()
{
	//task a
	int var;
	char var1;
	cout <<var<<endl;
	cout <<var1<<endl;
	//task b
	cout << "a: " << int(char('a')) << endl;
	cout << "b: " << int(char('b')) << endl;
	cout << "c: " << int(char('c')) << endl;
	cout << "z: " << int(char('z')) << endl;
	cout << "A: " << int(char('A')) << endl;
	cout << "B: " << int(char('B')) << endl;
	cout << "C: " << int(char('C')) << endl;
	cout << "Z: " << int(char('Z')) << endl;
	cout << "0: " << int(char('0')) << endl;
	cout << "1: " << int(char('1')) << endl;
	cout << "2: " << int(char('2')) << endl;
	cout << "9: " << int(char('9')) << endl;
	cout <<" "<< endl;
	//task c
		for (char c = '0'; c <= 'z'; c++)
		{
			if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
			{
				cout << c<<"= " <<int(c) << endl;	
			}
				
		}
	//task d
	cout <<" "<< endl;
	const char* message = "Hello world";
	cout << message;
	//task e
	cout <<" "<< endl;
	cout<< string_length(message)<<endl;
	

}

