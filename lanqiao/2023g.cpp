#include <iostream>
#include <string>

using namespace std;
const int N = 500010;

int s2[N];

int main()
{
    long long K, c = 0; // 不开longlong见祖宗
    string c1, c2, s;
    cin >> K >> s >> c1 >> c2;

    // 一个前缀和记录, 前i个位置, 有多少个c1, 有多少个c2
    //  if(s[0] == c1[0]) s1[0] = 1;
    //  else if(s[0] == c2[0]) s2[0] = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == c2[0])
            s2[i + 1] = s2[i] + 1;
        else
            s2[i + 1] = s2[i];
    } // s1, s2的下标从1开始

    // for (int i = 0; i + K - 1 < s.size(); i++)
    // {
    //     if (s[i] == c1[0])
    //         for (int j = i + K - 1; j < s.size(); j++)
    //         {
    //             if (s[j] == c2[0])
    //             {
    //                 c++;
    //             }
    //         }
    // } // 这个时间复杂度是小于O(k^2), 肯定会超时
    for (int i = 0; i + K - 1 < s.size(); i++)
    {
        if (s[i] == c1[0])
        {
            // 如果起点是合法的, 那么就可以加上从终点到这个点后k个字符的c2的个数
            c += (s2[s.size()] - s2[i + K - 1]);
        }
    }

    cout << c << endl;
    return 0;
}