#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>
#include <math.h>
#include <map>


#define int long long
using namespace std;
const int N = 2e5 + 10;
typedef pair<char, int> pii;

int w[N];
int pre[N];
map<int, pii> mp;

bool cmp(pii a, pii b)
{
    return a.second < b.second;
}


void solve()
{
    int n; cin >> n;
    pii a[4]; cin >> a[1].second >> a[2].second >> a[3].second;
    pii b[4]; cin >> b[1].second >> b[2].second >> b[3].second;
    a[1].first = 's', a[2].first = 'j', a[3].first = 'b';
    b[1].first = 's', b[2].first = 'j', b[3].first = 'b'; 

    map<char, int> mp1, mp2;

    sort(a + 1, a + 4, cmp);
    sort(b + 1, b + 4, cmp);

    mp1[a[1].first] = a[1].second;
    mp1[a[2].first] = a[2].second;
    mp1[a[3].first] = a[3].second;

    mp2[b[1].first] = b[1].second;
    mp2[b[2].first] = b[2].second;
    mp2[b[3].first] = b[3].second;

    int minv, maxv = 0;
    char op;
    if(a[3].second > b[3].second)
    {
        op = a[3].first;
        if(op == 's')
        {
            minv = max(a[3].second - mp2['s'] - mp2['b'], 0ll);
        }
        else if(op == 'j')
        {
            minv = max(a[3].second - mp2['s'] - mp2['j'], 0ll);
        }
        else if(op == 'b')
        {
            minv = max(a[3].second - mp2['j'] - mp2['b'], 0ll);
        }
    }
    else 
    {
        op = b[3].first;
        if(op == 's')
        {
            minv = max(b[3].second - mp1['j'] - mp1['s'], 0ll);
        }
        else if(op == 'j')
        {
            minv = max(b[3].second - mp1['b'] - mp1['j'], 0ll);
        }
        else if(op == 'b')
        {
            minv = max(b[3].second - mp1['b'] - mp1['s'], 0ll);
        }
    
    }
    // cout << op << " " << b[3].second << "\n";
    cout << minv << " ";
    maxv = (min(mp1['s'], mp2['j']) + min(mp1['j'], mp2['b']) + min(mp1['b'], mp2['s']));
    cout << maxv << "\n";

    return ;
}   


signed main()
{
    int _ = 1; 
    // cin >> _;
    while(_--) solve();
    return 0;
}