// 你有n个画, 和a种颜色, 但是只有b个特别喜欢的颜色
// 现在yura需要给这些画涂色, 每个画一个颜色, 在完成n个画之后, 确保包含这b个颜色
// 有多少种涂色的可能
//n个位置, 有b个喜欢的颜色, 每个位置有a种填色的方式, b种颜色一定要用上
//所以有b个位置先确定了, 然后n - b个位置随便填, a ^ (n - b), 然后c(n, b)
#include <iostream>

using namespace std;
typedef long long ll;

const int N = 100010;

int C[10010][10010];
int P = 1e9 + 7;

int qmi(int x, int y)
{
    int ans = 1;
    while(y)
    {
        if(y & 1) ans = (ans * x) % P;
        x = (x * x) % P;
        y >>= 1;
    }
    return ans % P;
}    

void init(int x)
{
    for(int m = 1 ; m <= x ; m ++) 
        C[m][0] = C[m][m] = 1;
    
    for(int i = 1 ; i <= x ; i ++)
    {
        for(int j = 1 ; j < i ; j ++)
        {//c42 = c31 + c32
            C[i][j] = C[i-1][j-1] + C[i - 1][j] % P;
        }
    }//c[i][j] = c[i-1][j-1] + c[i-1][j];
    return;
}

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    init(n);
    int ans = 0;
    for(int y = b ; y <= n ; y ++)
    {
        ans += C[n][y] * qmi(a-b, n - y) % P;
    }
    cout << ans  << endl;    
    return 0;
}