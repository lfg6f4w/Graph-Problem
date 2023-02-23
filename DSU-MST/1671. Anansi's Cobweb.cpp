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

const int mod = 1000000007, OO = 0x3f3f3f3f, MAX = 2e5 + 5;
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
int siz[1000006];
void init(int n) {
    for(int i = 1;i <= n;i++) {
        par[i] = i;
        siz[i] = 1;
    }
}
int findPar(int u) {
    return par[u] = (par[u] == u ? u : findPar(par[u]));
}
bool con(int u, int v) {
    u = findPar(u);
    v = findPar(v);
    if (u == v)return 0;
    if (siz[u] < siz[v]) {
        par[u] = v;
        siz[v] += siz[u];
    }
    else {
        par[v] = u;
        siz[u] += siz[v];
    }
    return 1;
}
void doWork(ll tt) {
    int n, m;
    cin >> n >> m;
    init(n);
    vector<pair<int, int>>adj(m);
    map<int, bool>mp;
    for (int i = 0;i < m;i++) {
        cin >> adj[i].first >> adj[i].second;
    }
    int q;
    cin >> q;
    vector<int>v(q);
    for (int i = 0;i < q;i++) {
        cin >> v[i];
        mp[v[i]] = 1;
    }
    int pars = n;
    for (int i = 0;i < adj.size();i++) {
        if (mp[i + 1])continue;
        if (con(adj[i].first, adj[i].second)) {
            pars--;
        }
    }
    vector<int>ans;
    for (int i = v.size() - 1;i >= 0;i--) {
        ans.push_back(pars);
        if (con(adj[v[i] - 1].first, adj[v[i] - 1].second)) {
            pars--;
        }
    }
    reverse(all(ans));
    cout << ans;
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
