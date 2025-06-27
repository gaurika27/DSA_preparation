class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;

        for (int i = 1; i < n; i++) {
            bool updated = false;
            for (auto& edge : times) {
                int u = edge[0], v = edge[1], wt = edge[2];
                if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    updated = true;
                }
            }
            if (!updated) break; // early stopping
        }

        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == 1e9 ? -1 : ans;
    }
};
