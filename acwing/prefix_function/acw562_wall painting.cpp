#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int N = 110;

int w[N];

void solve()
{
    cin >> n;
    string str;
    cin >> str;
    vector<int> v1;
    for (int i = 0; i < str.size(); i++)
        v1.push_back(str[i] - '0');
    for (int i = 1; i <= n; i++)
    {
        w[i] = w[i] + w[i - 1];
    }
}

int n;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
