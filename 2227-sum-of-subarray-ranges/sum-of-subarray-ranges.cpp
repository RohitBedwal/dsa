class Solution {
private :
    vector<int> nse(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i = n - 1 ; i>=0; i--){

            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            ans[i] = st.empty()? n : st.top();
            st.push(i); 
        }
        return ans;

    }
    vector<int> psee(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i = 0 ; i<n; i++){

            while(!st.empty() && arr[i]<arr[st.top()]){
                st.pop();
            }
            ans[i] = st.empty()? -1 : st.top();
            st.push(i); 
        }
        return ans;

    }
    long long  minimum(vector<int>& arr){
        int n = arr.size();
        vector<int> a = nse(arr);
        vector<int> b = psee(arr);
        int mod = 1e9 + 7;
        long long sum = 0;
        for(int i = 0; i< n; i++){
            int left = i - b[i];
            int right = a[i] - i;
            long long freq = (left * right * 1LL);
            long long  val = (freq * arr[i]);
            sum = (sum + val) ;



        }
        return sum ;
    }
    vector<int> nge(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i = n - 1 ; i>=0; i--){

            while(!st.empty() && arr[i]>=arr[st.top()]){
                st.pop();
            }
            ans[i] = st.empty()? n : st.top();
            st.push(i); 
        }
        return ans;

    }
    vector<int> pgee(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i = 0 ; i<n; i++){

            while(!st.empty() && arr[i]>arr[st.top()]){
                st.pop();
            }
            ans[i] = st.empty()? -1 : st.top();
            st.push(i); 
        }
        return ans;

    }
    long long maximum(vector<int>& arr){
        int n = arr.size();
        vector<int> a = nge(arr);
        vector<int> b = pgee(arr);
        int mod = 1e9 + 7;
        long long  sum = 0;
        for(int i = 0; i< n; i++){
            int left = i - b[i];
            int right = a[i] - i;
            long long freq = (left * right * 1LL);
            long long  val = (freq * arr[i]);
            sum = (sum + val) ;



        }
        return sum ;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        long long mini =  minimum(nums);
        long long maxi =  maximum(nums);
        return maxi - mini;
    }
};