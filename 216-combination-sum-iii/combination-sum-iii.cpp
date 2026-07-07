class Solution {
    private:
    void func( vector<vector<int>>& ans, vector<int>& db, int k, int target, int  s, int idx){
        if(db.size() == k){
            if(s == target){
                ans.push_back(db);
            }
            return;
        }
        if(s> target || idx > 9  ) return ;
        db.push_back(idx);
        s+=idx;
        func(ans, db, k, target, s, idx + 1);
        db.pop_back();
        s-=idx;

        func(ans, db, k, target, s, idx + 1);

    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
         vector<vector<int>> ans;
         vector<int> db;
         func(ans, db,k, n, 0, 1 );
         return ans;
    }
};