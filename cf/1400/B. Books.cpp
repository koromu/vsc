#include <iostream>
#include <algorithm>
#include <queue>

#define int long long
using namespace std;

const int N = 100010;

typedef pair<int, int> pii;
int a[N];
int n, t;
queue<int> q;
// priority_queue<pii, vector<pii>, greater<pii>> heap; // 第一个元素是书的个数, 第二个元素是时间, 那直接维护最大值?
signed main()
{
    cin >> n >> t;
    for(int i = 1 ; i <= n ; i ++) cin >> a[i];

    int maxv = 0;//记录最大值
    int sum = 0;// 记录当前队列的和
    int con = 0; // 记录当前队列的长度
    // 记录节点下标和尾巴节点下标
    for(int i = 1 ; i <= n ; i ++)
    {
        // 枚举每一个书
        // 如果加上这本书的话, 和小于等于t, 那么就加入q中, 然后更新最大值
        // 如果加上这本书大于t的话, 然后插入这个元素, 更新最大值, 然后从队头开始弹出, 直到和小于等于t
        // 所以最后都是要插入这个元素的, 然后如果和大于t的话, 那么开始弹出队头元素 , 只不过是插入之后可能长度是+1的也可能是正好的
        // 所以直接更新队列的最大值, 然后如果需要弹出队头, 那么与当前元素个数-1更新, 否则和当前元素个数更新
        
        // 如果这本书的值完全大于这个时间
        if(a[i] > t) continue;
        maxv = max(maxv, a[i]);// 时间是合法的直接更新时间
        if(sum + a[i] <= t)
        {
            // 如果是合法的
            q.push(a[i]);
            con = max(con, (int)q.size());
            sum += a[i];
        }
        else 
        {
            // 不合法的话, 就要开始弹出队头元素了
            // 并且好像不用更新长度con了
            while(sum + a[i] > t){ sum -= q.front(); q.pop();}
            q.push(a[i]);
            sum += a[i];
        }
    }
    cout << con << endl;
    return 0;
}

