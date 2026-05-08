// Last updated: 5/8/2026, 6:36:19 PM
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start = 0;
        int end = (int)arr.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            int missingNumbers = arr[mid] - (mid+1);

            if (missingNumbers < k)
                start = mid + 1;
                else
                end = mid - 1;
        }
        return k + start;
    }
};