#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

#define int long long
using namespace std;

const int N = 200010;
int w[N];

bool cmp(int a, int b)
{
    return a > b;
}

// void solve()
// {
//     // 从第一个样例可以得知，这个估计是要贪心了
//     // 首先读入盒子的数量之后
//     // 先排序，从左到右每个盒子放一个当前剩余的最大的数
//     // 此时从左到右盒子里的数是从大到小的
//     // 然后还有多的数字的话，根据wi（wi>=1）
//     // 首先统计出wi中1的个数，设为x
//     // 然后sum = 0
//     // 
//     int n, k;
//     cin >> n >> k;
//     priority_queue<int> q;
//     ha.clear();
//     int tmp;
//     for(int i = 1 ; i <= n ; i ++)
//     {
//         cin >> tmp;
//         q.push(tmp);

//     }
//     for(int i = 1 ; i <= k ; i ++) 
//     {
//         cin >> w[i];
//         ha[w[i]]++;// 统计出wi中每个数的个数
//     }
//     // 排序都不用了，有大根堆
//     int sum = 0;
//     // 如果存在1的话，就直接加上两倍
//     // for(auto i : ha) cout << i.first << " " << i.second << " ";
//     // cout << endl;

//     if(ha[1])
//         for(int k = 1 ; k <= ha[1] ; k ++)
//         {
//             sum += (2 * q.top());
//             q.pop();
//         }
//     for(int i = 1 ; i <= n ; i++) 
//         if(w[i] == 1) w[i]--;
//     // 如果存在大于1的值，先确定最大值，然后确定最小值
//     // 遍历w数组，如果是大于等于2的，那么加上一个当前剩余的最大值
//     for(int i = 1 ; i <= n ; i ++)
//     {
//         if(w[i] >= 2)
//         {
//             sum += q.top();
//             q.pop();
//         }
//     }// 扫最大值

//     bool flag = false;
//     do   
//     {
//         flag = false;
//         for(int i = 1; i <= n ; i ++)
//         {
//             if(w[i])
//             {
//                 w[i]--;
//                 if(w[i]) flag = true;
//                 else sum += q.top();
//                 q.pop();
//             }
//         }
//     }// 扫最小值
//     while(flag);

//     cout << sum << endl;
// }

void solve()
{
    // 我们可以发现一个很特殊的就是wi = 1的那个人, 他只能放一个, 然后可以产生的价值是这个两遍这个值, 所以很容易想到把最大的都给这些wi = 1的人 
    // 然后这个时候剩下的人的价值都是有最大值和最小值构成了, 其中一个人的价值和中间值无关, 为了所有的人价值最大, 我们要把中间这些无用的值最大, 并且每个人的价值最大
    // 每个人的价值是由最大值和最小值构成的, 所以要每一个人的最大值最大和最小值最大
    // 考虑最大值
    // 每个人的最大值可以思考到从可用的数字中从大到小给予每一个人
    // 所以需要一个排序
    // 然后再考虑最小值
    // 我们要每一个的最小值最大, 可以非常巧妙的开始思考到当前可用值中的最小值的属性, 然后发现这个最小值是一定会使用到的
    // 因为在分配的时候, 没有任何其他的值可以比这个最小值小, 所以不能被覆盖
    // 所以当前可用值最小值的分配无所谓了, 随便给一个人了(吗?)
    // 然后看第二小的值的属性, 发现这个值可能不会被使用到, 也就是这个值可能被覆盖
    // 这个情况就是和当前最小的值在一起的时候才会被覆盖
    // 因为所有的值都会被用到, 所以我们可以把小的值经可能都给覆盖掉
    // 为了覆盖经可能多的小值, 我们要在最小值得那一组插入经可能多的数, 也就是wi要经可能的大, 所以选择wi最大的那一组
    // 然后处理完了当前wi最大的组, 剩下的元素又可以按照一样的逻辑处理剩下的组
    // 这样我们就使小的值最大了，大的值最大，得到的就是最大值
    // 如此贪心
    int n, k;
    cin >> n >> k;
    vector<int> a;
    int tmp;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    for(int i = 1 ; i <= k ; i ++) cin >> w[i];
    // 从大到小排序
    sort(a.begin(), a.end(), cmp);
    sort(w + 1, w + k + 1);
    // for(auto i : a) cout << "a: " <<  i << endl;
    int sum = 0;

    int pos = 1;
    int hh = 0, tt = n - 1;
    while(w[pos] == 1 && pos != k + 1 )
    {
        sum += a[hh] * 2;
        // cout << "i : " << i << " sum :" <<  sum << endl;
        // a.erase(a.begin());// 取出来加上*2然后删掉
        hh ++; 
        pos++;
    }
    // 已经处理好了所有的1
    // 然后处理最大的wi
    for(int j = k ; j >= pos ; j --)// 用上面已经处理好的i
    {
        // sum += a.front();
        // sum += a.back();
        // cout << "a.f(): "  << a.front() << " a.back(): " << a.back() << endl;
        
        sum += (a[hh] + a[tt]);// 一次性加上首尾元素

        // a.erase(a.begin());
        // a.erase(a.end() - 1);
        hh ++;// 把删除操作变成忽略，这样可以一次O(1)删除多个元素
        tt --;
        // 加上了最大值，然后加上一个最小值，然后往前删w[i] - 2个数
        // for(int l = 1 ; l <= w[j] - 2 ; l ++) a.erase(a.end() - 1); // 除尾, 这样子除尾会超时的. 所以直接给忽略掉这些值就行
        tt -= (w[j] - 2);
        // 一次循环刚好少了w[i]个数字，完美^_^
    }
    cout << sum << endl;
    return ;
}


signed main()
{
    int _; cin >> _;
    while(_--) solve();
    return 0;
}