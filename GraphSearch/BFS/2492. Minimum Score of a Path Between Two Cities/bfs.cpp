class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> G;
        G.assign(n+1, {});
        for(auto& road: roads){
            G[road[0]].emplace_back(make_pair(road[1], road[2]));
            G[road[1]].emplace_back(make_pair(road[0], road[2]));
        }
        queue<int> q;
        q.push(1);
        int _min = INT_MAX;
        vector<bool> used(n+1,0);
        used[1] = true;
        while(!q.empty()){
            int top = q.front(); q.pop();
            for(auto it = G[top].begin(); it != G[top].end(); it++){
                if(!used[(*it).first]){
                    q.push((*it).first);
                    used[(*it).first] = true;
                }
                int d = (*it).second;
                _min = min(d, _min);
            }
        }
        return _min;
    }
};