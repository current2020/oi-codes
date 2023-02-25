#include<stdio.h>
#include<string.h>

const int MAXS = 1000005;
char t[MAXS], s[MAXS];
int border[MAXS];

void get_border()
{
    int len = strlen(t + 1);
    for(int i = 2, j = 0; i <= len; ++i)
    {
        while(j && t[j + 1] != t[i])
            j = border[j];
        if(t[j + 1] == t[i])
            ++j;
        border[i] = j;
    }
}

void match()
{
    int len = strlen(s + 1), end = strlen(t + 1);
    for(int i = 1, j = 0; i <= len; ++i)
    {
        while(j && s[i] != t[j + 1])
            j = border[j];
        if(s[i] == t[j + 1])
        {
            if(++j == end)
                printf("%d\n", i - end + 1);
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%s%s", s + 1, t + 1);
    get_border();
    match();
    int len = strlen(t + 1);
    for(int i = 1; i <= len; ++i)
        printf("%d ", border[i]);
    return 0;
}
