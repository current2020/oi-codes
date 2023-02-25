#include<stdio.h>
#include<string.h>
#include<queue>

const int SIZE = 1000005;

struct Aho_Corasick_Automaton
{
    static const int SIGMA = 26;
    static const int SIZE = 1000005;
    int ch[SIZE][SIGMA], info[SIZE], fail[SIZE], sz;

    Aho_Corasick_Automaton() { memset(ch[0], info[0] = sz = 0, sizeof ch[0]); }

    void clear() { memset(ch[0], info[0] = sz = 0, sizeof ch[0]); }

    inline int idx(char c) { return c - 'a'; }

    void insert(char* s)
    {
        int len = strlen(s + 1), u = 0, c;
        for(int i = 1; i <= len; ++i)
        {
            c = idx(s[i]);
            if(!ch[u][c])
            {
                ++sz;
                memset(ch[sz], info[sz] = fail[sz] = 0, sizeof ch[sz]);
                ch[u][c] = sz;
            }
            u = ch[u][c];
        }
        ++info[u];
    }

    void build()
    {
        std::queue<int> q;
        for(int i = 0; i < SIGMA; ++i)
            if(ch[0][i])
            {
                fail[ch[0][i]] = 0;
                q.push(ch[0][i]);
            }
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int i = 0; i < SIGMA; ++i)
                if(ch[u][i])
                {
                    fail[ch[u][i]] = ch[fail[u]][i];
                    q.push(ch[u][i]);
                }
                else
                {
                    ch[u][i] = ch[fail[u]][i];
                }
        }
    }

    int query(char* s)
    {
        int len = strlen(s + 1), ans = 0, u = 0, c;
        for(int i = 1; i <= len; ++i)
        {
            c = idx(s[i]);
            u = ch[u][c];
            for(int j = u; j && ~info[j]; j = fail[j])
            {
                ans += info[j];
                info[j] = -1;
            }
        }
        return ans;
    }
}aca;

int main(int argc, char const *argv[])
{
    int n;
    char s[SIZE];
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%s", s + 1);
        aca.insert(s);
    }
    scanf("%s", s + 1);
    aca.build();
    printf("%d\n", aca.query(s));
    return 0;
}
