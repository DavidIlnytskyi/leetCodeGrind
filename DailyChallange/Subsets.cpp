/*
 * https://leetcode.com/problems/subsets/description/?envType=daily-question&envId=2024-05-21
 */


class Solution {
public:
    void create_subset(int idx, vector<int> subset, vector<int> nums, vector<vector<int>>& result){
        if(idx == nums.size()){
            result.push_back(subset);
            return;
        }

        subset.push_back(nums[idx]);
        create_subset(idx+1, subset, nums, result);

        subset.pop_back();
        create_subset(idx+1, subset, nums, result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;

        create_subset(0, subset, nums, result);

        return result;
    }
};


/*
 Main idea:

 At each step you can either add next number
 to the sequence, either skip it.

 For example, at first step you can add 1 or
 skip it and in result get
 [1] or []
 after for array with [1] you can either
 pick 2, or skip it, so you will get
 [1, 2], or [1]

 At each step we are making our number idx
 bigger, so we are moving across array

 But we are also choosing to save or skip
 potential number.
 At each step there we can skip
 current number, but inc idx
 so at result, we can skip all the numbers
 but still have idx equal length, so the
 sequence will be added.
 */