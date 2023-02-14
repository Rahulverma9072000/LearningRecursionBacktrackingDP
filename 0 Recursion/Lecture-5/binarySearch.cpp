#include <iostream>
using namespace std;
// Binary Search
//  Condition Monotonic Array
bool binary_search(int *arr, int s, int e, int target)
{
    if (s > e)
    {
        return false;
    }
    int mid = s + (e - s) / 2;
    if (target == arr[mid])
    {
        return true;
    }
    else if (arr[mid] > target)
    {
        return binary_search(arr, s, mid - 1, target);
    }
    else
    {
        return binary_search(arr, mid + 1, e, target);
    }
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
    int target;
    cin >> target;
    cout << binary_search(arr, 0, n - 1, target) << endl;
    return 0;
}