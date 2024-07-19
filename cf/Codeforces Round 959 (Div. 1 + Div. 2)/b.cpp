#include <iostream>

using namespace std;

#define int long long
#define pii pair<int, int>
const int N = 2e5 +10, M = 0;

int a[N], b[N];
int p1[N], p0[N];
void solve()
{
   int n; cin >> n;
   string sa, sb; cin >> sa >> sb;
   sa = ' ' + sa;
   sb = ' ' + sb;
   for(int i = 1 ; i <= sa.size() - 1 ; i ++)
   {
        a[i] = (sa[i] == '1');
        b[i] = (sb[i] == '1');
        // cout << a[i] << " ";
   }
//    cout << endl;
   
    for(int i = 1 ; i <= n ; i ++)
    {
        p1[i] = p1[i - 1] + (int)(a[i] == 1);// 1的
        p0[i] = p0[i - 1] + (int)(a[i] == 0);// 0的
    }
    // for(int i = 1 ; i <= n ; i ++)
    // {
        // cout << pa[i] << " " << pb[i] << endl;
    // }
    for(int i = 1 ; i <= n ; i ++)
    {
        if(a[i] != b[i])
        {
            // 如果不同
            if(b[i] == 1)
                if(a[i] == 1)
                {
                    continue;
                }
                else 
                {
                    if(p1[i])
                    {
                        continue;
                    }
                    else
                    {
                        puts("NO");
                        return;
                    }
                }
        }
    }

    cout << "YES" << endl;
}
signed main()
{
    int t = 1;
    cin>>t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
}
