#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 200010;
int w[N];
int cyy[N];
vector<pair<pii, int>> v1;


void solve()
{
    int n; cin >> n;
    v1.clear();
    for(int i = 1 ;i <= n ; i ++)
    {
        cin >> w[i];
        cyy[i] = w[i];
    }
    
    // for(int i = 1 ; i <= n ; i ++)
    // {
    //     for(int j = n ; j >= i ; j --)
    //     {
    //         if(w[j] <= i && w[j] < w[i])
    //         {
    //             if(j - i != 0)
    //                 v1.push_back({{i, j}, j - i });
    //             for(int k = j - 1; k >= i ; k --)
    //             {
    //                 swap(w[k], w[k + 1]);
    //             }
    //             break;
    //         }
    //     }
    // }

    // for(int i = 1; i <= n ; i ++) cout << w[i] << " ";
    // cout << endl;
    // // cout << v1.size() << endl;

    // for(int i = 0; i < v1.size() ; i ++)
    // {
    //     cout << v1[i].first.first << " " << v1[i].first.second << " " << v1[i].second << endl;
    // }
    // cout << endl;
    // cout << v1.size() << endl;

// ``````````````````````````````````````````````````
    // 先排好顺序, 然后一个一个比对, 如果不应该在这个位置, 那么就挪到应该在的位置, 从前往后
    sort(cyy + 1, cyy + n + 1);
    for(int i = 1 ; i <= n ; i ++)
    {
        if(cyy[i] != w[i])
        {
            for(int j = i ; j <= n ; j ++)
            {
                if(cyy[i] == w[j])
                {
                    for(int k = j - 1 ; k >= i ; k--)
                    {
                        swap(w[k], w[k + 1]);
                    }
                    v1.push_back({{i, j}, j - i});
                    break;
                }
            }
        }
    }
    // for(int i = 1; i <= n ; i ++) cout << w[i] << " ";
    cout << v1.size() << endl;

    for(int i = 0; i < v1.size() ; i ++)
    {
        cout << v1[i].first.first << " " << v1[i].first.second << " " << v1[i].second << endl;
    }

    return;
}


signed main()
{
    int _;cin >> _;
    while(_--)
    {
        solve();
    }
    return 0;
}
// 44
// 2
// 1 2
// 2
// 2 1
// 3
// 1 2 3
// 3
// 1 3 2
// 3
// 2 1 3
// 3
// 2 3 1
// 3
// 3 1 2
// 3
// 3 2 1
// 4
// 1 2 3 4
// 4
// 1 2 4 3
// 4
// 1 3 2 4
// 4
// 1 3 4 2
// 4
// 1 4 2 3
// 4
// 1 4 3 2
// 4
// 2 1 3 4
// 4
// 2 1 4 3
// 4
// 2 3 1 4
// 4
// 2 3 4 1
// 4
// 2 4 1 3
// 4
// 2 4 3 1
// 4
// 3 1 2 4
// 4
// 3 1 4 2
// 4
// 3 2 1 4
// 4
// 3 2 4 1
// 4
// 3 4 1 2
// 4
// 3 4 2 1
// 4
// 4 1 2 3
// 4
// 4 1 3 2
// 4
// 4 2 1 3
// 4
// 4 2 3 1
// 4
// 4 3 1 2
// 4
// 4 3 2 1
// 3
// 1 5 2
// 2
// 1 1
// 3
// 1 1 1
// 3
// 2 2 2
// 3
// 3 2 1
// 5
// 2 6 4 4 2
// 4
// 4 1 5 5
// 4
// 3 1 3 1
// 4
// 5 3 4 4
// 6
// 3 2 1 3 1 1
// 5
// 5 1 5 1 2
// 6
// 1 1 1 1 1 