#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 100010;

struct duiwu{
    string a;
    int t;
    int fashi;
}d46[N], d47[N];

typedef pair<string, int> psi;

bool cmp(duiwu a, duiwu b)
{
    if(a.t == b.t)
    {
        return a.fashi < b.fashi;
    }
    return a.t > b.t;
}

signed main()
{
    int n; cin >> n;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> d46[i].a >> d46[i].t >> d46[i].fashi;
    }
    int m; cin >> m;
    for(int  i= 1 ; i <= m ; i++)
    {
        cin >> d47[i].a >> d47[i].t >> d47[i].fashi;
    }

    sort(d46 + 1, d46 + n + 1, cmp);
    sort(d47 + 1, d47 + m + 1, cmp);


    cout << "---" << endl;
    return 0;
}
