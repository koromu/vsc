#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 200010;
int a[N]; // 存储猩猩的高度
// int prefix_sum[N];  // 用来存储高度的前缀和
// int pre[N][N];

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int t = 0;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> a[i];
        cout << a[i] << " ";
    }
    
    cout << "\n";

    sort(a + 1, a + t + 1); // 从小到大
    int ans = 0;
    priority_queue<int> q;
    if (k != n && k != m)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int x = i, y = j;
                if (n % 2 == 0)
                {
                    // 如果n是奇数的话
                    if (i >= (n + 1) / 2 + 1)
                    {
                        x = n - i;
                    }
                }
                else
                {
                    if (i >= n / 2 + 1)
                    {
                        x = n - i;
                    }
                }
                if (m % 2 == 0)
                {
                    if (j >= (m + 1) / 2 + 1)
                    {
                        y = m - j;
                    }
                }
                else
                {
                    if (j >= m / 2 + 1)
                    {
                        y = m - j;
                    }
                }
                // if(i >= n / 2 + 1)
                // {
                //     x = n - i ;
                // }
                // if(j >= m / 2 + 1)
                // {
                //     y = m - j;
                // }
                q.push(min(x * y, k * k));
            }
        }
    }
    else
    {
        // 如果有一个相等就不能这么算了
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int x = i, y = j;
                if (n % 2 == 0 && n != k)
                {
                    // 如果n是奇数的话
                    if (i >= (n + 1) / 2 + 1)
                    {
                        x = n - i;
                    }
                }
                else if(n % 2 == 0 && n != k)
                {
                    if (i >= n / 2 + 1)
                    {
                        x = n - i;
                    }
                }

                if (m % 2 == 0 && m != k)
                {
                    if (j >= (m + 1) / 2 + 1)
                    {
                        y = m - j;
                    }
                }
                else if(m % 2 == 1 && m != k)
                {
                    if (j >= m / 2 + 1)
                    {
                        y = m - j;
                    }
                }
                // if(i >= n / 2 + 1)
                // {
                //     x = n - i ;
                // }
                // if(j >= m / 2 + 1)
                // {
                //     y = m - j;
                // }
                cout << x << " " << y << "\n";
                q.push(min(x * y, k * k));
            }
        }
    }

    for (int i = t; i >= 1; i--)
    {
        // cout << q.top() << " ";
        ans += a[i] * q.top();
        q.pop();
    }
    // cout << "\n";
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
