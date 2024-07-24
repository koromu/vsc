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
    int n; cin >> n;
    unordered_map<int, int> ha;
    for(int i = 1; i <= n; i++)
    {
        cin >> w[i];
        ha[w[i]]++;
    }
    for(int i = 1 ; i <= n ; i ++)
    {
        if(ha[w[i]] == 1)
        {
            cout <<  i << endl;
            break; 
        }
    }
}

signed main()
{
    int _ = 1; 
    cin >> _;
    while(_--) solve();
    return 0;
}
