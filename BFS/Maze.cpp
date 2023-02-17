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
int dy[] = { 1 , -1 , 0 ,  0 , 1 , -1 , 1  , -1 };
int dx[] = { 0 , 0  , 1 , -1 , 1 , -1 , -1 , 1 };
void doWork(ll tt) {
    int n, m, k;
    cin >> n >> m >> k;
    int srcX, srcY, ept = 0, will = 0;
    char grid[n + 10][m + 10];
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '.')srcX = i, srcY = j;
            ept += (grid[i][j] == '.');
        }
    queue<pair<int, int>>q;
    q.push({ srcX,srcY });
    vector<vector<bool>>used(n + 10, vector<bool>(m + 10, false));
    used[srcX][srcY] = 1;
    will = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        for (int i = 0;i < 4;i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (ept - k == will)break;
            if (xx<1 || yy < 1 || xx >n || yy > m)continue;
            if (used[xx][yy] == true)continue;
            if (grid[xx][yy] == '#')continue;
            q.push({ xx,yy });
            used[xx][yy] = true;
            will++;
        }
        q.pop();
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (grid[i][j] == '.' && !used[i][j])grid[i][j] = 'X';
            cout << grid[i][j];
        }
        cout << ed;
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
