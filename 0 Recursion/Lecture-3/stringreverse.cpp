#include <iostream>
using namespace std;
#include <string>
void solve(string &str, int i, int j)
{
    // base case
    if (i >= j)
    {
        return;
    }
    swap(str[i], str[j]);
    solve(str, i + 1, j - 1);
}
// Approach -> Vaapis aate time add krro current char
void solve1(string &str, int idx, string &ans)
{
    if (idx == str.size())
    {
        return;
    }
    solve1(str, idx + 1, ans);
    ans += str[idx];
}
int main()
{
    string str, ans;
    cin >> str;
    solve1(str, 0, ans);
    cout << ans << endl;
    return 0;
}