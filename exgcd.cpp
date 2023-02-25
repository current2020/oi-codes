#include<stdio.h>

typedef long long ll;
const int MAXN = 1005;
const ll P = 998244353;
ll p[MAXN][MAXN];

void exgcd(ll a, ll b, ll& x, ll& y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a % b, x, y);
    ll t = x;
    x = y;
    y = t - (a / b) * x;
}
int main(int argc, char const *argv[])
{
    p[0][0] = 1;
    int n, m, k;
    ll inv, tmp, ans = 0;
    scanf("%d%d%d", &n, &m, &k);
    exgcd(m, P, inv, tmp);
    inv = (inv % P + P) % P;
    for(int t = 1; t <= k; ++t)
    {
        for(int i = 1; i <= n; ++i)
        {
            for(int k = i - m; k < i; ++k)
            {
                if(k < 0) continue;
                p[i][t] = (p[i][t] + p[k][t - 1] * inv % P) % P;
            }
            if(i >= n - m + 1 && i < n)
            {
                for(int k = n + n - m - i; k < n; ++k)
                    p[i][t] = (p[i][t] + p[k][t - 1] * inv % P) % P;
            }
        }
        ans = (ans + p[n][t]) % P;
    }
    printf("%lld\n", ans);
    return 0;
}
