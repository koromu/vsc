#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

#define int long long
using namespace std;

const int N = 100010;
int w[N];
vector<int> v1;


void solve()
{
    int n, x, y; cin >> n >> x >> y;
    int pos;
    // 1 - y, y - x, x - n
    if((y - 1) % 2 == 0)// 最后要输出奇数个数
    {
        pos = 1;
    }
    else pos = -1;
    for(int i = y - 1  ; i >= 1 ; i --)
    {
        cout << pos << " ";
        pos = pos * -1;
    }
    for(int i = y ; i <= x ; i ++)
    {
        std::cout << 1 << " ";
    }
    // if((n - x) % 2 == 0)// 最后要输出奇数个数
    // {
    //     pos = 1;
    // }
    // else pos = -1;
    // std::cout << "pos : " << pos << endl;
    pos = -1;
    for(int i = x + 1 ; i <= n ; i ++)
    {   
        std::cout << pos << " ";
        pos = pos * -1;
    }
    
    std::cout << endl;
}

// void solve()
// {
//     int n, x, y; cin >> n >> x >> y;
//     for(int i = 1 ; i <= n ; i ++)
//     {
//         if(i < y || i > x)
//         {
//             cout << -1 << " ";
//         }
//         else cout << 1 << " ";
//     }
//     cout << endl;
// }

signed main()
{
    int _ = 1; 
    cin >> _;
    while(_--) solve();
    return 0;
}
