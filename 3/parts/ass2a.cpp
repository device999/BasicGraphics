#include<iostream>
using namespace std;

int string_length(const char* string) {
	int length = 0;
	for(const char* ptr = string; *ptr != '\0'; ++ ptr) {
	++ length;
	}
	return length;
}
char* string_copy(const char* string) {
// we need to add 1 because of '\0'
	char* result = new char[string_length(string) + 1];
// write your code here (remember zero-termination !)
	
	int i = 0;
		for (const char* newLine = string; *newLine != '\0'; ++newLine) {
			result[i++] = *newLine;
		}
		result[i] = '\0';
	return result;
	}
int main(int argc, char** argv) {
	const char* string_c = "This is a string and is a long one so that we can create memory leaks when it is copied and not deleted";
	char* copy = string_copy(string_c);
	// write your code here
	//Task 2a
	//std::cout << copy << std::endl;
	//delete[] copy; 
	//end
	//Task 2b


		for(int i=0;i<1000000;i++) {
			char* tempResult = copy;
			copy = string_copy(copy);
			std::cout << copy << std::endl;
			//free memory
			//uncomment tempResult to see how memory increases
			delete[] tempResult;
		}
		std::cout << copy << std::endl;
		delete[] copy;
	/*		
	//end
	//Task 2c
	//Check the memory requirements with the task manager.
	
		for(int i=0;i<1000000;i++) {
			copy = string_copy(copy);
		}
		std::cout << copy << std::endl;
		//end
		*/
	return 0;
	
}

