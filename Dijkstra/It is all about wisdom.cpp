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
ll n, m, k;
vector<pair<ll, pair<ll, ll>>>adj[1000006];
vector<ll>dis(1000006);
bool Dijkstra(ll src) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>>pq;
    fill(all(dis), 1e18);
    pq.push({ 0,1 });
    dis[1] = 0;
    while (!pq.empty()) {
        ll node = pq.top().second;
        ll cost = pq.top().first;
        pq.pop();
        for (auto i : adj[node]) {
            ll newCost = cost + i.second.first;
            if (newCost < dis[i.first] && i.second.second <= src) {
                pq.push({ newCost,i.first });
                dis[i.first] = newCost;
            }
        }
    }
    return dis[n] < k;
}
void doWork(ll tt) {
    cin >> n >> m >> k;
    for (int i = 1;i <= n;i++)adj[i].clear(), dis[i] = 1e10;
    for (int i = 0;i < m;i++) {
        int u, v, c, w;
        cin >> u >> v >> c >> w;
        adj[u].push_back({ v,{c,w} });
        adj[v].push_back({ u,{c,w} });
    }
    ll ans = -1, l = 0, r = 1e10;
    while (l <= r) {
        ll mid = (l + r) >> 1LL;
        (Dijkstra(mid) ? ans = mid,r = mid - 1 : l = mid + 1);
    }
    cout << ans;
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
