#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 200010;

int tmp1[10] = {0, 9, 90, 900, 9000, 90000, 900000, 9000000, 90000000, 900000000};
int tmp2[10] = {0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
vector<int> v1;

int w[N];

int st[N];
int primes[N], cnt;

void init()
{
    for(int i = 2; i <= 1e9 ; i++)
    {
        //先存入数组, 再更新    
        if(!st[i]) primes[cnt++] = i;//存入一个质数
        for(int j = 0; primes[j] <= 1e9 / i ; j++)//遍历质数数组
        {
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

void solve()
{
    int flag = false;
    int a, b, c; cin >> a >> b >> c;
    // if(a < b) {
    //     swap(a, b);
    //     flag = true;
    // }
    // 所以a大于b的长度
    // 二分枚举c的大小
    // int l = 0, r = tmp1[c];
    // while(l < r)
    // {
    //     int mid = l + r >> 1;
    //     // to_string(tmp2[b] * primes[mid]).size() == a
    //     if(to_string(primes[mid]).size() == c)
    //     {
    //         if(to_string(tmp2[b] * primes[mid]).size() == a)
    //         {
    //             if(flag)
    //             {
    //                 cout << tmp2[b] << " " << tmp2[b] * primes[mid];
    //                 return ;
    //             }
    //             else {
    //                 cout << tmp2[b] * primes[mid] << " " << tmp2[b];
    //                 return;
    //             }
    //         }
    //         else if(to_string(tmp2[b] * primes[mid]).size() > a)
    //         {
    //             r = mid;
    //         }
    //         else l = mid + 1;
    //     }
    //     else if(to_string(primes[mid]).size() < c)
    //     {
    //         l = mid + 1;
    //     }
    //     else r = mid;
    // }
    if(a < b)
    {
        for(int i = 1, f1 = 9 ; i <= a ; i ++)
        {
            if(i == a - c + 1)
            {
                cout << 1;
                f1 = 0;
            }
            else cout << f1;
        }
        cout << " ";
        cout << 9 ;
        for(int i = 2, f1 = 9 ; i <= b ; i ++)
        {
            cout << 0;
        }
    }
    else
    {
        cout << 9 ;
        for(int i = 2, f1 = 9 ; i <= a ; i ++)
        {
            cout << 0;
        }
        cout << " ";
        for(int i = 1, f1 = 9 ; i <= b ; i ++)
        {
            if(i == b - c + 1)
            {
                cout << 1;
                f1 = 0;
            }
            else cout << f1;
        }
    }
    cout << endl;
    // cout << __gcd(999100, 900000000) << endl;
}

signed main()
{
    // init();
    int _;cin >> _;
    while(_--)
    {
        solve();
    }
    return 0;
}
