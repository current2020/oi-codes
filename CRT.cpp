#include<stdio.h>

typedef long long ll;
const int MAXN = 15;
ll a[MAXN], b[MAXN], m[MAXN], t[MAXN], M = 1;

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
    int n;
    ll tmp, ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%ld %ld", b + i, a + i);
        M *= b[i];
    }
    for(int i = 1; i <= n; ++i)
    {
        m[i] = M / b[i];
        exgcd(m[i], b[i], t[i], tmp);
        t[i] = (t[i] % b[i] + b[i]) % b[i];
        ans = (ans + a[i] * m[i] * t[i] % M) % M;
    }
    printf("%ld\n", ans);
    return 0;
}
