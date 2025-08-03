#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;
vector<int> primes;

// Sieve of Eratosthenes to store primes up to 1e6
void sieve() {
    vector<bool> isPrime(MAX, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < MAX; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < MAX; j += i)
                isPrime[j] = false;
        }
    }

    for (int i = 2; i < MAX; ++i)
        if (isPrime[i])
            primes.push_back(i);
}

// Function to find prime factors using precomputed primes
void primeFactorize(long long n) {
    cout << "Prime factors of " << n << " are: ";
    for (int i = 0; i < primes.size() && (1LL * primes[i] * primes[i] <= n); ++i) {
        int p = primes[i];
        if(n % p == 0) {
            cout << p << " ";
            while(n%p==0)
            n /= p;
        }
    }
    if (n > 1)
        cout << n; // n is a prime > 1e6
    cout << endl;
}

int main() {
    sieve();  // Precompute primes up to 1e6

    long long n;
    cout << "Enter a number to factorize: ";
    cin >> n;

    primeFactorize(n);

    return 0;
}
