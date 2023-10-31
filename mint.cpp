#include<stdio.h>

using ll = long long;

void exgcd(ll a, ll b, ll& x, ll& y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a%b, y, x);
    y = y - (a/b) * x;
}

struct mint
{
    const static ll P = 1000000007;
    const static int N = 100005;
    static ll inv[N];
    static int n;
    ll val;

    static void calc_inv_until_k(int k)
    {
        while(n < k)
        {
            ++n;
            inv[n] = (P - P/n) * inv[P%n] % P;
        }
    }

    static ll calc_inv_of_k(ll k)
    {
        ll res, tmp;
        exgcd(k, P, res, tmp);
        return (res%P + P)%P;
    }

    mint() : val{0} {}
    mint(ll x) : val{x%P} {}

    mint& operator=(ll rhs)
    {
        val = rhs%P;
        return *this;
    }

    mint operator+(ll rhs) const { return mint{this->val + rhs}; }

    mint operator+(const mint& rhs) const { return mint{this->val + rhs.val}; }

    mint operator-(ll rhs) const { return mint{this->val - rhs + P}; }

    mint operator-(const mint& rhs) const { return mint{this->val - rhs.val + P}; }

    mint operator*(ll rhs) const { return mint{this->val * rhs}; }

    mint operator*(const mint& rhs) const { return mint{this->val * rhs.val}; }

    mint operator/(ll rhs) const
    {
        if(rhs > n) calc_inv_until_k(rhs);
        return mint{this->val * inv[rhs]};
    }

    mint operator/(const mint& rhs) const { return (*this)/rhs.val; }

    mint operator%(ll rhs) const { return mint{this->val * calc_inv_of_k(rhs)}; }

    mint operator%(const mint& rhs) const { return (*this)%rhs.val; }

    mint& operator+=(ll rhs)
    {
        this->val = (this->val + rhs)%P;
        return *this;
    }

    mint& operator+=(const mint& rhs) { return this->operator+=(rhs.val); }

    mint& operator-=(ll rhs)
    {
        this->val = (this->val - rhs + P)%P;
        return *this;
    }

    mint& operator-=(const mint& rhs) { return this->operator-=(rhs.val); }

    mint& operator*=(ll rhs)
    {
        this->val = (this->val * rhs)%P;
        return *this;
    }

    mint& operator*=(const mint& rhs) { return this->operator*=(rhs.val); }

    mint& operator/=(ll rhs) { return ((*this) = (*this) / rhs); }

    mint& operator/=(const mint& rhs) { return ((*this) = (*this) / rhs); }

    mint& operator%=(ll rhs) { return ((*this) = (*this) % rhs); }

    mint& operator%=(const mint& rhs) { return ((*this) = (*this) % rhs); }

    mint& operator++()
    {
        val = (val + 1)%P;
        return *this;
    }

    mint operator++(int)
    {
        mint tmp{val};
        val = (val + 1)%P;
        return tmp;
    }

    mint& operator--()
    {
        val = (val == 0) ? P-1 : val-1;
        return *this;
    }

    mint operator--(int)
    {
        mint tmp{val};
        val = (val == 0) ? P-1 : val-1;
        return tmp;
    }
};
ll mint::inv[] = {0, 1};
int mint::n{1};

int main()
{
    mint a{1614556}, b{41165};
    printf("%lld\n", (a/b).val);
    return 0;
}