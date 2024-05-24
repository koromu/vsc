#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;// 存点的下标
typedef long long ll;

const int N = 100010;

int main()
{
    ll ms;cin >> ms;
    // 不管是闰年还是平年, 都是24小时一天, 所以我们现在算出小时数
    // 毫秒转小时
    ll dms = 24 * 60 * 60 * 1000;
    // 先整除得到天数的整数
    ll rms = ms - ms / dms * dms;
    // 得到余出来的一天的秒数
    // 然后算出小时数
    int hh = 0, mm = 0, ss = 0;
    hh = rms / (60 * 60 * 1000);
    rms -= hh * 60 * 60 * 1000;
    mm = rms / (60 * 1000);
    rms -= mm * 60 * 1000;
    ss = rms / 1000;
    rms -= ss * 1000;

    // string ans = "";
    printf("%02d:%02d:%02d",hh, mm, ss );
    
    return 0;
}