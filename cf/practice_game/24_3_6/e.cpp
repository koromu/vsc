#include <iostream>

using namespace std;

const int N = 200010;
//一个数组, 记录每个台阶的高度

int h[N];
int n, q;//台阶的数量和问题的数量
//就是算出这个台阶的没一个相差的高度, 然后循环到一个腿长k小于的差的高度
void solve()
{
    for(int i = 1 ; i <= n ; i ++) cin >> h[i];//更本不用算, 这个就是差值
    // for(int i = 0; i < n ; i ++) h[i] = h[i+1] - h[i]; 
    // for(int i = 0 ; i < n ; i ++) cout << h[i] << " ";
    // cout << endl;
    int k;
    for(int i = 0 ; i < 1; i ++)
    {
        cin >> k;
        int l = 0 , r = n;
        while(l < r)
        {
            int mid = l + r  >> 1;
            if(h[mid] <= k)
            {
                //找到最后一个小于等于k的数字
                l = mid + 1;//也就是在有一堆相同的数字的时候, 我们会一直+1, +1, 直到最右边那个符合我们要求的数字
            }        
            else r = mid;
        }
        cout << l << " ";//这个是下标
    }
    cout << endl;
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> q;
        solve();        
    }

    return 0;
}