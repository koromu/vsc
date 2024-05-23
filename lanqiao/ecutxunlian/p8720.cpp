#include <iostream>
#include <set>

using namespace std;
typedef pair<long double,long double> pii;// 存点的下标
typedef unsigned long long ll;
int main()
{
    int n;
    cin >> n;
    set<pii> point;
    long double ta, tb;
    cin >> ta >> tb;
    point.insert({ta, tb});
    ll ans = 2;
    set<pii> now;// 记录这个点和已经存在的点的交点个数
    for(int i = 1; i < n ; i ++)
    {
        long double a2, b2;
        cin >> a2 >> b2;
        now.clear();
        for(auto i : point)
        {
            if(i.first == a2) continue;// 斜率相同就算了
            long double a1 = i.first, b1 = i.second;
            // if((b2 - b1) / (a1 - a2) >= -100000 && (b2 - b1) / (a1 - a2) <= 100000 && (a1 * (b2 - b1) / (a1 - a2) + b1) <= 100000 &&(a1 * (b2 - b1) / (a1 - a2) + b1) >= -100000 )
            now.insert({(b2 - b1) / (a1 - a2) ,a1 * (b2 - b1) / (a1 - a2) + b1 });// 自动去重
        }
        point.insert({a2, b2});
        ans += (now.size() + 1);
    }
    
    // for(set<pii>::iterator i = point.begin() ; i != point.end(); i ++)
    // {// 遍历每一个
    //     set<pii> now;
    //     for(auto j = i; j != point.end() ; j ++)
    //     {
    //         if(i->first == j->first)
    //         {
    //             // 斜率相同的话
    //             continue;
    //         }
    //         else
    //         {
    //             // 斜率不相同的话, 那么计算交点然后存入到一个临时数组中
    //             double a1 = i->first, b1 = i->second;
    //             double a2 = j->first, b2 = i->second;
    //             now.insert({(b2 - b1) / (a1 - a2) ,a1 * (b2 - b1) / (a1 - a2) + b1 });// 自动去重
    //         }
    //     }
    //     if(now.size() != 0)
    //         ans += now.size() + 1;
    // }
    // 所有的点都遍历完了的话
    cout << ans << endl;

    return 0;
}// 50