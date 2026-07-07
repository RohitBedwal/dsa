class Solution {
    private:
    void func(string s, vector<vector<string>>& ans,vector<string>& db, int idx ){
        if(idx == s.length()){
            ans.push_back(db);
            return;
        }
        for(int i = idx; i<s.length(); i++){
            if(isPallen(s, idx, i )){
                db.push_back(s.substr(idx, i - idx + 1));
                func(s, ans, db, i + 1);
                db.pop_back();

            }
        }
    }
    bool isPallen(string s, int st, int end){
        while(st<=end ){
            if(s[st++] != s[end--]){
                return false;
            }
           
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> db;

        func(s, ans, db, 0);
        return ans;
    }
};