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
const i64 N = 1e5 + 7;

int is_prime[N];

int fast_io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    return 0;
}();

int init = []()
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N; ++i)
    {
        is_prime[i] = true;
    }
    for (int i = 2; i * i <= N; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                {
                    is_prime[j] = false;
                }
            }
        }
    }
    return 0;
}();

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 2;
    }

    bool flag = false;

    for (int i = 0; i < n; i++)
    {
        if (is_prime[a[i]])
        {
            a[i] = 1;
        }
        else
        {
            a[i] = 2;
            flag = true;
        }
    }

    cout << 1 + flag << endl;

    for (int x : a)
    {
        cout << x << ' ';
    }

    cout << endl;
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