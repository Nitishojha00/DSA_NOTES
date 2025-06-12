#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7 + 5;
vector<int> spf(MAXN);        // Smallest Prime Factor
vector<int> primes;           // All primes ≤ N

void linearSieve(int N) {
    for (int i = 2; i <= N; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }

        for (int j = 0; j < primes.size() && primes[j] <= spf[i] && i * primes[j] <= N; j++) {
            spf[i * primes[j]] = primes[j];
        }
    }
}


void factorize(int x) {
    while (x > 1) {
        cout << spf[x] << " ";
        x /= spf[x];
    }
    cout << "\n";
}

int main() {
    int N = 10000000;  // Up to 1e7
    linearSieve(N);

    int x;
    cout << "Enter number to factorize: ";
    cin >> x;
    factorize(x);  // Print its prime factors using SPF

    return 0;
}
