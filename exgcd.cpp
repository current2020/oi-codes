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
    ll gcd = exgcd(b, a % b, x, y);
    ll t = x;
    x = y;
    y = t - (a / b) * x;
    return gcd;
}

int main(int argc, char const *argv[])
{
    ll a, b, x, y, gcd;
    scanf("%ld%ld", &a, &b);
    gcd = exgcd(a, b, x, y);
    printf("gcd: %ld\nx: %ld, y: %ld\n", gcd, x, y);
    return 0;
}
