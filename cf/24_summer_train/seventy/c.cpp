#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 300010;

int w[N];
unordered_map<int, int> v1 ;

void solve()
{
    int n, q; cin >> n >> q;
    int tmp;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> tmp;
        if(v1[tmp] == 0)
        v1[tmp] = i;
    }
    int t;
    while(q--)
    {
        cin >> t;// 每次值看最高的
        cout << v1[t] << " ";
        for(auto& i : v1)
        {
            if(i.second >= v1[t])
            {
                continue;;
            }
            else 
            {
                i.second+= 1;
            }
        }
        v1[t] = 1;
    }
    cout << endl;

}

signed main()
{
    // cout << endl;
    int _ = 1;
    while(_--)
    {
        solve();
    }
    return 0;
}
