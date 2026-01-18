#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;

const int N = 2e3, M = N + 20;
char a[M][M];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

void solve()
{
    int n;
    cin >> n;
    bool flag = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    while (1)
    {
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i][j] == '1')
                {
                    continue;
                }
                vector<int> cnt(4);
                for (int q = 0; q < 4; q++)
                {
                    cnt[q] = 0;
                    int nx = i + dy[q], ny = j + dx[q];
                    if (nx < 1 || nx > n || ny < 1 || ny > n)
                    {
                        continue;
                    }
                    if (a[nx][ny] == '1')
                    {
                        cnt[q] = 1;
                    }
                }
                int x = 0;
                for (int q = 0; q < 4; q++)
                {
                    x += cnt[q];
                }
                if (x >= 2)
                {
                    if (x == 2 && ((cnt[0] && cnt[2]) || (cnt[1] && cnt[3])))
                    {
                        continue;
                    }
                    else
                    {
                        a[i][j] = '1', res = 1;
                    }
                }
            }
        }
        if (!res)
        {
            break;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
