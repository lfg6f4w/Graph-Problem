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
int n, k;
void init() {
    for (int i = 0;i <= 100;i++) {
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
        if (cost > dis[node])continue;
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
    while (cin >> n >> k) {
        init();
        for (int i = 0;i < n;i++)cin >> t[i];
        cin.ignore();
        for (int i = 0;i < n;i++) {
            string s;
            getline(cin, s);
            stringstream ss(s);
            int x;
            vector<int>f;
            while (ss >> x)f.push_back(x);
            for (int j = 0;j < f.size();j++) {
                for (int k = j + 1;k < f.size();k++) {
                    if (j == k)continue;
                    int u = f[j];
                    int v = f[k];
                    int c = abs(u - v);
                    adj[v].push_back({ u,c * t[i] + min(60,u * 60) });
                    adj[u].push_back({ v,c * t[i] + min(60,u * 60) });
                }
            }
        }
        dij(0);
        cout << (dis[k] == OO ? "IMPOSSIBLE" : to_string(dis[k])) << ed;
    }
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
