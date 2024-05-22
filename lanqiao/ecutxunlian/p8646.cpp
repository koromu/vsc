#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int N = 110, M = 100010;

vector<int> p1;// 存已经处理过的数字 

int w[N];
int st[M];// 在一个很大的数之前找到一段连续长度最小是数组中最小元素的段


int main()
{
    int n;
    cin >> n;
    bool f1 = false, f2 = false;
    int tmp = 0;
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> w[i];
        tmp = __gcd(w[i], tmp);
    }
    sort(w, w + n);
    if(tmp > 1)
    {
        puts("INF");
        return 0;
    }// 先把不可能的情况给排除掉

    // 还是用一个筛子把100010中能组合到的数遍历一遍
    for(int i = 0 ; i < n ; i ++)
    {
        st[w[i]] = true;// 这个数本身一定是能到达的
        // 遍历一个数
        // 如果一个数x可以遍历得到, 那么x + w[i]一定可以遍历得到
        // 那么x + w[i] + w[i]一定可以遍历得到, 一直到100010为止
        for(int j = 1 ; j < M ; j ++)
            if(st[j] && j + w[i] < M)// 如果可以到达, 那么就更新下一个点
            {
                // 然后用w[i]把所有能到的值更新一遍
                st[j + w[i]] = true;
            }
        // 如果没有到过
    }

    ll ans = 0;

    for(int i = 1 ; i < M ; i ++)   
    {
        if(!st[i]){
            ans ++;
            // cout << "i : " << i << endl;
        }
    }
    cout << ans << endl;

    return 0;
}

