#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const int N = 200005;

vector<int> g[N];
int a[N];
bool ans[N];
map<int, int> mp;
int cnt = 0;

// void dfs(int u, int p)
// {
//     if (mp[a[u]] == 1)
//     {
//         cnt++;
//     }
//     mp[a[u]]++;

//     if (cnt > 0)
//     {
//         ans[u] = true;
//     }
//     else
//     {
//         ans[u] = false;
//     }

//     for (int v : g[u])
//     {
//         if (v == p)
//         {
//             continue;
//         }
//         dfs(v, u);
//     }

//     mp[a[u]]--;
//     if (mp[a[u]] == 1)
//     {
//         cnt--;
//     }
// }

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // dfs(1, 0);

    stack<pair<int, int>> st;
    vector<bool> vis(n + 1, false);
    st.push({1, 0});

    while (!st.empty())
    {
        auto [x, y] = st.top();
        st.pop();

        if (!vis[x])
        {
            if (mp[a[x]] == 1)
            {
                cnt++;
            }
            mp[a[x]]++;
            vis[x] = true;

            st.push({x, y});

            if (cnt > 0)
            {
                ans[x] = true;
            }
            else
            {
                ans[x] = false;
            }

            for (int v : g[x])
            {
                if (v != y)
                {
                    st.push({v, x});
                }
            }
        }
        else
        {
            mp[a[x]]--;
            if (mp[a[x]] == 1)
            {
                cnt--;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << (ans[i] ? "Yes" : "No") << endl;
    }

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