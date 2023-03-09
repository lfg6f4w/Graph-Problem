//  https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=499


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

const int mod = 1e9 + 7, oo = 0x3f3f3f3f, MAX = 2e5 + 5;
const double pi = acos(-1), EPS = 1e-7;
const ll OO = LLONG_MAX;
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
int n , m;
struct edge{
    int u , v , w;
    edge(int u, int v, int w):u(u), v(v), w(w) {}
};
vector<edge>edges;
int dist[5000];
bool BellmanFord(int src){
    for ( int i = 0 ; i < n ; i++)
        dist[i] = oo;
    dist[src] = 0;
    for ( int j = 0 ; j < n; j++){
        for ( int i = 0 ; i < m ; i++){
            int u = edges[i].u , v = edges[i].v , w = edges[i].w;
            if(dist[u] + w < dist[v]){
                if (j == n - 1) {
                    return 0;
                }
                dist[v] = dist[u] + w;
            }
        }
    }
    return 1;
}
void doWork(ll tt) {
    cin >> n >> m;
    edges.clear();
    for (int i = 0;i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }
    if (!BellmanFord(0))cout << "possible";
    else cout << "not possible";
}
int main() {
    Accept();
    int t = 1;
    cin >> t;
    for (int i = 1;i <= t;i++) {
        // cout << "Case "<<i<<": ",
        doWork(i), cout << ed;
     //   if (i < t)cout << ed;
    }
    Good_Bay 0;
}

