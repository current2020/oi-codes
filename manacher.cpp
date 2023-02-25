#include<string.h>
#include<stdio.h>

const int MAXN = 30000005;
char s[MAXN], ms[MAXN];
int p[MAXN];

inline int min(int x, int y) { return x < y ? x : y; }

int change()
{
    int len1 = strlen(s), len2 = 1;
    ms[0] = '~';
    for(int i = 0; i < len1; ++i)
    {
        ms[len2++] = '|';
        ms[len2++] = s[i];
    }
    ms[len2++] = '|';
    return len2;
}

int manacher()
{
    int len = change(), mid = 0, r = 0, ans = 0;
    for(int i = 1; i < len; ++i)
    {
        if(i <= r) p[i] = min(p[(mid << 1) - i], r - i);
        while(ms[i - p[i] - 1] == ms[i + p[i] + 1]) ++p[i];
        if(i + p[i] >= r) mid = i, r = i + p[i];
        if(p[i] > ans) ans = p[i];
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    scanf("%s", s);
    printf("%d\n", manacher());
    return 0;
}
