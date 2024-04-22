#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const int N = 100010;
int w[N];
void solve()
{
    int mex = 0;
    int h[N] = {0};
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i], h[w[i]] = 1;//全局mex也可以在这里求出来, 如果mex是一个出现的数, 那么至少有一个区间的mex不符合要求, 所以mex是第一个没有出现的数

    // 读入所有元素了, 然后先算出mex, 这个就是从前往后遍历到第一个相同的数, 然后这其中的没有出现的最小的数
    // int tag  = 0;
    // while(!h[w[tag + 1]] && tag + 1 <= n) //如果一直没有出现重复的值, 直接就是-1
    // {
    //     h[w[tag + 1]] = 1;
    //     tag ++;//直到出现了重复的值
    // }//和下面的代码一起找到全局的mex
    // for(int i  =  0 ;i <= N; i ++ )
    // {
    //     if(!h[i])
    //     {    
    //         //得到没有出现的最小的数
    //         mex = i;
    //         break;
    //     }
    // }
    for(int i = 1 ; i <= n ; i ++)
    {
        if(!h[i - 1]) break;//处理完数据以后, 随后在这里找第一个没有出现的数,  也就是mex
        else mex = i;
    }
    // cout << "mex: " << mex << endl;
    unordered_map<int, int> ha;
    vector<pii> ans ;
    //找到了最小的数了
    int l = 1 , r = 1;
    int tmp = 0;
    while(r <= n)
    {
        ha[w[r]] = 1;
        while(ha.count(tmp)) tmp ++;//直到tmp到这个区间从0开始第一个不存在的数, 也就是有可能是mex的数
        if(tmp == mex) //如果tmp等于mex, 说明这个区间里面有mex, 那么就直接把区间加入到答案里面
        {
            ans.push_back({l, r});
            l = r + 1;
            r = l;
            ha.clear();
            tmp = 0;
        }
        else r++;
        // cout <<  "l : " <<   l << "  r : " << r << endl;
    }
    //最后单独处理末尾的元素, 末尾的元素一定是可以加到最后一个区间中的
    ans.back().second = n;

if(ans.size() > 1){
    cout << ans.size() << endl;
    for(auto i : ans)
    {
        cout << i.first << " " << i.second << endl;
    }
}
else cout << -1 << endl;
    
    return;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}
//如何之妙?
//首先mex这个值一定是数组中从没出现的数 
//如果mex是一个出现的数, 那么至少有一个区间的mex不符合要求, 所以mex是第一个没有出现的数

//其次, 在找每一个区间的时候, 我们根据mex来求, 相当一个窗口, 记录窗口中的每一个出现的元素
//只有当当前窗口中的元素能组成0 ~ mex-1的时候, 我们就直接存下这个窗口, 这样可以得到第一个答案, 毕竟答案不唯一
//然后到最后我们可能提前结束了, 然后剩一堆或者一个大于mex的值或者一个不能凑到0 ~ mex-1 的区间
//这时这个区间可以直接和前面的区间合并
