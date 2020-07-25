#include <stdio.h>
#include <string>

class MyRectangle {
public:
	MyRectangle(int StartLength, int StartHeight);  // What is this in termonology in general and specifically for this one?
	int Length = 2; // Give two names for this in terminology.
	int Height = 1;
};

MyRectangle::MyRectangle(
	int StartLength,  // What is this in our terminology?
	int StartHeight) 
{
	Length = StartLength;
	Height = StartHeight;
}

MyRectangle TestRect1(5, 2);
MyRectangle TestRect3(4, 3);

int GetRectArea(const MyRectangle& Rect)
{
	return Rect.Length * Rect.Height;
}

void DoubleRectSize(MyRectangle* Rect1, MyRectangle Rect2)
{
	Rect1->Height *= 2;  // Same as "Rect1->Height = Rect1->Height * 2;"
	Rect1->Length *= 2;
	Rect2.Height *= 2;
	Rect2.Length *= 2;
}

//int main_ValueRefPtr()
int main()
{
	MyRectangle* TestRect2 =  new MyRectangle(4, 3);
	MyRectangle& TestRef = *TestRect2;
	DoubleRectSize(TestRect2, TestRect3);
	int area = GetRectArea(TestRect1);
	printf("TestRect2 %i %i\n", TestRect2->Length, TestRect2->Height);
	printf("TestRect3 %i %i\n", TestRect3.Length, TestRect3.Height);
	printf("TestRect1 %i %i\n", TestRect1.Length, TestRect1.Height);
	printf("GetRectArea TestRect1 %i\n", area);
	printf("TestRef %i %i\n", TestRef.Length, TestRef.Height);
	delete TestRect2;
	printf("TestRef %i %i\n", TestRef.Length, TestRef.Height);

	return 0;
}
