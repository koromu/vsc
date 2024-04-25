#include <iostream>
#include <vector>
#include  <cstring>

using namespace std;

const int N = 200010;//

int a[N];
int ne[N];
void solve()
{
    memset(ne, 0, sizeof ne);
    int n, q;
    cin >> n;
    for(int i = 1 ; i <= n ; i ++) cin >> a[i];
    //遍历终点, 然后更新前面的点, 每个下标存的是最近的一个不同的点
    for(int i = 2, l = 1; i <= n ; i ++)
    {
        if(a[i] != a[l])
        {
            while(l < i)//遍历到i的前面
            {
                ne[l++] = i;//下标l存的是最近的一个不同的数
            }
        }
    }
    // cout << n << endl;
    // for(int i = 1 ; i <= n ; i ++) cout << ne[i] << endl;

    cin >> q;
    while(q--)
    {
        int  l, r;
        cin >> l >> r;
        if(r >= ne[l] && ne[l])
            cout << l << " " << ne[l] << endl;
        else puts("-1 -1");
    }
    cout << endl;
}


int main()
{
    int _;
    cin >> _;
    while(_--)
    {
        solve();
    }

    return 0;
}