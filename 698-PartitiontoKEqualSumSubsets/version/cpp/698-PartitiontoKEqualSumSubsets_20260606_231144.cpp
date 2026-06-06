// Last updated: 6/6/2026, 11:11:44 PM
// dia
1class Solution {
2public:
3    bool solver(vector<int>& nums, vector<int>& visited, int start_index, int k, int current_sum, int target) {
4        if (k == 0) return true;  
5        if (current_sum == target) {
6            
7            return solver(nums, visited, 0, k - 1, 0, target);
8        }
9
10        for (int i = start_index; i < nums.size(); i++) {
11            if (!visited[i] && current_sum + nums[i] <= target) {
12                visited[i] = 1;  
13                if (solver(nums, visited, i + 1, k, current_sum + nums[i], target)) {
14                    return true;
15                }
16                visited[i] = 0;  
17               if (current_sum == 0)
18                    return false;
19            }
20        }
21
22        return false;
23    }
24
25    bool canPartitionKSubsets(vector<int>& nums, int k) {
26        int sum = accumulate(nums.begin(), nums.end(), 0);
27        if (sum % k != 0) return false;  
28
29        int target = sum / k;
30        vector<int> visited(nums.size(), 0);
31        sort(nums.begin(), nums.end(), greater<int>()); 
32        return solver(nums, visited, 0, k, 0, target);
33    }
34};