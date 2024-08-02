#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 45;

int n, x, y;

vector<int> v1;

void solve()
{
    string a; cin >> a;
    if(a.size() == 1)
    {
        if(a[0] != 'z')
        {
            cout << a << "z\n";
            return;
        }
        else
        {
            cout << a << "a\n";
            return;
        }
    }
    for(int i = 0; i + 1 <= a.size() - 1; i++)
    {
        if(a[i] == a[i + 1])
        {
            // 找到两个相同的字符了
            if(a[i] != 'z')
            {
                a = a.substr(0, i + 1) + (char)(a[i] + 1) + a.substr(i + 1);
                cout << a << "\n";
                return;
            }
            else
            {
                a = a.substr(0, i + 1) + 'a' + a.substr(i + 1);
                cout << a << "\n";
                return;
            }
        }
    }

    if(a[a.size() - 1] != 'z') cout << a << "z\n" ;
    else cout << a << "a\n";


    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 0;
    cin >> _;
    while(_--)
    {
        solve();
    }

    return 0;
}