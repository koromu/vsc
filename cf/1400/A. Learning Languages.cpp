#include <iostream>
#include <string>
#include <algorithm>

#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 110;
    // 要使得每一个人都可以通信
    // 那么一个人可以通过一种语言，传递到另外一个人
    // 那么我们可以把一个人会的语言放到一个集合之中，表示的是这个集合中的人都是可以互相交流的
    // 那么如果到最后有两个集合，那么说明这连个集合不能一起交流，那么我们就要让其中一个集合学习一个另外一个集合有的语言就可以了
    // 同理有三个语言，那么我们就让其中两个组会第三个组的一个语言就行了，也就是要学两门语言
    // 所以我们最小的金额数就是已有的集合数-1
int p[2 * N + 10];

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);// 其中集合和集合合并的过程在这
    return p[x];
}

int n, m;
void init()
{
    for(int i = 1 ; i <= 2 * N ; i ++) 
        p[i] = i;
}

signed main()
{
    // 初始化个并查集数组
    cin >> n >> m;
    init();
    int ans = 0;
    int suml = 0;
    for(int i = 1 ; i <= n ; i ++)
    {
        // 遍历每一个人
        int k; cin >> k;
        for(int j = 0 ; j < k ; j ++)
        {
            int lang; cin >> lang;
            suml += lang;
            // 如果这个语言已经属于某个集合那么, 把这个集合的父节节点指向当前这个人的集合
            // 这个节点编号是m + i
            p[find(lang)] = find(m + i);// 把每一个这个人会的语言放到一个集合中
            // cout << "p[" << lang << "] = " << p[lang] << endl;
        }
    }
    if(suml == 0) 
    {
        cout << n << endl;
        return 0;
    }
    // for(int i = 1 ; i <= m ; i ++) {
    //     // cout << find(i) << " ";
    //     // find(i);
    // }
    // cout << endl;
    // cout << n << endl;
    for(int i = m + 1 ; i <= m + n ; i ++) {
        // cout <<"i :" << i << " " << p[i] << " " << endl;
        if(p[i] == i) ans++;
    }
    // 如果n个人都不会语言
    // 然后分成了n组
    cout << ans - 1 << endl;
    return 0;
}
