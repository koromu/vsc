#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;
const int N = 1010;
unordered_map<int, int> ha;
ll w[N];

int con = 1, last = 1;

int main( )
{
    int n; cin >> n;
    int tmp = 1;
    int l1 = 0;
    for(int i = 0; i < n; i++) 
    {
        cin >> w[i];
        ha[w[i]]++;
        if(i != 0 && l1 == w[i])
        {
            tmp ++;
            con = max(con, tmp);
        }
        else tmp = 1;
        l1 = w[i];
    }
    if(n == con)
    {
        cout << -n << endl;
        return 0;
    }

    // cout << con << endl;
    // 先算出本来的能量是多少
    // 得到了所有的存在的石头, 然后遍历ha, 然后去掉w里的ha[i], 然后算出能量是多少
    // 这样的话得到了当前的能量值
    // 然后是算变化之后的能量的值
    for(auto i : ha)// 枚举要消失的石头
    {// 取出每次要毁灭的石头, 然后遍历原本的石头, 如果碰到这个本应该毁灭的直接跳过, i++
        // cout << i.first << " " << i.second << endl;
        int tmp = 1;
        int ll = -1;
        for(int j = 0 ; j < n ; j ++)
        {
            if(i.first == w[j])
                // 说明当前这个要毁灭的石头和当前遍历到的石头相同, 那么跳过
                continue;
            // 取出一个值, 给下一个位置用
            // 如果不相同就维护当前情况的全局最大值
            if(ll != -1 && ll == w[j])// 维护一个上一个值是什么
            {
                // 如果上一个值和当前这个值相同, 那么直接魔法值加1
                tmp++;
                last = max(last, tmp);
            }
            else tmp = 1;
            ll = w[j];
        }
    }
    cout << last - con ;
    return 0;
}