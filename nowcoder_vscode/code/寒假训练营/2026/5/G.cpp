#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    string s = "0112233445142015320125410214530214510214102302142025101203201451451522302514203214510021454101002532";
    int q[6][4] = {
        {3, 2, 1, 0},
        {0, 3, 2, 1},
        {1, 0, 3, 2},
        {2, 1, 0, 3},
        {1, 2, 3, 0},
        {3, 0, 1, 2}};

    int res = 0;
    string ans = "";

    for (char c : s)
    {
        res = q[c - '0'][res];
        ans += res + '0';
    }

    cout << ans << endl;

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}