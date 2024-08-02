#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 310;

vector<int> v1;
int q[N];
void solve()
{
    int n; cin >> n;
    string a; cin >> a;
    a = ' ' + a;
    string b = "2020";
    int tmp = 0;
    if(n < 4) 
    {
        cout << "NO" << endl;
        return;
    }
    for(int i = 1 ; i <= a.size() - 1 && tmp <= 4; i ++)
    {
        if(a[i] == b[tmp])
        {
            tmp ++;
            continue;
        }
        else break;
    }
    int tmp2 = 3;
    for(int i = a.size() - 1; i >= 1 && tmp2 >= 0; i --)
    {
        if(a[i] == b[tmp2])
        {
            tmp2 --;
            continue;
        }
        else break;
    }
    // cout << tmp - 1 << " " << tmp2 << endl;
    if((tmp - 1 >= tmp2) || (tmp >= 4 || tmp2 < 0))
    {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
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