#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>

const int N = 100010;
using namespace std;
typedef long long ll;
// 要求出一个区间差距最小的数组
// 首先在两个数组中找到距离最相近的值, 因为一个是左端点, 一个是右端点, 所以可以给左端点在另一个数组中找一个右端点
// 使用二分找到第一个大于这个值的值
// 这里可以使用lower_bound(x) 和 upper_bound(x)
// 其中一个求的是数组中第一个大于等于x的值, 一个是找到第一个大于x的值, 没有的话就找到end()
// 所以这里是用的是第二个


// 所以区间长度要用multiset
void solve()
{
    // 我们在找到一个区间后, 需要直接去掉这两个数, 然后存到一个新数组中, 这个数组也需要排序
    int n, tmp;cin >> n;
    set<int> s1, s2;// 左右坐标不不会相同, 但是区间长度可能会相同
    multiset<ll> s;// 而且区间大小也是可以重复的东西, 需要注意
    int ans[N];
    for(int i= 0 ; i < n ; i ++)
    {
        cin >> tmp;
        s1.insert(tmp);
    }
    for(int i = 0; i < n ; i ++)
    {
        cin >> tmp;
        s2.insert(tmp);
    }

    for(int i = 1 ; i <= n ; i ++) cin >> ans[i];
    sort(ans + 1, ans + n + 1);
    // while(!s1.empty())
    // {
    //     int x1 = *s2.begin();
    //     s2.erase(s2.begin());
    //     auto it1 = s1.lower_bound(x1);it1--;
    //     int x2 = *it1;
    //     // cout << x2 << " " ;
    //     s1.erase(it1);
    //     s.insert(x1 - x2);// 经过计算是不用+1的
    // }// lower版本

    while(!s1.empty())
    {
        auto it2 = s1.end();
        it2--;
        int x1 = *it2;
        s1.erase(it2);
        // 从小到大的便利左坐标得到的答案是错误的, 必须从大到小的便利左坐标, 或者从小到大的遍历右坐标
        auto it1 = s2.upper_bound(x1);
        if(it1 == s2.end()) it1--;
        int x2 = *it1;
        // cout << x2 << " " ;
        s2.erase(it1);
        s.insert(x2 - x1);// 经过计算是不用+1的
    }
    

    // for(auto i : s) cout << i << " ";
    // cout << endl;
    // 然后就是可以最小的区间长度, 权值直接用最大的
    ll res = 0;
    int j = n;
    for(auto i = s.begin() ; i != s.end() ; i ++, j --)
        res += (*i * ans[j]);
    cout << res << endl;
}

int main()
{
    int _;
    cin >> _;
    while(_--)
    {
        solve();
    }

    return 0;
}


// #define N 10
// using namespace std;

// multiset<int>tl;
// int a[N]={},c[N]={},l[N]={},r[N]={},n=0,t=0;
// int main(){
//     scanf("%d",&t);
//     while(t--){
//         scanf("%d",&n);
//         tl.clear();
//         for(int i=1;i<=n;i++){
//             scanf("%d",&l[i]);
//             tl.insert(l[i]);
//         }
//         for(int i=1;i<=n;i++){
//             scanf("%d",&r[i]);
//         }
//         for(int i=1;i<=n;i++){
//             scanf("%d",&c[i]);
//         }
//         sort(r+1,r+1+n);
//         for(int i=1;i<=n;i++){
//             auto id=tl.lower_bound(r[i]);
//             id--;
//             a[i]=r[i]-(*id);
//             tl.erase(id);
//         }
//         sort(a+1,a+1+n);
//         sort(c+1,c+1+n);
//         long long ans=0;
//         for(int i=1;i<=n;i++){
//             ans+=a[i]*1LL*c[n-i+1];
//         }
//         printf("%lld\n",ans);
//     }
//     return 0;
// }