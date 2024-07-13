#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 10010;
int a[N], b[N];
unordered_map<string, int> ha;

signed main()
{
    int n; cin >> n;
    int tmp;
    bool flag = false;
    // 此处发现卡片数只有10，所以可以试着暴力，然后用哈希存情况，当前出现一样的情况说明是无解的
    int k1, k2; cin >> k1;
    int tt1 = -1, tt2 = -1;
    int hh1 = 0, hh2 = 0;
    for(int j = 0 ; j < k1 ; j ++)
    {
        int tmp; cin >> tmp;
        a[++tt1] = tmp;
    }
    cin >> k2;
    for(int j = 0 ; j < k2 ; j ++)
    {
        int tmp; cin >> tmp;
        b[++tt2] = tmp;
    }
    int ans = 0;
    while(hh1 <= tt1 && hh2 <= tt2)// ab都不为0
    {
        ans ++;
        if(a[hh1] > b[hh2])
        {
            a[++tt1] = b[hh2 ++];
            a[++tt1] = a[hh1 ++];
            string st = "";
            for(int i = hh1 ; i <= tt1 ; i ++)
                st += to_string(a[i]);
            st += " ";
            for(int i = hh2 ; i <= tt2 ; i ++)
                st += to_string(b[i]);
            // cout << "st :" << st << endl;
            if(ha[st] == 0)
                ha[st] = 1;
            else 
            {
                puts("-1");
                return 0;
            }
            // 把当前a,b的状态存起来
        }
        else
        {
            b[++tt2] = a[hh1 ++];
            b[++tt2] = b[hh2 ++];
            string st = "";
            for(int i = hh1 ; i <= tt1 ; i ++)
                st += to_string(a[i]);
            for(int i = hh2 ; i <= tt2 ; i ++)
                st += to_string(b[i]);
            // cout << "st :" << st << endl;
            if(!ha[st])
                ha[st] ++;
            else 
            {
                puts("-1");
                return 0;
            }
        }
    }// 这样出来说明有一个胜利了
    // for(auto i : ha)
    //     cout << i.first << " " << i.second << endl;
    // cout << "hh1 :" << hh1 << " tt1 : " << tt1 << endl;
    // cout << "hh2 :" << hh2 << " tt2 : " << tt2 << endl;
    if(hh1 > tt1)
        cout << ans << " " << 2 << endl;
    else cout << ans << " " << 1 << endl;

    return 0;
}

// 哈希表表示状态的时候也要注意