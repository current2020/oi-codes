#include<stdio.h>

typedef long long ll;

ll exgcd(ll a, ll b, ll& x, ll& y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll g = exgcd(b, a%b, y, x);
    y = y - (a/b) * x;
    return g;
}

int main(int argc, char const *argv[])
{
    ll a, b, x, y, gcd;
    scanf("%ld%ld", &a, &b);
    gcd = exgcd(a, b, x, y);
    printf("gcd: %ld\nx: %ld, y: %ld\n", gcd, x, y);
    return 0;
}
