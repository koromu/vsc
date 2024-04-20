#include <iostream>

using namespace std;
const int N = 1010;
int w[N];
int n, m;
int  main()
{
    cin >> n >> m;
    int ans = 0;
    for(int i = 0 ; i < m ; i ++)
    {
        int tmp;
        cin >> tmp;
        ans += tmp;
    }
    if(ans == n * m) cout << n << endl;//加起来是和全部人加起来相同
    else if(ans < n) 
    {
        //会的人都加起来还没有总人数多, 最少0个人
        cout << 0 <<endl;
    }
    else
    {
        cout << ans - ans / n * n << endl;
    }

    return 0;
}
