#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 110;
typedef long long ll;
typedef pair<ll, ll> pii;
bool cmp(pii a, pii b)
{
    return a.first < b.first;
}

void solve()
{
    // int a[N], b[N];
    int n, k;cin >> n >> k;
    vector<pii> v1;
    for(int i = 0 ; i < n ; i ++)
    {
        ll a, b;
        cin >> a >> b;
        v1.push_back(make_pair(a, b));
    }
    sort(v1.begin(), v1.end(), cmp);
    //每天能生产k个, 截止日期是ai天, 需要bi个
    ll cnt = 0;
    for(int i = 0, day = 0 ; i < n ; i ++)
    {
        //对于每一个b, 我们看能否在截止日之前做完
        if(cnt + (v1[i].first - day) * k < v1[i].second)//如果有一个做不到那么就直接break
        {
            puts("No");
            return;
        }
        else
        {
            cnt = cnt +((v1[i].first - day) * k - v1[i].second);
            day = v1[i].first;
        }
    }
    puts("Yes");
    return;
}
int main()
{
    int _;
    cin >> _;
    while(_--)
    {
        solve();
    }
    return 0;
}