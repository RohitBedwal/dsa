class Solution {
    private:
        void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row , int col , int drow[], int dcol[]){
            int n = grid.size();
            int m = grid[0].size();
            vis[row][col] = 1;
            for(int i = 0; i<4; i++){
                int nrow = drow[i] + row;
                int ncol = dcol[i] + col;

                if(nrow>= 0 && nrow < n  && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1  ){
                    
                    dfs(grid, vis, nrow, ncol, drow, dcol);
                }
            }
        }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis (n, vector<int>(m, 0));
        int count = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for(int i = 0 ; i<m; i++){
            if(grid[0][i] == 1){
                dfs(grid, vis, 0, i, drow, dcol);
            }
            if(grid[n - 1][i] == 1){
                dfs(grid, vis, n - 1, i, drow, dcol);
            }
        }
        for(int i = 0 ; i<n; i++){
            if(grid[i][0] == 1){
                dfs(grid, vis, i, 0, drow, dcol);
            }
            if(grid[i][m - 1 ] == 1){
                dfs(grid, vis, i, m-1, drow, dcol);
            }
        }
        for(int i = 0; i< n; i++){
            for (int j = 0; j<m ; j++){
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};