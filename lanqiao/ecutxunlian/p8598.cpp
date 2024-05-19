#include <iostream>

using namespace std;

const int N = 100010;

int ha[N];

int main()
{
    int n;
    cin >> n;


    int ans1, ans2;
    int tmp, maxv = -1;
    int minv = 1e9;
    while(cin >> tmp)
    {
        if(ha[tmp]) ans2 = tmp;// 只会出现一个重复的数字
        ha[tmp]++;
        minv = min(minv, tmp);
        maxv = max(maxv, tmp);
    }

    for(int i = minv ; i <= maxv ; i ++)
    {
        if(!ha[i]) ans1 = i;
    }

    cout << ans1 << " " << ans2 << endl;

    return 0;
}