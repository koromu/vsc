#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 200010;
int w[N], a[N], b[N];

vector<pii> v1, v2;

bool cmp1(pii a, pii b)
{
    return a.second < b.second;
}
bool cmp2(pii a, pii b)
{
    return a.first < b.first;
}


void solve()
{
    int n; cin >> n;
    for(int i = 1 ; i <= n ; i++)
        cin >> w[i];
    string a; cin >> a;
    v1.clear(), v2.clear();
    a = ' ' + a;
    // 看成一个一个的区间
    // 按区间的左右端点排序
    for(int i = 1 ; i <= n ; i ++)
    {
        if(a[i] == 'B')
        {
            // 说明是向左的
            if(w[i] >= 1)
                v1.push_back({1, w[i]});
        }// 向左的尽量取小的, 用这个组成1 ~ v1.size()
        else 
        {
            if(w[i] <= n) 
                v2.push_back({w[i], n});
        }// 向右的尽量取小的, 用这个组成v1.size() + 1 ~ v2.size()
    }


    sort(v1.begin(), v1.end(), cmp1);
    sort(v2.begin(), v2.end(), cmp2);
    // for(auto i : v1) cout << i.first << ' ' << i.second << endl;
    // for(auto i : v2) cout << i.first << ' ' << i.second << endl;
    if(v1.size() + v2.size() != n)
    {
        cout << "NO" << endl;
        return;
    }
    else 
    {
        for(int i = 1 ; i <= v1.size() ; i ++)
        {
            int xx = v1[i - 1].first, yy = v1[i - 1].second;
            if(xx <= i && i <= yy) continue;
            else 
            {
                cout << "NO" << endl;
                return;
            }
        }
        for(int i = 1 + v1.size(), j = 0 ; i <= n ; i ++, j ++)
        {
            int xx = v2[j].first, yy = v2[j].second;
            if(xx <= i && i <= yy) continue;
            else 
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

signed main()
{
    int _; cin >> _;
    while(_--)
    {
        solve();
    }
    return 0;
}
