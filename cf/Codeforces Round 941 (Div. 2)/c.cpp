#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 510;
void solve()
{
    int n;
    cin >> n ;
    // priority_queue<pii, vector<pii>, greater<pii>> heap;
    vector<int> w;
    int tmp;
    int ans = 0;
    for(int i = 0 ; i < n ; i ++) cin >> tmp, w.push_back(tmp);
    sort(w.begin(), w.end());//根据倒数第三个样例可知, 要去重
    w.erase(unique(w.begin(), w.end()), w.end());
    tmp = 0;
    // cout << "w.size() = " << w.size() << endl;
    while(w[tmp] - tmp == 1 && w.size() - 1 > tmp)//相等的时候就退出
    {
        tmp ++;//记录tmp++用来判断这是谁的回合, 并且判断当前这个数要减多少, 第一个数减0, 第二个数减1, 第三个数减2
    }
    // tmp--;
    if(tmp % 2 == 0 )
    {
        //如果是1 2 3 4 5
        puts("Alice");
    }
    else puts("Bob");
    // for(int i = 0 ; i < n ; i ++)
    // {
    //     while(w[i + 1] && i < n)//如果在合理范围内而且不为0
    //     {
    //         w[i + 1] -= w[i];
    //         if(!w[i + 1]) i++;//直接看下一个
    //         else break;//如果不为0, 直接看下一个
    //     }
    //     ans ++;
    // }
    // if(ans % 2 == 0)  puts("Alice");
    // else puts("Bob");

    // int ans = 0;
    // int div = 0;
    // while(!heap.empty())
    // {
        
        // bool st = false;
        // tmp = heap.top().first;
        // div += tmp;
        // heap.pop();
        // ans++;//最后mod2得1就是
        // while(!heap.empty())
        // {
        //     pii tmp2 = heap.top();
        //     heap.pop();
        //     if(tmp2.second == 1 && tmp2.first <= tmp)
        //     {
        //         //如果这个是上一个减过的那么减tmp
        //         continue;
        //     }
        //     else if(tmp2.second == 1 && tmp2.first > tmp) 
        //     {
        //         tmp2.first -= tmp;
        //         heap.push({tmp2.first, 1});
        //         break;
        //     }

        //     if(tmp2.first <= div) {
        //         // div += tmp2.first;
        //         continue;
        //     }
        //     else 
        //     {
        //         tmp2.first -= div;
        //         heap.push({tmp2.first, 1});
        //         break;
        //     }
        // }
    // }
    // if(ans % 2 == 1) puts("Alice");
    // else puts("Bob");
}

int main()
{
    int _;
    cin >> _;
    while(_--)
    {
        solve();
    }
}