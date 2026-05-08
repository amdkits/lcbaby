// Last updated: 5/8/2026, 6:36:35 PM
class Solution {
public:
    int numSubArrUptoSum(vector<int>& nums, int goal) {
        int left = 0;
        int right = 0;
        int res = 0;
        int sum = 0;
        while (right < nums.size()) {
            sum += nums[right];
            // check whether we need to shrink the window
            while (left <= right && sum > goal) {
                sum -= nums[left];
                left++;
            }
            res += (right - left + 1);
            right++;
        }
        return res;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        /*
            //using prefix sum
            int res=0;
            std::unordered_map<int,int> prefixSumCount;
            prefixSumCount[0]=1;
            int sum=0;
            for(int i=0;i<nums.size();i++){
                sum+=nums[i];
                if(prefixSumCount.find(sum-goal)!=prefixSumCount.end()){
                    res+=prefixSumCount[sum-goal];
                }
                prefixSumCount[sum]++;
            }
            return res;
        */
        int a = numSubArrUptoSum(nums, goal);
        int b = numSubArrUptoSum(nums, goal - 1);
        return a - b;
    }
};
;