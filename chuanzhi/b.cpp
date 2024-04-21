#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef pair<int, int> pii;
const int N = 200010;

//单个的值直接操作, 范围的值记录
int w[N];
// pii op1[N];
int main()
{
    int n, q;
    long long ans = 0;//记录当前次数的总和
    
    cin >> n >> q;
    char op[2];
    for(int i = 1 ; i <= n ; i ++) {
        cin >> w[i];
        ans += w[i];
    }
    int last = 0;
    map<int, int> m1;
    for(int i =  1; i <= q ; i ++)
    {
        cin  >>  op;
        if(op[0] ==  '1')
        {
            //在x上加y
            int x, y;
            cin >> x >> y;
            //用map记录后来被修改的数字,  如果没有被修改的话, 那么就不动, 如果动了,  那么就记录下来,  然后下次 查询的时候就知道要删掉多少了,  如果全部被修改了的话那么就删掉上次被修改 的值, 也就是last
            if(m1.find(x) !=  m1.end())//如果找的到的话, 那么减去上一次被修改的值加上这次修改的值
            {
                ans  = ans - m1[x] + y;
            }
            else 
            {//如果找不到说明这个数要么被修改成了last, 要么没有被修改过, 所以先判断下有没有被修改过
                if(last)
                {
                    ans  =  ans - last + y;
                }
                else
                {
                    ans = ans - w[x] + y;
                }
            }
            cout << ans << endl;
            m1[x] = y;
        }
        else
        {
            int x;
            cin >> x;
            last = x;
            // cout << "x :  "  <<  x << "n  : " <<  n <<  endl;
            m1.clear();//每次全部修改后这个直接变成空, 下一次进入 的情况一定减去last 加上被更改的数
            ans = x * n;
            cout <<  ans <<  endl;
        }
    }

    // for(int i = 1 ; i <= q ; i ++)
    // {
    //     cin >> op;
    //     if(op[0] == '1')
    //     {
    //         int x, y;
    //         cin >> x >> y;
    //         op1[i] = {x, y};
    //     }
    //     else if(op[0] = '2')
    //     {
    //         int x;
    //         cin >> x;
    //         op1[i] = {0, x};//第i操作了全部变成x
    //     }
    // }
    
    // int last = 0;
    // for(int i = 1; i <= q; i ++)
    // {
    //     cout << "i : " <<  i << endl;
    //     if(!op1[i].first)
    //     {
    //         ans = op1[i].second * n;
    //         cout << ans << endl;
    //         last = op1[i].second;
    //     }
    //     else
    //     {
    //         if(last)
    //         {
    //             if(w[op1[i].first] == last)//?
    //                 ans = ans - last + op1[i].second;
    //             else ans = ans - w[op1[i].first]  + op1[i].second;
    //             cout << ans << endl;
    //             w[op1[i].first] = op1[i].second;
    //         }
    //         else
    //         {
    //             //没有修改过
    //             ans = ans - w[op1[i].first]  + op1[i].second;
    //             cout << ans << endl;
    //             w[op1[i].first] = op1[i].second;
    //         }
    //     }
        
    // }
    
    return 0;
}