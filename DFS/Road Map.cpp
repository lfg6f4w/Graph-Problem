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

const int mod = 1000000007, OO = 2e9, EPS = 1e-7, MAX = 1000005;
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
void doWork(ll tt) {
    int n, r1, r2;
    cin >> n >> r1 >> r2;
    vector<int>eg[n + 1], vis(n + 1), v(n - 1), ans(n + 1);
    cin >> v;
    int z = 1;
    for (int i = 0;i < n - 1;i++,z++) {
        if (i + 1 == r1)z++;
        eg[z].push_back(v[i]);
        eg[v[i]].push_back(z);
    }
    function<void(int, int)>DFS = [&](int node, int root) {
        ans[node] = root;
        for (auto i : eg[node]) {
            if (!ans[i])DFS(i, node);
        }
    };
    DFS(r2, -1);
    for (int i = 1;i <= n;i++) {
        if (i == r2)continue;
        cout << ans[i] << ' ';
    }
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
