#include <iostream>
#include <string>
#include <algorithm>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 200010;
int w[N];
int ans[N];
int fa[N];

void solve()
{
    int n; cin >> n;
    int root;
    // p中数组的顺序就是dis从小到大的顺序
    for(int i = 1 ; i <= n ; i ++) {
        cin >> fa[i];
        if(fa[i] == i) root = i;
    }
    int t1; cin >> t1;
    if(t1 != root)
    {
        int tmp;
        for(int i = 2 ; i <= n ; i ++) cin >> tmp;
        puts("-1");
        return;
    }
    else
    {
        ans[root] = 0;
        int cnt = 1;
        for(int i = 2 ; i <= n ; i ++)
        {
            int tmp; cin >> tmp;
            ans[tmp] = cnt++;// 这个是得到了每个点到根节点的距离
        }// 边权都是1, 然后根据原图判断是不是满足距离合法, 父节点比子节点大
        for(int i = 1; i <= n ; i ++)
        {
            if(ans[i] < ans[fa[i]])
            {
                puts("-1");
                return;
            }
        }
        for(int i = 1 ; i <= n ; i ++ )
        {
            cout << ans[i] - ans[fa[i]] << " ";
        }
    }
    cout << endl;
    return;
}


signed main()
{
    int _;cin >> _;
    while(_--)
    {
        solve();
    }
    return 0;
}
