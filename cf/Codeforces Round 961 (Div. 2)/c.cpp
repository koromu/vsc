#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10;

int w[N];
int f[N];

void solve() {
    int n;
    cin >> n ;
    memset(f, 0, sizeof f);
    for(int i = 1 ; i <= n ; i ++) {
        cin >> w[i];
        // cout << w[i] << " ";
    }
    bool flag = false;
    for(int i = 1 ; i <= n ; i ++)
    {
        if(w[i] > 1) flag = true;
        if(w[i] == 1 && flag)
        {
            cout << -1 << endl;
            return;
        }
    }

    // cout << endl;
    // f[i]之前都是不递减的情况
    int ans = 0;
    int pos = 1;
    for(int i = 1 ; i <= n ; i ++)
    {
        if(w[i] != 1)
        {
            pos = i;
            break;
        }
    }

    for(int i = pos + 1 ; i <= n ; i ++)
    {
        if(w[i] < w[i - 1])
        {
            int cmp = 0;
            int tmp = w[i];
            while(w[i - 1] > tmp)
            {
                tmp *= tmp;
                cmp ++;
            }
            
            f[i] = f[i - 1] + cmp;
        }
        else if(w[i] == w[i - 1])
        {
            f[i] = f[i - 1];
        }
        else
        {
            int cc = 0;
            int tmp = w[i - 1];
            while(w[i] >= tmp)
            {
                tmp *= tmp;
                cc ++;
            }
            cc--;
            if(cc >= f[i - 1]) f[i] = 0;
            else if(cc < f[i-1]) f[i] = f[i-1] - cc;
        }
        // for(int i = 1 ; i <= n ; i ++) cout << f[i] << " ";
        // cout << endl; 
    }
    for(int i = 1 ; i <= n ; i ++) ans += f[i];
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
