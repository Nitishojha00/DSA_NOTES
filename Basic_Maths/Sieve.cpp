// Time Complexity --> O(n log log(n) )   Dry Run to Understand 
// Space Complexity --> O(n) -> isPrime vector 

#include<bits/stdc++.h>
using namespace std;


const int n = 1e6+10;


vector<bool> sieve()
{
    vector<bool>isPrime(n,1);  // consider all number prime 
    isPrime[0] = isPrime[1] = 0;
    for(int i=2;i*i<=n;i++)
    {
        if(isPrime[i])
        {
            for(int j=i*i;j<=n;j+=i)
            {
                isPrime[j] = 0;
            }
        }
    }

    return isPrime;
}

int main()
{
    vector<bool>isPrime = sieve();
   for(int i=0;i<n;i++)
   {
     cout<<i<<"--->"<<(isPrime[i]==1?"Prime":"Not Prime")<<endl;
   }
}