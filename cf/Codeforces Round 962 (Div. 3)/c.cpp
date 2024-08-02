#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <math.h>
#include <vector>

#define int long long
using namespace std;
const int N = 2e5 + 10;

int w[N];
int pre[N];
void solve()
{
    int n, q; cin >> n >> q;
    string a, b; cin >> a >> b;
    a = ' ' + a;
    b = ' ' + b;
    unordered_map<char, int> mp1, mp2;
    for(int i = n ; i >= 1 ; i --)
    {
        mp1[a[i]] ++;
        mp2[b[i]] ++;
    }
    for(int i = n ; i >= 1 ; i --)
    {
        int c = 0;
        for(int j = 0 ; j <= 25 ; j ++)
        {
            // cout << (char)(j + 'a') << " " << mp1[j + 'a'] << " " << mp2[j + 'a'] << endl;
            if(mp1[j + 'a'] != mp2[j + 'a'])
            {
                c += (abs(mp1[j + 'a'] - mp2[j + 'a']));// 前面这段里面不相同的个数
            }
        }
        // 统计一个子串中的每个字母出现的次数, 所以要处理出每个字母的前缀和数组
        pre[i] = c;
        mp1[a[i]]--;
        mp2[b[i]]--;
        // cout << c << endl;
    }
    // cout << endl;
    for(int i = 1 ; i <= n ; i ++) cout << pre[i] / 2 << " ";
    cout << endl;
    while(q--)
    {
        int l, r; cin >> l >> r;
        cout <<  abs(pre[r] - pre[l - 1]) / 2 << endl;
    }
    cout << endl;
    return ;
}


signed main()
{
    int _ = 1; 
    cin >> _;
    while(_--) solve();
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <unordered_map>
// using namespace std;

// void solve() {
//     int n, q;
//     cin >> n >> q;
//     string a, b;
//     cin >> a >> b;

//     // 构造字符频率前缀和
//     vector<vector<int>> preA(n + 1, vector<int>(26, 0));
//     vector<vector<int>> preB(n + 1, vector<int>(26, 0));

//     for (int i = 1; i <= n; ++i) {
//         for (int j = 0; j < 26; ++j) {
//             preA[i][j] = preA[i - 1][j];
//             preB[i][j] = preB[i - 1][j];
//         }
//         preA[i][a[i - 1] - 'a']++;
//         preB[i][b[i - 1] - 'a']++;
//     }



//     while (q--) {
//         int l, r;
//         cin >> l >> r;
//         l--; // 转换为0索引
//         r--;

//         // 计算子字符串的字符频率
//         vector<int> countA(26, 0), countB(26, 0);
//         for (int j = 0; j < 26; ++j) {
//             countA[j] = preA[r + 1][j] - preA[l][j];
//             countB[j] = preB[r + 1][j] - preB[l][j];
//         }

//         // 计算字符频率差异的绝对值
//         int op = 0;
//         for (int j = 0; j < 26; ++j) {
//             op += abs(countA[j] - countB[j]);
//         }

//         cout << op / 2 << endl;
//     }
//     // cout << endl;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while (t--) {
//         solve();
//     }

//     return 0;
// }


// 11
// 11
// 11
// 11
// 11
// 11
// 11
// 11
// 11
// 11

// 11
// 22
// 22
// 22
// 33
// 11
// 33

// 55

// 22
// 11
// 11
// 22
// 12
// 01

// 1
// 1
// 1

// 8
// 5
// 1
// 1
// 1
// 1
// 1

// 1
// 1
// 1
// 1

// 4
// 2
// 2
// 3
// 1
// 2
// 1
// 2
// 2

