#include<iostream>
using namespace std;
int countSort(int arr[], const int m_count)
{
    int m_max = 0;

    for (int i = 0; i < m_count; i++)
    {
        if (m_max < arr[i])
            m_max = arr[i];
    }

    const int size = m_max+1;

    int* countArr = new int[size];
    int* sortedArr = new int[m_count];
     std::fill(countArr, countArr + size, 0);

    for (int i = 0; i < m_count; i++)
    {
        countArr[arr[i]]++;
    }

    for (int i = 1; i < size; ++i)
        countArr[i] += countArr[i - 1];

    for (int i = m_count-1; i >=0; i--)
    {
        sortedArr[countArr[arr[i]] - 1] = arr[i];
        countArr[arr[i]]--;
    }

    memcpy(arr, sortedArr, sizeof(int )*m_count);

    delete countArr;
    delete sortedArr;

    return 0;
}
int main()

{
    // Input array
    int inputArray[] = { 4, 3, 12, 1, 5, 5, 3, 9 };

    int m_count = sizeof(inputArray) / sizeof(inputArray[0]);

    // Output array
    countSort(inputArray, m_count);

    for (int i = 0; i < m_count; i++)
        cout << inputArray[i] << " ";

    return 0;
}