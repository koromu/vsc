#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
const int N = 110;

vector<ll> a;
vector<pii> v1;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b); // 思路正确但是不会分数的gcd
}

// 把一个分数变成最简
pii f1(ll x, ll y)
{
    ll ax, ay;
    ax = x / gcd(x, y);
    ay = y / gcd(x, y);
    return {ax, ay};
}

int main()
{
    int n;
    cin >> n;
    ll tmp;
    for (int i = 0; i < n; i++)
        cin >> tmp, a.push_back(tmp);

    a.erase(unique(a.begin(), a.end()), a.end());
    sort(a.begin(), a.end());

    for (int i = 0; i + 1 < a.size(); i++)
    {
        v1.push_back(f1(a[i], a[i + 1])); // 插入分母和分子
    }
    // 然后就是计算每两个分数之间的最大公约数, 答案就是最大公约数的最大值
    pii ans = v1[0];// 直接从第二个开始
    for (int i = 1; i < v1.size(); i++)
    {
        // 遍历每一个分数
        ll x = ans.first;
        ll y = ans.second;

        ll xx = v1[i].first;
        ll yy = v1[i].second;
        ll tmp = ans.first;
        ll gx = gcd(x, xx);
        ll gy = gcd(y, yy);
        ans.first = min(min(gx == 1 ? x : gx, xx / gx == 1 ? xx : xx / gx), x / gx == 1?x : x / gx);
        ans.second = min(min(gy == 1 ? y : gy, yy / gy == 1 ? yy : yy / gy), y / gy == 1 ? y : y / gy);
    }


    cout << ans.second << "/" << ans.first << endl;
    return 0;
}