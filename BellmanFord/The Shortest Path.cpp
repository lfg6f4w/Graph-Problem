/// https://codeforces.com/problemset/gymProblem/101498/L

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
const ll inf = LLONG_MAX;

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
vector<pair<int, int>>eg[2005];
vector<ll>dist;
int n, m;
bool negCycle = false;
void Bellman(int s) {
    for (int k = 0;k <= n + 1;k++) {
        for (int i = 1;i <= n;i++) {
            for (int j = 0;j < eg[i].size();++j) {
                int u = i, v = eg[i][j].first;
                ll w = eg[i][j].second;
                if (dist[v] + w < dist[u]) {
                    if (k > n)negCycle = 1;
                    dist[u] = dist[v] + w;
                }
            }
        }
    }
}
void doWork(ll tt) {
    cin >> n >> m;
    dist = vector<ll>(n + 1);
    memo(eg, 0);
    negCycle = false;
    ll mn = inf;
    for (int i = 0;i < m;i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        mn = min(mn, w);
        eg[u].push_back({ v,w });
    }
    if (mn >= 0) {
        cout << mn;
        return;
    }
    Bellman(1);
    if (negCycle)cout << "-inf";
    else {
        cout << *min_element(all(dist));
    }
}
int main() {
    Accept();
    int t = 1;
    cin >> t;
    for (int i = 1;i <= t;i++) {
        // cout << "Case "<<i<<": ",
        doWork(i);
        // cout << ed;
        if (i < t)cout << ed;
    }
    Good_Bay 0;
}
