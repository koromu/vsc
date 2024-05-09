#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>

using namespace std;

const int N = 30010;

int v[N], s[N], p[N];
// 记录体积, 距离根节点的距离, 和集合数组
struct Q{
    char op[2];
    int x, y;
}Qs[N];

int find(int x)
{
    if(p[x] != x)
    {
        int tmp = find(p[x]);
        s[x] += s[p[x]];// 因为第一合并的时候, 只把父节点的值给更新了
        // s[p[x]]此时应该表示p[x]到根的距离
        // 所以这个点的值先用父节点更新一下, 然后再把父节点忘掉
        p[x] = tmp;
    }
    return p[x];
}

int main()
{
    int _; cin >> _;
    // 还是先读入合并操作
    for(int i = 0; i <= N; i ++) p[i] = i, v[i] = 1;// 编号的范围是1 ~ N
    for(int i = 0 ; i < _; i ++)
    {
        char op[2];
        int x, y;
        // cin >> Qs[i].op >> Qs[i].x >>  Qs[i].y;
        cin >> op >> x >> y;
        int pa = find(x), pb = find(y);// 是吧i接到j的那一列后面
        // 如果是同一个集合的话, 也要更新一下距离
        if(op[0] == 'M')
        {
            if(pa != pb)
            {
                p[pa] = pb;
                // 其实就是这样的话, 我们不能很方便的把一个根节点的所有节点的数值更新成接在一列后面的结果
                // 所以在这里只需要更新父节点的值就行了, 也就是更新一列的头 
                // 这个时候一个列的头的长度就变成了上一个的体积, 作为头的值都是0, 所以维持相对距离就行
                // 然后唯一的头的长度是用更新了, 更新的就是总体积, 加上后来的列的头的体积就行了
                s[pa] = v[pb];
                v[pb] += v[pa];
            }
        }
        else 
        {
            if(pa == pb)
                cout << max(abs(s[x] - s[y]) - 1, 0) << endl;
                // find过程用的是更新s用的是x也就是自身加上到根节点的距离, 所以输出的时候也用的是x和y
                // 而不是pb, pa, 这个东西全是相同的
            else puts("-1");
        }
    }

    // 一个非常蠢的问题, 这个问题问的应该是当前这两个舰队是不是在一个列中, 如果全部放在一起, 那么与题意不符
    // for(int i = 0 ; i < _; i ++)
    // {
    //     Q q = Qs[i];
    //     int pa = find(q.x), pb = find(q.y);// 是吧i接到j的那一列后面
    //     if(q.op[0] == 'M')
    //     {
    //         if(pa != pb)
    //         {
    //             p[pa] = pb;
    //             // 其实就是这样的话, 我们不能很方便的把一个根节点的所有节点的数值更新成接在一列后面的结果
    //             // 所以在这里只需要更新父节点的值就行了, 也就是更新一列的头 
    //             // 这个时候一个列的头的长度就变成了上一个的体积, 作为头的值都是0, 所以维持相对距离就行
    //             // 然后唯一的头的长度是用更新了, 更新的就是总体积, 加上后来的列的头的体积就行了
    //             s[pa] = v[pb];
    //             v[pb] += v[pa];
    //         }
    //     }
    // }

    // for(int i = 0 ; i < _ ; i ++)
    // {
    //     Q q = Qs[i];
    //     int pa = find(q.x), pb = find(q.y);
    //     if(q.op[0] == 'C')
    //     {
    //         if(pa == pb)
    //             cout << max(abs(s[q.x] - s[q.y]) - 1, 0) << endl;
    //         else puts("-1");
    //     }
    // }

    return 0;
}