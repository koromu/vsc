#include <iostream>

using namespace std;

const int N = 300010, M = 110;
int f[N][M];
int a[N];


int main()
{
    int n; cin >> n;
    for(int i  = 1 ; i <= n ; i ++) cin >> a[i];

    // for(int i=1;i<=n;i++)f[i][a[i]]=1;
    for(int i = 2 ; i <= n ; i ++)
    {
        for(int j = 1 ; j <= 108 ; j ++)
        {
            f[i][j] += f[i-1][j];
            if(a[i] < j) f[i][j] += f[i-1][j];
            else if(a[i] > j) f[i][j] += 0;
            else
            {
                for(int k = 1 ; k <= j ; k ++) f[i][j] += f[i-1][k];
            }
        }
    }
    int sum = 0;
    for(int i=1;i<=108;i++)sum+=f[n][i]*i;
    cout<<sum<<endl;
    for(int i = 1 ; i <= n ; i ++) 
    {
        for(int j=1;j<=8;j++)
        {
            cout<<f[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
