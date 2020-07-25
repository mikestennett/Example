#include <iostream>
#include <string>


class MySuperClassVirtualFunc
{
public:
	void PrintNonVirtual();
	virtual void PrintVirtual();
};

void MySuperClassVirtualFunc::PrintNonVirtual()
{
	printf("MySuperClassVirtualFunc::PrintNonVirtual called\n");
}

void MySuperClassVirtualFunc::PrintVirtual()
{
	printf("MySuperClassVirtualFunc::PrintVirtual called\n");
}


class MySubClassVirtualFunc : public MySuperClassVirtualFunc
{
public:
	void PrintNonVirtual();
	virtual void PrintVirtual() override;
};

void MySubClassVirtualFunc::PrintNonVirtual()
{
	printf("MySubClassVirtualFunc::PrintNonVirtual called\n");
}

void MySubClassVirtualFunc::PrintVirtual()
{
	printf("MySubClassVirtualFunc::PrintVirtual called\n");
}

int main_VirtualVsNonVirtual()
//int main()
{
	MySubClassVirtualFunc Obj;
	MySuperClassVirtualFunc* ObjPtr = &Obj;

	ObjPtr->PrintNonVirtual();
	ObjPtr->PrintVirtual();

	return 0;
}
