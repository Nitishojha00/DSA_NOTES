// Find nCr = n!/(n-r)!(r)!

// we precompute factorial 👌👌👌👌

// it not valid if -> 

// what if factorial goes very large and we have to do modulo but ->

// (a/b)%m != ((a%m)/(b%m))%m  ✅  -> we cant say that

// (a/b) =>
// (b inverse = pow(b,-1)) 
// Now -> 
//  ((a%m)*(b inverse)%m)%m we can find ✅

//  if m is odd generally ->
 
 
//  b inverse  = pow(b,m-2)%m   


// simple hai always remember that line ✅

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;  // Change this as per problem's maximum n

long long factorial[MAX];

// Step 1: Precompute all factorials % MOD
void computeFactorials() {
    factorial[0] = 1;
    for (int i = 1; i < MAX; i++) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
}

// Step 2: Binary exponentiation to compute (a^b) % MOD
long long power(long long a, long long b) {
    long long result = 1;
    a = a % MOD;
    while (b > 0) {
        if (b % 2)
            result = (result * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return result;
}

// Step 3: Modular Inverse using Fermat's Little Theorem
long long modInverse(long long a) {
    return power(a, MOD - 2);
}

// Step 4: Compute nCr % MOD
long long nCr(int n, int r) {
    if (r > n) return 0;
    long long numerator = factorial[n];
    long long denominator = (factorial[r] * factorial[n - r]) % MOD;
    return (numerator * modInverse(denominator)) % MOD;
}

// 🔽 Driver code to test
int main() {
    computeFactorials();

    int n = 1e6, r = 500000;
    cout << "nCr(" << n << ", " << r << ") mod " << MOD << " = " << nCr(n, r) << endl;

    return 0;
}
