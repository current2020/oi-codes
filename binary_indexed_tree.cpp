#include<stdio.h>

const int MAXN = 500005;
int a[MAXN], c[MAXN];

inline int lowbit(int x) { return x & (-x); }

void build(int n)
{
    for(int i = 1; i <= n; ++i)
        for(int j = i - lowbit(i) + 1; j <= i; ++j)
            c[i] += a[j];
}

void add(int p, int d, int n) { for(int i = p; i <= n; i += lowbit(i)) c[i] += d; }

int query(int x)
{
    int res = 0;
    while(x > 0)
    {
        res += c[x];
        x -= lowbit(x);
    }
    return res;
}

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-') f = 0;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return f ? x : -x;
}

int main(int argc, char const *argv[])
{
    int n = read(), m = read(), q, x, y;
    for(int i = 1; i <= n; ++i) a[i] = read();
    build(n);
    while(m--)
    {
        q = read(), x = read(), y = read();
        if(q == 1)
        {
            add(x, y, n);
        }
        else
        {
            printf("%d\n", query(y) - query(x - 1));
        }
    }
    return 0;
}