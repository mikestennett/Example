#include <stdio.h>
#include <string>

class TestClassSize {
public:
	int age = 0;
};

class TestClassTwo {
public:
	int age = 1;
	virtual int GetTwiceTheAge() { return age * 2; }
};

class TestClassThree {
public:
	int age = 1;
	virtual int GetTwiceTheAge() { return age * 2; }
	virtual int GetThreeTimesTheAge() { return age * 3; }
};

int main_sizeOf() {  // comment this line and uncomment the next when running.
//int main() {
	// printf() displays the string inside quotation
	printf("SizeOf Example!\n");
	char myChar = 'A';
	int myInt = 0;
	float myFloat = 1.0;
	double myDouble = 1.0;
	char myword[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	char myword2[] = "Hello";
	std::string greeting = "why not";
	TestClassSize myTestClass;
	TestClassTwo myTestClassTwo;
	TestClassThree myTestClassThree;

	printf("SizeOf char %i\n", sizeof(myChar));
	printf("SizeOf int %i\n", sizeof(myInt));
	printf("SizeOf float %i\n", sizeof(myFloat));
	printf("SizeOf double %i\n", sizeof(myDouble));
	printf("SizeOf myword %i\n", sizeof(myword));
	printf("SizeOf myword2 %i\n", sizeof(myword2));
	printf("SizeOf greeting %i\n", sizeof(greeting));
	greeting = "I have a lot more to say now don't I.  Imean this is more than twenty eight characters.";
	printf("SizeOf greeting %i\n", sizeof(greeting));
	printf("SizeOf myTestClass %i\n", sizeof(myTestClass));
	printf("SizeOf TestClassTwo %i\n", sizeof(myTestClassTwo));
	printf("SizeOf TestClassThree %i\n", sizeof(myTestClassThree));
	printf("SizeOf TestClassThree::GetThreeTimesTheAge %p\n", &TestClassThree::GetThreeTimesTheAge);

	return 0;
}