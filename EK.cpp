#include<stdio.h>
#include<queue>

using std::queue;

typedef long long ll;
const int MAXN = 205;
const int MAXM = 10005;
const ll INF = 1e18;
int last[MAXN], nxt[MAXM], ver[MAXM], cnt;
ll c[MAXM], f[MAXM], tot_c[MAXN][MAXN], ans;
int pre[MAXN]; ll dis[MAXN];
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
        pre[i] = 0;
    dis[s] = INF;
    pre[s] = -1;
    q.push(s);
    while(!q.empty())
    {
        int x = q.front(), y;
        q.pop();
        for(int i = last[x]; i; i = nxt[i])
        {
            if(f[i] == c[i]) continue;
            y = ver[i];
            if(pre[y]) continue;
            pre[y] = i;
            dis[y] = min(dis[x], c[i] - f[i]);
            if(y == t) return true;
            q.push(y);
        }
    }
    return false;
}

void update()
{
    int cur = t, e;
    while(cur != s)
    {
        e = pre[cur];
        f[e] += dis[t];
        f[e^1] -= dis[t];
        cur = ver[e^1];
    }
    ans += dis[t];
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
    while(bfs()) update();
    printf("%lld\n", ans);
    return 0;
}