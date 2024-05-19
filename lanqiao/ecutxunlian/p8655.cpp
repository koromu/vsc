#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
const int N = 100010, M = 2 * N;

// N条无向边
// 是一个图
int n;
vector<int> e[N];// 一个拉链
unordered_map<int, int> ha;
// void add(int a, int b)
// {
//     e[idx] = b, ne[idx] = h[a], h[a] = idx++;
// }
vector<int> ans;// 记录一下环
bool flag;
int obj = 0;
void dfs(int u, int fa)
{
    for(int i = 0 ; i < e[u].size() ; i ++)
    {
        int j = e[u][i];
        // 取出这个子节点
        if(j == fa) continue;// 如果是父节点就跳过
        // cout << "j :" << j << endl;
        // 判断一下这个点的入度是多少, 如果是2的话, 说明已经找到一个环了
        if(ha[j] == 1) {// 如果已经存在了的hau, 就加入答案一下
            ans.push_back(j);
            flag = true;// 已经找到环了, 原路返回一路记录答案
            obj = j;
            // cout << "obj : " <<  obj << endl;
            return ;
        }
        ha[j]++;// 给子节点的入度加1
        dfs(j, u);
        if(flag)
        {
            // 如果找到了环就不用继续看下一个节点了, 直接原路返回
            // 如果这个点和上次找到环的点的尾巴相同, 说明和这个是头
            ans.push_back(j);
            if(obj == j)
            {
                sort(ans.begin(), ans.end());
                ans.erase(unique(ans.begin(), ans.end()), ans.end());
                for(auto i : ans) cout << i << " ";
                exit(0);
            }
            return;
        }
    }
}

int main()
{
    cin >> n;
    // 特判只有一个点的情况
    if(n == 1) 
    {
        int a, b;
        cin >> a >> b;
        cout << a << endl;
        return 0;
    }

    for(int i = 0 ; i < n ; i ++)
    {
        int a, b;
        cin >> a >> b;
        // add(a, b), add(b, a);
        e[a].push_back(b);
        e[b].push_back(a);
    }// 无向边建好图了

    // 直接遍历一遍图, 然后去过两次的点就存一下, 然后输出就行
    // ha[1] ++;
    dfs(1, -1);
    ans.push_back(1); 
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for(auto i : ans) cout << i << " ";
    return 0;
    
}

// 80