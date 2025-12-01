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

    set<int> st;

    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
        hash[x] = i + 1;
    }

    vector<int> a(st.begin(), st.end());

    int mx = INT_MIN;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i; j < a.size(); j++)
        {
            if(__gcd(a[i], a[j]) == 1)
            {
                mx = max(mx, hash[a[i]] + hash[a[j]]);
            }
        }
    }

    cout << (mx == INT_MIN ? -1 : mx) << endl;
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