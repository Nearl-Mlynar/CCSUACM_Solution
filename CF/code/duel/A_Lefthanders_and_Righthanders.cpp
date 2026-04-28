#include <bits/stdc++.h>
using namespace std;

void solve()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    string s;
    cin >> n >> s;

    int mid = n / 2;
    for (int i = 0; i < mid; i++)
    {
        int l = i + 1, r = mid + i + 1;

        if (s[l - 1] == 'R' && s[r - 1] == 'L')
        {
            swap(l, r);
        }

        cout << l << " " << r << endl;
    }
    return;
}

signed main()
{
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}