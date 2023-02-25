#include<stdio.h>

const int MAXN = 100005;
int lg[MAXN], st[MAXN << 1][20];

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

inline int max(int x, int y) { return x > y ? x : y; }

void get_log(int n)
{
    for(int i = 2; i <= n; ++i)
        lg[i] = lg[i - 1] + (1 << (lg[i - 1] + 1) == i);
}

void init(int n)
{
    get_log(n);
    for(int i = 1; i <= n; ++i)
        st[i][0] = read();
    for(int j = 1; j <= lg[n]; ++j)
        for(int i = 1; i <= n; ++i)
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

inline int qry(int l, int r) { return max(st[l][lg[r - l + 1]], st[r + 1 - (1 << lg[r - l + 1])][lg[r - l + 1]]); }

int main(int argc, char const *argv[])
{
    int n = read(), m = read(), l, r;
    init(n);
    while(m--)
    {
        l = read(), r = read();
        printf("%d\n", qry(l, r));
    }
    return 0;
}