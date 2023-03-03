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
vector<pair<int, int>>adj[1010];
vector<vector<int>>dis(1001, vector<int>(1001, OO));
int n, m, k;
void Dijkstra(int src, vector<int>& subDis) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
    pq.push({ 0,src });
    subDis[src] = 0;
    while (!pq.empty()) {
        int node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        for (auto i : adj[node]) {
            int newCost = cost + i.second;
            if (newCost < subDis[i.first]) {
                pq.push({ newCost,i.first });
                subDis[i.first] = newCost;
            }
        }
    }
}
void doWork(ll tt) {
    cin >> n >> m >> k;
    for (int i = 0;i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v,w });
        adj[v].push_back({ u,w });
    }
    vector<pair<int, int>>qu(k);
    for (int i = 0;i < k;i++) {
        cin >> qu[i].first >> qu[i].second;
    }
    for (int i = 1;i <= n;i++) {
        Dijkstra(i, dis[i]);
    }
    int ans = OO;
    for (int i = 1;i <= n;i++) {
        for (auto j : adj[i]) {
            int cnt = 0;
            for (auto k : qu) {
                cnt += min({dis[k.first][k.second], dis[k.first][i] + dis[j.first][k.second], dis[k.first][j.first] + dis[i][k.second]});
            }
            ans = min(ans, cnt);
        }
    }
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
