//  https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=989

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
void Floyd(int n,vector<vector<int>>& last) {
    for (int k = 1;k <= n;k++) {
        for (int i = 1;i <= n;++i) {
            for (int j = 1;j <= n;j++) {
                if (last[i][k] == oo || last[k][j] == oo)continue;
                last[i][j] = min(last[i][j], max(last[k][j], last[i][k]));
            }
        }
    }
}
void doWork(ll tt) {
    int n, m, q;
    bool line = 1;
    while (cin >> n >> m >> q, !(n == 0 && m == 0 && q == 0)) {
        if (line)line = 0;
        else cout << '\n';
        cout << "Case #" << tt++ << ed;
        vector<vector<int>>last(n + 1, vector<int>(n + 1, oo));
        for (int i = 0;i < m;i++) {
            int u, v, w;
            cin >> u >> v >> w;
            last[u][v] = w;
            last[v][u] = w;
        }
        Floyd(n, last);
        for (int i = 0;i < q;++i) {
            int u, v;
            cin >> u >> v;
            if (last[u][v] == oo)cout << "no path";
            else cout << last[u][v];
            cout << ed;
        }
    }
}
int main() {
    Accept();
    int t = 1;
    // cin >> t;
    for (int i = 1;i <= t;i++) {
        // cout << "Case "<<i<<": ",
        doWork(i);
        // cout << ed;
        // if (i < t)cout << ed;
    }
    Good_Bay 0;
}
