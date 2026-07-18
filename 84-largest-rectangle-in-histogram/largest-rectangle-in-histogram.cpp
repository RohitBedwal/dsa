class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int maxi = 0;
        stack<int> st;
        for(int i = 0; i<arr.size(); i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                int element = st.top(); st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxi = max(maxi, (arr[element]* (nse - pse - 1)));

            }
            st.push(i);
        }
        while(!st.empty()){
            int element = st.top(); st.pop();
            int nse = arr.size();
            int pse = st.empty()? -1: st.top();
            maxi = max(maxi, (arr[element]* (nse - pse - 1)));

        }
        return maxi;
    }
};