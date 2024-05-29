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

const int N = 200010;

int a[N], b[N];
pii fin[N];

// vector<pii> heap;
// unordered_map<int, int> ha;
// signed main()	
// {
//     int n, m;cin >> n >> m;
//     for(int i = 1; i <= n ; i ++) cin >> a[i];
//     for(int j = 1; j <= n ; j ++) cin >> b[j];
//     for(int i = 1; i <= n ; i ++)
//     {
//         heap.push_back({a[i], b[i]});
//         ha[a[i]] ++;// 当前这数出现的次数
//     }

//     while(m)
//     {
//         sort(heap.begin(), heap.end());
//         // m的操作次数不为0
//         // 先判断当前最小的相等的数有多少个, 如果大于m的话, 那么就直接输出答案了
//         if(ha[heap.begin()->first] > m)// 题目要求b是正整数
//         {
//             cout << heap.begin()->first << endl;
//             return 0;
//             // 否则的话, 判断次数是不是为大于等于1就是了, 如果有等于1的话, 更新一下答案可以return了;
//         }
//         else
//         {
//             int maxv = heap.begin()->first;
//             for(auto& i : heap)
//             {
//                 // 如果是当前最小值的话
//                 if(i.first == maxv)
//                 {
//                     if(i.second == 1)
//                     {
//                         cout << i.first + 1 << endl;
//                         return 0;
//                     }
//                     else
//                     {
//                         m--;
//                         ha[i.first]--;
//                         ha[i.first + 1]++;
//                         i.first++;
//                         i.second--;
//                         // 记得哈希表也要更新
//                     }
//                 }
//                 else break;
//             }
//         }
//     }
    
//     return 0;
// }

int n, m;

bool check(int x)
{
    int cnt = 0;
    for(int i = 1; i <= n ; i ++)
    {
        // 枚举每一个元素
        if(fin[i].first < x)
        {
            cnt += (x - fin[i].first);// 还要判断这个
            if(fin[i].second < x - fin[i].first)
                return false;
            // 如果这个页是小于x的话, 就是需要补, 然后计算补了多少
        }
        else break;
    }
    if(cnt <= m) return true;
    return false;
}

signed main()	
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++) cin >> a[i];
    for(int j = 1 ; j <= n ; j ++) cin >> b[j];
    for(int i = 1; i <= n ; i ++) fin[i].first = a[i], fin[i].second = b[i];
    int l = 0, r = 400010;
    sort(fin + 1, fin + n + 1);
    while(l < r)
    {
        int mid = l + r + 1 >> 1;
        if(check(mid))
        {
            l = mid;
        }
        else r = mid - 1;
    }
    cout << l << endl;
    return 0;
}