#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int w[N], tmp[N];

void solve()
{
    int n, k, maxv = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        {
            cin >> w[i];
            tmp[i] = w[i];
        }
    // 因为比赛是从前往后的, 所以如果前面有一个比他大的话, 那么等到他这就必输了
    // 所以至少要和第一个比他大的数换, 要么直接到第一个数去
    // 所以遍历算两边答案
    int ans = -1;
    int obj = 0;
    for (int i = 1; i <= k; i++)
    {
        if (w[i] > w[k])
        {
            obj = i;
            break;
        }
    }
    // 如果是和第一个大于k的数的数互换了, 那么答案个数就是, (k - obj)
    if (obj)
    {
        int tmp = 0;
        std::swap(w[obj], w[k]);
        tmp = k;
        k = obj;
        for(int i = k + 1 ; i <= n ; i ++)
        {
            if(w[k] < w[i]) 
            {
                if(k == 1) ans = i - k - 1;//但是和前面的元素还可以赢一场
                else ans= i - k;
                break;
            }
        }
        k = tmp;
    }
    // 和前面第一个你自己大的换

    std::swap(tmp[1], tmp[k]); // 直接和第一个换
    k = 1;
    // for(int i = 0 ; i < n ; i ++) cout << w[i] << " ";
    // cout << endl;
    for (int i = 2; i <= n; i++)
    {
        if (tmp[i] > tmp[k])
        {
            ans = max(i - 2, ans);
            break;
        }
    }
    if(ans == -1) {
        cout << n - 1 << endl;
        return ;
    }
    else cout << ans << endl;
}

int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }

    return 0;
}
