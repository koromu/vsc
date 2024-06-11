#include <iostream>
#include <cstring>
using namespace std;

const int N = 25;

int x, y;
int ans;
string s[N];
int g[N][N];
int used[N];// 记录每个点使用次数
int n; 

void dfs(string last , int u)// 现在这个字符串, 和已经加上的点的编号
{
    // cout << last << endl;
    ans = max(ans, (int)last.size());// 答案就是
    // 遍历这个字符串的所有能接在后面的
    for(int i = 1 ; i <= n ; i ++)
    {
        if(used[i] >= 2) continue;
        if(g[u][i] == 0 || g[u][i] == 0x3f3f3f3f) continue;

        used[i]++;
        dfs(last + s[i].substr(g[u][i]) ,i);// 已经把这个字符串传过去了, 所以可以再下一层更新答案
        used[i]--;// 使用次数要恢复
        
    }
}

int main()
{
    // 问的是能拼成的单词得最长的长度, 某个字母开头, 然后每个单词只能使用两边, 所以需要一个数组记录这个单词使用了多少遍
    // 单词是20个, 所以首先考虑一下暴力, 先更具开头可能是什么单词, 然后搜索, 单词得话, 重合部分越短越好
    cin >> n;
    for(int i = 1 ; i <= n ; i ++) cin >> s[i];
    string a; cin >> a;
    memset(g, 0x3f, sizeof g);
    for(int i = 1 ; i <= n ; i ++)
    {
        for(int j = 1 ; j <= n ; j ++)
        {
            string a = s[i], b = s[j];
            for(int k = 1 ; k < min((int)a.size(),(int)b.size()) ; k ++)
            {
                if(a.substr((int)a.size() - k) == b.substr(0, k))// a放前面, b在后面, 看a后面和b前面最少多少个重合
                {
                    g[i][j] = k;// 存的是重复的字符长度
                    break;// 匹配到的第一个就是最小的
                }
            }
        }
    }// 先处理出来所有组合的可能性, 标记一下两者之间的关系, 一个二维数组
    ans = 0;
    for(int i = 1 ; i <= n ; i ++)
    {
        if(s[i][0] == a[0])
        {
            used[i] = 1;
            dfs(s[i], i);// 搜索一遍, 以1开头的段落
        }
    }
    cout << ans << endl;

    return 0;
}