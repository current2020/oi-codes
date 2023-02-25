#include<stdio.h>

typedef long long ll;
const ll P = 1000000009;

inline ll llread()
{
    ll x = 0;
    bool f = 1;
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
    return f ? x : -1;
}

struct matrix
{
    const static int size = 2;
    ll a[size + 1][size + 1];

    matrix()
    {
        for(int i = 1; i <= size; ++i)
            for(int j = 1; j <= size; ++j)
                a[i][j] = 0;
    }

    void clear()
    {
        for(int i = 1; i <= size; ++i)
            for(int j = 1; j <= size; ++j)
                a[i][j] = 0;
    }

    void unitize()
    {
        for(int i = 1; i <= size; ++i)
            for(int j = 1; j <= size; ++j)
                a[i][j] = (i == j);
    }

    matrix operator * (const matrix& b)
    {
        matrix res;
        for(int i = 1; i <= size; ++i)
            for(int j = 1; j <= size; ++j)
                for(int k = 1; k <= size; ++k)
                    res.a[i][j] = (res.a[i][j] +  a[i][k] * b.a[k][j] % P) % P;
        return res;
    }

    void print()
    {
        for(int i = 1; i <= size; ++i)
        {
            for(int j = 1; j <= size; ++j)
                printf("%d ", a[i][j]);
            puts("");
        }
    }

    void get()
    {
        for(int i = 1; i <= size; ++i)
            for(int j = 1; j <= size; ++j)
                a[i][j] = llread();
    }

    friend matrix pow(matrix x, int y)
    {
        matrix res;
        res.unitize();
        while(y)
        {
            if(y & 1)
                res = res * x;
            x = x * x;
            y >>= 1;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    matrix x, y, z;
    x.get();
    puts("");
    y.get();
    puts("");
    z = x * y;
    z.print();
    return 0;
}
