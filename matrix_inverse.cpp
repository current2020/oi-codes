#include<stdio.h>

const int MAXN = 405;
double a[MAXN][MAXN << 1];

inline void swap(double& x, double& y)
{
    double t = x;
    x = y;
    y = t;
}

void test(int n)
{
    puts("");
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n << 1; ++ j)
            printf("%.3lf ", a[i][j]);
        puts("");
    }
    puts("");
}

float abs(float x) { return x > 0 ? x : -x; }

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            scanf("%lf", &a[i][j]);
    for(int i = 1; i <= n; ++i)
        a[i][n + i] = 1;
    for(int j = 1; j <= n; ++j)
    {
        int maxi = j;
        for(int i = j; i <= n; ++i)
            if(abs(a[i][j]) > abs(a[maxi][j]))
                maxi = i;
        if(a[maxi][j] == 0.0)
        {
            puts("No Solution");
            return 0;
        }
        if(maxi != j)
            for(int k = 1; k <= (n << 1); ++k)
                swap(a[j][k], a[maxi][k]);
        for(int i = 1; i <= n; ++i)
        {
            if(i == j) continue;
            double tmp = a[i][j] / a[j][j];
            for(int k = 1; k <= (n << 1); ++k)
            {
                a[i][k] = a[i][k] - a[j][k] * tmp;
            }
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
            printf("%.5lf ", a[i][n + j] / a[i][i]);
        puts("");
    }
    return 0;
}
