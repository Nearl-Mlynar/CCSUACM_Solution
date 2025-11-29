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

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    string s;
    for (int i = 0; i < n; i++)
    {
        int q;
        int res = 0;
        cin >> q >> s;
        for (char x : s)
        {
            if (x == 'D')
            {
                res++;
            }
            else
            {
                res--;
            }
        }

        a[i] = (a[i] + res + 10) % 10;
    }

    for (int x : a)
    {
        cout << x << " ";
    }
    cout << endl;
    return;
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