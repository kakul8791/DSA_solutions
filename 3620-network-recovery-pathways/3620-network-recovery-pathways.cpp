class Solution {
public:
    int n;

    bool check(long long mid, vector<vector<int>>& edges,
               vector<bool>& online, long long k) {

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegree(n, 0);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];

            if (w < mid)
                continue;

            // Intermediate nodes must be online
            if ((u != 0 && u != n - 1 && !online[u]) ||
                (v != 0 && v != n - 1 && !online[v]))
                continue;

            adj[u].push_back({v, w});
            indegree[v]++;
        }

        // Topological Sort
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            topo.push_back(u);

            for (auto &[v, w] : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        const long long INF = 1e18;
        vector<long long> dist(n, INF);
        dist[0] = 0;

        for (int u : topo) {
            if (dist[u] == INF)
                continue;

            for (auto &[v, w] : adj[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k) {

        n = online.size();

        long long low = 0;
        long long high = 0;

        for (auto &e : edges)
            high = max(high, (long long)e[2]);

        int ans = -1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (check(mid, edges, online, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};