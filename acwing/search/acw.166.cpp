#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 9, M = 1 << N - 1;// 用二进制枚举状态, 对于每行, 每列, 每个九宫格
char str[N * N  +10];
// 对于一个状态有多少个1, 我们可以每次用个函数计算, 当然也可以进行一个预处理, 处理出9位所有的情况的1的个数

int ones[1 << N];// 下标就是状态, 存的就是1的个数
int cnt;
// 一个剪枝, 首先是枚举顺序, 先枚举分支少的情况, 也就是对于一个位置能填多少种情况, 我们进行一个判断, 找到一个能填数字最少的情况
// 然后是剪枝 -> 可行性剪枝, 最优性剪枝(虽然这里可能没有)
// 然后还有其他的优化
// 位运算, 状态压缩的情况

// 每一行, 每一列, 每一个九宫格我们都要记录一下当前这个(i, j)是在那个行, 哪个列, 然后可以使用多少个数据, 所以需要开数组记录一下
int hang[N], lie[N], gong[3][3];// 每一个九宫格记录一个二进制数字
// 然后dfs的过程中填入一个数字, 就把这个位置的二进制变成0, 1就是能填的地方, 0就是不能填的地方

void change(int i, int j, int t, bool flag)
{
    // 把这(i, j)一位变成数字或者字符, 也就是在hang, lie, gong中把这个1变成0
    // 第i行, 第j列, 第i / 3, j / 3个九宫格中少了一个数字
    // 如果是1的话, 那就是第0位左移0位, 是9的话就是第8位, 左移8位
    
    // 如果是真的话, 那么就修改
    // 如果是假的话, 那么就回溯
    if(flag)
        str[i * N + j] = '1' + t; // 那就是变成t了, 那么行列什么的里面就要减去这个数字
    else 
        str[i * N + j] = '.'; // 否则就是要回溯

    t = 1 << t;
    if(!flag) t = -t;// 加上一个数

    hang[i] -= t;
    lie[j] -= t;
    gong[i / 3][j / 3] -= t;
}// 这一步就是修改操作, dfs讲究的恢复现场, 也就是回溯是需要修改回去的, 所以我们可以根据填入的参数把修改的方向进行改变

int lowbit(int x)
{
    return x & -x;
}

bool dfs(int c)
{
    // c是还有多少个需要填, 对于找一个可行解的情况, 我们传回bool, 这样的话, 找到了一种情况, 那么直接返回true, 然后就可以直接全部跳出来了
    if(c == 0) return true;
    
    // 然后枚举所以的空格
    int st;
    int tmpc = 10;
    for(int i = 0, k = 0 ; i < N ; i ++)
    {
        for(int j = 0 ; j < N ; j ++, k ++)
        {
            if(str[k] == '.')
            {
                // 取出这个位置可能的情况
                // 能填的数就是这个hang, lie, gong都没有出现的数字, 把他们取个交集, 这样每一个1就是一个不可以填的数字, 这个数字就是一个状态
                int tmpst = hang[i] & lie[j] & gong[i / 3][j / 3];
                if(tmpc <= ones[st])// 取出这个可以选择的分支数
                {
                    // 如果这个状态不能填的数字更少, 那么能填的更多, 那么就不选这个
                    tmpc = ones[st];
                    st = tmpst;// 也维护这个状态
                }
            }
        }
    }// 先挑选可填数字少的情况, 然后dfs每一种情况
    // 这样就找到了可以选数量最小的情况了
    for(int i = st ; i ; i -= lowbit(i))
    {
        int t = lowbit(i);// 得到的就是这个1, 然后我们要算出这个数字代表的位置, 也就是代表的数字
        // 所以我们可以预处理一个数组, 这儿数组表示这个(1000000)2这个1所在的位置, 也就是2 ^ k的k是多少, 第三个位置是8, k就是3
    }
}

int main()
{
    // 每个图都只有一行
    // 对于一行得到一个结果, 然后输出
    // 多组测试数据
    for(int i = 0 ; i < M ; i ++) 
        for(int j = 0 ; j < N ; j ++)
            ones[i] += (i >> j) & 1;// 一个状态的每一位是0的话加0, 是1的话加1

    while(cin >> str, str[0] != 'e')
    {
        // 读入一行数独
        // 初始这些数组的每一个位置都是1
        for(int i = 0 ; i < N ; i ++) hang[i] = lie[i] = 1 << N - 1;
        for(int i = 0 ; i < 3 ; i ++)
            for(int j = 0 ; j < 3 ; j ++)
                gong[i][j] = 1 << N - 1;
        // 如果这一位是.的话那就是我们能填的地方, 然后我们用这个数组把hang, lie, gong的初始化状态搞出来
        // 这是初始化好了这个数组
        for(int i = 0 ; i < N ; i ++)
        {
            for(int j = 0 ; j < N ; j ++)
            {
                if(str[i * N + j] != '.')
                {
                    change(i, j, str[i * N + j] - '1', true);// 减1的话, 加的时候也加1就是了, 然后这样的话偏移的时候就不需要变化了减1了, 可以直接就偏移 
                }
                else cnt ++;// 顺便记录需要填的格子有多少个
            }
        }
        // 然后是枚举每一个空格
        dfs(cnt);
        
        puts(str);
    }

    return 0;
}

