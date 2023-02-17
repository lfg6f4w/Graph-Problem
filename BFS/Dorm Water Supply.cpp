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
int dy[] = { 1 , -1 , 0 ,  0 , 1 , -1 , 1  , -1 };
int dx[] = { 0 , 0  , 1 , -1 , 1 , -1 , -1 , 1 };
vector<int>adj[1003];
int dim[1003][1003];
vector<int>vis(1003);
map<int, int>deg;
pair<int, int> BFS(int node) {
    queue<int>q;
    q.push(node);
    vis[node] = 1;
    int mn = OO;
    int x = node;
    while (!q.empty()) {
        int n = q.front();
        x = n;
        q.pop();
        for (int i : adj[n]) {
            mn = min(mn, dim[n][i]);
            if (vis[i])continue;
            q.push(i);
            vis[i] = 1;
        }
    }
    return { x,mn };
}
void doWork(ll tt) {
    int n, m;
    cin >> n >> m;
    for (int i = 0;i < m;i++) {
        int a, b, d;
        cin >> a >> b >> d;
        adj[a].push_back(b);
        dim[a][b] = d;
        deg[a]++;
        deg[b]++;
    }
    vector<tuple<int, int, int>>ans;
    for (int i = 1;i <= n;i++) {
        if (!vis[i] && deg[i] == 1) {
            pair<int, int>x = BFS(i);
            if (x.second == OO) vis[i] = 0;
            else ans.push_back(make_tuple(i, x.first, x.second));
        }
    }
    cout << ans.size() << ed;
    for (auto i : ans)
        cout << get<0>(i) << ' ' << get<1>(i) << ' ' << get<2>(i) << ed;
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
