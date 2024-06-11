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

const int N = 200010, M = 1010;

void solvea()
{
    int a = -1, b = -1, c = -1, d = -1, e = -1;
    for(int i = 1 ; i <= 20 ; i ++)
    {
        int no, t1, t2, t3, t4, t5;cin >> no >> t1 >> t2 >> t3 >> t4 >> t5;
        a = max(a, t1), b = max(b, t2), c = max(c, t3), d = max(d, t4), e = max(e, t5);
    }
    cout << a << " " << b << " " << c << " " << d << " " << e << endl;
    cout << a + b + c + d + e << endl;
}

void solveb()
{
    vector<int> v1;
    int n = 2019;
    while(n)
    {
        int a = n % 26;
        v1.push_back(a);
        n/=26;
    }
    // 数组中最高位是高位, 最低位是地位
    for(int i = v1.size() - 1 ; i >= 0 ; i --)
    {
        // cout << v1[i] << endl;
        cout << (char)(v1[i] + 'A' - 1);
    }
    cout << endl;
}

void solvec()
{
    unsigned long long sum[5] = {0};
    sum[1] =  sum[2] = sum[3] = 1;
    for(int i = 4; i <= 20190324 ; i ++)
    {
        sum[i % 5] = (sum[(i-1) % 5] + sum[(i-2) % 5] + sum[(i-3) % 5]) % 10000; 
    }
    cout << sum[20190324 % 5] << endl;
}

int dx[4] = {1, 0, 0, -1}; // 下左右上
int dy[4] = {0, -1, 1, 0};
char op[4] = {'D', 'L', 'R', 'U'};
string map[35];
int st[35][55];
char steps[10010];
bool flag;

// void dfs(int x, int y, char now_op)
// {
//     if(x == 29 && y == 49)
//     {
//         cout << now_op << " ";
//         flag = true; return ;
//     }
//     for(int i = 0 ; i < 4 ; i ++)
//     {
//         if(!st[x + dx[i]][y + dy[i]] && map[x + dx[i]][y + dy[i]] == '0' && (x + dx[i] < 30 && y + dy[i] < 50 && x + dx[i] >= 0 && y + dy[i] >= 0))
//         {
//             // 下一步没有走过, 而且能走, 而且没有越界
//             st[x + dx[i]][y + dy[i]] = true;
//             dfs(x + dx[i], y + dy[i], op[i]);
//             st[x + dx[i]][y + dy[i]]  = false;
//             if(flag)
//             {
//                 cout << now_op ;
//                 return;
//             }
//         }
//     }
// }

struct Node
{
    int x, y;
    int step;
    string s;//在这里面存这个点的路径
};

struct cmp{
    bool operator()(Node a,Node b)
    {
        if(a.step == b.step) return a.s > b.s;
        return a.step > b.step;
    }

};


void solvee()
{
    for(int i = 0 ; i < 30 ; i ++)
    {
        getline(cin, map[i]);
        // 否则初始化就是0
    }
    // for(int i = 0 ; i < 4 ; i ++)
    // {
    //     if(!st[dx[i]][dy[i]] && map[dx[i]][dy[i]] == '0' && (dx[i] < 30 &&  dy[i] < 50 &&  dx[i] >= 0 && dy[i] >= 0))
    //     {
    //         st[dx[i]][dy[i]] = true;
    //         dfs(dx[i], dy[i], op[i]);
    //         st[dx[i]][dy[i]] = false;
    //         if(flag)
    //         {
    //             cout << op[i] ;
    //             return ;
    //         }
    //     }
    // }
    priority_queue<Node, vector<Node>, cmp> q;


    q.push({0, 0, 0, ""});// 这是第一步
    while(q.size())
    {
        Node t = q.top();
        q.pop();
        if(t.x == 29 && t.y == 49)
        {
            cout << t.s << endl;
            return ;
        }
        // if(st[t.x][t.y]) continue;// 只出队一次
        // st[t.x][t.y] = true;

        for(int i = 0 ; i < 4 ; i ++)
        {
            int xx = t.x + dx[i], yy = t.y + dy[i];

            if(st[xx][yy]) continue; // 走过来不走
            if(xx < 0 || xx >= 30 || yy < 0 || yy >= 50) continue; // 越界了不走
            if(map[xx][yy] == '1') continue;// 不能走不走
            q.push({xx, yy, t.step + 1, t.s + op[i]});
            st[xx][yy] = true;
        }
    }
}
// bfs首先这个最短路就是每个点走一遍, 不需要复原
// 路径的话, 每一个点额外维护一个路径, 然后每次走一遍的时候, 我们直接加上这一步的方向, 然后重写比较远算符的以后, 记得有需要的话也要比较这个字典序
// 

signed main()	
{
    solvee();    

    return 0;
}
// DDDDRRURRRRRRDRRRRDDDLDDRDDDDDDDDDDDDRDDRRRURRUURRDDDDRDRRRRRRDRRU
// DDDDRRURRRRRRRDRRRDDDLDDRDDDDDDDDDDDDRDRDRRUUURRRRDDDDRDRRRRRRURRD
// DDDDRRURRRRRRDRRRRDDDLDDRDDDDDDDDDDDDRDDRRRURRUURRDDDDRDRRRRRRDRRURRDDDRRRRUURUUUUUUULULLUUUURRRRUULLLUUUULLUUULUURRURRURURRRDDRRRRRDDRRDDLLLDDRRDDRDDLDDDLLDDLLLDLDDDLDDRRRRRRRRRDDDDDDRR
// DDDDRRURRRRRRRDRRRDDDLDDRDDDDDDDDDDDDRDRDRRUUURRRRDDDDRDRRRRRRURRDRRDDDRRRRUURUUUUUUULULLUUUURRRRUULLLUUUULLUUULUURRURRURURRRDRDRRRRDDRRDDLLLDDRRDDRDDLDDDLLDDLLLDLDDDLDDRRRRRRRRRDDDDDDRR