#include <iostream>
using namespace std;
void solve(int *arr, int size)
{
    // base case
    if (size < 1)
    {
        return;
    }
    // for loop -> Perinting
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    solve(arr, size / 2);
}
void solveTwo(int *arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        cout << arr[s] << endl;
        return;
    }
    for (int i = s; i <= e; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int mid = (s + e) / 2;
    // rec call
    solveTwo(arr, s, mid);
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
    solve(arr, n);
    return 0;
}