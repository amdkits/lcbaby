// Last updated: 5/8/2026, 6:36:36 PM
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
       vector<pair<int, int>> buffer;
        buffer.reserve(arr.size());
        const int MOD = pow(10, 9) + 7;

        int res {0};
        for(int i = 0; i < arr.size();++i)
        {
            while(buffer.size() && buffer.back().first > arr[i])
            {
                auto [v, index] = buffer.back();
                buffer.pop_back();
                auto left = buffer.size() ? index - buffer.back().second : index + 1;
                auto right = i - index;
                res = (res + v*left*right) % MOD;
            }
            buffer.push_back({arr[i], i});
        }
        for(int i = 0 ; i < buffer.size();++i)
        {
            auto [v, index] = buffer[i];
            auto left = i == 0 ? index + 1 : index - buffer[i-1].second;
            auto right = arr.size() - index;
            res = (res + v*left*right) % MOD;
        }
        return res; 
    }
};