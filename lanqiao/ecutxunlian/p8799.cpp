#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <math.h>
#include <queue>
#define int long long

using namespace std;
typedef pair<int, int > pii;

const int N = 200010, M = 1010;;
vector<int> w;
bool ans[N];// 对应每一对零件都算出一个合法的答案, 不合法就算了

unordered_map<int, int> ha;

signed main()	
{
    int n, m, maxv = -1;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i ++)
    {
        int tmp;
        cin >> tmp;
        w.push_back(tmp);
        maxv = max(maxv, w[i]);
        ha[w[i]]++;
    }
    sort(w.begin(), w.end());
    w.erase(w.begin() ,unique(w.begin(), w.end()));

    // for(int i = 1; i <= n ; i ++)
    // {
    //     // 枚举倍数
    //     for(int j = 2 ; j <= 200000 ; j ++)
    //     {
    //         if(ans[j]) continue;
    //         if(w[i] * j > maxv) break;
    //         if(ha.find(w[i] * j) != ha.end())
    //         {
    //             ans[j] = true;
    //         }   
    //     }
    // }

    while(m--)
    {
        bool flag = false;
        int q;cin >> q;

        for(int i = 1 ; i <= n ; i ++)
        {
            if(w[i] * q > maxv)
            {
                puts("NO");
                flag = true;
                break;
            }
            if(ha.find(w[i] * q) != ha.end())
            {
                if(w[i] * q == w[i])
                {
                    if(ha[w[i]] >= 2)
                    {
                        puts("YES");
                        flag = true;
                        break;
                    }
                }
                else
                {
                    puts("YES");
                    flag = true;
                    break;
                }
            }
        }
        if(!flag)
            puts("NO");
        // 也就是需要一个齿轮是另外一个齿轮的q倍
    }// 预处理所有的可能性的话

    // while(m--)
    // {
    //     int q;cin >> q;
    //     if(q == 1)
    //     {
    //         if(ha[1] >= 2)
    //         {
    //             puts("YES");
    //         }
    //         else puts("NO");
    //         continue;
    //     }
    //     if(ans[q]) puts("YES");
    //     else puts("NO");
    // }

    return 0;
}