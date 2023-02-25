#include<stdio.h>

const int MAXN = 10005;
int fa[MAXN];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

int main(int argc, char const *argv[])
{
    int n, m, q, x, y;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
        fa[i] = i;
    for(int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &q, &x, &y);
        if(q == 1)
            fa[find(y)] = find(x);
        else
            puts(find(x) == find(y) ? "Y" : "N");
    }
    return 0;
}
