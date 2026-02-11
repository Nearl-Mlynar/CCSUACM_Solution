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
    i64 p;
    cin >> n >> p;

    vector<i64> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    i64 mx = -1;
    int l = 0, r = 0;

    set<pair<i64, int>> st;
    st.insert({0, 0});
    
    i64 pref = 0;

    for (int i = 1; i <= n; i++)
    {
        pref = (pref + a[i - 1]) % p;

        auto it = st.upper_bound({pref, INT_MAX});
        if (it != st.end())
        {
            i64 res1 = (pref - it->first + p) % p;
            if (res1 > mx)
            {
                mx = res1;
                l = it->second;
                r = i - 1;
            }
        }

        auto it2 = st.begin();
        i64 res2 = (pref - it2->first + p) % p;
        if (res2 > mx)
        {
            mx = res2;
            l = it2->second;
            r = i - 1;
        }

        st.insert({pref, i});
    }

    cout << l << " " << r << " " << mx << endl;
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