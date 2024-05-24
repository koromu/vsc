#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;// 存点的下标
typedef long long ll;

const int N = 110, M = 100010;

int w[M];
bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++) w[i] = i;

    while(m--)
    {
        int op, q;
        cin >> op >> q;
        if(op == 1)
        {
            sort(w + q , w + n + 1);
        }
        else sort(w + 1, w + q + 1, cmp);
        // cout << "op : " << op << endl;

        // for(int i = 0 ; i < n ; i ++)
        // {
        //     cout << w[i] << " ";
        // }
    }

    for(int i = 1 ; i <= n ; i ++)
    {
        cout << w[i] << " ";
    }
    return 0;
}