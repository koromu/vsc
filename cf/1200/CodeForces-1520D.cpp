#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
typedef pair<int, int> pii;// 存点的下标
typedef unsigned long long ll;

bool cmp(int a, int b)
{
    return a > b;
}

const int N = 200010;
int w[N];
int ha[N * 2];// 差值的最大值是2e5, 但是最小是-2e5, 而且相同为负数的话, 也是可以组合, 所以进行偏移
ll C(int a, int b)
{
    ll ans = 1;
    for(int i = a , j = 1; i >= a - b + 1; i --, j ++)
    {
        ans = ans * i / j;
    }
    return ans;
}

void solve()
{
    int n;
    memset(ha, 0, sizeof ha);
    cin >> n;
    ll ans = 0;
    for(int i = 0 ; i < n ; i ++) {
        cin >> w[i];
        w[i] = w[i] - i;
        ha[w[i] + 200000]++;
    }

    for(int i = 0 ; i <= n + 200000 ; i ++)
    {
        if(ha[i])
            ans += C(ha[i], 2);
    }
    cout << ans << endl;
    
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