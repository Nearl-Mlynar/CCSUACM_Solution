#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> hash(m + 1, 0);
    vector<int> cnt(m + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        hash[a] += b;
        cnt[a]++;
    }

    for (int i = 1; i <= m; i++)
    {
        double x = hash[i] * 1.000 / cnt[i];
        cout << x << endl;
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}