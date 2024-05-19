#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;

int a[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i ++) cin >> a[i];

    int ans = 0;
    for(int i = 1 ; i <= n ; i ++)
    {
        if(a[i] != i)
        {
            swap(a[i], a[a[i]]);// 把这个值放到和坐标相同的地方
            i = 1;
            ans ++;
            // for(int j = 1; j <= n ; j ++) cout << a[j] << " ";
            // cout << endl;;
        }
    }
    cout << ans << endl;
}