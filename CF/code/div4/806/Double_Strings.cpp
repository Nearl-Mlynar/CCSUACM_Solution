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

    set<string> st;

    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        st.insert(a[i]);
    }

    vector<int> b(n, 0);
    for (int i = 0; i < n; i++)
    {
        int m = a[i].size();
        for (int j = 1; j < m; j++)
        {
            if (st.count(a[i].substr(0, j)) && st.count(a[i].substr(j)))
            {
                b[i] = 1;
                break;
            }
        }
    }

    for (int x : b)
    {
        cout << x;
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