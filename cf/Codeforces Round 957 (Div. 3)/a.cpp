#include <iostream>
#include <algorithm>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 200010;

void solve()
{   
    int w[3];
    for(int i = 0 ; i < 3 ; i ++ ) cin >> w[i];
    // 对于三个数我们每次给当前最小的那个数加1
    for(int i = 0 ; i < 5 ; i ++)
    {
        sort(w, w + 3);
        w[0]++;
    }
    int sum = 1;
    for(int i= 0 ; i < 3 ; i ++) sum *= w[i];
    cout << sum << endl;
}



signed main()
{
    int _; cin >> _;
    while(_--) solve();
    return 0;
}
