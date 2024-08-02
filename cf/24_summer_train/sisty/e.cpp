#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

#include <vector>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 200010;
int w[N];

void solve()
{
    string a; cin >> a;

    int n = a.size();
    a = ' ' + a;
    unordered_map<char, int> ha;// 存每个字母出现的次数

    for(int i = n ; i >= 1 ; i--)
    {
        
    }
    
    return;
}
// vhrywe
// everywhere vrywhr vryhr vrhr vh v
// polycarp poycarp poyarp pyarp pyrp prp pp
// abacabaa acaa c
// t最开始是完全空的, 然后由s构成
// 从最后开始找到开头
// dfs遍历最后的字符串的长度, 如果最后能到达1那么就是有的
// dfs(i, j, k); // 当前的字符串长度, 有k个不同的字母
// 然后从 i-1开始找合法字符串 
// dfs()

// 先取出一个只有一中字符串的子串, 然后往前找, 找到第一个不同的直接跳过, 然后找到
signed main()
{
    int _;cin >> _;
    // string a = "abccbncbcbcccbca";
    // cout << a << endl;
    // remove(a.begin(), a.end(), 'c');
    // cout << a << endl;
    while(_--)
    {
        solve();
    }
    return 0;
}
