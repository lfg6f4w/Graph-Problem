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

const int mod = 1000000007, OO = 2e9, EPS = 1e-7;
const double pi = acos(-1);

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
int dy[] = { 1 , -1 , 0 ,  0 , 1 , -1 , 1  , -1 };
int dx[] = { 0 , 0  , 1 , -1 , 1 , -1 , -1 , 1 };

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
bool valid(int i, int j, int n, int m, vector<string>& grid,int mode ) {
    return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != 'W' && (mode == 1 || grid[i][j] != 'D');
}
int BFS(int sr, int sc, vector<string>& grid) {
    int n = grid.size(), m = grid[0].size();
    queue<pair<int, pair<int,int>>>q;
    vector<vector<vector<int>>>dis(n, vector<vector<int>>(m, vector<int>(2, -1)));
    q.push({ 0,{sr,sc} });
    dis[sr][sc][0] = 0;
    while (!q.empty()) {
        int r = q.front().second.first;
        int c = q.front().second.second;
        int t = q.front().first;
        q.pop();
        if (r == 0 || r == n - 1 || c == 0 || c == m - 1)return dis[r][c][t] + 1;
        if (grid[r][c] == 'O') {
            if (t == 0)
                dis[r][c][1] = dis[r][c][0];
            t |= 1;
        }
        if (grid[r][c] == 'C') {
            if (t == 1)
                dis[r][c][0] = dis[r][c][1];
            t &= 0;
        }
        for (int i = 0;i < 4;i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (valid(nr, nc, n, m, grid, t) && dis[nr][nc][t] == -1) {
                dis[nr][nc][t] = dis[r][c][t] + 1;
                q.push({ t,{nr,nc} });
            }
        }
    }
    return -1;
}
void doWork(ll tt) {
    int n, m;
    while (cin >> n >> m, n != -1) {
        vector<string>grid(n);
        cin >> grid;
        int sr = -1, sc = -1;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                if (grid[i][j] == 'H')
                    sr = i, sc = j;
        cout << BFS(sr, sc, grid) << ed;
    }
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
