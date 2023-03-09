///   https://atcoder.jp/contests/abc061/tasks/abc061_d?lang=en

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

const int mod = 1e9 + 7, oo = 0x3f3f3f3f, MAX = 2e5 + 5;
const double pi = acos(-1), EPS = 1e-7;
const ll OO = LLONG_MAX;

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
struct edge {
    int u, v, w;
    edge(int u, int v, int w):u(u), v(v), w(w) {}
};
int n, m;
ll x;
vector<edge>edges;
vector<ll>dist;
int negCycle = false;
void BellmanFord(int s) {
    for (int i = 1;i <= n;i++)
        dist[i] = 2e12;
    dist[s] = 0;
    for (int i = 0;i <= n;i++) {
        for (int j = 0;j < m;j++) {
            ll u = edges[j].u, v = edges[j].v, w = edges[j].w;
            if (dist[u] + w < dist[v]) {
                if (i == n)negCycle = true;
                if (i < n)x = dist[n];
                dist[v] = dist[u] + w;
            }
        }
    }
}
void doWork(ll tt) {
    cin >> n >> m;
    dist = vector<ll>(n + 1);
    for (int i = 0;i < m;i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, -w);
    }
    BellmanFord(1);
    if (negCycle && x != dist[n]) cout << "inf";
    else cout << -dist[n];
}
int main() {
    Accept();
    int t = 1;
    // cin >> t;
    for (int i = 1;i <= t;i++) {
        // cout << "Case "<<i<<": ",
        doWork(i), cout << ed;
     //   if (i < t)cout << ed;
    }
    Good_Bay 0;
}

