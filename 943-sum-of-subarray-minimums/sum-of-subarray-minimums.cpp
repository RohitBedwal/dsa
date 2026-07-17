class Solution {
    vector<int> nge(vector<int> &arr){
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);

        for( int i = n - 1  ; i>=0; i-- ){
            while(!st.empty() && arr[i] <= arr[st.top()]){
                st.pop();
            }
            ans[i] = st.empty()? n : st.top();
            st.push(i);

        }
        return ans;
    }
    vector<int> psee(vector<int> &arr){
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);

        for( int i = 0  ; i<n; i++ ){
            while(!st.empty() && arr[i] < arr[st.top()]){
                st.pop();
            }
            ans[i] = st.empty()? -1 : st.top();
            st.push(i);


        }
        return ans;
    }
public:

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int total = 0;
        int mod = 1e9 + 7;
        vector<int> a = nge(arr);
        vector<int> b = psee(arr);

        for(int i = 0; i<n; i++){
            int left = i - b[i];
            int right = a[i] - i;
            long long freq = (left * right * 1LL);
            int val = (freq * arr[i] * 1LL) % mod;
            
            total = (total + val) % mod;
        }
        return total;
    }
};