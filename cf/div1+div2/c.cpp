#include <iostream>
#include <cmath>
#define double long double
using namespace std;

// 计算两点之间的欧几里得距离
double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        double circles[n][2];
        for (int i = 0; i < n; ++i) {
            cin >> circles[i][0] >> circles[i][1];
        }
        
        double xs, ys, xt, yt;
        cin >> xs >> ys >> xt >> yt;
        
        double d_st = distance(xs, ys, xt, yt);  // 起点到终点的距离
        // cout << d_st << "\n";
        bool safe = true;
        
        for (int i = 0; i < n; ++i) {
            double cx = circles[i][0];
            double cy = circles[i][1];
            
            double d_it = distance(cx, cy, xt, yt);  // 圆心到终点的距离
            // cout << "圆心距离 : " << d_it << "\n";
            // 如果圆心到终点的距离小于起点到终点的距离，则路径将与圆相交
            if (d_it <= d_st) {
                safe = false;
                break;
            }
        }
        
        if (safe) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
