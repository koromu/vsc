#include <iostream>
#include <algorithm>

#define int long long
using namespace std;

char a[3] = {'Y','e','s'};

void solve()
{   
    // 遍历一遍字符串，然后按照顺序对比
    string s1;
    
    cin >> s1;
    if(s1[0] == 'Y')
        for(int i = 0 ; i < s1.size() ; i ++)
        {
            if(s1[i] != a[i % 3]) 
            {
                puts("NO");
                return;
            }
        }
    else if(s1[0] == 'e')
    {
        for(int i = 0 ; i < s1.size() ; i ++)
        {
            if(s1[i] != a[(i + 1) % 3]) 
            {
                puts("NO");
                return;
            }
        }
    }
    else
    {
        for(int i = 0 ; i < s1.size() ; i ++)
        {
            if(s1[i] != a[(i + 2) % 3]) 
            {
                puts("NO");
                return;
            }
        }
    }
    puts("YES");
}


signed main()
{
    int _; cin >> _;
    while(_--) solve();
    return 0;
}