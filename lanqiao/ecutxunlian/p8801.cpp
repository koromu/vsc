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
typedef pair<int, int> pii;

const int N = 70;
vector<pii> v1;
vector<int> v2;

int dfs(int u, int op)// 已经填好了u位, 下一位使用什么操作
{
    if(u == v1.size())
    {
        // 如果等于这个长度的话, 说明已经到最后一位了
        
    }
}

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    int tmp = n;
    while (n)
    {
        int x = n % 10;
        v1.push_back({9 - x, x + 1}); // 需要加的数, 和减的数
        // cout << v1[v1.size() - 1].first << " " << v1[v1.size() - 1].second << endl;
        n /= 10;
        // cout << x << " ";
    }
    cout << max(dfs(0, 0), dfs(0, 1));// 填好了多少位, 下一位使用什么操作 
}

signed main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int tmp = n;
    while (n)
    {
        int x = n % 10;
        v1.push_back({9 - x, x + 1}); // 需要加的数, 和减的数
        // cout << v1[v1.size() - 1].first << " " << v1[v1.size() - 1].second << endl;
        n /= 10;
        // cout << x << " ";
    }
    // cout << endl;
    // 正序遍历数组是从地位开始的, 我们需要从高位开始
    reverse(v1.begin(), v1.end());
    // memcpy(&v2, &v1, sizeof(v1));//把v1复制到v2中
    for (int i = 0; i < v1.size(); i++)
    {
        // cout << "要加的 : " << v1[i].first << " 要减的 : " << v1[i].second << " " <<  a << " " << b
        cout << endl;
        if (v1[i].first == 0)
        {
            v2.push_back(9);
            // cout << "要加的 : " << v1[i].first << " 要减的 : " << v1[i].second << " " <<  a << " " << b
            cout << endl;
            continue;
        }
        if (v1[i].second <= b && b)
        {
            b -= v1[i].second;
            v2.push_back(9);
            // cout << "要加的 : " << v1[i].first << " 要减的 : " << v1[i].second << " " <<  a << " " << b
            cout << endl;
            continue;
        }
        else if (v1[i].second > b && a)
        {
            if (v1[i].first <= a)
            {
                a -= v1[i].first;
                v2.push_back(9);
                // cout << "要加的 : " << v1[i].first << " 要减的 : " << v1[i].second << " " <<  a << " " << b
                cout << endl;
                continue;
            }
            else
            {
                v2.push_back(v1[i].second - 1 + a);
                a = 0;
                // cout << "要加的 : " << v1[i].first << " 要减的 : " << v1[i].second << " " <<  a << " " << b
                cout << endl;
                continue;
            }
        }
        // cout << "要加的 : " << v1[i].first << " 要减的 : " << v1[i].second << " " <<  a << " " << b
        cout << endl;
        v2.push_back(v1[i].second - 1);
    }
    
    // cout << "要加的 : " <<  v1[i].first << " 要减的 : " << v1[i].second << " ";
    cout << endl;
    for (auto i : v2)
        cout << i;
    cout << endl;
    return 0;
}// 90
