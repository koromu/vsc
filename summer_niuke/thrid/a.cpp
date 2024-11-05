#include <bits\stdc++.h>
#define int long long
using namespace std;

const int N = 500010;
int n, l, r;
int a[500010];
int cf[2 * N];

signed main()
{
    cin >> n >> l >> r;
    if (r == n)
    {
        cout << "Yes" << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    // priority_queue<int> cf;
    int hh = N, tt = N - 1;
    int cy = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] <= 2)
            cy++;
        else
            // cf.push((a[i] + 1) / 2 - 1);
            {
                cf[++tt] = ((a[i] + 1) / 2 - 1);
                sort(cf + hh, cf + tt);
            }
    while (tt - hh + 1 >= l)
    {
        vector<int> tmp;
        int k = 0;
        for (int i = 1; i <= l; i++)
        {
            tmp.push_back(cf[hh++]);
            sort(cf + hh, cf + tt + 1);
            // cf.pop();
        }
        for (int i : tmp)
        {
            i--;
            if (i == 0)
                k++;
            else
                // cf.push(i);
                cf[++tt] = i;
        }

        cy -= min(r - l, cy);
        cy += k;
        if (cy == 0)
        {
            // 如果队列为空
            while(cy == 0 && tt - hh + 1 >= l)
            {
                
            }
            cout << "Yes" << endl;
            return 0;
        }
        if (cy + tt - hh + 1 <= r)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}