#include <iostream>

using namespace std;

int main()
{
    int n;cin >> n;
    double ans;
    for(int i = 0 ; i < n ;  i ++)
    {
        double a;  double b;
        cin >> a >> b;
        if(a >= 10000000)
        {
            ans = b + 2.0;
        }
        else if(a <=  9800000)
        {
            ans = b + (a - 9500000) / 300000.0;
        }
        else
            ans = b + 1.0 + (a - 9800000) / 200000.0;

        if(ans > 0)printf("%.8lf\n", ans);
        else printf("%.8lf\n", 0.0);
    }

    return 0;
}