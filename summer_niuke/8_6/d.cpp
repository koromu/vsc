#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int P = 1e9 + 7; 
const int N = 200010;

int w[N];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    
    unordered_map<int, int> freq;
    int left = 1;  // 窗口左端
    int c1 = 0, c2 = 0; // 符合条件的区间数量

    // 从左到右扫描
    for (int right = 1; right <= n; ++right) { // 枚举右端点
        freq[w[right]]++; // 加上一个数, 只要加上的这个数不超过k就行
        while (freq[w[right]] > k) { // 如果超过了, 那么就移动左端点了哦
            freq[w[left]]--;
            if (freq[w[left]] == 0) {
                freq.erase(w[left]);
            }
            left++; // 出现次数减1
        }

        // 找当前窗口的最大值和最小值
        int maxv = 0, minv = P;
        for (const auto &i : freq) {
            maxv = max(maxv, i.second);
            minv = min(minv, i.second);
            cout << i.first << " " << i.second << "\n";
        }
        cout << "\n";
        
        if (maxv == k && minv == k) {
            c1++;
            for(int i = left ; i <= right; i++) cout << w[i] << " ";
            cout << "\n";
        }
    }

    freq.clear();
    left = n;
    // 从右到左扫描
    int right;
    for (right = n; right >= 1; --right) { // 枚举右端点
        freq[w[left]]++; // 加上一个数, 只要加上的这个数不超过k就行
        while (freq[w[left]] > k) { // 如果超过了, 那么就移动左端点了哦
            freq[w[left]]--;
            if (freq[w[left]] == 0) {
                freq.erase(w[left]);
            }
            left--; // 出现次数减1
        }
        // 找当前窗口的最大值和最小值
        int maxv = 0, minv = P;
        for (const auto &i : freq) {
            maxv = max(maxv, i.second);
            minv = min(minv, i.second);
        }

        if (maxv == k && minv == k) {
            for(int i = right ; i <= left; i++) cout << w[i] << " ";
            cout << "\n";
            c2++;
        }
    }
    // 最后还有一个扫尾操作, 如果队列不为空, 那么移动尾巴
    while(right <= left)
    {
        
    }

    cout << max(c1, c2) << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
