#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 1e6 + 7;

long long ans[2000007];
long long a[1500][1500] = {}, res = 1;

void init()
{
    for (int i = 1; i < 1500; i++)
    {
        for (int j = i - 1; j >= 1; j--)
        {
            a[j][i - j] = a[j - 1][i - j] + a[j][i - j - 1] - a[j - 1][i - j - 1] + res * res;
            ans[res] = a[j][i - j];
            res++;
        }
    }
}

void solve()
{
    i64 n;
    cin >> n;

    cout << ans[n] << endl;

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}