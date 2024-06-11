// C++ program to demonstrate
// postfix increment operator
// overloading
#include <iostream>
using namespace std;

class Integer {
private:
	int i;

public:
	// Parameterised constructor
	Integer(int i = 0)
	{
		this->i = i;
	}

	// Overloading the postfix operator
	Integer operator++(int)
	{
		// returned value should be a copy of the object before increment
		Integer temp = *this;
		++i;
		return temp;
	}
	Integer operator--()
	{
		// returned value should be a copy of the object after decreament

		--i;
		return *this;
	}

	// Function to display the value of i
	void display()
	{
		cout << "i = " << i << endl;
	}
};

// Driver function
int main()
{
	Integer i1(3);

	i1.display();

	// Using the post-increment operator
	Integer i2 = i1++;

	cout << "After post increment: " << endl;
	cout << "i1: ";
	i1.display();
	cout << "i2: ";
	i2.display();

	// Using the pre deccrement operator
	Integer i3 = --i1;

	cout << "After pre decrement: " << endl;
	cout << "i1: ";
	i1.display();
	cout << "i2: ";
	i2.display();
}
