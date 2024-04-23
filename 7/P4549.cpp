#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
const int N = 25;
int n;
// bool check(int x)
// {
//     int s = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         s += x * w[i];
//     }
//     if (s > 0)
//         return false;
//     else
//         return true;
// }

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
vector<int> w;
int main()
{
    cin >> n;
    int tmp;
    for (int i = 1; i <= n; i++)
        cin >> tmp, w.push_back(tmp);

    int ans = 0;
    ans = abs(w[0]);
    for (int i = 1; i < w.size(); i ++)
    {
        ans = gcd(ans,abs(w[i]));
    }
    std::cout << ans << endl;
    return 0;
}