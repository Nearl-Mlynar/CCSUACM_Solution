#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define forn(i, a, b) for (int i = a; i <= b; ++i)
#define rforn(i, a, b) for (int i = a; i >= b; --i)
#define all(v, l, r, ...) v.begin() + l, v.begin() + r, ##__VA_ARGS__
#define rall(v, l, r, ...) v.rbegin() + l, v.rbegin() + r, ##__VA_ARGS__
#define endl '\n'

const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

int fast_io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    return 0;
}();

int init = []()
{
    return 0;
}();

void solve()
{
    set<int> st;
    int m;
    cin >> m;
    forn(i, 1, m)
    {
        int op, x;
        cin >> op >> x;

        if (op == 1)
        {
            if (st.count(x))
            {
                cout << "Already Exist" << endl;
            }
            else
            {
                st.insert(x);
            }
        }
        else
        {
            if (st.empty())
            {
                cout << "Empty" << endl;
                continue;
            }
            auto it1 = st.lower_bound(x);

            if (it1 != st.end() && *it1 == x)
            {
                cout << *it1 << endl;
                st.erase(it1);
            }
            else
            {
                int res = 0;
                if (it1 == st.begin())
                {
                    res = *it1;
                }
                else if (it1 == st.end())
                {
                    --it1;
                    res = *it1;
                }
                else
                {
                    auto it2 = prev(it1);
                    if (x - *it2 <= *it1 - x)
                    {
                        res = *it2;
                    }
                    else
                    {
                        res = *it1;
                    }
                }
                cout << res << endl;
                st.erase(res);
            }
        }
    }
    return;
}

signed main()
{
    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}