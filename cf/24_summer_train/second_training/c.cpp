#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 200010;
int a[N];
vector<pii> b;
bool st[26];

void solve()
{   
    // // 读入一个数据, 然后变成字母加长度, 我们要的就是不存在奇数长度的子串
    // unordered_map<int, int> ha;
    // string a ; cin >> a;
    // int dsum = 0;
    // for(int i = 0 ; i <= 26 ; i ++)
    // {
    //     if(ha[i] == 1) 
    //     {
    //         dsum++;// 独狼的话, 就是只有一个
    //         st[i] = true;// 处理好了一个字母
    //         ha[i]--;
    //     }
    // }
    // for(int i = 0, j = i; i < a.size(); i = j)
    // {
    //     // 遍历每一个位置
    //     int s1 = 0;
    //     while(j < a.size() )// 如果是独狼的话, 直接进入了
    //     {
    //         if(a[i] == a[j])
    //         // 如果两个相同的话, 并且j还合法的话
    //         {
    //             s1++;
    //             j++;
    //         }
    //         else if(a[i] != a[j] && st[a[j] - 'a'])
    //         {
    //             j++;
    //         }
    //         else break;
    //     }
    //     // 如果j已经到了外面了, 那么这一段全相同
    //     // 出来了就可以插入数组了
    //     b.push_back({s1, a[i] - 'a'});
    //     ha[a[i] - 'a']++;// 这个字母的组加一
    // }

    // // 先删独狼
    // // 再看奇偶
    // for(int i = 0 ; i < b.size() ; i ++)
    // {
    //     if(st[b[i].second]) continue;
    //     // 如果没有处理过
    //     if(b[i].first % 2 == 1)
    //     {
    //         // 如果是奇数的话
    //         // 如果下一个字母的长度大于等于2, 那么只删一个
    //         if(b[i + 1].first >= 2 && b[i + 2].second == b[i].second) dsum +=2;
    //         else if(b[i+1].first == 1) // 独狼没有被加到b中
    //         {
    //             // 把下一个字母删了
    //             dsum++;
    //         }
    //     }
    // }

    // 我们两个两个找, 如果找到两个相同的字符串, 那么就把这之间的字符串删除
    // 先找到哪个删哪个, 这样删除的会更少
    string s; cin >> s;
    s = ' ' + s;
    int ans = 0, tmp = 0;
    unordered_map<char, int> ha;
    for(int i = 1 ; i < s.size() ; i ++)
    {
        if(ha.empty())
        {
            // 如果是空的话直接插入一个
            ha[s[i]]++;
        }
        else 
        {
            if(!ha[s[i]]) // 从第二个开始看, 如果没有出现过, 那么这个就存到ha表中
            {
                tmp++;
                // 如果不存在那么就ans++;
                ha[s[i]]++;
            }
            else
            {
                // 如果已经存在了
                ans += tmp;
                ha.clear();
                tmp = 0;
            }
        // 然后在碰到不同的元素ans就加1, 然后不同的元素也放到ha中
        // 如果存在, 也就是碰到相同的了, 那么这一段就只留这两个相同的, 然后就可以开删了, 就是当前的ans值
        }
    }
    for(auto i : ha)
    {
        ans ++;
    }
    cout << ans << endl;

    // // 如果是奇数, 直接减1
    return; 
}



signed main()
{
    int _; cin >> _;
    while(_--) solve();
    return 0;
}
