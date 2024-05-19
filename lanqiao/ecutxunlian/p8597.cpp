#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>


using namespace std;

const int N = 1010;

int va[N], vb[N];

int main()
{
    string a, b;
    cin >> a >> b;
    for(int i = 0 ; i < a.size() ; i ++)
    {
        if(a[i] == 'o') va[i] = 0;
        else va[i] = 1;
        
        if(b[i] == 'o') vb[i] = 0;
        else vb[i] = 1;
    }
    int ans = 0;
    for(int i = 0 ; i < N ; i ++)
    {
        if(va[i] != vb[i])
        {
            vb[i] = (vb[i] + 1) % 2;
            vb[i + 1] = (vb[i + 1] + 1) % 2;
            ans ++;
        }
    } 
    cout << ans << endl;

    return 0;
}