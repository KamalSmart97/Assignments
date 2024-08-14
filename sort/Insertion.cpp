#include<iostream>

using namespace std;

int InsertionSort(int arr[], int m_count)
{
	for (int i = 1; i < m_count; ++i)
	{
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		arr[j + 1] = key;
	}
}

int main()
{
	int arr[] = { 1,5,8,15,3,7 };

	int count = sizeof(arr) / sizeof(arr[0]);

	InsertionSort(arr, count);

	for (int i = 0; i < count; i++)
		cout << arr[i] << " ";

	return 0;
}
