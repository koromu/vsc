#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <unordered_map>
#include <vector>

#define int long long
using namespace std;
const int N = 210, P = 998244353;
int w[N];
int pre[N];

void solve()
{
    int n; cin >> n;
    for(int i = 1 ; i <= n ; i ++) {
        cin >> w[i];
        pre[i] = pre[i - 1] + w[i];
    }

    // int sum = 1;    
    // int pos = n;
    // int c = 1;
    // for(int i = n ; i >= 1 ; i --)
    // {
    //     if(w[i] >= w[i - 1]) continue;
    //     else 
    //     {
    //         // 说明下一个就是新的一个串
    //         sum = (pre[pos] - pre[i - 1]);
    //         int mid = (pre[pos] - pre[i - 1]) / (pos - i + 1);

    //         for(int k = 1 ; k <= sum % (pos - i + 1) ; k ++)
    //         {
    //             c = (c * (mid + 1) ) % P;
    //         }
    //         c = (c * (pos - i + 1) * mid % P) % P;
    //         pos = i - 1;
    //     }
    // }

    // if(pos != 1){
    //     sum = (pre[pos] - pre[1]);
    //     int mid = (pre[pos] - pre[1]) / pos;

    //     for(int k = 1 ; k <= sum % (pos) ; k ++)
    //     {
    //         c = (c * (mid + 1) ) % P;
    //     }
    //     c = (c * (pos) * mid % P) % P;
    // }


    // int c = 1;
    // int mid = pre[n] / n;
    // // cout << mid << "\n";
    // for(int i = n ; i >= 1 ; i --)
    // {
    //     // cout << w[i] << " " << mid << "\n";
    //     if(w[i] > mid)
    //     {
    //         mid = pre[i] / i;
    //         // cout << mid << "\n";
    //         int sum = 0;
    //         for(int j = 1 ; j <= i ; j ++)
    //         {
    //             // cout << "w[j] : " <<  w[j] << " mid : " << mid << "\n";
    //             sum = (sum + (w[j] - mid) ) % P;
    //         }
    //         // cout << "sum : " << sum << "\n";
    //         for(int k = 1 ; k <= sum ; k ++)
    //         {
    //             c = (c * (mid + 1) ) % P;
    //         }
    //         for(int k = 1 ; k <= i - sum ; k ++)
    //         {
    //             c = (c * mid) % P;
    //         }
    //         // cout << sum << "\n";
    //         cout << c % P << "\n";
    //         return;
    //     }
    //     else c = (c * w[i] % P);

    //     // cout << "qianzhuihe : " << pre[i] << endl;
    //     mid = pre[i] / i;
    //     // cout << mid << "\n";
    // }
    // cout << c % P << "\n";
	if(n == 1) {
		cout << w[1] % P << "\n";
		return;
	}
	for(int l = 1 ; l <= 400 ; l ++){
		for(int i = 2 ; i <= n ; i ++)
		{
			while(w[i - 1] < w[i])
			{
				w[i]--;
				w[i - 1]++;
			}
		}
	}

	int ans = 1;
	for(int i = 1 ; i <= n ; i ++)
	{
		ans = (ans * w[i]) % P;
		// cout << w[i] << " ";
	}
	// cout << "\n";
	cout << ans % P << endl;
    return ;
}


signed main()
{
    int _ = 1; 
    cin >> _;
    while(_--) 
        solve();
    return 0;
}
