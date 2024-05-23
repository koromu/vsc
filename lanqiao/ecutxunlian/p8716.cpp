#include <iostream>
#include <set>

using namespace std;
typedef pair<long double,long double> pii;// 存点的下标
typedef unsigned long long ll;

const int N = 10010;
int c[N];
int tmp = 0;
int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool checkday(int s)
{
    // cout << "S : " << s << endl; 
    // 是个合法的日子吗
    int yy, mm, dd;
    yy = s / 10000;
    mm = ((s - yy * 10000) / 100);
    dd = s % 100;
    // cout <<"yy : " << yy << " mm : " << mm << " dd : " << dd << endl;
    if(mm == 2)
    {
        if((yy % 4 == 0 && yy % 100 != 0) ||(yy % 400 == 0))// 铭记1900
        {
            // 是闰年的话
            if(dd <= 29) return true;
            else return false;
        }
        else 
        {
            if(dd <= 28) return true;
            else return false;
        }
    }
    else if(mm <= 12)
    {
        // 不是二月, 直接取出天数, 天数合法就是合法, 和年没关系
        int ddd = day[mm];
        if(dd <= ddd) return true;
        else return false;
    }
    else return false;
}

bool checkform(int s)
{
    // 判断一下是不是ababbaba的就行了
    // 也就是取出每一位
    // cout << "S : " << s << endl;
    int x[8];
    for(int i = 0 ; i < 8 ; i ++)
    {
        x[i] = s % 10;
        s /= 10;
    }
    // 那么0是最低位
    if((x[0] == x[2] && x[5] == x[2] && x[5] == x[7]) && (x[1] == x[3] && x[3] == x[4] && x[4] == x[6]))
        return true;
    else return false;
}

int main()
{
    for(int i = 1 ; i <= 9 ; i ++)
    {
        for(int j = 0 ; j <= 9 ; j ++)
        {
            for(int k = 0; k <= 9 ; k ++)
            {
                for(int l = 0 ; l <= 9 ; l ++)
                {
                    if(k || l)
                    {
                        int tt = i * 10000000 + j * 1000000 + k * 100000 + l * 10000 + l * 1000 + k * 100 + j * 10 + i;
                        c[tmp++] = tt;
                
                    }
                }
            }
        }
    }

    int s;
    cin >> s;
    // 先打表枚举回文数
    bool flag = false;
    // 然后判断日期是否合法, 然后再判断格式是否正确
    int i;
    for(i = 0 ; c[i] <= 99399399 && !flag ; i ++)
    {
        if(c[i] > s)
        {
            if(checkday(c[i]))
            {
                cout << c[i] << endl;
                flag = true;
            }
        }
    }

    for(; c[i] <= 99933999 ; i ++)
    {
        if(c[i] > s)
        {
            if(checkday(c[i]))
            {
                // cout << "c[i] : " << c[i] << endl;
                if(checkform(c[i]))
                {
                    cout << c[i] << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}//90