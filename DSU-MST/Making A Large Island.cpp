class Solution {
public:
    int dy[4] = {1 , 0 , -1 ,  0};
    int dx[4] = {0 , 1 ,  0 , -1};
    bool valid(int i, int j, int n) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    void init(int n, vector<vector<pair<int, int>>>& par, vector<vector<int>>& siz, vector<vector<int>>& adj) {
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                if (adj[i][j] == 1) {
                    par[i][j] = { i,j };
                    siz[i][j] = 1;
                }
                else {
                    par[i][j] = { i,j };
                    siz[i][j] = 0;
                }
            }
        }
    }
    pair<int,int> findPar(pair<int,int> u, vector<vector<pair<int, int>>>& par) {
        return par[u.first][u.second] = (par[u.first][u.second] == u ? u : findPar(par[u.first][u.second], par));
    }
    void Con(pair<int,int> u, pair<int,int> v, vector<vector<pair<int, int>>>& par, vector<vector<int>>& siz) {
        u = findPar(u, par);
        v = findPar(v, par);
        if (u == v)return;
        if (siz[u.first][u.second] < siz[v.first][v.second])swap(u, v);
        siz[u.first][u.second] += siz[v.first][v.second];
        par[v.first][v.second] = u;
    }
    int largestIsland(vector<vector<int>>& adj) {    
        int n = adj.size();
        vector<vector<pair<int, int>>>par(n, vector<pair<int, int>>(n));
        vector<vector<int>>siz(n, vector<int>(n));
        init(n, par, siz, adj);
        int ans = 1;
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                if (adj[i][j]) {
                    for (int k = 0;k < 4;k++) {
                        if (valid(i + dx[k], j + dy[k], n) && adj[i + dx[k]][j + dy[k]] == 1) {
                            pair<int, int>u = { i,j };
                            pair<int, int>v = { i + dx[k],j + dy[k] };
                            pair<int, int>paru = findPar(u, par);
                            pair<int, int>parv = findPar(v, par);
                            if (paru == parv)continue;
                            ans = max(ans, siz[paru.first][paru.second] + siz[parv.first][parv.second]);
                            Con(u, v, par, siz);
                        }
                    }
                }
            }
        }
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                if (!adj[i][j]) {
                    set<pair<int, int>>st;
                    int x = 1;
                    for (int k = 0;k < 4;k++) {
                        if (valid(i + dx[k], j + dy[k], n))
                            st.insert(findPar({ i + dx[k],j + dy[k] }, par));
                    }
                    for (auto i : st) {
                        x += siz[i.first][i.second];
                    }
                    ans = max(ans, x);
                }
            }
        }
        return ans;
    }
};
