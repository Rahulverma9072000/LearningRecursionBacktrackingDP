#include <iostream>
using namespace std;
void merge(int *arr, int s, int mid, int e)
{
    // First array is from s to mid
    // Second array is from mid+1 to e
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *first = new int[len1];
    int *second = new int[len2];
    // Copy Value
    int i = 0;
    for (int index = s; index <= mid; index++)
    {
        first[i++] = arr[index];
    }
    int j = 0;
    for (int index = mid + 1; index <= e; index++)
    {
        second[j++] = arr[index];
    }
    // Merge These 2 array into orignal array
    int orignalArrayindex = s;
    int index1 = 0;
    int index2 = 0;
    while (index1 < len1 and index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[orignalArrayindex++] = first[index1++];
        }
        else
        {
            arr[orignalArrayindex++] = second[index2++];
        }
    }
    // exhaust first array
    while (index1 < len1)
    {
        arr[orignalArrayindex++] = first[index1++];
    }
    // exhaust second array
    while (index2 < len2)
    {
        arr[orignalArrayindex++] = second[index2++];
    }
    // Free the Memory
}
void mergeSort(int *arr, int s, int e)
{
    cout << "Recieved call for s -> " << s << " e -> " << e << endl;
    // Base Case
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;
    // left Part Recursion sort krke dega
    mergeSort(arr, s, mid);
    // right part recursion sort krke dega
    mergeSort(arr, mid + 1, e);
    // Merge 2 sorted part
    merge(arr, s, mid, e);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    // print the array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}