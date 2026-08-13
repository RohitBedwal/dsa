class Solution {
    private:
    void dfs(int sr, int sc, vector<vector<int>>& image, vector<vector<int>>& ans, int drow[], int dcol[], int newColor, int intColor){
        ans[sr][sc] = newColor;
        int n = image.size();
        int m = image[0].size();
        for(int i = 0; i<4; i++){
            int nrow = sr + drow[i];
            int ncol = sc + dcol[i];
            if(
                nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                image[nrow][ncol] == intColor &&
                ans[nrow][ncol] != newColor 

            ){
                dfs(nrow, ncol, image, ans, drow, dcol, newColor, intColor);
            }
        }

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
       
        int intColor = image[sr][sc];
        int drow [] = {-1, 0, 1, 0}; 
        int dcol [] = { 0, 1, 0, -1};
        dfs(sr, sc, image, ans, drow, dcol, color, intColor); 
        return ans;
    }
};