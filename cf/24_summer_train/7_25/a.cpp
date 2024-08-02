#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 310;

vector<int> v1;
int q[N];
void solve()
{
    int hh = 1, tt;
    int n; cin >> n;
    v1.clear();
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> q[i];
        tt = i;
    }
    int tmp = 1;
    while(hh <= tt)
    {
        if((tmp ++ % 2) == 1)
        {
            v1.push_back(q[hh++]);
        }
        else v1.push_back(q[tt--]);
    }
    for(auto i : v1) cout << i << " ";
    cout << endl;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _  = 1; 
    cin >> _;
    while(_--)
    { 
        solve();
    }
    return 0;
}