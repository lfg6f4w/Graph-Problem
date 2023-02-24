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

const int mod = 1000000007, OO = 0x3f3f3f3f;
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
int par[1000006];
int siz[1000006];
vector<pair<int, pair<int, int>>>eg1;
vector<pair<int, pair<int, int>>>eg2;
void init(int n) {
    eg1.clear();
    eg2.clear();
    for (int i = 1;i <= n;i++)
        par[i] = i, siz[i] = 1;
}
int findPar(int u) {
    return par[u] = (par[u] == u ? u : findPar(par[u]));
}
bool con(int u, int v) {
    u = findPar(u);
    v = findPar(v);
    if (u == v)return false;
    if (siz[u] < siz[v])
        par[u] = v, siz[v] += siz[u];
    else par[v] = u, siz[u] += siz[v];
    return true;
}
int n, m, k;
int u, v, w;
void doWork(ll tt) {
    cin >> n >> m >> k;
    init(n);
    int sum = OO;
    while (m--) {
        cin >> u >> v >> w;
        sum = min(sum, abs(w - k));
        if (w > k)
            eg1.push_back({ w,{u,v} });
        else
            eg2.push_back({ w,{u,v} });
    }
    sort(all(eg1));
    sort(all(eg2));
    for (auto i : eg2)con(i.second.first, i.second.second);
    ll ans = 0;
    for (auto i : eg1) {
        if (con(i.second.first, i.second.second))ans += i.first - k;
    }
    cout << (ans == 0 ? sum : ans);
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
