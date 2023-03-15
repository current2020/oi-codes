#include<stdio.h>

inline int read()
{
    int x = 0;
    char ch = getchar();
    while(ch < '0' || ch > '9')
        ch = getchar();
    while(ch >= '0' && ch <= '9')
    {
        x = x*10 + ch - '0';
        ch = getchar();
    }
    return x;
}

inline int read2()
{
    int x = 0;
    bool f = true;
    char ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-') f = false;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        x = x*10 + ch - '0';
        ch = getchar();
    }
    return f ? x : -x;
}

int main()
{
    int x = read();
    printf("%d\n", x);
    return 0;
}