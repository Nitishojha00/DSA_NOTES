// ✅ Conclusion: Why We Use This power_mod Function
// We use this modular exponentiation algorithm because:


//  modm efficiently in log(b) time
// instead of multiplying a by itself b times (which takes O(b) time — too slow for large b like 1e9).

// 🔹 It avoids integer overflow by using % mod at every step,
// and handles huge powers safely — even for very large a, b like 
 

// 🔹 It's a standard technique used in:

//         Competitive Programming

//         Cryptography (e.g., RSA)

//         Fermat's Little Theorem

//         Modular Inverse

//         Combinatorics involving factorials under modulo

// 🔹 Key Idea:

//     It breaks b into its binary bits,
//     and uses square-and-multiply only for bits that are 1.


    using ll = long long;

ll power_mod(ll a, ll b, ll mod) {
    ll res = 1;
    a = a % mod;  // Ensure base is within mod

    while (b > 0) {
        if (b & 1) {
            res = (res * a) % mod;  // Multiply result when b is odd
        }
        a = (a * a) % mod;  // Square the base
        b >>= 1;            // Divide exponent by 2 (bitwise)
    }

    return res;
}
