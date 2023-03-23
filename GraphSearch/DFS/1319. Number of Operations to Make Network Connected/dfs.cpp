class Solution {
public:
    vector<vector<int>> G;
    vector<int> used;
    void dfs(int i){
        for(auto v: G[i]){
            if(!used[v]){
                used[v] = 1;
                dfs(v);
            }
        }
    }


    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1)    return -1;
        G.assign(n, {});
        used.assign(n , 0);
        for(auto& cable: connections){
            G[cable[0]].emplace_back(cable[1]);
            G[cable[1]].emplace_back(cable[0]);
        }
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            if(!used[i]){
                dfs(i);
                cnt++;
            }
        }
        return cnt-1;
    }
};