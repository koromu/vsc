#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>


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
    unordered_map<int, int> ha;   
    int n; cin >> n;
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> w[i];
        ha[w[i]] = i;// 存下一个数字的下标是多少
    }
    ll ans = 0;
    for(int i = 1 ; i < n ; i ++)
    {
        // 枚举每一个合数
        for(int j = 1 ; j < n * j ; j ++ )
        {
            if(ha[i / j])
            {
                // 如果存在这个合数的话
                if(ha[j])
                {
                    if(ha[i / j] + ha[j] == i * j)
                        ans ++;
                }
            }
        }
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