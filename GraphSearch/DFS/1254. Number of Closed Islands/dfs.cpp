class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 1){
            return;
        }
        grid[i][j] = 1;
        dfs(i+1, j, grid);
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
        dfs(i, j-1, grid);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // transform edge block from 0 to 1
        // first and last column
        for(int i = 0; i < m; ++i){
            dfs(i, 0, grid);
            dfs(i, n-1, grid);
        }  
        for(int j = 0; j < n; ++j){
            dfs(0, j, grid);
            dfs(m-1, j, grid);
        }
        int cnt = 0;
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                if(grid[i][j] == 0){
                    dfs(i, j, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};