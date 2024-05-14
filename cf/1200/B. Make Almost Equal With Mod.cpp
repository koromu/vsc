#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

const int N = 110;
typedef long long ll;
ll a[N];
unordered_map<ll, int> ha;
void solve()
{
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i ++) cin >> a[i];
    ll x = 1;
    bool flag = true;

    do
    {
        x <<= 1;// 2 4 8 
        ha.clear();
        flag = true;
        int tmp = 0;
        for(int i = 0 ; i < n ; i ++)
        {
            // cout << a[i] / x<< " " << a[i] % x << endl;
        // 遍历每一个数计算出现几个数, 每一个记录一下, 然后如果遍历完了还是true, 就退出
            if(ha[a[i] % x] == 0)// 如果没有出现过
            {
                ha[a[i] % x]++, tmp++;
            }
        }
        // 每一个数都处理过了后, 看出现了多少个不同的, 一个也不行, 三个也不行, 只能是2个
        if(tmp != 2) flag = false;
    }
    while(!flag);
    
    // if(flag)
    
    cout << x << endl;// 因为一定存在答案, 所以直接输出

    return ;
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