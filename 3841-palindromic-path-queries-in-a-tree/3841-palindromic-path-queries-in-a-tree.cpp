
class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> tin(n), tout(n), depth(n), parent(n, -1);
        int timer = 0;

        // Iterative DFS: avoids stack overflow on a chain-shaped tree.
        vector<pair<int, bool>> st;
        st.push_back({0, false});

        while (!st.empty()) {
            auto [u, exiting] = st.back();
            st.pop_back();

            if (exiting) {
                tout[u] = timer;
                continue;
            }

            tin[u] = ++timer;
            st.push_back({u, true});

            for (int i = (int)adj[u].size() - 1; i >= 0; --i) {
                int v = adj[u][i];
                if (v == parent[u]) continue;

                parent[v] = u;
                depth[v] = depth[u] + 1;
                st.push_back({v, false});
            }
        }

        int LOG = 1;
        while ((1 << LOG) <= n) ++LOG;

        vector<vector<int>> up(LOG, vector<int>(n, -1));

        for (int u = 0; u < n; ++u)
            up[0][u] = parent[u];

        for (int k = 1; k < LOG; ++k) {
            for (int u = 0; u < n; ++u) {
                int p = up[k - 1][u];
                if (p != -1)
                    up[k][u] = up[k - 1][p];
            }
        }

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];

            for (int k = 0; k < LOG; ++k) {
                if (diff & (1 << k))
                    u = up[k][u];
            }

            if (u == v) return u;

            for (int k = LOG - 1; k >= 0; --k) {
                if (up[k][u] != up[k][v]) {
                    u = up[k][u];
                    v = up[k][v];
                }
            }

            return parent[u];
        };

        // Fenwick tree for XOR range updates and point queries.
        vector<int> bit(n + 2, 0);

        auto add = [&](int idx, int val) {
            for (; idx <= n; idx += idx & -idx)
                bit[idx] ^= val;
        };

        auto pointQuery = [&](int idx) {
            int result = 0;

            for (; idx > 0; idx -= idx & -idx)
                result ^= bit[idx];

            return result;
        };

        auto mask = [](char c) {
            return 1 << (c - 'a');
        };

        // A node's character contributes to every root path
        // ending inside that node's subtree.
        for (int u = 0; u < n; ++u) {
            int m = mask(s[u]);
            add(tin[u], m);
            add(tout[u] + 1, m);
        }

        vector<bool> answer;

        for (const string& q : queries) {
            string type;
            int u, v;
            char c;

            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                ss >> c;

                int delta = mask(s[u]) ^ mask(c);

                // Update all root paths passing through u.
                add(tin[u], delta);
                add(tout[u] + 1, delta);

                s[u] = c;
            } else {
                ss >> v;

                int w = lca(u, v);

                int pathMask = pointQuery(tin[u])
                             ^ pointQuery(tin[v])
                             ^ mask(s[w]);

                // A palindrome permutation permits at most
                // one character with an odd frequency.
                answer.push_back(
                    (pathMask & (pathMask - 1)) == 0
                );
            }
        }

        return answer;
    }
};
