#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solve()
{
    int n;cin >> n;
    string s, obj;
    cin >> s;
    int ans = 1e9;
    for(int i = 1 ; i <= n; i ++)
    {
        if(n % i != 0) continue;
        //切割一个长度是i的子串
        int cnt = 0;
        obj = s.substr(0, i);//substr传入的是开始的下标和长度
        for(int j = i, p = 0 ; j < n ; j ++) 
        {
            if(obj[p] != s[j])//如果不相同
                cnt ++;
            if(cnt > 1) break;
            p ++;
            if(p == i) p = 0;
        }
        if(cnt <= 1)//如果到最后还是合法的话, 那么就是一个可能性了
        {
            ans = i;
            break; 
        }
    }

    for(int i = 1 ; i <= n; i ++)
    {
        if(n % i != 0) continue;
        //切割一个长度是i的子串
        int cnt = 0;
        obj = s.substr(n - i, i);//substr传入的是开始的下标和长度
        for(int j = 0, p = 0 ; j <= n - i - 1 ; j ++) 
        {//12345678 i = 3 j = 5确实是 n - i - 1, 第五个数下标是1
            if(obj[p] != s[j])//如果不相同
                cnt ++;
            if(cnt > 1) break;
            p ++;
            if(p == i) p = 0;
        }
        if(cnt <= 1)//如果到最后还是合法的话, 那么就是一个可能性了
        {
            ans = min(ans, i);
            break; 
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
    // 首先一个字符串想要拆成连续的相同的一段一段的话, 所有字符都要拆进去的话, 那么这个子串的长度一定就是这个总长度的约数
    // 然后再看一个字符串被切开来的话, 那么开头一定是在一个段落之中, 直接枚举合法的长度, 然后从开头开始判断, 如果和后面的段落和目标字符串相差不止是一个不同的话, 就增加长度
    // 从开头的字符串可能
    return 0;
}