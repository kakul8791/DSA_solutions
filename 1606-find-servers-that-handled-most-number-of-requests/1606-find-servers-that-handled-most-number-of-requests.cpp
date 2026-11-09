
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        
        // Available servers
        set<int> available;
        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        // {finish time, server id}
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > busy;

        vector<int> count(k, 0);

        for (int i = 0; i < arrival.size(); i++) {

            // Free all servers whose requests are completed
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                available.insert(busy.top().second);
                busy.pop();
            }

            // All servers are busy
            if (available.empty()) {
                continue;
            }

            // Preferred server = i % k
            int start = i % k;

            // Find first available server >= start
            auto it = available.lower_bound(start);

            // Wrap around if necessary
            if (it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            // Assign request
            available.erase(it);
            count[server]++;

            // Mark server busy
            busy.push({
                (long long)arrival[i] + load[i],
                server
            });
        }

        // Find maximum requests handled
        int mx = *max_element(count.begin(), count.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (count[i] == mx) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
