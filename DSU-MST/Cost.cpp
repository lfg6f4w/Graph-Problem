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

const int mod = 1e9, OO = 0x3f3f3f3f, MAX = 2e5 + 5;
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
int par[1000006];
ll siz[1000006];
void init(int n) {
    for (int i = 1;i <= n;i++)
        par[i] = i, siz[i] = 1;
}
int findPar(int u) {
    return par[u] = (par[u] == u ? u : findPar(par[u]));
}
void con(int u, int v, ll& num) {
    u = findPar(u);
    v = findPar(v);
    if (u == v)return;
    if (siz[u] < siz[v]) swap(u, v);
    num = ((num % mod) + ((siz[u] % mod) * (siz[v] % mod)) % mod) % mod;
    siz[u] += siz[v];
    par[v] = u;
}
void doWork(ll tt) {
    int n, m;
    cin >> n >> m;
    init(n);
    vector<pair<int, pair<int, int>>>adj(m);
    for (int i = 0;i < m;i++) {
        cin >> adj[i].second.first >> adj[i].second.second >> adj[i].first;
    }
    sort(rall(adj));
    ll ans = 0, num = 0;
    for (int i = 0;i < m;i++) {
        con(adj[i].second.first, adj[i].second.second, num);
        ans = ((ans % mod) + ((adj[i].first % mod) * (num % mod)) % mod) % mod;
    }
    cout << ans % mod;
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
