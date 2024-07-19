#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

#define int long long
using namespace std;
typedef pair<int, int> pii;

int lowbit(int x) { return x & (-x); };

const int N = 200010;
vector<int> v1, v2;
set<int> m1, m2;
bool st[N];

// void dfs(int u, int n)
// {
//     // cout << "u : " << u << " n : " << u << endl;
//     if(u == v1.size())
//     {
//         // 长度够了
//         m2.insert(n);
//         return;
//     }

//     for (auto i : m1)
//     {
//         if(!st[i]) n += i;
//         st[i] = true;
//         dfs(u  + 1, n);
//         st[i] = false;
//         n -= i;
//     }
// }

void solve()
{   
    int n; cin >> n;
    v1.clear();m1.clear();m2.clear();v2.clear();
    int t1 = n;
    while(t1)
    {
        v1.push_back(t1 % 10);
        t1 /= 10;
    }
    // cout << "v1 : " <<  v1.size() << endl;
    t1 = n;
    while(t1)
    {
        m1.insert(lowbit(t1));
        t1 -= lowbit(t1);
    }
    // 得到每一个lowbit

    int ans =  m1.size() + 1;
    for(auto i : m1)
    {
        // cout << i << " ";
        v2.push_back(i);
    }
    for(int i = v2.size() - 1 ; i >= 0; i--)
        if(n == v2[i]) ans--;
    // cout << endl << endl;
    cout << ans <<endl;
    for(int i = v2.size() - 1 ; i >= 0; i--)
        if(n != v2[i]) cout <<n -  v2[i] << " ";
    cout << n ;
    cout << endl;
}

signed main()
{
    int _; cin >> _;
    while(_--) solve();
    return 0;
}
