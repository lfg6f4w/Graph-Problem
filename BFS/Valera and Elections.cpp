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
int dy[] = { 1 , -1 , 0 ,  0 , 1 , -1 , 1  , -1 };
int dx[] = { 0 , 0  , 1 , -1 , 1 , -1 , -1 , 1 };

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
unordered_set<int>BFS(int src, vector<vector<pair<int, int>>>& adj) {
    queue<pair<int, int>>q;
    vector<bool>vis(adj.size());
    unordered_set<int>ans;
    q.push({ src,-1 });
    vis[src] = 1;
    while (!q.empty()) {
        int node = q.front().first;
        int last = q.front().second;
        q.pop();
        for (auto i : adj[node]) {
            int neigh = i.first;
            int t = i.second;
            if (vis[neigh] == 0) {
                vis[neigh] = 1;
                if (t == 2) {
                    ans.erase(last);
                    ans.insert(neigh);
                    q.push({ neigh,neigh });
                }
                else {
                    q.push({ neigh,last });
                }
            }
        }
    }
    return ans;
}
void doWork(ll tt) {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>>adj(n);
    for (int i = 1;i < n;i++) {
        int u, v, t;
        cin >> u >> v >> t;
        --u, --v;
        adj[u].push_back({ v,t });
        adj[v].push_back({ u,t });
    }
    auto ans = BFS(0, adj);
    cout << ans.size() << ed;
    for (auto i : ans)cout << i + 1 << ' ';
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
