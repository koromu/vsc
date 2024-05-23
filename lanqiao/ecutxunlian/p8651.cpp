#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <tuple> // 添加此头文件

using namespace std;

typedef long long ll;

const int N = 100010;
int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
set<tuple<int, int, int>> s1; // 使用 std::tuple

int main()
{
    string a;
    cin >> a;
    int x1, x2, x3;
    x1 = (a[0] - '0') * 10 + (a[1] - '0');
    x2 = (a[3] - '0') * 10 + (a[4] - '0');
    x3 = (a[6] - '0') * 10 + (a[7] - '0');

    // 得到三个数字
    // 先判断年月日
    // 先看月份
    bool flag = false;
    if(x2 >= 0 && x2 <= 12)
    {
        if(x2 == 2)
        {
            // 如果是2月的话
            if(x3 == 29)
            {
                // 是闰年的话
                if(x1 >= 60 && x1 <= 99 && (((x1 + 1900) % 4 == 0 && (x1 + 1900) % 100 != 0) || (x1 + 1900) % 400 == 0))
                {
                    // cout << 1900 + x1 << "-" << a[3] << a[4] << "-" << a[6] << a[7] << endl;
                    flag = true;
                }
                else if(x1 >= 0 && x1 <= 59 && (((2000 + x1) % 4 == 0 && (2000 + x1) % 100 != 0) || (2000 + x1) % 400 == 0) ) //要么吗x1属于0 ~ 59, 那么就是判断2000 + x1
                {
                    // cout << 2000 + x1 << "-" << a[3] << a[4] << "-" << a[6] << a[7] << endl;
                    flag = true;
                }
            }
        }
        if(!flag){
            // 因为到这里的月份都已经是合法的
            // 取出这个月份的合法天数 
            int days = day[x2];
            // cout << days << endl;
            if(x3 >= 1 && x3 <= days)
            {
                if(x1 >= 60 && x1 <= 99 )
                {
                    // cout << 1900 + x1 << "-" << a[3] << a[4] << "-" << a[6] << a[7] << endl;
                    s1.insert(make_tuple(1900 + x1, x2, x3));
                }
                else if(x1 >= 0 && x1 <= 59 ) //要么吗x1属于0 ~ 59, 那么就是判断2000 + x1
                {
                    // cout << 2000 + x1 << "-" << a[3] << a[4] << "-" << a[6] << a[7] << endl;
                    s1.insert(make_tuple(2000 + x1, x2, x3));
                }
            }//
        } 
    }
    // 然后是月日年
    flag = false;
    if(x1 >= 0 && x1 <= 12)
    {
        if(x1 == 2)
        {
            // 如果是2月的话
            if(x2 == 29)
            {
                // 是闰年的话
                if(x3 >= 60 && x3 <= 99 && (((x3 + 1900) % 4 == 0 && (x3 + 1900) % 100 != 0 )|| (x3 + 1900) % 400 == 0))
                {
                    // cout << 1900 + x3 << "-" << a[0] << a[1] << "-" << a[3] << a[4] << endl;
                    s1.insert(make_tuple(1900 + x3, x1, x2));
                    flag = true;
                }
                else if(x3 >= 0 && x3 <= 59 && (((2000 + x3) % 4 == 0 && (2000 + x3) % 100 != 0) || (2000 + x3) % 400 == 0 )) //要么吗x3属于0 ~ 59, 那么就是判断2000 + x3
                {
                    // cout << 2000 + x3 << "-" << a[0] << a[1] << "-" << a[3] << a[4] << endl;
                    s1.insert(make_tuple(2000 + x3, x1, x2));
                    flag = true;
                }
            }

        }
        if(!flag){
            // 因为到这里的月份都已经是合法的
            // 取出这个月份的合法天数 
            int days = day[x1];
            // cout << days << endl;
            if(x2 >= 1 && x2 <= days)
            {
                if(x3 >= 60 && x3 <= 99 )
                {
                    // cout << 1900 + x3 << "-" << a[0] << a[1] << "-" << a[3] << a[4] << endl;
                    s1.insert(make_tuple(1900 + x3, x1, x2));
                }
                else if(x3 >= 0 && x3 <= 59 ) //要么吗x3属于0 ~ 59, 那么就是判断2000 + x3
                {
                    // cout << 2000 + x3 << "-" << a[0] << a[1] << "-" << a[3] << a[4] << endl;
                    s1.insert(make_tuple(2000 + x3, x1, x2));
                }
            }
        } 
    }
    // 然后是日月年
    flag = false;
    if(x2 >= 0 && x2 <= 12)
    {
        if(x2 == 2)
        {
            // 如果是2月的话
            if(x3 == 29)
            {
                // 是闰年的话
                if(x3 >= 60 && x3 <= 99 && (((x3 + 1900) % 4 == 0 && (x3 + 1900) % 100 != 0) || (x3 + 1900) % 400 == 0))
                {
                    // cout << 1900 + x3 << "-" << a[3] << a[4] << "-" << a[0] << a[1] << endl;
                    s1.insert(make_tuple(1900 + x3, x2, x1));
                    flag = true;
                }
                else if(x3 >= 0 && x3 <= 59 && (((2000 + x3) % 4 == 0 && (2000 + x3) % 100 != 0 )|| (2000 + x3) % 400 == 0 )) //要么吗x3属于0 ~ 59, 那么就是判断2000 + x3
                {
                    // cout << 2000 + x3 << "-" << a[3] << a[4] << "-" << a[0] << a[1] << endl;
                    s1.insert(make_tuple(2000 + x3, x2, x1));
                    flag = true;
                }
            }

        }
        if(!flag){
            // 因为到这里的月份都已经是合法的
            // 取出这个月份的合法天数 
            int days = day[x2];
            // cout << days << endl;
            if(x3 >= 1 && x3 <= days)
            {
                if(x3 >= 60 && x3 <= 99 )
                {
                    // cout << 1900 + x3 << "-" << a[3] << a[4] << "-" << a[0] << a[1] << endl;
                    s1.insert(make_tuple(1900 + x3, x2, x1));
                }
                else if(x3 >= 0 && x3 <= 59 ) //要么吗x3属于0 ~ 59, 那么就是判断2000 + x3
                {
                    // cout << 2000 + x3 << "-" << a[3] << a[4] << "-" << a[0] << a[1] << endl;
                    s1.insert(make_tuple(2000 + x3, x2, x1));
                }
            }
        } 
    }
    for(auto i : s1)
    {
        int y = get<0>(i), m = get<1>(i) , d = get<2>(i);
        if(m <= 10)
        {
            if(d <= 10)
            {
                cout << y << "-0" << m << "-0" << d << endl;
            }
            else
            {
                cout << y << "-0" << m << "-" << d << endl;
            }
        }
        else
        {
            if(d <= 10)
            {
                cout << y << "-" << m << "-0" << d << endl;
            }
            else 
                cout << y << "-" << m << '-' << d << endl;
        }
    }
    return 0;
}

// 60..