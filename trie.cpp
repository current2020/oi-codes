#include<stdio.h>
#include<string.h>

const int MAXS = 55;

struct trie
{
    static const int MAXSIZE = 500005;
    static const int MAXSIGMA = 26;
    int ch[MAXSIZE][MAXSIGMA], info[MAXSIZE], sz;

    trie() { memset(ch[0], info[0] = sz = 0, sizeof ch[0]); }

    inline int idx(char c) { return c - 'a'; }

    int insert(char* s)
    {
        int len = strlen(s + 1), u = 0, c;
        for(int i = 1; i <= len; ++i)
        {
            c = idx(s[i]);
            if(!ch[u][c])
            {
                ++sz;
                memset(ch[sz], info[sz] = 0, sizeof info[sz]);
                ch[u][c] = sz;
            }
            u = ch[u][c];
        }
        info[u] = 1;
        return u;
    }

    int find(char* s)
    {
        int len = strlen(s + 1), u = 0, c;
        for(int i = 1; i <= len; ++i)
        {
            c = idx(s[i]);
            if(!ch[u][c])
                return 0;
            u = ch[u][c];
        }
        return u;
    }
} nameList;

int main(int argc, char const *argv[])
{
    int n, m;
    char s[MAXS];
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%s", s + 1);
        nameList.insert(s);
    }
    scanf("%d", &m);
    for(int i = 1; i <= m; ++i)
    {
        scanf("%s", s + 1);
        int u = nameList.find(s);
        if(u == 0 || nameList.info[u] == 0)
        {
            puts("WRONG");
        }
        else if(nameList.info[u] == 1)
        {
            puts("OK");
            ++nameList.info[u];
        }
        else
        {
            puts("REPEAT");
        }
    }
    return 0;
}
