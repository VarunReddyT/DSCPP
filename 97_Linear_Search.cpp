#include <iostream>
using namespace std;
int linearSearch(int arr[], int size, int val)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == val)
        {
            return i + 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {23, 125, 243, 2, 54, 2, 32};
    int arrSize = sizeof(arr) / sizeof(int);
    cout << linearSearch(arr, 5, 54) << "th element";
    return 0;
}