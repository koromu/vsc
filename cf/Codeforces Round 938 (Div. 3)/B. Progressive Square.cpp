#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
using namespace std;
const int N = 200010;
int n, c, d;

void solve()
{
    vector<int> w, t;
    // memset(w, 0, sizeof w);
    int minv = INT_MAX, tmp = 0;
    cin >> n >> c >> d;
    for (int i = 0; i < n * n; i++) {
        cin >> tmp;
        w.push_back(tmp);
        minv = min(tmp, minv);
    }
    
    // 1.通过递归推出所有数, 然后二分查找数组, n^2*logn
    for(int i = 0 ; i <= n - 1 ; i ++)
        for(int j = 0 ; j <= n - 1 ; j ++)
        {
            t.push_back(minv + i * c + j * d);
        }
    
    sort(w.begin(), w.end());
    sort(t.begin(), t.end());
    if(w == t) puts("YES");
    else puts("NO");
    return;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}