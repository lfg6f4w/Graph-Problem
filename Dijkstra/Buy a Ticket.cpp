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
vector<pair<ll, ll>>adj[1000006];
vector<ll>cost(1000006);
vector<ll>dis(1000006);
ll n, m;
void Dijkstra() {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>>pq;
    for (int i = 1;i <= n;++i)pq.push({ cost[i],i });
    while (!pq.empty()) {
        ll Cost = pq.top().first;// 10
        ll node = pq.top().second;// 2
        pq.pop();
        if (Cost > cost[node])continue;
        for (auto i : adj[node]) {// 1 3
            ll newCost = i.second + Cost; // 6 + 8 = 14
            if (newCost < cost[i.first]) {
                cost[i.first] = newCost;
                pq.push({ newCost,i.first });
            }
        }
    }
}
void doWork(ll tt) {
    cin >> n >> m;
    for (int i = 0;i < m;i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v,2LL * w });
        adj[v].push_back({ u,2LL * w });
    }
    for (int i = 1;i <= n;i++)cin >> cost[i];
    Dijkstra();
    for (int i = 1;i <= n;i++)cout << cost[i] << ' ';
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

/**
2 -> 1 , 3
->

10 2
20 3
30 1


*/
