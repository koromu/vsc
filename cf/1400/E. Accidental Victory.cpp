#include <iostream>
#include <algorithm>

#define int long long
using namespace std;
typedef pair<int, int> pii;
const int N = 200010;

pii a[N]; 
int b[N];
int n; 
void init()
{
    for(int i = 1 ; i <= n ; i ++) b[i] = b[i-1] + a[i].first;
}

bool check(int pos)
{
    // a[pos]就是那个数
    // 加上前面的所有数
    int x = a[pos].first;
    x += b[pos-1];// 加上前面所有的和
    for(int i = pos; i <= n ; i ++)
    {
        if(x < a[i].first)
        {
            x += (b[i - 1] - b[pos]);
            if(x < a[i].first) return false;// 如果这个数不合法, 也就是小了, 那么答案就在这个数的右边了
        }  
    }
    return true;
}

bool cmp(pii x1, pii x2)
{
    return x1.second < x2.second;
}

void solve()
{   
    cin >> n;
    for(int i = 1 ; i <= n ; i ++) 
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    init();
    // for(int i = 1 ; i <= n ; i ++) cout << a[i].first << " ";
    // cout << endl;
    int l = 1, r = n;
    while(l < r)
    {
        int mid = l + r >> 1;
        // 二分枚举数组
        if(check(mid))// 传入的是一个下标
        {
            // 是合法的话
            r = mid ;
        }
        else l = mid + 1;
        // cout << "l : " << l << " r : " << r << endl;
    }// 这样的话找到的是第一个合法的, 那么这个左边的那个就是不合法的
    cout << n - l + 1 << endl;
    sort(a + l, a + n + 1, cmp);
    // for(int i = l ; i <= n ; i ++) cout << "值为: " << a[i].first  << " a.second: " << a[i].second << endl;
    // 这个l是根据1 ~ n来的, 所以不用+1偏移
    for(int i = l ; i <= n ; i ++) cout << a[i].second << " ";// 需要原始的下标, 而且需要是排序的
    cout << endl;
    return;
}



signed main()
{
    int _; cin >> _;
    while(_--) solve();
    return 0;
}

