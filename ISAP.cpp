#include<stdio.h>
#include<queue>

using std::queue;

typedef long long ll;
const int MAXN = 205;
const int MAXM = 10005;
const ll INF = 1e18;
int last[MAXN], nxt[MAXM], ver[MAXM], cnt;
ll c[MAXM], f[MAXM], tot_c[MAXN][MAXN], ans;
int level[MAXN], gap[MAXN], cur[MAXN];
int n, m, s, t;

ll min(ll a, ll b) { return a < b ? a : b; }

void add_edge(int x, int y)
{
    nxt[++cnt] = last[x];
    last[x] = cnt;
    ver[cnt] = y;
    c[cnt] = tot_c[x][y];
}

bool bfs()
{
    queue<int> q;
    for(int i = 1; i <= n; ++i)
    {
        level[i] = -1;
        gap[i] = 0;
    }
    gap[level[t] = 0] = 1;
    q.push(t);
    while(!q.empty())
    {
        int x = q.front(), y;
        q.pop();
        for(int i = last[x]; i; i = nxt[i])
        {
            y = ver[i];
            if(level[y] >= 0) continue;
            ++gap[level[y] = level[x] + 1];
            q.push(y);
        }
    }
    return level[s] >= 0;
}

ll dfs(int x, ll maxflow)
{
    if(x == t) return maxflow;
    ll flow = 0, dflow;
    for(int i = cur[x]; i; i = nxt[i])
    {
        cur[x] = i;
        int y = ver[i];
        if(level[x] != level[y] + 1) continue;
        if(f[i] == c[i]) continue;
        dflow = dfs(y, min(maxflow - flow, c[i] - f[i]));
        flow += dflow;
        f[i] += dflow;
        f[i^1] -= dflow;
        if(flow == maxflow) return flow;
    }
    if(--gap[level[x]] == 0) level[s] = n;
    ++gap[++level[x]];
    return flow;
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
    bfs();
    while(level[s] < n)
    {
        for(int i = 1; i <= n; ++i)
            cur[i] = last[i];
        ans += dfs(s, INF);
    }
    printf("%lld\n", ans);
    return 0;
}