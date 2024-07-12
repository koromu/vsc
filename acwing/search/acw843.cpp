#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 1010;

int bfs(string start)
{
    // 一个3*3的字符串组不好存储
    // 可以转化成一个长度为9的字符串就好存了，然后遵守一个转换的规则

    // 一个距离数组，还可以当作状态数组，因为这次不是一个点，而是一个状态
    // 所第一个元素用状态，第二个元素是数字
    // 可以用哈希表，这样的话我们的终点可可以直接用哈希表进行判断
    string end = "12345678x";
    unordered_map<string, int> dis;
    // 还需要一个队列
    queue<string> q;// 存入一个状态, 距离直接到哈希表里面找
    q.push(start);
    dis[start] = 0;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    while(q.size())
    {
        string now = q.front();
        q.pop();
        // 扩展队头
        // 也还是四个方向
        // 首先要知道这个字符串中x的位置
        int index = now.find('x');// 字符产真的博大精深呀, 返回了下标
        int x = index / 3, y = index % 3;
        // cout <<"X : " << x << " y : " <<y << endl;
        // 一个逻辑得到二维坐标
        int dd = dis[now];
        if(now == end) return dd;
        for(int i = 0 ; i < 4 ; i ++)
        {
            int xx = x + dx[i], yy = y + dy[i];
            if(xx >= 0 && xx < 3 && yy >= 0 && yy < 3)
            {
                // 位置合法的话就可以加入了
                // 要进行交换
                swap(now[index], now[xx * 3 + yy]);// 交换一下，然后要恢复，为了下一次，所以保存这个交换的结果要放到队列里面去
                if(dis[now] == 0)
                {
                    q.push(now);
                    // 更新距离, 但是我们只用了一个now数组，距离找不到了，也更新不了。
                    // 所以要先去出来
                    if(dis[now] == 0)
                    dis[now] = dd + 1;// 一个while里用的是同一个now，所以只用取一次
                }
                swap(now[index], now[xx * 3 + yy]);
            }
        }
    }
    return -1;
}

void solve()
{       
    // 最短路，一次变换一个位置
    string start, tmp;    
    for(int i = 0 ; i < 9 ; i ++) cin >> tmp, start += tmp;

    cout << bfs(start) << endl;
}

signed main()
{
    int _ = 1;
    while(_--) solve();
    return 0;
}
