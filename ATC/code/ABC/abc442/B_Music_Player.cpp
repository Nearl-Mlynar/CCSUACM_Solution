#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int cnt = 0;
    int q;
    int flag = 0;
    cin >> q;

    while (q--)
    {
        int a;
        cin >> a;

        if (a == 1)
        {
            cnt++;
        }
        else if (a == 2)
        {
            cnt = max(cnt - 1, 0);
        }
        else
        {
            flag ^= 1;
        }

        if (flag && cnt >= 3)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
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
    while (T--)
    {
        solve();
    }
    return 0;
}