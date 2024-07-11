#include <iostream>
#include <algorithm>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 100010;
int w[N];

void solve()
{   
    int n, k; cin >> n >> k;
    for(int i = 0 ; i < k ; i ++)
    {
        cin >> w[i];
    }
    sort(w, w + k);
    int sum = 0;
    for(int i = 0 ; i < k - 1 ; i ++)
    {
        if(w[i] != 1)
        {
            sum += (w[i] * 2) - 1;
        }
        else sum ++;
    }
    cout << sum << endl;
}



signed main()
{
    int _; cin >> _;
    while(_--) solve();
    return 0;
}
