#include <iostream>
using namespace std;
void print(int *arr, int size, int idx)
{
    // base case
    if (idx == size)
        return;
    cout << arr[idx] << " ";
    print(arr, size, idx + 1);
}
// Reverse Print
void printRev(int *arr, int size, int idx)
{
    // base case
    if (idx == size)
        return;
    printRev(arr, size, idx + 1);
    cout << arr[idx] << " ";
}
void printRev1(int *arr, int index)
{
    // base case
    if (index < 0)
    {
        return;
    }
    cout << arr[index] << " ";
    // Recursive Relation
    printRev1(arr, index - 1);
}
void print3(int arr[], int size)
{
    // base case
    if (size == 0)
    {
        return;
    }
    cout << arr[0] << " ";
    print3(arr + 1, size - 1);
}
int main()
{
    int arr[] = {1, 3, 4, 5};
    int size = 4;
    print3(arr, size);
    return 0;
}