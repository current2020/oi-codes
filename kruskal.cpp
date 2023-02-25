#include<algorithm>
#include<stdio.h>

using namespace std;

const int MAXN = 5005;
const int MAXM = 200005;

struct edge
{
    int x, y, w;

    void set(int a, int b, int c) { x = a, y = b, w = c; }

    bool operator < (const edge& b) { return this->w < b.w; }
}a[MAXM];

int fa[MAXN];

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

int find(int x)
{
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y)
{
    fa[find(x)] = find(y);
}

int main(int argc, char const *argv[])
{
    int n = read(), m = read(), x, y, z;
    for(int i = 1; i <= n; ++i)
        fa[i] = i;
    for(int i = 1; i <= m; ++i)
    {
        x = read(), y = read(), z = read();
        a[i].set(x, y, z);
    } 
    sort(a + 1, a + m + 1);
    int cnt = 1, tot = 0;
    for(int i = 1; i <= m; ++i)
    {
        if(find(a[i].x) == find(a[i].y)) continue;
        merge(a[i].x, a[i].y);
        tot += a[i].w;
        if(++cnt == n) break;
    }
    if(cnt == n) printf("%d\n", tot);
    else puts("orz");
    return 0;
}