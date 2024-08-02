#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <unordered_map>
#include <vector>

#define int long long
using namespace std;
const int N = 110;
int w[N];
int pre[N];

void solve()
{
    int n; cin >> n;
    for(int i = 1 ; i <= n ; i ++) {
        cin >> w[i];
        pre[i] = pre[i - 1] + w[i];
    }
    int c = 1;
    int mid = pre[n] / n;
    cout << mid << "\n";
    for(int i = n ; i >= 1 ; i --)
    {
        if(w[i] > mid)
        {
            int sum = 0;
            for(int j = 1 ; j <= i ; j ++)
            {
                sum += (w[j] - mid);
            }
            for(int k = 1 ; k <= sum ; k ++)
            {
                c *= (mid + 1);
            }
            for(int k = 1 ; k <= c - sum ; k ++)
            {
                c *= mid;
            }
            // cout << sum << "\n";
            cout << c << "\n";
            return;
        }
        else c *= w[i];
        // cout << mid << "\n";
    }

    return ;
}


signed main()
{
    int _ = 1; 
    cin >> _;
    while(_--) solve();
    return 0;
}