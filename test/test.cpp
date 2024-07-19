#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 100010;
int w[N];

vector<string> v1;

void solve()
{
    string n; cin >> n;
    for(int i = 0 ; i <= 60 ; i ++)
    {
        v1.push_back(to_string((int)pow(2, i)));
    }
    // for(int i = 0 ; i < v1.size() ; i ++) cout << v1[i] << " ";

    int ans = 0;

    for(int i = 0 ; i < v1.size() ; i ++)
    {
        // 取出每一个字符
        int tmp = 0;
        for(int j = 0 ; j < v1[i].size() ; j ++)
        {
            if(n[i] != v1[i][j])
            {
                tmp ++;
            }
        }
        
    }
    cout << endl;

}
signed main()
{
    int _  = 1; 
    cin >> _;
    while(_--)
    {
        solve();
    }

    return 0;
}