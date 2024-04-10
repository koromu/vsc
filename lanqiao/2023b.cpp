#include <iostream>
using namespace std;

const int N = 10010;

int A[N], B[N];
int n, maxv;

// bool check(int x)
// {
//     bool flag = true;
//     for (int i = 0; i < n; i++)
//     {
//         if (A[i] / x <= B[i])
//         {
//             // 如果小了, 说明x大了, 那么答案在mid的左边
//             continue;
//         }
//         else
//         {
//             flag = false;
//             break;
//         }
//     }
//     // 如果是true, 那么此时所有的样例都是合法的, x可以减小, 否则x不能减小, 还要变大
//     return flag;
// }
bool check(int x)
{
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (A[i] / x > B[i])
        {
            // 如果大了, 说明x小了, 那么答案在mid的右边
            return false;
        }
    }
    // 如果是true, 那么此时所有的样例都是合法的, x可以减小, 否则x不能减小, 还要变大
    return flag;
}

bool check2(int x)
{
    //要找到符合条件的最大值
    for (int i = 0; i < n; i++)
    {
        if (A[i] / x < B[i])
        {
            // 如果小了, 说明x大了, 那么答案在mid的左边
            return false;
        }
    }
    return true;
}

// bool check2(int x)
// {
//     bool flag = false;
//     for (int i = 0; i < n; i++)
//     {
//         if (A[i] / x < B[i])
//         {
//             // 如果大了, 说明mid是小了, 并且mid不会是答案, 那么mid要变大, 直接退出去变大mid
//             flag = false;
//             break;
//         }
//     }
//     // true, 那么此时所有的样例都是合法的, x可以变大, 否则x不能减小, 还要变大
//     return true;
// }

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i] >> B[i];
        maxv = max(maxv, max(A[i], B[i]));
    }

    int l = 0, r = maxv;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
        {
            r = mid;
        }
        else
            l = mid + 1;//要找符合的区间的最小值
    } // 最后找到的就是最大值? 通过样例可以得知是最小值
    cout << l << " ";

    l = 0, r = maxv;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check2(mid))
        {
            l = mid;
        }
        else
            r = mid - 1; //要找符合的区间的最大值
    }
    cout << l << endl;
    return 0;
}