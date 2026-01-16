#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    std ::string s[7] = {"Red", "Orange", "Yellow", "Green", "Blue", "Indigo", "Violet"};

    int a[7];
    for (int i = 0; i < 7; i++)
    {
        cin >> a[i];
    }

    int idx = 0, mx = a[0];
    for (int i = 0; i < 7; i++)
    {
        if (mx < a[i])
        {
            mx = a[i];
            idx = i;
        }
    }

    cout << s[idx] << endl;
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