#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 310;

vector<int> v1;
int q[N];

int wei[10] = {0, 9, 99, 999, 9999, 99999, 999999, 9999999};

void solve()
{
    int n; cin >> n;
    int tot = 0;
    if(n % 9)
    {
        tot = n / 9 + 1;
    }
    else tot = n / 9;
    // cout << tot << endl;
    for(int i = 1 ; i <= wei[tot]; i ++)
    {
        int tmp = i;
        int ans = 0;
        bool st[15] = {0};
        while(tmp)
        {
            if(st[tmp % 10] == 0)
            {
                ans += (tmp % 10);
                st[tmp % 10] = true;
            }
            else break;
            tmp /= 10;
        }
        if(ans == n)
        {
            cout << i << endl;
            return;
        }
    }   // 50以内, 每一个是9的话, 只需要
    cout << "-1" << endl;
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