#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
typedef unsigned long long  ull;
const int N = 200010;

int a[N], b[N];
multiset<int> b;
void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i ++) cin >> a[i]; 
    for(int i = 0 ; i < m ; i ++) 
    {
        int tmp;
        cin >> tmp;
        b.insert(tmp);
    }

    // a数组的值和b数组的值相差尽可能的大
    sort(a, a + n);
    sort(b, b + n);
    for(int i = 0 ; i < n ; i ++)
    {
        
    }


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