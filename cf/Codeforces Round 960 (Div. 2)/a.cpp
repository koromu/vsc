#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

#define int long long
using namespace std;

const int N = 200010;
int w[N];
vector<int> v1;

void solve()
{
    unordered_map<int, int> ha;
    ha.clear();
    int n ; cin >> n;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> w[i];
        ha[w[i]] ++;
    }
    for(auto i : ha)
    {
        if(i.second % 2 == 1)
        {
            puts("YES");
            return;
        }
    }
    // sort(w + 1, w + 1 + n);
    // if(ha[w[n]] % 2 == 0) puts("NO");
    // else puts("YES");
    puts("NO");    
    return ;
}


signed main()
{
    int _ = 1;  cin >> _;
    while(_--) solve();
    return 0;
}