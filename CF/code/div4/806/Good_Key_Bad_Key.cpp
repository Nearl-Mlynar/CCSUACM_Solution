#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int res = 0;
    int sum = 0;
    for (int i = -1; i < n; i++)
    {
        int p = sum;
        for (int j = i + 1; j < min(n, i + 32); j++)
        {
            p += (a[j] >> (j - i));
        }
        res = max(res, p);
        if (i + 1 != n)
        {
            sum += a[i + 1] - k;
        }
    }

    cout << res << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}