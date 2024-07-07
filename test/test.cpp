// #include <iostream>
// #include <vector>
// #include <map>



// // #define int long long
// using namespace std;

// const int N = 10;

// bool w[N];

// void solve()
// {
//     // x是下标
//     int n = 0;
//     cin >> n;
//     // int l = 0 , r = 1e9;
    
//     vector <int> v1;
//     for(int i = 0 ; i < n ; i ++ )
//     {
//         scanf("%d", &w[i]);
//         if(w[i] != 1) 
//         {
//             v1.push_back(i);
//         }
//     }
//     // for(int i = 0 ; i <= 1e9 ; i ++)
//     // {
//     //     string t1, t2;
//     //     cout << "READ " << i << endl;
//     //     cin >> t1;
//     //     if(t1[0] == 't')
//     //     {
//     //         // 就判断一下下一个, 如果是就下一个测试用例, 如果不是就从这个位置开始
//     //         cout << "READ " << i + 1 << endl;
//     //         cin >> t2;
//     //         if(t2[0] == 'f')
//     //         {
//     //             cout << "OUTPUT " << i << endl;
//     //             break;
//     //         }
//     //         else continue;
//     //     }
//     //     else continue;
//     // }
//     for(auto i = v1.begin() ; i != v1.end() ; i ++)
//     {
//         if(*i - 1 < 0) continue; 
//         cout << "READ " << *i - 1 << endl;
//         string t1;
//         scanf("%s", &t1[0]);
//         if(t1[0] == 't')
//         {
//             // 就判断一下下一个, 如果是就下一个测试用例, 如果不是就从这个位置开始
//             printf("OUTPUT %d", *i - 1 );
//             break;
//         }
//     }
// }

// signed main()
// {
//     int _;
//     scanf("%d", &_);
//     while(_--)
//     {
//         solve();
//     }
//     return 0;
// }

// #include <bitsdc++.h>
#include <iostream>

using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; 
const int N = 100010;

int a[2];

void solve()
{
    int ans=-1;
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i&1]);
        if(i>=1)
            if(a[i&1]==0 && a[(i-1)&1]==1)
                if(ans==-1){
                    ans=i-1;
                    break;
                }
                else continue;
    }
    // string s;
    // while(cin>>s)
    // {
    //     if(s=="false")cout<<"READ"<<" "<<ans+1<<endl;
    //     else cout<<"READ"<<" "<<ans<<endl;
    // }
    cout << "READ " << ans << endl;
    string s1, s3;
    cin >> s1;
    cin >> s3;

    cout<<"OUTPUT"<<" "<<ans;
}

signed main()
{
    int t; cin>>t;
    while(t--)solve();
    return 0;
}