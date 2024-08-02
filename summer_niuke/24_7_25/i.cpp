#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define N 1000010
#define B 133

vector<pii> w;
map<int, int> m;

bool cmp(pii a, pii b)
{
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

void solve()
{
    int n, m; cin >> n >> m;
    int x, y;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> x >> y;
        w.push_back({x, y});
    }

    sort(w.begin(), w.end(), cmp);

    for(auto i : w)
    {
        
    }

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _  = 1; 
    // cin >> _;
    while(_--)
    { 
        solve();
    }
    return 0;
}
