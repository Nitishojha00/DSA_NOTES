// Time Complexity --> O(n log log(n) )   Dry Run to Understand 
// Space Complexity --> O(n) -> isPrime vector 

#include<bits/stdc++.h>
using namespace std;

const int n = 1e6+10;
vector<bool>isPrime(n,1);  // consider all number prime 


void sieve()
{
    isPrime[0] = isPrime[1] = 0;  // Marked 0,1 as Non Prime
    for(int i=2;i*i<n;i++)    // i*i because 1 factor always lie less than or equal to square root of any number
    {
        if(isPrime[i])  // whenever the number is prime we mark all factor of its to non prime 
        {
            for(int j=i*i;j<n;j+=i)
            {
                isPrime[j] = 0; 
            }
        }
        else   
          continue;
    }
}

int main()
{
   sieve();
   for(int i=0;i<n;i++)
   {
     cout<<i<<"--->"<<(isPrime[i]==1?"Prime":"Not Prime")<<endl;
   }
}