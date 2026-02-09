#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n;
    i64 a0, a1;
    cin >> n >> a0 >> a1;

    string s;
    i64 cnt0 = 0, cnt1 = 0;

    for (int i = 0; i < n; ++i)
    {
        if (abs(a0 * cnt1 - a1 * (cnt0 + 1)) <= abs(a0 * (cnt1 + 1) - a1 * cnt0))
        {
            s += '0';
            cnt0++;
        }
        else
        {
            s += '1';
            cnt1++;
        }
    }

    cout << s << endl;
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