#include <iostream>
using namespace std;
// Print in Decreasing Order
void print(int n)
{
    // base case
    if (n == 0)
        return;
    cout << n << endl;
    // Recursive Call
    print(n - 1);
}
// Print in Increasing Order
void printInc(int n)
{
    if (n == 0)
        return;
    printInc(n - 1);
    cout << n << " ";
}
// Print Decreasing and Increasing
void printDecInc(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    printDecInc(n - 1);
    cout << n << " ";
}
int main()
{
    int n;
    cin >> n;
    printDecInc(n);
    return 0;
}
