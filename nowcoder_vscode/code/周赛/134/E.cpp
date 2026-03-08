#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    int cnt = 0;
    for (char x : s)
    {
        cnt += x - '0';
    }

    if (cnt == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << max(cnt, n - 1) << endl;
    }

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}