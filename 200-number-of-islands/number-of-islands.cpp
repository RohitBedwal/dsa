class Solution {
    private:
        void bfs(int row, int col,vector<vector<char>>& grid, vector<vector<int>>& vis ){
            int n = grid.size();
            int m = grid[0].size();
            vis[row][col] = 1;
            queue<pair<int, int>> q;
            q.push({row, col});
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};
            while(!q.empty()){
                int row = q.front().first; 
                int col = q.front().second; 
                q.pop();
              for(int i = 0; i < 4; i++) { 
                int nrow = row + drow[i]; 
                int mcol = col + dcol[i];
                        
                        if(nrow >= 0 && nrow < n && mcol >=0 && mcol < m 
                        && !vis[nrow][mcol] && grid[nrow][mcol] == '1'
                        ){  
                            vis[nrow][mcol] = 1;
                            q.push({nrow, mcol});
                        }
                    }
                }
            }
        
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int row = 0; row<n; row++){
            for(int col = 0; col<m; col++ ){
                if(grid[row][col] == '1' && !vis[row][col]){
                    cnt++;
                    bfs(row, col, grid, vis);
                }
            }
        }
        return cnt;
    }
};