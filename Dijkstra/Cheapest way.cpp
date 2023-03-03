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
map<string, pair<int, int>>inCity;
map<int, string>mp;
vector<pair<int, int>>adj[1000006];
vector<int>dis(1000006);
vector<int>par(1000006);
int n, m, k;
void init() {
    inCity.clear();
    for (int i = 1;i <= n;i++) {
        adj[i].clear();
        dis[i] = OO;
    }
}
int dijkstra(string s,string d) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    for (int i = 1;i <= n;i++)dis[i] = OO, par[i] = -1;
    pq.push({ inCity[s].second,inCity[s].first });
    dis[inCity[s].first] = inCity[s].second;
    while (!pq.empty()) {
        int node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if (cost > dis[node])continue;
        for (auto i : adj[node]) {
            int newCost = cost + i.second + inCity[mp[i.first]].second;
            if (newCost < dis[i.first]) {
                pq.push({ newCost,i.first });
                dis[i.first] = newCost;
                par[i.first] = node;
            }
        }
    }
    return dis[inCity[d].first];
}
vector<string>Parent(string s, string d) {
    int x = par[inCity[d].first];
    vector<string>v;
    v.push_back(d);
    while (x != -1) {
        v.push_back(mp[x]);
        x = par[x];
    }
    reverse(all(v));
    return v;
}
void doWork(ll tt) {
    cout << "Map #" << tt << ed;
    cin >> n;
    init();
    for (int i = 1;i <= n;i++) {
        string s;
        int x;
        cin >> s >> x;
        inCity[s] = { i,x };
        mp[i] = s;
    }
    cin >> m;
    for (int i = 0;i < m;i++) {
        string u, v;
        int w;
        cin >> u >> v >> w;
        adj[inCity[u].first].push_back({ inCity[v].first,w * 2 });
        adj[inCity[v].first].push_back({ inCity[u].first,w * 2 });
    }
    cin >> k;
    for (int i = 1;i <= k;i++) {
        string s, e;
        int p;
        cin >> s >> e >> p;
        ld x = dijkstra(s, e);
        x += (x * 0.1);
        vector<string>v = Parent(s, e);
        cout << "Query #" << i << ed;
        for (int i = 0;i < v.size();i++)cout << v[i] << " \n"[i == v.size() - 1];
        cout << "Each passenger has to pay : " << fixed(2) << x / (p * 1.0) << " taka" << ed;
    }
}
int main() {
    Accept();
    int t = 1;
    cin >> t;
    for (int i = 1;i <= t;i++) {
        // cout << "Case "<<i<<": ",
        doWork(i);
        if (i < t)cout << ed;
    }
    Good_Bay 0;
}
