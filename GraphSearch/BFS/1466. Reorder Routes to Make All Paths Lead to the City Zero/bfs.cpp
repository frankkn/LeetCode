class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> G;
        G.assign(n, {});
        for(auto& road:connections){
            G[road[0]].emplace_back(make_pair(road[1], 1));
            G[road[1]].emplace_back(make_pair(road[0], 0));
        }
        vector<int> used;
        used.assign(n, 0);
        int cnt = 0;
        queue<int> Q;
        Q.push(0);
        used[0] = 1;
        while(!Q.empty()){
            int cur_node = Q.front(); Q.pop();
            for(auto u: G[cur_node]){
                int node = u.first;
                int isOutedge = u.second;
                if(!used[node]){
                    used[node] = 1;
                    Q.push(node);
                    if(isOutedge){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};