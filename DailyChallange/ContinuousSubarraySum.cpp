/*
 https://leetcode.com/problems/continuous-subarray-sum/description/
 */

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> modulesAndPositions;
        modulesAndPositions[0] = -1;
        for(int idx = 0; idx < nums.size(); ++idx){
            sum = (sum + nums[idx])%k;
            cout << sum << endl;
            if(modulesAndPositions.find(sum) != modulesAndPositions.end()){
                if(idx - modulesAndPositions[sum] > 1)
                    return true;
            } else {
                modulesAndPositions[sum] = idx;
            }
        }
        return false;
    }
};

/*
 Main idea:

 We are going through array and calculating the sum.
 Every time we add new number, mod our sum by k
 In result, we get missing values for each position

 For example, if we are missing value 1 on n-th
 iteration, we are saving value that we are missing
 and index on which we are missing this value:
 map[1] = n, and continue summing and modding
 In case we have found that mod which we've found
 is already present in our array, it means between
 current and this mode we have sequence, that is
 multiple of k.

 For example,
 [23,2,6,4,7], k = 6
 [5,1,1,5,0] those are mods
 At index 0 and 3 mods are the same, which means
 we have added multiple of 6 to the sum.
 In this case, we have added 2, 6, 4 which sums
 to 12 and gives as the same mod as it was at 1st
 step
 */