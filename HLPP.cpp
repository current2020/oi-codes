#include<stdio.h>
#include<utility>
#include<queue>

using std::queue;
using std::priority_queue;
using std::pair;
using std::make_pair;

typedef long long ll;
const int MAXN = 205;
const int MAXH = 405;
const int MAXM = 10005;
const ll INF = 1e18;
int last[MAXN], nxt[MAXM], ver[MAXM], cnt;
ll c[MAXM], f[MAXM], tot_c[MAXN][MAXN], ans;
int level[MAXN], gap[MAXH], inq[MAXN];
ll left[MAXN];
int n, m, s, t;
priority_queue<pair<int, int>> q;

ll min(ll a, ll b) { return a < b ? a : b; }

void add_edge(int x, int y)
{
    nxt[++cnt] = last[x];
    last[x] = cnt;
    ver[cnt] = y;
    c[cnt] = tot_c[x][y];
}

void bfs()
{
    queue<int> q;
    for(int i = 1; i <= n; ++i)
        level[i] = -1;
    gap[level[t] = 0] = 1;
    q.push(t);
    while(!q.empty())
    {
        int x = q.front(), y;
        q.pop();
        for(int i = last[x]; i; i = nxt[i])
        {
            if(f[i^1] == c[i^1]) continue;
            y = ver[i];
            if(level[y] >= 0) continue;
            ++gap[level[y] = level[x] + 1];
            q.push(y);
        }
    }
    level[s] = n;
}

void relabel(int x)
{
    if(--gap[level[x]] == 0)
    {
        for(int i = 1; i <= n; ++i)
        {
            if(i == s || i == t) continue;
            if(level[i] < level[x] || level[i] > n) continue;
            level[i] = n + 1;
        }
    }
    level[x] = n<<1;
    for(int i = last[x]; i; i = nxt[i])
    {
        if(f[i] == c[i]) continue;
        int y = ver[i];
        level[x] = min(level[x], level[y] + 1);
    }
    ++gap[level[x]];
}

void push(int x)
{
    for(int i = last[x]; i; i = nxt[i])
    {
        if(f[i] == c[i]) continue;
        int y = ver[i];
        if(level[y] != level[x] - 1) continue;
        ll dflow = min(left[x], c[i] - f[i]);
        f[i] += dflow;
        f[i^1] -= dflow;
        left[y] += dflow;
        left[x] -= dflow;
        if(!inq[y] && y != s && y != t)
        {
            q.push(make_pair(level[y], y));
            inq[y] = 1;
        }
        if(left[x] == 0) return;
    }
    relabel(x);
    q.push(make_pair(level[x], x));
    inq[x] = 1;
}

ll HLPP()
{
    bfs();
    for(int i = last[s]; i; i = nxt[i])
    {
        if(f[i] == c[i]) continue;
        int y = ver[i];
        ll dflow = c[i] - f[i];
        f[i] += dflow;
        f[i^1] -= dflow;
        left[y] += dflow;
        if(!inq[y] && y != s && y != t)
        {
            q.push(make_pair(level[y], y));
            inq[y] = 1;
        }
    }
    while(!q.empty())
    {
        int x = q.top().second;
        q.pop();
        inq[x] = 0;
        push(x);
    }
    return left[t];
}

int main()
{
    int u, v; ll w;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for(int i = 1; i <= m; ++i)
    {
        scanf("%d%d%lld", &u, &v, &w);
        tot_c[u][v] += w;
    }
    add_edge(0, 0);
    for(int i = 1; i <= n; ++i)
    {
        for(int j = i+1; j <= n; ++j)
        {
            if(tot_c[i][j] > 0 || tot_c[j][i] > 0)
            {
                add_edge(i, j);
                add_edge(j, i);
            }
        }
    }
    printf("%lld\n", HLPP());
    return 0;
}