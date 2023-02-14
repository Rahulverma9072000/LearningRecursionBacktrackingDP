#include <iostream>
using namespace std;
void add2str(string a, string b, int carry, string &ans, int i, int j)
{
    // base case
    if (i < 0 and j < 0 and carry == 0)
    {
        return;
    }
    int first = 0;
    int second = 0;
    if (i >= 0)
    {
        first = a[i] - '0';
    }
    if (j >= 0)
    {
        second = b[j] - '0';
    }
    int sum = first + second + carry;
    int lastDigit = sum % 10;
    carry = sum / 10;
    ans.push_back(lastDigit + '0');
    add2str(a, b, carry, ans, i - 1, j - 1);
}
int main()
{
    string a, b, ans;
    cin >> a >> b;
    ans = "";
    add2str(a, b, 0, ans, a.size() - 1, b.size() - 1);
    // Reverse the ans
    cout << ans << endl;
    return 0;
}