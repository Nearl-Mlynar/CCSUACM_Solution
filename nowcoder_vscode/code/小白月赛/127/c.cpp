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
    cin >> n;

    if (n <= 4 && n != 3)
    {
        cout << -1 << endl;
        return;
    }
    else if (n == 3)
    {
        cout << 1 << " " << 2 << " " << 1 << " " << endl;
        return;
    }

    while (n % 2 == 0)
    {
        cout << 1 << " " << 2 << " " << 1 << " ";
        n -= 3;
    }

    for (int i = 1; i < n / 2 + 1; i++)
    {
        cout << i << " ";
    }

    for (int i = n / 2 + 1; i > 0; i--)
    {
        cout << i << " ";
    }

    cout << endl;
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