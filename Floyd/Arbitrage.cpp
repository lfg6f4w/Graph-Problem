/// https://www.spoj.com/problems/ARBITRAG/


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
    int n;
    while (cin >> n, n != 0) {
        map<string, int>mp;
        vector<vector<double>>dist(n + 1, vector<double>(n + 1, 0.0));
        for (int i = 1;i <= n;i++) {
            string s;
            cin >> s;
            mp[s] = i;
        }
        int m;
        cin >> m;
        for (int i = 1;i <= m;i++) {
            string s, t;
            double x;
            cin >> s >> x >> t;
            dist[mp[s]][mp[t]] = x;
        }
        for (int k = 1;k <= n;k++)
            for (int i = 1;i <= n;i++)
                for (int j = 1;j <= n;j++)
                    dist[i][j] = max(dist[i][j], dist[i][k] * dist[k][j]);
        bool ok = 0;
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++) {
                ok |= (dist[i][j] * dist[j][i] > 1);
                // cout << dist[i][j] << " \n"[j == n];
            }
      /*
      for(int i=1;i<=n;i++)
        ok|=(dist[i][i]>1)
      */
        cout << "Case " << tt++ << ": " << (ok ? "Yes" : "No") << ed;
    }
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
