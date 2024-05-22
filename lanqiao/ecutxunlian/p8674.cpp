#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;
const int N = 1000010;
struct point{
    int time;// 当前的时间
    int c;// 调的次数
    bool operator < (const point &i )const {
        return c > i.c;
    }
};

bool st[N];// 每个时间可能走过的次数

priority_queue<point> q;

int main()
{
    int n, k, ans = 0;
    cin >> n >> k;
    // 但是这并不一定是最优解, 证明不来, 所以还是使用dfs或者bfs
    q.push((point){0, 0});// 显存一个其实的点
    st[0] = true;
    while(!q.empty())
    {
        // 当队列不空的话
        point now = q.top();
        ans = max(now.c, ans);// 从队头取出来的点才是步数最少的点
        q.pop();
        if(!st[(now.time + 1) % n])// 如果下一个时间没有做过的话, 那么就走一下
        {
            st[(now.time + 1) % n] = true;
            q.push((point){(now.time + 1) % n, now.c + 1});
        }
        if(!st[(now.time + k) % n])
        {
            st[(now.time + k) % n] = true;
            q.push((point){(now.time + k) % n, now.c + 1});
        }// 第一次到达的点一定是用步数最少的点, 所以直接标记成走过的点, 然后再从最少的步数中找到最大的那个就是答案了
    }
// 因为我们需要找到最小的步骤, 一步一步的看, 可能走1步可能走k步, 某一个时间第一个走到的点的步数就是最小的
// 所以可以每次选步数最小的的点, 然后走一步, 那么此时下一个点的步数就是最小的
// 每次从步数最小的点走一步, 下一步走到的时间点就是步数最小的点, 看来优先队列也是可以的, 直接改成普通队列也是可以的
    cout << ans << endl;
    return 0;
}

