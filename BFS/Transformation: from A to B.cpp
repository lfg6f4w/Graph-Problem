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
map<int, int>par;
void BFS(int n, int m) {
    queue<int>q;
    q.push(m);
    par[m] = -1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == n)return;
        if (x % 2 == 0) {
            int op1 = x / 2;
            if (par.find(op1) == par.end() && op1 >= n) {
                q.push(op1);
                par[op1] = x;
            }
        }
        else if (x % 10 == 1) {
            int op2 = x / 10;
            if (par.find(op2) == par.end() && op2 >= n) {
                q.push(op2);
                par[op2] = x;
            }
        }
    }
}
void doWork(ll tt) {
    int n, m;
    cin >> n >> m;
    BFS(n, m);
    if (par.find(n) != par.end()) {
        vector<int>v;
        int x = n;
        while (x != -1) {
            v.push_back(x);
            x = par[x];
        }
        cout << "YES\n" << v.size() << ed << v;
    }
    else cout << "NO";
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
