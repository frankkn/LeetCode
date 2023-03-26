class Solution {
public:
    vector<vector<int>> G;
    vector<int> used;
    int _max = -1;
    void dfs(int i, unordered_map<int, int>& time){
        used[i] = 1;
        for(auto u: G[i]){
            if(!used[u]){
                time[u] = time[i] + 1;
                dfs(u, time);
            }else{
                if(time.find(u) != time.end()){
                    _max = max(_max, time[i] - time[u] + 1);
                }
            }
        }
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        G.assign(n, {});
        for(int i = 0; i < n; ++i){
            if(edges[i] != -1)
                G[i].emplace_back(edges[i]);
        }
        used.assign(n, 0);
        for(int i = 0; i < n; ++i){
            if(!used[i]){
                unordered_map<int, int> time;
                time[i] = 1;
                dfs(i, time);
            }
        }
        return _max;
    }
};