class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> st; 
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            while(!st.empty() && st.front() <= i - k  ){
                st.pop_front();
            }
            while(!st.empty() && nums[st.back()] <= nums[i]){
                st.pop_back();
            }
            st.push_back(i);
            if(i >= k-1) ans.push_back(nums[st.front()]);
        }
        return ans;


    }
};