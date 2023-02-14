#include <iostream>
using namespace std;
#include <string>
#include <vector>
void printSubsequence(string str, int index, string ans, vector<string> &output)
{
    // base case
    if (index == str.size())
    {
        output.push_back(ans);
        return;
    }
    // include
    printSubsequence(str, index + 1, ans + str[index], output);
    // not include
    printSubsequence(str, index + 1, ans, output);
}
int main()
{
    string str;
    cin >> str;
    vector<string> output;
    printSubsequence(str, 0, "", output);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;
    return 0;
}