#include <stdio.h>

const int myConst = 0;
int myGlobal = 0;
int myGlobaltwo = 0;

int TimesTwo(int x) {
	return x * 2;
}

int main_VariableExample() {  // comment this line and uncomment the next when running.
//int main() {
	// printf() displays the string inside quotation
	printf("Variable Example!");
	int x = 0;
	int y = 1;
	y = TimesTwo(y);
	int intSize = sizeof(x);
	int* calculatedptr = &myGlobal + 1;  // Adds by Size of pointer type in this case by 4 because the integer has a sizeof 4

	printf("\nx = %i", x);
	printf("\nintSize = %i bytes", intSize);
	printf("\ny = %i", y);
	printf("\nx pointer = %p", &x);
	printf("\ny pointer = %p", &y);
	printf("\nmyGlobal pointer = %p", &myGlobal);
	printf("\n myGlobaltwo pointer = %p", &myGlobaltwo);
	printf("\ncalculatedptr pointer = %p", calculatedptr);
	printf("\nTimesTwo() pointer = %p", &TimesTwo);
	return 0;
}