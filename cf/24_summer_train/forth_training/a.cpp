#include <iostream>
#include <string>
#include <algorithm>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 100010;
int n, m, k;
string a; 

void solve()
{   
    string a; cin >> a;
    if((a[a.size() - 1] - '0') % 2 == 0)
    {
        // 偶
        puts("0");
    }
    else if( (a[a.size() - 1] - '0') % 2 != 0)
    {
        if((a[0] - '0') % 2 ==0)
        {
            puts("1");
        }
        else 
        {
            for(int i = 1 ; i < a.size() - 1 ; i++)
            {
                if((a[i] - '0') % 2 == 0)
                {
                    puts("2");
                    return;
                }
            }
            puts("-1");
        }
    }
}

signed main()
{
    int _; cin >> _;
    while(_--) solve();
    return 0;
}
