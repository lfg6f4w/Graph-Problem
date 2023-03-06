class Solution {
public:
    vector<long long>Dijkstra(int s, vector<vector<pair<int, int>>>& adj) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>pq;
        vector<long long>des(adj.size(), LLONG_MAX);
        pq.push({ 0,s });
        des[s] = 0;
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            if (node.first > des[node.second])continue;
            for (auto i : adj[node.second]) {
                long long newCost = node.first + i.second;
                if (newCost < des[i.first]) {
                    pq.push({ newCost,i.first });
                    des[i.first] = newCost;
                }
            }
        }
        return des;
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int s1, int s2, int d) {
        vector<vector<pair<int, int>>>adj(n);
        vector<vector<pair<int, int>>>inverAdj(n);
        for (int i = 0;i < edges.size();i++) {
            adj[edges[i][0]].push_back({ edges[i][1],edges[i][2] });
            inverAdj[edges[i][1]].push_back({ edges[i][0],edges[i][2] });
        }
        auto des1 = Dijkstra(s1, adj);
        auto des2 = Dijkstra(s2, adj);
        auto des = Dijkstra(d, inverAdj);
        long long ans = LLONG_MAX;
        for (int i = 0;i < n;i++) {
            if(des1[i] != LLONG_MAX && des2[i] != LLONG_MAX && des[i] != LLONG_MAX)
              ans = min({ ans,des1[i] + des2[i] + des[i] });
        }
        return (ans >= LLONG_MAX ? -1 : ans);
    }
};
