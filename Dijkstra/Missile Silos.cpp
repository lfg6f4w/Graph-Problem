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
vector<pair<int, int>>adj[1000006];
vector<int>dis(1000006);
vector<int>t(1000006);
vector<pair<int, pair<int,int>>>edges;
int n, m, k, l;
void init() {
    for (int i = 0;i <= n;i++) {
        adj[i].clear();
        dis[i] = OO;
    }
}
void dij(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push({ 0,s });
    dis[s] = 0;
    while (!pq.empty()) {
        int node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        for (auto i : adj[node]) {
            int newCost = cost + i.second;
            if (newCost < dis[i.first]) {
                pq.push({ newCost,i.first });
                dis[i.first] = newCost;
            }
        }
    }
}
void doWork(ll tt) {
    cin >> n >> m >> k;
    init();
    for (int i = 0;i < m;i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({ v,c });
        adj[v].push_back({ u,c });
        edges.push_back({ c,{u,v} });
    }
    cin >> l;
    dij(k);
    int ans = 0;
    for (int i = 1;i <= n;++i) {
        ans += (dis[i] == l);
    }
    for (int i = 0;i < m;i++) {
        if (dis[edges[i].second.first] > l && dis[edges[i].second.second] > l)continue;
        int a = l - dis[edges[i].second.first];
        int b = l - dis[edges[i].second.second];
        if (dis[edges[i].second.first] + edges[i].first <= l ||
            dis[edges[i].second.second] + edges[i].first <= l ||
            a + b > edges[i].first) continue;
        if (a > 0)ans++;
        if (b > 0 && a + b != edges[i].first)ans++;
    }
    cout << ans;
}
int main() {
    Accept();
    int t = 1;
    // cin >> t;
    for (int i = 1;i <= t;i++) {
        // cout << "Case "<<i<<": ",
        doWork(i);
        if (i < t)cout << ed;
    }
    Good_Bay 0;
}
