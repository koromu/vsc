// // #include <iostream>
// // #include <cstring>
// // #include <algorithm>

// // using namespace std;
// // const int N = 100010;

// // int h[N], e[N], ne[N], idx;
// // int n, m;
// // int d[N], q[N];//记录入度的数量, 和队列的数组

// // void add(int a, int b)
// // {
// //     e[idx] = b; ne[idx] = h[a] ;h[a] = idx++;//这个增加是在h数组的基础上建立的, 通过h[a]还可以存到这个数组的链子上
// // }

// // bool topsort()
// // {
// //     int tt = -1, hh = 0;

// //     //把所有入度为0 的点存入数组
// //     for(int i = 1 ; i <= n ; i++)//总共是n个点, 注意插入的时候, 点的编号是从1 到 n的
// //     {
// //         if(d[i] == 0)//入度为0
// //             q[++tt] = i;//存入下标在q中
// //     }
// //     //一个循环直到把所有队列中的元素处理掉, 最后再队列里面的就是拓扑序, 在队列外面进不去的就是环
// //     while( tt >= hh)
// //     {
// //         int t = q[hh++];//t要从队头开始取出来
// //         for(int i = h[t]; i != -1 ; i = ne[i])//遍历这条链上的点
// //         {
// //             int j = e[i];//取到i指向的点
// //             if(--d[j] == 0)//删掉j这个点, 如果j指向的点的入度为0的话, 就可以存到里面去了
// //                 q[++tt] = j;//j是一个一个链表的头, 把这个头存进q中, 然后下次将要再遍历从这个j开始得链表
// //         }
// //     }
// //     //再判断有没有入度为0的点, 有就放进去
// //     return tt == n - 1 ;//最后得到的tt如果是n-1, 也就是说队列的下标存入了所有的分支, 那么这个图是无环的拓扑结构
// // }


// // int main()
// // {
// //     cin >> n >> m;
// //     memset(h, -1, sizeof(h));
// //     for(int i = 0 ; i < m ; i ++)
// //     {
// //         int a, b ; 
// //         cin >> a >> b;
// //         add(a, b);
// //         d[b]++;
// //     }
// //     if(topsort())
// //     {
// //         for(int i = 0 ; i < n ; i ++) printf("%d ", q[i]);
// //         puts("");
// //     }
// //     else
// //         puts("-1");
    
    
// //     return 0;
// // }

// #include <iostream>
// #include <cstring>
// #include <algorithm>

// using namespace std;

// const int N = 100010;
// int h[N], e[N], ne[N], idx;
// int n, m;
// int q[N], d[N];//记录入度
// //d里面放的是b
// //q里面放的也是b
// void add(int a, int b)
// {
// 	e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
// }

// bool topsort()
// {
// 	//入度为0的进入队列中
// 	int tt = -1, hh = 0;
// 	d[1] = 0;
// 	for (int i = 1; i <= n; i++)
// 	{
// 		if (d[i] == 0)
// 			q[++tt] = i;
// 	}
// 	while (tt >= hh)
// 	{
// 		int t = q[hh++];//得到一个点的编号
// 		for (int i = h[t]; i != -1; i = ne[i])//得到一个点的编号在这个链表里的idx
// 		{//得到这个idx对应的b
// 			int j = e[i];//e[i]存的是一个b, 是a指向的点, h[t]存入的是idx
// 			//--d[j];// t是入度为0的点
// 			if (--d[j] == 0)
// 				q[++tt] = j;//存入b
// 		}
// 	}//所以q, d, h这两个数组都是放的b, 只有e和ne有关的组成链表的东西索引用的idx, 其中e放b, ne放idx
// 	return tt == n - 1;
// }

// int main()
// {
// 	cin >> n >> m;
// 	memset(h, -1, sizeof h);
// 	for (int i = 0; i < m; i++)
// 	{
// 		int a, b;
// 		cin >> a >> b;
// 		add(a, b);
// 		d[b] ++;
// 	}

// if(topsort())
// 	for (int i = 0; i < n; i++) printf("%d ", q[i]);
// else
// 	puts("-1");
// return 0;
// }
#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

typedef pair<int, int> pii;

const int N = 200010;

vector<int> h[2 * N];// 存边
int dis[N];// 存一个点的入度
int q[N * 2];

int n, m; 

bool topsort()
{
    // 先把所有入度为0的点加到队列里面
    int hh = 0, tt = -1;// 拓扑排序手写有奇效 
    for(int i = 1 ; i <= n ; i ++ )
    {
        if(dis[i] == 0)
        {
            q[++tt] = i;// 这个点加到队列中
        }
    }
    while(hh <= tt)
    {
        int point = q[hh++];// 取出队头元素
        for(int i = 0 ; i < h[point].size() ; i ++)
        {
            int j = h[point][i];// 得到指向的边
            // 遍历所有子节点
            dis[j]--;
            if(dis[j] == 0)
            {
                // 可以加到队列中了
                q[++tt] = j;
            }
        }
    }
    return tt == n - 1;// 如果出队的点的个数刚好是n的话，说明是拓扑图，否则就是有环
}

signed main()
{   
    cin >> n >> m;
    for(int i = 0 ; i < n ; i ++)
    {
        int a, b ; cin >> a >> b;
        h[a].push_back(b);// 一条a -> b的边
        dis[b] ++;// 那么b入度+1
    }
    for(int i = 0 ; i < n ; i ++) cout << dis[i] << " ";
    cout << endl;

    if(topsort())
    {
        // 非常巧妙地手写队列q中出队顺序就是拓扑序
        for(int i = 0 ; i < n ; i ++)
        {
            cout << q[i] << " ";
        }
    }
    else puts("-1");

    return 0;
}