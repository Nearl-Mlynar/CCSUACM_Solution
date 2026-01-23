#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

int lowbit(int x)
{
    return x & -x;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n + 1, -1);

    if (n & 1)
    {
        cout << n - 1 << " ";
        for (int i = 2; i < n; i++)
        {
            cout << (i ^ 1) << " ";
        }
        cout << 1 << endl;
        return;
    }

    if (n == lowbit(n))
    {
        cout << -1 << endl;
        return;
    }

    a[1] = n, a[n] = 1;
    for (int i = 2; i < n; i++)
    {
        a[i] = i ^ 1;
    }

    swap(a[1], a[lowbit(n)]);

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " \n"[i == n];
    }

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}