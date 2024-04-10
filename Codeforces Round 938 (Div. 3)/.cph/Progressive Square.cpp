#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510, M = 1e8 + 10;

int s[N][N];
// 预处理有所的数组
int n, c, d; // 想右+d, 向下+c
// int dx[2] = {1, 0};
// int dy[2] = {0, 1};
int w[N];
int hash1[M];

// void dfs(int i, int j)
// {
//     if((i == n && j == n) || flag)
//     {
//         flag = true;
//         return ;
//     }
//     else
//     {
//         dfs(i+1, j);
//         dfs(i, j+1);
//     }
// }
// void init(int x)
// {
//     memset(s, 0, sizeof s);
//     memset(hash1, 0, sizeof hash1);
//     s[0][0] = w[0];
//     hash1[1] = true;
//     for (int i = 0; i < x; i++)
//     {
//         for (int j = 0; j < x; j++)
//         {
//             if (i + 1 < n)
//             {
//                 s[i + 1][j] = s[i][j] + c;
//             }
//             if (j + 1 < n)
//             {
//                 s[i][j + 1] = s[i][j] + d;
//             }
//             hash1[s[i][j + 1]]++;
//             hash1[s[i + 1][j]] ++;
//         }
//     }
// }

void solve()
{
    memset(w, 0 ,sizeof w);
    // int fist;
    // cin >> n >> c >> d;
    // for (int i = 0; i < n * n; i++)
    //     cin >> w[i];
    // sort(w, w + n * n);
    // init(n);
    // int tmp;
    // for (int i = 0; i < n * n ; i++)
    // {
    //     if (hash1[w[i]]){
    //         hash1[w[i]] --;
    //         continue;
    //     }
    //     else
    //     {
    //         puts("NO");
    //         return;
    //     }
    // }
    // puts("YES");
    // return;
    int tmp = 0;
    cin >> n >> c >> d;
    int dow = 0, rig = 0;
    for (int i = 1; i <= n * n; i++) {
        cin >> w[i];
    }
    sort(w + 1, w + n * n + 1);
    
    for(int i = 2 ; i <= n * n ; i ++)
    {
        if((w[i] - w[1]) % c == 0)
            dow++;
        else if((w[i] - w[1]) % d== 0)
            rig++;
        else {
            puts("NO");
            return ;
        }
    }
    if(dow == n && rig == n)
    puts("YES");

}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}