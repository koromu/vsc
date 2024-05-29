#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#define int long long

using namespace std;
typedef pair<int, int > pii;

const int N = 100010;

int w[N];
void solve()
{
    // 32个元素之内
    int x;cin >> x;
    memset(w, 0, sizeof w);
    // 转为二进制
    for(int i = 0 ; i <= 31 ; i ++)
    {
        if(x & (1 << i)) w[i] ++;
    }
    for(int i = 0 ; i <= 31 ; i ++)
    {
        if(w[i] == 2) {
            w[i] = 0, w[i + 1] ++;
            continue;
        }
        if(w[i] == 1 && w[i + 1] == 1)
        {
            w[i] = -1;
            w[i + 1] = 0;
            w[i + 2] ++;
        }
    }
    cout << 32 << endl;
    for(int i = 0 ; i <= 31 ; i ++)
    {
        cout << w[i] << " ";
    }
    cout << endl;

}

signed main()
{
    int _;
    cin >> _;
    while(_--)
    {
        solve();
    }
    return 0;
}