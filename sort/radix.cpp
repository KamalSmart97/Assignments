#include<iostream>
using namespace std;


int countSort(int arr[], const int m_count, int exp)
{
    const int size = 10;

    int countArr[10] = { 0 };
    int* sortedArr = new int[m_count];
    std::fill(countArr, countArr + 10, 0);

    for (int i = 0; i < m_count; i++)
    {
        countArr[(arr[i]/exp)%10]++;
    }

    for (int i = 1; i < size; ++i)
        countArr[i] += countArr[i - 1];

    for (int i = m_count - 1; i >= 0; i--)
    {
        sortedArr[countArr[(arr[i] / exp) % 10] - 1] = arr[i];
        countArr[(arr[i] / exp) % 10]--;
    }

    memcpy(arr, sortedArr, sizeof(int) * m_count);

    delete sortedArr;

    return 0;
}

int radixSort(int arr[], const int m_count)
{
    int m_max = 0;
    for (int i = 0; i < m_count; i++)
    {
        if (m_max < arr[i])
            m_max = arr[i];
    }

    for (int exp = 1; m_max / exp > 0; exp *= 10)
    {
        countSort(arr, m_count, exp);
    }
}
int main()

{
    // Input array
    int inputArray[] = { 170, 45, 75, 90, 802, 24, 2, 66 };

    int m_count = sizeof(inputArray) / sizeof(inputArray[0]);

    // Output array
    radixSort(inputArray, m_count);

    for (int i = 0; i < m_count; i++)
        cout << inputArray[i] << " ";

    return 0;
}