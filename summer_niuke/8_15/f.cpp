#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1010;
int st[N][N];  // 用于记录点是否已经被加入
int row[N], col[N], main_diag[2 * N], anti_diag[2 * N]; // 用于记录直线的使用次数
int n;

void solve() {
    cin >> n;
    int x, y;
    string result;

    // 初始化
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(main_diag, 0, sizeof(main_diag));
    memset(anti_diag, 0, sizeof(anti_diag));

    for(int i = 1; i <= n * n; i++) {
        cin >> x >> y;
        // 检查当前点是否可以加入集合
        if (row[x] < 2 && col[y] < 2 && main_diag[x - y + n] < 2 && anti_diag[x + y] < 2) {
            result += '1';
            row[x]++;
            col[y]++;
            main_diag[x - y + n]++;
            anti_diag[x + y]++;
        } else {
            result += '0';
        }
    }

    cout << result << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
