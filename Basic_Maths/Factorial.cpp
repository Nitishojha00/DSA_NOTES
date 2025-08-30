using ll = long long;
const int MAXN = 1e6 + 5;
const ll MOD = 1e9 + 7;

ll fact[MAXN];

void computeFactorials() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}