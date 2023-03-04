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
bool valid(int i, int j, int n, int m) {
    return i >= 0 && i < n && j >= 0 && j < m;
}
string path(int i, int j, vector<vector<pair<int, int>>>& par) {
    pair<int, int>p;
    p.first = i;
    p.second = j;
    string s;
    while (p.first != -1) {
        int x = par[p.first][p.second].first;
        int y = par[p.first][p.second].second;
        if (x == -1)break;
        if (p.first == x - 1)s += 'U';
        else if (p.first == x + 1)s += 'D';
        if (p.second == y - 1)s += 'L';
        else if (p.second == y + 1)s += 'R';
        p = par[p.first][p.second];
    }
    reverse(all(s));
    return s;
}
void doWork(ll tt) {
    int n, m, sr, sc;
    cin >> n >> m;
    vector<string>grid(n);
    vector<vector<int>>dis1(n, vector<int>(m, -1));
    vector<vector<int>>dis2(n, vector<int>(m, -1));
    vector<vector<pair<int, int>>>par(n, vector<pair<int,int>>(m, { -1,-1 }));
    cin >> grid;
    queue<vector<int>>q;
    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
            if (grid[i][j] == 'A')sr = i, sc = j;
            else if (grid[i][j] == 'M')q.push({ i,j,0 }), dis1[i][j] = 0;
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        for (int i = 0;i < 4;i++) {
            int x = node[0] + dx[i];
            int y = node[1] + dy[i];
            if (!valid(x, y, n, m))continue;
            if (~dis1[x][y] || grid[x][y] != '.')continue;
            q.push({ x,y,node[2] + 1 });
            dis1[x][y] = dis1[node[0]][node[1]] + 1;
        }
    }
    q.push({ sr,sc,0 });
    dis2[sr][sc] = 0;
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        for (int i = 0;i < 4;i++) {
            int x = node[0] + dx[i];
            int y = node[1] + dy[i];
            if (!valid(x, y, n, m))continue;
            if (~dis2[x][y] || grid[x][y] != '.')continue;
            if (node[2] + 1 >= dis1[x][y] && dis1[x][y] != -1)continue;
            q.push({ x,y,node[2] + 1 });
            dis2[x][y] = dis2[node[0]][node[1]] + 1;
            par[x][y] = { node[0],node[1] };
        }
    }
    pair<int, int>p = { -1,-1 };
    for (int i = 0;i < m;i++)if ((grid[0][i] == '.' || grid[0][i] == 'A' )&& dis2[0][i] != -1) { p = { 0,i }; break; }
    if (p.first != -1) {
        cout << "YES\n" << dis2[p.first][p.second] << ed << path(p.first, p.second, par);
        return;
    }
    for (int i = 0;i < m;i++)if ((grid[n - 1][i] == '.' || grid[n - 1][i] == 'A') && dis2[n - 1][i] != -1) { p = { n - 1,i }; break; }
    if (p.first != -1) {
        cout << "YES\n" << dis2[p.first][p.second] << ed << path(p.first, p.second, par);
        return;
    }
    for (int i = 0;i < n;i++)if ((grid[i][0] == '.' || grid[i][0] == 'A') && dis2[i][0] != -1) { p = { i,0 }; break; }
    if (p.first != -1) {
        cout << "YES\n" << dis2[p.first][p.second] << ed << path(p.first, p.second, par);
        return;
    }
    for (int i = 0;i < n;i++)if ((grid[i][m - 1] == '.' || grid[i][m - 1] == 'A') && dis2[i][m - 1] != -1) { p = { i,m - 1 }; break; }
    if (p.first != -1) {
        cout << "YES\n" << dis2[p.first][p.second] << ed << path(p.first, p.second, par);
        return;
    }
    else cout << "NO";
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
