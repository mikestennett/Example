#include <stdio.h>
#include <string>


// Declare Classes
class Animal {
public:
	static int AnimalCount;  // static attribute is one per class definition and is really global with class scope

	int Age = 1; // attribute is only created when an object of animal type is created
	//Animal() { printf("Animal::Animal() - Default Constructor - At address %p - AnimalCount = %i\n", this, ++AnimalCount);}
	//Animal(const Animal& p2) { printf("Animal::Animal() - Copy Constructor - At address %p - AnimalCount = %i\n", this, ++AnimalCount);  Age = p2.Age;  }
	//~Animal() { printf("Animal::~Animal() - Default Destructor - At address %p -  AnimalCount = %i\n", this, --AnimalCount); }
	virtual void Speak() { printf("Animal::Speak - Animal said something\n"); }
};

class Dog: public Animal {
public:
	int NumberOfTreats = 0; 
	virtual void Speak() { printf("Dog::Speak - Dog said Bark!\n"); }
};

class Cat: public Animal {
public:
	int Lives = 9;
	int SleepHours = 20;
	virtual void Speak() { printf("Cat::Speak - Cat said Meow!\n"); }
};

// Global and Static Variables defined
int Animal::AnimalCount = 0; // Initialize class static attribute
Cat Pablo;

// Define Functions
void PrintAllStaticAndGlobalAddresses() {
	printf("***** Starting PrintAllStaticAndGlobalAddresses - Printing all static and global addresseses  \n");
	printf("%p is the address of %s with size of %i\n", &Animal::AnimalCount, "int Animal::AnimalCount", sizeof(Animal::AnimalCount));
	printf("%p is the address of %s with size of %i\n", &Pablo, "Cat Pablo", sizeof(Pablo));
	printf("***** Exiting PrintAllStaticAndGlobalAddresses \n");
}

// Forward function delarations so we can print thier addresses in the PrintAllFunctionAddresses
void AnotherFunc();
int main();
Animal* PassingParameters(
	int MyIntParam, // Pass by value
	Animal* AnyAnimalParam,  // Passes a pointer
	Cat CatOneParam, // Passes by value so a copy is created
	int MyMiddleParam,  // Pass by value
	int MyMiddleParam2, // Pass by value
	Cat& CatTwoParam, // Passes by reference so only the pointer value is passed under the covers
	int MyLastParam  // Pass by value
);

void PrintAllFunctionAddresses() {
	printf("***** Starting PrintAllFunctionAddresses - Printing all function addresses  \n");
	printf("%p is the address of function Animal::Speak\n", &Animal::Speak);
	printf("%p is the address of function Dog::Speak\n", &Dog::Speak);
	printf("%p is the address of function Cat::Speak\n", &Cat::Speak);
	printf("%p is the address of function PrintAllStaticAndGlobalAddresses\n", &PrintAllStaticAndGlobalAddresses);
	printf("%p is the address of function PrintAllFunctionAddresses\n", &PrintAllFunctionAddresses);
	printf("%p is the address of function AnotherFunc\n", &AnotherFunc);
	printf("%p is the address of function PassingParameters\n", &PassingParameters);
	printf("%p is the address of function main\n", &main);
	printf("***** Exiting PrintAllFunctionAddresses \n");
}

void AnotherFunc() {
	int myNewInt = 5;
	printf("***** Starting AnotherFunc\n");
	printf("%p is the address of %s with size of %i\n", &myNewInt, "int myNewInt", sizeof(myNewInt));
	printf("***** Exiting AnotherFunc\n");

}


Animal* PassingParameters(
	int MyIntParam, // Pass by value
	Animal* AnyAnimalParam,  // Passes a pointer
	Cat CatOneParam, // Passes by value so a copy is created
	int MyMiddleParam,  // Pass by value
	int MyMiddleParam2, // Pass by value
	Cat& CatTwoParam, // Passes by reference so only the pointer value is passed under the covers
	int MyLastParam  // Pass by value
)
{
	int LocalInt = 2;
	int* myPtr = &MyMiddleParam2 + 1;  // Adds by Size of pointer type in this case by 4 because the integer has a sizeof 4
	Dog* myDogPtr = nullptr;
	printf("***** Starting PassingParameters\n");
	printf("** Printing out parameters on the stack\n"); // print out Parameters
	printf("%p is the address of %s with size of %i\n",  &MyIntParam, "int MyIntParam", sizeof(MyIntParam));
	printf("%p is the address of %s with size of %i with value %p\n", &AnyAnimalParam, "Animal* AnyAnimalParam", sizeof(AnyAnimalParam), AnyAnimalParam);
	printf("%p is the address of %s with size of %i\n", &CatOneParam, "Cat CatOneParam", sizeof(CatOneParam));
	printf("%p is the address of %s with size of %i\n", &MyMiddleParam, "int MyMiddleParam", sizeof(MyMiddleParam));
	printf("%p is the address of %s with size of %i\n", &MyMiddleParam2, "int MyMiddleParam2", sizeof(MyMiddleParam2));
	printf("%p is the address of %s with size of %i - Not showing actual values but the object being referenced\n", std::addressof(CatTwoParam), "Cat& CatTwoParam", sizeof(CatTwoParam));
	printf("%p is the real address of %s with size of %i with a value of %p\n", myPtr, "Cat& CatTwoParam", sizeof(myPtr), *myPtr);

	printf("%p is the address of %s with size of %i\n", &MyLastParam, "int MyLastParam", sizeof(MyLastParam));

	printf("** Printing out local variables on the stack\n");// Print out Local vars
	printf("%p is the address of %s with size of %i\n", &LocalInt, "int LocalInt", sizeof(LocalInt));
	printf("%p is the address of %s with size of %i\n", &myPtr, "int* myPtr", sizeof(myPtr));
	printf("%p is the address of %s with size of %i\n", &myDogPtr, "Dog* myDogPtr", sizeof(myDogPtr));

	myDogPtr = new Dog();

	printf("%p is the address of %s with size of %i with a value of %p which is the address in the heap\n", &myDogPtr, "Dog* myDogPtr", sizeof(myDogPtr), myDogPtr);
	printf("%s has a size of %i\n", "Dog Object that myDogPtr is pointing to", sizeof(*myDogPtr));
	printf("The first 4 bytes is the hidden Virtual Table pointer address\n");
	printf("%p is the address of %s with size of %i\n", &myDogPtr->Age, "myDogPtr->Age", sizeof(myDogPtr->Age));
	printf("%p is the address of %s with size of %i\n", &myDogPtr->NumberOfTreats, "myDogPtr->NumberOfTreats", sizeof(myDogPtr->NumberOfTreats));


	AnyAnimalParam->Speak();
	CatOneParam.Speak();
	CatTwoParam.Speak();
	AnotherFunc();
	printf("***** Exiting PassingParameters\n");
	return myDogPtr;
}


int main_for_MemoryAllocationExample() {  // comment this line and uncomment the next when running.
//int main() {
	printf("***** Starting  main() function - print statements before this one represent code executed to initialize statics and globals\n");
	

	PrintAllFunctionAddresses();
	PrintAllStaticAndGlobalAddresses();
	Dog Gizmo;
	printf("%p is the address of %s with size of %i\n", &Gizmo, "Dog Gizmo", sizeof(Gizmo));
	printf("%p is the address of Gizmo.Age\n", &(Gizmo.Age));
	printf("%p is the address of Gizmo.NumberOfTreats\n", &(Gizmo.NumberOfTreats));
	Animal* myAnimalPtr = PassingParameters(2, &Gizmo, Pablo, 4, 5, Pablo, 3);
	AnotherFunc();

	printf("%p is the address of %s with size of %i with a value of %p which is the address in the heap\n", &myAnimalPtr, "Animal* myAnimalPtr", sizeof(myAnimalPtr), myAnimalPtr);
	myAnimalPtr->Speak();
	int AnotherInt = 12;
	printf("%p is the address of %s with size of %i\n", &AnotherInt, "int AnotherInt", sizeof(AnotherInt));

	delete myAnimalPtr;
	printf("***** Exiting  main() function - All printfs after this are destructors on statics and globals \n");

	return 0;
}