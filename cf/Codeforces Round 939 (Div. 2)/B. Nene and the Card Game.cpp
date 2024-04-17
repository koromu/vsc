#include <iostream>
#include <unordered_map>

using namespace std;
const int N = 110;


int n;
void solve()
{
    cin >> n;
    unordered_map<int, int> m1;
    int ans = 0;
    for(int i = 0 ; i < n ; i ++) 
    {
        int tmp ; cin >> tmp;
        
        if(m1[tmp]) {
            ans ++;
        }
        m1[tmp] ++;
    }
    cout << ans << endl;
    //先手只能拿到相同的牌的分, 所以就是统计相同的分
    return ;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
}