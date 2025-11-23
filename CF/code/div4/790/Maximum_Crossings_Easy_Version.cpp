#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;
int m;
int t[N];

int lowbit(int x)
{
    return x & -x;
}

void update(int k, int v)
{
    while (k <= m)
    {
        t[k] += v;
        k += lowbit(k);
    }
}

int getsum(int k)
{
    int res = 0;
    while (k > 0)
    {
        res += t[k];
        k -= lowbit(k);
    }
    return res;
}

void clear()
{
    memset(t, 0, sizeof(t)); 
}

void solve()
{
    int n;
    cin >> n;
    clear(); 

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    m = b.size();                               

    int res = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        res += getsum(idx); 
        update(idx, 1);
    }

    cout << res << endl;
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