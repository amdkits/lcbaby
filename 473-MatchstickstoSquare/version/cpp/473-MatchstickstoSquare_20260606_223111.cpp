// Last updated: 6/6/2026, 10:31:11 PM
class Solution {
    bool backtrack(vector<int>& matchsticks, int index, int (&sides)[4], int length)
    {
        if(index == matchsticks.size())
        {
            return true;
        }

        for(int j = 0; j < 4; j++)
        {
            if(j > 0 && sides[j] == sides[j - 1]) continue;
            if(sides[j] + matchsticks[index] <= length)
            {
                sides[j] += matchsticks[index];
                if(backtrack(matchsticks, index + 1, sides, length))
                    return true;
                sides[j] -= matchsticks[index];
            }
        }

        return false;
    }


public:
    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        bool res = false;
        sort(matchsticks.rbegin(), matchsticks.rend());
        if(total % 4 != 0) return res;

        int sides[4] = {};; 
        return backtrack(matchsticks, 0, sides, total / 4);
    }
};