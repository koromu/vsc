#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
const int N = 15;
int a[N];
bool st[N], ha[N];
int main()
{
    // 最多多少用户同时存在, 然后任意两个的差值不等于k
    // 感觉先排一个顺序, 然后计算差值
    int n, k;
    cin >> n >> k;
    for(int i = 0 ; i < n ; i ++) cin >> a[i];
    int ans = 0;

    sort(a, a + n);
    for(int i = 0 ; i < n ; i ++)
    {
        if(ha[a[i]]) continue;
        ha[a[i]] = true;
        for(int j = i + 1 ; j < n && (a[j] - a[i] <= k) && !st[j] ; j ++ )
        {
            if(a[j] - a[i] == k)
            {
                // 如果等于k的话
                ans ++;
                st[j] = true;// 标记一下在计算这个数字了                
            }
        }
    }
    cout << n - ans << endl;
    return 0;
}

