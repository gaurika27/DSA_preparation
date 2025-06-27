class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build the graph and indegree array
        for (auto& pre : prerequisites) {
            int course = pre[0], prereq = pre[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        // Push nodes with 0 indegree (no prerequisites)
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topoOrder;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            topoOrder.push_back(node);

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // If topoOrder has all courses, return it. Else, return empty (cycle exists).
        if (topoOrder.size() == numCourses)
            return topoOrder;
        return {};
    }
};
