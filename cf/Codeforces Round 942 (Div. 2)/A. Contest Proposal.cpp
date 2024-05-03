#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int N = 110; 

void solve()
{
    int n;
    vector<int> va, vb;
    cin >> n;
    int tmp, ans = 0;
    for(int i = 0 ; i < n ; i ++) cin >> tmp, va.push_back(tmp);
    for(int i = 0 ; i < n ; i ++) cin >> tmp, vb.push_back(tmp);
    
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    // cout << n << endl;
    for(int i = 0 ; i < n ;i ++)
    {
        if(va[i] > vb[i])
        {
            //如果大于那么就插入一个
            va.push_back(vb[i]);//大的, 然后排序, 按道理最大的那个就被排除了
            sort(va.begin(), va.end());
            ans ++;
        }
    }
    cout << ans << endl;

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