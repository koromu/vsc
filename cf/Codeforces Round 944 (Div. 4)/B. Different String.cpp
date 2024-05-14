#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}


void solve()
{
    string a;cin >> a;
    for(int i = 0 ; i < a.size() - 1 ; i ++)
    {
        if(a[i] == a[i + 1]) continue;
        else 
        {
            puts("YES");
            for(int j = 0 ; j < i ; j ++)
            {
                cout << a[j];
            }

            cout << a[i + 1] << a[i];
            for(int j = i + 2 ; j < a.size() ; j ++)
                cout << a[j]; 

            // 输出的时候不够随机
            cout << endl;
            return ;
        }
    }
    puts("NO");
}

int main()
{
    int _;
    cin >> _;
    while(_--)
    {
        solve();
    }
    return 0;
}

