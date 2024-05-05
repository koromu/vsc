#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 110;
typedef long long ll;
typedef pair<ll, ll> pii;
bool cmp(pii a, pii b)
{
    return a.first < b.first;
}

void solve()
{
    // 6,7,8,9,10,11,12,13,14,15,16,17,18
    int a, b;
    cin >> a >> b;
    if(a == 0 && (b == 6 || b == 7 || b == 8 || b == 9 || b == 10 || b == 11 || b == 12 || b == 13 || b == 14 || b == 15 || b == 16 || b == 17 || b == 18))
    {
        cout << "Yes" << endl;
    }
    else if((a == 1 || a == 4) && (b == 4 || b == 5 || b == 6 || b == 7 || b == 8 || b == 9 || b == 10 || b == 11))
    {
        cout << "Yes" << endl;
    }
    else if((a == 3 || a == 6 || a == 9 || a == 12) && (b ==2 || b == 3 || b == 5 || b == 6))
    {
        puts("Yes");
    }
    else puts("No");
}
int main()
{
    int a, b;
    while(cin >> a >> b)
    {
        if(a == 0 && (b == 6 || b == 7 || b == 8 || b == 9 || b == 10 || b == 11 || b == 12 || b == 13 || b == 14 || b == 15 || b == 16 || b == 17 || b == 18))
        {
            cout << "Yes" << endl;
        }
        else if((a == 1 || a == 4) && (b == 4 || b == 5 || b == 6 || b == 7 || b == 8 || b == 9 || b == 10 || b == 11|| b == 12 || b == 13 || b == 14 || b == 15 || b == 16 ))
        {
            cout << "Yes" << endl;
        }
        else if((a == 3 || a == 6 || a == 9 || a == 12) && (b == 0))
        {
            puts("Yes");
        }
        else if((a == 2 || a == 5 || a == 8) && (b == 2 || b == 3 || b == 5 || b == 6))
            puts("Yes");
        else puts("No");
    }
    return 0;
}