class Solution {
public:
    vector<pair<int,int>>adj[200];
    vector<vector<int>> BFS(int src) {
        vector<vector<int>>dis(200, vector<int>(2, -1));
        queue<pair<int, int>>q;
        q.push({ src,1 });
        q.push({ src,0 });
        dis[src][0] = dis[src][1] = 0;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            for (auto neigh : adj[node.first]) {
                int nodeNeigh = neigh.first;
                int colorNeigh = neigh.second;
                if (colorNeigh != node.second && dis[nodeNeigh][colorNeigh] == -1) {
                    dis[nodeNeigh][colorNeigh] = dis[node.first][node.second] + 1;
                    q.push({ nodeNeigh,colorNeigh });
                }
            }
        }
        return dis;
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) {
        for(auto i: red) adj[i[0]].push_back({ i[1],0 });
        for(auto i: blue) adj[i[0]].push_back({ i[1],1 });
        vector<vector<int>>dis = BFS(0);
        vector<int>ans(n);
        for (int i = 0;i < n;i++) {
            if (dis[i][1] != -1 && dis[i][0] != -1)ans[i] = min(dis[i][1], dis[i][0]);
            else ans[i] = max(dis[i][1], dis[i][0]);
        }
        return ans;   
    }
};

// -------------------------------------------------------------------------------------------
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& redEdge : redEdges) {
            adj[redEdge[0]].push_back({redEdge[1], 0});
        }
        for (auto& blueEdge : blueEdges) {
            adj[blueEdge[0]].push_back(make_pair(blueEdge[1], 1));
        }

        vector<int> answer(n, -1);
        vector<vector<bool>> visit(n, vector<bool>(2));
        queue<vector<int>> q;

        // Start with node 0, with number of steps as 0 and undefined color -1.
        q.push({0, 0, -1});
        visit[0][1] = visit[0][0] = true;
        answer[0] = 0;

        while (!q.empty()) {
            auto element = q.front();
            int node = element[0], steps = element[1], prevColor = element[2];
            q.pop();

            for (auto& [neighbor, color] : adj[node]) {
                if (!visit[neighbor][color] && color != prevColor) {
                    visit[neighbor][color] = true;
                    q.push({neighbor, 1 + steps, color});
                    if (answer[neighbor] == -1) answer[neighbor] = 1 + steps;
                }
            }
        }
        return answer;
    }
};
