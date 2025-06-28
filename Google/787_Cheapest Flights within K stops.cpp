class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prev(n, 1e9);
        prev[src] = 0;

        for (int i = 0; i <= k; ++i) {
            vector<int> curr = prev;  
            for (auto& flight : flights) {
                int u = flight[0], v = flight[1], wt = flight[2];
                if (prev[u] != 1e9)
                    curr[v] = min(curr[v], prev[u] + wt);
            }
            prev = curr;
        }

        return (prev[dst] == 1e9) ? -1 : prev[dst];
    }
};
