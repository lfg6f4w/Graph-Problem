/*** وَمَا تَوْفِيقِي إِلَّا بِاللَّهِ ۚ عَلَيْهِ تَوَكَّلْتُ وَإِلَيْهِ أُنِيبُ ***/

#include                             <bits/stdc++.h>
#define     ll                       long long
#define     ld                       long double
#define     ft                       first
#define     sd                       second
#define     ed                       '\n'
#define     sz(x)                    x.size()
#define     all(x)                   x.begin(), x.end()
#define     rall(x)                  x.rbegin(), x.rend()
#define     fixed(x)                 fixed<<setprecision(x)
#define     memo(dp,x)               memset(dp,x,sizeof(dp))
#define     sumOf(a)                 (ll)((-1 + sqrt(8 * a + 1)) / 2)
#define     Good_Bay                 return

const int mod = 1000000007, OO = 2e9, EPS = 1e-7;
const double pi = acos(-1);

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

int dxy[9][2] = { {-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{0,1},{-1,1},{-1,0} };

int mul_inv(int a, int b) { // don't forget it (Puiple(-40))
    int b0 = b, t, q;
    int x0 = 0, x1 = 1;
    if (b == 1) return 1;
    while (a > 1) {
        q = a / b;
        t = b, b = a % b, a = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }
    if (x1 < 0) x1 += b0;
    return x1;
}
int color[2005];
vector<int>eg[2005];
int n, m, ok = 1;
int dfs(int node) {
    if (color[node] == -1)color[node] = 1;
    for (auto i : eg[node]) {
        if (color[i] == -1) {
            color[i] = !color[node];
            dfs(i);
        }
        if (color[i] == color[node])ok = 0;
    }
    return ok;
}
void doWork(ll tt) {
    cout << "Scenario #" << tt << ":\n";
    cin >> n >> m;
    ok = 1;
    for (int i = 1;i <= n;i++) {
        color[i] = -1;
        eg[i].clear();
    }
    for (int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        eg[v].push_back(u);
        eg[u].push_back(v);
    }
    // cout << dfs(1);
    for (int i = 1;i <= n;i++) {
        if (color[i] == -1 && !dfs(i)) {
            cout << "Suspicious bugs found!";
            return;
        }
    }
    cout << "No suspicious bugs found!";
}
int main() {
    Accept();
    int t = 1;
    cin >> t;
    for (int i = 1;i <= t;i++)
        // cout << "Case "<<i<<": ",
        doWork(i), cout << ed;
    Good_Bay 0;
}
