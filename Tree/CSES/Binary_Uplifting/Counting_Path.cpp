

#pragma GCC optimize("O3,unroll-loops")
 
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
const int MAXN = 1e6 + 5;
 
#define INF 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define py cout << "YES\n"
#define pn cout << "NO\n"
#define pm cout << "-1\n"
 
#ifdef Nitish
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using umll = unordered_map<ll, ll>;
 
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
ll gcd(ll a, ll b) {if (b > a) return gcd(b, a); if (b == 0) return a; return gcd(b, a % b);}
ll power_mod(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1;} return res;}
ll mod_add(ll a, ll b, ll m) {a %= m; b %= m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a %= m; b %= m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a %= m; b %= m; return (((a - b) % m) + m) % m;}
// ll mod_div(ll a, ll b, ll m) {a %= m; b %= m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}
// ll fact[MAXN], ifact[MAXN];
// void precompute_factorials(int n, ll m) {fact[0] = ifact[0] = 1; for (int i = 1; i <= n; i++) {fact[i] = (fact[i - 1] * i) % m; ifact[i] = power_mod(fact[i], m - 2, m);}}
// ll combination(ll n, ll r, ll m) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
vector<bool> sieve(int n) {vector<bool> is_prime(n + 1, true); is_prime[0] = is_prime[1] = false; for (int i = 2; i * i <= n; i++) {if (is_prime[i]) {for (int j = i * i; j <= n; j += i) is_prime[j] = false;}} return is_prime;}
 
//I have to learn
// void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
// ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
// ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
 
ll etf(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1) number = (number / n * (n - 1)); return number;}
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}
 
vector<int>adj[MAXN];
vector<vector<int>>dp;
vector<int>l(MAXN,0);
vector<int>path(MAXN,0);
int n ;
int logn;
 
void dfs(int node  , int par)
{
    dp[node][0] = par;
    if(par!=-1)
    l[node] = l[par] + 1;
    
    for(auto child:adj[node])
    {
        if(child==par) continue;
        dfs(child,node);
    }
}
 
void fillTable()
{
    for(int i=1;i<logn;i++) // 0 wala already fill hai
    {
        for(int j=1;j<=n;j++)
        {
            if(dp[j][i-1]!=-1)
            {
                dp[j][i] = dp[dp[j][i-1]][i-1];
            }
        }
    }
}
int findAns(int n1 , int n2)
{
    int ans = 0;
    if(l[n2]>l[n1]) swap(n1,n2);
    int level = l[n1] - l[n2];
    ans = level;
    for(int i=logn-1;i>=0;i--)
    {
        int val = (1LL << i);
        if(level>=val)
        {
            n1 = dp[n1][i];
            level = level-val;
        }
    }
    if(n1==n2) return n1;
    
    for(int i=logn-1;i>=0;i--)
    {
        if(dp[n1][i]!=-1 && dp[n1][i]!=dp[n2][i])
        {
          ans = ans + 2*(1<<i); 
          n1 = dp[n1][i];
          n2 = dp[n2][i];
        }
    }
    
    return dp[n1][0];
}
 
void Cal(int node , int par)
{
    
    for(auto child:adj[node])
    {
        if(par==child) continue;
        Cal(child,node);
        path[node]+=path[child];
    }
}
 
void solve() {
    // write your code here
    l[0] = 0;
    int q;
    cin>>n>>q;
    logn = log2(n)+1;
    for(int i=0;i<n-1;i++) // created adjacency list
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // tree bangaya
    dp.resize(n+1,vector<int>(logn,-1));
    dfs(1,-1);
    
      fillTable();
      for(int i=0;i<q;i++)
    {
        int u,v;
        cin>>u>>v;
       // cout<<u<<" "<<v<<endl;
       path[u]++;
       path[v]++;
       int lca = findAns(u,v);
       path[lca]--;
       if (dp[lca][0] != -1) path[dp[lca][0]]--;
    }
    
    
    Cal(1,-1);
    for(int i=1;i<=n;i++)
    {
        cout<<path[i]<<endl;
    }
}
 
int main() {
    fastio();
    solve();
    return 0;
