#include<stdio.h>
#include<math.h>
#include<time.h>
#include<random>

double E0, E1, ans, state;

double energy()
{
    return 0.0;
}

void Simulate_Anneal(double beginT = 5000, double endT = 1e-8, double changeT = 0.92)
{
    E0 = energy();
    for(double T = beginT; T > endT; T *= changeT)
    {
        state += 0.1;//change state
        E1 = energy();
        if(E1 < E0)
        {
            E0 = E1;
        }
        else
        {
            if(exp((E0 - E1) / T) * RAND_MAX < rand())
                state -= 0.1; //change state back
        }
    }
}

void solve(int ctrl = 10)
{
    ans = 100.0; //INF
    while(ctrl--)
    {
        Simulate_Anneal();
        if(E0 < ans) ans = E0;
    }
}

main()
{
    srand(time(0));
}