#include <iostream>

using namespace std;
const int N = 110;

int a[N];

int k, q;
void solve()
{
    cin >> k >> q;
    for(int i = 0 ; i < k ; i ++) cin >> a[i];
    for(int i = 0 ; i < q ; i ++)
    {
        int peo;
        cin >> peo;//这个是人, 从1 ~ peo排序2
        //然后看a[i]中最小的数字, 分类讨论
        //最小的数等于1的话, 那么最后的人0人, 如果小于peo那么最后剩下的就是peo-1
        //如果大于peo, 那么剩下的就是peo
        //如果等于peo, 那么剩下的就是peo - 1
        if(a[0]== peo) 
        {
            cout << peo - 1 << " ";
        }
        else if(a[0] > peo) cout << peo << " ";
        else if(a[0] == 1) cout << 0 << " ";
        else cout << a[0] - 1 << " ";
    }
    cout << endl;
    return ;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
}