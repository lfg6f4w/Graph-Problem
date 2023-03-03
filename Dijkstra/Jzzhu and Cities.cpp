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
vector<pair<ll,ll>>adj[1000006];
vector<ll>dis(1000006);
vector<ll>train(1000006);
ll n, m, k, cnt = 0;
void Dijkstra() {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>>pq;
    pq.push({ 0,1 });
    dis[1] = 0;
    while (!pq.empty()) {
        int node = pq.top().second;
        ll cost = pq.top().first;
        pq.pop();
        if (cost > dis[node]) {
            continue;
        }
        for (auto i : adj[node]) {
            ll newCost = cost + i.second;
            if (newCost < dis[i.first]) {
                pq.push({ newCost , i.first });
                dis[i.first] = newCost;
            }
        }
    }
}
void doWork(ll tt) {
    cin >> n >> m >> k;
    fill(all(dis), 1e18);
    fill(all(train), 1e18);
    for (int i = 0;i < m;i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v,w });
        adj[v].push_back({ u,w });
    }
    for (int i = 0;i < k;i++) {
        ll v, w;
        cin >> v >> w;
        adj[1].push_back({ v,w });
        if (train[v] < 1e15) {
            train[v] = min(w, train[v]);
            cnt++;
        }
        else train[v] = w;
    }
    Dijkstra();
    for (int i = 2;i <= n;i++) {
        if (train[i] > 1e17) continue;
        for (auto j : adj[i]) {
            if (dis[j.first] + j.second <= train[i]) {
                cnt++;
                break;
            }
        }
    }
    cout << cnt;
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
