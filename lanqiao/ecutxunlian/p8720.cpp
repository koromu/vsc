#include <iostream>
#include <set>

using namespace std;
typedef pair<double,double> pii;// 存点的下标
typedef unsigned long long ll;
int main()
{
    int n;
    cin >> n;
    set<pii> point;
    // double ta, tb;
    // cin >> ta >> tb;
    // point.insert({ta, tb});
    ll ans = 1;
    for(int i = 0; i < n ; i ++)
    {
        double a2, b2;
        cin >> a2 >> b2;
        if(point.find({a2, b2}) != point.end() && point.size() != 0) continue;
        set<pii> now;// 记录这个点和已经存在的点的交点个数
        // now.clear();
        for(auto i = point.begin() ; i!= point.end() ; i ++)
        {
            if(i->first == a2) continue;// 斜率相同就算了
            double a1 = i->first, b1 = i->second;
            now.insert({(b2 - b1) / (a1 - a2) ,a2 * (b2 - b1) / (a1 - a2) + b2 });// 自动去重
        }
        point.insert({a2, b2});
        ans += (now.size() + 1);
    }

    cout << ans << endl;

    return 0;
}// 50