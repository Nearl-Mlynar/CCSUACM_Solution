// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl '\n'
// const int N = 2e5 + 10;

// int t[N];

// int lowbit(int x)
// {
//     return x & -x;
// }

// void update(int k, int v)
// {
//     while (k <= N - 2)
//     {
//         t[k] += v;
//         k += lowbit(k);
//     }
// }

// void clear()
// {
//     for (int i = 0; i < N; i++)
//     {
//         t[i] = 0;
//     }
// }

// int query(int k)
// {
//     int res = 0;
//     while (k > 0)
//     {
//         res += t[k];
//         k -= lowbit(k);
//     }
//     return res;
// }

// void solve()
// {
//     clear();
//     int n;
//     cin >> n;
//     vector<int> a(n + 1);
//     for (int i = 1; i <= n; ++i)
//     {
//         cin >> a[i];
//     }

//     int res = 0;
//     for (int i = 1; i <= n; ++i)
//     {
//         if (a[i] < i)
//         {
//             update(i, 1);
//             if (a[i] > 0)
//             {
//                 res += query(a[i] - 1);
//             }
//         }
//     }

//     cout << res << endl;
// }

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int T;
//     cin >> T;
//     while (T--)
//     {
//         solve();
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    int res = 0;
    vector<int> B;

    for (int j = 1; j <= n; ++j)
    {
        if (a[j] < j)
        {
            res += lower_bound(B.begin(), B.end(), a[j]) - B.begin();
            B.insert(lower_bound(B.begin(), B.end(), j), j);
        }
    }

    cout << res << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}