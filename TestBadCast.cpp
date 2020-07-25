#include <stdio.h>
#include <string>

class FredClass {
public:
	int age = 0;
};


class TedClass {
public:
	int height = 1;
};


void printAge(FredClass* myclass) {
	printf("Age is %i \n",  myclass->age);
}



int main_TestBadCast() {  // comment this line and uncomment the next when running.
//int main() {
	// printf() displays the string inside quotation
	printf("SizeOf Example!\n");
	
	FredClass myTestClassOne;
	TedClass myTestClassTwo;

	//printAge(&myTestClassOne);
	printAge((FredClass*)&myTestClassTwo);

	return 0;
}