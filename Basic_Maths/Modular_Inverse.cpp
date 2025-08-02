class Solution {
  public:
 
  int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
    }

    int modInverse(int n, int m) {
        // code here
        int val = gcd(n,m);
        if(val!=1) return -1; // no factors available
        
        for(int i=1;i<1e6;i++)
        {
            if((n*i)%m==1)  return i;
        }

        return -1;
    }
};
// a.x%b==1  find x such that expressione follow 
// example when not exist n = 3 , m = 9
//  gcd(3,9) = 3
// here gcd is not 1 means not exist modular inverse
