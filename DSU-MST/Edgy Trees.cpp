/*** وَمَا تَوْفِيقِي إِلَّا بِاللَّهِ ۚ عَلَيْهِ تَوَكَّلْتُ وَإِلَيْهِ أُنِيبُ ***/

#include                             <bits/stdc++.h>
#define     ll                       long long
#define     ld                       long double
#define     ed                       '\n'
#define     sz(x)                    x.size()
#define     all(x)                   x.begin(), x.end()
#define     rall(x)                  x.rbegin(), x.rend()
#define     fixed(x)                 fixed<<setprecision(x)
#define     memo(dp,x)               memset(dp,x,sizeof(dp))
#define     sumOf(a)                 (ll)((-1 + sqrt(8 * a + 1)) / 2)
#define     Good_Bay                 return

const int mod = 1e9 + 7, OO = 0x3f3f3f3f, MAX = 2e5 + 5;
const double pi = acos(-1), EPS = 1e-7;

using namespace std;

template < typename T > istream& operator >> (istream& in, vector < T >& v) {
    for (auto& x : v) in >> x;
    return in;
}

template < typename T > ostream& operator << (ostream& out, const vector < T >& v) {
    for (const T& x : v) out << x << ' ';
    return out;
}

void Accept() { // for VS code
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int dy[] = { 1 , 0 , -1 ,  0 , 1 , -1 ,  1 , -1 };
int dx[] = { 0 , 1 ,  0 , -1 , 1 , -1 , -1 ,  1 };
ll par[1000006];
ll siz[1000006];
ll vis[1000006];
void init(int n) {
    for (int i= 1;i <= n;i++) {
        par[i] = i;
        siz[i] = 1;
        vis[i] = 0;
    }
}
int findPar(int u) {
    return par[u] = (par[u] == u ? u : findPar(par[u]));
}
void Con(int u, int v) {
    u = findPar(u);
    v = findPar(v);
    if (u == v)return;
    if (siz[u] < siz[v])swap(u, v);
    siz[u] += siz[v];
    par[v] = u;
}
ll fastPower(ll n, int b) {
    ll mult = 1;
    while (b) {
        if (b & 1)mult = ((mult % mod) * (n % mod)) % mod;
        n = ((n % mod) * (n % mod)) % mod;
        b /= 2;
    }
    return mult;
}
void doWork(ll tt) {
    int n, k;
    cin >> n >> k;
    init(n);
    for (int i = 1;i < n;i++) {
        int u, v, x;
        cin >> u >> v >> x;
        if (!x)Con(u, v);
    }
    ll tot = fastPower(n, k), ans = 0;
    for (int i = 1;i <= n;i++) {
        ll x = findPar(i);
        if (!vis[x])ans = (ans % mod + fastPower(siz[x], k) % mod) % mod;
        vis[x] = 1;
    }
    cout << (tot - ans + mod) % mod;
}
int main() {
    Accept();
    int t = 1;
    // cin >> t;
    for (int i = 1;i <= t;i++)
        // cout << "Case "<<i<<": ",
        doWork(i), cout << ed;
    Good_Bay 0;
}
