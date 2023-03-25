class Solution {
public:
    vector<vector<int>> G;
    vector<int> used;
    int dfs_component(int i, int& no){
        used[i] = 1;
        no++;
        for(auto u:G[i]){
            if(!used[u]){
                dfs_component(u, no);
            }
        }
        return no;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        G.assign(n, {});
        for(auto& e: edges){
            G[e[0]].emplace_back(e[1]);
            G[e[1]].emplace_back(e[0]);
        }
        used.assign(n , 0);
        vector<long long> components;
        for(int i = 0; i < n; ++i){
            if(!used[i]){
                int zero = 0;
                components.emplace_back(dfs_component(i, zero));
            }
        }
        long long ans = 0;
        for(long long i = 0; i < components.size(); ++i){
            ans += (components[i] * (n-components[i]));
        }
        return ans/2;

    }
};