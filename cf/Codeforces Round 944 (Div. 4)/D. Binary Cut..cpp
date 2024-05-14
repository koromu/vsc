#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}


void solve()
{
    string a;
    cin >> a;
    int res = 0;
    // for(int i = 0 ; i + 1 < a.size() ; i ++)
    // {
    //     // 遍历这个字符串, 如果后面的字符比前面的字符大1, 那么就继续, 否则res++, 然后i直接++ 继续判断
    //     // 最欧加上最后一段
    //     if(a[i] == '1')
    //         if(a[i + 1] == '0')
    //             res ++;
    // }
    int i = 0;// 全局坐标 
    // 错了, 全部错了, 只能有一个01串
    // 先判断是否有1串
    if(a[i] == '1')
    {
        for(; i < a.size() ; i ++)
        {
            if(a[i + 1] == '0' && i + 1 < a.size()) // 如果超过了就不进入这个判断了
            {
                // 如果下一个是1的话, 那么就答案加1, 然后退出这个循环, 然后判断01串
                res ++;
                i ++;
                break;
            }   
        }
    }

// 然后判断01 串
    for(; i + 1 < a.size() ; i ++)
    {
        if(a[i] == '1')
        {
            if(a[i + 1] == '0' && i + 1 < a.size())
            {
                res ++;
                i ++;
                break;
            }
        }
    }

    for(; i + 1 < a.size() ; i ++)
    {
        if(a[i] != a[i + 1]) res ++;
        //如果前面和后面不一样直接加1
    }
    res ++ ;
    cout << res << endl;
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

