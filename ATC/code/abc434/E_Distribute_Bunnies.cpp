#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

struct HopcroftKarp
{
    int n, m;
    vector<array<int, 2>> ver;
    vector<int> l, r;

    HopcroftKarp(int n, int m) : n(n), m(m)
    {
        l.assign(n, -1);
        r.assign(m, -1);
    }

    void add(int x, int y)
    {
        x--, y--;
        ver.push_back({x, y});
    }

    int work()
    {
        vector<int> adj(ver.size());
        mt19937 rgen(chrono::steady_clock::now().time_since_epoch().count());
        shuffle(ver.begin(), ver.end(), rgen);
        vector<int> deg(n + 1);
        for (auto &[u, v] : ver)
        {
            deg[u]++;
        }
        for (int i = 1; i <= n; i++)
        {
            deg[i] += deg[i - 1];
        }
        for (auto &[u, v] : ver)
        {
            adj[--deg[u]] = v;
        }

        int ans = 0;
        vector<int> a, p, q(n);
        while (true)
        {
            a.assign(n, -1), p.assign(n, -1);
            int t = 0;
            for (int i = 0; i < n; i++)
            {
                if (l[i] == -1)
                {
                    q[t++] = a[i] = p[i] = i;
                }
            }
            bool match = false;
            for (int i = 0; i < t; i++)
            {
                int x = q[i];
                if (~l[a[x]])
                {
                    continue;
                }
                for (int j = deg[x]; j < deg[x + 1]; j++)
                {
                    int y = adj[j];
                    if (r[y] == -1)
                    {
                        while (~y)
                        {
                            r[y] = x;
                            swap(l[x], y);
                            x = p[x];
                        }
                        match = true;
                        ++ans;
                        break;
                    }
                    if (p[r[y]] == -1)
                    {
                        q[t++] = y = r[y];
                        p[y] = x;
                        a[y] = a[x];
                    }
                }
            }
            if (!match)
            {
                break;
            }
        }
        return ans;
    }

    vector<array<int, 2>> answer()
    {
        vector<array<int, 2>> ans;
        for (int i = 0; i < n; i++)
        {
            if (~l[i])
            {
                ans.push_back({i, l[i]});
            }
        }
        return ans;
    }
};

void solve()
{
    int N;
    cin >> N;
    vector<long long> X(N), R(N);
    for (int i = 0; i < N; i++)
    {
        cin >> X[i] >> R[i];
    }

    vector<long long> g;
    for (int i = 0; i < N; i++)
    {
        g.push_back(X[i] - R[i]);
        g.push_back(X[i] + R[i]);
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    int M = g.size();

    HopcroftKarp flow(N, M);

    for (int i = 0; i < N; i++)
    {
        long long a = X[i] - R[i];
        long long b = X[i] + R[i];
        int idA = lower_bound(g.begin(), g.end(), a) - g.begin();
        int idB = lower_bound(g.begin(), g.end(), b) - g.begin();
        flow.add(i + 1, idA + 1);
        if (idA != idB)
        {
            flow.add(i + 1, idB + 1);
        }
    }

    int ans = flow.work();
    cout << ans << "\n";
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}