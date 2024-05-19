#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool flag1, flag2;
int main()
{
    int w, a, b;
    cin >> w >> a >> b;
    // 找到a的坐标
    int dx = 1; // 一开始是向右偏移, 然后是向左偏移
    // 是交替进行着, 所以每次遍历完一行就要把x取反一下
    int x = 1, y = 1;
    int x1, y1, x2, y2;
    int maxv = max(a, b);
    for (int i = 1, j = 1; j <= maxv; i++, j++)
    // 记录一下现在到那个数了, 然后也 记录一行
    {
        // 要么向左要么向右, 但是上下走的时候是不需要变横坐标的
        // 如果没有到的话那么就先改变坐标
        // 所以是先走
        if (j == a && !flag1)
        {
            x1 = x, y1 = y;
            flag1= true;
        }

        if (j == b && !flag2)
        {
            x2 = x, y2 = y;
            flag2 = true;
        }
        x += dx;

        if (i == w) // 如果一行过去了
        {
            // 需要改变x
            // 需要把i复原一下
            // 纵坐标加1
            if (j == a && !flag1)
            {
                x1 = x, y1 = y;
                flag1 = true;
            }

            if (j == b && !flag2)
            {
                x2 = x, y2 = y;
                flag2 = true;
            }
            i = 0;
            x -= dx; // 先进一步, 然后等下一轮退回来
            dx *= -1;
            y += 1;
            // 横坐标是不用改变的
        }
    }

    cout << abs(x1 - x2) + abs(y1 - y2) << endl;

    return 0;
}