#include<stdio.h>

typedef long long ll;
const int MAXN = 100005;
ll val[MAXN << 2], tag[MAXN << 2], a[MAXN], d;
int L, R;

void mark(int l, int r, int p, ll k)
{
    val[p] += (r - l + 1) * k;
    tag[p] += k;
}

void push_up(int p)
{
    val[p] = val[p << 1] + val[p << 1 | 1];
}

void push_down(int l, int r, int p)
{
    int mid = (l + r) >> 1;
    mark(l, mid, p << 1, tag[p]);
    mark(mid + 1, r, p << 1 | 1, tag[p]);
    tag[p] = 0;
}

void build(int l, int r, int p)
{
    if(l == r)
    {
        val[p] = a[l];
        tag[p] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1 | 1);
    push_up(p);
}

void upd(int l, int r, int p)
{
    if(L <= l && r <= R)
    {
        mark(l, r, p, d);
        return;
    }
    push_down(l, r, p);
    int mid = (l + r) >> 1;
    if(L <= mid) upd(l, mid, p << 1);
    if(R > mid) upd(mid + 1, r, p << 1 | 1);
    push_up(p);
}

ll qry(int l, int r, int p)
{
    if(L <= l && r <= R) return val[p];
    ll res = 0;
    push_down(l, r, p);
    int mid = (l + r) >> 1;
    if(L <= mid) res += qry(l, mid, p << 1);
    if(R > mid) res += qry(mid + 1, r, p << 1 | 1);
    return res;
}

int main(int argc, char const *argv[])
{
    int n, m, q;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%lld", a + i);
    build(1, n, 1);
    for(int i = 1; i <= m; ++i)
    {
        scanf("%d", &q);
        if(q == 1)
        {
            scanf("%d%d%lld", &L, &R, &d);
            upd(1, n, 1);
        }
        else
        {
            scanf("%d%d", &L, &R);
            printf("%lld\n", qry(1, n, 1));
        }
    }
    return 0;
}