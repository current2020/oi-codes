#include<string.h>
#include<stdio.h>
#include<queue>

using namespace std;

const int MAXN = 100005;
const int MAXM = 200005;
int last[MAXN], nxt[MAXM], ver[MAXM], w[MAXM], cnt;
int dis[MAXN], vis[MAXN];
priority_queue<pair<int, int> > pq;

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

void add(int x, int y, int z = 0)
{
    nxt[++cnt] = last[x];
    last[x] = cnt;
    ver[cnt] = y;
    w[cnt] = z;
}

void dijkstra(int s)
{
    int x, to;
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0x00, sizeof vis);
    dis[s] = 0;
    pq.push(make_pair(0, s));
    while(!pq.empty())
    {
        x = pq.top().second;
        pq.pop();
        if(vis[x]) continue;
        vis[x] = 1;
        for(int i = last[x]; i; i = nxt[i])
        {
            to = ver[i];
            if(!vis[to])
            {
                if(dis[to] > dis[x] + w[i])
                {
                    dis[to] = dis[x] + w[i];
                    pq.push(make_pair(-dis[to], to));
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int n = read(), m = read(), s = read(), x, y, z;
    for(int i = 1; i <= m; ++i)
    {
        x = read(), y = read(), z = read();
        add(x, y, z);
    }
    dijkstra(s);
    for(int i = 1; i <= n; ++i)
        printf("%d ", dis[i]);
    return 0;
}
