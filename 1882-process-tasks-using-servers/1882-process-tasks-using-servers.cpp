
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > freeServers;

        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>
        > busyServers;

        int n = servers.size();
        int m = tasks.size();

        for(int i = 0; i < n; i++) {
            freeServers.push({servers[i], i});
        }

        vector<int> ans(m);

        long long currentTime = 0;

        for(int i = 0; i < m; i++) {

            // Time cannot move backwards
            currentTime = max(currentTime, (long long)i);

            // Release available servers
            while(!busyServers.empty() &&
                  get<0>(busyServers.top()) <= currentTime) {

                auto [available, weight, index] = busyServers.top();
                busyServers.pop();

                freeServers.push({weight, index});
            }

            // If no server is free, wait
            if(freeServers.empty()) {

                currentTime = get<0>(busyServers.top());

                while(!busyServers.empty() &&
                      get<0>(busyServers.top()) <= currentTime) {

                    auto [available, weight, index] = busyServers.top();
                    busyServers.pop();

                    freeServers.push({weight, index});
                }
            }

            // Select the best server
            auto [weight, index] = freeServers.top();
            freeServers.pop();

            ans[i] = index;

            // Mark server as busy
            busyServers.push({
                currentTime + tasks[i],
                weight,
                index
            });
        }

        return ans;
    }
};
