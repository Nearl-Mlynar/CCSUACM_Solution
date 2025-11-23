#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> a(n + 2);

    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x].push_back(i);
    }

    int res = 0;
    string s;
    cin >> s;

    auto f = [&](auto &&f, int idx) -> int
    {
        int k = (s[idx - 1] == 'B') ? -1 : 1;

        for (int child : a[idx])
        {
            k += f(f, child);
        }

        if (k == 0)
        {
            res++;
        }
        return k;
    };

    f(f, 1);
    cout << res << endl;
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