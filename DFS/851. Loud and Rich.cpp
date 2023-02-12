
class Solution {
public:
    vector<int>quite, ans, vis;
    vector<int>adj[600];
    int dfs(int node, vector<int>q) {
        vis[node] = 1;
        int x = node;
        for (int i : adj[node]) {
            if (!vis[i]) {
                int x1 = dfs(i, q);
                if (q[x] > q[x1]) {
                    x = x1;
                }
            }
        }
        return x;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        int m = richer.size();
        ans = vector<int>(n);
        vis = vector<int>(n);
        for (int i = 0;i < m;i++) {
            adj[richer[i][1]].push_back(richer[i][0]);
        }
        for (int i = 0;i < n;i++) {
            int x = dfs(i, quiet);
            ans[i] = x;
            vis.clear();
            vis.resize(n + 1);
        }
        return ans;
    }
};

// -------------------------------------------------------------------------------------

class Solution {
private:
  struct Node{
    bool vis=0;
    int mnQ=-1;
    int idOfMnQ=-1;
  };

  void DFS(int node, vector<vector<int>>& adj, vector<Node>& nodes){
    pair<int,int> mn={nodes[node].mnQ, nodes[node].idOfMnQ};
    nodes[node].vis=1;
    for(auto& neigh : adj[node]){
      if(nodes[neigh].vis==0) DFS(neigh, adj, nodes);
      mn=min(mn, {nodes[neigh].mnQ, nodes[neigh].idOfMnQ});
    }
    nodes[node].mnQ=mn.first;
    nodes[node].idOfMnQ=mn.second;
  }

  void topological(int node, vector<vector<int>>& adj, vector<Node>& nodes, vector<int>& topoOrder){
    nodes[node].vis=1;
    for(auto& neigh : adj[node])
      if(nodes[neigh].vis==0)
        topological(neigh, adj, nodes, topoOrder);
    topoOrder.push_back(node);
  } 

public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>>adj(n);
        for(auto& edge : richer)
          adj[edge.back()].push_back(edge.front());
        vector<Node>nodes(n);
        for(int i=0; i<n; i++) 
          nodes[i].idOfMnQ=i, nodes[i].mnQ=quiet[i];
        
        vector<int>topoOrder;
        for(int i=0; i<n; i++)
          if(nodes[i].vis==0)
            topological(i,adj,nodes,topoOrder);
        reverse(topoOrder.begin(), topoOrder.end());

        for(auto& node : nodes) node.vis=0;

        for(auto& node : topoOrder)
          if(nodes[node].vis==0)
            DFS(node,adj,nodes);
        
        vector<int>ans(n);
        for(int i=0; i<n; i++)
          ans[i]=nodes[i].idOfMnQ;
        return ans;


    }
};
