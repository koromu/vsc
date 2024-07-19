#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 200010;
int w[N];
vector<pair<pii, int>> v1;


void solve()
{
    int n; cin >> n;
    v1.clear();
    for(int i = 1 ;i <= n ; i ++)
    {
        cin >> w[i];
    }
    
    for(int i = 1 ; i <= n ; i ++)
    {
        for(int j = n ; j >= i ; j --)
        {
            if(w[j] <= i && w[j] < w[i])
            {
                if(j - i != 0)
                    v1.push_back({{i, j}, j - i });
                for(int k = j - 1; k >= i ; k --)
                {
                    swap(w[k], w[k + 1]);
                }
                break;
            }
        }
    }
    // for(int i = 1; i <= n ; i ++) cout << w[i] << " ";
    cout << v1.size() << endl;
    for(auto i = v1.begin() ; i <= v1.end() - 1 ; i ++)
    {
        cout << i->first.first << " " << i->first.second << " " << i->second << endl;
    }
    // cout << endl;
    // cout << v1.size() << endl;




    return;
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
