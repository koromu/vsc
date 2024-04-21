#include <iostream>

using namespace std;

void solve()
{
    double p, g, b, m;
    cin >> p >> g >> b >> m;

    double con = p + g + b + m; 
    if(!con){
        printf("%.2lf\n", 0.0);
        return ;   
    }
    double ans = 0;
    ans += (p / con);
    ans += ((g / con) * 0.650);
    ans *= 100;
//     cout << ans << endl;
    printf("%.2lf\n", ans);
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
    return 0;
}