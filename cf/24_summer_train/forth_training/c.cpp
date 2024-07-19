#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 200010;
int w[N];
int q[N * 2 + 10];

void solve()
{   
    int v1 = 0;
    int n; cin >> n;
    int idx = 0;
    int hh = N, tt = N - 1;
    
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> w[i];
        if(w[i] > v1)
        {
            v1 = w[i];
            idx = i;
        }
    }
    // cout << "idx : " << idx << endl;
    if(idx == 1)
    {
        int x = n - 1;// 需要操作的次数
        q[++tt] = w[1];
        int i, j;
        for(i = 2, j = n ; i <= j ;)
        {
            if(w[i] < w[j])
            {
                q[--hh] = w[i++];
            }
            else q[++tt] = w[j--];
        }
        // cout << "hh : " << hh << " tt : " << tt << endl;
        for(int k = hh ; k <= tt ; k ++) cout << q[k] << " ";
        cout << endl;
    }
    else if(idx == n)
    {
        int x = n - 1;// 需要操作的次数
        q[++tt] = w[n];
        int i, j;
        for(i = 1, j = n - 1 ; i <= j ;)
        {
            if(w[i] < w[j])
            {
                q[--hh] = w[i++];
            }
            else q[++tt] = w[j--];
        }
        // cout << "hh : " << hh << " tt : " << tt << endl;
        for(int k = hh ; k <= tt ; k ++) cout << q[k] << " ";
        cout << endl;
    }
    else puts("-1");
}

signed main()
{
    int _; cin >> _;
    while(_--) solve();
    return 0;
}
