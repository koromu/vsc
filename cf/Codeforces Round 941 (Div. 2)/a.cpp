#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool cmp(int a, int b )
{
    return a > b;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    int ha[110] = {0};
    for(int i = 0 ; i < n; i ++)
    {
        int tmp;
        cin >> tmp;
        ha[tmp] ++;
    }
    sort(ha, ha + 110, cmp);
    if(ha[0] >= m) cout << m - 1 << endl;
    else cout << n << endl;;
}

int main()
{
    int _;
    cin >> _;
    while(_--)
    {
        solve();
    }
}