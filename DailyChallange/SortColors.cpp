/*
    https://leetcode.com/problems/sort-colors/?envType=daily-question&envId=2024-06-12
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0, mid = 0, end = nums.size() - 1;
        while(mid <= end){
            if(nums[mid] == 0){
                swap(nums[start], nums[mid]);
                ++start;
                ++mid;
            } else if(nums[mid] == 1){
                ++mid;
            } else {
                swap(nums[end], nums[mid]);
                --end;
            }
        }
    }
};


/*
 Main idea:

 Create three pointers, for 0, 1 and 2 values.
 Use 1's pointer as iterative pointer. Iterate
 through array. If we see 0, swap start and mid
 pointer values. After that we need to increase
 start pointer by 1, we do it so next 1 that we
 will find stay right from already known ones,
 and increase middle pointer by one, as first
 1's was substituted with 0, so first 1 is at the
 end, and all 1's have moved by 1 to the right.
 If we see 1, just increase middle pointer as all
 is good. If we see 2, swap with end pointer and
 decrease end pointer by 1, so next 2 will be to
 the left from previous found ones
 */