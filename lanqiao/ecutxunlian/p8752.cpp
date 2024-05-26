#include <iostream>

using namespace std;

bool check(string x)
{
    if(x[0] == x[2])
    {
        if(x[3] - x[1] == 1)
            return true;
    }
    return false;
}

int main()
{
    int ans = 0;
    for(int i = 0 ; i < 5 ; i ++)
    {
        string tmp;cin >> tmp;
        if(check(tmp))
            ans ++;
    }
    cout << ans << endl;
    return 0;
}