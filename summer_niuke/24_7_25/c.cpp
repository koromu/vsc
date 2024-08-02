#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define N 1000010
#define B 133

int w[N];
int fa[N];
bool st[N];
int a[N];

bool cmp(pii a, pii b)
{
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int find(int x)
{
    if(fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}


void solve()
{
    int n;cin >> n;
    for(int i = 1 ; i <= n ; i ++)
    {
        fa[i] = i;
        w[i] = 1;
        st[i] = false;
    }
    for(int i = 1; i <= n ; i ++)
    {
        cin >> a[i];
        int x1 = find(a[i]), x2 = find(i);
        if(x1 != x2)
        {
            w[find(i)] += w[x1];
            fa[x1] = x2;// 把x1连到x2上面去
        }
        // find(x1), find(x2);
        // for(int i = 1 ; i <= n ; i ++) 
        // {
        //     // if(fa[i] == i)
        //     std::cout << w[i] << " ";
        // }
        // std::cout << endl;
    }
    int duizi = 0, ans = 0;
    // for(int i = 1; i <= n ; i ++)
    // {
    //     if(fa[i] == i)
    //     {
    //         // 如果找到了父亲
    //         if(w[i] == 2)
    //         {
    //             duizi ++;
    //         }
    //     }
    // }
    for(int i = 1 ; i <= n ; i ++) find(i);
    for(int i = 1 ; i <= n ; i ++)
    {
        if(fa[i] == i && !st[fa[i]])
        {
            // std::cout << "w[i] :" << w[i] << endl;
            // 如果找到了父亲
            if(w[i] == 2)
            {
                duizi ++;
            }
            else if(w[i] >= 3 && w[i] <= 4)
            {
                ans++;
            }
            else if(w[i] >= 5)
            {
                int mm =  (w[i]) % 3;
                // std::cout << "mm : " << mm << endl;
                if(mm)
                {
                    ans += (w[i]) / 3 ;
                    if(mm == 2)
                    {
                        // std::cout << "1111" << endl;
                        duizi ++;
                    }
                }
                else 
                {
                    ans += (w[i]) / 3;
                }
            }
            st[fa[i]] = true;
        }
        // std::cout << ans << endl;
    }
    // std::cout << duizi << endl;
    // std::cout << ans << endl;
    if(duizi >= 2)
    {
        ans += (duizi / 2);
        if(duizi % 2) 
            ans ++;
    }
    else if(duizi == 1) ans++;
    // for(int i = 1 ; i <= n ; i ++) std::cout << fa[i] << " ";
    // std::cout << endl;

    // for(int i = 1 ; i <= n ; i ++) 
    // {
    //     if(fa[i] == i)
    //         std::cout  << "i : " << i << " " << w[i] << endl;
    // }

    std::cout << ans << endl;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _  = 1; 
    cin >> _;
    while(_--)
    { 
        solve();
    }
    return 0;
}
