#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
typedef pair<long double,long double> pii;// 存点的下标
typedef unsigned long long ll;

const int N = 3010;

string to(int x, int n)
{
    string ans = "";
    while(x)
    {
        int tmp = x % n;
        if(tmp >= 10)
        {
            ans += (char)(tmp - 10 + 'A');
        }
        else ans += (char)(tmp + '0');
        x /= n;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cin >> n;// 表示n进制
    for(int i = 1; i < n ; i ++)
    {
        for(int j = 1; j <= i ; j ++)
        {
            // j * j == j * i
            cout << to(i, n) << "*" << to(j, n) << "=" << to(i * j, n) << " ";
        }
        cout << endl;
    }


    
    return 0;
}