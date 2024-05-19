#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
const int N = 100010;
vector<pii> v1;
int n, k;
bool check(int x)
{
    int c1 = 0;
    for(int i = 0 ; i < n ; i ++)
    {
        int h = v1[i].first, w = v1[i].second;
        c1 += (h / x) * (w / x) ;
    }
    if(c1 >= k)
        return true;
    return false;
}

int main()
{
    cin >> n >> k;
    for(int i = 0 ; i < n ; i ++)
    {
        int h, w;
        cin >> h >> w;
        v1.push_back({h, w});
    }

    int l = 1, r = N;
    while(l < r)
    {
        int mid = l + r + 1 >> 1;
        if(check(mid))
            // 如果是真说明这个mid是合法的, 可以变大
            l = mid;
        else
            r = mid - 1;
    }
    cout << r << endl;

    return 0;
}

