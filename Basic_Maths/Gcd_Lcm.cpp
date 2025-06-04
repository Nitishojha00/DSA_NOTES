// T.C ->  O(log min(a, b))
// S.C -> O(1)

#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)  //  recursive it take space O(log min(a, b)) -> (due to call stack)
{
    if(!b)  return a;

    return gcd(b,a%b);
}

int main()
{
   cout<<gcd(8,10); 
   //  Built_In Method
   cout<<__gcd(8,20);  
}