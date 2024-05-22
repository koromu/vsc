#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int main()
{
    int n, u = 0, last = -1e9, sum = 0, tmp, ans;// u代表层数, ans是维护的答案, sum是维护的和
    cin >> n;
    int x = 0;// 记录现在这一层多少个了
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> tmp;
        sum += tmp;// 加上这个答案
        x++;
        // 每一层有2^层数个元素, 所以我们判断每一层有多少元素就可以
        if(x == 1 << u)
        {
            // 如果相等了, 说明这一层的数据已经全部读入了
            x = 0;
            u++;
            if(sum > last)
            {
                last = sum;
                ans = u;
            }
            sum = 0;
        }
    }
    // 有老六, 不是满二叉树
    if(sum > last)
    {
        ans = u + 1;
    }

    cout << ans << endl;
    return 0;
}

