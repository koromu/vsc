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
	int n; cin >> n;
	for(int i = 1 ; i <= n ; i ++ )
	{
		cout << max((i - 1) * 2, (n - i) * 2) << endl;
	}
    return 0;
}