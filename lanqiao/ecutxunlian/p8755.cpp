// #include <iostream>
// #include <algorithm>
// #include <tuple>
// #include <queue>


// #define int long long
// using namespace std;
// const int N = 200010;
// typedef pair<int, int> pii;

// int w[N];// 第i个计算机的算力

// priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>> , greater<tuple<int, int, int>>> heap;
// signed main()
// {
//     int n, m;
//     cin >> n >> m;// 存下总共的计算机数量, 和询问次数
//     for (int i = 1; i <= n; i++) cin >> w[i];

//     for (int i = 1; i <= m; i++)
//     {
//         int a, b, c, d;
//         scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
//         // 当队列不为空
//         while(!heap.empty() && get<0>(heap.top())<= a)
//         {
//             // 判断第一个的时间有没有超过当前的时间a
//             // 如果是小于等于的, 就可以弹出了, 然后再弹出之前还要把算力返回
//             w[get<1>(heap.top())] += get<2>(heap.top());
//             heap.pop();// 弹出去
//         }// 处理完以后可以判断现在这个询问了
//         if(d <= w[b])
//         {
//             // 如果这个算力是合法的话
//             w[b] -= d;
//             printf("%lld\n", w[b]);
//             heap.push({a + c, b, d});// 解锁的时间, 目标计算机的编号, 占用的算力
//         }
//         else puts("-1");
//     }
//     return 0;
// }// 全都要long long 也就是要#define int long long


#include <iostream>
#include <vector>
#include <math.h>
#define int long long
using namespace std;
const int N = 200010;
// typedef pair<ll, ll> pii;

struct Node{
    int c;
    int dead_time;// 算力和持续时间
};

int w[N];// 第i个计算机的算力

vector<Node> v1[N];

signed main()
{
    int n, m;
    cin >> n >> m;// 存下总共的计算机数量, 和询问次数
    for(int i = 1 ; i <= n ; i ++) cin >> w[i];
    for(int i = 1 ; i <= m ; i ++) 
    {
        int a, b, c, d;
        scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        Node tmp;
        tmp.c = d;
        tmp.dead_time = a + c;
        for(auto i = v1[b].begin(); i != v1[b].end() ;)
        {
            // 当前时间是这次询问的时间
            if(a >= i->dead_time) 
            {
                // 如果大于等于的话, 那么就可以把算力更新一下, 然后再把这个点删掉
                w[b] += i->c;
                auto tmp = i;
                i++;
                v1[b].erase(tmp);// 删掉这个迭代器指向的东西
                i--;
            }
            else i++;
        }// 更新算力的过程
        if(d <= w[b]){
            // 判断这个算力够不够, 如果够的话直接更新一下当前的算力, 遍历所有的修改, 如果有修改已经超过了时间, 那么加上这个算力
            v1[b].push_back(tmp);
            w[b] -= d;
            printf("%lld\n", w[b]);
        }// 否则直接下一个
        else puts("-1");
    }
    return 0;
}// 全都要long long 也就是要#define int long long