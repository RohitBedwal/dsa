class Solution {
    private:
    int func(vector<int>& nums, int k) {
        if(k < 0) return 0;
        int l = 0;
        int r = 0;
        int cnt = 0;
        int sum = 0;
        while(r < nums.size()){
            sum += (nums[r] % 2);
            while(sum > k){
                sum = sum - (nums[l] % 2);
                l++;
            }
            cnt += r - l + 1;
            r++;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = func(nums, k ) - func(nums, k - 1);
        return ans;
    }
};