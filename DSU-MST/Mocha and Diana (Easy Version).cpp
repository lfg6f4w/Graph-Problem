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
int dy[] = { 1 , 0 , -1 ,  0 , 1 , -1 , 1  , -1 };
int dx[] = { 0 , 1 ,  0 , -1 , 1 , -1 , -1 , 1 };

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
int par[100005], siz[100005];
void init(int n) {
    for (int i = 1;i <= n;i++)
        par[i] = i, siz[i] = 1;
}
int FindParent(int node) {
    if (par[node] == node) return node;
    return par[node] = FindParent(par[node]);
}
bool isConnect(int u, int v) {
    return FindParent(u) == FindParent(v);
}
void Connect(int u,int v) {
    if (isConnect(u, v))return;
    v = FindParent(v);
    u = FindParent(u);
    if (siz[u] < siz[v])par[u] = v, siz[v] += siz[u];
    else par[v] = u, siz[u] += siz[v];
}
void doWork(ll tt) {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<vector<int>>arr(2, vector<int>(n + 1));
    for (int i = 1;i <= n;i++)arr[0][i] = arr[1][i] = i;
    function<int(int, int)>findPar = [&](int u, int t) {
        if (arr[t][u] == u)return u;
        return arr[t][u] = findPar(arr[t][u], t);
    };
    for (int i = 0;i < m1;i++) {
        int u, v;
        cin >> u >> v;
        int pu = findPar(u, 0);
        int pv = findPar(v, 0);
        arr[0][pu] = pv;
    }
    for (int i = 0;i < m2;i++) {
        int u, v;
        cin >> u >> v;
        int pu = findPar(u, 1);
        int pv = findPar(v, 1);
        arr[1][pu] = pv;
    }
    vector<pair<int, int>>ans;
    for (int i = 1;i <= n;i++) {
        for (int j = i + 1;j <= n;j++) {
            int pi0 = findPar(i, 0);
            int pj0 = findPar(j, 0);

            int pi1 = findPar(i, 1);
            int pj1 = findPar(j, 1);

            if (pi0 != pj0 && pi1 != pj1) {
                ans.push_back({ i,j });
                arr[0][pi0] = pj0;
                arr[1][pi1] = pj1;
            }
        }
    }
    cout << ans.size() << ed;
    for (auto i : ans)cout << i.first << ' ' << i.second << ed;
}
int main() {
    Accept();
    int t = 1;
    // cin >> t;
    for (int i = 1;i <= t;i++)
        // cout << "Case "<<i<<": ",
        doWork(i);// cout << ed;
    Good_Bay 0;
}
