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

    string a, b;
    cin >> a >> b;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == '1' || a[i] == 'I')
        {
            a[i] = 'l';
        }
        if (b[i] == '1' || b[i] == 'I')
        {
            b[i] = 'l';
        }
        if (a[i] == '0')
        {
            a[i] = 'O';
        }
        if (b[i] == '0')
        {
            b[i] = 'O';
        }
        if (a[i] != b[i])
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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