#include <iostream>
#include <string>
#include <algorithm>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 100010;
int n, m, k;
signed main()
{
    int ans = 0;
    double minv = 999;
    int n; cin >> n;
    for(int i = 0 ; i < n ; i ++)
    {
        double t, p; cin >> t >> p;
        double tmp = p / t;
        if(tmp < minv) {
            minv = tmp;
            ans = i + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
