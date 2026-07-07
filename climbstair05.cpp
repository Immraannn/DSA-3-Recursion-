#include<iostream>
using namespace std;

int climbStairs(int nstair)
{
    // Base cases
    if(nstair==0)
        return 1;

    if(nstair<0)
        return 0;

    return climbStairs(nstair-1) + climbStairs(nstair-2);
}

int main()
{
    int nstair;
    cin>>nstair;

    cout<<climbStairs(nstair);

    return 0;
}
