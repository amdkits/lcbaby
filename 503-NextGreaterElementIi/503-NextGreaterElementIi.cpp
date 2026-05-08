// Last updated: 5/8/2026, 6:36:55 PM
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n {static_cast<int>(nums.size())};
        vector<int> res(n, -1);
        stack<int> st;

        for (int i {2*n-1}; i>=0; i--){
            while (!st.empty() && (nums[i%n] >= st.top()))
                st.pop();
            if (!st.empty() && (i < n))
                res[i] = {st.top()};
            st.push(nums[i%n]);
        }
        return res;
    }
};