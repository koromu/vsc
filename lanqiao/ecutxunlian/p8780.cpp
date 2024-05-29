#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#define int long long

using namespace std;
typedef pair<int, int > pii;

const int N = 100010;

int w[N];
signed main()
{
    int a, b, n;
    cin >> a >> b >>n;
    int week = a * 5 + b * 2;
    int ww = 0;
    if(n / week)
    {
        ww = n / week;
    }
    n %= week;
    int dd = 0;
    if(n)
    {
        for(int i = 1; i <= 5 ; i ++)
        {
            n -= a;
            dd++;
            if(n <= 0) break;
        }
    }
    if(n)
    {
        for(int i = 1; i <= 2 ; i ++)
        {
            n -= b;
            dd++;
            if(n <= 0) break;
        }
    }
    cout << ww * 7 + dd << endl;
    return 0;
}