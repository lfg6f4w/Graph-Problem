/*** وَمَا تَوْفِيقِي إِلَّا بِاللَّهِ ۚ عَلَيْهِ تَوَكَّلْتُ وَإِلَيْهِ أُنِيبُ ***/

#include                             <bits/stdc++.h>
#define     ll                       long long
#define     ld                       long double
#define     ft                       first
#define     sd                       second
#define     ed                       '\n'
#define     sz(x)                    x.size()
#define     all(x)                   x.begin(), x.end()
#define     rall(x)                  x.rbegin(), x.rend()
#define     fixed(x)                 fixed<<setprecision(x)
#define     memo(dp,x)               memset(dp,x,sizeof(dp))
#define     sumOf(a)                 (ll)((-1 + sqrt(8 * a + 1)) / 2)
#define     Good_Bay                 return

const int mod = 1000000007, OO = 2e9, EPS = 1e-7, MAX = 1000005;
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

int dxy[9][2] = { {-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{0,1},{-1,1},{-1,0} };

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
vector<int>eg[100005], vis(100005);
vector<int>init, goal, ans;
void dfs(int node, int event) {
    vis[node] = 1;
    for (auto i : eg[node]) {
        if (!vis[i]) {
            // it not need to change, but it may be mast change
            if (init[i - 1] == goal[i - 1]) {
                // event = 0 => no parent change
                if (!event)dfs(i, 0);
                // event = 1 => first son of change parent , not change
                if (event == 1)dfs(i, 2);
                // event =2 => son of son of change parent, mast change
                if (event == 2) { dfs(i, 0); ans.push_back(i); }
                // event = 3 => parent and son changed and mast all sons change
                if (event == 3) { dfs(i, 2); ans.push_back(i); }
            }
            // must change
            if (init[i - 1] != goal[i - 1]) {
                // event = 0 => it node is parent
                if (!event) { dfs(i, 1); ans.push_back(i); }
                // event = 1 => its parent change and it must change
                if (event == 1) { dfs(i, 3); ans.push_back(i); }
                // event = 2 => its grandparent had changed and it will change already
                if (event == 2) dfs(i, 1);
                // event = 3 => its grandparent and its parent changed and it will change already
                if (event == 3)  dfs(i, 3);
            }
        }
    }
}
void doWork(ll tt) {
    int n;
    cin >> n;
    init = vector<int>(n);
    goal = vector<int>(n);
    for (int i = 0;i < n-1;i++) {
        int u, v;
        cin >> u >> v;
        eg[u].push_back(v);
        eg[v].push_back(u);
    }
    cin >> init >> goal;
    eg[0].push_back(1);
    dfs(0, 0);
    cout << ans.size() << ed << ans;
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
// ------------------------------------------------------------------------------------------

/*** وَمَا تَوْفِيقِي إِلَّا بِاللَّهِ ۚ عَلَيْهِ تَوَكَّلْتُ وَإِلَيْهِ أُنِيبُ ***/

#include                             <bits/stdc++.h>
#define     ll                       long long
#define     ld                       long double
#define     ft                       first
#define     sd                       second
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

int dxy[9][2] = { {-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{0,1},{-1,1},{-1,0} };

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
void doWork(ll tt) {
    int n;
    cin >> n;
    vector<int>eg[n + 1], init(n), goal(n), ans;
    for (int i = 1;i < n;i++) {
        int u, v;
        cin >> u >> v;
        eg[u].push_back(v);
        eg[v].push_back(u);
    }
    cin >> init >> goal;
    function<void(int, int, bool, bool, bool)>dfs = [&](int node, int parent, int level, int even, int odd) {
        if (level)init[node - 1] = (odd ? !init[node - 1] : init[node - 1]);
        else init[node - 1] = (even ? !init[node - 1] : init[node - 1]);
        if (init[node - 1] != goal[node - 1]) {
            init[node - 1] = goal[node - 1];
            ans.push_back(node);
            if (level)odd = !odd;
            else even = !even;
        }
        for (int i : eg[node]) {
            if (i != parent)
                dfs(i, node, !level, even, odd);
        }
    };
    dfs(1, -1, 0, 0, 0);
    cout << ans.size() << ed;
    for (auto i : ans)cout << i << ed;
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
