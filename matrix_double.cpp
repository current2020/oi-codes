#include<stdio.h>

struct matrix
{
    const static int size = 3;
    double a[size + 1][size + 1];

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
                    res.a[i][j] = res.a[i][j] +  a[i][k] * b.a[k][j];
        return res;
    }

    void print()
    {
        for(int i = 1; i <= size; ++i)
        {
            for(int j = 1; j <= size; ++j)
                printf("%.4lf ", a[i][j]);
            puts("");
        }
    }

    void get()
    {
        for(int i = 1; i <= size; ++i)
            for(int j = 1; j <= size; ++j)
                scanf("%lf", &a[i][j]);
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
