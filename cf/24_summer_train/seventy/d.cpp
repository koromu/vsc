#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>

#define int long long
using namespace std;
typedef pair<int, int> pii;


unordered_map<char, int> ha, alp;

void solve()
{
    ha.clear();
    alp.clear();
    string shunxu = "", s;

    int w[27];
    for(int i = 0 ; i <= 26 ; i ++) w[i] = 0;
    cin >> s;
    s = ' ' + s;
    for(int i = s.size() - 1 ; i >= 1 ; i --)
    {
        if(!ha[s[i]]) {
            shunxu = shunxu + s[i];
            ha[s[i]] = 1;
        }
    }
    // 然后得到了删除顺序的反序
    // reverse(shunxu.begin(), shunxu.end());
    // 然后到了顺序
    shunxu = ' ' + shunxu;
    // cout << shunxu << endl;

    // 因为知道了删除顺序, 还剩下要找的的最开始的那个这种字符串
    // 遍历一遍统计所有单词单词出现的次数, 假设总共是删了26次, 所以用总共出现的次数和最后一个单词出现, 求出一个单词中出现的次数
    // 类比推出所有单词出现的次数
    // 然后从前往后遍历得到一个单词
    for(int i = 1; i <= s.size() - 1 ; i ++)
    {
        w[(int)(s[i] - 'a' + 1)]++;
    }
    // 因为w中已经存了出现了的单词得出现的次数
    // for(int i = 1 ; i <= 26 ; i ++) cout << w[i] << endl;
    // cout << endl;
    // int len = 0;
    for(int i = 1; i <= shunxu.size() - 1 ; i ++)// 
    {
        // 第一个删的字符, 出现了一次
        if(w[shunxu[i] - 'a' + 1])
            {
                // cout << shunxu[i] << " " << w[shunxu[i] - 'a' + 1] << endl;
                if(w[shunxu[i] - 'a' + 1] % (shunxu.size() - i) == 0)
                {
                    alp[shunxu[i]] = w[(int)(shunxu[i] - 'a'  + 1)] / (shunxu.size() - i);
                }
                else
                {
                    cout << -1 << endl;
                    return;
                }
            }
    }
    string ans = "";
    // for(auto i : alp) cout << i.first << " " << i.second << endl;
    for(int i = 1 ; i <= s.size() - 1 ; i ++)
    {
        if(alp[s[i]]){
            alp[s[i]]--;
            ans += s[i];
        }
        else break;
    }
    // 然后按规则计算出原串
    string cmp = ans;
    bool st[26] = {0};
    for(int i = shunxu.size() - 1; i >= 1; i --)
    {
        st[shunxu[i] - 'a'] = true;
        for(int j = 0 ; j <= ans.size() - 1; j ++)
        {
            if(st[ans[j] - 'a']) continue;
            else cmp += ans[j];
        }
    }
    // cout << cmp << " " << s << endl;
    cmp = ' ' + cmp;
    if(cmp != s)
    {
        puts("-1");
        return;
    }
    // for(int i = 0 ; i <= ans.size() - 1 ; i ++) cout << ans[i];
    cout << ans ;
    cout << " ";
    // for(int i = shunxu.size() - 1  ; i >= 1 ; i --) cout << shunxu[i];
    reverse(shunxu.begin(), shunxu.end());
    cout << shunxu.substr(0, shunxu.size() - 1);
    cout << endl;


    int a = 1;
    int b = 2;
    a = a + b;
    a += b;

}

signed main()
{
    // cout << endl;
    int _ = 1;
    cin >> _;
    while(_--)
    {
        solve();
    }
    return 0;
}
