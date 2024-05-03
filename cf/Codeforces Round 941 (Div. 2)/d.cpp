#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 510;

void solve()
{
    //读入一个n 和 一个k
    //要构造一个数组, 数组中的和不能包括k, 但是需要包括(1 ~ k - 1) 和  (k + 1 ~ n)
    //突然可以想到二进制表达1 ~ k - 1 和 k + 1 ~ n
    //但是怎么才能不表示k呢?
    //而且是存在, 可以多, 不能少, 只要不表达k
    vector<int> v;
    int n, k;cin >> n >> k;
    int m = k;
    // int ha[200010] = {0};
    for(int i = 0 ; m > pow(2, i);i ++ )
    {
        v.push_back(pow(2, i));
        m -= pow(2, i);
        // ha[(int)pow(2, i)] = 1;
    }
    if(m > 1)
    {
        v.push_back(m - 1);
    }
    // for(int i = 0 ; i < v.size();i ++ )
    //     cout << "v[" << i << "] = " <<  v[i] << " ";
    // cout << endl;
    
    // 已经把1 ~ k - 1的表示出来了
    //然后表示k + 1 ~ n;
    //按道理是一样的表达方式
    //(...) k 2k 4k 8k//因为前面的(...)可以表示1 ~ k - 1, 所以k + 1 ~ 2k - 1可以和k进行表示
    //随后2k - 1 和 2k可以表示 4k - 1
    //但是不能表示k, 所以右移一位
    //(...) k + 1, 2k + 1, 4k + 1, 前面的数一起, 加上一个k + 1可以表示k + 2 ~ 2k(k - 1 + k + 1)
    int size = v.size();
    int i;
    v.push_back(k + 1);//反正都是大于k的, 根据题目发现有些特殊数数据过不去
    v.push_back(2*k+1);
    v.push_back(3*k+1);
    for(i = 2 ; pow(2, i) * k + 1 <= n ;i ++ )
    {
        //前面已经有v.size()个了, 所以直接再加25 - v.size(), 就不管n了
        v.push_back(pow(2, i) * k + 1);
    }
    // if(pow(2, i) * k > n)
    // {
    if(n != k)
        v.push_back(n);
    // }
    cout << v.size() <<endl;
    for(auto i : v) cout << i << " "; 
    cout << endl;
    return;
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