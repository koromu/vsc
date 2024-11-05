#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,a,b;
string s;
int tot[100001][21];
int net[100001][21];
int t[2];

void solve(){
    cin>>n>>a>>b>>s;
    int r = 0;
    for(int i = 0;i<n;i++){
        while(t[0] < a && t[1] < a){
            t[s[r] - '0']++;
            r = (r+1)%n;
        }
        net[i][0] = r;
        tot[i][0] = t[1] > t[0];
        t[s[i]-'0']--;
    }
    for(int j = 1;j<=20;j++)
        for(int i = 0;i<n;i++)
            tot[i][j] += tot[i][j-1]+tot[net[i][j-1]][j-1],
            net[i][j] = net[net[i][j-1]][j-1];
   for(int i = 1;i<n;i++,cout<<endl){
       for(int j = 0;j<=20;j++)
           cout<<tot[i][j]<<" ";
   }
    for(int i = 0;i<n;i++){
        int sum = 0,com = 0,pos = i;
        for(int j = 20;j>=0;j--){
            if(com+(1ll<<j) <= 2*b-1){
                com+=(1ll<<j);
                sum+=tot[pos][j];
                pos=net[pos][j];
            }
        }
        cout<<(sum>=b?1:0);
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _=1;
    //cin>>_;
    while(_--){
        solve();
    }
    return 0;
}