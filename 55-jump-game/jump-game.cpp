class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mxlen = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > mxlen) return false;
            mxlen = max(mxlen, (nums[i] + i));

        }
        return true;

    }
};