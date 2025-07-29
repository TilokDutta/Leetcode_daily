class Solution {
public:
    vector<int> dfs(vector<vector<int>> &adj, int node, int parent, vector<int> &count, string &labels) {
        vector<int> storenode(26, 0);
        storenode[labels[node] - 'a']++;

        for (int child : adj[node]) {
            if (child != parent) {
                vector<int> childFreq = dfs(adj, child, node, count, labels);
                for (int i = 0; i < 26; i++) {
                    storenode[i] += childFreq[i];
                }
            }
        }

        count[node] = storenode[labels[node] - 'a'];
        return storenode;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> count(n, 0);
        dfs(adj, 0, -1, count, labels);
        return count;
    }
};
