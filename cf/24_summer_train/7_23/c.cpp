#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

#define int long long
using namespace std;
const int N = 2e5;
int w[N];
int f[N];
unordered_map<int, int> ha;

void solve()
{
    int n, m;
    string a; cin >> a;
    string b; cin >> b;
    int ans = 0;
    for(int i = 0; i <= a.size() - 1 ; i ++)
    {
        for(int j = 0 ; j <= b.size() - 1  ; j ++)
        {
            if(a[i] == b[j])
            {
                int tmp = 0;
                for(int l = j, k = i; l <= b.size() - 1 && k <= a.size() - 1 ; l ++, k ++)
                {
                    if(a[k] == b[l]) tmp ++;
                    else 
                    {
                        break;
                    }
                }
                ans = max(ans, tmp);
            }
        }
    }
    std::cout << (int)a.size() + (int)b.size() - 2 * ans << endl;
    return ;
}


signed main()
{
    int _ = 1; 
    cin >> _;
    while(_--) solve();
    return 0;
}