class Solution {
public:
    string minWindow(string s, string t) {
        int l =0, r = 0, cnt = 0;
        vector<int> mpp(256, 0);
        int minLen = INT_MAX;
        int idx = -1;
        for(int i = 0; i<t.size(); i++){
            mpp[t[i]]++;
        }
        while(r < s.size()){
            if(mpp[s[r]] > 0){
                cnt++;
            }
            mpp[s[r]]--;
            while(cnt == t.length()){
                if((r - l + 1) < minLen){
                    minLen = r - l + 1;
                    idx = l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]] > 0){
                    cnt--;
                }
                l++;
               

            }
            r++;
        }
        return (idx == -1) ? "": s.substr(idx, minLen);


    }
};