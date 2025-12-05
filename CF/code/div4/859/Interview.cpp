#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 7;

void solve()
{
    int n;
    scanf("%lld", &n);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }

    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + a[i];
    }

    int left = 1, right = n;
    while (left < right)
    {
        int mid = (left + right) / 2;
        int k = mid - left + 1;

        printf("? %lld ", k);
        for (int i = left; i <= mid; i++)
        {
            printf("%lld ", i);
        }
        printf("\n");  
        fflush(stdout);

        int q;
        scanf("%lld", &q); 

        int res = pref[mid] - pref[left - 1];
        if (q > res)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    printf("! %lld\n", left);
    fflush(stdout); 
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    scanf("%lld", &T);
    while (T--)
    {
        solve();
    }
    return 0;
}