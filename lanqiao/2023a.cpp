#include <iostream>

using namespace std;

const int N = 110;
int w[N];
// day存的是2023年每一个月的天数
int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool st[13][35];
int main()
{
    for (int i = 1; i <= 100; i++)
        cin >> w[i];
    int c = 0;
    for (int i = 1; i + 7 <= 100; i++)
    {
        // i从1到100, j从i+1到100, k从j+1到100, l从k+1到100, m从l+1到100, n从m+1到100, o从n+1到100, p从o+1到100
        if (w[i] == 2)
            for (int j = i + 1; j + 6 <= 100; j++)
            {
                if (w[j] == 0)
                    for (int k = j + 1; k + 5 <= 100; k++)
                    {
                        if (w[k] == 2)
                            for (int l = k + 1; l + 4 <= 100; l++)
                            {
                                if (w[l] == 3)
                                    for (int m = l + 1; m + 3 <= 100; m++)
                                    {
                                        if (w[m] <= 1)
                                            for (int n = m + 1; n + 2 <= 100; n++)
                                            {
                                                int x = (w[m] * 10 + w[n]);
                                                if (x <= 12)
                                                    for (int o = n + 1; o + 1 <= 100; o++)
                                                    {
                                                        if (w[o] <= 3)
                                                            for (int p = o + 1; p <= 100; p++)
                                                            {
                                                                int y = w[o] * 10 + w[p];
                                                                if (y >= 1 && y <= day[x])
                                                                {
                                                                    if (!st[x][y])
                                                                        c++;
                                                                    st[x][y] = true;
                                                                }
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
            }
    }
    cout << c << endl;
    return 0;
}