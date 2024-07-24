#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#define int long long
using namespace std;

const int N = 450;
int w[N];
string mp[N];
int x[4];
int y[4];
string tmp;



void solve()
{
    int n; cin >> n;
    int cmp = 0;
    // cout << n << endl;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> mp[i - 1];
        for(int j = 1 ; j <= n ; j ++)
        {
            if(mp[i - 1][j - 1] == '*')
            {
                x[cmp] = i - 1 , y[cmp] = j - 1 ;
                cmp++;
            }
        }
    }
    if(x[0] != x[1] && y[0] != y[1])
    {
        x[2] = x[0], x[3] = x[1];
        y[2] = y[1], y[3] = y[0];
        // cout << x[2] << " " << y[2] << endl;
        // cout << x[3] << " " << y[3] << endl;
        for(int i = 0 ; i < n ; i ++)
        {
            for(int j = 0 ; j < n ; j ++)
            {
                if( (i == x[2] && j  == y[2]) || (i  == x[3] && j  == y[3]))
                {
                    cout << "*";
                }
                else cout << mp[i][j];
            }
            cout << endl;
        }
    }
    else if(y[0] == y[1] && x[0] != x[1])
    {
        x[2] = x[0], x[3] = x[1];
        if(y[0] + 1 < n)
        {
            y[2] = y[0] + 1, y[3] = y[0] + 1;
        }
        else if(y[0] - 1 >= 0)
        {
            y[2] = y[0] - 1, y[3] = y[0] - 1;
        }
        // cout << x[2] << " " << y[2] << endl;
        // cout << x[3] << " " << y[3] << endl;
        for(int i = 0 ; i < n ; i ++)
        {
            for(int j = 0 ; j < n ; j ++)
            {
                if( (i == x[2] && j == y[2]) || (i == x[3] && j  == y[3]))
                {
                    cout << "*";
                }
                else cout << mp[i][j] ;
            }
            cout << endl;
        }
    }
    else if(x[0] == x[1] && y[0] != y[1])
    {
        y[2] = y[0], y[3] = y[1];
        if(x[0] + 1 < n)
        {
            x[2] = x[0] + 1, x[3] = x[0] + 1;
        }
        else if(x[0] - 1 >= 0)
        {
            x[2] = x[0] - 1, x[3] = x[0] - 1;
        }
        // cout << x[2] << " " << y[2] << endl;
        // cout << x[3] << " " << y[3] << endl;
        for(int i = 0 ; i < n ; i ++)
        {
            for(int j = 0 ; j < n ; j ++)
            {
                if( (i  == x[2] && j == y[2]) || (i  == x[3] && j  == y[3]))
                {
                    cout << "*";
                }
                else cout << mp[i][j] ;
            }
            cout << endl;
        }
    }
}

signed main()
{
    int _ = 1; 
    cin >> _;
    while(_--) 
        solve();
    return 0;
}
