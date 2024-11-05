// // #include <iostream>
// // #include <cmath>
// // #include <string>

// // // 判断是否为完全平方数
// // bool isPerfectSquare(int x) {
// //     int root = static_cast<int>(sqrt(x));
// //     return root * root == x;
// // }

// // // 计算 0 到 upper_limit 之间符合条件的数字个数
// // int countValidNumbers(int n, int upper_limit) {
// //     int count = 0;

// //     // 遍历所有可能的数字，位数为n
// //     for (int num = 0; num <= upper_limit; ++num) {
// //         std::string str_num = std::to_string(num);
// //         // 如果数字的位数不足n位，则补零
// //         while (str_num.size() < n) {
// //             str_num = "0" + str_num;
// //         }
        
// //         // 将数字分为两部分
// //         int left_part = std::stoi(str_num.substr(0, n / 2));
// //         int right_part = std::stoi(str_num.substr(n / 2, n / 2));

// //         // 检查两部分是否都是完全平方数
// //         if (isPerfectSquare(left_part) && isPerfectSquare(right_part)) {
// //             count++;
// //         }
// //     }

// //     return count;
// // }

// // // 计算区间 [L, R] 之间符合条件的数字个数
// // int solve(int n, int L, int R) {
// //     int count_up_to_R = countValidNumbers(n, R);
// //     int count_up_to_L_minus_1 = countValidNumbers(n, L - 1);
// //     return count_up_to_R - count_up_to_L_minus_1;
// // }

// // int main() {
// //     int n, L, R;
// //     std::cin >> n >> L >> R;

// //     int result = solve(n, L, R);
// //     std::cout << result << std::endl;

// //     return 0;
// // }

// // #include <iostream>
// // #include <cmath>
// // #include <string>

// // // 自定义输入输出__int128的方法
// // std::ostream& operator<<(std::ostream& dest, __int128_t value) {
// //     std::ostream::sentry s(dest);
// //     if (s) {
// //         __uint128_t tmp = value < 0 ? -value : value;
// //         char buffer[128];
// //         char* d = std::end(buffer);
// //         do {
// //             --d;
// //             *d = "0123456789"[tmp % 10];
// //             tmp /= 10;
// //         } while (tmp != 0);
// //         if (value < 0) {
// //             --d;
// //             *d = '-';
// //         }
// //         int len = std::end(buffer) - d;
// //         if (dest.rdbuf()->sputn(d, len) != len) {
// //             dest.setstate(std::ios_base::badbit);
// //         }
// //     }
// //     return dest;
// // }

// // std::istream& operator>>(std::istream& in, __int128_t& value) {
// //     std::string str;
// //     in >> str;
// //     value = 0;
// //     for (char c : str) {
// //         value = value * 10 + (c - '0');
// //     }
// //     if (str[0] == '-') {
// //         value = -value;
// //     }
// //     return in;
// // }

// // // 判断是否为完全平方数
// // bool isPerfectSquare(__int128_t x) {
// //     __int128_t root = static_cast<__int128_t>(sqrtl(x));
// //     return root * root == x;
// // }

// // // 计算 0 到 upper_limit 之间符合条件的数字个数
// // int countValidNumbers(int n, __int128_t upper_limit) {
// //     int count = 0;

// //     for (__int128_t num = 0; num <= upper_limit; ++num) {
// //         std::string str_num = std::to_string(static_cast<unsigned long long>(num));
// //         // 如果数字的位数不足n位，则补零
// //         while (str_num.size() < n) {
// //             str_num = "0" + str_num;
// //         }

// //         int half = n / 2;
// //         __int128_t left_part = std::stoull(str_num.substr(0, half));
// //         __int128_t right_part = std::stoull(str_num.substr(half, half));

// //         // 检查两部分是否都是完全平方数
// //         if (isPerfectSquare(left_part) && isPerfectSquare(right_part)) {
// //             count++;
// //         }
// //     }

// //     return count;
// // }

// // // 计算区间 [L, R] 之间符合条件的数字个数
// // int solve(int n, __int128_t L, __int128_t R) {
// //     int count_up_to_R = countValidNumbers(n, R);
// //     int count_up_to_L_minus_1 = countValidNumbers(n, L - 1);
// //     return count_up_to_R - count_up_to_L_minus_1;
// // }

// // int main() {
// //     int n;
// //     __int128_t L, R;
// //     std::cin >> n >> L >> R;

// //     int result = solve(n, L, R);
// //     std::cout << result << std::endl;

// //     return 0;
// // }


// #include <iostream>
// #include <cmath>
// #include <vector>
// #include <string>

// // 判断是否为完全平方数
// bool isPerfectSquare(int x) {
//     int root = static_cast<int>(sqrt(x));
//     return root * root == x;
// }

// // 查找并打印区间 [L, R] 中所有符合条件的数字
// void findAndPrintValidNumbers(int L, int R) {
//     int count = 0;
//     std::vector<int> validNumbers;

//     // 遍历区间 [L, R] 中的所有数字
//     for (int num = L; num <= R; ++num) {
//         std::string str_num = std::to_string(num);
//         int n = str_num.size();

//         // 如果位数不是偶数，则不符合题意，跳过
//         if (n % 2 != 0) continue;

//         // 将数字分为两部分
//         int left_part = std::stoi(str_num.substr(0, n / 2));
//         int right_part = std::stoi(str_num.substr(n / 2, n / 2));

//         // 检查两部分是否都是完全平方数
//         if (isPerfectSquare(left_part) && isPerfectSquare(right_part)) {
//             count++;
//             validNumbers.push_back(num);
//         }
//     }

//     // 输出符合条件的数字个数
//     std::cout << "Total count: " << count << std::endl;

//     // 输出所有符合条件的数字
//     std::cout << "Valid numbers: ";
//     for (int num : validNumbers) {
//         std::cout << num << " ";
//     }
//     std::cout << std::endl;
// }

// int main() {
//     int L = 1025;
//     int R = 9936;
//     std::cin >> L >> R;
//     findAndPrintValidNumbers(L, R);

//     return 0;
// }

#include <bits/stdc++.h>
#define int long long
#define ft first
#define sd second
#define cn cout<<"NO"<<endl
#define cy cout<<"YES"<<endl
using namespace std;
const int mod = 1e9 + 7; 

int n;
string l,r;

__int128_t doit1(__int128_t x)
{
    __int128_t l=0,r=1e16;
    while(l<r)
    {
        __int128_t mid=(l+r+1)/2;
        if((__int128_t)mid*mid<=x)l=mid;
        else r=mid-1;
    }
    return l+1;
}

__int128_t doit2(__int128_t x)
{
    if(x==0)return 0;
    __int128_t l=0,r=1e16;
    while(l<r)
    {
        __int128_t mid=(l+r+1)/2;
        if((__int128_t)mid*mid<x)l=mid;
        else r=mid-1;
    }
    return l+1;
}

void print128(__int128_t x) 
{
    if (x == 0) {
        cout << 0;
        return;
    }
    if (x < 0) {
        cout << "-";
        x = -x;
    }
    string res;
    while (x > 0) {
        res.push_back('0' + x % 10);
        x /= 10;
    }
    reverse(res.begin(), res.end());
    cout << res;
}

void solve()
{
    cin>>n>>l>>r; l='@'+l; r='@'+r;
    __int128_t rv=1;
    for(int i=n/2+1;i<=n;i++)rv=rv*10;
    __int128_t R=doit2(rv);
    // cout<<"R:"<<R<<endl;
    
    bool ok=false;

    __int128_t lv=0;
    for(int i=1;i<=n/2;i++)lv=lv*10+(int)(r[i]-'0');
    __int128_t L=doit2(lv);
    if(((__int128_t)doit1(lv)-1)*((__int128_t)doit1(lv)-1)==lv)ok=true;
    lv=0;
    for(int i=1;i<=n/2;i++)lv=lv*10+(int)(l[i]-'0');
    L=L-doit2(lv);
    // cout<<"L:"<<L<<endl;
    // print128(L);
    // cout << "\n";
    __int128_t ans=(__int128_t)L*(__int128_t)R;

    rv=0;
    for(int i=n/2+1;i<=n;i++)rv=rv*10+(int)(r[i]-'0');
    __int128_t tmp=doit1(rv);
    //cout<<"tmp:"<<tmp<<endl;
    rv=0;
    for(int i=n/2+1;i<=n;i++)rv=rv*10+(int)(l[i]-'0');
    tmp-=doit2(rv);
    //cout<<"tmp:"<<tmp<<endl;
    
    if(ok)ans+=(__int128_t)tmp;
    //cout<<ans<<endl;   
    // print128(L);
    print128(ans); 
}

signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
