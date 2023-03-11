//  https://codeforces.com/group/yAhl7s6c8Y/contest/394769/problem/D

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
char grid[505][505];
int n, m;
int dist[505][505][2][2][2];
bool valid(int i, int j, int a, int b, int c) {
    if (i < 0 || i >= n || j < 0 || j >= m)return 0;
    if (grid[i][j] == 'A' && !a)return 0;
    if (grid[i][j] == 'B' && !b)return 0;
    if (grid[i][j] == 'C' && !c)return 0;
    return 1;
}
int BFS(int sr, int sc, int dr, int dc) {
    queue<vector<int>>q;
    q.push({ sr,sc,0,0,0 });
    dist[sr][sc][0][0][0] = 0;
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        int x = node[0], y = node[1], a = node[2], b = node[3], c = node[4];
        if (x == dr && y == dc) {
            return dist[x][y][a][b][c];
        }
        if (grid[x][y] == 'a') {
            if (a == 0)
                dist[x][y][1][b][c] = dist[x][y][0][b][c];
            a |= 1;
        }
        if (grid[x][y] == 'b') {
            if (b == 0)
                dist[x][y][a][1][c] = dist[x][y][a][0][c];
            b |= 1;
        }
        if (grid[x][y] == 'c') {
            if (c == 0)
                dist[x][y][a][b][1] = dist[x][y][a][b][0];
            c |= 1;
        }
        for (int i = 0;i < 4;i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (valid(xx, yy, a, b, c) && dist[xx][yy][a][b][c] == -1) {
                dist[xx][yy][a][b][c] = dist[x][y][a][b][c] + 1;
                q.push({ xx,yy,a,b,c });
            }
        }
    }
    return -1;
}
void doWork(ll tt) {
    cin >> n >> m;
    memo(dist, -1);
    int sr, sc, dr, dc;
    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')sr = i, sc = j;
            if (grid[i][j] == 'E')dr = i, dc = j;
        }
    cout << BFS(sr, sc, dr, dc);
}
int main() {
 freopen("maze.in", "r", stdin);
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
 
