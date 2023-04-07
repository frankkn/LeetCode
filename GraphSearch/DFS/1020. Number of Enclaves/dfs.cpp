class Solution {
public:

    void dfs(int r, int c, vector<vector<int>>& grid){
        
        int m = grid.size(), n = grid[0].size();
        if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c]==0){
            return;
        }
        grid[r][c] = 0;
        dfs(r+1, c, grid);
        dfs(r-1, c, grid);
        dfs(r, c+1, grid);
        dfs(r, c-1, grid);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
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
                if(grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};