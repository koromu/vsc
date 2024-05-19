#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int k;// 全局记录位数
int a, b;
int c1, c2;// 分别记录A, B
bool solve(int st)
{
    if(k == 0) return true;
    int t1 = 0, t2 = 0;
    for(int i = 0 ; i < k; i ++)
    {
        // 枚举每一个位置
        if((st >> i) & 1)
        {
            // 如果这一位是1的话
            t1 ++;
        }
        else t2 ++;
    }// 这是统计这一层的情况, 也就是个数, 每次统计完之后都要进行更新下一层的个数, 还有判读当前的a和b的个数的合法情况

    if(c1 + t1 > a || c2 + t2 > b)
    {
        // 如果已经超过了的话, 那么就直接return
        return false;
    }

    //如果当前是合法的话, 就可以更新了
    c1 += t1, c2 += t2;
    int tmp_st = 0;
    for(int i = 0 ; i + 1 < k ; i ++)// 记得k需要更新
    {
        if(((st >> i) & 1) == ((st >> (i + 1)) & 1)) // 取出第一个位置和第二个位置, 相同是1, 不同就是0, 也就是不变
            tmp_st += (1 << i);
    }// 从0 ~ k - 2是k - 1次
    // cout << "tmp_st : " << tmp_st << endl;
    k--;// 下一层的位数需要减1
    if(!solve(tmp_st)) return false;
    return true;
}


int main()
{   
    // 最底下那层确认的的话, 这一层就是确认的了
    // 所以只确认最底层有多少总就行了?
    // 不对, 最底下一层确定后上层不一定合法
    // 所以可以dfs试一下
    // 先遍历最下面一层的情况
    // n + m = k(k -1) / 2
    // 所以可以算出k是多少, 知道了k的话就知道了最后一层有多少个字母了, 也就是k - 1个字母

    // 就用1代表A, 0代表B, 使用二进制来枚举
    cin >> a >> b;
    for(int i = 0 ; i < 231 ; i ++)
    {
        if( i * (i - 1) / 2 == a + b)
        {
            k = i - 1;
            break;
        }
    }
    int tmp = k;
    int ans = 0;
    for(int i = 0 ; i < (1 << tmp) ; i ++)
    {
        // 枚举所有的情况, 总共是k - 1位
        // 直接枚举, 每次枚举都判断情况
        if(solve(i))// 如果是false就不管
            ans ++;
        c1 = c2 = 0;
        k = tmp;
    }
    cout << ans << endl;
}