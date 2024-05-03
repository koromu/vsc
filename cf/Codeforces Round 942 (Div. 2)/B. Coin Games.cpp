#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void solve()
{
    int n;cin >> n;
    string s;
    cin >> s;
    int cu = 0;
    for(int i = 0 ; i < n ; i ++ )if(s[i] == 'U') cu++;
    //得到u的个数
    if(cu == 0) {
        puts("NO");
        return;
    }
    else if(s.size() == 2)
    {
        if(cu == 1)
        {
            puts("YES");
            return;
        }
        else if(cu == 2)
        {
            puts("NO");
            return ;
        }
    }

        if(cu % 2 == 0)
            puts("NO");
        else 
            puts("YES");
            
        return ;
}

int main()
{
    int _;
    cin >> _;
    while(_--)
    {
        solve();
    }
    return 0;
}

