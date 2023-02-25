#include<stdio.h>

const int MAXN = 500005;
const int MAXX = 1000005;
int last[MAXN], nxt[MAXX], ver[MAXX], cnt;
int lg[MAXN], dep[MAXN], fa[MAXN][20];

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

inline void swap2(int &x, int &y) { x ^= y ^= x ^= y; }

void add(int x, int y)
{
    nxt[++cnt] = last[x];
    last[x] = cnt;
    ver[cnt] = y;
}

void pre_lg(int n)
{
    for(int i = 1; i <= n; ++i)
        lg[i] = lg[i - 1] + (i == (1 << (lg[i - 1] + 1)));
}

void pre_LCA(int x, int from)
{
    int to;
    dep[x] = dep[from] + 1;
    fa[x][0] = from;
    for(int i = 1; i <= lg[dep[x]]; ++i)
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for(int i = last[x]; i; i = nxt[i])
    {
        to = ver[i];
        if(to == from) continue;;
        pre_LCA(to, x);
    }
}

int LCA(int x, int y)
{
    if(dep[y] > dep[x])
        swap2(x, y);
    while(dep[x] > dep[y])
        x = fa[x][lg[dep[x] - dep[y]]];
    if(x == y)
        return x;
    for(int i = lg[dep[x] - 1]; i>= 0; --i)
        if(fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return fa[x][0];
    return 0;
}

int main(int argc, char const *argv[])
{
    int n = read(), m = read(), s = read(), x, y;
    for(int i = 1; i < n; ++ i)
    {
        x = read(), y = read();
        add(x, y);
        add(y, x);
    }
    pre_lg(n);
    pre_LCA(s, 0);
    for(int i = 1; i <= m; ++i)
    {
        x = read(), y = read();
        printf("%d\n", LCA(x, y));
    }
    return 0;
}
