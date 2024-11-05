// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// typedef pair<int, int> pii;
// const int N = 1000010;

// int w[N];

// void solve()
// {
//     int n; cin >> n;
//     for(int i = 1 ; i <= n ; i ++)
//     {
//         cin >> w[i];
//     }   
//     sort(w + 1, w + 1 + n);
//     // 然后两两之间求差值, 
// }


// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int _  = 1; 
//     cin >> _;
//     while(_--)
//     { 
//         solve();
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// map<int, int> m1;
// void solve() {
//     int x0;
//     int n; cin >> n >> x0;
//     m1.clear();
//     vector<int> v1;
//     if(n == 1)
//     {
//         cout << 0 << endl;
//         return;
//     }
//     int last = x0;
//     for(int i = 2 ; i <= n ; i ++)
//     {
//         int tmp; cin >> tmp;
//         if(m1[tmp - x0] == 0)
//         {
//             if(tmp - x0 == 1)
//             {
//                 cout << 1 << endl;
//                 return;
//             }
//             v1.push_back(tmp - x0);
//             m1[tmp - x0]++;
//         }
//         if(m1[tmp - last] == 0)
//         {
//             v1.push_back(tmp - last);
//             m1[tmp - last]++;
//         }
//         last = tmp;
//     }

//     long long ans = 1e18;
//     for(auto i : v1)
//     {
//         for(auto j : v1)
//         {
//             // cout << i << " " << j << endl;
//             if(i < j && (j % i != 0))
//                 ans = min(ans, (long long)j % i);
//             else if(i > j && (i % j != 0)) ans = min(ans, (long long)i % j);
//         }
//     }
//     if(ans == 1e18) 
//         cout << 0 << endl;
//     else cout << ans << endl;
//
// }

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int t;
//     cin >> t;
//     while (t--) {
//         solve();
//     }

//     return 0;
// }

