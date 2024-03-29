#include<stdio.h>

const int MAXN = 500005;
int a[MAXN], c[MAXN], n;

inline int lowbit(int x) { return x&(-x); }

void add(int x, int d)
{
    while(x <= n)
    {
        c[x] += d;
        x += lowbit(x);
    }
}

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

void build()
{
    for(int i = 1; i <= n; ++i)
        add(i, a[i]);
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
    n = read();
    int m = read(), q, x, y;
    for(int i = 1; i <= n; ++i) a[i] = read();
    build();
    while(m--)
    {
        q = read(), x = read(), y = read();
        if(q == 1) add(x, y);
        else printf("%d\n", query(y) - query(x - 1));
    }
    return 0;
}