#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
typedef unsigned long long  ull;
const int N = 200010;

void solve()
{
    int x;
    double y;
    cin >> x >> y;
    // 每一个
    double c = (y / 2);// 完全得到需要多少个y
    int cx = 0;
    if(c == (int)c)
    {// 没有半个的情况
        cx = 7 * c;
        if(x <= cx) cout << c << endl;
        else{
            cout << (((x - cx) % 15 == 0) ? (c + (x - cx) / 15) : (c + (x - cx) / 15 + 1)) << endl;
        }
    }
    else{
        cx = 7 * (int)c + 11;// 右半个的情况
        if(x <= cx) cout << (int)c + 1 << endl;
        else{
            cout << (((x - cx) % 15 == 0) ? ((int)c + (int)(x - cx) / 15) + 1 : ((int)c + (int)(x - cx) / 15 + 1) + 1) << endl;
        }
    }
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