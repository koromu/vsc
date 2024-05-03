#include <iostream>
#include <bitset>
using namespace std;
typedef long long ll;
const int N = 200010;
void solve()
{
    int n, m;
    cin >> n >> m;
    int b[N], tmp1;
    int maxa = 0, mina = 0, s = 0;
    for(int i = 0 ; i < n ; i ++) cin >> tmp1, maxa ^= tmp1/*, cout << "maxa : " <<  maxa << endl*/;
    for(int i = 0 ; i < m ; i ++) cin >> b[i], s |= b[i];
    ll tmp = 0;
    if(n % 2 == 0)//偶数的情况
    {
        mina = maxa;
        //遍历s的每一位
        for(int i = 0; i < 32 ; i ++)
        {
            //如果s的这个位是1的话, 那么
            if((s >> i) & 1)
            {
                if((mina >> i) & 1)
                    mina -= (1 << i);
            }
            // cout << mina << endl;
        }
        // mina ^= tmp;// 最小值不能这么算
        cout << mina << " " << maxa << endl;
    }
    else
    {
        mina = maxa;
        ll tmp2 = 0;
        for(int i = 0; i < m ; i ++)
        {
            //奇数
            tmp2 |= b[i];
            // cout << "b[i] : " << b[i] << " tmp2 : " << tmp2 << endl;
        }
        maxa |= tmp2;
        cout << mina << " " << maxa << endl;
        //是个奇数的话
    }


    

    return;
}

int main()
{
    int _;cin >> _;
    while(_--)
    {
        solve();
    }

    return 0;
}