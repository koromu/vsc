#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

#define int long long
using namespace std;
const int N = 2e5 + 10;

int w[N];

void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> w[i];
    sort(w + 1, w + 1 + n);
    vector<int> v1;
    int nn = 0;
    while(((double)w[n] + (double)w[1] / 2) != 0)
    {
        nn++;
        if(nn >= 41)
        {
            cout << "-1\n";
            return;
        }
        int mid = (w[1] + w[n]) >> 1;
        v1.push_back(mid);
        for(int i = 1 ; i <= n ; i ++)
        {
            w[i] = abs(w[i] - mid);
        }
        sort(w + 1, w + 1 + n);
    }
    cout << v1.size() << "\n";
    for(auto i : v1)
    {
        cout << i << " ";
    }
    cout << "\n";
    // 每次减掉平均数, 然后2 1 0 1 2
    // 1 0 1 0 1
    // 35 5 25 35
    // 15 15 5 15
    // 5 5 5 5

    return ;
}


signed main()
{
    int _ = 1; 
    cin >> _;
    while(_--) solve();
    return 0;
}