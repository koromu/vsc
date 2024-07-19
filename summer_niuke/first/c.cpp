#include <iostream>
#include <string>
#include <algorithm>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 500010;

struct duiwu{
    string a;
    int t;
    int fashi;
}duis[N];

bool cmp(duiwu a, duiwu b)
{
    if(a.t == b.t)
    {
        return a.fashi < b.fashi;
    }
    return a.t > b.t;
}

void solve()
{
    int n; cin >> n;
    for(int i = 1 ; i <= n ; i ++)
        cin >> duis[i].a >> duis[i].t >> duis[i].fashi;
    for(int i = 1 ; i <= n ; i ++)
        cout << duis[i].a << " ";
    
    sort(duis + 1, duis + n + 1, cmp);
    cout << "---" <<endl;
}

signed main()
{
    int _;cin >> _;
    while(_--)
    {
        solve();
    }
    return 0;
}
