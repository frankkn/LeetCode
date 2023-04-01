class Solution {
public:
    unordered_map<int,int> tickets;
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        tickets.emplace(1, costs[0]);
        tickets.emplace(7, costs[1]);
        tickets.emplace(30, costs[2]);
        vector<int> dp(366, 0);
        for(int i = 1; i <= 365; ++i){
            if(find(days.begin(), days.end(), i) == days.end()){
                dp[i] = dp[i-1];
                continue;
            }
            int _min = INT_MAX;
            for(auto t: tickets){
                _min = min(_min, dp[max(0,i - t.first)] + t.second);
            }
            dp[i] = _min;
        }
        return dp[days.back()];
    }
};