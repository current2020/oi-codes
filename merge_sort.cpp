#include<stdio.h>
#include<algorithm>

const int MAXN = 100005;
int a[MAXN], b[MAXN];

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

void sort(int l, int r)
{
    if(l + 1 >= r) return;
    int mid = (l + r) >> 1;
    sort(l, mid);
    sort(mid, r);
    int p = l, q = mid, k = l;
    while(p < mid || q < r)
    {
        if(p == mid) { b[k++] = a[q++]; continue; }
        if(q == r) { b[k++] = a[p++]; continue; }
        if(a[p] <= a[q]) b[k++] = a[p++];
        else b[k++] = a[q++];
    }
    for(int i = l; i < r; ++i) a[i] = b[i];
    return;
}

int main(int argc, char const *argv[])
{
    int n = read();
    for(int i = 1; i <= n; ++i) a[i] = read();
    sort(1, n + 1);
    for(int i = 1; i <= n; ++i) printf("%d ", a[i]);
    return 0;
}