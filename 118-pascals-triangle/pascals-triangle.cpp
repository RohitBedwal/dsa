class Solution {
    vector<int> func(int numRows){
        long long ans = 1;
        vector<int> v ;
        v.push_back(ans);
        for(int col = 1; col < numRows; col++ ){
            ans = ans * (numRows - col);
            ans = ans / col;
            v.push_back(ans);
        }
        return v;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> arr;

        for(int i = 1; i<= numRows;i++){
            arr.push_back(func(i));
        }
        return arr;

    }
};