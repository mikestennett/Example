#include <iostream>
#include <string>


class MyFuncPtrClass
{
public:
	void MyMemberPtrPrint(int x) { printf("MyMemberPtrPrint called %i\n", x); };
	

	/* more of TMyClass */
};

void MyFuncPtrPrint() {
	printf("MyFuncPtrPrint called\n");
}

typedef  void (MyFuncPtrClass::* MemberPtrType)(int);

typedef int MyIntType;

int main_FucntionPointers()
//int main()
{
	void (*fun_ptr)() = nullptr; // variable "fun_ptr" of type void func()
	fun_ptr = &MyFuncPtrPrint;
	
	(*fun_ptr)();
	printf("fun_ptr = %p\n", fun_ptr);

	MyFuncPtrClass obj1;
	MyFuncPtrClass* obj1Ptr = &obj1;


	void (MyFuncPtrClass:: * memberPtr)(int) = nullptr;
	memberPtr = &MyFuncPtrClass::MyMemberPtrPrint;
	MemberPtrType memberPtr2 = &MyFuncPtrClass::MyMemberPtrPrint;
	MyIntType y = 2;
	(obj1.*memberPtr)(y);
	(obj1Ptr->*memberPtr2)(3);

	

	printf("fun_ptr = %p\n", memberPtr);

	return 0;
}
