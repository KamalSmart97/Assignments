#include<iostream>

using namespace std;

class a
{
public:
	a(int a= 0) {

	
		m_overall++;
	}

	void* operator new(size_t size)
	{
		void* p = ::operator new(size);
		//void * p = malloc(size); will also work fine
		m_heap++;

		return p;
	}

	static int m_overall, m_heap;

};

int a::m_overall(0);
int a::m_heap(0);

int main()
{
	a* p = new a();

	a h, y, j;

	cout << "heap" << a::m_heap;
	cout << "stack" << a::m_overall- a::m_heap;

	return 0;
}