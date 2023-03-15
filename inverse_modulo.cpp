#include<stdio.h>

typedef long long ll;
const int MAXN = 3000005;
ll inv[MAXN], P;

inline void calc(int n)
{
    inv[1] = 1;
    for(int i = 2; i <= n; ++i)
        inv[i] = (P - P/i) * inv[P%i] % P;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d%lld", &n, &P);
    calc(n);
    for(int i = 1; i <= n; ++i)
        printf("%lld\n", inv[i]);
    return 0;
}
