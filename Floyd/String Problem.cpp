/// https://codeforces.com/problemset/problem/33/b

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
const ll inf = LLONG_MAX;

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
void doWork(ll tt) {
    string s, t;
    cin >> s >> t;
    int n;
    cin >> n;
    vector<vector<int>>dist(200, vector<int>(200, oo));
    for (int i = 0;i < 200;i++)for (int j = 0;j < 200;j++)if (i == j)dist[i][j] = 0;
    for (int i = 0;i < n;i++) {
        char u, v;
        int w;
        cin >> u >> v >> w;
        dist[u - 'a'][v - 'a'] = min(w, dist[u - 'a'][v - 'a']);
    }
    if (s.size() != t.size()) {
        cout << -1;
        return;
    }
    for (int k = 0;k < 26;k++)
        for (int i = 0;i < 26;i++)
            for (int j = 0;j < 26;j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    ll sum = 0;
    string res;
    for (int i = 0;i < s.size();i++) {
        if (s[i] != t[i]) {
            int x = oo;
            char c;
            for (int j = 0;j < 26;j++) {
                if (x > dist[s[i] - 'a'][j] + dist[t[i] - 'a'][j]) {
                    x = dist[s[i] - 'a'][j] + dist[t[i] - 'a'][j];
                    c = j + 'a';
                }
            }
            res += c;
            sum += x;
        }
        else res += s[i];
    }
    if (sum >= oo)cout << -1;
    else cout << sum << ed << res;
}
int main() {
    Accept();
    int t = 1;
    // cin >> t;
    for (int i = 1;i <= t;i++) {
        // cout << "Case "<<i<<": ",
        doWork(i);
        // cout << ed;
        if (i < t)cout << ed;
    }
    Good_Bay 0;
}
