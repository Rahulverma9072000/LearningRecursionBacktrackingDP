#include <iostream>
#include <vector>
using namespace std;
int getMax(int *arr, int size, int index)
{
    // base case
    if (index == size)
    {
        return INT_MIN;
    }
    int meraAns = arr[index];
    int recAns = getMax(arr, size, index + 1);
    return max(recAns, meraAns);
}
void solve(int arr[], int size, int index, int &maxc)
{
    // base case
    if (index == size)
    {
        return;
    }
    maxc = max(maxc, arr[index]);
    solve(arr, size, index + 1, maxc);
}
int findFirst(int *arr, int size, int index, int target)
{
    if (index == size)
    {
        return -1;
    }
    if (arr[index] == target)
    {
        return index;
    }
    return findFirst(arr, size, index + 1, target);
}
// bas Iterate piche se krro
int findLast(int *arr, int size, int index, int target)
{
    if (index == size)
    {
        return -1;
    }
    if (arr[index] == target)
    {
        return index;
    }
    return findLast(arr, size, index - 1, target);
}
void findAllOcc(int arr[], int size, int index, int target, vector<int> &ans)
{
    // base case
    if (index == size)
    {
        return;
    }
    if (arr[index] == target)
    {
        ans.push_back(index);
    }
    findAllOcc(arr, size, index + 1, target, ans);
}
int main()
{
    int arr[] = {7, 2, 15, 9, 21};
    int size = 5;
    cout << getMax(arr, size, 0);
    return 0;
}