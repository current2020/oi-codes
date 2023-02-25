#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

typedef unsigned long long ull;
const int MAXN = 10005;
const int MAXM = 1505;
const ull MOD1 = 19260817;
const ull MOD2 = 19660813;
ull BASE1[MAXM], BASE2[MAXM];

static void init()
{
    BASE1[0] = BASE2[0] = 1;
    for(int i = 1; i <= 1500; ++i)
    {
        BASE1[i] = BASE1[i - 1] * 127 % MOD1;
        BASE2[i] = BASE2[i - 1] * 127 % MOD2;
    }
}

struct hash
{
    ull hash1, hash2;

    hash() { hash1 = hash2 = 0; }

    bool operator < (const hash& b)
    {
        if(this->hash1 < b.hash1) return 1;
        if(this->hash1 > b.hash1) return 0;
        return this->hash2 < b.hash2;
    }

    hash operator = (const string& s)
    {
        int len = s.length();
        this->hash1 = this->hash2 = 0;
        for(int i = 0; i < len; ++i)
        {
            this->hash1 = (this->hash1 + s[i] * BASE1[i]) % MOD1;
            this->hash2 = (this->hash2 + s[i] * BASE2[i]) % MOD2;
        }
        return *this;
    }

    bool operator != (const hash& b)
    {
        return this->hash1 != b.hash1 || this->hash2 != b.hash2;
    }
}a[MAXN];

int main(int argc, char const *argv[])
{
    int n, cnt = 1;
    string s;
    cin >> n;
    init();
    for(int i = 1; i <= n; ++i)
    {
        cin >> s;
        a[i] = s;
    }
    sort(a + 1, a + n + 1);
    for(int i = 2; i <= n; ++i)
        if(a[i] != a[i - 1])
            ++cnt;
    printf("%d\n", cnt);
    return 0;
}
