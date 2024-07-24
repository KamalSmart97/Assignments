#include<iostream>

using namespace std;

static int count1 = 0;
static int count2 = 0;

class Myclass1 {

public:
	Myclass1()
	{
		count1++;
	}
};

class Myclass2: public Myclass1 {

public:
	Myclass2()
	{
		count2++;
	}
};

int main()
{
	Myclass1 a[10];
	Myclass2 b[20];

	cout << " Print MyClass1 counter" << count1 - count2 <<endl;
	cout << " Print MyClass2 counter"<< count2;

}