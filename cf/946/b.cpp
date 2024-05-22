#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;
typedef unsigned long long  ull;
const int N = 200010;

void solve()
{
    int n;cin >> n;
    string a;
    string b;
    cin >> a;
    // 同样还是找到不重复的字符
    vector<char> s;
    for(int i = 0 ; i < n ; i ++) s.push_back(a[i]);// 顺便排好了顺序
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());

    for(int i = 0 ; i < n ; i ++)
    {// 判断当前这个字符的下标是什么
        int l = 0,  r = s.size() - 1 ;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(s[mid] >= a[i])
            {
                // 如果大于等于那么就是在左边
                r = mid;
            }
            else l = mid + 1;
        }
        // 最后找到了这个下标
        int c = s.size();
        // acdefg
        l += 1;
        if(c % 2 == 0)
        {
            // 如果是偶数
            if(l <= c / 2)
            {
                // 那么就是在左边
                b += s[c - l];
            }
            else{
                b += s[c - l];
            }
        }
        else
        {
            if(l < c / 2 + 1)
            {
                b += s[c - l];
            }
            else if(l > c / 2 + 1)
            {
                b += s[c - l];
            }
            else b += s[l - 1];
        }
    }
    cout << b << endl;
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