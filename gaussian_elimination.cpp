#include<stdio.h>
#include<math.h>

const int MAXN = 105;
const double EPS = 1e-8;
double a[MAXN][MAXN];

inline void swap(double& a, double& b)
{
    double tmp = a;
    a = b;
    b = tmp;
}

void test_output(int n)
{
    puts("");
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n + 1; ++j)
            printf("%.2lf ", a[i][j]);
        printf("\n");
    }
    puts("");
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n + 1; ++j)
            scanf("%lf", &a[i][j]);
    for(int j = 1; j <= n; ++j)
    {
        int maxi = 0;
        for(int i = j; i <= n; ++i)
        {
            if(fabs(a[i][j]) > fabs(a[maxi][j]) + EPS)
                maxi = i;
        }
        if(maxi == 0)
        {
            puts("No Solution");
            return 0;
        }
        if(maxi != j)
        {
            for(int k = 1; k <= n + 1; ++k)
                swap(a[j][k], a[maxi][k]);
        }
        for(int i = 1; i <= n; ++i)
        {
            if(i == j) continue;
            double d = a[i][j] / a[j][j];
            for(int k = 1; k <= n + 1; ++k)
                a[i][k] -= a[j][k] * d;
        }
    }
    for(int i = 1; i <= n; ++i)
        printf("%.2lf\n", a[i][n + 1] / a[i][i]);
    return 0;
}
